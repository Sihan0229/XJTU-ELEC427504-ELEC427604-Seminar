#include "Seminar2_Part2_acc.h"
#include "Seminar2_Part2_acc_private.h"
P_Seminar2_Part2_T Seminar2_Part2_rtDefaultP = { 0.33333333333333331 ,
0.33333333333333331 , 1.5 , 0.33333333333333331 , 0.33333333333333331 , 1.5 ,
0.33333333333333331 , 0.33333333333333331 , 1.5 , 50.0 , 311.12698372208092 ,
0.0 , 314.15926535897933 , 0.0 , 311.12698372208092 , 0.0 ,
314.15926535897933 , - 2.0943951023931953 , 311.12698372208092 , 0.0 ,
314.15926535897933 , 2.0943951023931953 , { 53.0 , 24.0 } , { 0.0065 , 0.0 ,
0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 ,
0.0 , 0.0 , 0.0 , 0.006 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , - 0.008 , - 0.0 , -
0.002 , - 0.0 , - 0.002 , - 0.0 , - 0.002 , 0.004 , - 0.002 , - 0.002 , -
0.006 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 ,
0.0 , 0.0 , 6.0E-6 , - 1.0 , 0.0 , - 1.0 , 0.0 , - 1.0 , 0.0 , 2.5E-7 , 0.0 ,
0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 ,
0.0 , 0.0 , 0.01 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , - 0.006 , - 0.0 , - 0.002 ,
0.002 , - 0.002 , 0.002 , - 0.002 , 0.008 , - 0.004 , - 0.004 , - 0.01 , -
0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0
, 1.0000100000000003 , - 1.0 , 1.0 , - 1.0 , 1.0 , - 1.0 , 0.0 , 0.0 , 2.5E-7
, 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0
, 0.0 , 0.0 , 0.002 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , - 0.002 , - 0.0 , - 0.002
, - 0.0 , - 0.0 , - 0.0 , - 0.0 , 0.002 , - 0.0 , - 0.002 , - 0.002 , - 0.0 ,
- 0.0 , - 0.0 , - 0.0 , - 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 ,
2.0E-6 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 2.5E-7 , 0.0 , 0.0 ,
0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , -
0.002 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.002 , - 0.0
, - 0.0 , - 0.0 , - 0.002 , 0.002 , - 0.0 , 0.002 , - 0.0 , - 0.0 , - 0.0 , -
0.0 , - 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , - 2.0E-6 , 0.0 , 0.0
, 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 2.5E-7 , 0.0 , 0.0 , 0.0 , 0.0 ,
0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.002 , 0.0 , 0.0 , 0.0
, 0.0 , 0.0 , - 0.002 , - 0.0 , - 0.0 , - 0.0 , - 0.002 , - 0.0 , - 0.0 , -
0.0 , - 0.0 , - 0.0 , - 0.002 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , 0.0 ,
0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 2.0E-6 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 ,
0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 2.5E-7 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 ,
0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , - 0.002 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , -
0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.002 , - 0.0 , - 0.002 , - 0.0 ,
0.002 , 0.002 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , 0.0 , 0.0 , 0.0 , 0.0
, 0.0 , 0.0 , 0.0 , - 2.0E-6 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0
, 0.0 , 0.0 , 0.0 , 2.5E-7 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 ,
0.0 , 0.0 , 0.0 , 0.002 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , - 0.002 , - 0.0 , -
0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.002 , 0.002 , - 0.002 , - 0.0 , - 0.002 , -
0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0
, 2.0E-6 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 ,
0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.012
, 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , - 0.006 , 0.002 , - 0.002 , 0.002 , - 0.002 ,
0.002 , - 0.002 , 0.008 , - 0.004 , - 0.004 , - 0.012 , - 0.0 , - 0.0 , - 0.0
, - 0.0 , - 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 ,
1.0000120000000003 , - 1.0 , 1.0 , - 1.0 , 1.0 , - 1.0 , 0.0 , 0.0 , 0.0 ,
0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 ,
0.0 , 0.0 , 1.0 , 1.0 , 0.0 , 0.0 , 0.0 , 0.0 , - 1.0 , - 0.0 , - 0.0 , - 0.0
, - 0.0 , - 0.0 , - 0.0 , 1.0 , - 0.0 , - 1.0 , - 1.0 , - 1.0 , - 0.0 , - 0.0
, - 0.0 , - 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.001 , 0.001 ,
0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 ,
0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , - 1.0 , 0.0 , 1.0 , 0.0
, 0.0 , 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 1.0 ,
1.0 , - 0.0 , 1.0 , - 0.0 , - 1.0 , - 0.0 , - 0.0 , - 0.0 , 0.0 , 0.0 , 0.0 ,
0.0 , 0.0 , 0.0 , 0.0 , - 0.001 , 0.0 , 0.001 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 ,
0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 ,
0.0 , 0.0 , 0.0 , 1.0 , 0.0 , 0.0 , 1.0 , 0.0 , 0.0 , - 1.0 , - 0.0 , - 0.0 ,
- 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 1.0 , - 0.0 , - 0.0
, - 1.0 , - 0.0 , - 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.001 ,
0.0 , 0.0 , 0.001 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0
, 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , - 1.0 , 0.0 ,
0.0 , 0.0 , 1.0 , 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0
, - 1.0 , - 0.0 , 1.0 , 1.0 , - 0.0 , - 0.0 , - 0.0 , - 1.0 , - 0.0 , 0.0 ,
0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , - 0.001 , 0.0 , 0.0 , 0.0 , 0.001 , 0.0 ,
0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 ,
0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 1.0 , 0.0 , 0.0 , 0.0 , 0.0 , 1.0 , - 1.0 , -
0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , 1.0 , - 1.0 , - 0.0 , - 1.0 , -
0.0 , - 0.0 , - 0.0 , - 0.0 , - 1.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0
, 0.001 , 0.0 , 0.0 , 0.0 , 0.0 , 0.001 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , -
0.0 , - 0.0 , - 0.0 , 1.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 ,
0.0 , 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , 0.0 , 0.0 , 0.0 ,
0.0 , 0.0 , 0.0 , 0.0 , 1.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 ,
0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , -
0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , 0.0 ,
1.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , - 0.0 , - 0.0 , -
0.0 , - 0.0 , - 0.0 , - 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 ,
1.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 ,
0.0 , 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , -
0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , 0.0 , 0.0 , 1.0 , 0.0 , 0.0 , 0.0 , 0.0
, 0.0 , 0.0 , 0.0 , 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , 0.0
, 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 1.0 , 0.0 , 0.0 , 0.0 , 0.0
, 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , - 0.0 , - 0.0 , - 0.0
, - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , -
0.0 , 0.0 , 0.0 , 0.0 , 1.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , - 0.0
, - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , 1.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 ,
0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 ,
0.0 , 0.0 , 0.0 , 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0
, - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 1.0
, 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 ,
- 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 1.0 , 0.0 , 0.0 , 0.0 , 0.0
, 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , - 0.0 , -
0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 2.5E-7 , - 0.0 , - 0.0 ,
2.5E-7 , - 0.0 , - 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 1.0 , 0.0 , 0.0 , 0.0
, 0.0 , 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , 0.0 , 0.0 , 0.0
, 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0
, 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , - 1.0 , - 0.0 , - 0.0 , 1.0 , -
0.0 , - 0.0 , - 0.0 , - 2.5E-7 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , 0.0
, 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 1.0 , 0.0 , 0.0 , 0.0 , 0.0 , - 0.0 , - 0.0 ,
- 0.0 , - 0.0 , - 0.0 , - 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0
, 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0
, 0.0 , 0.0 , - 1.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0065 , -
0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 ,
0.0 , 0.0 , 1.0 , 0.0 , 0.0 , 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , -
0.0 , 0.002 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0
, 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , - 0.0 , -
0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 2.5E-7 , - 0.0 , - 0.0 ,
2.5E-7 , - 0.0 , - 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 1.0
, 0.0 , 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , 0.0 , 0.0 , 0.0
, 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0
, 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , - 1.0 , - 0.0 , - 0.0 , 1.0 , -
0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 2.5E-7 , - 0.0 , - 0.0 , 2.5E-7 , 0.0
, 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 1.0 , 0.0 , - 0.0 , - 0.0 ,
- 0.0 , - 0.0 , - 0.0 , - 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0
, 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0
, 0.0 , 0.0 , - 0.0 , - 0.0 , - 1.0 , - 0.0 , - 0.0 , 1.0 , - 0.0 , - 0.0 ,
2.5E-7 , - 0.0 , - 0.0 , - 2.5E-7 , - 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0
, 0.0 , 0.0 , 0.0 , 0.0 , 1.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0 , - 0.0
, 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0
, 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , - 0.0 , 1.0 , -
0.0 , - 0.0 , - 1.0 , - 0.0 } , { 1.0 , 4.0 } , { 7.0 , 9.0 , 11.0 , 6.0 } ,
{ 7.0 , 1.0 } , { - 4.9520151844527271E-14 , - 12.199115510540295 , -
275.12855293722106 , - 262.92943742668172 , 12.199115510540125 ,
275.12855293722112 , 262.92943742668177 } , { 53.0 , 33.0 } , { 100.0 , 100.0
, 100.0 , 100.0 , 100.0 , 100.0 , 100.0 , 121.0 , 121.0 , 121.0 , 121.0 ,
121.0 , 121.0 , 121.0 , 121.0 , 121.0 , 121.0 , 121.0 , 118.0 , 118.0 , 118.0
, 118.0 , 118.0 , 118.0 , 85.0 , 85.0 , 85.0 , 85.0 , 85.0 , 85.0 , 85.0 ,
118.0 , 118.0 , 118.0 , 118.0 , 118.0 , 118.0 , 118.0 , 118.0 , 118.0 , 85.0
, 85.0 , 85.0 , 85.0 , 85.0 , 85.0 , 85.0 , 105.0 , 105.0 , 105.0 , 105.0 ,
105.0 , 105.0 , 85.0 , 85.0 , 85.0 , 85.0 , 85.0 , 85.0 , 85.0 , 118.0 ,
118.0 , 118.0 , 118.0 , 118.0 , 105.0 , 105.0 , 105.0 , 105.0 , 105.0 , 105.0
, 83.0 , 83.0 , 83.0 , 83.0 , 83.0 , 83.0 , 99.0 , 99.0 , 99.0 , 99.0 , 99.0
, 99.0 , 99.0 , 69.0 , 69.0 , 69.0 , 69.0 , 69.0 , 69.0 , 69.0 , 69.0 , 69.0
, 99.0 , 99.0 , 99.0 , 99.0 , 99.0 , 99.0 , 99.0 , 83.0 , 83.0 , 83.0 , 83.0
, 83.0 , 83.0 , 99.0 , 99.0 , 99.0 , 99.0 , 99.0 , 99.0 , 99.0 , 32.0 , 32.0
, 32.0 , 95.0 , 95.0 , 95.0 , 95.0 , 95.0 , 32.0 , 32.0 , 32.0 , 87.0 , 87.0
, 87.0 , 87.0 , 87.0 , 87.0 , 95.0 , 95.0 , 95.0 , 95.0 , 95.0 , 95.0 , 95.0
, 95.0 , 95.0 , 95.0 , 95.0 , 95.0 , 95.0 , 95.0 , 95.0 , 95.0 , 95.0 , 95.0
, 95.0 , 95.0 , 95.0 , 95.0 , 95.0 , 87.0 , 87.0 , 87.0 , 87.0 , 87.0 , 87.0
, 95.0 , 95.0 , 95.0 , 95.0 , 95.0 , 95.0 , 95.0 , 65.0 , 66.0 , 67.0 , 86.0
, 86.0 , 67.0 , 67.0 , 67.0 , 65.0 , 66.0 , 67.0 , 95.0 , 95.0 , 95.0 , 95.0
, 95.0 , 95.0 , 82.0 , 115.0 , 115.0 , 115.0 , 115.0 , 115.0 , 115.0 , 85.0 ,
85.0 , 85.0 , 85.0 , 85.0 , 85.0 , 85.0 , 85.0 , 85.0 , 82.0 , 115.0 , 115.0
, 115.0 , 115.0 , 115.0 , 115.0 , 95.0 , 95.0 , 95.0 , 95.0 , 95.0 , 95.0 ,
82.0 , 115.0 , 115.0 , 115.0 , 115.0 , 115.0 , 115.0 , 58.0 , 58.0 , 58.0 ,
111.0 , 111.0 , 117.0 , 117.0 , 117.0 , 58.0 , 58.0 , 58.0 , 83.0 , 83.0 ,
83.0 , 83.0 , 83.0 , 83.0 , 67.0 , 110.0 , 110.0 , 110.0 , 110.0 , 110.0 ,
110.0 , 95.0 , 95.0 , 95.0 , 95.0 , 95.0 , 95.0 , 95.0 , 95.0 , 95.0 , 67.0 ,
110.0 , 110.0 , 110.0 , 110.0 , 110.0 , 110.0 , 83.0 , 83.0 , 83.0 , 83.0 ,
83.0 , 83.0 , 67.0 , 110.0 , 110.0 , 110.0 , 110.0 , 110.0 , 110.0 , 32.0 ,
32.0 , 32.0 , 108.0 , 108.0 , 114.0 , 114.0 , 114.0 , 32.0 , 32.0 , 32.0 ,
80.0 , 80.0 , 80.0 , 80.0 , 80.0 , 80.0 , 32.0 , 117.0 , 117.0 , 117.0 ,
117.0 , 117.0 , 117.0 , 65.0 , 66.0 , 67.0 , 86.0 , 86.0 , 86.0 , 86.0 , 86.0
, 86.0 , 32.0 , 117.0 , 117.0 , 117.0 , 117.0 , 117.0 , 117.0 , 80.0 , 80.0 ,
80.0 , 80.0 , 80.0 , 80.0 , 32.0 , 117.0 , 117.0 , 117.0 , 117.0 , 117.0 ,
117.0 , 84.0 , 84.0 , 84.0 , 116.0 , 116.0 , 114.0 , 114.0 , 114.0 , 84.0 ,
84.0 , 84.0 , 73.0 , 73.0 , 73.0 , 73.0 , 73.0 , 73.0 , 66.0 , 98.0 , 98.0 ,
98.0 , 98.0 , 98.0 , 98.0 , 58.0 , 58.0 , 58.0 , 102.0 , 102.0 , 102.0 ,
102.0 , 102.0 , 102.0 , 66.0 , 98.0 , 98.0 , 98.0 , 98.0 , 98.0 , 98.0 , 73.0
, 73.0 , 73.0 , 73.0 , 73.0 , 73.0 , 66.0 , 98.0 , 98.0 , 98.0 , 98.0 , 98.0
, 98.0 , 104.0 , 104.0 , 104.0 , 97.0 , 97.0 , 101.0 , 101.0 , 101.0 , 104.0
, 104.0 , 104.0 , 68.0 , 68.0 , 68.0 , 68.0 , 68.0 , 68.0 , 114.0 , 98.0 ,
98.0 , 98.0 , 98.0 , 98.0 , 98.0 , 32.0 , 32.0 , 32.0 , 58.0 , 58.0 , 58.0 ,
58.0 , 58.0 , 58.0 , 114.0 , 98.0 , 98.0 , 98.0 , 98.0 , 98.0 , 98.0 , 68.0 ,
68.0 , 68.0 , 68.0 , 68.0 , 68.0 , 114.0 , 98.0 , 98.0 , 98.0 , 98.0 , 98.0 ,
98.0 , 114.0 , 114.0 , 114.0 , 103.0 , 103.0 , 110.0 , 110.0 , 110.0 , 114.0
, 114.0 , 114.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 97.0 , 101.0 ,
101.0 , 101.0 , 101.0 , 101.0 , 101.0 , 84.0 , 84.0 , 84.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 97.0 , 101.0 , 101.0 , 101.0 , 101.0 , 101.0 ,
101.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 97.0 , 101.0 , 101.0 ,
101.0 , 101.0 , 101.0 , 101.0 , 101.0 , 101.0 , 101.0 , 101.0 , 101.0 , 116.0
, 116.0 , 116.0 , 101.0 , 101.0 , 101.0 , 86.0 , 86.0 , 86.0 , 86.0 , 86.0 ,
86.0 , 110.0 , 114.0 , 114.0 , 114.0 , 114.0 , 114.0 , 114.0 , 104.0 , 104.0
, 104.0 , 86.0 , 86.0 , 86.0 , 86.0 , 86.0 , 86.0 , 110.0 , 114.0 , 114.0 ,
114.0 , 114.0 , 114.0 , 114.0 , 86.0 , 86.0 , 86.0 , 86.0 , 86.0 , 86.0 ,
110.0 , 114.0 , 114.0 , 114.0 , 114.0 , 114.0 , 114.0 , 101.0 , 101.0 , 101.0
, 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 101.0 , 101.0 , 101.0 , 68.0 , 68.0 ,
68.0 , 68.0 , 68.0 , 68.0 , 99.0 , 58.0 , 58.0 , 58.0 , 58.0 , 58.0 , 58.0 ,
114.0 , 114.0 , 114.0 , 68.0 , 68.0 , 68.0 , 68.0 , 68.0 , 68.0 , 99.0 , 58.0
, 58.0 , 58.0 , 58.0 , 58.0 , 58.0 , 68.0 , 68.0 , 68.0 , 68.0 , 68.0 , 68.0
, 99.0 , 58.0 , 58.0 , 58.0 , 58.0 , 58.0 , 58.0 , 45.0 , 45.0 , 45.0 , 77.0
, 77.0 , 77.0 , 77.0 , 77.0 , 45.0 , 45.0 , 45.0 , 49.0 , 50.0 , 51.0 , 52.0
, 53.0 , 54.0 , 104.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 101.0 ,
101.0 , 101.0 , 49.0 , 50.0 , 51.0 , 52.0 , 53.0 , 54.0 , 104.0 , 32.0 , 32.0
, 32.0 , 32.0 , 32.0 , 32.0 , 49.0 , 50.0 , 51.0 , 52.0 , 53.0 , 54.0 , 104.0
, 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 80.0 , 80.0 , 80.0 , 101.0 ,
101.0 , 101.0 , 101.0 , 101.0 , 80.0 , 80.0 , 80.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 86.0 , 86.0 , 86.0 , 86.0 , 86.0 , 86.0 , 101.0 ,
101.0 , 101.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 86.0 , 86.0
, 86.0 , 86.0 , 86.0 , 86.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0
, 86.0 , 86.0 , 86.0 , 86.0 , 86.0 , 86.0 , 104.0 , 104.0 , 104.0 , 97.0 ,
97.0 , 97.0 , 97.0 , 97.0 , 104.0 , 104.0 , 104.0 , 32.0 , 32.0 , 32.0 , 32.0
, 32.0 , 32.0 , 32.0 , 68.0 , 68.0 , 68.0 , 68.0 , 68.0 , 68.0 , 45.0 , 45.0
, 45.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 68.0 , 68.0 , 68.0
, 68.0 , 68.0 , 68.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 68.0
, 68.0 , 68.0 , 68.0 , 68.0 , 68.0 , 97.0 , 97.0 , 97.0 , 115.0 , 115.0 ,
115.0 , 115.0 , 115.0 , 97.0 , 97.0 , 97.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0
, 32.0 , 32.0 , 49.0 , 50.0 , 51.0 , 52.0 , 53.0 , 54.0 , 80.0 , 80.0 , 80.0
, 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 49.0 , 50.0 , 51.0 , 52.0
, 53.0 , 54.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 49.0 , 50.0
, 51.0 , 52.0 , 53.0 , 54.0 , 115.0 , 115.0 , 115.0 , 117.0 , 117.0 , 117.0 ,
117.0 , 117.0 , 115.0 , 115.0 , 115.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 104.0 , 104.0 , 104.0
, 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0
, 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0
, 32.0 , 32.0 , 32.0 , 32.0 , 101.0 , 101.0 , 101.0 , 114.0 , 114.0 , 114.0 ,
114.0 , 114.0 , 101.0 , 101.0 , 101.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 97.0 , 97.0 , 97.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 10.0 , 10.0 , 10.0 , 101.0 , 101.0 , 101.0 ,
101.0 , 101.0 , 10.0 , 10.0 , 10.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0
, 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 115.0 , 115.0 , 115.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 86.0 , 86.0 , 86.0 , 109.0 , 109.0 , 109.0 ,
109.0 , 109.0 , 86.0 , 86.0 , 86.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0
, 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 101.0 , 101.0 , 101.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 45.0 , 45.0 , 45.0 , 101.0 , 101.0 , 101.0 ,
101.0 , 101.0 , 45.0 , 45.0 , 45.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0
, 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0
, 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0
, 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0
, 32.0 , 32.0 , 32.0 , 73.0 , 73.0 , 73.0 , 110.0 , 110.0 , 110.0 , 110.0 ,
110.0 , 73.0 , 73.0 , 73.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 83.0 , 83.0 , 83.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 116.0 , 116.0 , 116.0 , 116.0 , 116.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 111.0 , 111.0 , 111.0 , 32.0 , 32.0 , 32.0
, 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0
, 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0
, 32.0 , 77.0 , 77.0 , 77.0 , 32.0 , 49.0 , 49.0 , 50.0 , 51.0 , 77.0 , 77.0
, 77.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0
, 32.0 , 32.0 , 32.0 , 117.0 , 117.0 , 117.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
101.0 , 101.0 , 101.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 101.0 , 101.0 ,
101.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 114.0 , 114.0 , 114.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0
, 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0
, 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 97.0
, 97.0 , 97.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 97.0 , 97.0 , 97.0 , 32.0
, 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0
, 32.0 , 99.0 , 99.0 , 99.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0
, 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0
, 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 115.0 , 115.0 ,
115.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 115.0 , 115.0 , 115.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 101.0 , 101.0 , 101.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0
, 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0
, 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 117.0 , 117.0 ,
117.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 117.0 , 117.0 , 117.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 114.0 , 114.0 , 114.0
, 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 114.0 , 114.0 , 114.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 101.0 , 101.0 , 101.0 , 32.0
, 32.0 , 32.0 , 32.0 , 32.0 , 101.0 , 101.0 , 101.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 109.0 , 109.0 , 109.0 , 32.0 , 32.0
, 32.0 , 32.0 , 32.0 , 109.0 , 109.0 , 109.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 101.0 , 101.0 , 101.0 , 32.0 , 32.0 , 32.0
, 32.0 , 32.0 , 101.0 , 101.0 , 101.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 110.0 , 110.0 , 110.0 , 32.0 , 32.0 , 32.0 , 32.0
, 32.0 , 110.0 , 110.0 , 110.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 116.0 , 116.0 , 116.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0
, 116.0 , 116.0 , 116.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 ,
32.0 , 32.0 , 32.0 , 32.0 , 32.0 , 32.0 } , { 2.0 , 6.0 } , { 0.8 , 0.8 , 0.8
, 0.8 , 0.8 , 0.8 , 0.8 , 0.8 , 0.8 , 0.8 , 0.8 , 0.8 } , { 1.0 , 6.0 } , {
3.0 , 3.0 , 3.0 , 3.0 , 3.0 , 3.0 } , { 6.0 , 1.0 } , { 0.0 , 0.0 , 0.0 , 0.0
, 0.0 , 0.0 } , { 1.0 , 6.0 } , { 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 } , { 1.0
, 1.0 } , 0.0 , { 1.0 , 1.0 } , 100.0 , 1.0 , 1.0 , 0.0 , 0.02 , 0.0 , 100.0
, 0.0 , 0.02 , 0.0 , 100.0 , 0.0 , 0.02 , 0.0 , 100.0 , 0.0 , 0.02 , 0.0 ,
100.0 , 0.0 , 0.02 , 0.0 , 100.0 , 0.0 , 0.02 , 0.0 , 100.0 , 0.0 , 0.02 ,
0.0 , 0.02 , 0.0 , 0.0 , 2.2204460492503131E-16 , 0.0 ,
2.2204460492503131E-16 , 1.0 , 1.0 , 1.0 , 1.0 , 0.0 , 6.2831853071795862 ,
0.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 314.15926535897933 ,
1.0 , 1.0 , 1.0 , 0.0 , 1.0 , 0.8 , 0.0 , 0.8 , 0.0 , 0.8 , 0.0 , 0.8 , 0.0 ,
0.8 , 0.0 , 0.8 , 0.0 , { - 0.5 , - 0.8660254037844386 } , { - 0.5 ,
0.8660254037844386 } , { - 0.5 , - 0.8660254037844386 } , { - 0.5 ,
0.8660254037844386 } , { - 0.5 , 0.8660254037844386 } , { - 0.5 , -
0.8660254037844386 } , { - 0.5 , 0.8660254037844386 } , { - 0.5 , -
0.8660254037844386 } , { 50.0 , 0.0 , 0.0 , 0.02 , 0.0 , 0.02 , 0.0 , 0.0 ,
0.0 } , { 50.0 , 50.0 , 0.0 , 0.0 , 0.02 , 0.0 , 0.02 , 0.0 , 0.0 , 0.02 ,
0.0 , 0.02 , 0.0 , 2.0 , 0.0 , 314.15926535897933 , 0.0 , 2.0 , 0.0 ,
314.15926535897933 , 1.5707963267948966 , 0.70710678118654746 } , { 50.0 ,
0.0 , 0.0 , 0.02 , 0.0 , 0.02 , 0.0 , 0.0 , 0.0 } , { 50.0 , 50.0 , 0.0 , 0.0
, 0.02 , 0.0 , 0.02 , 0.0 , 0.0 , 0.02 , 0.0 , 0.02 , 0.0 , 2.0 , 0.0 ,
314.15926535897933 , 0.0 , 2.0 , 0.0 , 314.15926535897933 ,
1.5707963267948966 , 0.70710678118654746 } , { 50.0 , 0.0 , 0.0 , 0.02 , 0.0
, 0.02 , 14400.0 , 0.0 , 0.0 } , { 50.0 , 50.0 , 0.0 , 0.0 , 0.02 , 0.0 ,
0.02 , 169.70562748477141 , 0.0 , 0.02 , 0.0 , 0.02 , 0.0 , 2.0 , 0.0 ,
314.15926535897933 , 0.0 , 2.0 , 0.0 , 314.15926535897933 ,
1.5707963267948966 , 0.70710678118654746 } , { 50.0 , 0.0 , 0.0 , 0.02 , 0.0
, 0.02 , 14400.0 , 0.0 , 0.0 } , { 50.0 , 50.0 , 0.0 , 0.0 , 0.02 , 0.0 ,
0.02 , 169.70562748477141 , 0.0 , 0.02 , 0.0 , 0.02 , 0.0 , 2.0 , 0.0 ,
314.15926535897933 , 0.0 , 2.0 , 0.0 , 314.15926535897933 ,
1.5707963267948966 , 0.70710678118654746 } , { 60.0 , 0.0 , 0.0 ,
0.016666666666666666 , 0.0 , 0.016666666666666666 , 14400.0 , 0.0 , 0.0 } , {
60.0 , 60.0 , 0.0 , 0.0 , 0.016666666666666666 , 0.0 , 0.016666666666666666 ,
169.70562748477141 , 0.0 , 0.016666666666666666 , 0.0 , 0.016666666666666666
, 0.0 , 2.0 , 0.0 , 376.99111843077515 , 0.0 , 2.0 , 0.0 , 376.99111843077515
, 1.5707963267948966 , 0.70710678118654746 } } ;