// RUN: %clang_cc1 %s -triple spir -cl-std=clc++ -emit-llvm -O0 -o - | FileCheck %s

typedef __SIZE_TYPE__ size_t;

class A {
public:
  void* operator new(size_t);
  void operator delete(void *ptr);
};

void test_new_delete(A **a) {
// CHECK: %{{.*}} = call spir_func i8 addrspace(4)* @_ZNU3AS41AnwEj(i32 {{.*}})
    *a = new A;
// CHECK: call spir_func void @_ZNU3AS41AdlEPU3AS4v(i8 addrspace(4)* {{.*}})
    delete *a;
}
