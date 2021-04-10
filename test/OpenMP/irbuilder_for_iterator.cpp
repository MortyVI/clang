// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --function-signature --include-generated-funcs
// RUN: %clang_cc1 -fopenmp-enable-irbuilder -verify -fopenmp -fopenmp-version=50 -x c++ -triple x86_64-unknown-unknown -emit-llvm %s -o - | FileCheck %s
// expected-no-diagnostics

#ifndef HEADER
#define HEADER

struct MyIterator {
  MyIterator(unsigned pos);
  MyIterator(const MyIterator &other);
  const MyIterator &operator=(const MyIterator &that);
  MyIterator &operator++();
  int operator-(const MyIterator &that) const;
  MyIterator &operator+=(unsigned a);
  MyIterator operator+(unsigned a) const;
  bool operator==(const MyIterator &that) const;
  bool operator!=(const MyIterator &that) const;
  unsigned operator*() const;
};

extern "C" void workshareloop_iterator(float *a, float *b, float *c) {
#pragma omp for
  for (MyIterator it = MyIterator(7); it != MyIterator(41); ++it) {
    unsigned i = *it;
    a[i] = b[i] * c[i];
  }
}

#endif // HEADER
// CHECK-LABEL: define {{[^@]+}}@workshareloop_iterator
// CHECK-SAME: (float* [[A:%.*]], float* [[B:%.*]], float* [[C:%.*]]) [[ATTR0:#.*]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[A_ADDR:%.*]] = alloca float*, align 8
// CHECK-NEXT:    [[B_ADDR:%.*]] = alloca float*, align 8
// CHECK-NEXT:    [[C_ADDR:%.*]] = alloca float*, align 8
// CHECK-NEXT:    [[IT:%.*]] = alloca [[STRUCT_MYITERATOR:%.*]], align 1
// CHECK-NEXT:    [[AGG_CAPTURED:%.*]] = alloca [[STRUCT_ANON:%.*]], align 8
// CHECK-NEXT:    [[AGG_CAPTURED1:%.*]] = alloca [[STRUCT_ANON_0:%.*]], align 1
// CHECK-NEXT:    [[DOTCOUNT_ADDR:%.*]] = alloca i64, align 8
// CHECK-NEXT:    [[I:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[P_LASTITER:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[P_LOWERBOUND:%.*]] = alloca i64, align 8
// CHECK-NEXT:    [[P_UPPERBOUND:%.*]] = alloca i64, align 8
// CHECK-NEXT:    [[P_STRIDE:%.*]] = alloca i64, align 8
// CHECK-NEXT:    store float* [[A]], float** [[A_ADDR]], align 8
// CHECK-NEXT:    store float* [[B]], float** [[B_ADDR]], align 8
// CHECK-NEXT:    store float* [[C]], float** [[C_ADDR]], align 8
// CHECK-NEXT:    call void @_ZN10MyIteratorC1Ej(%struct.MyIterator* nonnull dereferenceable(1) [[IT]], i32 7)
// CHECK-NEXT:    [[TMP0:%.*]] = getelementptr inbounds [[STRUCT_ANON]], %struct.anon* [[AGG_CAPTURED]], i32 0, i32 0
// CHECK-NEXT:    store %struct.MyIterator* [[IT]], %struct.MyIterator** [[TMP0]], align 8
// CHECK-NEXT:    [[TMP1:%.*]] = getelementptr inbounds [[STRUCT_ANON_0]], %struct.anon.0* [[AGG_CAPTURED1]], i32 0, i32 0
// CHECK-NEXT:    call void @_ZN10MyIteratorC1ERKS_(%struct.MyIterator* nonnull dereferenceable(1) [[TMP1]], %struct.MyIterator* nonnull align 1 dereferenceable(1) [[IT]])
// CHECK-NEXT:    call void @__captured_stmt(i64* [[DOTCOUNT_ADDR]], %struct.anon* [[AGG_CAPTURED]])
// CHECK-NEXT:    [[DOTCOUNT:%.*]] = load i64, i64* [[DOTCOUNT_ADDR]], align 8
// CHECK-NEXT:    br label [[OMP_LOOP_PREHEADER:%.*]]
// CHECK:       omp_loop.preheader:
// CHECK-NEXT:    store i64 0, i64* [[P_LOWERBOUND]], align 8
// CHECK-NEXT:    [[TMP2:%.*]] = sub i64 [[DOTCOUNT]], 1
// CHECK-NEXT:    store i64 [[TMP2]], i64* [[P_UPPERBOUND]], align 8
// CHECK-NEXT:    store i64 1, i64* [[P_STRIDE]], align 8
// CHECK-NEXT:    [[OMP_GLOBAL_THREAD_NUM:%.*]] = call i32 @__kmpc_global_thread_num(%struct.ident_t* [[GLOB1:@.*]])
// CHECK-NEXT:    call void @__kmpc_for_static_init_8u(%struct.ident_t* [[GLOB1]], i32 [[OMP_GLOBAL_THREAD_NUM]], i32 34, i32* [[P_LASTITER]], i64* [[P_LOWERBOUND]], i64* [[P_UPPERBOUND]], i64* [[P_STRIDE]], i64 1, i64 1)
// CHECK-NEXT:    [[TMP3:%.*]] = load i64, i64* [[P_LOWERBOUND]], align 8
// CHECK-NEXT:    [[TMP4:%.*]] = load i64, i64* [[P_UPPERBOUND]], align 8
// CHECK-NEXT:    [[TMP5:%.*]] = sub i64 [[TMP4]], [[TMP3]]
// CHECK-NEXT:    [[TMP6:%.*]] = add i64 [[TMP5]], 1
// CHECK-NEXT:    br label [[OMP_LOOP_HEADER:%.*]]
// CHECK:       omp_loop.header:
// CHECK-NEXT:    [[OMP_LOOP_IV:%.*]] = phi i64 [ 0, [[OMP_LOOP_PREHEADER]] ], [ [[OMP_LOOP_NEXT:%.*]], [[OMP_LOOP_INC:%.*]] ]
// CHECK-NEXT:    br label [[OMP_LOOP_COND:%.*]]
// CHECK:       omp_loop.cond:
// CHECK-NEXT:    [[OMP_LOOP_CMP:%.*]] = icmp ult i64 [[OMP_LOOP_IV]], [[TMP6]]
// CHECK-NEXT:    br i1 [[OMP_LOOP_CMP]], label [[OMP_LOOP_BODY:%.*]], label [[OMP_LOOP_EXIT:%.*]]
// CHECK:       omp_loop.body:
// CHECK-NEXT:    [[TMP7:%.*]] = add i64 [[OMP_LOOP_IV]], [[TMP3]]
// CHECK-NEXT:    call void @__captured_stmt.1(%struct.MyIterator* [[IT]], i64 [[TMP7]], %struct.anon.0* [[AGG_CAPTURED1]])
// CHECK-NEXT:    [[CALL:%.*]] = call i32 @_ZNK10MyIteratordeEv(%struct.MyIterator* nonnull dereferenceable(1) [[IT]])
// CHECK-NEXT:    store i32 [[CALL]], i32* [[I]], align 4
// CHECK-NEXT:    [[TMP8:%.*]] = load float*, float** [[B_ADDR]], align 8
// CHECK-NEXT:    [[TMP9:%.*]] = load i32, i32* [[I]], align 4
// CHECK-NEXT:    [[IDXPROM:%.*]] = zext i32 [[TMP9]] to i64
// CHECK-NEXT:    [[ARRAYIDX:%.*]] = getelementptr inbounds float, float* [[TMP8]], i64 [[IDXPROM]]
// CHECK-NEXT:    [[TMP10:%.*]] = load float, float* [[ARRAYIDX]], align 4
// CHECK-NEXT:    [[TMP11:%.*]] = load float*, float** [[C_ADDR]], align 8
// CHECK-NEXT:    [[TMP12:%.*]] = load i32, i32* [[I]], align 4
// CHECK-NEXT:    [[IDXPROM2:%.*]] = zext i32 [[TMP12]] to i64
// CHECK-NEXT:    [[ARRAYIDX3:%.*]] = getelementptr inbounds float, float* [[TMP11]], i64 [[IDXPROM2]]
// CHECK-NEXT:    [[TMP13:%.*]] = load float, float* [[ARRAYIDX3]], align 4
// CHECK-NEXT:    [[MUL:%.*]] = fmul float [[TMP10]], [[TMP13]]
// CHECK-NEXT:    [[TMP14:%.*]] = load float*, float** [[A_ADDR]], align 8
// CHECK-NEXT:    [[TMP15:%.*]] = load i32, i32* [[I]], align 4
// CHECK-NEXT:    [[IDXPROM4:%.*]] = zext i32 [[TMP15]] to i64
// CHECK-NEXT:    [[ARRAYIDX5:%.*]] = getelementptr inbounds float, float* [[TMP14]], i64 [[IDXPROM4]]
// CHECK-NEXT:    store float [[MUL]], float* [[ARRAYIDX5]], align 4
// CHECK-NEXT:    br label [[OMP_LOOP_INC]]
// CHECK:       omp_loop.inc:
// CHECK-NEXT:    [[OMP_LOOP_NEXT]] = add nuw i64 [[OMP_LOOP_IV]], 1
// CHECK-NEXT:    br label [[OMP_LOOP_HEADER]]
// CHECK:       omp_loop.exit:
// CHECK-NEXT:    call void @__kmpc_for_static_fini(%struct.ident_t* [[GLOB1]], i32 [[OMP_GLOBAL_THREAD_NUM]])
// CHECK-NEXT:    [[OMP_GLOBAL_THREAD_NUM6:%.*]] = call i32 @__kmpc_global_thread_num(%struct.ident_t* [[GLOB1]])
// CHECK-NEXT:    call void @__kmpc_barrier(%struct.ident_t* [[GLOB2:@.*]], i32 [[OMP_GLOBAL_THREAD_NUM6]])
// CHECK-NEXT:    br label [[OMP_LOOP_AFTER:%.*]]
// CHECK:       omp_loop.after:
// CHECK-NEXT:    ret void
//
//
// CHECK-LABEL: define {{[^@]+}}@__captured_stmt
// CHECK-SAME: (i64* nonnull align 8 dereferenceable(8) [[DISTANCE:%.*]], %struct.anon* noalias [[__CONTEXT:%.*]]) [[ATTR2:#.*]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[DISTANCE_ADDR:%.*]] = alloca i64*, align 8
// CHECK-NEXT:    [[__CONTEXT_ADDR:%.*]] = alloca %struct.anon*, align 8
// CHECK-NEXT:    [[DOTSTART:%.*]] = alloca [[STRUCT_MYITERATOR:%.*]], align 1
// CHECK-NEXT:    [[DOTSTOP:%.*]] = alloca [[STRUCT_MYITERATOR]], align 1
// CHECK-NEXT:    [[DOTSTEP:%.*]] = alloca i64, align 8
// CHECK-NEXT:    store i64* [[DISTANCE]], i64** [[DISTANCE_ADDR]], align 8
// CHECK-NEXT:    store %struct.anon* [[__CONTEXT]], %struct.anon** [[__CONTEXT_ADDR]], align 8
// CHECK-NEXT:    [[TMP0:%.*]] = load %struct.anon*, %struct.anon** [[__CONTEXT_ADDR]], align 8
// CHECK-NEXT:    [[TMP1:%.*]] = getelementptr inbounds [[STRUCT_ANON:%.*]], %struct.anon* [[TMP0]], i32 0, i32 0
// CHECK-NEXT:    [[TMP2:%.*]] = load %struct.MyIterator*, %struct.MyIterator** [[TMP1]], align 8
// CHECK-NEXT:    call void @_ZN10MyIteratorC1ERKS_(%struct.MyIterator* nonnull dereferenceable(1) [[DOTSTART]], %struct.MyIterator* nonnull align 1 dereferenceable(1) [[TMP2]])
// CHECK-NEXT:    call void @_ZN10MyIteratorC1Ej(%struct.MyIterator* nonnull dereferenceable(1) [[DOTSTOP]], i32 41)
// CHECK-NEXT:    store i64 1, i64* [[DOTSTEP]], align 8
// CHECK-NEXT:    [[TMP3:%.*]] = load i64, i64* [[DOTSTEP]], align 8
// CHECK-NEXT:    [[CMP:%.*]] = icmp ult i64 [[TMP3]], 0
// CHECK-NEXT:    br i1 [[CMP]], label [[COND_TRUE:%.*]], label [[COND_FALSE:%.*]]
// CHECK:       cond.true:
// CHECK-NEXT:    [[CALL:%.*]] = call i32 @_ZNK10MyIteratormiERKS_(%struct.MyIterator* nonnull dereferenceable(1) [[DOTSTART]], %struct.MyIterator* nonnull align 1 dereferenceable(1) [[DOTSTOP]])
// CHECK-NEXT:    [[CONV:%.*]] = sext i32 [[CALL]] to i64
// CHECK-NEXT:    [[TMP4:%.*]] = load i64, i64* [[DOTSTEP]], align 8
// CHECK-NEXT:    [[SUB:%.*]] = sub i64 0, [[TMP4]]
// CHECK-NEXT:    [[DIV:%.*]] = udiv i64 [[CONV]], [[SUB]]
// CHECK-NEXT:    br label [[COND_END:%.*]]
// CHECK:       cond.false:
// CHECK-NEXT:    [[CALL1:%.*]] = call i32 @_ZNK10MyIteratormiERKS_(%struct.MyIterator* nonnull dereferenceable(1) [[DOTSTOP]], %struct.MyIterator* nonnull align 1 dereferenceable(1) [[DOTSTART]])
// CHECK-NEXT:    [[CONV2:%.*]] = sext i32 [[CALL1]] to i64
// CHECK-NEXT:    [[TMP5:%.*]] = load i64, i64* [[DOTSTEP]], align 8
// CHECK-NEXT:    [[DIV3:%.*]] = udiv i64 [[CONV2]], [[TMP5]]
// CHECK-NEXT:    br label [[COND_END]]
// CHECK:       cond.end:
// CHECK-NEXT:    [[COND:%.*]] = phi i64 [ [[DIV]], [[COND_TRUE]] ], [ [[DIV3]], [[COND_FALSE]] ]
// CHECK-NEXT:    [[TMP6:%.*]] = load i64*, i64** [[DISTANCE_ADDR]], align 8
// CHECK-NEXT:    store i64 [[COND]], i64* [[TMP6]], align 8
// CHECK-NEXT:    ret void
//
//
// CHECK-LABEL: define {{[^@]+}}@__captured_stmt.1
// CHECK-SAME: (%struct.MyIterator* nonnull align 1 dereferenceable(1) [[LOOPVAR:%.*]], i64 [[LOGICAL:%.*]], %struct.anon.0* noalias [[__CONTEXT:%.*]]) [[ATTR2]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[LOOPVAR_ADDR:%.*]] = alloca %struct.MyIterator*, align 8
// CHECK-NEXT:    [[LOGICAL_ADDR:%.*]] = alloca i64, align 8
// CHECK-NEXT:    [[__CONTEXT_ADDR:%.*]] = alloca %struct.anon.0*, align 8
// CHECK-NEXT:    [[REF_TMP:%.*]] = alloca [[STRUCT_MYITERATOR:%.*]], align 1
// CHECK-NEXT:    store %struct.MyIterator* [[LOOPVAR]], %struct.MyIterator** [[LOOPVAR_ADDR]], align 8
// CHECK-NEXT:    store i64 [[LOGICAL]], i64* [[LOGICAL_ADDR]], align 8
// CHECK-NEXT:    store %struct.anon.0* [[__CONTEXT]], %struct.anon.0** [[__CONTEXT_ADDR]], align 8
// CHECK-NEXT:    [[TMP0:%.*]] = load %struct.anon.0*, %struct.anon.0** [[__CONTEXT_ADDR]], align 8
// CHECK-NEXT:    [[TMP1:%.*]] = getelementptr inbounds [[STRUCT_ANON_0:%.*]], %struct.anon.0* [[TMP0]], i32 0, i32 0
// CHECK-NEXT:    [[TMP2:%.*]] = load i64, i64* [[LOGICAL_ADDR]], align 8
// CHECK-NEXT:    [[MUL:%.*]] = mul i64 1, [[TMP2]]
// CHECK-NEXT:    [[CONV:%.*]] = trunc i64 [[MUL]] to i32
// CHECK-NEXT:    call void @_ZNK10MyIteratorplEj(%struct.MyIterator* sret(%struct.MyIterator) align 1 [[REF_TMP]], %struct.MyIterator* nonnull dereferenceable(1) [[TMP1]], i32 [[CONV]])
// CHECK-NEXT:    [[TMP3:%.*]] = load %struct.MyIterator*, %struct.MyIterator** [[LOOPVAR_ADDR]], align 8
// CHECK-NEXT:    [[CALL:%.*]] = call nonnull align 1 dereferenceable(1) %struct.MyIterator* @_ZN10MyIteratoraSERKS_(%struct.MyIterator* nonnull dereferenceable(1) [[TMP3]], %struct.MyIterator* nonnull align 1 dereferenceable(1) [[REF_TMP]])
// CHECK-NEXT:    ret void
//
