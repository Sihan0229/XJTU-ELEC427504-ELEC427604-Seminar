#ifndef RTW_HEADER_Seminar2_Part2_acc_private_h_
#define RTW_HEADER_Seminar2_Part2_acc_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "Seminar2_Part2_acc.h"
#include "Seminar2_Part2_acc_types.h"
#if !defined(ss_VALIDATE_MEMORY)
#define ss_VALIDATE_MEMORY(S, ptr)     if(!(ptr)) {\
    ssSetErrorStatus(S, RT_MEMORY_ALLOCATION_ERROR);\
    }
#endif
#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)     if((ptr) != (NULL)) {\
    free((ptr));\
    (ptr) = (NULL);\
    }
#else
#define rt_FREE(ptr)     if((ptr) != (NULL)) {\
    free((void *)(ptr));\
    (ptr) = (NULL);\
    }
#endif
#endif
#ifndef __RTW_UTFREE__
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
boolean_T Seminar2_Part2_acc_rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr
, int_T * tailPtr , int_T * headPtr , int_T * lastPtr , real_T tMinusDelay ,
real_T * * uBufPtr , boolean_T isfixedbuf , boolean_T istransportdelay ,
int_T * maxNewBufSzPtr ) ; real_T Seminar2_Part2_acc_rt_TDelayInterpolate (
real_T tMinusDelay , real_T tStart , real_T * uBuf , int_T bufSz , int_T *
lastIdx , int_T oldestIdx , int_T newIdx , real_T initOutput , boolean_T
discrete , boolean_T minorStepAndTAtLastMajorOutput ) ; void
Seminar2_Part2_RMS_Init ( SimStruct * S , B_RMS_Seminar2_Part2_T * localB ,
DW_RMS_Seminar2_Part2_T * localDW , P_RMS_Seminar2_Part2_T * localP ,
X_RMS_Seminar2_Part2_T * localX ) ; void Seminar2_Part2_RMS_Deriv ( SimStruct
* S , B_RMS_Seminar2_Part2_T * localB , DW_RMS_Seminar2_Part2_T * localDW ,
XDot_RMS_Seminar2_Part2_T * localXdot ) ; void Seminar2_Part2_RMS_Disable (
SimStruct * S , DW_RMS_Seminar2_Part2_T * localDW ) ; void
Seminar2_Part2_RMS_Update ( SimStruct * S , B_RMS_Seminar2_Part2_T * localB ,
DW_RMS_Seminar2_Part2_T * localDW , P_RMS_Seminar2_Part2_T * localP ) ; void
Seminar2_Part2_RMS ( SimStruct * S , boolean_T rtu_Enable , real_T rtu_In ,
B_RMS_Seminar2_Part2_T * localB , DW_RMS_Seminar2_Part2_T * localDW ,
P_RMS_Seminar2_Part2_T * localP , X_RMS_Seminar2_Part2_T * localX ,
XDis_RMS_Seminar2_Part2_T * localXdis ) ; void Seminar2_Part2_TrueRMS_Init (
SimStruct * S , B_TrueRMS_Seminar2_Part2_T * localB ,
DW_TrueRMS_Seminar2_Part2_T * localDW , P_TrueRMS_Seminar2_Part2_T * localP ,
X_TrueRMS_Seminar2_Part2_T * localX ) ; void Seminar2_Part2_TrueRMS_Deriv (
SimStruct * S , B_TrueRMS_Seminar2_Part2_T * localB ,
DW_TrueRMS_Seminar2_Part2_T * localDW , XDot_TrueRMS_Seminar2_Part2_T *
localXdot ) ; void Seminar2_Part2_TrueRMS_ZC ( SimStruct * S ,
B_TrueRMS_Seminar2_Part2_T * localB , DW_TrueRMS_Seminar2_Part2_T * localDW ,
P_TrueRMS_Seminar2_Part2_T * localP , ZCV_TrueRMS_Seminar2_Part2_T *
localZCSV ) ; void Seminar2_Part2_TrueRMS_Disable ( SimStruct * S ,
DW_TrueRMS_Seminar2_Part2_T * localDW ) ; void Seminar2_Part2_TrueRMS_Update
( SimStruct * S , B_TrueRMS_Seminar2_Part2_T * localB ,
DW_TrueRMS_Seminar2_Part2_T * localDW , P_TrueRMS_Seminar2_Part2_T * localP )
; void Seminar2_Part2_TrueRMS ( SimStruct * S , boolean_T rtu_Enable , real_T
rtu_In , B_TrueRMS_Seminar2_Part2_T * localB , DW_TrueRMS_Seminar2_Part2_T *
localDW , P_TrueRMS_Seminar2_Part2_T * localP , X_TrueRMS_Seminar2_Part2_T *
localX , XDis_TrueRMS_Seminar2_Part2_T * localXdis ) ; void
Seminar2_Part2_RMS_Term ( SimStruct * const S ) ; void
Seminar2_Part2_TrueRMS_Term ( SimStruct * const S ) ;
#endif
