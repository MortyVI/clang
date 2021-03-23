// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py

// RUN: %clang_cc1 -triple riscv32 -target-feature +experimental-v -emit-llvm -o - %s \
// RUN:       | FileCheck --check-prefix=CHECK-RV32 %s
// RUN: %clang_cc1 -triple riscv64 -target-feature +experimental-v -emit-llvm -o - %s \
// RUN:       | FileCheck --check-prefix=CHECK-RV64 %s
// RUN: %clang_cc1 -triple riscv64 -target-feature +experimental-v -Werror -Wall -o - \
// RUN:       %s > /dev/null 2>&1 | FileCheck --check-prefix=ASM --allow-empty %s

// ASM-NOT: warning
#include <riscv_vector.h>

// CHECK-RV32-LABEL: @test_vsetvl_e8m1(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[AVL_ADDR:%.*]] = alloca i32, align 4
// CHECK-RV32-NEXT:    store i32 [[AVL:%.*]], i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = load i32, i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP1:%.*]] = call i32 @llvm.riscv.vsetvli.i32(i32 [[TMP0]], i32 0, i32 0)
// CHECK-RV32-NEXT:    ret i32 [[TMP1]]
//
// CHECK-RV64-LABEL: @test_vsetvl_e8m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[AVL_ADDR:%.*]] = alloca i64, align 8
// CHECK-RV64-NEXT:    store i64 [[AVL:%.*]], i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = load i64, i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call i64 @llvm.riscv.vsetvli.i64(i64 [[TMP0]], i64 0, i64 0)
// CHECK-RV64-NEXT:    ret i64 [[TMP1]]
//
size_t test_vsetvl_e8m1(size_t avl) {
  return vsetvl_e8m1(avl);
}

// CHECK-RV32-LABEL: @test_vsetvl_e8m2(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[AVL_ADDR:%.*]] = alloca i32, align 4
// CHECK-RV32-NEXT:    store i32 [[AVL:%.*]], i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = load i32, i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP1:%.*]] = call i32 @llvm.riscv.vsetvli.i32(i32 [[TMP0]], i32 0, i32 1)
// CHECK-RV32-NEXT:    ret i32 [[TMP1]]
//
// CHECK-RV64-LABEL: @test_vsetvl_e8m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[AVL_ADDR:%.*]] = alloca i64, align 8
// CHECK-RV64-NEXT:    store i64 [[AVL:%.*]], i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = load i64, i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call i64 @llvm.riscv.vsetvli.i64(i64 [[TMP0]], i64 0, i64 1)
// CHECK-RV64-NEXT:    ret i64 [[TMP1]]
//
size_t test_vsetvl_e8m2(size_t avl) {
  return vsetvl_e8m2(avl);
}

// CHECK-RV32-LABEL: @test_vsetvl_e8m4(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[AVL_ADDR:%.*]] = alloca i32, align 4
// CHECK-RV32-NEXT:    store i32 [[AVL:%.*]], i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = load i32, i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP1:%.*]] = call i32 @llvm.riscv.vsetvli.i32(i32 [[TMP0]], i32 0, i32 2)
// CHECK-RV32-NEXT:    ret i32 [[TMP1]]
//
// CHECK-RV64-LABEL: @test_vsetvl_e8m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[AVL_ADDR:%.*]] = alloca i64, align 8
// CHECK-RV64-NEXT:    store i64 [[AVL:%.*]], i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = load i64, i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call i64 @llvm.riscv.vsetvli.i64(i64 [[TMP0]], i64 0, i64 2)
// CHECK-RV64-NEXT:    ret i64 [[TMP1]]
//
size_t test_vsetvl_e8m4(size_t avl) {
  return vsetvl_e8m4(avl);
}

// CHECK-RV32-LABEL: @test_vsetvl_e8m8(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[AVL_ADDR:%.*]] = alloca i32, align 4
// CHECK-RV32-NEXT:    store i32 [[AVL:%.*]], i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = load i32, i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP1:%.*]] = call i32 @llvm.riscv.vsetvli.i32(i32 [[TMP0]], i32 0, i32 3)
// CHECK-RV32-NEXT:    ret i32 [[TMP1]]
//
// CHECK-RV64-LABEL: @test_vsetvl_e8m8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[AVL_ADDR:%.*]] = alloca i64, align 8
// CHECK-RV64-NEXT:    store i64 [[AVL:%.*]], i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = load i64, i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call i64 @llvm.riscv.vsetvli.i64(i64 [[TMP0]], i64 0, i64 3)
// CHECK-RV64-NEXT:    ret i64 [[TMP1]]
//
size_t test_vsetvl_e8m8(size_t avl) {
  return vsetvl_e8m8(avl);
}

// CHECK-RV32-LABEL: @test_vsetvl_e8mf2(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[AVL_ADDR:%.*]] = alloca i32, align 4
// CHECK-RV32-NEXT:    store i32 [[AVL:%.*]], i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = load i32, i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP1:%.*]] = call i32 @llvm.riscv.vsetvli.i32(i32 [[TMP0]], i32 0, i32 7)
// CHECK-RV32-NEXT:    ret i32 [[TMP1]]
//
// CHECK-RV64-LABEL: @test_vsetvl_e8mf2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[AVL_ADDR:%.*]] = alloca i64, align 8
// CHECK-RV64-NEXT:    store i64 [[AVL:%.*]], i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = load i64, i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call i64 @llvm.riscv.vsetvli.i64(i64 [[TMP0]], i64 0, i64 7)
// CHECK-RV64-NEXT:    ret i64 [[TMP1]]
//
size_t test_vsetvl_e8mf2(size_t avl) {
  return vsetvl_e8mf2(avl);
}

// CHECK-RV32-LABEL: @test_vsetvl_e8mf4(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[AVL_ADDR:%.*]] = alloca i32, align 4
// CHECK-RV32-NEXT:    store i32 [[AVL:%.*]], i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = load i32, i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP1:%.*]] = call i32 @llvm.riscv.vsetvli.i32(i32 [[TMP0]], i32 0, i32 6)
// CHECK-RV32-NEXT:    ret i32 [[TMP1]]
//
// CHECK-RV64-LABEL: @test_vsetvl_e8mf4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[AVL_ADDR:%.*]] = alloca i64, align 8
// CHECK-RV64-NEXT:    store i64 [[AVL:%.*]], i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = load i64, i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call i64 @llvm.riscv.vsetvli.i64(i64 [[TMP0]], i64 0, i64 6)
// CHECK-RV64-NEXT:    ret i64 [[TMP1]]
//
size_t test_vsetvl_e8mf4(size_t avl) {
  return vsetvl_e8mf4(avl);
}

// CHECK-RV32-LABEL: @test_vsetvl_e8mf8(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[AVL_ADDR:%.*]] = alloca i32, align 4
// CHECK-RV32-NEXT:    store i32 [[AVL:%.*]], i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = load i32, i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP1:%.*]] = call i32 @llvm.riscv.vsetvli.i32(i32 [[TMP0]], i32 0, i32 5)
// CHECK-RV32-NEXT:    ret i32 [[TMP1]]
//
// CHECK-RV64-LABEL: @test_vsetvl_e8mf8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[AVL_ADDR:%.*]] = alloca i64, align 8
// CHECK-RV64-NEXT:    store i64 [[AVL:%.*]], i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = load i64, i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call i64 @llvm.riscv.vsetvli.i64(i64 [[TMP0]], i64 0, i64 5)
// CHECK-RV64-NEXT:    ret i64 [[TMP1]]
//
size_t test_vsetvl_e8mf8(size_t avl) {
  return vsetvl_e8mf8(avl);
}

// CHECK-RV32-LABEL: @test_vsetvl_e16m1(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[AVL_ADDR:%.*]] = alloca i32, align 4
// CHECK-RV32-NEXT:    store i32 [[AVL:%.*]], i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = load i32, i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP1:%.*]] = call i32 @llvm.riscv.vsetvli.i32(i32 [[TMP0]], i32 1, i32 0)
// CHECK-RV32-NEXT:    ret i32 [[TMP1]]
//
// CHECK-RV64-LABEL: @test_vsetvl_e16m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[AVL_ADDR:%.*]] = alloca i64, align 8
// CHECK-RV64-NEXT:    store i64 [[AVL:%.*]], i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = load i64, i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call i64 @llvm.riscv.vsetvli.i64(i64 [[TMP0]], i64 1, i64 0)
// CHECK-RV64-NEXT:    ret i64 [[TMP1]]
//
size_t test_vsetvl_e16m1(size_t avl) {
  return vsetvl_e16m1(avl);
}

// CHECK-RV32-LABEL: @test_vsetvl_e16m2(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[AVL_ADDR:%.*]] = alloca i32, align 4
// CHECK-RV32-NEXT:    store i32 [[AVL:%.*]], i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = load i32, i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP1:%.*]] = call i32 @llvm.riscv.vsetvli.i32(i32 [[TMP0]], i32 1, i32 1)
// CHECK-RV32-NEXT:    ret i32 [[TMP1]]
//
// CHECK-RV64-LABEL: @test_vsetvl_e16m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[AVL_ADDR:%.*]] = alloca i64, align 8
// CHECK-RV64-NEXT:    store i64 [[AVL:%.*]], i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = load i64, i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call i64 @llvm.riscv.vsetvli.i64(i64 [[TMP0]], i64 1, i64 1)
// CHECK-RV64-NEXT:    ret i64 [[TMP1]]
//
size_t test_vsetvl_e16m2(size_t avl) {
  return vsetvl_e16m2(avl);
}

// CHECK-RV32-LABEL: @test_vsetvl_e16m4(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[AVL_ADDR:%.*]] = alloca i32, align 4
// CHECK-RV32-NEXT:    store i32 [[AVL:%.*]], i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = load i32, i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP1:%.*]] = call i32 @llvm.riscv.vsetvli.i32(i32 [[TMP0]], i32 1, i32 2)
// CHECK-RV32-NEXT:    ret i32 [[TMP1]]
//
// CHECK-RV64-LABEL: @test_vsetvl_e16m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[AVL_ADDR:%.*]] = alloca i64, align 8
// CHECK-RV64-NEXT:    store i64 [[AVL:%.*]], i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = load i64, i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call i64 @llvm.riscv.vsetvli.i64(i64 [[TMP0]], i64 1, i64 2)
// CHECK-RV64-NEXT:    ret i64 [[TMP1]]
//
size_t test_vsetvl_e16m4(size_t avl) {
  return vsetvl_e16m4(avl);
}

// CHECK-RV32-LABEL: @test_vsetvl_e16m8(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[AVL_ADDR:%.*]] = alloca i32, align 4
// CHECK-RV32-NEXT:    store i32 [[AVL:%.*]], i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = load i32, i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP1:%.*]] = call i32 @llvm.riscv.vsetvli.i32(i32 [[TMP0]], i32 1, i32 3)
// CHECK-RV32-NEXT:    ret i32 [[TMP1]]
//
// CHECK-RV64-LABEL: @test_vsetvl_e16m8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[AVL_ADDR:%.*]] = alloca i64, align 8
// CHECK-RV64-NEXT:    store i64 [[AVL:%.*]], i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = load i64, i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call i64 @llvm.riscv.vsetvli.i64(i64 [[TMP0]], i64 1, i64 3)
// CHECK-RV64-NEXT:    ret i64 [[TMP1]]
//
size_t test_vsetvl_e16m8(size_t avl) {
  return vsetvl_e16m8(avl);
}

// CHECK-RV32-LABEL: @test_vsetvl_e16mf2(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[AVL_ADDR:%.*]] = alloca i32, align 4
// CHECK-RV32-NEXT:    store i32 [[AVL:%.*]], i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = load i32, i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP1:%.*]] = call i32 @llvm.riscv.vsetvli.i32(i32 [[TMP0]], i32 1, i32 7)
// CHECK-RV32-NEXT:    ret i32 [[TMP1]]
//
// CHECK-RV64-LABEL: @test_vsetvl_e16mf2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[AVL_ADDR:%.*]] = alloca i64, align 8
// CHECK-RV64-NEXT:    store i64 [[AVL:%.*]], i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = load i64, i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call i64 @llvm.riscv.vsetvli.i64(i64 [[TMP0]], i64 1, i64 7)
// CHECK-RV64-NEXT:    ret i64 [[TMP1]]
//
size_t test_vsetvl_e16mf2(size_t avl) {
  return vsetvl_e16mf2(avl);
}

// CHECK-RV32-LABEL: @test_vsetvl_e16mf4(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[AVL_ADDR:%.*]] = alloca i32, align 4
// CHECK-RV32-NEXT:    store i32 [[AVL:%.*]], i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = load i32, i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP1:%.*]] = call i32 @llvm.riscv.vsetvli.i32(i32 [[TMP0]], i32 1, i32 6)
// CHECK-RV32-NEXT:    ret i32 [[TMP1]]
//
// CHECK-RV64-LABEL: @test_vsetvl_e16mf4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[AVL_ADDR:%.*]] = alloca i64, align 8
// CHECK-RV64-NEXT:    store i64 [[AVL:%.*]], i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = load i64, i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call i64 @llvm.riscv.vsetvli.i64(i64 [[TMP0]], i64 1, i64 6)
// CHECK-RV64-NEXT:    ret i64 [[TMP1]]
//
size_t test_vsetvl_e16mf4(size_t avl) {
  return vsetvl_e16mf4(avl);
}

// CHECK-RV32-LABEL: @test_vsetvl_e32m1(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[AVL_ADDR:%.*]] = alloca i32, align 4
// CHECK-RV32-NEXT:    store i32 [[AVL:%.*]], i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = load i32, i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP1:%.*]] = call i32 @llvm.riscv.vsetvli.i32(i32 [[TMP0]], i32 2, i32 0)
// CHECK-RV32-NEXT:    ret i32 [[TMP1]]
//
// CHECK-RV64-LABEL: @test_vsetvl_e32m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[AVL_ADDR:%.*]] = alloca i64, align 8
// CHECK-RV64-NEXT:    store i64 [[AVL:%.*]], i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = load i64, i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call i64 @llvm.riscv.vsetvli.i64(i64 [[TMP0]], i64 2, i64 0)
// CHECK-RV64-NEXT:    ret i64 [[TMP1]]
//
size_t test_vsetvl_e32m1(size_t avl) {
  return vsetvl_e32m1(avl);
}

// CHECK-RV32-LABEL: @test_vsetvl_e32m2(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[AVL_ADDR:%.*]] = alloca i32, align 4
// CHECK-RV32-NEXT:    store i32 [[AVL:%.*]], i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = load i32, i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP1:%.*]] = call i32 @llvm.riscv.vsetvli.i32(i32 [[TMP0]], i32 2, i32 1)
// CHECK-RV32-NEXT:    ret i32 [[TMP1]]
//
// CHECK-RV64-LABEL: @test_vsetvl_e32m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[AVL_ADDR:%.*]] = alloca i64, align 8
// CHECK-RV64-NEXT:    store i64 [[AVL:%.*]], i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = load i64, i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call i64 @llvm.riscv.vsetvli.i64(i64 [[TMP0]], i64 2, i64 1)
// CHECK-RV64-NEXT:    ret i64 [[TMP1]]
//
size_t test_vsetvl_e32m2(size_t avl) {
  return vsetvl_e32m2(avl);
}

// CHECK-RV32-LABEL: @test_vsetvl_e32m4(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[AVL_ADDR:%.*]] = alloca i32, align 4
// CHECK-RV32-NEXT:    store i32 [[AVL:%.*]], i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = load i32, i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP1:%.*]] = call i32 @llvm.riscv.vsetvli.i32(i32 [[TMP0]], i32 2, i32 2)
// CHECK-RV32-NEXT:    ret i32 [[TMP1]]
//
// CHECK-RV64-LABEL: @test_vsetvl_e32m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[AVL_ADDR:%.*]] = alloca i64, align 8
// CHECK-RV64-NEXT:    store i64 [[AVL:%.*]], i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = load i64, i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call i64 @llvm.riscv.vsetvli.i64(i64 [[TMP0]], i64 2, i64 2)
// CHECK-RV64-NEXT:    ret i64 [[TMP1]]
//
size_t test_vsetvl_e32m4(size_t avl) {
  return vsetvl_e32m4(avl);
}

// CHECK-RV32-LABEL: @test_vsetvl_e32m8(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[AVL_ADDR:%.*]] = alloca i32, align 4
// CHECK-RV32-NEXT:    store i32 [[AVL:%.*]], i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = load i32, i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP1:%.*]] = call i32 @llvm.riscv.vsetvli.i32(i32 [[TMP0]], i32 2, i32 3)
// CHECK-RV32-NEXT:    ret i32 [[TMP1]]
//
// CHECK-RV64-LABEL: @test_vsetvl_e32m8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[AVL_ADDR:%.*]] = alloca i64, align 8
// CHECK-RV64-NEXT:    store i64 [[AVL:%.*]], i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = load i64, i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call i64 @llvm.riscv.vsetvli.i64(i64 [[TMP0]], i64 2, i64 3)
// CHECK-RV64-NEXT:    ret i64 [[TMP1]]
//
size_t test_vsetvl_e32m8(size_t avl) {
  return vsetvl_e32m8(avl);
}

// CHECK-RV32-LABEL: @test_vsetvl_e32mf2(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[AVL_ADDR:%.*]] = alloca i32, align 4
// CHECK-RV32-NEXT:    store i32 [[AVL:%.*]], i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = load i32, i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP1:%.*]] = call i32 @llvm.riscv.vsetvli.i32(i32 [[TMP0]], i32 2, i32 7)
// CHECK-RV32-NEXT:    ret i32 [[TMP1]]
//
// CHECK-RV64-LABEL: @test_vsetvl_e32mf2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[AVL_ADDR:%.*]] = alloca i64, align 8
// CHECK-RV64-NEXT:    store i64 [[AVL:%.*]], i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = load i64, i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call i64 @llvm.riscv.vsetvli.i64(i64 [[TMP0]], i64 2, i64 7)
// CHECK-RV64-NEXT:    ret i64 [[TMP1]]
//
size_t test_vsetvl_e32mf2(size_t avl) {
  return vsetvl_e32mf2(avl);
}

// CHECK-RV32-LABEL: @test_vsetvl_e64m1(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[AVL_ADDR:%.*]] = alloca i32, align 4
// CHECK-RV32-NEXT:    store i32 [[AVL:%.*]], i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = load i32, i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP1:%.*]] = call i32 @llvm.riscv.vsetvli.i32(i32 [[TMP0]], i32 3, i32 0)
// CHECK-RV32-NEXT:    ret i32 [[TMP1]]
//
// CHECK-RV64-LABEL: @test_vsetvl_e64m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[AVL_ADDR:%.*]] = alloca i64, align 8
// CHECK-RV64-NEXT:    store i64 [[AVL:%.*]], i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = load i64, i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call i64 @llvm.riscv.vsetvli.i64(i64 [[TMP0]], i64 3, i64 0)
// CHECK-RV64-NEXT:    ret i64 [[TMP1]]
//
size_t test_vsetvl_e64m1(size_t avl) {
  return vsetvl_e64m1(avl);
}

// CHECK-RV32-LABEL: @test_vsetvl_e64m2(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[AVL_ADDR:%.*]] = alloca i32, align 4
// CHECK-RV32-NEXT:    store i32 [[AVL:%.*]], i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = load i32, i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP1:%.*]] = call i32 @llvm.riscv.vsetvli.i32(i32 [[TMP0]], i32 3, i32 1)
// CHECK-RV32-NEXT:    ret i32 [[TMP1]]
//
// CHECK-RV64-LABEL: @test_vsetvl_e64m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[AVL_ADDR:%.*]] = alloca i64, align 8
// CHECK-RV64-NEXT:    store i64 [[AVL:%.*]], i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = load i64, i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call i64 @llvm.riscv.vsetvli.i64(i64 [[TMP0]], i64 3, i64 1)
// CHECK-RV64-NEXT:    ret i64 [[TMP1]]
//
size_t test_vsetvl_e64m2(size_t avl) {
  return vsetvl_e64m2(avl);
}

// CHECK-RV32-LABEL: @test_vsetvl_e64m4(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[AVL_ADDR:%.*]] = alloca i32, align 4
// CHECK-RV32-NEXT:    store i32 [[AVL:%.*]], i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = load i32, i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP1:%.*]] = call i32 @llvm.riscv.vsetvli.i32(i32 [[TMP0]], i32 3, i32 2)
// CHECK-RV32-NEXT:    ret i32 [[TMP1]]
//
// CHECK-RV64-LABEL: @test_vsetvl_e64m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[AVL_ADDR:%.*]] = alloca i64, align 8
// CHECK-RV64-NEXT:    store i64 [[AVL:%.*]], i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = load i64, i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call i64 @llvm.riscv.vsetvli.i64(i64 [[TMP0]], i64 3, i64 2)
// CHECK-RV64-NEXT:    ret i64 [[TMP1]]
//
size_t test_vsetvl_e64m4(size_t avl) {
  return vsetvl_e64m4(avl);
}

// CHECK-RV32-LABEL: @test_vsetvl_e64m8(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[AVL_ADDR:%.*]] = alloca i32, align 4
// CHECK-RV32-NEXT:    store i32 [[AVL:%.*]], i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = load i32, i32* [[AVL_ADDR]], align 4
// CHECK-RV32-NEXT:    [[TMP1:%.*]] = call i32 @llvm.riscv.vsetvli.i32(i32 [[TMP0]], i32 3, i32 3)
// CHECK-RV32-NEXT:    ret i32 [[TMP1]]
//
// CHECK-RV64-LABEL: @test_vsetvl_e64m8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[AVL_ADDR:%.*]] = alloca i64, align 8
// CHECK-RV64-NEXT:    store i64 [[AVL:%.*]], i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = load i64, i64* [[AVL_ADDR]], align 8
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call i64 @llvm.riscv.vsetvli.i64(i64 [[TMP0]], i64 3, i64 3)
// CHECK-RV64-NEXT:    ret i64 [[TMP1]]
//
size_t test_vsetvl_e64m8(size_t avl) {
  return vsetvl_e64m8(avl);
}
