#include "Seminar2_Part2_acc.h"
#include "rtwtypes.h"
#include "Seminar2_Part2_acc_private.h"
#include "mwmathutil.h"
#include "multiword_types.h"
#include <stdio.h>
#include "slexec_vm_simstruct_bridge.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_lookup_functions.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "simtarget/slSimTgtMdlrefSfcnBridge.h"
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
#include "simtarget/slAccSfcnBridge.h"
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
boolean_T Seminar2_Part2_acc_rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr
, int_T * tailPtr , int_T * headPtr , int_T * lastPtr , real_T tMinusDelay ,
real_T * * uBufPtr , boolean_T isfixedbuf , boolean_T istransportdelay ,
int_T * maxNewBufSzPtr ) { int_T testIdx ; int_T tail = * tailPtr ; int_T
bufSz = * bufSzPtr ; real_T * tBuf = * uBufPtr + bufSz ; real_T * xBuf = (
NULL ) ; int_T numBuffer = 2 ; if ( istransportdelay ) { numBuffer = 3 ; xBuf
= * uBufPtr + 2 * bufSz ; } testIdx = ( tail < ( bufSz - 1 ) ) ? ( tail + 1 )
: 0 ; if ( ( tMinusDelay <= tBuf [ testIdx ] ) && ! isfixedbuf ) { int_T j ;
real_T * tempT ; real_T * tempU ; real_T * tempX = ( NULL ) ; real_T * uBuf =
* uBufPtr ; int_T newBufSz = bufSz + 1024 ; if ( newBufSz > * maxNewBufSzPtr
) { * maxNewBufSzPtr = newBufSz ; } tempU = ( real_T * ) utMalloc ( numBuffer
* newBufSz * sizeof ( real_T ) ) ; if ( tempU == ( NULL ) ) { return ( false
) ; } tempT = tempU + newBufSz ; if ( istransportdelay ) tempX = tempT +
newBufSz ; for ( j = tail ; j < bufSz ; j ++ ) { tempT [ j - tail ] = tBuf [
j ] ; tempU [ j - tail ] = uBuf [ j ] ; if ( istransportdelay ) tempX [ j -
tail ] = xBuf [ j ] ; } for ( j = 0 ; j < tail ; j ++ ) { tempT [ j + bufSz -
tail ] = tBuf [ j ] ; tempU [ j + bufSz - tail ] = uBuf [ j ] ; if (
istransportdelay ) tempX [ j + bufSz - tail ] = xBuf [ j ] ; } if ( * lastPtr
> tail ) { * lastPtr -= tail ; } else { * lastPtr += ( bufSz - tail ) ; } *
tailPtr = 0 ; * headPtr = bufSz ; utFree ( uBuf ) ; * bufSzPtr = newBufSz ; *
uBufPtr = tempU ; } else { * tailPtr = testIdx ; } return ( true ) ; } real_T
Seminar2_Part2_acc_rt_TDelayInterpolate ( real_T tMinusDelay , real_T tStart
, real_T * uBuf , int_T bufSz , int_T * lastIdx , int_T oldestIdx , int_T
newIdx , real_T initOutput , boolean_T discrete , boolean_T
minorStepAndTAtLastMajorOutput ) { int_T i ; real_T yout , t1 , t2 , u1 , u2
; real_T * tBuf = uBuf + bufSz ; if ( ( newIdx == 0 ) && ( oldestIdx == 0 )
&& ( tMinusDelay > tStart ) ) return initOutput ; if ( tMinusDelay <= tStart
) return initOutput ; if ( ( tMinusDelay <= tBuf [ oldestIdx ] ) ) { if (
discrete ) { return ( uBuf [ oldestIdx ] ) ; } else { int_T tempIdx =
oldestIdx + 1 ; if ( oldestIdx == bufSz - 1 ) tempIdx = 0 ; t1 = tBuf [
oldestIdx ] ; t2 = tBuf [ tempIdx ] ; u1 = uBuf [ oldestIdx ] ; u2 = uBuf [
tempIdx ] ; if ( t2 == t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; } else {
yout = u1 ; } } else { real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; yout = f1 * u1 + f2 * u2 ; } return yout ; } } if (
minorStepAndTAtLastMajorOutput ) { if ( newIdx != 0 ) { if ( * lastIdx ==
newIdx ) { ( * lastIdx ) -- ; } newIdx -- ; } else { if ( * lastIdx == newIdx
) { * lastIdx = bufSz - 1 ; } newIdx = bufSz - 1 ; } } i = * lastIdx ; if (
tBuf [ i ] < tMinusDelay ) { while ( tBuf [ i ] < tMinusDelay ) { if ( i ==
newIdx ) break ; i = ( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0 ; } } else { while
( tBuf [ i ] >= tMinusDelay ) { i = ( i > 0 ) ? i - 1 : ( bufSz - 1 ) ; } i =
( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0 ; } * lastIdx = i ; if ( discrete ) {
double tempEps = ( DBL_EPSILON ) * 128.0 ; double localEps = tempEps *
muDoubleScalarAbs ( tBuf [ i ] ) ; if ( tempEps > localEps ) { localEps =
tempEps ; } localEps = localEps / 2.0 ; if ( tMinusDelay >= ( tBuf [ i ] -
localEps ) ) { yout = uBuf [ i ] ; } else { if ( i == 0 ) { yout = uBuf [
bufSz - 1 ] ; } else { yout = uBuf [ i - 1 ] ; } } } else { if ( i == 0 ) {
t1 = tBuf [ bufSz - 1 ] ; u1 = uBuf [ bufSz - 1 ] ; } else { t1 = tBuf [ i -
1 ] ; u1 = uBuf [ i - 1 ] ; } t2 = tBuf [ i ] ; u2 = uBuf [ i ] ; if ( t2 ==
t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; } else { yout = u1 ; } } else {
real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; yout
= f1 * u1 + f2 * u2 ; } } return ( yout ) ; } void rt_ssGetBlockPath (
SimStruct * S , int_T sysIdx , int_T blkIdx , char_T * * path ) {
_ssGetBlockPath ( S , sysIdx , blkIdx , path ) ; } void rt_ssSet_slErrMsg (
void * S , void * diag ) { SimStruct * castedS = ( SimStruct * ) S ; if ( !
_ssIsErrorStatusAslErrMsg ( castedS ) ) { _ssSet_slErrMsg ( castedS , diag )
; } else { _ssDiscardDiagnostic ( castedS , diag ) ; } } void
rt_ssReportDiagnosticAsWarning ( void * S , void * diag ) {
_ssReportDiagnosticAsWarning ( ( SimStruct * ) S , diag ) ; } void
rt_ssReportDiagnosticAsInfo ( void * S , void * diag ) {
_ssReportDiagnosticAsInfo ( ( SimStruct * ) S , diag ) ; } void
Seminar2_Part2_RMS_Init ( SimStruct * S , B_RMS_Seminar2_Part2_T * localB ,
DW_RMS_Seminar2_Part2_T * localDW , P_RMS_Seminar2_Part2_T * localP ,
X_RMS_Seminar2_Part2_T * localX ) { localX -> integrator_CSTATE_o5 = localP
-> P_3 ; localDW -> Memory_PreviousInput = localP -> P_7 ; localX ->
integrator_CSTATE_e = localP -> P_8 ; localDW -> Memory_PreviousInput_a =
localP -> P_12 ; localB -> B_6_22_0 = localP -> P_2 ; } void
Seminar2_Part2_RMS_Disable ( SimStruct * S , DW_RMS_Seminar2_Part2_T *
localDW ) { localDW -> RMS_MODE = false ; } void Seminar2_Part2_RMS (
SimStruct * S , boolean_T rtu_Enable , real_T rtu_In , B_RMS_Seminar2_Part2_T
* localB , DW_RMS_Seminar2_Part2_T * localDW , P_RMS_Seminar2_Part2_T *
localP , X_RMS_Seminar2_Part2_T * localX , XDis_RMS_Seminar2_Part2_T *
localXdis ) { int32_T isHit ; boolean_T rtb_B_6_4_0 ; isHit = ssIsSampleHit (
S , 1 , 0 ) ; if ( ( isHit != 0 ) && ssIsModeUpdateTimeStep ( S ) ) { if (
rtu_Enable ) { if ( ! localDW -> RMS_MODE ) { if ( ssGetTaskTime ( S , 1 ) !=
ssGetTStart ( S ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } (
void ) memset ( & ( localXdis -> integrator_CSTATE_o5 ) , 0 , 2 * sizeof (
boolean_T ) ) ; localDW -> RMS_MODE = true ; } } else { if ( ssGetTaskTime (
S , 1 ) == ssGetTStart ( S ) ) { ( void ) memset ( & ( localXdis ->
integrator_CSTATE_o5 ) , 1 , 2 * sizeof ( boolean_T ) ) ; } if ( localDW ->
RMS_MODE ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; ( void )
memset ( & ( localXdis -> integrator_CSTATE_o5 ) , 1 , 2 * sizeof ( boolean_T
) ) ; Seminar2_Part2_RMS_Disable ( S , localDW ) ; } } } if ( localDW ->
RMS_MODE ) { localB -> B_6_0_0 = localX -> integrator_CSTATE_o5 ; { real_T *
* uBuffer = ( real_T * * ) & localDW -> TransportDelay_PWORK . TUbufferPtrs [
0 ] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay = simTime - localP
-> P_4 ; localB -> B_6_1_0 = Seminar2_Part2_acc_rt_TDelayInterpolate (
tMinusDelay , 0.0 , * uBuffer , localDW -> TransportDelay_IWORK .
CircularBufSize , & localDW -> TransportDelay_IWORK . Last , localDW ->
TransportDelay_IWORK . Tail , localDW -> TransportDelay_IWORK . Head , localP
-> P_5 , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ( * uBuffer +
localDW -> TransportDelay_IWORK . CircularBufSize ) [ localDW ->
TransportDelay_IWORK . Head ] == ssGetT ( S ) ) ) ) ; } isHit = ssIsSampleHit
( S , 1 , 0 ) ; if ( isHit != 0 ) { localB -> B_6_3_0 = localP -> P_6 ; }
rtb_B_6_4_0 = ( ssGetT ( S ) >= localB -> B_6_3_0 ) ; isHit = ssIsSampleHit (
S , 1 , 0 ) ; if ( isHit != 0 ) { localB -> B_6_5_0 = localDW ->
Memory_PreviousInput ; } if ( rtb_B_6_4_0 ) { localB -> B_5_0_0 = localB ->
B_6_0_0 - localB -> B_6_1_0 ; localB -> B_5_1_0 = localP -> P_1 * localB ->
B_5_0_0 ; localB -> B_6_7_0 = localB -> B_5_1_0 ; } else { localB -> B_6_7_0
= localB -> B_6_5_0 ; } localB -> B_6_8_0 = localX -> integrator_CSTATE_e ; {
real_T * * uBuffer = ( real_T * * ) & localDW -> TransportDelay_PWORK_j .
TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay =
simTime - localP -> P_9 ; localB -> B_6_9_0 =
Seminar2_Part2_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer ,
localDW -> TransportDelay_IWORK_m . CircularBufSize , & localDW ->
TransportDelay_IWORK_m . Last , localDW -> TransportDelay_IWORK_m . Tail ,
localDW -> TransportDelay_IWORK_m . Head , localP -> P_10 , 0 , ( boolean_T )
( ssIsMinorTimeStep ( S ) && ( ( * uBuffer + localDW ->
TransportDelay_IWORK_m . CircularBufSize ) [ localDW ->
TransportDelay_IWORK_m . Head ] == ssGetT ( S ) ) ) ) ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { localB -> B_6_11_0 = localP
-> P_11 ; } rtb_B_6_4_0 = ( ssGetT ( S ) >= localB -> B_6_11_0 ) ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { localB -> B_6_13_0 =
localDW -> Memory_PreviousInput_a ; } if ( rtb_B_6_4_0 ) { localB -> B_4_0_0
= localB -> B_6_8_0 - localB -> B_6_9_0 ; localB -> B_4_1_0 = localP -> P_0 *
localB -> B_4_0_0 ; localB -> B_6_15_0 = localB -> B_4_1_0 ; } else { localB
-> B_6_15_0 = localB -> B_6_13_0 ; } localB -> B_6_16_0 . re = localB ->
B_6_7_0 ; localB -> B_6_16_0 . im = localB -> B_6_15_0 ; localB -> B_6_19_0 =
( muDoubleScalarSin ( localP -> P_15 * ssGetTaskTime ( S , 0 ) + localP ->
P_16 ) * localP -> P_13 + localP -> P_14 ) * rtu_In ; localB -> B_6_21_0 = (
muDoubleScalarSin ( localP -> P_19 * ssGetTaskTime ( S , 0 ) + localP -> P_20
) * localP -> P_17 + localP -> P_18 ) * rtu_In ; localB -> B_6_22_0 = localP
-> P_21 * muDoubleScalarHypot ( localB -> B_6_16_0 . re , localB -> B_6_16_0
. im ) ; if ( ssIsModeUpdateTimeStep ( S ) ) { srUpdateBC ( localDW ->
RMS_SubsysRanBC ) ; } } } void Seminar2_Part2_RMS_Update ( SimStruct * S ,
B_RMS_Seminar2_Part2_T * localB , DW_RMS_Seminar2_Part2_T * localDW ,
P_RMS_Seminar2_Part2_T * localP ) { int32_T isHit ; if ( localDW -> RMS_MODE
) { { real_T * * uBuffer = ( real_T * * ) & localDW -> TransportDelay_PWORK .
TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ; localDW ->
TransportDelay_IWORK . Head = ( ( localDW -> TransportDelay_IWORK . Head < (
localDW -> TransportDelay_IWORK . CircularBufSize - 1 ) ) ? ( localDW ->
TransportDelay_IWORK . Head + 1 ) : 0 ) ; if ( localDW ->
TransportDelay_IWORK . Head == localDW -> TransportDelay_IWORK . Tail ) { if
( ! Seminar2_Part2_acc_rt_TDelayUpdateTailOrGrowBuf ( & localDW ->
TransportDelay_IWORK . CircularBufSize , & localDW -> TransportDelay_IWORK .
Tail , & localDW -> TransportDelay_IWORK . Head , & localDW ->
TransportDelay_IWORK . Last , simTime - localP -> P_4 , uBuffer , ( boolean_T
) 0 , false , & localDW -> TransportDelay_IWORK . MaxNewBufSize ) ) {
ssSetErrorStatus ( S , "tdelay memory allocation error" ) ; return ; } } ( *
uBuffer + localDW -> TransportDelay_IWORK . CircularBufSize ) [ localDW ->
TransportDelay_IWORK . Head ] = simTime ; ( * uBuffer ) [ localDW ->
TransportDelay_IWORK . Head ] = localB -> B_6_0_0 ; } isHit = ssIsSampleHit (
S , 1 , 0 ) ; if ( isHit != 0 ) { localDW -> Memory_PreviousInput = localB ->
B_6_7_0 ; } { real_T * * uBuffer = ( real_T * * ) & localDW ->
TransportDelay_PWORK_j . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
localDW -> TransportDelay_IWORK_m . Head = ( ( localDW ->
TransportDelay_IWORK_m . Head < ( localDW -> TransportDelay_IWORK_m .
CircularBufSize - 1 ) ) ? ( localDW -> TransportDelay_IWORK_m . Head + 1 ) :
0 ) ; if ( localDW -> TransportDelay_IWORK_m . Head == localDW ->
TransportDelay_IWORK_m . Tail ) { if ( !
Seminar2_Part2_acc_rt_TDelayUpdateTailOrGrowBuf ( & localDW ->
TransportDelay_IWORK_m . CircularBufSize , & localDW ->
TransportDelay_IWORK_m . Tail , & localDW -> TransportDelay_IWORK_m . Head ,
& localDW -> TransportDelay_IWORK_m . Last , simTime - localP -> P_9 ,
uBuffer , ( boolean_T ) 0 , false , & localDW -> TransportDelay_IWORK_m .
MaxNewBufSize ) ) { ssSetErrorStatus ( S , "tdelay memory allocation error" )
; return ; } } ( * uBuffer + localDW -> TransportDelay_IWORK_m .
CircularBufSize ) [ localDW -> TransportDelay_IWORK_m . Head ] = simTime ; (
* uBuffer ) [ localDW -> TransportDelay_IWORK_m . Head ] = localB -> B_6_8_0
; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { localDW ->
Memory_PreviousInput_a = localB -> B_6_15_0 ; } } } void
Seminar2_Part2_RMS_Deriv ( SimStruct * S , B_RMS_Seminar2_Part2_T * localB ,
DW_RMS_Seminar2_Part2_T * localDW , XDot_RMS_Seminar2_Part2_T * localXdot ) {
if ( localDW -> RMS_MODE ) { localXdot -> integrator_CSTATE_o5 = localB ->
B_6_19_0 ; localXdot -> integrator_CSTATE_e = localB -> B_6_21_0 ; } else { {
real_T * dx ; int_T i ; dx = & ( localXdot -> integrator_CSTATE_o5 ) ; for (
i = 0 ; i < 2 ; i ++ ) { dx [ i ] = 0.0 ; } } } } void
Seminar2_Part2_RMS_Term ( SimStruct * const S ) { } void
Seminar2_Part2_TrueRMS_Init ( SimStruct * S , B_TrueRMS_Seminar2_Part2_T *
localB , DW_TrueRMS_Seminar2_Part2_T * localDW , P_TrueRMS_Seminar2_Part2_T *
localP , X_TrueRMS_Seminar2_Part2_T * localX ) { localX ->
integrator_CSTATE_o = localP -> P_2 ; localDW -> Memory_PreviousInput =
localP -> P_6 ; localB -> B_8_10_0 = localP -> P_1 ; } void
Seminar2_Part2_TrueRMS_Disable ( SimStruct * S , DW_TrueRMS_Seminar2_Part2_T
* localDW ) { localDW -> TrueRMS_MODE = false ; } void Seminar2_Part2_TrueRMS
( SimStruct * S , boolean_T rtu_Enable , real_T rtu_In ,
B_TrueRMS_Seminar2_Part2_T * localB , DW_TrueRMS_Seminar2_Part2_T * localDW ,
P_TrueRMS_Seminar2_Part2_T * localP , X_TrueRMS_Seminar2_Part2_T * localX ,
XDis_TrueRMS_Seminar2_Part2_T * localXdis ) { int32_T isHit ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( ( isHit != 0 ) && ssIsModeUpdateTimeStep (
S ) ) { if ( rtu_Enable ) { if ( ! localDW -> TrueRMS_MODE ) { if (
ssGetTaskTime ( S , 1 ) != ssGetTStart ( S ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } localXdis ->
integrator_CSTATE_o = 0 ; localDW -> TrueRMS_MODE = true ; } } else { if (
ssGetTaskTime ( S , 1 ) == ssGetTStart ( S ) ) { localXdis ->
integrator_CSTATE_o = 1 ; } if ( localDW -> TrueRMS_MODE ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; localXdis ->
integrator_CSTATE_o = 1 ; Seminar2_Part2_TrueRMS_Disable ( S , localDW ) ; }
} } if ( localDW -> TrueRMS_MODE ) { localB -> B_8_1_0 = localX ->
integrator_CSTATE_o ; { real_T * * uBuffer = ( real_T * * ) & localDW ->
TransportDelay_PWORK . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
real_T tMinusDelay = simTime - localP -> P_3 ; localB -> B_8_2_0 =
Seminar2_Part2_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer ,
localDW -> TransportDelay_IWORK . CircularBufSize , & localDW ->
TransportDelay_IWORK . Last , localDW -> TransportDelay_IWORK . Tail ,
localDW -> TransportDelay_IWORK . Head , localP -> P_4 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ( * uBuffer + localDW -> TransportDelay_IWORK .
CircularBufSize ) [ localDW -> TransportDelay_IWORK . Head ] == ssGetT ( S )
) ) ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { localB ->
B_8_3_0 = localP -> P_5 ; localB -> B_8_4_0 = localDW -> Memory_PreviousInput
; } if ( ssGetT ( S ) >= localB -> B_8_3_0 ) { localB -> B_7_0_0 = localB ->
B_8_1_0 - localB -> B_8_2_0 ; localB -> B_7_1_0 = localP -> P_0 * localB ->
B_7_0_0 ; localB -> B_8_7_0 = localB -> B_7_1_0 ; } else { localB -> B_8_7_0
= localB -> B_8_4_0 ; } localB -> B_8_8_0 = rtu_In * rtu_In ; if (
ssIsModeUpdateTimeStep ( S ) ) { localDW ->
Saturationtoavoidnegativesqrt_MODE = localB -> B_8_7_0 >= localP -> P_7 ? 1 :
localB -> B_8_7_0 > localP -> P_8 ? 0 : - 1 ; } localB -> B_8_9_0 = localDW
-> Saturationtoavoidnegativesqrt_MODE == 1 ? localP -> P_7 : localDW ->
Saturationtoavoidnegativesqrt_MODE == - 1 ? localP -> P_8 : localB -> B_8_7_0
; if ( ssIsMajorTimeStep ( S ) != 0 ) { if ( localDW -> Sqrt_DWORK1 != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ;
ssSetContTimeOutputInconsistentWithStateAtMajorStep ( S ) ; localDW ->
Sqrt_DWORK1 = 0 ; } localB -> B_8_10_0 = muDoubleScalarSqrt ( localB ->
B_8_9_0 ) ; } else { if ( localB -> B_8_9_0 < 0.0 ) { localB -> B_8_10_0 = -
muDoubleScalarSqrt ( muDoubleScalarAbs ( localB -> B_8_9_0 ) ) ; } else {
localB -> B_8_10_0 = muDoubleScalarSqrt ( localB -> B_8_9_0 ) ; } if ( localB
-> B_8_9_0 < 0.0 ) { localDW -> Sqrt_DWORK1 = 1 ; } } if (
ssIsModeUpdateTimeStep ( S ) ) { srUpdateBC ( localDW -> TrueRMS_SubsysRanBC
) ; } } } void Seminar2_Part2_TrueRMS_Update ( SimStruct * S ,
B_TrueRMS_Seminar2_Part2_T * localB , DW_TrueRMS_Seminar2_Part2_T * localDW ,
P_TrueRMS_Seminar2_Part2_T * localP ) { int32_T isHit ; if ( localDW ->
TrueRMS_MODE ) { { real_T * * uBuffer = ( real_T * * ) & localDW ->
TransportDelay_PWORK . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
localDW -> TransportDelay_IWORK . Head = ( ( localDW -> TransportDelay_IWORK
. Head < ( localDW -> TransportDelay_IWORK . CircularBufSize - 1 ) ) ? (
localDW -> TransportDelay_IWORK . Head + 1 ) : 0 ) ; if ( localDW ->
TransportDelay_IWORK . Head == localDW -> TransportDelay_IWORK . Tail ) { if
( ! Seminar2_Part2_acc_rt_TDelayUpdateTailOrGrowBuf ( & localDW ->
TransportDelay_IWORK . CircularBufSize , & localDW -> TransportDelay_IWORK .
Tail , & localDW -> TransportDelay_IWORK . Head , & localDW ->
TransportDelay_IWORK . Last , simTime - localP -> P_3 , uBuffer , ( boolean_T
) 0 , false , & localDW -> TransportDelay_IWORK . MaxNewBufSize ) ) {
ssSetErrorStatus ( S , "tdelay memory allocation error" ) ; return ; } } ( *
uBuffer + localDW -> TransportDelay_IWORK . CircularBufSize ) [ localDW ->
TransportDelay_IWORK . Head ] = simTime ; ( * uBuffer ) [ localDW ->
TransportDelay_IWORK . Head ] = localB -> B_8_1_0 ; } isHit = ssIsSampleHit (
S , 1 , 0 ) ; if ( isHit != 0 ) { localDW -> Memory_PreviousInput = localB ->
B_8_7_0 ; } } } void Seminar2_Part2_TrueRMS_Deriv ( SimStruct * S ,
B_TrueRMS_Seminar2_Part2_T * localB , DW_TrueRMS_Seminar2_Part2_T * localDW ,
XDot_TrueRMS_Seminar2_Part2_T * localXdot ) { if ( localDW -> TrueRMS_MODE )
{ localXdot -> integrator_CSTATE_o = localB -> B_8_8_0 ; } else { localXdot
-> integrator_CSTATE_o = 0.0 ; } } void Seminar2_Part2_TrueRMS_ZC ( SimStruct
* S , B_TrueRMS_Seminar2_Part2_T * localB , DW_TrueRMS_Seminar2_Part2_T *
localDW , P_TrueRMS_Seminar2_Part2_T * localP , ZCV_TrueRMS_Seminar2_Part2_T
* localZCSV ) { if ( localDW -> TrueRMS_MODE ) { localZCSV ->
Saturationtoavoidnegativesqrt_UprLim_ZC = localB -> B_8_7_0 - localP -> P_7 ;
localZCSV -> Saturationtoavoidnegativesqrt_LwrLim_ZC = localB -> B_8_7_0 -
localP -> P_8 ; } else { { real_T * zcsv = & ( localZCSV ->
Saturationtoavoidnegativesqrt_UprLim_ZC ) ; int_T i ; for ( i = 0 ; i < 2 ; i
++ ) { zcsv [ i ] = 0.0 ; } } } } void Seminar2_Part2_TrueRMS_Term (
SimStruct * const S ) { } static void mdlOutputs ( SimStruct * S , int_T tid
) { real_T B_30_13_0 [ 2 ] ; real_T B_30_18_0 [ 2 ] ; real_T B_30_23_0 [ 2 ]
; real_T B_30_28_0 [ 2 ] ; real_T B_30_33_0 [ 2 ] ; real_T B_30_38_0 [ 2 ] ;
real_T B_30_54_0 ; B_Seminar2_Part2_T * _rtB ; DW_Seminar2_Part2_T * _rtDW ;
P_Seminar2_Part2_T * _rtP ; X_Seminar2_Part2_T * _rtX ; real_T
B_30_20_0_idx_0 ; real_T B_30_20_0_idx_1 ; real_T B_30_25_0_idx_0 ; real_T
B_30_25_0_idx_1 ; real_T B_30_35_0_idx_0 ; real_T B_30_35_0_idx_1 ; real_T
B_30_40_0_idx_0 ; real_T B_30_40_0_idx_1 ; real_T rtb_B_30_7_0 ; int32_T
isHit ; boolean_T rtb_B_30_57_0 ; _rtDW = ( ( DW_Seminar2_Part2_T * )
ssGetRootDWork ( S ) ) ; _rtX = ( ( X_Seminar2_Part2_T * ) ssGetContStates (
S ) ) ; _rtP = ( ( P_Seminar2_Part2_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( (
B_Seminar2_Part2_T * ) _ssGetModelBlockIO ( S ) ) ; _rtB -> B_30_0_0 =
muDoubleScalarSin ( _rtP -> P_12 * ssGetTaskTime ( S , 0 ) + _rtP -> P_13 ) *
_rtP -> P_10 + _rtP -> P_11 ; _rtB -> B_30_1_0 = muDoubleScalarSin ( _rtP ->
P_16 * ssGetTaskTime ( S , 0 ) + _rtP -> P_17 ) * _rtP -> P_14 + _rtP -> P_15
; _rtB -> B_30_2_0 = muDoubleScalarSin ( _rtP -> P_20 * ssGetTaskTime ( S , 0
) + _rtP -> P_21 ) * _rtP -> P_18 + _rtP -> P_19 ; ssCallAccelRunBlock ( S ,
30 , 3 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_30_4_0 = _rtP -> P_42 * _rtB ->
B_30_3_0 [ 4 ] ; Seminar2_Part2_TrueRMS ( S , _rtB -> B_30_3_0_p , _rtB ->
B_30_4_0 , & _rtB -> TrueRMS_j , & _rtDW -> TrueRMS_j , & _rtP -> TrueRMS_j ,
& _rtX -> TrueRMS_j , & ( ( XDis_Seminar2_Part2_T * ) ssGetContStateDisabled
( S ) ) -> TrueRMS_j ) ; Seminar2_Part2_RMS ( S , _rtB -> B_30_4_0_c , _rtB
-> B_30_4_0 , & _rtB -> RMS_l , & _rtDW -> RMS_l , & _rtP -> RMS_l , & _rtX
-> RMS_l , & ( ( XDis_Seminar2_Part2_T * ) ssGetContStateDisabled ( S ) ) ->
RMS_l ) ; if ( _rtB -> B_30_3_0_p ) { rtb_B_30_7_0 = _rtB -> TrueRMS_j .
B_8_10_0 ; } else { rtb_B_30_7_0 = _rtB -> RMS_l . B_6_22_0 ; } _rtB ->
B_30_8_0 = _rtP -> P_43 * _rtB -> B_30_3_0 [ 5 ] ; Seminar2_Part2_TrueRMS ( S
, _rtB -> B_30_6_0 , _rtB -> B_30_8_0 , & _rtB -> TrueRMS_i , & _rtDW ->
TrueRMS_i , & _rtP -> TrueRMS_i , & _rtX -> TrueRMS_i , & ( (
XDis_Seminar2_Part2_T * ) ssGetContStateDisabled ( S ) ) -> TrueRMS_i ) ;
Seminar2_Part2_RMS ( S , _rtB -> B_30_7_0 , _rtB -> B_30_8_0 , & _rtB ->
RMS_g , & _rtDW -> RMS_g , & _rtP -> RMS_g , & _rtX -> RMS_g , & ( (
XDis_Seminar2_Part2_T * ) ssGetContStateDisabled ( S ) ) -> RMS_g ) ; _rtB ->
B_30_12_0 [ 0 ] = _rtX -> Integrator_CSTATE [ 0 ] ; _rtB -> B_30_12_0 [ 1 ] =
_rtX -> Integrator_CSTATE [ 1 ] ; { real_T * * uBuffer = ( real_T * * ) &
_rtDW -> TransportDelay_PWORK . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT
( S ) ; real_T tMinusDelay ; { int_T i1 ; real_T * y0 = & B_30_13_0 [ 0 ] ;
int_T * iw_Tail = & _rtDW -> TransportDelay_IWORK . Tail [ 0 ] ; int_T *
iw_Head = & _rtDW -> TransportDelay_IWORK . Head [ 0 ] ; int_T * iw_Last = &
_rtDW -> TransportDelay_IWORK . Last [ 0 ] ; int_T * iw_CircularBufSize = &
_rtDW -> TransportDelay_IWORK . CircularBufSize [ 0 ] ; for ( i1 = 0 ; i1 < 2
; i1 ++ ) { tMinusDelay = ( ( _rtP -> P_45 > 0.0 ) ? _rtP -> P_45 : 0.0 ) ;
tMinusDelay = simTime - tMinusDelay ; y0 [ i1 ] =
Seminar2_Part2_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer ,
iw_CircularBufSize [ i1 ] , & iw_Last [ i1 ] , iw_Tail [ i1 ] , iw_Head [ i1
] , _rtP -> P_46 , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ( *
uBuffer + iw_CircularBufSize [ i1 ] ) [ iw_Head [ i1 ] ] == ssGetT ( S ) ) )
) ; uBuffer ++ ; } } } _rtB -> B_30_17_0 [ 0 ] = _rtX -> Integrator_CSTATE_j
[ 0 ] ; _rtB -> B_30_17_0 [ 1 ] = _rtX -> Integrator_CSTATE_j [ 1 ] ; {
real_T * * uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_m .
TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay ; {
int_T i1 ; real_T * y0 = & B_30_18_0 [ 0 ] ; int_T * iw_Tail = & _rtDW ->
TransportDelay_IWORK_g . Tail [ 0 ] ; int_T * iw_Head = & _rtDW ->
TransportDelay_IWORK_g . Head [ 0 ] ; int_T * iw_Last = & _rtDW ->
TransportDelay_IWORK_g . Last [ 0 ] ; int_T * iw_CircularBufSize = & _rtDW ->
TransportDelay_IWORK_g . CircularBufSize [ 0 ] ; for ( i1 = 0 ; i1 < 2 ; i1
++ ) { tMinusDelay = ( ( _rtP -> P_49 > 0.0 ) ? _rtP -> P_49 : 0.0 ) ;
tMinusDelay = simTime - tMinusDelay ; y0 [ i1 ] =
Seminar2_Part2_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer ,
iw_CircularBufSize [ i1 ] , & iw_Last [ i1 ] , iw_Tail [ i1 ] , iw_Head [ i1
] , _rtP -> P_50 , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ( *
uBuffer + iw_CircularBufSize [ i1 ] ) [ iw_Head [ i1 ] ] == ssGetT ( S ) ) )
) ; uBuffer ++ ; } } } B_30_20_0_idx_0 = ( _rtB -> B_30_17_0 [ 0 ] -
B_30_18_0 [ 0 ] ) * _rtP -> P_51 ; _rtB -> B_30_22_0 [ 0 ] = _rtX ->
Integrator_CSTATE_b [ 0 ] ; B_30_20_0_idx_1 = ( _rtB -> B_30_17_0 [ 1 ] -
B_30_18_0 [ 1 ] ) * _rtP -> P_51 ; _rtB -> B_30_22_0 [ 1 ] = _rtX ->
Integrator_CSTATE_b [ 1 ] ; { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_g . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
real_T tMinusDelay ; { int_T i1 ; real_T * y0 = & B_30_23_0 [ 0 ] ; int_T *
iw_Tail = & _rtDW -> TransportDelay_IWORK_j . Tail [ 0 ] ; int_T * iw_Head =
& _rtDW -> TransportDelay_IWORK_j . Head [ 0 ] ; int_T * iw_Last = & _rtDW ->
TransportDelay_IWORK_j . Last [ 0 ] ; int_T * iw_CircularBufSize = & _rtDW ->
TransportDelay_IWORK_j . CircularBufSize [ 0 ] ; for ( i1 = 0 ; i1 < 2 ; i1
++ ) { tMinusDelay = ( ( _rtP -> P_53 > 0.0 ) ? _rtP -> P_53 : 0.0 ) ;
tMinusDelay = simTime - tMinusDelay ; y0 [ i1 ] =
Seminar2_Part2_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer ,
iw_CircularBufSize [ i1 ] , & iw_Last [ i1 ] , iw_Tail [ i1 ] , iw_Head [ i1
] , _rtP -> P_54 , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ( *
uBuffer + iw_CircularBufSize [ i1 ] ) [ iw_Head [ i1 ] ] == ssGetT ( S ) ) )
) ; uBuffer ++ ; } } } B_30_25_0_idx_0 = ( _rtB -> B_30_22_0 [ 0 ] -
B_30_23_0 [ 0 ] ) * _rtP -> P_55 ; _rtB -> B_30_27_0 [ 0 ] = _rtX ->
Integrator_CSTATE_m [ 0 ] ; B_30_25_0_idx_1 = ( _rtB -> B_30_22_0 [ 1 ] -
B_30_23_0 [ 1 ] ) * _rtP -> P_55 ; _rtB -> B_30_27_0 [ 1 ] = _rtX ->
Integrator_CSTATE_m [ 1 ] ; { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_i . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
real_T tMinusDelay ; { int_T i1 ; real_T * y0 = & B_30_28_0 [ 0 ] ; int_T *
iw_Tail = & _rtDW -> TransportDelay_IWORK_e . Tail [ 0 ] ; int_T * iw_Head =
& _rtDW -> TransportDelay_IWORK_e . Head [ 0 ] ; int_T * iw_Last = & _rtDW ->
TransportDelay_IWORK_e . Last [ 0 ] ; int_T * iw_CircularBufSize = & _rtDW ->
TransportDelay_IWORK_e . CircularBufSize [ 0 ] ; for ( i1 = 0 ; i1 < 2 ; i1
++ ) { tMinusDelay = ( ( _rtP -> P_57 > 0.0 ) ? _rtP -> P_57 : 0.0 ) ;
tMinusDelay = simTime - tMinusDelay ; y0 [ i1 ] =
Seminar2_Part2_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer ,
iw_CircularBufSize [ i1 ] , & iw_Last [ i1 ] , iw_Tail [ i1 ] , iw_Head [ i1
] , _rtP -> P_58 , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ( *
uBuffer + iw_CircularBufSize [ i1 ] ) [ iw_Head [ i1 ] ] == ssGetT ( S ) ) )
) ; uBuffer ++ ; } } } _rtB -> B_30_32_0 [ 0 ] = _rtX -> Integrator_CSTATE_jh
[ 0 ] ; _rtB -> B_30_32_0 [ 1 ] = _rtX -> Integrator_CSTATE_jh [ 1 ] ; {
real_T * * uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_n .
TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay ; {
int_T i1 ; real_T * y0 = & B_30_33_0 [ 0 ] ; int_T * iw_Tail = & _rtDW ->
TransportDelay_IWORK_l . Tail [ 0 ] ; int_T * iw_Head = & _rtDW ->
TransportDelay_IWORK_l . Head [ 0 ] ; int_T * iw_Last = & _rtDW ->
TransportDelay_IWORK_l . Last [ 0 ] ; int_T * iw_CircularBufSize = & _rtDW ->
TransportDelay_IWORK_l . CircularBufSize [ 0 ] ; for ( i1 = 0 ; i1 < 2 ; i1
++ ) { tMinusDelay = ( ( _rtP -> P_61 > 0.0 ) ? _rtP -> P_61 : 0.0 ) ;
tMinusDelay = simTime - tMinusDelay ; y0 [ i1 ] =
Seminar2_Part2_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer ,
iw_CircularBufSize [ i1 ] , & iw_Last [ i1 ] , iw_Tail [ i1 ] , iw_Head [ i1
] , _rtP -> P_62 , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ( *
uBuffer + iw_CircularBufSize [ i1 ] ) [ iw_Head [ i1 ] ] == ssGetT ( S ) ) )
) ; uBuffer ++ ; } } } B_30_35_0_idx_0 = ( _rtB -> B_30_32_0 [ 0 ] -
B_30_33_0 [ 0 ] ) * _rtP -> P_63 ; _rtB -> B_30_37_0 [ 0 ] = _rtX ->
Integrator_CSTATE_o [ 0 ] ; B_30_35_0_idx_1 = ( _rtB -> B_30_32_0 [ 1 ] -
B_30_33_0 [ 1 ] ) * _rtP -> P_63 ; _rtB -> B_30_37_0 [ 1 ] = _rtX ->
Integrator_CSTATE_o [ 1 ] ; { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_p . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
real_T tMinusDelay ; { int_T i1 ; real_T * y0 = & B_30_38_0 [ 0 ] ; int_T *
iw_Tail = & _rtDW -> TransportDelay_IWORK_f . Tail [ 0 ] ; int_T * iw_Head =
& _rtDW -> TransportDelay_IWORK_f . Head [ 0 ] ; int_T * iw_Last = & _rtDW ->
TransportDelay_IWORK_f . Last [ 0 ] ; int_T * iw_CircularBufSize = & _rtDW ->
TransportDelay_IWORK_f . CircularBufSize [ 0 ] ; for ( i1 = 0 ; i1 < 2 ; i1
++ ) { tMinusDelay = ( ( _rtP -> P_65 > 0.0 ) ? _rtP -> P_65 : 0.0 ) ;
tMinusDelay = simTime - tMinusDelay ; y0 [ i1 ] =
Seminar2_Part2_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer ,
iw_CircularBufSize [ i1 ] , & iw_Last [ i1 ] , iw_Tail [ i1 ] , iw_Head [ i1
] , _rtP -> P_66 , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ( *
uBuffer + iw_CircularBufSize [ i1 ] ) [ iw_Head [ i1 ] ] == ssGetT ( S ) ) )
) ; uBuffer ++ ; } } } B_30_40_0_idx_0 = ( _rtB -> B_30_37_0 [ 0 ] -
B_30_38_0 [ 0 ] ) * _rtP -> P_67 ; B_30_40_0_idx_1 = ( _rtB -> B_30_37_0 [ 1
] - B_30_38_0 [ 1 ] ) * _rtP -> P_67 ; switch ( ( int32_T ) _rtB ->
B_30_0_0_m ) { case 1 : B_30_20_0_idx_0 = ( ( ( ( _rtB -> B_30_12_0 [ 0 ] -
B_30_13_0 [ 0 ] ) * _rtP -> P_47 + ( _rtP -> P_113 . re * B_30_20_0_idx_0 -
_rtP -> P_113 . im * B_30_20_0_idx_1 ) ) + ( _rtP -> P_112 . re *
B_30_25_0_idx_0 - _rtP -> P_112 . im * B_30_25_0_idx_1 ) ) * _rtP -> P_1 * (
( ( ( _rtB -> B_30_27_0 [ 0 ] - B_30_28_0 [ 0 ] ) * _rtP -> P_59 + ( _rtP ->
P_111 . re * B_30_35_0_idx_0 - _rtP -> P_111 . im * B_30_35_0_idx_1 ) ) + (
_rtP -> P_110 . re * B_30_40_0_idx_0 - _rtP -> P_110 . im * B_30_40_0_idx_1 )
) * _rtP -> P_0 ) - ( ( ( _rtB -> B_30_12_0 [ 1 ] - B_30_13_0 [ 1 ] ) * _rtP
-> P_47 + ( _rtP -> P_113 . re * B_30_20_0_idx_1 + _rtP -> P_113 . im *
B_30_20_0_idx_0 ) ) + ( _rtP -> P_112 . re * B_30_25_0_idx_1 + _rtP -> P_112
. im * B_30_25_0_idx_0 ) ) * _rtP -> P_1 * - ( ( ( ( _rtB -> B_30_27_0 [ 1 ]
- B_30_28_0 [ 1 ] ) * _rtP -> P_59 + ( _rtP -> P_111 . re * B_30_35_0_idx_1 +
_rtP -> P_111 . im * B_30_35_0_idx_0 ) ) + ( _rtP -> P_110 . re *
B_30_40_0_idx_1 + _rtP -> P_110 . im * B_30_40_0_idx_0 ) ) * _rtP -> P_0 ) )
* _rtP -> P_2 ; break ; case 2 : B_30_20_0_idx_0 = ( ( ( ( _rtB -> B_30_12_0
[ 0 ] - B_30_13_0 [ 0 ] ) * _rtP -> P_47 + ( _rtP -> P_117 . re *
B_30_20_0_idx_0 - _rtP -> P_117 . im * B_30_20_0_idx_1 ) ) + ( _rtP -> P_116
. re * B_30_25_0_idx_0 - _rtP -> P_116 . im * B_30_25_0_idx_1 ) ) * _rtP ->
P_4 * ( ( ( ( _rtB -> B_30_27_0 [ 0 ] - B_30_28_0 [ 0 ] ) * _rtP -> P_59 + (
_rtP -> P_115 . re * B_30_35_0_idx_0 - _rtP -> P_115 . im * B_30_35_0_idx_1 )
) + ( _rtP -> P_114 . re * B_30_40_0_idx_0 - _rtP -> P_114 . im *
B_30_40_0_idx_1 ) ) * _rtP -> P_3 ) - ( ( ( _rtB -> B_30_12_0 [ 1 ] -
B_30_13_0 [ 1 ] ) * _rtP -> P_47 + ( _rtP -> P_117 . re * B_30_20_0_idx_1 +
_rtP -> P_117 . im * B_30_20_0_idx_0 ) ) + ( _rtP -> P_116 . re *
B_30_25_0_idx_1 + _rtP -> P_116 . im * B_30_25_0_idx_0 ) ) * _rtP -> P_4 * -
( ( ( ( _rtB -> B_30_27_0 [ 1 ] - B_30_28_0 [ 1 ] ) * _rtP -> P_59 + ( _rtP
-> P_115 . re * B_30_35_0_idx_1 + _rtP -> P_115 . im * B_30_35_0_idx_0 ) ) +
( _rtP -> P_114 . re * B_30_40_0_idx_1 + _rtP -> P_114 . im * B_30_40_0_idx_0
) ) * _rtP -> P_3 ) ) * _rtP -> P_5 ; break ; default : B_30_20_0_idx_0 = ( (
( ( _rtB -> B_30_12_0 [ 0 ] - B_30_13_0 [ 0 ] ) * _rtP -> P_47 +
B_30_20_0_idx_0 ) + B_30_25_0_idx_0 ) * _rtP -> P_7 * ( ( ( ( _rtB ->
B_30_27_0 [ 0 ] - B_30_28_0 [ 0 ] ) * _rtP -> P_59 + B_30_35_0_idx_0 ) +
B_30_40_0_idx_0 ) * _rtP -> P_6 ) - ( ( ( _rtB -> B_30_12_0 [ 1 ] - B_30_13_0
[ 1 ] ) * _rtP -> P_47 + B_30_20_0_idx_1 ) + B_30_25_0_idx_1 ) * _rtP -> P_7
* - ( ( ( ( _rtB -> B_30_27_0 [ 1 ] - B_30_28_0 [ 1 ] ) * _rtP -> P_59 +
B_30_35_0_idx_1 ) + B_30_40_0_idx_1 ) * _rtP -> P_6 ) ) * _rtP -> P_8 ; break
; } _rtB -> B_0_0_0 [ 0 ] = rtb_B_30_7_0 ; if ( _rtB -> B_30_6_0 ) { _rtB ->
B_0_0_0 [ 1 ] = _rtB -> TrueRMS_i . B_8_10_0 ; } else { _rtB -> B_0_0_0 [ 1 ]
= _rtB -> RMS_g . B_6_22_0 ; } _rtB -> B_0_0_0 [ 2 ] = B_30_20_0_idx_0 ;
ssCallAccelRunBlock ( S , 0 , 1 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock
( S , 30 , 48 , SS_CALL_MDL_OUTPUTS ) ; Seminar2_Part2_TrueRMS ( S , _rtB ->
B_30_9_0 , _rtB -> B_30_8_0 , & _rtB -> TrueRMS_m , & _rtDW -> TrueRMS_m , &
_rtP -> TrueRMS_m , & _rtX -> TrueRMS_m , & ( ( XDis_Seminar2_Part2_T * )
ssGetContStateDisabled ( S ) ) -> TrueRMS_m ) ; Seminar2_Part2_RMS ( S , _rtB
-> B_30_10_0 , _rtB -> B_30_8_0 , & _rtB -> RMS_m , & _rtDW -> RMS_m , & _rtP
-> RMS_m , & _rtX -> RMS_m , & ( ( XDis_Seminar2_Part2_T * )
ssGetContStateDisabled ( S ) ) -> RMS_m ) ; if ( _rtB -> B_30_9_0 ) {
rtb_B_30_7_0 = _rtB -> TrueRMS_m . B_8_10_0 ; } else { rtb_B_30_7_0 = _rtB ->
RMS_m . B_6_22_0 ; } _rtB -> B_30_53_0 = _rtX -> integrator_CSTATE ; { real_T
* * uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_f . TUbufferPtrs
[ 0 ] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP
-> P_69 ; B_30_54_0 = Seminar2_Part2_acc_rt_TDelayInterpolate ( tMinusDelay ,
0.0 , * uBuffer , _rtDW -> TransportDelay_IWORK_e2 . CircularBufSize , &
_rtDW -> TransportDelay_IWORK_e2 . Last , _rtDW -> TransportDelay_IWORK_e2 .
Tail , _rtDW -> TransportDelay_IWORK_e2 . Head , _rtP -> P_70 , 0 , (
boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW ->
TransportDelay_IWORK_e2 . CircularBufSize ) [ _rtDW ->
TransportDelay_IWORK_e2 . Head ] == ssGetT ( S ) ) ) ) ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_30_56_0 = _rtP ->
P_71 ; } rtb_B_30_57_0 = ( ssGetT ( S ) >= _rtB -> B_30_56_0 ) ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_30_58_0 = _rtDW
-> Memory_PreviousInput ; } if ( rtb_B_30_57_0 ) { _rtB -> B_30_60_0 = ( _rtB
-> B_30_53_0 - B_30_54_0 ) * _rtP -> P_9 ; } else { _rtB -> B_30_60_0 = _rtB
-> B_30_58_0 ; } B_30_20_0_idx_0 = _rtB -> B_30_60_0 * _rtB -> B_30_60_0 ;
Seminar2_Part2_TrueRMS ( S , _rtB -> B_30_12_0_f , _rtB -> B_30_8_0 , & _rtB
-> TrueRMS_e , & _rtDW -> TrueRMS_e , & _rtP -> TrueRMS_e , & _rtX ->
TrueRMS_e , & ( ( XDis_Seminar2_Part2_T * ) ssGetContStateDisabled ( S ) ) ->
TrueRMS_e ) ; Seminar2_Part2_RMS ( S , _rtB -> B_30_13_0 , _rtB -> B_30_8_0 ,
& _rtB -> RMS_b , & _rtDW -> RMS_b , & _rtP -> RMS_b , & _rtX -> RMS_b , & (
( XDis_Seminar2_Part2_T * ) ssGetContStateDisabled ( S ) ) -> RMS_b ) ; if (
_rtB -> B_30_12_0_f ) { B_30_20_0_idx_1 = _rtB -> TrueRMS_e . B_8_10_0 ; }
else { B_30_20_0_idx_1 = _rtB -> RMS_b . B_6_22_0 ; } B_30_20_0_idx_1 *=
B_30_20_0_idx_1 ; if ( B_30_20_0_idx_1 > _rtP -> P_73 ) { B_30_25_0_idx_0 =
_rtP -> P_73 ; } else if ( B_30_20_0_idx_1 < _rtP -> P_74 ) { B_30_25_0_idx_0
= _rtP -> P_74 ; } else { B_30_25_0_idx_0 = B_30_20_0_idx_1 ; } rtb_B_30_7_0
= ( ( rtb_B_30_7_0 * rtb_B_30_7_0 - B_30_20_0_idx_0 ) - B_30_20_0_idx_1 ) /
B_30_25_0_idx_0 ; if ( rtb_B_30_7_0 > _rtP -> P_75 ) { rtb_B_30_7_0 = _rtP ->
P_75 ; } else if ( rtb_B_30_7_0 < _rtP -> P_76 ) { rtb_B_30_7_0 = _rtP ->
P_76 ; } if ( ssIsMajorTimeStep ( S ) != 0 ) { if ( _rtDW -> Sqrt_DWORK1 != 0
) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ;
ssSetContTimeOutputInconsistentWithStateAtMajorStep ( S ) ; _rtDW ->
Sqrt_DWORK1 = 0 ; } _rtB -> B_30_70_0 = muDoubleScalarSqrt ( rtb_B_30_7_0 ) ;
} else if ( rtb_B_30_7_0 < 0.0 ) { _rtB -> B_30_70_0 = - muDoubleScalarSqrt (
muDoubleScalarAbs ( rtb_B_30_7_0 ) ) ; _rtDW -> Sqrt_DWORK1 = 1 ; } else {
_rtB -> B_30_70_0 = muDoubleScalarSqrt ( rtb_B_30_7_0 ) ; }
ssCallAccelRunBlock ( S , 30 , 71 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_30_75_0
= _rtP -> P_77 * _rtB -> B_30_3_0 [ 8 ] ; _rtB -> B_30_76_0 = _rtP -> P_78 *
_rtB -> B_30_3_0 [ 9 ] ; _rtB -> B_30_77_0 = _rtP -> P_79 * _rtB -> B_30_3_0
[ 10 ] ; _rtB -> B_30_78_0 [ 0 ] = _rtP -> P_80 * _rtB -> B_30_75_0 ; _rtB ->
B_30_78_0 [ 1 ] = _rtP -> P_80 * _rtB -> B_30_76_0 ; _rtB -> B_30_78_0 [ 2 ]
= _rtP -> P_80 * _rtB -> B_30_77_0 ; _rtB -> B_30_79_0 = _rtX ->
Integrator_CSTATE_g ; muDoubleScalarSinCos ( _rtB -> B_30_79_0 , &
rtb_B_30_7_0 , & B_30_20_0_idx_0 ) ; _rtB -> B_30_81_0 [ 0 ] = _rtB ->
B_30_78_0 [ 0 ] * rtb_B_30_7_0 ; _rtB -> B_30_81_0 [ 1 ] = _rtB -> B_30_78_0
[ 0 ] * B_30_20_0_idx_0 ; _rtB -> B_30_82_0 = _rtP -> P_84 * _rtB -> B_30_3_0
[ 0 ] ; _rtB -> B_30_83_0 = _rtP -> P_85 * _rtB -> B_30_3_0 [ 1 ] ; _rtB ->
B_30_84_0 = _rtP -> P_86 * _rtB -> B_30_3_0 [ 2 ] ; _rtB -> B_30_85_0 [ 0 ] =
_rtP -> P_87 * _rtB -> B_30_82_0 ; _rtB -> B_30_85_0 [ 1 ] = _rtP -> P_87 *
_rtB -> B_30_83_0 ; _rtB -> B_30_85_0 [ 2 ] = _rtP -> P_87 * _rtB ->
B_30_84_0 ; _rtB -> B_30_86_0 [ 0 ] = _rtB -> B_30_85_0 [ 0 ] * rtb_B_30_7_0
; _rtB -> B_30_86_0 [ 1 ] = _rtB -> B_30_85_0 [ 0 ] * B_30_20_0_idx_0 ; _rtB
-> B_30_87_0 [ 0 ] = _rtB -> B_30_78_0 [ 1 ] * rtb_B_30_7_0 ; _rtB ->
B_30_87_0 [ 1 ] = _rtB -> B_30_78_0 [ 1 ] * B_30_20_0_idx_0 ; _rtB ->
B_30_88_0 [ 0 ] = _rtB -> B_30_85_0 [ 1 ] * rtb_B_30_7_0 ; _rtB -> B_30_88_0
[ 1 ] = _rtB -> B_30_85_0 [ 1 ] * B_30_20_0_idx_0 ; _rtB -> B_30_89_0 [ 0 ] =
_rtB -> B_30_78_0 [ 2 ] * rtb_B_30_7_0 ; _rtB -> B_30_89_0 [ 1 ] = _rtB ->
B_30_78_0 [ 2 ] * B_30_20_0_idx_0 ; _rtB -> B_30_90_0 [ 0 ] = _rtB ->
B_30_85_0 [ 2 ] * rtb_B_30_7_0 ; _rtB -> B_30_90_0 [ 1 ] = _rtB -> B_30_85_0
[ 2 ] * B_30_20_0_idx_0 ; _rtB -> B_30_128_0 = _rtP -> P_88 * _rtB ->
B_30_3_0 [ 6 ] ; ssCallAccelRunBlock ( S , 30 , 129 , SS_CALL_MDL_OUTPUTS ) ;
_rtB -> B_30_133_0 = _rtP -> P_89 * _rtB -> B_30_3_0 [ 7 ] ;
ssCallAccelRunBlock ( S , 30 , 134 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
B_30_138_0 = _rtP -> P_90 * _rtB -> B_30_3_0 [ 3 ] ; Seminar2_Part2_TrueRMS (
S , _rtB -> B_30_15_0 , _rtB -> B_30_138_0 , & _rtB -> TrueRMS , & _rtDW ->
TrueRMS , & _rtP -> TrueRMS , & _rtX -> TrueRMS , & ( ( XDis_Seminar2_Part2_T
* ) ssGetContStateDisabled ( S ) ) -> TrueRMS ) ; Seminar2_Part2_RMS ( S ,
_rtB -> B_30_16_0 , _rtB -> B_30_138_0 , & _rtB -> RMS , & _rtDW -> RMS , &
_rtP -> RMS , & _rtX -> RMS , & ( ( XDis_Seminar2_Part2_T * )
ssGetContStateDisabled ( S ) ) -> RMS ) ; if ( _rtB -> B_30_15_0 ) { _rtB ->
B_30_141_0 = _rtB -> TrueRMS . B_8_10_0 ; } else { _rtB -> B_30_141_0 = _rtB
-> RMS . B_6_22_0 ; } ssCallAccelRunBlock ( S , 30 , 142 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 30 , 143 ,
SS_CALL_MDL_OUTPUTS ) ; UNUSED_PARAMETER ( tid ) ; } static void
mdlOutputsTID2 ( SimStruct * S , int_T tid ) { B_Seminar2_Part2_T * _rtB ;
P_Seminar2_Part2_T * _rtP ; _rtP = ( ( P_Seminar2_Part2_T * ) ssGetModelRtp (
S ) ) ; _rtB = ( ( B_Seminar2_Part2_T * ) _ssGetModelBlockIO ( S ) ) ; _rtB
-> B_30_0_0_m = _rtP -> P_91 ; _rtB -> B_30_1_0_c = _rtP -> P_92 ; _rtB ->
B_30_3_0_p = ( _rtP -> P_93 != 0.0 ) ; _rtB -> B_30_4_0_c = ! _rtB ->
B_30_3_0_p ; _rtB -> B_30_6_0 = ( _rtP -> P_94 != 0.0 ) ; _rtB -> B_30_7_0 =
! _rtB -> B_30_6_0 ; _rtB -> B_30_9_0 = ( _rtP -> P_95 != 0.0 ) ; _rtB ->
B_30_10_0 = ! _rtB -> B_30_9_0 ; _rtB -> B_30_12_0_f = ( _rtP -> P_96 != 0.0
) ; _rtB -> B_30_13_0 = ! _rtB -> B_30_12_0_f ; _rtB -> B_30_15_0 = ( _rtP ->
P_97 != 0.0 ) ; _rtB -> B_30_16_0 = ! _rtB -> B_30_15_0 ; _rtB -> B_30_17_0_k
= _rtP -> P_98 ; _rtB -> B_30_18_0 = _rtP -> P_99 ; _rtB -> B_30_19_0 = _rtP
-> P_100 ; _rtB -> B_30_20_0 = _rtP -> P_101 ; _rtB -> B_30_21_0 = _rtP ->
P_102 ; _rtB -> B_30_22_0_c = _rtP -> P_103 ; _rtB -> B_30_23_0 = _rtP ->
P_104 ; _rtB -> B_30_24_0 = _rtP -> P_105 ; _rtB -> B_30_25_0 = _rtP -> P_106
; _rtB -> B_30_26_0 = _rtP -> P_107 ; _rtB -> B_30_27_0_b = _rtP -> P_108 ;
_rtB -> B_30_28_0 = _rtP -> P_109 ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { B_Seminar2_Part2_T *
_rtB ; DW_Seminar2_Part2_T * _rtDW ; P_Seminar2_Part2_T * _rtP ;
X_Seminar2_Part2_T * _rtX ; int32_T isHit ; _rtDW = ( ( DW_Seminar2_Part2_T *
) ssGetRootDWork ( S ) ) ; _rtX = ( ( X_Seminar2_Part2_T * ) ssGetContStates
( S ) ) ; _rtP = ( ( P_Seminar2_Part2_T * ) ssGetModelRtp ( S ) ) ; _rtB = (
( B_Seminar2_Part2_T * ) _ssGetModelBlockIO ( S ) ) ; ssCallAccelRunBlock ( S
, 30 , 3 , SS_CALL_MDL_UPDATE ) ; Seminar2_Part2_TrueRMS_Update ( S , & _rtB
-> TrueRMS_j , & _rtDW -> TrueRMS_j , & _rtP -> TrueRMS_j ) ;
Seminar2_Part2_RMS_Update ( S , & _rtB -> RMS_l , & _rtDW -> RMS_l , & _rtP
-> RMS_l ) ; Seminar2_Part2_TrueRMS_Update ( S , & _rtB -> TrueRMS_i , &
_rtDW -> TrueRMS_i , & _rtP -> TrueRMS_i ) ; Seminar2_Part2_RMS_Update ( S ,
& _rtB -> RMS_g , & _rtDW -> RMS_g , & _rtP -> RMS_g ) ; { real_T * * uBuffer
= ( real_T * * ) & _rtDW -> TransportDelay_PWORK . TUbufferPtrs [ 0 ] ;
real_T simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK . Head [ 0 ] =
( ( _rtDW -> TransportDelay_IWORK . Head [ 0 ] < ( _rtDW ->
TransportDelay_IWORK . CircularBufSize [ 0 ] - 1 ) ) ? ( _rtDW ->
TransportDelay_IWORK . Head [ 0 ] + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay_IWORK . Head [ 0 ] == _rtDW -> TransportDelay_IWORK . Tail [ 0
] ) { if ( ! Seminar2_Part2_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK . CircularBufSize [ 0 ] , & _rtDW ->
TransportDelay_IWORK . Tail [ 0 ] , & _rtDW -> TransportDelay_IWORK . Head [
0 ] , & _rtDW -> TransportDelay_IWORK . Last [ 0 ] , simTime - _rtP -> P_45 ,
uBuffer , ( boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK .
MaxNewBufSize ) ) { ssSetErrorStatus ( S , "tdelay memory allocation error" )
; return ; } } ( * uBuffer + _rtDW -> TransportDelay_IWORK . CircularBufSize
[ 0 ] ) [ _rtDW -> TransportDelay_IWORK . Head [ 0 ] ] = simTime ; ( *
uBuffer ++ ) [ _rtDW -> TransportDelay_IWORK . Head [ 0 ] ] = _rtB ->
B_30_12_0 [ 0 ] ; _rtDW -> TransportDelay_IWORK . Head [ 1 ] = ( ( _rtDW ->
TransportDelay_IWORK . Head [ 1 ] < ( _rtDW -> TransportDelay_IWORK .
CircularBufSize [ 1 ] - 1 ) ) ? ( _rtDW -> TransportDelay_IWORK . Head [ 1 ]
+ 1 ) : 0 ) ; if ( _rtDW -> TransportDelay_IWORK . Head [ 1 ] == _rtDW ->
TransportDelay_IWORK . Tail [ 1 ] ) { if ( !
Seminar2_Part2_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK . CircularBufSize [ 1 ] , & _rtDW ->
TransportDelay_IWORK . Tail [ 1 ] , & _rtDW -> TransportDelay_IWORK . Head [
1 ] , & _rtDW -> TransportDelay_IWORK . Last [ 1 ] , simTime - _rtP -> P_45 ,
uBuffer , ( boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK .
MaxNewBufSize ) ) { ssSetErrorStatus ( S , "tdelay memory allocation error" )
; return ; } } ( * uBuffer + _rtDW -> TransportDelay_IWORK . CircularBufSize
[ 1 ] ) [ _rtDW -> TransportDelay_IWORK . Head [ 1 ] ] = simTime ; ( *
uBuffer ) [ _rtDW -> TransportDelay_IWORK . Head [ 1 ] ] = _rtB -> B_30_12_0
[ 1 ] ; } { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_m . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
_rtDW -> TransportDelay_IWORK_g . Head [ 0 ] = ( ( _rtDW ->
TransportDelay_IWORK_g . Head [ 0 ] < ( _rtDW -> TransportDelay_IWORK_g .
CircularBufSize [ 0 ] - 1 ) ) ? ( _rtDW -> TransportDelay_IWORK_g . Head [ 0
] + 1 ) : 0 ) ; if ( _rtDW -> TransportDelay_IWORK_g . Head [ 0 ] == _rtDW ->
TransportDelay_IWORK_g . Tail [ 0 ] ) { if ( !
Seminar2_Part2_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_g . CircularBufSize [ 0 ] , & _rtDW ->
TransportDelay_IWORK_g . Tail [ 0 ] , & _rtDW -> TransportDelay_IWORK_g .
Head [ 0 ] , & _rtDW -> TransportDelay_IWORK_g . Last [ 0 ] , simTime - _rtP
-> P_49 , uBuffer , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_g . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * uBuffer + _rtDW ->
TransportDelay_IWORK_g . CircularBufSize [ 0 ] ) [ _rtDW ->
TransportDelay_IWORK_g . Head [ 0 ] ] = simTime ; ( * uBuffer ++ ) [ _rtDW ->
TransportDelay_IWORK_g . Head [ 0 ] ] = _rtB -> B_30_17_0 [ 0 ] ; _rtDW ->
TransportDelay_IWORK_g . Head [ 1 ] = ( ( _rtDW -> TransportDelay_IWORK_g .
Head [ 1 ] < ( _rtDW -> TransportDelay_IWORK_g . CircularBufSize [ 1 ] - 1 )
) ? ( _rtDW -> TransportDelay_IWORK_g . Head [ 1 ] + 1 ) : 0 ) ; if ( _rtDW
-> TransportDelay_IWORK_g . Head [ 1 ] == _rtDW -> TransportDelay_IWORK_g .
Tail [ 1 ] ) { if ( ! Seminar2_Part2_acc_rt_TDelayUpdateTailOrGrowBuf ( &
_rtDW -> TransportDelay_IWORK_g . CircularBufSize [ 1 ] , & _rtDW ->
TransportDelay_IWORK_g . Tail [ 1 ] , & _rtDW -> TransportDelay_IWORK_g .
Head [ 1 ] , & _rtDW -> TransportDelay_IWORK_g . Last [ 1 ] , simTime - _rtP
-> P_49 , uBuffer , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_g . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * uBuffer + _rtDW ->
TransportDelay_IWORK_g . CircularBufSize [ 1 ] ) [ _rtDW ->
TransportDelay_IWORK_g . Head [ 1 ] ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_g . Head [ 1 ] ] = _rtB -> B_30_17_0 [ 1 ] ; } { real_T
* * uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_g . TUbufferPtrs
[ 0 ] ; real_T simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK_j .
Head [ 0 ] = ( ( _rtDW -> TransportDelay_IWORK_j . Head [ 0 ] < ( _rtDW ->
TransportDelay_IWORK_j . CircularBufSize [ 0 ] - 1 ) ) ? ( _rtDW ->
TransportDelay_IWORK_j . Head [ 0 ] + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay_IWORK_j . Head [ 0 ] == _rtDW -> TransportDelay_IWORK_j . Tail
[ 0 ] ) { if ( ! Seminar2_Part2_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_j . CircularBufSize [ 0 ] , & _rtDW ->
TransportDelay_IWORK_j . Tail [ 0 ] , & _rtDW -> TransportDelay_IWORK_j .
Head [ 0 ] , & _rtDW -> TransportDelay_IWORK_j . Last [ 0 ] , simTime - _rtP
-> P_53 , uBuffer , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_j . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * uBuffer + _rtDW ->
TransportDelay_IWORK_j . CircularBufSize [ 0 ] ) [ _rtDW ->
TransportDelay_IWORK_j . Head [ 0 ] ] = simTime ; ( * uBuffer ++ ) [ _rtDW ->
TransportDelay_IWORK_j . Head [ 0 ] ] = _rtB -> B_30_22_0 [ 0 ] ; _rtDW ->
TransportDelay_IWORK_j . Head [ 1 ] = ( ( _rtDW -> TransportDelay_IWORK_j .
Head [ 1 ] < ( _rtDW -> TransportDelay_IWORK_j . CircularBufSize [ 1 ] - 1 )
) ? ( _rtDW -> TransportDelay_IWORK_j . Head [ 1 ] + 1 ) : 0 ) ; if ( _rtDW
-> TransportDelay_IWORK_j . Head [ 1 ] == _rtDW -> TransportDelay_IWORK_j .
Tail [ 1 ] ) { if ( ! Seminar2_Part2_acc_rt_TDelayUpdateTailOrGrowBuf ( &
_rtDW -> TransportDelay_IWORK_j . CircularBufSize [ 1 ] , & _rtDW ->
TransportDelay_IWORK_j . Tail [ 1 ] , & _rtDW -> TransportDelay_IWORK_j .
Head [ 1 ] , & _rtDW -> TransportDelay_IWORK_j . Last [ 1 ] , simTime - _rtP
-> P_53 , uBuffer , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_j . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * uBuffer + _rtDW ->
TransportDelay_IWORK_j . CircularBufSize [ 1 ] ) [ _rtDW ->
TransportDelay_IWORK_j . Head [ 1 ] ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_j . Head [ 1 ] ] = _rtB -> B_30_22_0 [ 1 ] ; } { real_T
* * uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_i . TUbufferPtrs
[ 0 ] ; real_T simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK_e .
Head [ 0 ] = ( ( _rtDW -> TransportDelay_IWORK_e . Head [ 0 ] < ( _rtDW ->
TransportDelay_IWORK_e . CircularBufSize [ 0 ] - 1 ) ) ? ( _rtDW ->
TransportDelay_IWORK_e . Head [ 0 ] + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay_IWORK_e . Head [ 0 ] == _rtDW -> TransportDelay_IWORK_e . Tail
[ 0 ] ) { if ( ! Seminar2_Part2_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_e . CircularBufSize [ 0 ] , & _rtDW ->
TransportDelay_IWORK_e . Tail [ 0 ] , & _rtDW -> TransportDelay_IWORK_e .
Head [ 0 ] , & _rtDW -> TransportDelay_IWORK_e . Last [ 0 ] , simTime - _rtP
-> P_57 , uBuffer , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_e . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * uBuffer + _rtDW ->
TransportDelay_IWORK_e . CircularBufSize [ 0 ] ) [ _rtDW ->
TransportDelay_IWORK_e . Head [ 0 ] ] = simTime ; ( * uBuffer ++ ) [ _rtDW ->
TransportDelay_IWORK_e . Head [ 0 ] ] = _rtB -> B_30_27_0 [ 0 ] ; _rtDW ->
TransportDelay_IWORK_e . Head [ 1 ] = ( ( _rtDW -> TransportDelay_IWORK_e .
Head [ 1 ] < ( _rtDW -> TransportDelay_IWORK_e . CircularBufSize [ 1 ] - 1 )
) ? ( _rtDW -> TransportDelay_IWORK_e . Head [ 1 ] + 1 ) : 0 ) ; if ( _rtDW
-> TransportDelay_IWORK_e . Head [ 1 ] == _rtDW -> TransportDelay_IWORK_e .
Tail [ 1 ] ) { if ( ! Seminar2_Part2_acc_rt_TDelayUpdateTailOrGrowBuf ( &
_rtDW -> TransportDelay_IWORK_e . CircularBufSize [ 1 ] , & _rtDW ->
TransportDelay_IWORK_e . Tail [ 1 ] , & _rtDW -> TransportDelay_IWORK_e .
Head [ 1 ] , & _rtDW -> TransportDelay_IWORK_e . Last [ 1 ] , simTime - _rtP
-> P_57 , uBuffer , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_e . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * uBuffer + _rtDW ->
TransportDelay_IWORK_e . CircularBufSize [ 1 ] ) [ _rtDW ->
TransportDelay_IWORK_e . Head [ 1 ] ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_e . Head [ 1 ] ] = _rtB -> B_30_27_0 [ 1 ] ; } { real_T
* * uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_n . TUbufferPtrs
[ 0 ] ; real_T simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK_l .
Head [ 0 ] = ( ( _rtDW -> TransportDelay_IWORK_l . Head [ 0 ] < ( _rtDW ->
TransportDelay_IWORK_l . CircularBufSize [ 0 ] - 1 ) ) ? ( _rtDW ->
TransportDelay_IWORK_l . Head [ 0 ] + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay_IWORK_l . Head [ 0 ] == _rtDW -> TransportDelay_IWORK_l . Tail
[ 0 ] ) { if ( ! Seminar2_Part2_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_l . CircularBufSize [ 0 ] , & _rtDW ->
TransportDelay_IWORK_l . Tail [ 0 ] , & _rtDW -> TransportDelay_IWORK_l .
Head [ 0 ] , & _rtDW -> TransportDelay_IWORK_l . Last [ 0 ] , simTime - _rtP
-> P_61 , uBuffer , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_l . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * uBuffer + _rtDW ->
TransportDelay_IWORK_l . CircularBufSize [ 0 ] ) [ _rtDW ->
TransportDelay_IWORK_l . Head [ 0 ] ] = simTime ; ( * uBuffer ++ ) [ _rtDW ->
TransportDelay_IWORK_l . Head [ 0 ] ] = _rtB -> B_30_32_0 [ 0 ] ; _rtDW ->
TransportDelay_IWORK_l . Head [ 1 ] = ( ( _rtDW -> TransportDelay_IWORK_l .
Head [ 1 ] < ( _rtDW -> TransportDelay_IWORK_l . CircularBufSize [ 1 ] - 1 )
) ? ( _rtDW -> TransportDelay_IWORK_l . Head [ 1 ] + 1 ) : 0 ) ; if ( _rtDW
-> TransportDelay_IWORK_l . Head [ 1 ] == _rtDW -> TransportDelay_IWORK_l .
Tail [ 1 ] ) { if ( ! Seminar2_Part2_acc_rt_TDelayUpdateTailOrGrowBuf ( &
_rtDW -> TransportDelay_IWORK_l . CircularBufSize [ 1 ] , & _rtDW ->
TransportDelay_IWORK_l . Tail [ 1 ] , & _rtDW -> TransportDelay_IWORK_l .
Head [ 1 ] , & _rtDW -> TransportDelay_IWORK_l . Last [ 1 ] , simTime - _rtP
-> P_61 , uBuffer , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_l . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * uBuffer + _rtDW ->
TransportDelay_IWORK_l . CircularBufSize [ 1 ] ) [ _rtDW ->
TransportDelay_IWORK_l . Head [ 1 ] ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_l . Head [ 1 ] ] = _rtB -> B_30_32_0 [ 1 ] ; } { real_T
* * uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_p . TUbufferPtrs
[ 0 ] ; real_T simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK_f .
Head [ 0 ] = ( ( _rtDW -> TransportDelay_IWORK_f . Head [ 0 ] < ( _rtDW ->
TransportDelay_IWORK_f . CircularBufSize [ 0 ] - 1 ) ) ? ( _rtDW ->
TransportDelay_IWORK_f . Head [ 0 ] + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay_IWORK_f . Head [ 0 ] == _rtDW -> TransportDelay_IWORK_f . Tail
[ 0 ] ) { if ( ! Seminar2_Part2_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_f . CircularBufSize [ 0 ] , & _rtDW ->
TransportDelay_IWORK_f . Tail [ 0 ] , & _rtDW -> TransportDelay_IWORK_f .
Head [ 0 ] , & _rtDW -> TransportDelay_IWORK_f . Last [ 0 ] , simTime - _rtP
-> P_65 , uBuffer , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_f . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * uBuffer + _rtDW ->
TransportDelay_IWORK_f . CircularBufSize [ 0 ] ) [ _rtDW ->
TransportDelay_IWORK_f . Head [ 0 ] ] = simTime ; ( * uBuffer ++ ) [ _rtDW ->
TransportDelay_IWORK_f . Head [ 0 ] ] = _rtB -> B_30_37_0 [ 0 ] ; _rtDW ->
TransportDelay_IWORK_f . Head [ 1 ] = ( ( _rtDW -> TransportDelay_IWORK_f .
Head [ 1 ] < ( _rtDW -> TransportDelay_IWORK_f . CircularBufSize [ 1 ] - 1 )
) ? ( _rtDW -> TransportDelay_IWORK_f . Head [ 1 ] + 1 ) : 0 ) ; if ( _rtDW
-> TransportDelay_IWORK_f . Head [ 1 ] == _rtDW -> TransportDelay_IWORK_f .
Tail [ 1 ] ) { if ( ! Seminar2_Part2_acc_rt_TDelayUpdateTailOrGrowBuf ( &
_rtDW -> TransportDelay_IWORK_f . CircularBufSize [ 1 ] , & _rtDW ->
TransportDelay_IWORK_f . Tail [ 1 ] , & _rtDW -> TransportDelay_IWORK_f .
Head [ 1 ] , & _rtDW -> TransportDelay_IWORK_f . Last [ 1 ] , simTime - _rtP
-> P_65 , uBuffer , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_f . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * uBuffer + _rtDW ->
TransportDelay_IWORK_f . CircularBufSize [ 1 ] ) [ _rtDW ->
TransportDelay_IWORK_f . Head [ 1 ] ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_f . Head [ 1 ] ] = _rtB -> B_30_37_0 [ 1 ] ; }
Seminar2_Part2_TrueRMS_Update ( S , & _rtB -> TrueRMS_m , & _rtDW ->
TrueRMS_m , & _rtP -> TrueRMS_m ) ; Seminar2_Part2_RMS_Update ( S , & _rtB ->
RMS_m , & _rtDW -> RMS_m , & _rtP -> RMS_m ) ; { real_T * * uBuffer = (
real_T * * ) & _rtDW -> TransportDelay_PWORK_f . TUbufferPtrs [ 0 ] ; real_T
simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK_e2 . Head = ( ( _rtDW
-> TransportDelay_IWORK_e2 . Head < ( _rtDW -> TransportDelay_IWORK_e2 .
CircularBufSize - 1 ) ) ? ( _rtDW -> TransportDelay_IWORK_e2 . Head + 1 ) : 0
) ; if ( _rtDW -> TransportDelay_IWORK_e2 . Head == _rtDW ->
TransportDelay_IWORK_e2 . Tail ) { if ( !
Seminar2_Part2_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_e2 . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_e2 . Tail , & _rtDW -> TransportDelay_IWORK_e2 . Head ,
& _rtDW -> TransportDelay_IWORK_e2 . Last , simTime - _rtP -> P_69 , uBuffer
, ( boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK_e2 .
MaxNewBufSize ) ) { ssSetErrorStatus ( S , "tdelay memory allocation error" )
; return ; } } ( * uBuffer + _rtDW -> TransportDelay_IWORK_e2 .
CircularBufSize ) [ _rtDW -> TransportDelay_IWORK_e2 . Head ] = simTime ; ( *
uBuffer ) [ _rtDW -> TransportDelay_IWORK_e2 . Head ] = _rtB -> B_30_53_0 ; }
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
Memory_PreviousInput = _rtB -> B_30_60_0 ; } Seminar2_Part2_TrueRMS_Update (
S , & _rtB -> TrueRMS_e , & _rtDW -> TrueRMS_e , & _rtP -> TrueRMS_e ) ;
Seminar2_Part2_RMS_Update ( S , & _rtB -> RMS_b , & _rtDW -> RMS_b , & _rtP
-> RMS_b ) ; Seminar2_Part2_TrueRMS_Update ( S , & _rtB -> TrueRMS , & _rtDW
-> TrueRMS , & _rtP -> TrueRMS ) ; Seminar2_Part2_RMS_Update ( S , & _rtB ->
RMS , & _rtDW -> RMS , & _rtP -> RMS ) ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdateTID2 ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER (
tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { B_Seminar2_Part2_T * _rtB ;
DW_Seminar2_Part2_T * _rtDW ; P_Seminar2_Part2_T * _rtP ;
XDot_Seminar2_Part2_T * _rtXdot ; X_Seminar2_Part2_T * _rtX ; _rtDW = ( (
DW_Seminar2_Part2_T * ) ssGetRootDWork ( S ) ) ; _rtXdot = ( (
XDot_Seminar2_Part2_T * ) ssGetdX ( S ) ) ; _rtX = ( ( X_Seminar2_Part2_T * )
ssGetContStates ( S ) ) ; _rtP = ( ( P_Seminar2_Part2_T * ) ssGetModelRtp ( S
) ) ; _rtB = ( ( B_Seminar2_Part2_T * ) _ssGetModelBlockIO ( S ) ) ;
ssCallAccelRunBlock ( S , 30 , 3 , SS_CALL_MDL_DERIVATIVES ) ;
Seminar2_Part2_TrueRMS_Deriv ( S , & _rtB -> TrueRMS_j , & _rtDW -> TrueRMS_j
, & _rtXdot -> TrueRMS_j ) ; Seminar2_Part2_RMS_Deriv ( S , & _rtB -> RMS_l ,
& _rtDW -> RMS_l , & _rtXdot -> RMS_l ) ; Seminar2_Part2_TrueRMS_Deriv ( S ,
& _rtB -> TrueRMS_i , & _rtDW -> TrueRMS_i , & _rtXdot -> TrueRMS_i ) ;
Seminar2_Part2_RMS_Deriv ( S , & _rtB -> RMS_g , & _rtDW -> RMS_g , & _rtXdot
-> RMS_g ) ; _rtXdot -> Integrator_CSTATE [ 0 ] = _rtB -> B_30_86_0 [ 0 ] ;
_rtXdot -> Integrator_CSTATE_j [ 0 ] = _rtB -> B_30_88_0 [ 0 ] ; _rtXdot ->
Integrator_CSTATE_b [ 0 ] = _rtB -> B_30_90_0 [ 0 ] ; _rtXdot ->
Integrator_CSTATE_m [ 0 ] = _rtB -> B_30_81_0 [ 0 ] ; _rtXdot ->
Integrator_CSTATE_jh [ 0 ] = _rtB -> B_30_87_0 [ 0 ] ; _rtXdot ->
Integrator_CSTATE_o [ 0 ] = _rtB -> B_30_89_0 [ 0 ] ; _rtXdot ->
Integrator_CSTATE [ 1 ] = _rtB -> B_30_86_0 [ 1 ] ; _rtXdot ->
Integrator_CSTATE_j [ 1 ] = _rtB -> B_30_88_0 [ 1 ] ; _rtXdot ->
Integrator_CSTATE_b [ 1 ] = _rtB -> B_30_90_0 [ 1 ] ; _rtXdot ->
Integrator_CSTATE_m [ 1 ] = _rtB -> B_30_81_0 [ 1 ] ; _rtXdot ->
Integrator_CSTATE_jh [ 1 ] = _rtB -> B_30_87_0 [ 1 ] ; _rtXdot ->
Integrator_CSTATE_o [ 1 ] = _rtB -> B_30_89_0 [ 1 ] ;
Seminar2_Part2_TrueRMS_Deriv ( S , & _rtB -> TrueRMS_m , & _rtDW -> TrueRMS_m
, & _rtXdot -> TrueRMS_m ) ; Seminar2_Part2_RMS_Deriv ( S , & _rtB -> RMS_m ,
& _rtDW -> RMS_m , & _rtXdot -> RMS_m ) ; _rtXdot -> integrator_CSTATE = _rtB
-> B_30_8_0 ; Seminar2_Part2_TrueRMS_Deriv ( S , & _rtB -> TrueRMS_e , &
_rtDW -> TrueRMS_e , & _rtXdot -> TrueRMS_e ) ; Seminar2_Part2_RMS_Deriv ( S
, & _rtB -> RMS_b , & _rtDW -> RMS_b , & _rtXdot -> RMS_b ) ; _rtXdot ->
Integrator_CSTATE_g = _rtB -> B_30_1_0_c ; Seminar2_Part2_TrueRMS_Deriv ( S ,
& _rtB -> TrueRMS , & _rtDW -> TrueRMS , & _rtXdot -> TrueRMS ) ;
Seminar2_Part2_RMS_Deriv ( S , & _rtB -> RMS , & _rtDW -> RMS , & _rtXdot ->
RMS ) ; }
#define MDL_PROJECTION
static void mdlProjection ( SimStruct * S ) { B_Seminar2_Part2_T * _rtB ;
DW_Seminar2_Part2_T * _rtDW ; P_Seminar2_Part2_T * _rtP ; X_Seminar2_Part2_T
* _rtX ; _rtDW = ( ( DW_Seminar2_Part2_T * ) ssGetRootDWork ( S ) ) ; _rtX =
( ( X_Seminar2_Part2_T * ) ssGetContStates ( S ) ) ; _rtP = ( (
P_Seminar2_Part2_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( ( B_Seminar2_Part2_T
* ) _ssGetModelBlockIO ( S ) ) ; ssCallAccelRunBlock ( S , 30 , 3 ,
SS_CALL_MDL_PROJECTION ) ; }
#define MDL_ZERO_CROSSINGS
static void mdlZeroCrossings ( SimStruct * S ) { B_Seminar2_Part2_T * _rtB ;
DW_Seminar2_Part2_T * _rtDW ; P_Seminar2_Part2_T * _rtP ; X_Seminar2_Part2_T
* _rtX ; ZCV_Seminar2_Part2_T * _rtZCSV ; _rtDW = ( ( DW_Seminar2_Part2_T * )
ssGetRootDWork ( S ) ) ; _rtZCSV = ( ( ZCV_Seminar2_Part2_T * )
ssGetSolverZcSignalVector ( S ) ) ; _rtX = ( ( X_Seminar2_Part2_T * )
ssGetContStates ( S ) ) ; _rtP = ( ( P_Seminar2_Part2_T * ) ssGetModelRtp ( S
) ) ; _rtB = ( ( B_Seminar2_Part2_T * ) _ssGetModelBlockIO ( S ) ) ;
ssCallAccelRunBlock ( S , 30 , 3 , SS_CALL_MDL_ZERO_CROSSINGS ) ;
Seminar2_Part2_TrueRMS_ZC ( S , & _rtB -> TrueRMS_j , & _rtDW -> TrueRMS_j ,
& _rtP -> TrueRMS_j , & _rtZCSV -> TrueRMS_j ) ; Seminar2_Part2_TrueRMS_ZC (
S , & _rtB -> TrueRMS_i , & _rtDW -> TrueRMS_i , & _rtP -> TrueRMS_i , &
_rtZCSV -> TrueRMS_i ) ; Seminar2_Part2_TrueRMS_ZC ( S , & _rtB -> TrueRMS_m
, & _rtDW -> TrueRMS_m , & _rtP -> TrueRMS_m , & _rtZCSV -> TrueRMS_m ) ;
Seminar2_Part2_TrueRMS_ZC ( S , & _rtB -> TrueRMS_e , & _rtDW -> TrueRMS_e ,
& _rtP -> TrueRMS_e , & _rtZCSV -> TrueRMS_e ) ; Seminar2_Part2_TrueRMS_ZC (
S , & _rtB -> TrueRMS , & _rtDW -> TrueRMS , & _rtP -> TrueRMS , & _rtZCSV ->
TrueRMS ) ; } static void mdlInitializeSizes ( SimStruct * S ) {
ssSetChecksumVal ( S , 0 , 2501033024U ) ; ssSetChecksumVal ( S , 1 ,
3083892662U ) ; ssSetChecksumVal ( S , 2 , 2702329544U ) ; ssSetChecksumVal (
S , 3 , 1001825920U ) ; { mxArray * slVerStructMat = ( NULL ) ; mxArray *
slStrMat = mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ; int status
= mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" ) ; if (
status == 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 ,
"Version" ) ; if ( slVerMat == ( NULL ) ) { status = 1 ; } else { status =
mxGetString ( slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "10.7" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork ( S ) != ( SLSize )
sizeof ( DW_Seminar2_Part2_T ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file (%ld vs %lu)." , ( signed long )
ssGetSizeofDWork ( S ) , ( unsigned long ) sizeof ( DW_Seminar2_Part2_T ) ) ;
ssSetErrorStatus ( S , msg ) ; } if ( ssGetSizeofGlobalBlockIO ( S ) != (
SLSize ) sizeof ( B_Seminar2_Part2_T ) ) { static char msg [ 256 ] ; sprintf
( msg , "Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file (%ld vs %lu)." , ( signed long )
ssGetSizeofGlobalBlockIO ( S ) , ( unsigned long ) sizeof (
B_Seminar2_Part2_T ) ) ; ssSetErrorStatus ( S , msg ) ; } { int
ssSizeofParams ; ssGetSizeofParams ( S , & ssSizeofParams ) ; if (
ssSizeofParams != sizeof ( P_Seminar2_Part2_T ) ) { static char msg [ 256 ] ;
sprintf ( msg , "Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file (%d vs %lu)." , ssSizeofParams , (
unsigned long ) sizeof ( P_Seminar2_Part2_T ) ) ; ssSetErrorStatus ( S , msg
) ; } } _ssSetModelRtp ( S , ( real_T * ) & Seminar2_Part2_rtDefaultP ) ;
rt_InitInfAndNaN ( sizeof ( real_T ) ) ; ( ( P_Seminar2_Part2_T * )
ssGetModelRtp ( S ) ) -> P_73 = rtInf ; ( ( P_Seminar2_Part2_T * )
ssGetModelRtp ( S ) ) -> P_75 = rtInf ; ( ( P_Seminar2_Part2_T * )
ssGetModelRtp ( S ) ) -> TrueRMS_e . P_7 = rtInf ; ( ( P_Seminar2_Part2_T * )
ssGetModelRtp ( S ) ) -> TrueRMS_m . P_7 = rtInf ; ( ( P_Seminar2_Part2_T * )
ssGetModelRtp ( S ) ) -> TrueRMS_i . P_7 = rtInf ; ( ( P_Seminar2_Part2_T * )
ssGetModelRtp ( S ) ) -> TrueRMS_j . P_7 = rtInf ; ( ( P_Seminar2_Part2_T * )
ssGetModelRtp ( S ) ) -> TrueRMS . P_7 = rtInf ; } static void
mdlInitializeSampleTimes ( SimStruct * S ) { { SimStruct * childS ;
SysOutputFcn * callSysFcns ; childS = ssGetSFunction ( S , 0 ) ; callSysFcns
= ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; } slAccRegPrmChangeFcn ( S , mdlOutputsTID2 ) ; }
static void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
