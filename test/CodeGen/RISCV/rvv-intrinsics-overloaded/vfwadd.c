// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv32 -target-feature +f -target-feature +d -target-feature +experimental-v \
// RUN:   -disable-O0-optnone -emit-llvm %s -o - | opt -S -mem2reg | FileCheck --check-prefix=CHECK-RV32 %s
// RUN: %clang_cc1 -triple riscv64 -target-feature +f -target-feature +d -target-feature +experimental-v \
// RUN:   -disable-O0-optnone -emit-llvm %s -o - | opt -S -mem2reg | FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV32-LABEL: @test_vfwadd_vv_f64m1(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfwadd.nxv1f64.nxv1f32.nxv1f32.i32(<vscale x 1 x float> [[OP1:%.*]], <vscale x 1 x float> [[OP2:%.*]], i32 [[VL:%.*]])
// CHECK-RV32-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwadd_vv_f64m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfwadd.nxv1f64.nxv1f32.nxv1f32.i64(<vscale x 1 x float> [[OP1:%.*]], <vscale x 1 x float> [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
vfloat64m1_t test_vfwadd_vv_f64m1(vfloat32mf2_t op1, vfloat32mf2_t op2,
                                  size_t vl) {
  return vfwadd_vv(op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwadd_vf_f64m1(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfwadd.nxv1f64.nxv1f32.f32.i32(<vscale x 1 x float> [[OP1:%.*]], float [[OP2:%.*]], i32 [[VL:%.*]])
// CHECK-RV32-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwadd_vf_f64m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfwadd.nxv1f64.nxv1f32.f32.i64(<vscale x 1 x float> [[OP1:%.*]], float [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
vfloat64m1_t test_vfwadd_vf_f64m1(vfloat32mf2_t op1, float op2, size_t vl) {
  return vfwadd_vf(op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwadd_wv_f64m1(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfwadd.w.nxv1f64.nxv1f32.i32(<vscale x 1 x double> [[OP1:%.*]], <vscale x 1 x float> [[OP2:%.*]], i32 [[VL:%.*]])
// CHECK-RV32-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwadd_wv_f64m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfwadd.w.nxv1f64.nxv1f32.i64(<vscale x 1 x double> [[OP1:%.*]], <vscale x 1 x float> [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
vfloat64m1_t test_vfwadd_wv_f64m1(vfloat64m1_t op1, vfloat32mf2_t op2,
                                  size_t vl) {
  return vfwadd_wv(op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwadd_wf_f64m1(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfwadd.w.nxv1f64.f32.i32(<vscale x 1 x double> [[OP1:%.*]], float [[OP2:%.*]], i32 [[VL:%.*]])
// CHECK-RV32-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwadd_wf_f64m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfwadd.w.nxv1f64.f32.i64(<vscale x 1 x double> [[OP1:%.*]], float [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
vfloat64m1_t test_vfwadd_wf_f64m1(vfloat64m1_t op1, float op2, size_t vl) {
  return vfwadd_wf(op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwadd_vv_f64m2(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.riscv.vfwadd.nxv2f64.nxv2f32.nxv2f32.i32(<vscale x 2 x float> [[OP1:%.*]], <vscale x 2 x float> [[OP2:%.*]], i32 [[VL:%.*]])
// CHECK-RV32-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwadd_vv_f64m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.riscv.vfwadd.nxv2f64.nxv2f32.nxv2f32.i64(<vscale x 2 x float> [[OP1:%.*]], <vscale x 2 x float> [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
vfloat64m2_t test_vfwadd_vv_f64m2(vfloat32m1_t op1, vfloat32m1_t op2,
                                  size_t vl) {
  return vfwadd_vv(op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwadd_vf_f64m2(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.riscv.vfwadd.nxv2f64.nxv2f32.f32.i32(<vscale x 2 x float> [[OP1:%.*]], float [[OP2:%.*]], i32 [[VL:%.*]])
// CHECK-RV32-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwadd_vf_f64m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.riscv.vfwadd.nxv2f64.nxv2f32.f32.i64(<vscale x 2 x float> [[OP1:%.*]], float [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
vfloat64m2_t test_vfwadd_vf_f64m2(vfloat32m1_t op1, float op2, size_t vl) {
  return vfwadd_vf(op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwadd_wv_f64m2(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.riscv.vfwadd.w.nxv2f64.nxv2f32.i32(<vscale x 2 x double> [[OP1:%.*]], <vscale x 2 x float> [[OP2:%.*]], i32 [[VL:%.*]])
// CHECK-RV32-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwadd_wv_f64m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.riscv.vfwadd.w.nxv2f64.nxv2f32.i64(<vscale x 2 x double> [[OP1:%.*]], <vscale x 2 x float> [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
vfloat64m2_t test_vfwadd_wv_f64m2(vfloat64m2_t op1, vfloat32m1_t op2,
                                  size_t vl) {
  return vfwadd_wv(op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwadd_wf_f64m2(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.riscv.vfwadd.w.nxv2f64.f32.i32(<vscale x 2 x double> [[OP1:%.*]], float [[OP2:%.*]], i32 [[VL:%.*]])
// CHECK-RV32-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwadd_wf_f64m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.riscv.vfwadd.w.nxv2f64.f32.i64(<vscale x 2 x double> [[OP1:%.*]], float [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
vfloat64m2_t test_vfwadd_wf_f64m2(vfloat64m2_t op1, float op2, size_t vl) {
  return vfwadd_wf(op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwadd_vv_f64m4(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x double> @llvm.riscv.vfwadd.nxv4f64.nxv4f32.nxv4f32.i32(<vscale x 4 x float> [[OP1:%.*]], <vscale x 4 x float> [[OP2:%.*]], i32 [[VL:%.*]])
// CHECK-RV32-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwadd_vv_f64m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x double> @llvm.riscv.vfwadd.nxv4f64.nxv4f32.nxv4f32.i64(<vscale x 4 x float> [[OP1:%.*]], <vscale x 4 x float> [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
vfloat64m4_t test_vfwadd_vv_f64m4(vfloat32m2_t op1, vfloat32m2_t op2,
                                  size_t vl) {
  return vfwadd_vv(op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwadd_vf_f64m4(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x double> @llvm.riscv.vfwadd.nxv4f64.nxv4f32.f32.i32(<vscale x 4 x float> [[OP1:%.*]], float [[OP2:%.*]], i32 [[VL:%.*]])
// CHECK-RV32-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwadd_vf_f64m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x double> @llvm.riscv.vfwadd.nxv4f64.nxv4f32.f32.i64(<vscale x 4 x float> [[OP1:%.*]], float [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
vfloat64m4_t test_vfwadd_vf_f64m4(vfloat32m2_t op1, float op2, size_t vl) {
  return vfwadd_vf(op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwadd_wv_f64m4(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x double> @llvm.riscv.vfwadd.w.nxv4f64.nxv4f32.i32(<vscale x 4 x double> [[OP1:%.*]], <vscale x 4 x float> [[OP2:%.*]], i32 [[VL:%.*]])
// CHECK-RV32-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwadd_wv_f64m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x double> @llvm.riscv.vfwadd.w.nxv4f64.nxv4f32.i64(<vscale x 4 x double> [[OP1:%.*]], <vscale x 4 x float> [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
vfloat64m4_t test_vfwadd_wv_f64m4(vfloat64m4_t op1, vfloat32m2_t op2,
                                  size_t vl) {
  return vfwadd_wv(op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwadd_wf_f64m4(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x double> @llvm.riscv.vfwadd.w.nxv4f64.f32.i32(<vscale x 4 x double> [[OP1:%.*]], float [[OP2:%.*]], i32 [[VL:%.*]])
// CHECK-RV32-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwadd_wf_f64m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x double> @llvm.riscv.vfwadd.w.nxv4f64.f32.i64(<vscale x 4 x double> [[OP1:%.*]], float [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
vfloat64m4_t test_vfwadd_wf_f64m4(vfloat64m4_t op1, float op2, size_t vl) {
  return vfwadd_wf(op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwadd_vv_f64m8(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x double> @llvm.riscv.vfwadd.nxv8f64.nxv8f32.nxv8f32.i32(<vscale x 8 x float> [[OP1:%.*]], <vscale x 8 x float> [[OP2:%.*]], i32 [[VL:%.*]])
// CHECK-RV32-NEXT:    ret <vscale x 8 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwadd_vv_f64m8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x double> @llvm.riscv.vfwadd.nxv8f64.nxv8f32.nxv8f32.i64(<vscale x 8 x float> [[OP1:%.*]], <vscale x 8 x float> [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x double> [[TMP0]]
//
vfloat64m8_t test_vfwadd_vv_f64m8(vfloat32m4_t op1, vfloat32m4_t op2,
                                  size_t vl) {
  return vfwadd_vv(op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwadd_vf_f64m8(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x double> @llvm.riscv.vfwadd.nxv8f64.nxv8f32.f32.i32(<vscale x 8 x float> [[OP1:%.*]], float [[OP2:%.*]], i32 [[VL:%.*]])
// CHECK-RV32-NEXT:    ret <vscale x 8 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwadd_vf_f64m8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x double> @llvm.riscv.vfwadd.nxv8f64.nxv8f32.f32.i64(<vscale x 8 x float> [[OP1:%.*]], float [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x double> [[TMP0]]
//
vfloat64m8_t test_vfwadd_vf_f64m8(vfloat32m4_t op1, float op2, size_t vl) {
  return vfwadd_vf(op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwadd_wv_f64m8(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x double> @llvm.riscv.vfwadd.w.nxv8f64.nxv8f32.i32(<vscale x 8 x double> [[OP1:%.*]], <vscale x 8 x float> [[OP2:%.*]], i32 [[VL:%.*]])
// CHECK-RV32-NEXT:    ret <vscale x 8 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwadd_wv_f64m8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x double> @llvm.riscv.vfwadd.w.nxv8f64.nxv8f32.i64(<vscale x 8 x double> [[OP1:%.*]], <vscale x 8 x float> [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x double> [[TMP0]]
//
vfloat64m8_t test_vfwadd_wv_f64m8(vfloat64m8_t op1, vfloat32m4_t op2,
                                  size_t vl) {
  return vfwadd_wv(op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwadd_wf_f64m8(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x double> @llvm.riscv.vfwadd.w.nxv8f64.f32.i32(<vscale x 8 x double> [[OP1:%.*]], float [[OP2:%.*]], i32 [[VL:%.*]])
// CHECK-RV32-NEXT:    ret <vscale x 8 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwadd_wf_f64m8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x double> @llvm.riscv.vfwadd.w.nxv8f64.f32.i64(<vscale x 8 x double> [[OP1:%.*]], float [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x double> [[TMP0]]
//
vfloat64m8_t test_vfwadd_wf_f64m8(vfloat64m8_t op1, float op2, size_t vl) {
  return vfwadd_wf(op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwadd_vv_f64m1_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfwadd.mask.nxv1f64.nxv1f32.nxv1f32.i32(<vscale x 1 x double> [[MASKEDOFF:%.*]], <vscale x 1 x float> [[OP1:%.*]], <vscale x 1 x float> [[OP2:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) #[[ATTR5:[0-9]+]]
// CHECK-RV32-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwadd_vv_f64m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfwadd.mask.nxv1f64.nxv1f32.nxv1f32.i64(<vscale x 1 x double> [[MASKEDOFF:%.*]], <vscale x 1 x float> [[OP1:%.*]], <vscale x 1 x float> [[OP2:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR5:[0-9]+]]
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
vfloat64m1_t test_vfwadd_vv_f64m1_m(vbool64_t mask, vfloat64m1_t maskedoff,
                                    vfloat32mf2_t op1, vfloat32mf2_t op2,
                                    size_t vl) {
  return vfwadd_vv(mask, maskedoff, op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwadd_vf_f64m1_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfwadd.mask.nxv1f64.nxv1f32.f32.i32(<vscale x 1 x double> [[MASKEDOFF:%.*]], <vscale x 1 x float> [[OP1:%.*]], float [[OP2:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) #[[ATTR5]]
// CHECK-RV32-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwadd_vf_f64m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfwadd.mask.nxv1f64.nxv1f32.f32.i64(<vscale x 1 x double> [[MASKEDOFF:%.*]], <vscale x 1 x float> [[OP1:%.*]], float [[OP2:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR5]]
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
vfloat64m1_t test_vfwadd_vf_f64m1_m(vbool64_t mask, vfloat64m1_t maskedoff,
                                    vfloat32mf2_t op1, float op2, size_t vl) {
  return vfwadd_vf(mask, maskedoff, op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwadd_wv_f64m1_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfwadd.w.mask.nxv1f64.nxv1f32.i32(<vscale x 1 x double> [[MASKEDOFF:%.*]], <vscale x 1 x double> [[OP1:%.*]], <vscale x 1 x float> [[OP2:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) #[[ATTR5]]
// CHECK-RV32-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwadd_wv_f64m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfwadd.w.mask.nxv1f64.nxv1f32.i64(<vscale x 1 x double> [[MASKEDOFF:%.*]], <vscale x 1 x double> [[OP1:%.*]], <vscale x 1 x float> [[OP2:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR5]]
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
vfloat64m1_t test_vfwadd_wv_f64m1_m(vbool64_t mask, vfloat64m1_t maskedoff,
                                    vfloat64m1_t op1, vfloat32mf2_t op2,
                                    size_t vl) {
  return vfwadd_wv(mask, maskedoff, op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwadd_wf_f64m1_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfwadd.w.mask.nxv1f64.f32.i32(<vscale x 1 x double> [[MASKEDOFF:%.*]], <vscale x 1 x double> [[OP1:%.*]], float [[OP2:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) #[[ATTR5]]
// CHECK-RV32-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwadd_wf_f64m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfwadd.w.mask.nxv1f64.f32.i64(<vscale x 1 x double> [[MASKEDOFF:%.*]], <vscale x 1 x double> [[OP1:%.*]], float [[OP2:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR5]]
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
vfloat64m1_t test_vfwadd_wf_f64m1_m(vbool64_t mask, vfloat64m1_t maskedoff,
                                    vfloat64m1_t op1, float op2, size_t vl) {
  return vfwadd_wf(mask, maskedoff, op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwadd_vv_f64m2_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.riscv.vfwadd.mask.nxv2f64.nxv2f32.nxv2f32.i32(<vscale x 2 x double> [[MASKEDOFF:%.*]], <vscale x 2 x float> [[OP1:%.*]], <vscale x 2 x float> [[OP2:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) #[[ATTR5]]
// CHECK-RV32-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwadd_vv_f64m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.riscv.vfwadd.mask.nxv2f64.nxv2f32.nxv2f32.i64(<vscale x 2 x double> [[MASKEDOFF:%.*]], <vscale x 2 x float> [[OP1:%.*]], <vscale x 2 x float> [[OP2:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR5]]
// CHECK-RV64-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
vfloat64m2_t test_vfwadd_vv_f64m2_m(vbool32_t mask, vfloat64m2_t maskedoff,
                                    vfloat32m1_t op1, vfloat32m1_t op2,
                                    size_t vl) {
  return vfwadd_vv(mask, maskedoff, op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwadd_vf_f64m2_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.riscv.vfwadd.mask.nxv2f64.nxv2f32.f32.i32(<vscale x 2 x double> [[MASKEDOFF:%.*]], <vscale x 2 x float> [[OP1:%.*]], float [[OP2:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) #[[ATTR5]]
// CHECK-RV32-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwadd_vf_f64m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.riscv.vfwadd.mask.nxv2f64.nxv2f32.f32.i64(<vscale x 2 x double> [[MASKEDOFF:%.*]], <vscale x 2 x float> [[OP1:%.*]], float [[OP2:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR5]]
// CHECK-RV64-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
vfloat64m2_t test_vfwadd_vf_f64m2_m(vbool32_t mask, vfloat64m2_t maskedoff,
                                    vfloat32m1_t op1, float op2, size_t vl) {
  return vfwadd_vf(mask, maskedoff, op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwadd_wv_f64m2_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.riscv.vfwadd.w.mask.nxv2f64.nxv2f32.i32(<vscale x 2 x double> [[MASKEDOFF:%.*]], <vscale x 2 x double> [[OP1:%.*]], <vscale x 2 x float> [[OP2:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) #[[ATTR5]]
// CHECK-RV32-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwadd_wv_f64m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.riscv.vfwadd.w.mask.nxv2f64.nxv2f32.i64(<vscale x 2 x double> [[MASKEDOFF:%.*]], <vscale x 2 x double> [[OP1:%.*]], <vscale x 2 x float> [[OP2:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR5]]
// CHECK-RV64-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
vfloat64m2_t test_vfwadd_wv_f64m2_m(vbool32_t mask, vfloat64m2_t maskedoff,
                                    vfloat64m2_t op1, vfloat32m1_t op2,
                                    size_t vl) {
  return vfwadd_wv(mask, maskedoff, op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwadd_wf_f64m2_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.riscv.vfwadd.w.mask.nxv2f64.f32.i32(<vscale x 2 x double> [[MASKEDOFF:%.*]], <vscale x 2 x double> [[OP1:%.*]], float [[OP2:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) #[[ATTR5]]
// CHECK-RV32-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwadd_wf_f64m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.riscv.vfwadd.w.mask.nxv2f64.f32.i64(<vscale x 2 x double> [[MASKEDOFF:%.*]], <vscale x 2 x double> [[OP1:%.*]], float [[OP2:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR5]]
// CHECK-RV64-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
vfloat64m2_t test_vfwadd_wf_f64m2_m(vbool32_t mask, vfloat64m2_t maskedoff,
                                    vfloat64m2_t op1, float op2, size_t vl) {
  return vfwadd_wf(mask, maskedoff, op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwadd_vv_f64m4_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x double> @llvm.riscv.vfwadd.mask.nxv4f64.nxv4f32.nxv4f32.i32(<vscale x 4 x double> [[MASKEDOFF:%.*]], <vscale x 4 x float> [[OP1:%.*]], <vscale x 4 x float> [[OP2:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) #[[ATTR5]]
// CHECK-RV32-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwadd_vv_f64m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x double> @llvm.riscv.vfwadd.mask.nxv4f64.nxv4f32.nxv4f32.i64(<vscale x 4 x double> [[MASKEDOFF:%.*]], <vscale x 4 x float> [[OP1:%.*]], <vscale x 4 x float> [[OP2:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR5]]
// CHECK-RV64-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
vfloat64m4_t test_vfwadd_vv_f64m4_m(vbool16_t mask, vfloat64m4_t maskedoff,
                                    vfloat32m2_t op1, vfloat32m2_t op2,
                                    size_t vl) {
  return vfwadd_vv(mask, maskedoff, op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwadd_vf_f64m4_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x double> @llvm.riscv.vfwadd.mask.nxv4f64.nxv4f32.f32.i32(<vscale x 4 x double> [[MASKEDOFF:%.*]], <vscale x 4 x float> [[OP1:%.*]], float [[OP2:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) #[[ATTR5]]
// CHECK-RV32-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwadd_vf_f64m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x double> @llvm.riscv.vfwadd.mask.nxv4f64.nxv4f32.f32.i64(<vscale x 4 x double> [[MASKEDOFF:%.*]], <vscale x 4 x float> [[OP1:%.*]], float [[OP2:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR5]]
// CHECK-RV64-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
vfloat64m4_t test_vfwadd_vf_f64m4_m(vbool16_t mask, vfloat64m4_t maskedoff,
                                    vfloat32m2_t op1, float op2, size_t vl) {
  return vfwadd_vf(mask, maskedoff, op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwadd_wv_f64m4_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x double> @llvm.riscv.vfwadd.w.mask.nxv4f64.nxv4f32.i32(<vscale x 4 x double> [[MASKEDOFF:%.*]], <vscale x 4 x double> [[OP1:%.*]], <vscale x 4 x float> [[OP2:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) #[[ATTR5]]
// CHECK-RV32-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwadd_wv_f64m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x double> @llvm.riscv.vfwadd.w.mask.nxv4f64.nxv4f32.i64(<vscale x 4 x double> [[MASKEDOFF:%.*]], <vscale x 4 x double> [[OP1:%.*]], <vscale x 4 x float> [[OP2:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR5]]
// CHECK-RV64-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
vfloat64m4_t test_vfwadd_wv_f64m4_m(vbool16_t mask, vfloat64m4_t maskedoff,
                                    vfloat64m4_t op1, vfloat32m2_t op2,
                                    size_t vl) {
  return vfwadd_wv(mask, maskedoff, op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwadd_wf_f64m4_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x double> @llvm.riscv.vfwadd.w.mask.nxv4f64.f32.i32(<vscale x 4 x double> [[MASKEDOFF:%.*]], <vscale x 4 x double> [[OP1:%.*]], float [[OP2:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) #[[ATTR5]]
// CHECK-RV32-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwadd_wf_f64m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x double> @llvm.riscv.vfwadd.w.mask.nxv4f64.f32.i64(<vscale x 4 x double> [[MASKEDOFF:%.*]], <vscale x 4 x double> [[OP1:%.*]], float [[OP2:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR5]]
// CHECK-RV64-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
vfloat64m4_t test_vfwadd_wf_f64m4_m(vbool16_t mask, vfloat64m4_t maskedoff,
                                    vfloat64m4_t op1, float op2, size_t vl) {
  return vfwadd_wf(mask, maskedoff, op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwadd_vv_f64m8_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x double> @llvm.riscv.vfwadd.mask.nxv8f64.nxv8f32.nxv8f32.i32(<vscale x 8 x double> [[MASKEDOFF:%.*]], <vscale x 8 x float> [[OP1:%.*]], <vscale x 8 x float> [[OP2:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) #[[ATTR5]]
// CHECK-RV32-NEXT:    ret <vscale x 8 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwadd_vv_f64m8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x double> @llvm.riscv.vfwadd.mask.nxv8f64.nxv8f32.nxv8f32.i64(<vscale x 8 x double> [[MASKEDOFF:%.*]], <vscale x 8 x float> [[OP1:%.*]], <vscale x 8 x float> [[OP2:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR5]]
// CHECK-RV64-NEXT:    ret <vscale x 8 x double> [[TMP0]]
//
vfloat64m8_t test_vfwadd_vv_f64m8_m(vbool8_t mask, vfloat64m8_t maskedoff,
                                    vfloat32m4_t op1, vfloat32m4_t op2,
                                    size_t vl) {
  return vfwadd_vv(mask, maskedoff, op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwadd_vf_f64m8_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x double> @llvm.riscv.vfwadd.mask.nxv8f64.nxv8f32.f32.i32(<vscale x 8 x double> [[MASKEDOFF:%.*]], <vscale x 8 x float> [[OP1:%.*]], float [[OP2:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) #[[ATTR5]]
// CHECK-RV32-NEXT:    ret <vscale x 8 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwadd_vf_f64m8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x double> @llvm.riscv.vfwadd.mask.nxv8f64.nxv8f32.f32.i64(<vscale x 8 x double> [[MASKEDOFF:%.*]], <vscale x 8 x float> [[OP1:%.*]], float [[OP2:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR5]]
// CHECK-RV64-NEXT:    ret <vscale x 8 x double> [[TMP0]]
//
vfloat64m8_t test_vfwadd_vf_f64m8_m(vbool8_t mask, vfloat64m8_t maskedoff,
                                    vfloat32m4_t op1, float op2, size_t vl) {
  return vfwadd_vf(mask, maskedoff, op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwadd_wv_f64m8_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x double> @llvm.riscv.vfwadd.w.mask.nxv8f64.nxv8f32.i32(<vscale x 8 x double> [[MASKEDOFF:%.*]], <vscale x 8 x double> [[OP1:%.*]], <vscale x 8 x float> [[OP2:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) #[[ATTR5]]
// CHECK-RV32-NEXT:    ret <vscale x 8 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwadd_wv_f64m8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x double> @llvm.riscv.vfwadd.w.mask.nxv8f64.nxv8f32.i64(<vscale x 8 x double> [[MASKEDOFF:%.*]], <vscale x 8 x double> [[OP1:%.*]], <vscale x 8 x float> [[OP2:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR5]]
// CHECK-RV64-NEXT:    ret <vscale x 8 x double> [[TMP0]]
//
vfloat64m8_t test_vfwadd_wv_f64m8_m(vbool8_t mask, vfloat64m8_t maskedoff,
                                    vfloat64m8_t op1, vfloat32m4_t op2,
                                    size_t vl) {
  return vfwadd_wv(mask, maskedoff, op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwadd_wf_f64m8_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x double> @llvm.riscv.vfwadd.w.mask.nxv8f64.f32.i32(<vscale x 8 x double> [[MASKEDOFF:%.*]], <vscale x 8 x double> [[OP1:%.*]], float [[OP2:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) #[[ATTR5]]
// CHECK-RV32-NEXT:    ret <vscale x 8 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwadd_wf_f64m8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x double> @llvm.riscv.vfwadd.w.mask.nxv8f64.f32.i64(<vscale x 8 x double> [[MASKEDOFF:%.*]], <vscale x 8 x double> [[OP1:%.*]], float [[OP2:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR5]]
// CHECK-RV64-NEXT:    ret <vscale x 8 x double> [[TMP0]]
//
vfloat64m8_t test_vfwadd_wf_f64m8_m(vbool8_t mask, vfloat64m8_t maskedoff,
                                    vfloat64m8_t op1, float op2, size_t vl) {
  return vfwadd_wf(mask, maskedoff, op1, op2, vl);
}
