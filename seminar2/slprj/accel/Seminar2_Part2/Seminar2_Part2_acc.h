#ifndef RTW_HEADER_Seminar2_Part2_acc_h_
#define RTW_HEADER_Seminar2_Part2_acc_h_
#ifndef Seminar2_Part2_acc_COMMON_INCLUDES_
#define Seminar2_Part2_acc_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME simulink_only_sfcn
#define S_FUNCTION_LEVEL 2
#ifndef RTW_GENERATED_S_FUNCTION
#define RTW_GENERATED_S_FUNCTION
#endif
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "Seminar2_Part2_acc_types.h"
#include <stddef.h>
#include <float.h>
#include "mwmathutil.h"
#include <string.h>
#include "rt_defines.h"
#include "rt_nonfinite.h"
typedef struct { creal_T B_6_16_0 ; real_T B_6_0_0 ; real_T B_6_1_0 ; real_T
B_6_3_0 ; real_T B_6_5_0 ; real_T B_6_7_0 ; real_T B_6_8_0 ; real_T B_6_9_0 ;
real_T B_6_11_0 ; real_T B_6_13_0 ; real_T B_6_15_0 ; real_T B_6_19_0 ;
real_T B_6_21_0 ; real_T B_6_22_0 ; real_T B_5_0_0 ; real_T B_5_1_0 ; real_T
B_4_0_0 ; real_T B_4_1_0 ; } B_RMS_Seminar2_Part2_T ; typedef struct { real_T
Memory_PreviousInput ; real_T Memory_PreviousInput_a ; struct { real_T
modelTStart ; } TransportDelay_RWORK ; struct { real_T modelTStart ; }
TransportDelay_RWORK_e ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK_j ; int32_T RMS_sysIdxToRun ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_p ; struct { int_T Tail ; int_T
Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
TransportDelay_IWORK ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } TransportDelay_IWORK_m ; int8_T
RMS_SubsysRanBC ; boolean_T RMS_MODE ; char_T pad_RMS_MODE [ 2 ] ; }
DW_RMS_Seminar2_Part2_T ; typedef struct { real_T integrator_CSTATE_o5 ;
real_T integrator_CSTATE_e ; } X_RMS_Seminar2_Part2_T ; typedef struct {
real_T integrator_CSTATE_o5 ; real_T integrator_CSTATE_e ; }
XDot_RMS_Seminar2_Part2_T ; typedef struct { boolean_T integrator_CSTATE_o5 ;
boolean_T integrator_CSTATE_e ; } XDis_RMS_Seminar2_Part2_T ; typedef struct
{ real_T integrator_CSTATE_o5 ; real_T integrator_CSTATE_e ; }
XAbsTol_RMS_Seminar2_Part2_T ; typedef struct { real_T integrator_CSTATE_o5 ;
real_T integrator_CSTATE_e ; } XPtMin_RMS_Seminar2_Part2_T ; typedef struct {
real_T integrator_CSTATE_o5 ; real_T integrator_CSTATE_e ; }
XPtMax_RMS_Seminar2_Part2_T ; typedef struct { real_T B_8_1_0 ; real_T
B_8_2_0 ; real_T B_8_3_0 ; real_T B_8_4_0 ; real_T B_8_7_0 ; real_T B_8_8_0 ;
real_T B_8_9_0 ; real_T B_8_10_0 ; real_T B_7_0_0 ; real_T B_7_1_0 ; }
B_TrueRMS_Seminar2_Part2_T ; typedef struct { real_T Memory_PreviousInput ;
struct { real_T modelTStart ; } TransportDelay_RWORK ; struct { void *
TUbufferPtrs [ 2 ] ; } TransportDelay_PWORK ; int32_T TrueRMS_sysIdxToRun ;
int32_T TmpAtomicSubsysAtSwitchInport1_sysIdxToRun ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
TransportDelay_IWORK ; int_T Saturationtoavoidnegativesqrt_MODE ; int8_T
TrueRMS_SubsysRanBC ; int8_T Sqrt_DWORK1 ; boolean_T TrueRMS_MODE ; char_T
pad_TrueRMS_MODE [ 5 ] ; } DW_TrueRMS_Seminar2_Part2_T ; typedef struct {
real_T integrator_CSTATE_o ; } X_TrueRMS_Seminar2_Part2_T ; typedef struct {
real_T integrator_CSTATE_o ; } XDot_TrueRMS_Seminar2_Part2_T ; typedef struct
{ boolean_T integrator_CSTATE_o ; } XDis_TrueRMS_Seminar2_Part2_T ; typedef
struct { real_T integrator_CSTATE_o ; } XAbsTol_TrueRMS_Seminar2_Part2_T ;
typedef struct { real_T integrator_CSTATE_o ; }
XPtMin_TrueRMS_Seminar2_Part2_T ; typedef struct { real_T integrator_CSTATE_o
; } XPtMax_TrueRMS_Seminar2_Part2_T ; typedef struct { real_T
Saturationtoavoidnegativesqrt_UprLim_ZC ; real_T
Saturationtoavoidnegativesqrt_LwrLim_ZC ; } ZCV_TrueRMS_Seminar2_Part2_T ;
typedef struct { ZCSigState Saturationtoavoidnegativesqrt_UprLim_ZCE ;
ZCSigState Saturationtoavoidnegativesqrt_LwrLim_ZCE ; }
ZCE_TrueRMS_Seminar2_Part2_T ; typedef struct { real_T B_30_0_0 ; real_T
B_30_1_0 ; real_T B_30_2_0 ; real_T B_30_3_0 [ 11 ] ; real_T B_30_3_1 [ 12 ]
; real_T B_30_4_0 ; real_T B_30_8_0 ; real_T B_30_12_0 [ 2 ] ; real_T
B_30_17_0 [ 2 ] ; real_T B_30_22_0 [ 2 ] ; real_T B_30_27_0 [ 2 ] ; real_T
B_30_32_0 [ 2 ] ; real_T B_30_37_0 [ 2 ] ; real_T B_30_53_0 ; real_T
B_30_56_0 ; real_T B_30_58_0 ; real_T B_30_60_0 ; real_T B_30_70_0 ; real_T
B_30_75_0 ; real_T B_30_76_0 ; real_T B_30_77_0 ; real_T B_30_78_0 [ 3 ] ;
real_T B_30_79_0 ; real_T B_30_81_0 [ 2 ] ; real_T B_30_82_0 ; real_T
B_30_83_0 ; real_T B_30_84_0 ; real_T B_30_85_0 [ 3 ] ; real_T B_30_86_0 [ 2
] ; real_T B_30_87_0 [ 2 ] ; real_T B_30_88_0 [ 2 ] ; real_T B_30_89_0 [ 2 ]
; real_T B_30_90_0 [ 2 ] ; real_T B_30_128_0 ; real_T B_30_133_0 ; real_T
B_30_138_0 ; real_T B_30_141_0 ; real_T B_30_0_0_m ; real_T B_30_1_0_c ;
real_T B_30_17_0_k ; real_T B_30_18_0 ; real_T B_30_19_0 ; real_T B_30_20_0 ;
real_T B_30_21_0 ; real_T B_30_22_0_c ; real_T B_30_23_0 ; real_T B_30_24_0 ;
real_T B_30_25_0 ; real_T B_30_26_0 ; real_T B_30_27_0_b ; real_T B_30_28_0 ;
real_T B_0_0_0 [ 3 ] ; real_T B_0_1_1 ; boolean_T B_30_3_0_p ; boolean_T
B_30_4_0_c ; boolean_T B_30_6_0 ; boolean_T B_30_7_0 ; boolean_T B_30_9_0 ;
boolean_T B_30_10_0 ; boolean_T B_30_12_0_f ; boolean_T B_30_13_0 ; boolean_T
B_30_15_0 ; boolean_T B_30_16_0 ; char_T pad_B_30_16_0 [ 6 ] ;
B_TrueRMS_Seminar2_Part2_T TrueRMS_e ; B_RMS_Seminar2_Part2_T RMS_b ;
B_TrueRMS_Seminar2_Part2_T TrueRMS_m ; B_RMS_Seminar2_Part2_T RMS_m ;
B_TrueRMS_Seminar2_Part2_T TrueRMS_i ; B_RMS_Seminar2_Part2_T RMS_g ;
B_TrueRMS_Seminar2_Part2_T TrueRMS_j ; B_RMS_Seminar2_Part2_T RMS_l ;
B_TrueRMS_Seminar2_Part2_T TrueRMS ; B_RMS_Seminar2_Part2_T RMS ; }
B_Seminar2_Part2_T ; typedef struct { real_T Memory_PreviousInput ; real_T
StateSpace_RWORK [ 2 ] ; struct { real_T modelTStart ; } TransportDelay_RWORK
; struct { real_T modelTStart ; } TransportDelay_RWORK_a ; struct { real_T
modelTStart ; } TransportDelay_RWORK_g ; struct { real_T modelTStart ; }
TransportDelay_RWORK_o ; struct { real_T modelTStart ; }
TransportDelay_RWORK_l ; struct { real_T modelTStart ; }
TransportDelay_RWORK_h ; struct { real_T modelTStart ; }
TransportDelay_RWORK_f ; void * StateSpace_PWORK [ 22 ] ; struct { void *
TUbufferPtrs [ 4 ] ; } TransportDelay_PWORK ; struct { void * TUbufferPtrs [
4 ] ; } TransportDelay_PWORK_m ; struct { void * TUbufferPtrs [ 4 ] ; }
TransportDelay_PWORK_g ; struct { void * TUbufferPtrs [ 4 ] ; }
TransportDelay_PWORK_i ; struct { void * TUbufferPtrs [ 4 ] ; }
TransportDelay_PWORK_n ; struct { void * TUbufferPtrs [ 4 ] ; }
TransportDelay_PWORK_p ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK_f ; void * Scope1_PWORK ; void * Scope2_PWORK ; void *
Scope_PWORK ; int32_T TmpAtomicSubsysAtSwitchInport1_sysIdxToRun ; int32_T
TmpAtomicSubsysAtMultiportSwitchInport4_sysIdxToRun ; int32_T
TmpAtomicSubsysAtMultiportSwitchInport3_sysIdxToRun ; int32_T
TmpAtomicSubsysAtMultiportSwitchInport2_sysIdxToRun ; int32_T
MATLABFunction_sysIdxToRun ; int_T StateSpace_IWORK [ 23 ] ; struct { int_T
Tail [ 2 ] ; int_T Head [ 2 ] ; int_T Last [ 2 ] ; int_T CircularBufSize [ 2
] ; int_T MaxNewBufSize ; } TransportDelay_IWORK ; struct { int_T Tail [ 2 ]
; int_T Head [ 2 ] ; int_T Last [ 2 ] ; int_T CircularBufSize [ 2 ] ; int_T
MaxNewBufSize ; } TransportDelay_IWORK_g ; struct { int_T Tail [ 2 ] ; int_T
Head [ 2 ] ; int_T Last [ 2 ] ; int_T CircularBufSize [ 2 ] ; int_T
MaxNewBufSize ; } TransportDelay_IWORK_j ; struct { int_T Tail [ 2 ] ; int_T
Head [ 2 ] ; int_T Last [ 2 ] ; int_T CircularBufSize [ 2 ] ; int_T
MaxNewBufSize ; } TransportDelay_IWORK_e ; struct { int_T Tail [ 2 ] ; int_T
Head [ 2 ] ; int_T Last [ 2 ] ; int_T CircularBufSize [ 2 ] ; int_T
MaxNewBufSize ; } TransportDelay_IWORK_l ; struct { int_T Tail [ 2 ] ; int_T
Head [ 2 ] ; int_T Last [ 2 ] ; int_T CircularBufSize [ 2 ] ; int_T
MaxNewBufSize ; } TransportDelay_IWORK_f ; struct { int_T Tail ; int_T Head ;
int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
TransportDelay_IWORK_e2 ; char StateSpace_MODE [ 28 ] ; int8_T Sqrt_DWORK1 ;
char_T pad_Sqrt_DWORK1 [ 7 ] ; DW_TrueRMS_Seminar2_Part2_T TrueRMS_e ;
DW_RMS_Seminar2_Part2_T RMS_b ; DW_TrueRMS_Seminar2_Part2_T TrueRMS_m ;
DW_RMS_Seminar2_Part2_T RMS_m ; DW_TrueRMS_Seminar2_Part2_T TrueRMS_i ;
DW_RMS_Seminar2_Part2_T RMS_g ; DW_TrueRMS_Seminar2_Part2_T TrueRMS_j ;
DW_RMS_Seminar2_Part2_T RMS_l ; DW_TrueRMS_Seminar2_Part2_T TrueRMS ;
DW_RMS_Seminar2_Part2_T RMS ; } DW_Seminar2_Part2_T ; typedef struct { real_T
StateSpace_CSTATE [ 7 ] ; real_T Integrator_CSTATE [ 2 ] ; real_T
Integrator_CSTATE_j [ 2 ] ; real_T Integrator_CSTATE_b [ 2 ] ; real_T
Integrator_CSTATE_m [ 2 ] ; real_T Integrator_CSTATE_jh [ 2 ] ; real_T
Integrator_CSTATE_o [ 2 ] ; real_T integrator_CSTATE ; real_T
Integrator_CSTATE_g ; X_TrueRMS_Seminar2_Part2_T TrueRMS_e ;
X_RMS_Seminar2_Part2_T RMS_b ; X_TrueRMS_Seminar2_Part2_T TrueRMS_m ;
X_RMS_Seminar2_Part2_T RMS_m ; X_TrueRMS_Seminar2_Part2_T TrueRMS_i ;
X_RMS_Seminar2_Part2_T RMS_g ; X_TrueRMS_Seminar2_Part2_T TrueRMS_j ;
X_RMS_Seminar2_Part2_T RMS_l ; X_TrueRMS_Seminar2_Part2_T TrueRMS ;
X_RMS_Seminar2_Part2_T RMS ; } X_Seminar2_Part2_T ; typedef int_T
PeriodicIndX_Seminar2_Part2_T [ 1 ] ; typedef real_T
PeriodicRngX_Seminar2_Part2_T [ 2 ] ; typedef struct { real_T
StateSpace_CSTATE [ 7 ] ; real_T Integrator_CSTATE [ 2 ] ; real_T
Integrator_CSTATE_j [ 2 ] ; real_T Integrator_CSTATE_b [ 2 ] ; real_T
Integrator_CSTATE_m [ 2 ] ; real_T Integrator_CSTATE_jh [ 2 ] ; real_T
Integrator_CSTATE_o [ 2 ] ; real_T integrator_CSTATE ; real_T
Integrator_CSTATE_g ; XDot_TrueRMS_Seminar2_Part2_T TrueRMS_e ;
XDot_RMS_Seminar2_Part2_T RMS_b ; XDot_TrueRMS_Seminar2_Part2_T TrueRMS_m ;
XDot_RMS_Seminar2_Part2_T RMS_m ; XDot_TrueRMS_Seminar2_Part2_T TrueRMS_i ;
XDot_RMS_Seminar2_Part2_T RMS_g ; XDot_TrueRMS_Seminar2_Part2_T TrueRMS_j ;
XDot_RMS_Seminar2_Part2_T RMS_l ; XDot_TrueRMS_Seminar2_Part2_T TrueRMS ;
XDot_RMS_Seminar2_Part2_T RMS ; } XDot_Seminar2_Part2_T ; typedef struct {
boolean_T StateSpace_CSTATE [ 7 ] ; boolean_T Integrator_CSTATE [ 2 ] ;
boolean_T Integrator_CSTATE_j [ 2 ] ; boolean_T Integrator_CSTATE_b [ 2 ] ;
boolean_T Integrator_CSTATE_m [ 2 ] ; boolean_T Integrator_CSTATE_jh [ 2 ] ;
boolean_T Integrator_CSTATE_o [ 2 ] ; boolean_T integrator_CSTATE ; boolean_T
Integrator_CSTATE_g ; XDis_TrueRMS_Seminar2_Part2_T TrueRMS_e ;
XDis_RMS_Seminar2_Part2_T RMS_b ; XDis_TrueRMS_Seminar2_Part2_T TrueRMS_m ;
XDis_RMS_Seminar2_Part2_T RMS_m ; XDis_TrueRMS_Seminar2_Part2_T TrueRMS_i ;
XDis_RMS_Seminar2_Part2_T RMS_g ; XDis_TrueRMS_Seminar2_Part2_T TrueRMS_j ;
XDis_RMS_Seminar2_Part2_T RMS_l ; XDis_TrueRMS_Seminar2_Part2_T TrueRMS ;
XDis_RMS_Seminar2_Part2_T RMS ; } XDis_Seminar2_Part2_T ; typedef struct {
real_T StateSpace_CSTATE [ 7 ] ; real_T Integrator_CSTATE [ 2 ] ; real_T
Integrator_CSTATE_j [ 2 ] ; real_T Integrator_CSTATE_b [ 2 ] ; real_T
Integrator_CSTATE_m [ 2 ] ; real_T Integrator_CSTATE_jh [ 2 ] ; real_T
Integrator_CSTATE_o [ 2 ] ; real_T integrator_CSTATE ; real_T
Integrator_CSTATE_g ; XAbsTol_TrueRMS_Seminar2_Part2_T TrueRMS_e ;
XAbsTol_RMS_Seminar2_Part2_T RMS_b ; XAbsTol_TrueRMS_Seminar2_Part2_T
TrueRMS_m ; XAbsTol_RMS_Seminar2_Part2_T RMS_m ;
XAbsTol_TrueRMS_Seminar2_Part2_T TrueRMS_i ; XAbsTol_RMS_Seminar2_Part2_T
RMS_g ; XAbsTol_TrueRMS_Seminar2_Part2_T TrueRMS_j ;
XAbsTol_RMS_Seminar2_Part2_T RMS_l ; XAbsTol_TrueRMS_Seminar2_Part2_T TrueRMS
; XAbsTol_RMS_Seminar2_Part2_T RMS ; } CStateAbsTol_Seminar2_Part2_T ;
typedef struct { real_T StateSpace_CSTATE [ 7 ] ; real_T Integrator_CSTATE [
2 ] ; real_T Integrator_CSTATE_j [ 2 ] ; real_T Integrator_CSTATE_b [ 2 ] ;
real_T Integrator_CSTATE_m [ 2 ] ; real_T Integrator_CSTATE_jh [ 2 ] ; real_T
Integrator_CSTATE_o [ 2 ] ; real_T integrator_CSTATE ; real_T
Integrator_CSTATE_g ; XPtMin_TrueRMS_Seminar2_Part2_T TrueRMS_e ;
XPtMin_RMS_Seminar2_Part2_T RMS_b ; XPtMin_TrueRMS_Seminar2_Part2_T TrueRMS_m
; XPtMin_RMS_Seminar2_Part2_T RMS_m ; XPtMin_TrueRMS_Seminar2_Part2_T
TrueRMS_i ; XPtMin_RMS_Seminar2_Part2_T RMS_g ;
XPtMin_TrueRMS_Seminar2_Part2_T TrueRMS_j ; XPtMin_RMS_Seminar2_Part2_T RMS_l
; XPtMin_TrueRMS_Seminar2_Part2_T TrueRMS ; XPtMin_RMS_Seminar2_Part2_T RMS ;
} CXPtMin_Seminar2_Part2_T ; typedef struct { real_T StateSpace_CSTATE [ 7 ]
; real_T Integrator_CSTATE [ 2 ] ; real_T Integrator_CSTATE_j [ 2 ] ; real_T
Integrator_CSTATE_b [ 2 ] ; real_T Integrator_CSTATE_m [ 2 ] ; real_T
Integrator_CSTATE_jh [ 2 ] ; real_T Integrator_CSTATE_o [ 2 ] ; real_T
integrator_CSTATE ; real_T Integrator_CSTATE_g ;
XPtMax_TrueRMS_Seminar2_Part2_T TrueRMS_e ; XPtMax_RMS_Seminar2_Part2_T RMS_b
; XPtMax_TrueRMS_Seminar2_Part2_T TrueRMS_m ; XPtMax_RMS_Seminar2_Part2_T
RMS_m ; XPtMax_TrueRMS_Seminar2_Part2_T TrueRMS_i ;
XPtMax_RMS_Seminar2_Part2_T RMS_g ; XPtMax_TrueRMS_Seminar2_Part2_T TrueRMS_j
; XPtMax_RMS_Seminar2_Part2_T RMS_l ; XPtMax_TrueRMS_Seminar2_Part2_T TrueRMS
; XPtMax_RMS_Seminar2_Part2_T RMS ; } CXPtMax_Seminar2_Part2_T ; typedef
struct { real_T StateSpace_Sf0_ZC [ 7 ] ; ZCV_TrueRMS_Seminar2_Part2_T
TrueRMS_e ; ZCV_TrueRMS_Seminar2_Part2_T TrueRMS_m ;
ZCV_TrueRMS_Seminar2_Part2_T TrueRMS_i ; ZCV_TrueRMS_Seminar2_Part2_T
TrueRMS_j ; ZCV_TrueRMS_Seminar2_Part2_T TrueRMS ; } ZCV_Seminar2_Part2_T ;
typedef struct { ZCSigState StateSpace_Sf0_ZCE [ 7 ] ;
ZCE_TrueRMS_Seminar2_Part2_T TrueRMS_e ; ZCE_TrueRMS_Seminar2_Part2_T
TrueRMS_m ; ZCE_TrueRMS_Seminar2_Part2_T TrueRMS_i ;
ZCE_TrueRMS_Seminar2_Part2_T TrueRMS_j ; ZCE_TrueRMS_Seminar2_Part2_T TrueRMS
; } PrevZCX_Seminar2_Part2_T ; struct P_RMS_Seminar2_Part2_T_ { real_T P_0 ;
real_T P_1 ; real_T P_2 ; real_T P_3 ; real_T P_4 ; real_T P_5 ; real_T P_6 ;
real_T P_7 ; real_T P_8 ; real_T P_9 ; real_T P_10 ; real_T P_11 ; real_T
P_12 ; real_T P_13 ; real_T P_14 ; real_T P_15 ; real_T P_16 ; real_T P_17 ;
real_T P_18 ; real_T P_19 ; real_T P_20 ; real_T P_21 ; } ; struct
P_TrueRMS_Seminar2_Part2_T_ { real_T P_0 ; real_T P_1 ; real_T P_2 ; real_T
P_3 ; real_T P_4 ; real_T P_5 ; real_T P_6 ; real_T P_7 ; real_T P_8 ; } ;
struct P_Seminar2_Part2_T_ { real_T P_0 ; real_T P_1 ; real_T P_2 ; real_T
P_3 ; real_T P_4 ; real_T P_5 ; real_T P_6 ; real_T P_7 ; real_T P_8 ; real_T
P_9 ; real_T P_10 ; real_T P_11 ; real_T P_12 ; real_T P_13 ; real_T P_14 ;
real_T P_15 ; real_T P_16 ; real_T P_17 ; real_T P_18 ; real_T P_19 ; real_T
P_20 ; real_T P_21 ; real_T P_22 [ 2 ] ; real_T P_23 [ 1272 ] ; real_T P_24 [
2 ] ; real_T P_25 [ 4 ] ; real_T P_26 [ 2 ] ; real_T P_27 [ 7 ] ; real_T P_28
[ 2 ] ; real_T P_29 [ 1749 ] ; real_T P_30 [ 2 ] ; real_T P_31 [ 12 ] ;
real_T P_32 [ 2 ] ; real_T P_33 [ 6 ] ; real_T P_34 [ 2 ] ; real_T P_35 [ 6 ]
; real_T P_36 [ 2 ] ; real_T P_37 [ 6 ] ; real_T P_38 [ 2 ] ; real_T P_39 ;
real_T P_40 [ 2 ] ; real_T P_41 ; real_T P_42 ; real_T P_43 ; real_T P_44 ;
real_T P_45 ; real_T P_46 ; real_T P_47 ; real_T P_48 ; real_T P_49 ; real_T
P_50 ; real_T P_51 ; real_T P_52 ; real_T P_53 ; real_T P_54 ; real_T P_55 ;
real_T P_56 ; real_T P_57 ; real_T P_58 ; real_T P_59 ; real_T P_60 ; real_T
P_61 ; real_T P_62 ; real_T P_63 ; real_T P_64 ; real_T P_65 ; real_T P_66 ;
real_T P_67 ; real_T P_68 ; real_T P_69 ; real_T P_70 ; real_T P_71 ; real_T
P_72 ; real_T P_73 ; real_T P_74 ; real_T P_75 ; real_T P_76 ; real_T P_77 ;
real_T P_78 ; real_T P_79 ; real_T P_80 ; real_T P_81 ; real_T P_82 ; real_T
P_83 ; real_T P_84 ; real_T P_85 ; real_T P_86 ; real_T P_87 ; real_T P_88 ;
real_T P_89 ; real_T P_90 ; real_T P_91 ; real_T P_92 ; real_T P_93 ; real_T
P_94 ; real_T P_95 ; real_T P_96 ; real_T P_97 ; real_T P_98 ; real_T P_99 ;
real_T P_100 ; real_T P_101 ; real_T P_102 ; real_T P_103 ; real_T P_104 ;
real_T P_105 ; real_T P_106 ; real_T P_107 ; real_T P_108 ; real_T P_109 ;
creal_T P_110 ; creal_T P_111 ; creal_T P_112 ; creal_T P_113 ; creal_T P_114
; creal_T P_115 ; creal_T P_116 ; creal_T P_117 ; P_TrueRMS_Seminar2_Part2_T
TrueRMS_e ; P_RMS_Seminar2_Part2_T RMS_b ; P_TrueRMS_Seminar2_Part2_T
TrueRMS_m ; P_RMS_Seminar2_Part2_T RMS_m ; P_TrueRMS_Seminar2_Part2_T
TrueRMS_i ; P_RMS_Seminar2_Part2_T RMS_g ; P_TrueRMS_Seminar2_Part2_T
TrueRMS_j ; P_RMS_Seminar2_Part2_T RMS_l ; P_TrueRMS_Seminar2_Part2_T TrueRMS
; P_RMS_Seminar2_Part2_T RMS ; } ; extern P_Seminar2_Part2_T
Seminar2_Part2_rtDefaultP ;
#endif
