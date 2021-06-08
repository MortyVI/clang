// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang_cc1 -triple aarch64-arm-none-eabi -target-feature +neon -target-feature +bf16 \
// RUN: -disable-O0-optnone -emit-llvm %s -o - | opt -S -mem2reg | FileCheck %s

#include <arm_neon.h>

// CHECK-LABEL: @test_vbfdot_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <2 x float> [[R:%.*]] to <8 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <4 x bfloat> [[A:%.*]] to <8 x i8>
// CHECK-NEXT:    [[TMP2:%.*]] = bitcast <4 x bfloat> [[B:%.*]] to <8 x i8>
// CHECK-NEXT:    [[VBFDOT3_I:%.*]] = call <2 x float> @llvm.aarch64.neon.bfdot.v2f32.v4bf16(<2 x float> [[R]], <4 x bfloat> [[A]], <4 x bfloat> [[B]]) #[[ATTR3:[0-9]+]]
// CHECK-NEXT:    ret <2 x float> [[VBFDOT3_I]]
//
float32x2_t test_vbfdot_f32(float32x2_t r, bfloat16x4_t a, bfloat16x4_t b) {
  return vbfdot_f32(r, a, b);
}

// CHECK-LABEL: @test_vbfdotq_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <4 x float> [[R:%.*]] to <16 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <8 x bfloat> [[A:%.*]] to <16 x i8>
// CHECK-NEXT:    [[TMP2:%.*]] = bitcast <8 x bfloat> [[B:%.*]] to <16 x i8>
// CHECK-NEXT:    [[VBFDOT3_I:%.*]] = call <4 x float> @llvm.aarch64.neon.bfdot.v4f32.v8bf16(<4 x float> [[R]], <8 x bfloat> [[A]], <8 x bfloat> [[B]]) #[[ATTR3]]
// CHECK-NEXT:    ret <4 x float> [[VBFDOT3_I]]
//
float32x4_t test_vbfdotq_f32(float32x4_t r, bfloat16x8_t a, bfloat16x8_t b){
  return vbfdotq_f32(r, a, b);
}

// CHECK-LABEL: @test_vbfdot_lane_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[__REINT_144:%.*]] = alloca <4 x bfloat>, align 8
// CHECK-NEXT:    [[__REINT1_144:%.*]] = alloca <2 x float>, align 8
// CHECK-NEXT:    store <4 x bfloat> [[B:%.*]], <4 x bfloat>* [[__REINT_144]], align 8
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <4 x bfloat>* [[__REINT_144]] to <2 x float>*
// CHECK-NEXT:    [[TMP1:%.*]] = load <2 x float>, <2 x float>* [[TMP0]], align 8
// CHECK-NEXT:    [[TMP2:%.*]] = bitcast <2 x float> [[TMP1]] to <8 x i8>
// CHECK-NEXT:    [[TMP3:%.*]] = bitcast <8 x i8> [[TMP2]] to <2 x float>
// CHECK-NEXT:    [[LANE:%.*]] = shufflevector <2 x float> [[TMP3]], <2 x float> [[TMP3]], <2 x i32> zeroinitializer
// CHECK-NEXT:    store <2 x float> [[LANE]], <2 x float>* [[__REINT1_144]], align 8
// CHECK-NEXT:    [[TMP4:%.*]] = bitcast <2 x float>* [[__REINT1_144]] to <4 x bfloat>*
// CHECK-NEXT:    [[TMP5:%.*]] = load <4 x bfloat>, <4 x bfloat>* [[TMP4]], align 8
// CHECK-NEXT:    [[TMP6:%.*]] = bitcast <2 x float> [[R:%.*]] to <8 x i8>
// CHECK-NEXT:    [[TMP7:%.*]] = bitcast <4 x bfloat> [[A:%.*]] to <8 x i8>
// CHECK-NEXT:    [[TMP8:%.*]] = bitcast <4 x bfloat> [[TMP5]] to <8 x i8>
// CHECK-NEXT:    [[VBFDOT3_I:%.*]] = call <2 x float> @llvm.aarch64.neon.bfdot.v2f32.v4bf16(<2 x float> [[R]], <4 x bfloat> [[A]], <4 x bfloat> [[TMP5]]) #[[ATTR3]]
// CHECK-NEXT:    ret <2 x float> [[VBFDOT3_I]]
//
float32x2_t test_vbfdot_lane_f32(float32x2_t r, bfloat16x4_t a, bfloat16x4_t b){
  return vbfdot_lane_f32(r, a, b, 0);
}

// CHECK-LABEL: @test_vbfdotq_laneq_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[__REINT_146:%.*]] = alloca <8 x bfloat>, align 16
// CHECK-NEXT:    [[__REINT1_146:%.*]] = alloca <4 x float>, align 16
// CHECK-NEXT:    store <8 x bfloat> [[B:%.*]], <8 x bfloat>* [[__REINT_146]], align 16
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <8 x bfloat>* [[__REINT_146]] to <4 x float>*
// CHECK-NEXT:    [[TMP1:%.*]] = load <4 x float>, <4 x float>* [[TMP0]], align 16
// CHECK-NEXT:    [[TMP2:%.*]] = bitcast <4 x float> [[TMP1]] to <16 x i8>
// CHECK-NEXT:    [[TMP3:%.*]] = bitcast <16 x i8> [[TMP2]] to <4 x float>
// CHECK-NEXT:    [[LANE:%.*]] = shufflevector <4 x float> [[TMP3]], <4 x float> [[TMP3]], <4 x i32> <i32 3, i32 3, i32 3, i32 3>
// CHECK-NEXT:    store <4 x float> [[LANE]], <4 x float>* [[__REINT1_146]], align 16
// CHECK-NEXT:    [[TMP4:%.*]] = bitcast <4 x float>* [[__REINT1_146]] to <8 x bfloat>*
// CHECK-NEXT:    [[TMP5:%.*]] = load <8 x bfloat>, <8 x bfloat>* [[TMP4]], align 16
// CHECK-NEXT:    [[TMP6:%.*]] = bitcast <4 x float> [[R:%.*]] to <16 x i8>
// CHECK-NEXT:    [[TMP7:%.*]] = bitcast <8 x bfloat> [[A:%.*]] to <16 x i8>
// CHECK-NEXT:    [[TMP8:%.*]] = bitcast <8 x bfloat> [[TMP5]] to <16 x i8>
// CHECK-NEXT:    [[VBFDOT3_I:%.*]] = call <4 x float> @llvm.aarch64.neon.bfdot.v4f32.v8bf16(<4 x float> [[R]], <8 x bfloat> [[A]], <8 x bfloat> [[TMP5]]) #[[ATTR3]]
// CHECK-NEXT:    ret <4 x float> [[VBFDOT3_I]]
//
float32x4_t test_vbfdotq_laneq_f32(float32x4_t r, bfloat16x8_t a, bfloat16x8_t b) {
  return vbfdotq_laneq_f32(r, a, b, 3);
}

// CHECK-LABEL: @test_vbfdot_laneq_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[__REINT_148:%.*]] = alloca <8 x bfloat>, align 16
// CHECK-NEXT:    [[__REINT1_148:%.*]] = alloca <2 x float>, align 8
// CHECK-NEXT:    store <8 x bfloat> [[B:%.*]], <8 x bfloat>* [[__REINT_148]], align 16
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <8 x bfloat>* [[__REINT_148]] to <4 x float>*
// CHECK-NEXT:    [[TMP1:%.*]] = load <4 x float>, <4 x float>* [[TMP0]], align 16
// CHECK-NEXT:    [[TMP2:%.*]] = bitcast <4 x float> [[TMP1]] to <16 x i8>
// CHECK-NEXT:    [[TMP3:%.*]] = bitcast <16 x i8> [[TMP2]] to <4 x float>
// CHECK-NEXT:    [[LANE:%.*]] = shufflevector <4 x float> [[TMP3]], <4 x float> [[TMP3]], <2 x i32> <i32 3, i32 3>
// CHECK-NEXT:    store <2 x float> [[LANE]], <2 x float>* [[__REINT1_148]], align 8
// CHECK-NEXT:    [[TMP4:%.*]] = bitcast <2 x float>* [[__REINT1_148]] to <4 x bfloat>*
// CHECK-NEXT:    [[TMP5:%.*]] = load <4 x bfloat>, <4 x bfloat>* [[TMP4]], align 8
// CHECK-NEXT:    [[TMP6:%.*]] = bitcast <2 x float> [[R:%.*]] to <8 x i8>
// CHECK-NEXT:    [[TMP7:%.*]] = bitcast <4 x bfloat> [[A:%.*]] to <8 x i8>
// CHECK-NEXT:    [[TMP8:%.*]] = bitcast <4 x bfloat> [[TMP5]] to <8 x i8>
// CHECK-NEXT:    [[VBFDOT3_I:%.*]] = call <2 x float> @llvm.aarch64.neon.bfdot.v2f32.v4bf16(<2 x float> [[R]], <4 x bfloat> [[A]], <4 x bfloat> [[TMP5]]) #[[ATTR3]]
// CHECK-NEXT:    ret <2 x float> [[VBFDOT3_I]]
//
float32x2_t test_vbfdot_laneq_f32(float32x2_t r, bfloat16x4_t a, bfloat16x8_t b) {
  return vbfdot_laneq_f32(r, a, b, 3);
}

// CHECK-LABEL: @test_vbfdotq_lane_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[__REINT_142:%.*]] = alloca <4 x bfloat>, align 8
// CHECK-NEXT:    [[__REINT1_142:%.*]] = alloca <4 x float>, align 16
// CHECK-NEXT:    store <4 x bfloat> [[B:%.*]], <4 x bfloat>* [[__REINT_142]], align 8
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <4 x bfloat>* [[__REINT_142]] to <2 x float>*
// CHECK-NEXT:    [[TMP1:%.*]] = load <2 x float>, <2 x float>* [[TMP0]], align 8
// CHECK-NEXT:    [[TMP2:%.*]] = bitcast <2 x float> [[TMP1]] to <8 x i8>
// CHECK-NEXT:    [[TMP3:%.*]] = bitcast <8 x i8> [[TMP2]] to <2 x float>
// CHECK-NEXT:    [[LANE:%.*]] = shufflevector <2 x float> [[TMP3]], <2 x float> [[TMP3]], <4 x i32> zeroinitializer
// CHECK-NEXT:    store <4 x float> [[LANE]], <4 x float>* [[__REINT1_142]], align 16
// CHECK-NEXT:    [[TMP4:%.*]] = bitcast <4 x float>* [[__REINT1_142]] to <8 x bfloat>*
// CHECK-NEXT:    [[TMP5:%.*]] = load <8 x bfloat>, <8 x bfloat>* [[TMP4]], align 16
// CHECK-NEXT:    [[TMP6:%.*]] = bitcast <4 x float> [[R:%.*]] to <16 x i8>
// CHECK-NEXT:    [[TMP7:%.*]] = bitcast <8 x bfloat> [[A:%.*]] to <16 x i8>
// CHECK-NEXT:    [[TMP8:%.*]] = bitcast <8 x bfloat> [[TMP5]] to <16 x i8>
// CHECK-NEXT:    [[VBFDOT3_I:%.*]] = call <4 x float> @llvm.aarch64.neon.bfdot.v4f32.v8bf16(<4 x float> [[R]], <8 x bfloat> [[A]], <8 x bfloat> [[TMP5]]) #[[ATTR3]]
// CHECK-NEXT:    ret <4 x float> [[VBFDOT3_I]]
//
float32x4_t test_vbfdotq_lane_f32(float32x4_t r, bfloat16x8_t a, bfloat16x4_t b) {
  return vbfdotq_lane_f32(r, a, b, 0);
}

// CHECK-LABEL: @test_vbfmmlaq_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <4 x float> [[R:%.*]] to <16 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <8 x bfloat> [[A:%.*]] to <16 x i8>
// CHECK-NEXT:    [[TMP2:%.*]] = bitcast <8 x bfloat> [[B:%.*]] to <16 x i8>
// CHECK-NEXT:    [[VBFMMLAQ_V3_I:%.*]] = call <4 x float> @llvm.aarch64.neon.bfmmla(<4 x float> [[R]], <8 x bfloat> [[A]], <8 x bfloat> [[B]]) #[[ATTR3]]
// CHECK-NEXT:    [[VBFMMLAQ_V4_I:%.*]] = bitcast <4 x float> [[VBFMMLAQ_V3_I]] to <16 x i8>
// CHECK-NEXT:    ret <4 x float> [[VBFMMLAQ_V3_I]]
//
float32x4_t test_vbfmmlaq_f32(float32x4_t r, bfloat16x8_t a, bfloat16x8_t b) {
  return vbfmmlaq_f32(r, a, b);
}

// CHECK-LABEL: @test_vbfmlalbq_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <4 x float> [[R:%.*]] to <16 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <8 x bfloat> [[A:%.*]] to <16 x i8>
// CHECK-NEXT:    [[TMP2:%.*]] = bitcast <8 x bfloat> [[B:%.*]] to <16 x i8>
// CHECK-NEXT:    [[VBFMLALBQ_V3_I:%.*]] = call <4 x float> @llvm.aarch64.neon.bfmlalb(<4 x float> [[R]], <8 x bfloat> [[A]], <8 x bfloat> [[B]]) #[[ATTR3]]
// CHECK-NEXT:    [[VBFMLALBQ_V4_I:%.*]] = bitcast <4 x float> [[VBFMLALBQ_V3_I]] to <16 x i8>
// CHECK-NEXT:    ret <4 x float> [[VBFMLALBQ_V3_I]]
//
float32x4_t test_vbfmlalbq_f32(float32x4_t r, bfloat16x8_t a, bfloat16x8_t b) {
  return vbfmlalbq_f32(r, a, b);
}

// CHECK-LABEL: @test_vbfmlaltq_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <4 x float> [[R:%.*]] to <16 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <8 x bfloat> [[A:%.*]] to <16 x i8>
// CHECK-NEXT:    [[TMP2:%.*]] = bitcast <8 x bfloat> [[B:%.*]] to <16 x i8>
// CHECK-NEXT:    [[VBFMLALTQ_V3_I:%.*]] = call <4 x float> @llvm.aarch64.neon.bfmlalt(<4 x float> [[R]], <8 x bfloat> [[A]], <8 x bfloat> [[B]]) #[[ATTR3]]
// CHECK-NEXT:    [[VBFMLALTQ_V4_I:%.*]] = bitcast <4 x float> [[VBFMLALTQ_V3_I]] to <16 x i8>
// CHECK-NEXT:    ret <4 x float> [[VBFMLALTQ_V3_I]]
//
float32x4_t test_vbfmlaltq_f32(float32x4_t r, bfloat16x8_t a, bfloat16x8_t b) {
  return vbfmlaltq_f32(r, a, b);
}

// CHECK-LABEL: @test_vbfmlalbq_lane_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[VGET_LANE:%.*]] = extractelement <4 x bfloat> [[B:%.*]], i32 0
// CHECK-NEXT:    [[VECINIT:%.*]] = insertelement <8 x bfloat> undef, bfloat [[VGET_LANE]], i32 0
// CHECK-NEXT:    [[VGET_LANE3:%.*]] = extractelement <4 x bfloat> [[B]], i32 0
// CHECK-NEXT:    [[VECINIT5:%.*]] = insertelement <8 x bfloat> [[VECINIT]], bfloat [[VGET_LANE3]], i32 1
// CHECK-NEXT:    [[VGET_LANE8:%.*]] = extractelement <4 x bfloat> [[B]], i32 0
// CHECK-NEXT:    [[VECINIT10:%.*]] = insertelement <8 x bfloat> [[VECINIT5]], bfloat [[VGET_LANE8]], i32 2
// CHECK-NEXT:    [[VGET_LANE13:%.*]] = extractelement <4 x bfloat> [[B]], i32 0
// CHECK-NEXT:    [[VECINIT15:%.*]] = insertelement <8 x bfloat> [[VECINIT10]], bfloat [[VGET_LANE13]], i32 3
// CHECK-NEXT:    [[VGET_LANE18:%.*]] = extractelement <4 x bfloat> [[B]], i32 0
// CHECK-NEXT:    [[VECINIT20:%.*]] = insertelement <8 x bfloat> [[VECINIT15]], bfloat [[VGET_LANE18]], i32 4
// CHECK-NEXT:    [[VGET_LANE23:%.*]] = extractelement <4 x bfloat> [[B]], i32 0
// CHECK-NEXT:    [[VECINIT25:%.*]] = insertelement <8 x bfloat> [[VECINIT20]], bfloat [[VGET_LANE23]], i32 5
// CHECK-NEXT:    [[VGET_LANE28:%.*]] = extractelement <4 x bfloat> [[B]], i32 0
// CHECK-NEXT:    [[VECINIT30:%.*]] = insertelement <8 x bfloat> [[VECINIT25]], bfloat [[VGET_LANE28]], i32 6
// CHECK-NEXT:    [[VGET_LANE33:%.*]] = extractelement <4 x bfloat> [[B]], i32 0
// CHECK-NEXT:    [[VECINIT35:%.*]] = insertelement <8 x bfloat> [[VECINIT30]], bfloat [[VGET_LANE33]], i32 7
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <4 x float> [[R:%.*]] to <16 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <8 x bfloat> [[A:%.*]] to <16 x i8>
// CHECK-NEXT:    [[TMP2:%.*]] = bitcast <8 x bfloat> [[VECINIT35]] to <16 x i8>
// CHECK-NEXT:    [[VBFMLALBQ_V3_I:%.*]] = call <4 x float> @llvm.aarch64.neon.bfmlalb(<4 x float> [[R]], <8 x bfloat> [[A]], <8 x bfloat> [[VECINIT35]]) #[[ATTR3]]
// CHECK-NEXT:    [[VBFMLALBQ_V4_I:%.*]] = bitcast <4 x float> [[VBFMLALBQ_V3_I]] to <16 x i8>
// CHECK-NEXT:    ret <4 x float> [[VBFMLALBQ_V3_I]]
//
float32x4_t test_vbfmlalbq_lane_f32(float32x4_t r, bfloat16x8_t a, bfloat16x4_t b) {
  return vbfmlalbq_lane_f32(r, a, b, 0);
}

// CHECK-LABEL: @test_vbfmlalbq_laneq_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[VGETQ_LANE:%.*]] = extractelement <8 x bfloat> [[B:%.*]], i32 3
// CHECK-NEXT:    [[VECINIT:%.*]] = insertelement <8 x bfloat> undef, bfloat [[VGETQ_LANE]], i32 0
// CHECK-NEXT:    [[VGETQ_LANE3:%.*]] = extractelement <8 x bfloat> [[B]], i32 3
// CHECK-NEXT:    [[VECINIT5:%.*]] = insertelement <8 x bfloat> [[VECINIT]], bfloat [[VGETQ_LANE3]], i32 1
// CHECK-NEXT:    [[VGETQ_LANE8:%.*]] = extractelement <8 x bfloat> [[B]], i32 3
// CHECK-NEXT:    [[VECINIT10:%.*]] = insertelement <8 x bfloat> [[VECINIT5]], bfloat [[VGETQ_LANE8]], i32 2
// CHECK-NEXT:    [[VGETQ_LANE13:%.*]] = extractelement <8 x bfloat> [[B]], i32 3
// CHECK-NEXT:    [[VECINIT15:%.*]] = insertelement <8 x bfloat> [[VECINIT10]], bfloat [[VGETQ_LANE13]], i32 3
// CHECK-NEXT:    [[VGETQ_LANE18:%.*]] = extractelement <8 x bfloat> [[B]], i32 3
// CHECK-NEXT:    [[VECINIT20:%.*]] = insertelement <8 x bfloat> [[VECINIT15]], bfloat [[VGETQ_LANE18]], i32 4
// CHECK-NEXT:    [[VGETQ_LANE23:%.*]] = extractelement <8 x bfloat> [[B]], i32 3
// CHECK-NEXT:    [[VECINIT25:%.*]] = insertelement <8 x bfloat> [[VECINIT20]], bfloat [[VGETQ_LANE23]], i32 5
// CHECK-NEXT:    [[VGETQ_LANE28:%.*]] = extractelement <8 x bfloat> [[B]], i32 3
// CHECK-NEXT:    [[VECINIT30:%.*]] = insertelement <8 x bfloat> [[VECINIT25]], bfloat [[VGETQ_LANE28]], i32 6
// CHECK-NEXT:    [[VGETQ_LANE33:%.*]] = extractelement <8 x bfloat> [[B]], i32 3
// CHECK-NEXT:    [[VECINIT35:%.*]] = insertelement <8 x bfloat> [[VECINIT30]], bfloat [[VGETQ_LANE33]], i32 7
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <4 x float> [[R:%.*]] to <16 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <8 x bfloat> [[A:%.*]] to <16 x i8>
// CHECK-NEXT:    [[TMP2:%.*]] = bitcast <8 x bfloat> [[VECINIT35]] to <16 x i8>
// CHECK-NEXT:    [[VBFMLALBQ_V3_I:%.*]] = call <4 x float> @llvm.aarch64.neon.bfmlalb(<4 x float> [[R]], <8 x bfloat> [[A]], <8 x bfloat> [[VECINIT35]]) #[[ATTR3]]
// CHECK-NEXT:    [[VBFMLALBQ_V4_I:%.*]] = bitcast <4 x float> [[VBFMLALBQ_V3_I]] to <16 x i8>
// CHECK-NEXT:    ret <4 x float> [[VBFMLALBQ_V3_I]]
//
float32x4_t test_vbfmlalbq_laneq_f32(float32x4_t r, bfloat16x8_t a, bfloat16x8_t b) {
  return vbfmlalbq_laneq_f32(r, a, b, 3);
}

// CHECK-LABEL: @test_vbfmlaltq_lane_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[VGET_LANE:%.*]] = extractelement <4 x bfloat> [[B:%.*]], i32 0
// CHECK-NEXT:    [[VECINIT:%.*]] = insertelement <8 x bfloat> undef, bfloat [[VGET_LANE]], i32 0
// CHECK-NEXT:    [[VGET_LANE3:%.*]] = extractelement <4 x bfloat> [[B]], i32 0
// CHECK-NEXT:    [[VECINIT5:%.*]] = insertelement <8 x bfloat> [[VECINIT]], bfloat [[VGET_LANE3]], i32 1
// CHECK-NEXT:    [[VGET_LANE8:%.*]] = extractelement <4 x bfloat> [[B]], i32 0
// CHECK-NEXT:    [[VECINIT10:%.*]] = insertelement <8 x bfloat> [[VECINIT5]], bfloat [[VGET_LANE8]], i32 2
// CHECK-NEXT:    [[VGET_LANE13:%.*]] = extractelement <4 x bfloat> [[B]], i32 0
// CHECK-NEXT:    [[VECINIT15:%.*]] = insertelement <8 x bfloat> [[VECINIT10]], bfloat [[VGET_LANE13]], i32 3
// CHECK-NEXT:    [[VGET_LANE18:%.*]] = extractelement <4 x bfloat> [[B]], i32 0
// CHECK-NEXT:    [[VECINIT20:%.*]] = insertelement <8 x bfloat> [[VECINIT15]], bfloat [[VGET_LANE18]], i32 4
// CHECK-NEXT:    [[VGET_LANE23:%.*]] = extractelement <4 x bfloat> [[B]], i32 0
// CHECK-NEXT:    [[VECINIT25:%.*]] = insertelement <8 x bfloat> [[VECINIT20]], bfloat [[VGET_LANE23]], i32 5
// CHECK-NEXT:    [[VGET_LANE28:%.*]] = extractelement <4 x bfloat> [[B]], i32 0
// CHECK-NEXT:    [[VECINIT30:%.*]] = insertelement <8 x bfloat> [[VECINIT25]], bfloat [[VGET_LANE28]], i32 6
// CHECK-NEXT:    [[VGET_LANE33:%.*]] = extractelement <4 x bfloat> [[B]], i32 0
// CHECK-NEXT:    [[VECINIT35:%.*]] = insertelement <8 x bfloat> [[VECINIT30]], bfloat [[VGET_LANE33]], i32 7
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <4 x float> [[R:%.*]] to <16 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <8 x bfloat> [[A:%.*]] to <16 x i8>
// CHECK-NEXT:    [[TMP2:%.*]] = bitcast <8 x bfloat> [[VECINIT35]] to <16 x i8>
// CHECK-NEXT:    [[VBFMLALTQ_V3_I:%.*]] = call <4 x float> @llvm.aarch64.neon.bfmlalt(<4 x float> [[R]], <8 x bfloat> [[A]], <8 x bfloat> [[VECINIT35]]) #[[ATTR3]]
// CHECK-NEXT:    [[VBFMLALTQ_V4_I:%.*]] = bitcast <4 x float> [[VBFMLALTQ_V3_I]] to <16 x i8>
// CHECK-NEXT:    ret <4 x float> [[VBFMLALTQ_V3_I]]
//
float32x4_t test_vbfmlaltq_lane_f32(float32x4_t r, bfloat16x8_t a, bfloat16x4_t b) {
  return vbfmlaltq_lane_f32(r, a, b, 0);
}

// CHECK-LABEL: @test_vbfmlaltq_laneq_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[VGETQ_LANE:%.*]] = extractelement <8 x bfloat> [[B:%.*]], i32 3
// CHECK-NEXT:    [[VECINIT:%.*]] = insertelement <8 x bfloat> undef, bfloat [[VGETQ_LANE]], i32 0
// CHECK-NEXT:    [[VGETQ_LANE3:%.*]] = extractelement <8 x bfloat> [[B]], i32 3
// CHECK-NEXT:    [[VECINIT5:%.*]] = insertelement <8 x bfloat> [[VECINIT]], bfloat [[VGETQ_LANE3]], i32 1
// CHECK-NEXT:    [[VGETQ_LANE8:%.*]] = extractelement <8 x bfloat> [[B]], i32 3
// CHECK-NEXT:    [[VECINIT10:%.*]] = insertelement <8 x bfloat> [[VECINIT5]], bfloat [[VGETQ_LANE8]], i32 2
// CHECK-NEXT:    [[VGETQ_LANE13:%.*]] = extractelement <8 x bfloat> [[B]], i32 3
// CHECK-NEXT:    [[VECINIT15:%.*]] = insertelement <8 x bfloat> [[VECINIT10]], bfloat [[VGETQ_LANE13]], i32 3
// CHECK-NEXT:    [[VGETQ_LANE18:%.*]] = extractelement <8 x bfloat> [[B]], i32 3
// CHECK-NEXT:    [[VECINIT20:%.*]] = insertelement <8 x bfloat> [[VECINIT15]], bfloat [[VGETQ_LANE18]], i32 4
// CHECK-NEXT:    [[VGETQ_LANE23:%.*]] = extractelement <8 x bfloat> [[B]], i32 3
// CHECK-NEXT:    [[VECINIT25:%.*]] = insertelement <8 x bfloat> [[VECINIT20]], bfloat [[VGETQ_LANE23]], i32 5
// CHECK-NEXT:    [[VGETQ_LANE28:%.*]] = extractelement <8 x bfloat> [[B]], i32 3
// CHECK-NEXT:    [[VECINIT30:%.*]] = insertelement <8 x bfloat> [[VECINIT25]], bfloat [[VGETQ_LANE28]], i32 6
// CHECK-NEXT:    [[VGETQ_LANE33:%.*]] = extractelement <8 x bfloat> [[B]], i32 3
// CHECK-NEXT:    [[VECINIT35:%.*]] = insertelement <8 x bfloat> [[VECINIT30]], bfloat [[VGETQ_LANE33]], i32 7
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <4 x float> [[R:%.*]] to <16 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <8 x bfloat> [[A:%.*]] to <16 x i8>
// CHECK-NEXT:    [[TMP2:%.*]] = bitcast <8 x bfloat> [[VECINIT35]] to <16 x i8>
// CHECK-NEXT:    [[VBFMLALTQ_V3_I:%.*]] = call <4 x float> @llvm.aarch64.neon.bfmlalt(<4 x float> [[R]], <8 x bfloat> [[A]], <8 x bfloat> [[VECINIT35]]) #[[ATTR3]]
// CHECK-NEXT:    [[VBFMLALTQ_V4_I:%.*]] = bitcast <4 x float> [[VBFMLALTQ_V3_I]] to <16 x i8>
// CHECK-NEXT:    ret <4 x float> [[VBFMLALTQ_V3_I]]
//
float32x4_t test_vbfmlaltq_laneq_f32(float32x4_t r, bfloat16x8_t a, bfloat16x8_t b) {
  return vbfmlaltq_laneq_f32(r, a, b, 3);
}
