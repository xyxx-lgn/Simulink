/*
 * File: PMSM_MC_2025a.c
 *
 * Code generated for Simulink model 'PMSM_MC_2025a'.
 *
 * Model version                  : 5.26
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Fri Oct 16 21:56:24 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PMSM_MC_2025a.h"
#include "rtwtypes.h"
#include <math.h>
#include "PMSM_MC_2025a_private.h"
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include <float.h>

/* Named constants for Chart: '<S331>/ModeMgr' */
#define PMSM_MC_2025_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define PMSM_MC_2025a_IN_CalFailed     ((uint8_T)1U)
#define PMSM_MC_2025a_IN_Calibrate     ((uint8_T)2U)
#define PMSM_MC_2025a_IN_Calibrate1    ((uint8_T)1U)
#define PMSM_MC_2025a_IN_Calibrate2    ((uint8_T)2U)
#define PMSM_MC_2025a_IN_IFStart       ((uint8_T)1U)
#define PMSM_MC_2025a_IN_Init          ((uint8_T)3U)
#define PMSM_MC_2025a_IN_Normal        ((uint8_T)3U)
#define PMSM_MC_2025a_IN_RngChk        ((uint8_T)4U)
#define PMSM_MC_2025a_IN_Run           ((uint8_T)1U)
#define PMSM_MC_2025a_IN_Run_i         ((uint8_T)2U)
#define PMSM_MC_2025a_IN_SensorCtr     ((uint8_T)1U)
#define PMSM_MC_2025a_IN_SensorLessCtr ((uint8_T)2U)
#define PMSM_MC_2025a_IN_StartFail     ((uint8_T)3U)
#define PMSM_MC_2025a_IN_Stop          ((uint8_T)2U)
#define PMSM_MC_2025a_IN_Stop_e        ((uint8_T)4U)
#define PMSM_MC_2025a_IN_VFOpenLoop    ((uint8_T)3U)

/* Named constants for Chart: '<S7>/OpenLopThetaeCal' */
#define PMSM_MC_2025a_IN_Align         ((uint8_T)1U)
#define PMSM_MC_2025a_IN_CloseLop      ((uint8_T)1U)
#define PMSM_MC_2025a_IN_IFStart_k     ((uint8_T)2U)
#define PMSM_MC_2025a_IN_Open          ((uint8_T)2U)
#define PMSM_MC_2025a_IN_Stop_m        ((uint8_T)3U)
#define PMSM_MC_2025a_IN_Transm        ((uint8_T)3U)
#define PMSM_MC_2025a_IN_VFOpenLoop_m  ((uint8_T)4U)

/* Exported block signals */
real32_T ACurrent_Sample;              /* '<Root>/ACurrent_Sample' */
real32_T BCurrent_Sample;              /* '<Root>/BCurrent_Sample' */
real32_T CCurrent_Sample;              /* '<Root>/CCurrent_Sample' */
int32_T Ecode_cnt;                     /* '<Root>/Ecode_cnt' */
int16_T MotorSpdRef;                   /* '<Root>/MotorSpdRef' */
real32_T VBus_Sample;                  /* '<Root>/VBus_Sample' */
real32_T UVoltage_PWM;                 /* '<S3>/Saturation' */
real32_T VVoltage_PWM;                 /* '<S3>/Saturation1' */
real32_T WVoltage_PWM;                 /* '<S3>/Saturation2' */
real32_T DAixCurrent;                  /* '<S18>/Add' */
real32_T QAixCurrent;                  /* '<S18>/Add1' */
real32_T Thetae_Est;                   /* '<S20>/Switch1' */
real32_T DAixCurrent_Ref;              /* '<S6>/Constant' */
real32_T MotorActSpd_Encode;           /* '<S338>/Add1' */
real32_T MotorActSpd_Est;              /* '<S339>/Add1' */
real32_T MotorActSpd;                  /* '<S332>/Switch' */
real32_T QAixCurrent_Ref;              /* '<S341>/Switch2' */
boolean_T SD_MosCtr;                   /* '<S3>/Merge' */

/* Exported block parameters */
real32_T MC_DCurrLopKi_CFG = 0.00829375815F;/* Variable: MC_DCurrLopKi_CFG
                                             * Referenced by: '<S14>/Constant1'
                                             */
real32_T MC_DCurrLopKp_CFG = 0.0870848F;/* Variable: MC_DCurrLopKp_CFG
                                         * Referenced by: '<S14>/Constant'
                                         */
real32_T MC_QCurrLopKi_CFG = 0.00829375815F;/* Variable: MC_QCurrLopKi_CFG
                                             * Referenced by: '<S14>/Constant3'
                                             */
real32_T MC_QCurrLopKp_CFG = 0.0870848F;/* Variable: MC_QCurrLopKp_CFG
                                         * Referenced by: '<S14>/Constant2'
                                         */
real32_T MC_SpdLopKi_CFG = 1.0E-5F;    /* Variable: MC_SpdLopKi_CFG
                                        * Referenced by: '<S333>/Constant3'
                                        */
real32_T MC_SpdLopKp_CFG = 0.002F;     /* Variable: MC_SpdLopKp_CFG
                                        * Referenced by: '<S333>/Constant2'
                                        */
boolean_T OpenLoopEn_CFG = false;      /* Variable: OpenLoopEn_CFG
                                        * Referenced by: '<S331>/Constant2'
                                        */
boolean_T SensorLessEn_CFG = false;    /* Variable: SensorLessEn_CFG
                                        * Referenced by:
                                        *   '<S331>/Constant1'
                                        *   '<S332>/Constant5'
                                        *   '<S15>/Constant3'
                                        *   '<S20>/Constant1'
                                        *   '<S20>/Constant3'
                                        *   '<S150>/Constant6'
                                        *   '<S207>/Constant6'
                                        *   '<S266>/Constant6'
                                        */
uint8_T MC_MotModeDebug_CFG = 255U;    /* Variable: MC_MotModeDebug_CFG
                                        * Referenced by: '<S331>/Constant'
                                        */
uint8_T MC_POLE_NUM_CFG = 7U;          /* Variable: MC_POLE_NUM_CFG
                                        * Referenced by:
                                        *   '<S10>/Constant'
                                        *   '<S11>/Constant'
                                        */
uint8_T SensorLessType_CFG = 0U;       /* Variable: SensorLessType_CFG
                                        * Referenced by: '<S20>/Constant'
                                        */

/* Block signals (default storage) */
B_PMSM_MC_2025a_T PMSM_MC_2025a_B;

/* Block states (default storage) */
DW_PMSM_MC_2025a_T PMSM_MC_2025a_DW;

/* Real-time model */
static RT_MODEL_PMSM_MC_2025a_T PMSM_MC_2025a_M_;
RT_MODEL_PMSM_MC_2025a_T *const PMSM_MC_2025a_M = &PMSM_MC_2025a_M_;

/* Temporary sensorless handover diagnostic: hold the pre-handover q-current
 * reference while mode 5 is first entered. 4000 high-rate ticks = 200 ms. */
static uint16_T PMSM_MC_2025a_Mode5HoldTicks;
static real32_T PMSM_MC_2025a_Mode5IqHold;
static boolean_T PMSM_MC_2025a_Mode5HoldActive;
static boolean_T PMSM_MC_2025a_Mode5Seen;

/* Forward declaration for local functions */
static void PMSM_MC_2025a_RangeCheck(void);
static void PMSM_MC_2025a_Ramping(real_T in, real_T MaxStep);
static void PMSM_MC_2025a_OLThetaeSum(void);
static void PMSM_MC_2025a_enter_atomic_Stop(void);
static void PMSM_MC_2025a_WeightedTransmite(const real32_T *Switch);
static void PMSM_MC_2025a_OLStableCntSum(const real32_T *Divide);
void sMultiWordShl(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T y[],
                   int32_T n)
{
  int32_T i;
  int32_T nb;
  int32_T nc;
  uint32_T u1i;
  uint32_T ys;
  nb = (int32_T)(n2 >> 5);
  ys = (u1[n1 - 1] & 2147483648U) != 0U ? MAX_uint32_T : 0U;
  nc = nb > n ? n : nb;
  u1i = 0U;
  for (i = 0; i < nc; i++) {
    y[i] = 0U;
  }

  if (nb < n) {
    uint32_T nl;
    nl = n2 - ((uint32_T)nb << 5);
    nb += n1;
    if (nb > n) {
      nb = n;
    }

    nb -= i;
    if (nl > 0U) {
      for (nc = 0; nc < nb; nc++) {
        uint32_T yi;
        yi = u1i >> (32U - nl);
        u1i = u1[nc];
        y[i] = u1i << nl | yi;
        i++;
      }

      if (i < n) {
        y[i] = u1i >> (32U - nl) | ys << nl;
        i++;
      }
    } else {
      for (nc = 0; nc < nb; nc++) {
        y[i] = u1[nc];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = ys;
    i++;
  }
}

void sLong2MultiWord(int32_T u, uint32_T y[], int32_T n)
{
  int32_T i;
  uint32_T yi;
  y[0] = (uint32_T)u;
  yi = u < 0 ? MAX_uint32_T : 0U;
  for (i = 1; i < n; i++) {
    y[i] = yi;
  }
}

void sMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[], int32_T
                   n2, uint32_T y[], int32_T n)
{
  int32_T i;
  int32_T j;
  int32_T k;
  uint32_T cb;
  uint32_T cb1;
  uint32_T yk;
  boolean_T isNegative1;
  boolean_T isNegative2;
  isNegative1 = ((u1[n1 - 1] & 2147483648U) != 0U);
  isNegative2 = ((u2[n2 - 1] & 2147483648U) != 0U);
  cb1 = 1U;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0U;
  }

  for (i = 0; i < n1; i++) {
    int32_T ni;
    uint32_T a0;
    uint32_T a1;
    uint32_T cb2;
    uint32_T u1i;
    cb = 0U;
    u1i = u1[i];
    if (isNegative1) {
      u1i = ~u1i + cb1;
      cb1 = (uint32_T)(u1i < cb1);
    }

    a1 = u1i >> 16U;
    a0 = u1i & 65535U;
    cb2 = 1U;
    ni = n - i;
    ni = n2 <= ni ? n2 : ni;
    k = i;
    for (j = 0; j < ni; j++) {
      uint32_T b1;
      uint32_T w01;
      uint32_T w10;
      u1i = u2[j];
      if (isNegative2) {
        u1i = ~u1i + cb2;
        cb2 = (uint32_T)(u1i < cb2);
      }

      b1 = u1i >> 16U;
      u1i &= 65535U;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk = y[k] + cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }

  /* Apply sign */
  if (isNegative1 != isNegative2) {
    cb = 1U;
    for (k = 0; k < n; k++) {
      yk = ~y[k] + cb;
      y[k] = yk;
      cb = (uint32_T)(yk < cb);
    }
  }
}

real32_T sMultiWord2Single(const uint32_T u1[], int32_T n1, int32_T e1)
{
  int32_T exp_0;
  int32_T i;
  real32_T y;
  y = 0.0F;
  exp_0 = e1;
  if ((u1[n1 - 1] & 2147483648U) != 0U) {
    uint32_T cb;
    cb = 1U;
    for (i = 0; i < n1; i++) {
      uint32_T u1i;
      u1i = ~u1[i];
      cb += u1i;
      y -= (real32_T)ldexp((real32_T)cb, exp_0);
      cb = (uint32_T)(cb < u1i);
      exp_0 += 32;
    }
  } else {
    for (i = 0; i < n1; i++) {
      y += (real32_T)ldexp((real32_T)u1[i], exp_0);
      exp_0 += 32;
    }
  }

  return y;
}

int32_T MultiWord2sLong(const uint32_T u[])
{
  return (int32_T)u[0];
}

void sMultiWordShr(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T y[],
                   int32_T n)
{
  int32_T i;
  int32_T i1;
  int32_T nb;
  uint32_T ys;
  nb = (int32_T)(n2 >> 5);
  i = 0;
  ys = (u1[n1 - 1] & 2147483648U) != 0U ? MAX_uint32_T : 0U;
  if (nb < n1) {
    int32_T nc;
    uint32_T nr;
    nc = n + nb;
    if (nc > n1) {
      nc = n1;
    }

    nr = n2 - ((uint32_T)nb << 5);
    if (nr > 0U) {
      uint32_T u1i;
      u1i = u1[nb];
      for (i1 = nb + 1; i1 < nc; i1++) {
        uint32_T yi;
        yi = u1i >> nr;
        u1i = u1[i1];
        y[i] = u1i << (32U - nr) | yi;
        i++;
      }

      y[i] = (nc < n1 ? u1[nc] : ys) << (32U - nr) | u1i >> nr;
      i++;
    } else {
      for (i1 = nb; i1 < nc; i1++) {
        y[i] = u1[i1];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = ys;
    i++;
  }
}

int32_T div_s32_floor(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  if (denominator == 0) {
    quotient = numerator >= 0 ? MAX_int32_T : MIN_int32_T;

    /* Divide by zero handler */
  } else {
    uint32_T absDenominator;
    uint32_T absNumerator;
    uint32_T tempAbsQuotient;
    boolean_T quotientNeedsNegation;
    absNumerator = numerator < 0 ? ~(uint32_T)/*MW:OvOk*/ numerator + 1U :
      (uint32_T)numerator;
    absDenominator = denominator < 0 ? ~(uint32_T)/*MW:OvOk*/ denominator + 1U :
      (uint32_T)denominator;
    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }
    }

    quotient = quotientNeedsNegation ? -/*MW:OvOk*/ ((int32_T)tempAbsQuotient) :
      (int32_T)tempAbsQuotient;
  }

  return quotient;
}

/* Function for Chart: '<S331>/ModeMgr' */
static void PMSM_MC_2025a_RangeCheck(void)
{
  int32_T qY;
  if ((PMSM_MC_2025a_DW.MotOffsetBuff[0] >= 0) &&
      (PMSM_MC_2025a_DW.MotOffsetBuff[1] < PMSM_MC_2025a_DW.MotOffsetBuff[0] -
       MAX_int32_T)) {
    qY = MAX_int32_T;
  } else if ((PMSM_MC_2025a_DW.MotOffsetBuff[0] < 0) &&
             (PMSM_MC_2025a_DW.MotOffsetBuff[1] >
              PMSM_MC_2025a_DW.MotOffsetBuff[0] - MIN_int32_T)) {
    qY = MIN_int32_T;
  } else {
    qY = PMSM_MC_2025a_DW.MotOffsetBuff[0] - PMSM_MC_2025a_DW.MotOffsetBuff[1];
  }

  if (qY < 0) {
    if (qY <= MIN_int32_T) {
      qY = MAX_int32_T;
    } else {
      qY = -qY;
    }
  }

  if (qY > 100) {
    PMSM_MC_2025a_DW.MotCalNormal = false;
  } else {
    PMSM_MC_2025a_DW.MotCalNormal = true;
    if ((PMSM_MC_2025a_DW.MotOffsetBuff[0] < 0) &&
        (PMSM_MC_2025a_DW.MotOffsetBuff[1] < MIN_int32_T
         - PMSM_MC_2025a_DW.MotOffsetBuff[0])) {
      qY = MIN_int32_T;
    } else if ((PMSM_MC_2025a_DW.MotOffsetBuff[0] > 0) &&
               (PMSM_MC_2025a_DW.MotOffsetBuff[1] > MAX_int32_T
                - PMSM_MC_2025a_DW.MotOffsetBuff[0])) {
      qY = MAX_int32_T;
    } else {
      qY = PMSM_MC_2025a_DW.MotOffsetBuff[0] + PMSM_MC_2025a_DW.MotOffsetBuff[1];
    }

    PMSM_MC_2025a_B.MotOffset = qY / 2;
  }
}

real32_T rt_modf_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  y = u0;
  if (u1 == 0.0F) {
    if (u0 == 0.0F) {
      y = u1;
    }
  } else if (rtIsNaNF(u0) || rtIsNaNF(u1) || rtIsInfF(u0)) {
    y = (rtNaNF);
  } else if (u0 == 0.0F) {
    y = 0.0F / u1;
  } else if (rtIsInfF(u1)) {
    if ((u1 < 0.0F) != (u0 < 0.0F)) {
      y = u1;
    }
  } else {
    boolean_T yEq;
    y = fmodf(u0, u1);
    yEq = (y == 0.0F);
    if ((!yEq) && (u1 > floorf(u1))) {
      real32_T q;
      q = fabsf(u0 / u1);
      yEq = !(fabsf(q - floorf(q + 0.5F)) > FLT_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0F;
    } else if ((u0 < 0.0F) != (u1 < 0.0F)) {
      y += u1;
    }
  }

  return y;
}

/* Function for Chart: '<S7>/OpenLopThetaeCal' */
static void PMSM_MC_2025a_Ramping(real_T in, real_T MaxStep)
{
  real_T tmp;
  tmp = in - PMSM_MC_2025a_DW.WeRefRamped;
  if (tmp > MaxStep) {
    PMSM_MC_2025a_DW.WeRefRamped = (real32_T)(PMSM_MC_2025a_DW.WeRefRamped +
      MaxStep);
  } else if (tmp < -MaxStep) {
    PMSM_MC_2025a_DW.WeRefRamped = (real32_T)(PMSM_MC_2025a_DW.WeRefRamped -
      MaxStep);
  } else {
    PMSM_MC_2025a_DW.WeRefRamped = (real32_T)in;
  }
}

/* Function for Chart: '<S7>/OpenLopThetaeCal' */
static void PMSM_MC_2025a_OLThetaeSum(void)
{
  /* Inport: '<Root>/MotorSpdRef' */
  if ((MotorSpdRef > 0) || (PMSM_MC_2025a_B.Switch_m == 8)) {
    /* Constant: '<S7>/Ts' */
    PMSM_MC_2025a_DW.Thetae_OL += PMSM_MC_2025a_DW.WeRefRamped * 5.0E-5F;
  } else {
    /* Constant: '<S7>/Ts' */
    PMSM_MC_2025a_DW.Thetae_OL -= PMSM_MC_2025a_DW.WeRefRamped * 5.0E-5F;
  }

  /* End of Inport: '<Root>/MotorSpdRef' */
  if (PMSM_MC_2025a_DW.Thetae_OL < 0.0F) {
    /* set range to [0 2pi] */
    PMSM_MC_2025a_DW.Thetae_OL = -PMSM_MC_2025a_DW.Thetae_OL;
    PMSM_MC_2025a_DW.Thetae_OL = fmodf(PMSM_MC_2025a_DW.Thetae_OL, 6.28F);
    PMSM_MC_2025a_DW.Thetae_OL = 6.28F - PMSM_MC_2025a_DW.Thetae_OL;
  } else {
    /* set range to [0 2pi] */
    PMSM_MC_2025a_DW.Thetae_OL = fmodf(PMSM_MC_2025a_DW.Thetae_OL, 6.28F);
  }
}

/* Function for Chart: '<S7>/OpenLopThetaeCal' */
static void PMSM_MC_2025a_enter_atomic_Stop(void)
{
  /* init output */
  PMSM_MC_2025a_B.Thetae_SensLess = 0.0F;
  PMSM_MC_2025a_B.OLStartCompletedFlag = false;
  PMSM_MC_2025a_B.TransmActiveFlag = false;

  /* init local variable */
  PMSM_MC_2025a_DW.WeRefRamped = 0.0F;
  PMSM_MC_2025a_DW.OLStableCnt = 0U;
  PMSM_MC_2025a_DW.TransmFactor = 0.0F;
  PMSM_MC_2025a_DW.Thetae_OL = 0.0F;
  PMSM_MC_2025a_DW.PhaseOffset = 0.0F;
}

/* Function for Chart: '<S7>/OpenLopThetaeCal' */
static void PMSM_MC_2025a_WeightedTransmite(const real32_T *Switch)
{
  real32_T RawNow;

  /* update factor each sw cycle
     TransmFactor = TransmFactor+TransmStep;
     open loop angle calculate */
  PMSM_MC_2025a_Ramping((real_T)PMSM_MC_2025a_ConstB.Gain, (real_T)
                        PMSM_MC_2025a_ConstB.Gain1);
  PMSM_MC_2025a_OLThetaeSum();
  RawNow = *Switch - PMSM_MC_2025a_DW.Thetae_OL;
  if (RawNow > 3.1415927F) {
    RawNow -= 6.2831855F;
  }

  if (RawNow < -3.14159274F) {
    RawNow += 6.2831855F;
  }

  RawNow -= PMSM_MC_2025a_DW.PhaseOffset;
  if (RawNow > 3.1415927F) {
    RawNow -= 6.2831855F;
  }

  if (RawNow < -3.14159274F) {
    RawNow += 6.2831855F;
  }

  RawNow *= 0.002f;
  if (RawNow > 0.002F) {
    RawNow = 0.002F;
  }

  if (RawNow < -0.002F) {
    RawNow = -0.002F;
  }

  /* 计算最新相位偏差 */
  PMSM_MC_2025a_DW.PhaseOffset += RawNow;
  if (PMSM_MC_2025a_DW.PhaseOffset > 3.1415927F) {
    PMSM_MC_2025a_DW.PhaseOffset -= 6.2831855F;
  }

  if (PMSM_MC_2025a_DW.PhaseOffset < -3.14159274F) {
    PMSM_MC_2025a_DW.PhaseOffset += 6.2831855F;
  }

  /* 计算一下输出的无感模式电角度,要求观测器稳定收敛，
     根据权重系数补偿相位差，慢慢从开环角度切换到闭环观测器角度 */
  PMSM_MC_2025a_B.Thetae_SensLess = PMSM_MC_2025a_DW.Thetae_OL +
    PMSM_MC_2025a_DW.PhaseOffset;
  if (PMSM_MC_2025a_B.Thetae_SensLess < 0.0F) {
    /* limit to [-PI,PI] */
    PMSM_MC_2025a_B.Thetae_SensLess = -PMSM_MC_2025a_B.Thetae_SensLess;
    PMSM_MC_2025a_B.Thetae_SensLess = fmodf(PMSM_MC_2025a_B.Thetae_SensLess,
      6.28F);
    PMSM_MC_2025a_B.Thetae_SensLess = 6.28F - PMSM_MC_2025a_B.Thetae_SensLess;
  }

  PMSM_MC_2025a_B.Thetae_SensLess = fmodf(PMSM_MC_2025a_B.Thetae_SensLess, 6.28F);
  RawNow = *Switch - PMSM_MC_2025a_B.Thetae_SensLess;
  if (RawNow > 3.1415927F) {
    RawNow -= 6.2831855F;
  }

  if (RawNow < -3.14159274F) {
    RawNow += 6.2831855F;
  }

  if ((RawNow < 0.25F) && (RawNow > -0.25F)) {
    /* limit to [0,1] */
    PMSM_MC_2025a_DW.TransmFactor++;
  } else {
    PMSM_MC_2025a_DW.TransmFactor = 0.0F;
  }

  if (PMSM_MC_2025a_DW.TransmFactor > 2000.0F) {
    /* 开环切闭环完成 */
    PMSM_MC_2025a_B.OLStartCompletedFlag = true;
  }
}

/* Function for Chart: '<S7>/OpenLopThetaeCal' */
static void PMSM_MC_2025a_OLStableCntSum(const real32_T *Divide)
{
  /* Inport: '<Root>/MotorSpdRef' */
  if (((MotorSpdRef > 0) && (*Divide > PMSM_MC_2025a_ConstB.Gain2)) ||
      ((MotorSpdRef < 0) && (*Divide < -PMSM_MC_2025a_ConstB.Gain2))) {
    int32_T tmp;
    tmp = PMSM_MC_2025a_DW.OLStableCnt + 1;
    if (PMSM_MC_2025a_DW.OLStableCnt + 1 > 65535) {
      tmp = 65535;
    }

    PMSM_MC_2025a_DW.OLStableCnt = (uint16_T)tmp;
  } else {
    PMSM_MC_2025a_DW.OLStableCnt = 0U;
  }

  /* End of Inport: '<Root>/MotorSpdRef' */
}

/* Model step function */
void PMSM_MC_2025a_step(void)
{
  int64m_T rtb_Switch1;
  int64m_T tmp;
  int64m_T tmp_1;
  int32_T rtb_Minus_p;
  int32_T rtb_Sign_a;
  real32_T Switch;
  real32_T rtb_Add6;
  real32_T rtb_Integrator_g;
  real32_T rtb_Product_cc;
  real32_T rtb_Sum_j;
  real32_T rtb_Sum_la;
  real32_T rtb_err_g;
  uint32_T elapsedTicks_p;
  uint32_T tmp_0;
  int16_T tmp_2;
  uint8_T rtb_Switch_hz;
  boolean_T rtb_LogicalOperator;
  if (PMSM_MC_2025a_DW.counter % 20U == 19U) {
    /* Outputs for Function Call SubSystem: '<S1>/MC_LowFrqTask' */
    /* Chart: '<S331>/ModeMgr' incorporates:
     *  Constant: '<S331>/Constant1'
     *  Constant: '<S331>/Constant2'
     *  Inport: '<Root>/Ecode_cnt'
     *  Inport: '<Root>/MotorSpdRef'
     */
    elapsedTicks_p = PMSM_MC_2025a_M->Timing.clockTick0 -
      PMSM_MC_2025a_DW.previousTicks_h;
    PMSM_MC_2025a_DW.previousTicks_h = PMSM_MC_2025a_M->Timing.clockTick0;
    elapsedTicks_p += PMSM_MC_2025a_DW.temporalCounter_i1_j;
    if (elapsedTicks_p <= 65535U) {
      PMSM_MC_2025a_DW.temporalCounter_i1_j = (uint16_T)elapsedTicks_p;
    } else {
      PMSM_MC_2025a_DW.temporalCounter_i1_j = MAX_uint16_T;
    }

    if (PMSM_MC_2025a_DW.is_active_c1_PMSM_MC_2025a == 0) {
      PMSM_MC_2025a_DW.is_active_c1_PMSM_MC_2025a = 1U;
      PMSM_MC_2025a_DW.is_c1_PMSM_MC_2025a = PMSM_MC_2025a_IN_SensorCtr;
      PMSM_MC_2025a_DW.is_SensorCtr = PMSM_MC_2025a_IN_Calibrate;
      PMSM_MC_2025a_DW.is_Calibrate = PMSM_MC_2025a_IN_Init;
      PMSM_MC_2025a_B.Switch_m = 0U;
    } else {
      switch (PMSM_MC_2025a_DW.is_c1_PMSM_MC_2025a) {
       case PMSM_MC_2025a_IN_SensorCtr:
        /* value is 1 mean sensorless control */
        if (SensorLessEn_CFG && (MotorSpdRef != 0)) {
          PMSM_MC_2025a_DW.is_Calibrate = PMSM_MC_2025_IN_NO_ACTIVE_CHILD;
          PMSM_MC_2025a_DW.is_Normal = PMSM_MC_2025_IN_NO_ACTIVE_CHILD;
          PMSM_MC_2025a_DW.is_SensorCtr = PMSM_MC_2025_IN_NO_ACTIVE_CHILD;
          PMSM_MC_2025a_DW.is_c1_PMSM_MC_2025a = PMSM_MC_2025a_IN_SensorLessCtr;
          PMSM_MC_2025a_DW.is_SensorLessCtr = PMSM_MC_2025a_IN_Stop_e;
          PMSM_MC_2025a_B.Switch_m = 4U;
        } else if (OpenLoopEn_CFG && (MotorSpdRef != 0)) {
          PMSM_MC_2025a_DW.is_Calibrate = PMSM_MC_2025_IN_NO_ACTIVE_CHILD;
          PMSM_MC_2025a_DW.is_Normal = PMSM_MC_2025_IN_NO_ACTIVE_CHILD;
          PMSM_MC_2025a_DW.is_SensorCtr = PMSM_MC_2025_IN_NO_ACTIVE_CHILD;
          PMSM_MC_2025a_DW.is_c1_PMSM_MC_2025a = PMSM_MC_2025a_IN_VFOpenLoop;
          PMSM_MC_2025a_B.Switch_m = 8U;
        } else {
          switch (PMSM_MC_2025a_DW.is_SensorCtr) {
           case PMSM_MC_2025a_IN_CalFailed:
            PMSM_MC_2025a_B.Switch_m = 3U;
            if (MotorSpdRef == 0) {
              PMSM_MC_2025a_DW.is_SensorCtr = PMSM_MC_2025a_IN_Calibrate;
              PMSM_MC_2025a_DW.is_Calibrate = PMSM_MC_2025a_IN_Init;
              PMSM_MC_2025a_B.Switch_m = 0U;
            }
            break;

           case PMSM_MC_2025a_IN_Calibrate:
            switch (PMSM_MC_2025a_DW.is_Calibrate) {
             case PMSM_MC_2025a_IN_Calibrate1:
              PMSM_MC_2025a_B.Switch_m = 1U;
              PMSM_MC_2025a_B.MotCalThetae = 0.0F;
              if (PMSM_MC_2025a_DW.temporalCounter_i1_j >= 30000) {
                PMSM_MC_2025a_DW.temporalCounter_i1_j = 0U;
                PMSM_MC_2025a_DW.is_Calibrate = PMSM_MC_2025a_IN_Calibrate2;
                PMSM_MC_2025a_DW.MotOffsetBuff[0] = Ecode_cnt;
                PMSM_MC_2025a_B.Switch_m = 2U;

                /* 0° */
              }
              break;

             case PMSM_MC_2025a_IN_Calibrate2:
              PMSM_MC_2025a_B.Switch_m = 2U;
              PMSM_MC_2025a_B.MotCalThetae = 0.0F;
              if (PMSM_MC_2025a_DW.temporalCounter_i1_j >= 30000) {
                PMSM_MC_2025a_DW.is_Calibrate = PMSM_MC_2025a_IN_RngChk;
                PMSM_MC_2025a_DW.MotOffsetBuff[1] = Ecode_cnt;
                PMSM_MC_2025a_RangeCheck();
              }
              break;

             case PMSM_MC_2025a_IN_Init:
              PMSM_MC_2025a_B.Switch_m = 0U;
              if (MotorSpdRef != 0) {
                PMSM_MC_2025a_DW.temporalCounter_i1_j = 0U;
                PMSM_MC_2025a_DW.is_Calibrate = PMSM_MC_2025a_IN_Calibrate1;
                PMSM_MC_2025a_B.Switch_m = 1U;
                PMSM_MC_2025a_B.MotCalThetae = 0.0F;

                /* 0° */
              }
              break;

             default:
              /* case IN_RngChk: */
              if (!PMSM_MC_2025a_DW.MotCalNormal) {
                PMSM_MC_2025a_DW.is_Calibrate = PMSM_MC_2025_IN_NO_ACTIVE_CHILD;
                PMSM_MC_2025a_DW.is_SensorCtr = PMSM_MC_2025a_IN_CalFailed;
                PMSM_MC_2025a_B.Switch_m = 3U;
              } else {
                PMSM_MC_2025a_DW.is_Calibrate = PMSM_MC_2025_IN_NO_ACTIVE_CHILD;
                PMSM_MC_2025a_DW.is_SensorCtr = PMSM_MC_2025a_IN_Normal;
                PMSM_MC_2025a_DW.is_Normal = PMSM_MC_2025a_IN_Stop;
                PMSM_MC_2025a_B.Switch_m = 4U;
              }
              break;
            }
            break;

           default:
            /* case IN_Normal: */
            if (PMSM_MC_2025a_DW.is_Normal == PMSM_MC_2025a_IN_Run) {
              PMSM_MC_2025a_B.Switch_m = 5U;
              if (MotorSpdRef == 0) {
                PMSM_MC_2025a_DW.is_Normal = PMSM_MC_2025a_IN_Stop;
                PMSM_MC_2025a_B.Switch_m = 4U;
              }
            } else {
              /* case IN_Stop: */
              PMSM_MC_2025a_B.Switch_m = 4U;
              if (MotorSpdRef != 0) {
                PMSM_MC_2025a_DW.is_Normal = PMSM_MC_2025a_IN_Run;
                PMSM_MC_2025a_B.Switch_m = 5U;
              }
            }
            break;
          }
        }
        break;

       case PMSM_MC_2025a_IN_SensorLessCtr:
        /* value is 0 mean sensor control */
        if ((!SensorLessEn_CFG) && (MotorSpdRef != 0)) {
          PMSM_MC_2025a_DW.is_SensorLessCtr = PMSM_MC_2025_IN_NO_ACTIVE_CHILD;
          PMSM_MC_2025a_DW.is_c1_PMSM_MC_2025a = PMSM_MC_2025a_IN_SensorCtr;
          PMSM_MC_2025a_DW.is_SensorCtr = PMSM_MC_2025a_IN_Calibrate;
          PMSM_MC_2025a_DW.is_Calibrate = PMSM_MC_2025a_IN_Init;
          PMSM_MC_2025a_B.Switch_m = 0U;
        } else if (OpenLoopEn_CFG && (MotorSpdRef != 0)) {
          PMSM_MC_2025a_DW.is_SensorLessCtr = PMSM_MC_2025_IN_NO_ACTIVE_CHILD;
          PMSM_MC_2025a_DW.is_c1_PMSM_MC_2025a = PMSM_MC_2025a_IN_VFOpenLoop;
          PMSM_MC_2025a_B.Switch_m = 8U;
        } else {
          switch (PMSM_MC_2025a_DW.is_SensorLessCtr) {
           case PMSM_MC_2025a_IN_IFStart:
            PMSM_MC_2025a_B.Switch_m = 7U;
            if (PMSM_MC_2025a_B.OLStartCompletedFlag) {
              PMSM_MC_2025a_DW.is_SensorLessCtr = PMSM_MC_2025a_IN_Run_i;
              PMSM_MC_2025a_B.Switch_m = 5U;
            } else if (PMSM_MC_2025a_DW.temporalCounter_i1_j >= 40000) {
              PMSM_MC_2025a_DW.is_SensorLessCtr = PMSM_MC_2025a_IN_StartFail;
              PMSM_MC_2025a_B.Switch_m = 6U;
            }
            break;

           case PMSM_MC_2025a_IN_Run_i:
            PMSM_MC_2025a_B.Switch_m = 5U;
            if (MotorSpdRef == 0) {
              PMSM_MC_2025a_DW.is_SensorLessCtr = PMSM_MC_2025a_IN_Stop_e;
              PMSM_MC_2025a_B.Switch_m = 4U;
            }
            break;

           case PMSM_MC_2025a_IN_StartFail:
            PMSM_MC_2025a_B.Switch_m = 6U;
            if (MotorSpdRef == 0) {
              PMSM_MC_2025a_DW.is_SensorLessCtr = PMSM_MC_2025a_IN_Stop_e;
              PMSM_MC_2025a_B.Switch_m = 4U;
            }
            break;

           default:
            /* case IN_Stop: */
            PMSM_MC_2025a_B.Switch_m = 4U;
            if (MotorSpdRef != 0) {
              PMSM_MC_2025a_DW.temporalCounter_i1_j = 0U;
              PMSM_MC_2025a_DW.is_SensorLessCtr = PMSM_MC_2025a_IN_IFStart;
              PMSM_MC_2025a_B.Switch_m = 7U;
            }
            break;
          }
        }
        break;

       default:
        /* case IN_VFOpenLoop: */
        PMSM_MC_2025a_B.Switch_m = 8U;
        rtb_LogicalOperator = ((!OpenLoopEn_CFG) && (MotorSpdRef != 0));
        if (rtb_LogicalOperator && SensorLessEn_CFG) {
          PMSM_MC_2025a_DW.is_c1_PMSM_MC_2025a = PMSM_MC_2025a_IN_SensorLessCtr;
          PMSM_MC_2025a_DW.is_SensorLessCtr = PMSM_MC_2025a_IN_Stop_e;
          PMSM_MC_2025a_B.Switch_m = 4U;
        } else if (rtb_LogicalOperator && (!SensorLessEn_CFG)) {
          PMSM_MC_2025a_DW.is_c1_PMSM_MC_2025a = PMSM_MC_2025a_IN_SensorCtr;
          PMSM_MC_2025a_DW.is_SensorCtr = PMSM_MC_2025a_IN_Calibrate;
          PMSM_MC_2025a_DW.is_Calibrate = PMSM_MC_2025a_IN_Init;
          PMSM_MC_2025a_B.Switch_m = 0U;
        }
        break;
      }
    }

    /* End of Chart: '<S331>/ModeMgr' */

    /* Switch: '<S331>/Switch' incorporates:
     *  Constant: '<S331>/Constant'
     *  Constant: '<S334>/Constant'
     *  RelationalOperator: '<S334>/Compare'
     */
    if (MC_MotModeDebug_CFG != 255) {
      /* Switch: '<S331>/Switch' */
      PMSM_MC_2025a_B.Switch_m = MC_MotModeDebug_CFG;
    }

    /* End of Switch: '<S331>/Switch' */

    /* Delay: '<S332>/Delay' incorporates:
     *  Inport: '<Root>/Ecode_cnt'
     */
    if (PMSM_MC_2025a_DW.icLoad_c) {
      PMSM_MC_2025a_DW.Delay_DSTATE_h5 = Ecode_cnt;
    }

    /* Sum: '<S332>/Minus' incorporates:
     *  Delay: '<S332>/Delay'
     *  Inport: '<Root>/Ecode_cnt'
     */
    rtb_Minus_p = Ecode_cnt - PMSM_MC_2025a_DW.Delay_DSTATE_h5;

    /* Switch: '<S332>/Switch1' incorporates:
     *  Constant: '<S332>/Constant6'
     *  Constant: '<S336>/Constant'
     *  Constant: '<S337>/Constant'
     *  RelationalOperator: '<S336>/Compare'
     *  RelationalOperator: '<S337>/Compare'
     *  Sum: '<S332>/Add2'
     *  Switch: '<S332>/Switch2'
     */
    if (rtb_Minus_p < -8000) {
      sLong2MultiWord(rtb_Minus_p + 16384, &tmp.chunks[0U], 2);
      sMultiWordShl(&tmp.chunks[0U], 2, 31U, &rtb_Switch1.chunks[0U], 2);
    } else if (rtb_Minus_p > 8000) {
      /* Gain: '<S332>/Gain1' incorporates:
       *  Constant: '<S332>/Constant9'
       *  Delay: '<S332>/Delay'
       *  Inport: '<Root>/Ecode_cnt'
       *  Sum: '<S332>/Add5'
       *  Switch: '<S332>/Switch2'
       */
      elapsedTicks_p = 2147483648U;
      tmp_0 = (uint32_T)((PMSM_MC_2025a_DW.Delay_DSTATE_h5 - Ecode_cnt) + 16384);
      sMultiWordMul(&elapsedTicks_p, 1, &tmp_0, 1, &rtb_Switch1.chunks[0U], 2);
    } else {
      /* Switch: '<S332>/Switch2' */
      sLong2MultiWord(rtb_Minus_p, &tmp.chunks[0U], 2);
      sMultiWordShl(&tmp.chunks[0U], 2, 31U, &rtb_Switch1.chunks[0U], 2);
    }

    /* End of Switch: '<S332>/Switch1' */

    /* Product: '<S332>/Product' incorporates:
     *  Constant: '<S332>/Constant'
     *  Constant: '<S332>/Constant1'
     *  DataTypeConversion: '<S332>/Data Type Conversion'
     *  Product: '<S332>/Divide'
     */
    rtb_Product_cc = sMultiWord2Single(&rtb_Switch1.chunks[0U], 2, 0) *
      4.65661287E-10F / 16384.0F * 60000.0F;

    /* Delay: '<S338>/Delay' */
    if (PMSM_MC_2025a_DW.icLoad_a1) {
      PMSM_MC_2025a_DW.Delay_DSTATE_pq = rtb_Product_cc;
    }

    /* Sum: '<S338>/Add1' incorporates:
     *  Delay: '<S338>/Delay'
     *  Product: '<S338>/Product'
     *  Product: '<S338>/Product1'
     */
    MotorActSpd_Encode = PMSM_MC_2025a_ConstB.Add_k *
      PMSM_MC_2025a_DW.Delay_DSTATE_pq + rtb_Product_cc;

    /* Gain: '<S332>/Gain' incorporates:
     *  Constant: '<S332>/Constant3'
     *  Product: '<S332>/Divide1'
     */
    rtb_Product_cc = PMSM_MC_2025a_B.Switch2 / 7.0F * 9.55414F;

    /* Delay: '<S339>/Delay' */
    if (PMSM_MC_2025a_DW.icLoad_e) {
      PMSM_MC_2025a_DW.Delay_DSTATE_a = rtb_Product_cc;
    }

    /* Sum: '<S339>/Add1' incorporates:
     *  Delay: '<S339>/Delay'
     *  Product: '<S339>/Product'
     *  Product: '<S339>/Product1'
     */
    MotorActSpd_Est = PMSM_MC_2025a_ConstB.Add_iy *
      PMSM_MC_2025a_DW.Delay_DSTATE_a + rtb_Product_cc;

    /* Switch: '<S332>/Switch' incorporates:
     *  Constant: '<S332>/Constant5'
     */
    if (SensorLessEn_CFG) {
      /* Switch: '<S332>/Switch' */
      MotorActSpd = MotorActSpd_Est;
    } else {
      /* Switch: '<S332>/Switch' */
      MotorActSpd = MotorActSpd_Encode;
    }

    /* End of Switch: '<S332>/Switch' */

    /* Switch: '<S342>/Switch2' incorporates:
     *  Constant: '<S333>/Constant4'
     *  Gain: '<S333>/Gain1'
     *  Inport: '<Root>/MotorSpdRef'
     *  RelationalOperator: '<S342>/LowerRelop1'
     *  RelationalOperator: '<S342>/UpperRelop'
     *  Switch: '<S342>/Switch'
     */
    if (MotorSpdRef > 2000) {
      tmp_2 = 2000;
    } else if ((MotorSpdRef << 15) < PMSM_MC_2025a_ConstB.Gain1_g) {
      /* Switch: '<S342>/Switch' incorporates:
       *  Gain: '<S333>/Gain1'
       */
      tmp_2 = (int16_T)(PMSM_MC_2025a_ConstB.Gain1_g >> 15);
    } else {
      tmp_2 = MotorSpdRef;
    }

    /* Sum: '<S333>/Minus' incorporates:
     *  DataTypeConversion: '<S333>/Data Type Conversion'
     *  Switch: '<S342>/Switch2'
     */
    rtb_Product_cc = (real32_T)tmp_2 - MotorActSpd;

    /* Sum: '<S386>/Sum' incorporates:
     *  Constant: '<S333>/Constant2'
     *  DiscreteIntegrator: '<S377>/Integrator'
     *  Product: '<S382>/PProd Out'
     */
    QAixCurrent_Ref = rtb_Product_cc * MC_SpdLopKp_CFG +
      PMSM_MC_2025a_DW.Integrator_DSTATE_e;

    /* Switch: '<S341>/Switch2' incorporates:
     *  Constant: '<S333>/Constant1'
     *  RelationalOperator: '<S341>/LowerRelop1'
     *  RelationalOperator: '<S341>/UpperRelop'
     *  Switch: '<S341>/Switch'
     */
    if (QAixCurrent_Ref > 3.0F) {
      /* Sum: '<S386>/Sum' incorporates:
       *  Switch: '<S341>/Switch2'
       */
      QAixCurrent_Ref = 3.0F;
    } else if (QAixCurrent_Ref < PMSM_MC_2025a_ConstB.Gain_k) {
      /* Sum: '<S386>/Sum' incorporates:
       *  Switch: '<S341>/Switch'
       *  Switch: '<S341>/Switch2'
       */
      QAixCurrent_Ref = PMSM_MC_2025a_ConstB.Gain_k;
    }

    /* End of Switch: '<S341>/Switch2' */

    /* Update for Delay: '<S332>/Delay' incorporates:
     *  Inport: '<Root>/Ecode_cnt'
     */
    PMSM_MC_2025a_DW.icLoad_c = false;
    PMSM_MC_2025a_DW.Delay_DSTATE_h5 = Ecode_cnt;

    /* Update for Delay: '<S338>/Delay' */
    PMSM_MC_2025a_DW.icLoad_a1 = false;
    PMSM_MC_2025a_DW.Delay_DSTATE_pq = MotorActSpd_Encode;

    /* Update for Delay: '<S339>/Delay' */
    PMSM_MC_2025a_DW.icLoad_e = false;
    PMSM_MC_2025a_DW.Delay_DSTATE_a = MotorActSpd_Est;

    /* Update for DiscreteIntegrator: '<S377>/Integrator' incorporates:
     *  Constant: '<S333>/Constant3'
     *  Product: '<S374>/IProd Out'
     */
    if (!PMSM_MC_2025a_Mode5HoldActive) {
      PMSM_MC_2025a_DW.Integrator_DSTATE_e += rtb_Product_cc * MC_SpdLopKi_CFG;
      if (PMSM_MC_2025a_DW.Integrator_DSTATE_e > 3.0F) {
        PMSM_MC_2025a_DW.Integrator_DSTATE_e = 3.0F;
      } else if (PMSM_MC_2025a_DW.Integrator_DSTATE_e < -3.0F) {
        PMSM_MC_2025a_DW.Integrator_DSTATE_e = -3.0F;
      }
    }

    /* End of Update for DiscreteIntegrator: '<S377>/Integrator' */
    /* End of Outputs for SubSystem: '<S1>/MC_LowFrqTask' */
  }

  /* Chart: '<Root>/Scheduler' incorporates:
   *  SubSystem: '<S1>/MC_HighFrqTask'
   */
  /* Product: '<S7>/Divide' incorporates:
   *  Constant: '<S7>/Pn'
   *  Delay: '<S3>/Delay'
   */
  rtb_Product_cc = PMSM_MC_2025a_B.Switch2 / 7.0F;

  /* Switch: '<S328>/Switch' incorporates:
   *  Constant: '<S330>/Constant'
   *  Delay: '<S3>/Delay1'
   *  RelationalOperator: '<S330>/Compare'
   */
  if (Thetae_Est >= 0.0F) {
    /* Switch: '<S328>/Switch' incorporates:
     *  Constant: '<S328>/Constant'
     *  Math: '<S328>/Mod'
     */
    Switch = rt_modf_snf(Thetae_Est, 6.28F);
  } else {
    /* Switch: '<S328>/Switch' incorporates:
     *  Abs: '<S328>/Abs'
     *  Constant: '<S328>/Constant1'
     *  Constant: '<S328>/Constant2'
     *  Math: '<S328>/Mod1'
     *  Sum: '<S328>/Add'
     */
    Switch = 6.28F - rt_modf_snf(fabsf(Thetae_Est), 6.28F);
  }

  /* End of Switch: '<S328>/Switch' */

  /* Chart: '<S7>/OpenLopThetaeCal' */
  elapsedTicks_p = PMSM_MC_2025a_M->Timing.clockTick0 -
    PMSM_MC_2025a_DW.previousTicks;
  PMSM_MC_2025a_DW.previousTicks = PMSM_MC_2025a_M->Timing.clockTick0;
  elapsedTicks_p += PMSM_MC_2025a_DW.temporalCounter_i1;
  if (elapsedTicks_p <= 2047U) {
    PMSM_MC_2025a_DW.temporalCounter_i1 = (uint16_T)elapsedTicks_p;
  } else {
    PMSM_MC_2025a_DW.temporalCounter_i1 = 2047U;
  }

  if (PMSM_MC_2025a_DW.is_active_c2_PMSM_MC_2025a == 0) {
    PMSM_MC_2025a_DW.is_active_c2_PMSM_MC_2025a = 1U;
    PMSM_MC_2025a_DW.is_c2_PMSM_MC_2025a = PMSM_MC_2025a_IN_Stop_m;
    PMSM_MC_2025a_enter_atomic_Stop();
  } else {
    switch (PMSM_MC_2025a_DW.is_c2_PMSM_MC_2025a) {
     case PMSM_MC_2025a_IN_CloseLop:
      if (PMSM_MC_2025a_B.Switch_m != 5) {
        PMSM_MC_2025a_DW.is_c2_PMSM_MC_2025a = PMSM_MC_2025a_IN_Stop_m;
        PMSM_MC_2025a_enter_atomic_Stop();
      } else {
        PMSM_MC_2025a_B.Thetae_SensLess = Switch;
      }
      break;

     case PMSM_MC_2025a_IN_IFStart_k:
      if (PMSM_MC_2025a_B.OLStartCompletedFlag && (PMSM_MC_2025a_B.Switch_m == 5))
      {
        PMSM_MC_2025a_DW.is_IFStart = PMSM_MC_2025_IN_NO_ACTIVE_CHILD;
        PMSM_MC_2025a_DW.is_c2_PMSM_MC_2025a = PMSM_MC_2025a_IN_CloseLop;
        PMSM_MC_2025a_B.TransmActiveFlag = false;
        PMSM_MC_2025a_B.Thetae_SensLess = Switch;
      } else {
        switch (PMSM_MC_2025a_DW.is_IFStart) {
         case PMSM_MC_2025a_IN_Align:
          if (PMSM_MC_2025a_DW.temporalCounter_i1 >= 2000) {
            PMSM_MC_2025a_DW.is_IFStart = PMSM_MC_2025a_IN_Open;
            PMSM_MC_2025a_Ramping((real_T)PMSM_MC_2025a_ConstB.Gain, (real_T)
                                  PMSM_MC_2025a_ConstB.Gain1);
            PMSM_MC_2025a_OLThetaeSum();
            PMSM_MC_2025a_OLStableCntSum(&rtb_Product_cc);
            PMSM_MC_2025a_B.Thetae_SensLess = PMSM_MC_2025a_DW.Thetae_OL;
          }
          break;

         case PMSM_MC_2025a_IN_Open:
          if (PMSM_MC_2025a_DW.OLStableCnt > PMSM_MC_2025a_ConstB.Gain3) {
            PMSM_MC_2025a_DW.is_IFStart = PMSM_MC_2025a_IN_Transm;

            /* 相位计算与方向判断 */
            PMSM_MC_2025a_B.TransmActiveFlag = true;
            PMSM_MC_2025a_DW.PhaseOffset = 0.0F;

            /* CapturePhaseOffset();
               cal steps according time
               TransmStep = 1/(OLWeightedTransmTime*1000/50); */
            /* transmite from open to close */
            PMSM_MC_2025a_WeightedTransmite(&Switch);
          } else {
            PMSM_MC_2025a_Ramping((real_T)PMSM_MC_2025a_ConstB.Gain, (real_T)
                                  PMSM_MC_2025a_ConstB.Gain1);
            PMSM_MC_2025a_OLThetaeSum();
            PMSM_MC_2025a_OLStableCntSum(&rtb_Product_cc);
            PMSM_MC_2025a_B.Thetae_SensLess = PMSM_MC_2025a_DW.Thetae_OL;
          }
          break;

         default:
          /* case IN_Transm: */
          PMSM_MC_2025a_WeightedTransmite(&Switch);
          break;
        }
      }
      break;

     case PMSM_MC_2025a_IN_Stop_m:
      switch (PMSM_MC_2025a_B.Switch_m) {
       case 8U:
        PMSM_MC_2025a_DW.is_c2_PMSM_MC_2025a = PMSM_MC_2025a_IN_VFOpenLoop_m;
        PMSM_MC_2025a_DW.temporalCounter_i1 = 0U;
        PMSM_MC_2025a_DW.is_VFOpenLoop = PMSM_MC_2025a_IN_Align;
        PMSM_MC_2025a_B.Thetae_SensLess = 0.0F;
        break;

       case 7U:
        PMSM_MC_2025a_DW.is_c2_PMSM_MC_2025a = PMSM_MC_2025a_IN_IFStart_k;
        PMSM_MC_2025a_DW.temporalCounter_i1 = 0U;
        PMSM_MC_2025a_DW.is_IFStart = PMSM_MC_2025a_IN_Align;
        PMSM_MC_2025a_B.Thetae_SensLess = 0.0F;
        break;
      }
      break;

     default:
      /* case IN_VFOpenLoop: */
      if (PMSM_MC_2025a_B.Switch_m != 8) {
        PMSM_MC_2025a_DW.is_VFOpenLoop = PMSM_MC_2025_IN_NO_ACTIVE_CHILD;
        PMSM_MC_2025a_DW.is_c2_PMSM_MC_2025a = PMSM_MC_2025a_IN_Stop_m;
        PMSM_MC_2025a_enter_atomic_Stop();
      } else if (PMSM_MC_2025a_DW.is_VFOpenLoop == PMSM_MC_2025a_IN_Align) {
        if (PMSM_MC_2025a_DW.temporalCounter_i1 >= 2000) {
          PMSM_MC_2025a_DW.is_VFOpenLoop = PMSM_MC_2025a_IN_Open;
          PMSM_MC_2025a_Ramping((real_T)PMSM_MC_2025a_ConstB.Gain, (real_T)
                                PMSM_MC_2025a_ConstB.Gain1);
          PMSM_MC_2025a_OLThetaeSum();
          PMSM_MC_2025a_B.Thetae_SensLess = PMSM_MC_2025a_DW.Thetae_OL;
        }
      } else {
        /* case IN_Open: */
        PMSM_MC_2025a_Ramping((real_T)PMSM_MC_2025a_ConstB.Gain, (real_T)
                              PMSM_MC_2025a_ConstB.Gain1);
        PMSM_MC_2025a_OLThetaeSum();
        PMSM_MC_2025a_B.Thetae_SensLess = PMSM_MC_2025a_DW.Thetae_OL;
      }
      break;
    }
  }

  /* End of Chart: '<S7>/OpenLopThetaeCal' */

  /* Sum: '<S5>/Add' incorporates:
   *  Inport: '<Root>/Ecode_cnt'
   */
  rtb_Minus_p = Ecode_cnt - PMSM_MC_2025a_B.MotOffset;

  /* Signum: '<S9>/Sign' */
  if (rtb_Minus_p < 0) {
    rtb_Sign_a = -1;
  } else {
    rtb_Sign_a = (rtb_Minus_p > 0);
  }

  /* End of Signum: '<S9>/Sign' */

  /* If: '<S9>/If' */
  if (rtb_Sign_a == 1) {
    /* Outputs for IfAction SubSystem: '<S9>/If Action Subsystem' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* SignalConversion generated from: '<S10>/Out1' incorporates:
     *  Constant: '<S10>/Constant'
     *  Constant: '<S10>/Constant2'
     *  Constant: '<S10>/Constant3'
     *  DataTypeConversion: '<S10>/Data Type Conversion'
     *  DataTypeConversion: '<S10>/Data Type Conversion1'
     *  Math: '<S10>/Mod'
     *  Product: '<S10>/Divide'
     *  Product: '<S10>/Product'
     *  Product: '<S10>/Product1'
     */
    Switch = (real32_T)(rtb_Minus_p - (div_s32_floor(rtb_Minus_p, 16384) << 14))
      / 16384.0F * 6.28F * (real32_T)MC_POLE_NUM_CFG;

    /* End of Outputs for SubSystem: '<S9>/If Action Subsystem' */
  } else if (rtb_Sign_a == -1) {
    /* Outputs for IfAction SubSystem: '<S9>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    /* Gain: '<S11>/Gain' */
    elapsedTicks_p = 2147483648U;
    tmp_0 = (uint32_T)rtb_Minus_p;
    sMultiWordMul(&elapsedTicks_p, 1, &tmp_0, 1, &tmp_1.chunks[0U], 2);

    /* DataTypeConversion: '<S11>/Data Type Conversion3' */
    sMultiWordShr(&tmp_1.chunks[0U], 2, 31U, &tmp.chunks[0U], 2);
    rtb_Minus_p = MultiWord2sLong(&tmp.chunks[0U]);

    /* Gain: '<S11>/Gain1' incorporates:
     *  Constant: '<S11>/Constant'
     *  Constant: '<S11>/Constant2'
     *  Constant: '<S11>/Constant3'
     *  DataTypeConversion: '<S11>/Data Type Conversion'
     *  DataTypeConversion: '<S11>/Data Type Conversion1'
     *  Math: '<S11>/Mod'
     *  Product: '<S11>/Divide'
     *  Product: '<S11>/Product'
     *  Product: '<S11>/Product1'
     */
    Switch = -((real32_T)(rtb_Minus_p - (div_s32_floor(rtb_Minus_p, 16384) << 14))
               / 16384.0F * 6.28F * (real32_T)MC_POLE_NUM_CFG);

    /* End of Outputs for SubSystem: '<S9>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S9>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    /* SignalConversion generated from: '<S12>/Out1' incorporates:
     *  Constant: '<S12>/Constant1'
     */
    Switch = 0.0F;

    /* End of Outputs for SubSystem: '<S9>/If Action Subsystem2' */
  }

  /* End of If: '<S9>/If' */

  /* Outputs for IfAction SubSystem: '<S3>/FOC' incorporates:
   *  ActionPort: '<S6>/Action Port'
   */
  /* If: '<S3>/If' incorporates:
   *  Constant: '<S143>/Constant'
   *  Constant: '<S144>/Constant'
   *  Constant: '<S145>/Constant'
   *  Constant: '<S15>/Constant3'
   *  Logic: '<S15>/Logical Operator'
   *  RelationalOperator: '<S143>/Compare'
   *  RelationalOperator: '<S144>/Compare'
   *  RelationalOperator: '<S145>/Compare'
   *  Signum: '<S15>/Sign'
   *  Switch: '<S15>/Switch1'
   *  Switch: '<S15>/Switch2'
   */
  rtb_LogicalOperator = ((PMSM_MC_2025a_B.Switch_m == 1) ||
    (PMSM_MC_2025a_B.Switch_m == 2));

  /* End of Outputs for SubSystem: '<S3>/FOC' */
  if (rtb_LogicalOperator || (PMSM_MC_2025a_B.Switch_m == 5) ||
      (PMSM_MC_2025a_B.Switch_m == 7) || (PMSM_MC_2025a_B.Switch_m == 8)) {
    /* Outputs for IfAction SubSystem: '<S3>/FOC' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* Merge: '<S3>/Merge' incorporates:
     *  Constant: '<S6>/Constant1'
     *  SignalConversion generated from: '<S6>/SD_MosCtr'
     */
    SD_MosCtr = true;

    /* Sum: '<S13>/Minus' incorporates:
     *  Gain: '<S13>/Gain'
     *  Gain: '<S13>/Gain1'
     *  Inport: '<Root>/BCurrent_Sample'
     *  Inport: '<Root>/CCurrent_Sample'
     */
    rtb_Product_cc = 0.57735F * BCurrent_Sample - 0.57735F * CCurrent_Sample;

    /* Switch: '<S20>/Switch' incorporates:
     *  Constant: '<S20>/Constant'
     *  Constant: '<S20>/Constant1'
     *  Constant: '<S20>/Constant2'
     */
    if (SensorLessEn_CFG) {
      rtb_Switch_hz = SensorLessType_CFG;
    } else {
      rtb_Switch_hz = 0U;
    }

    /* End of Switch: '<S20>/Switch' */

    /* Outputs for Enabled SubSystem: '<S20>/FluxObs+PLL' incorporates:
     *  EnablePort: '<S146>/Enable'
     */
    if (rtb_Switch_hz == 2) {
      /* Sum: '<S149>/e' incorporates:
       *  Delay: '<S149>/Delay2'
       *  Delay: '<S149>/Delay3'
       *  Math: '<S149>/Math Function'
       *  Math: '<S149>/Math Function1'
       *
       * About '<S149>/Math Function':
       *  Operator: magnitude^2
       *
       * About '<S149>/Math Function1':
       *  Operator: magnitude^2
       */
      rtb_err_g = (PMSM_MC_2025a_ConstB.MathFunction2 -
                   PMSM_MC_2025a_DW.Delay2_DSTATE_f *
                   PMSM_MC_2025a_DW.Delay2_DSTATE_f) -
        PMSM_MC_2025a_DW.Delay3_DSTATE_c * PMSM_MC_2025a_DW.Delay3_DSTATE_c;

      /* Sum: '<S149>/Add5' incorporates:
       *  Constant: '<S149>/Gamma'
       *  Delay: '<S149>/Delay'
       *  Delay: '<S149>/Delay2'
       *  Delay: '<S6>/Delay'
       *  Gain: '<S149>/Rs'
       *  Gain: '<S149>/Ts'
       *  Inport: '<Root>/ACurrent_Sample'
       *  Product: '<S149>/Product'
       *  Product: '<S149>/Product2'
       *  Sum: '<S149>/Add'
       *  Sum: '<S149>/Add1'
       */
      PMSM_MC_2025a_DW.Delay_DSTATE_i += ((PMSM_MC_2025a_DW.Delay_DSTATE_j -
        0.08F * ACurrent_Sample) + PMSM_MC_2025a_DW.Delay2_DSTATE_f * rtb_err_g *
        100000.0F) * 5.0E-5F;

      /* Sum: '<S149>/Add6' incorporates:
       *  Delay: '<S149>/Delay'
       *  Gain: '<S149>/Ld'
       *  Inport: '<Root>/ACurrent_Sample'
       */
      rtb_Add6 = PMSM_MC_2025a_DW.Delay_DSTATE_i - 4.2E-5F * ACurrent_Sample;

      /* Sum: '<S149>/Add7' incorporates:
       *  Constant: '<S149>/Gamma'
       *  Delay: '<S149>/Delay1'
       *  Delay: '<S149>/Delay3'
       *  Delay: '<S6>/Delay1'
       *  Gain: '<S149>/Rs1'
       *  Gain: '<S149>/Ts1'
       *  Product: '<S149>/Product1'
       *  Product: '<S149>/Product3'
       *  Sum: '<S149>/Add3'
       *  Sum: '<S149>/Add4'
       */
      PMSM_MC_2025a_DW.Delay1_DSTATE_o += (rtb_err_g *
        PMSM_MC_2025a_DW.Delay3_DSTATE_c * 100000.0F +
        (PMSM_MC_2025a_DW.Delay1_DSTATE_k - 0.08F * rtb_Product_cc)) * 5.0E-5F;

      /* Sum: '<S149>/Add8' incorporates:
       *  Delay: '<S149>/Delay1'
       *  Delay: '<S149>/Delay3'
       *  Gain: '<S149>/Lq'
       */
      PMSM_MC_2025a_DW.Delay3_DSTATE_c = PMSM_MC_2025a_DW.Delay1_DSTATE_o -
        4.2E-5F * rtb_Product_cc;

      /* Sum: '<S150>/err' incorporates:
       *  Delay: '<S149>/Delay3'
       *  Delay: '<S150>/Delay'
       *  Product: '<S150>/Product'
       *  Product: '<S150>/Product2'
       *  Trigonometry: '<S150>/Cos'
       *  Trigonometry: '<S150>/Sin'
       */
      rtb_err_g = cosf(PMSM_MC_2025a_DW.Delay_DSTATE_p) *
        PMSM_MC_2025a_DW.Delay3_DSTATE_c - sinf(PMSM_MC_2025a_DW.Delay_DSTATE_p)
        * rtb_Add6;

      /* DiscreteIntegrator: '<S188>/Integrator' incorporates:
       *  Constant: '<S150>/Constant6'
       *  RelationalOperator: '<S151>/Compare'
       */
      if (SensorLessEn_CFG && (PMSM_MC_2025a_DW.Integrator_PrevResetState_cx <=
           0)) {
        PMSM_MC_2025a_DW.Integrator_DSTATE_l = 0.0F;
      }

      /* Sum: '<S197>/Sum' incorporates:
       *  Constant: '<S150>/Constant'
       *  DiscreteIntegrator: '<S188>/Integrator'
       *  Product: '<S193>/PProd Out'
       */
      rtb_Sum_j = rtb_err_g * 52000.0F + PMSM_MC_2025a_DW.Integrator_DSTATE_l;

      /* Sum: '<S150>/Add' incorporates:
       *  Delay: '<S149>/Delay2'
       *  Delay: '<S150>/Delay'
       *  Gain: '<S150>/Gain'
       */
      PMSM_MC_2025a_DW.Delay2_DSTATE_f = 5.0E-5F * rtb_Sum_j +
        PMSM_MC_2025a_DW.Delay_DSTATE_p;

      /* Math: '<S150>/Mod' incorporates:
       *  Constant: '<S150>/Constant5'
       *  Delay: '<S149>/Delay2'
       *  Delay: '<S150>/Delay'
       */
      PMSM_MC_2025a_DW.Delay_DSTATE_p = rt_modf_snf
        (PMSM_MC_2025a_DW.Delay2_DSTATE_f, 6.28318548F);

      /* Merge: '<S20>/Merge' incorporates:
       *  Delay: '<S150>/Delay'
       *  SignalConversion generated from: '<S146>/Thetae_Est'
       */
      PMSM_MC_2025a_B.Merge = PMSM_MC_2025a_DW.Delay_DSTATE_p;

      /* Delay: '<S152>/Delay' */
      if (PMSM_MC_2025a_DW.icLoad_m) {
        PMSM_MC_2025a_DW.Delay_DSTATE_e = rtb_Sum_j;
      }

      /* Sum: '<S152>/Add1' incorporates:
       *  Constant: '<S150>/Constant1'
       *  Delay: '<S152>/Delay'
       *  Product: '<S152>/Product'
       *  Product: '<S152>/Product1'
       */
      PMSM_MC_2025a_B.Merge1 = rtb_Sum_j * 0.0085F + PMSM_MC_2025a_ConstB.Add_f5
        * PMSM_MC_2025a_DW.Delay_DSTATE_e;

      /* Update for Delay: '<S149>/Delay2' */
      PMSM_MC_2025a_DW.Delay2_DSTATE_f = rtb_Add6;

      /* Update for DiscreteIntegrator: '<S188>/Integrator' incorporates:
       *  Constant: '<S150>/Constant4'
       *  Constant: '<S150>/Constant6'
       *  Product: '<S185>/IProd Out'
       *  RelationalOperator: '<S151>/Compare'
       */
      PMSM_MC_2025a_DW.Integrator_DSTATE_l += rtb_err_g * 40.0F;
      PMSM_MC_2025a_DW.Integrator_PrevResetState_cx = (int8_T)SensorLessEn_CFG;

      /* Update for Delay: '<S152>/Delay' */
      PMSM_MC_2025a_DW.icLoad_m = false;
      PMSM_MC_2025a_DW.Delay_DSTATE_e = PMSM_MC_2025a_B.Merge1;
    }

    /* End of Outputs for SubSystem: '<S20>/FluxObs+PLL' */

    /* Outputs for Enabled SubSystem: '<S20>/Luenberger+PLL' incorporates:
     *  EnablePort: '<S147>/Enable'
     */
    if (rtb_Switch_hz == 3) {
      /* Gain: '<S206>/Ts3' incorporates:
       *  Delay: '<S147>/Delay'
       */
      rtb_Integrator_g = 5.0E-5F * PMSM_MC_2025a_DW.Delay_DSTATE_d;

      /* Delay: '<S206>/Delay3' */
      rtb_err_g = PMSM_MC_2025a_DW.Delay3_DSTATE_e;

      /* Delay: '<S206>/Delay1' */
      rtb_Add6 = PMSM_MC_2025a_DW.Delay1_DSTATE_p;

      /* Sum: '<S206>/Add4' incorporates:
       *  Delay: '<S206>/Delay'
       *  Delay: '<S206>/Delay1'
       *  Delay: '<S206>/Delay3'
       *  Gain: '<S206>/Ts2'
       *  Inport: '<Root>/ACurrent_Sample'
       *  Product: '<S206>/Product2'
       *  Product: '<S206>/Product3'
       *  Sum: '<S206>/Add5'
       */
      PMSM_MC_2025a_DW.Delay1_DSTATE_p = ((ACurrent_Sample -
        PMSM_MC_2025a_DW.Delay_DSTATE_n4) * PMSM_MC_2025a_ConstB.k1 * 5.0E-5F +
        PMSM_MC_2025a_DW.Delay1_DSTATE_p) - rtb_Integrator_g *
        PMSM_MC_2025a_DW.Delay3_DSTATE_e;

      /* Delay: '<S208>/Delay' */
      if (PMSM_MC_2025a_DW.icLoad_h) {
        /* Sum: '<S208>/Add1' incorporates:
         *  Delay: '<S206>/Delay1'
         */
        PMSM_MC_2025a_DW.Delay_DSTATE_jn = PMSM_MC_2025a_DW.Delay1_DSTATE_p;
      }

      /* Sum: '<S208>/Add1' incorporates:
       *  Delay: '<S206>/Delay1'
       *  Delay: '<S208>/Delay'
       *  Product: '<S208>/Product'
       *  Product: '<S208>/Product1'
       */
      PMSM_MC_2025a_DW.Delay_DSTATE_jn = PMSM_MC_2025a_ConstB.Add_p *
        PMSM_MC_2025a_DW.Delay_DSTATE_jn + PMSM_MC_2025a_DW.Delay1_DSTATE_p;

      /* Switch: '<S207>/Switch1' incorporates:
       *  Constant: '<S207>/Constant2'
       *  Constant: '<S207>/Constant3'
       *  Constant: '<S211>/Constant'
       *  Inport: '<Root>/MotorSpdRef'
       *  RelationalOperator: '<S211>/Compare'
       */
      if (MotorSpdRef >= 0) {
        rtb_Sum_j = -1.0F;
      } else {
        rtb_Sum_j = 1.0F;
      }

      /* End of Switch: '<S207>/Switch1' */

      /* Sum: '<S206>/Add7' incorporates:
       *  Delay: '<S206>/Delay2'
       *  Delay: '<S206>/Delay3'
       *  Gain: '<S206>/Ts6'
       *  Product: '<S206>/Product6'
       *  Product: '<S206>/Product7'
       *  Sum: '<S206>/Add9'
       */
      PMSM_MC_2025a_DW.Delay3_DSTATE_e = ((rtb_Product_cc -
        PMSM_MC_2025a_DW.Delay2_DSTATE_d) * PMSM_MC_2025a_ConstB.k1 * 5.0E-5F +
        PMSM_MC_2025a_DW.Delay3_DSTATE_e) + rtb_Add6 * rtb_Integrator_g;

      /* Delay: '<S209>/Delay' */
      if (PMSM_MC_2025a_DW.icLoad_hx) {
        /* Sum: '<S209>/Add1' incorporates:
         *  Delay: '<S206>/Delay3'
         */
        PMSM_MC_2025a_DW.Delay_DSTATE_dq = PMSM_MC_2025a_DW.Delay3_DSTATE_e;
      }

      /* Sum: '<S209>/Add1' incorporates:
       *  Delay: '<S206>/Delay3'
       *  Delay: '<S209>/Delay'
       *  Product: '<S209>/Product'
       *  Product: '<S209>/Product1'
       */
      PMSM_MC_2025a_DW.Delay_DSTATE_dq = PMSM_MC_2025a_ConstB.Add_b *
        PMSM_MC_2025a_DW.Delay_DSTATE_dq + PMSM_MC_2025a_DW.Delay3_DSTATE_e;

      /* Sum: '<S207>/err' incorporates:
       *  Delay: '<S207>/Delay'
       *  Product: '<S207>/Product'
       *  Product: '<S207>/Product1'
       *  Product: '<S207>/Product2'
       *  Product: '<S207>/Product3'
       *  Trigonometry: '<S207>/Cos'
       *  Trigonometry: '<S207>/Sin'
       */
      rtb_Sum_j = cosf(PMSM_MC_2025a_DW.Delay_DSTATE_h) *
        PMSM_MC_2025a_DW.Delay_DSTATE_jn * rtb_Sum_j + sinf
        (PMSM_MC_2025a_DW.Delay_DSTATE_h) * PMSM_MC_2025a_DW.Delay_DSTATE_dq *
        rtb_Sum_j;

      /* DiscreteIntegrator: '<S248>/Integrator' incorporates:
       *  Constant: '<S207>/Constant6'
       *  RelationalOperator: '<S210>/Compare'
       */
      if (SensorLessEn_CFG && (PMSM_MC_2025a_DW.Integrator_PrevResetState_m <= 0))
      {
        PMSM_MC_2025a_DW.Integrator_DSTATE_m = 0.0F;
      }

      /* Sum: '<S257>/Sum' incorporates:
       *  Constant: '<S207>/Constant'
       *  DiscreteIntegrator: '<S248>/Integrator'
       *  Product: '<S253>/PProd Out'
       */
      rtb_Integrator_g = rtb_Sum_j * 200.0F +
        PMSM_MC_2025a_DW.Integrator_DSTATE_m;

      /* Math: '<S207>/Mod' incorporates:
       *  Constant: '<S207>/Constant5'
       *  Delay: '<S207>/Delay'
       *  Gain: '<S207>/Gain'
       *  Sum: '<S207>/Add'
       */
      PMSM_MC_2025a_DW.Delay_DSTATE_h = rt_modf_snf(5.0E-5F * rtb_Integrator_g +
        PMSM_MC_2025a_DW.Delay_DSTATE_h, 6.28318548F);

      /* Merge: '<S20>/Merge' incorporates:
       *  Delay: '<S207>/Delay'
       *  SignalConversion generated from: '<S147>/Thetae_Est'
       */
      PMSM_MC_2025a_B.Merge = PMSM_MC_2025a_DW.Delay_DSTATE_h;

      /* Delay: '<S212>/Delay' */
      if (PMSM_MC_2025a_DW.icLoad_a) {
        PMSM_MC_2025a_DW.Delay_DSTATE_k = rtb_Integrator_g;
      }

      /* Sum: '<S212>/Add1' incorporates:
       *  Constant: '<S207>/Constant1'
       *  Delay: '<S147>/Delay'
       *  Delay: '<S212>/Delay'
       *  Product: '<S212>/Product'
       *  Product: '<S212>/Product1'
       */
      PMSM_MC_2025a_DW.Delay_DSTATE_d = rtb_Integrator_g * 0.0085F +
        PMSM_MC_2025a_ConstB.Add_f * PMSM_MC_2025a_DW.Delay_DSTATE_k;

      /* Sum: '<S152>/Add1' incorporates:
       *  Delay: '<S147>/Delay'
       *  Merge: '<S20>/Merge1'
       *  SignalConversion generated from: '<S147>/We_Est'
       */
      PMSM_MC_2025a_B.Merge1 = PMSM_MC_2025a_DW.Delay_DSTATE_d;

      /* Sum: '<S206>/Add6' incorporates:
       *  Delay: '<S206>/Delay2'
       *  Delay: '<S6>/Delay1'
       *  Gain: '<S206>/1-Rs*Ts//Ls1'
       *  Gain: '<S206>/Ts//Ls2'
       *  Gain: '<S206>/Ts//Ls3'
       *  Gain: '<S206>/Ts5'
       *  Product: '<S206>/Product4'
       *  Product: '<S206>/Product5'
       *  Sum: '<S206>/Add8'
       */
      PMSM_MC_2025a_DW.Delay2_DSTATE_d = (((0.90476191F *
        PMSM_MC_2025a_DW.Delay2_DSTATE_d - PMSM_MC_2025a_DW.Delay2_DSTATE_d *
        PMSM_MC_2025a_ConstB.Ts4) - 1.19047618F * rtb_err_g) + 1.19047618F *
        PMSM_MC_2025a_DW.Delay1_DSTATE_k) + PMSM_MC_2025a_ConstB.Add_i *
        rtb_Product_cc * 5.0E-5F;

      /* Sum: '<S206>/Add3' incorporates:
       *  Delay: '<S206>/Delay'
       *  Delay: '<S6>/Delay'
       *  Gain: '<S206>/1-Rs*Ts//Ls'
       *  Gain: '<S206>/Ts//Ls'
       *  Gain: '<S206>/Ts//Ls1'
       *  Gain: '<S206>/Ts1'
       *  Inport: '<Root>/ACurrent_Sample'
       *  Product: '<S206>/Product'
       *  Product: '<S206>/Product1'
       *  Sum: '<S206>/Add2'
       */
      PMSM_MC_2025a_DW.Delay_DSTATE_n4 = (((0.90476191F *
        PMSM_MC_2025a_DW.Delay_DSTATE_n4 - PMSM_MC_2025a_DW.Delay_DSTATE_n4 *
        PMSM_MC_2025a_ConstB.Ts) - 1.19047618F * rtb_Add6) + 1.19047618F *
        PMSM_MC_2025a_DW.Delay_DSTATE_j) + PMSM_MC_2025a_ConstB.Add_i *
        ACurrent_Sample * 5.0E-5F;

      /* Update for Delay: '<S208>/Delay' */
      PMSM_MC_2025a_DW.icLoad_h = false;

      /* Update for Delay: '<S209>/Delay' */
      PMSM_MC_2025a_DW.icLoad_hx = false;

      /* Update for DiscreteIntegrator: '<S248>/Integrator' incorporates:
       *  Constant: '<S207>/Constant4'
       *  Constant: '<S207>/Constant6'
       *  Product: '<S245>/IProd Out'
       *  RelationalOperator: '<S210>/Compare'
       */
      PMSM_MC_2025a_DW.Integrator_DSTATE_m += rtb_Sum_j * 2.0F;
      PMSM_MC_2025a_DW.Integrator_PrevResetState_m = (int8_T)SensorLessEn_CFG;

      /* Update for Delay: '<S212>/Delay' incorporates:
       *  Delay: '<S147>/Delay'
       */
      PMSM_MC_2025a_DW.icLoad_a = false;
      PMSM_MC_2025a_DW.Delay_DSTATE_k = PMSM_MC_2025a_DW.Delay_DSTATE_d;
    }

    /* End of Outputs for SubSystem: '<S20>/Luenberger+PLL' */

    /* Outputs for Enabled SubSystem: '<S20>/SMO+PLL' incorporates:
     *  EnablePort: '<S148>/Enable'
     */
    if (rtb_Switch_hz == 1) {
      /* Sum: '<S267>/Add2' incorporates:
       *  Constant: '<S267>/Constant11'
       *  Constant: '<S267>/Constant4'
       *  Constant: '<S267>/Ts'
       *  Delay: '<S267>/Delay'
       *  Delay: '<S267>/Delay2'
       *  Delay: '<S6>/Delay'
       *  Product: '<S267>/Product'
       *  Product: '<S267>/Product1'
       *  Product: '<S267>/Product2'
       *  Sum: '<S267>/Add'
       *  Sum: '<S267>/Add1'
       */
      PMSM_MC_2025a_DW.Delay_DSTATE_o += ((PMSM_MC_2025a_DW.Delay_DSTATE_j -
        PMSM_MC_2025a_DW.Delay2_DSTATE) * 23809.5F + -1904.8F *
        PMSM_MC_2025a_DW.Delay_DSTATE_o) * 5.0E-5F;

      /* Sum: '<S267>/Add3' incorporates:
       *  Delay: '<S267>/Delay'
       *  Inport: '<Root>/ACurrent_Sample'
       */
      rtb_err_g = PMSM_MC_2025a_DW.Delay_DSTATE_o - ACurrent_Sample;

      /* Switch: '<S326>/Switch' incorporates:
       *  Constant: '<S267>/Constant9'
       *  Constant: '<S326>/Constant'
       *  Product: '<S326>/Divide'
       *  RelationalOperator: '<S326>/Relational Operator'
       *  RelationalOperator: '<S326>/Relational Operator1'
       *  Switch: '<S326>/Switch1'
       */
      if (rtb_err_g > 0.7F) {
        rtb_Sum_la = 1.0F;
      } else if (rtb_err_g < PMSM_MC_2025a_ConstB.Gain_a) {
        /* Switch: '<S326>/Switch1' incorporates:
         *  Constant: '<S326>/Constant1'
         */
        rtb_Sum_la = -1.0F;
      } else {
        rtb_Sum_la = rtb_err_g / 0.7F;
      }

      /* Product: '<S326>/Product' incorporates:
       *  Constant: '<S267>/Constant8'
       *  Delay: '<S267>/Delay2'
       *  Switch: '<S326>/Switch'
       */
      PMSM_MC_2025a_DW.Delay2_DSTATE = rtb_Sum_la * 5.5F;

      /* Delay: '<S324>/Delay' */
      if (PMSM_MC_2025a_DW.icLoad) {
        /* Sum: '<S324>/Add1' incorporates:
         *  Delay: '<S267>/Delay2'
         */
        PMSM_MC_2025a_DW.Delay_DSTATE_o0 = PMSM_MC_2025a_DW.Delay2_DSTATE;
      }

      /* Sum: '<S324>/Add1' incorporates:
       *  Constant: '<S267>/Constant10'
       *  Delay: '<S267>/Delay2'
       *  Delay: '<S324>/Delay'
       *  Product: '<S324>/Product'
       *  Product: '<S324>/Product1'
       */
      PMSM_MC_2025a_DW.Delay_DSTATE_o0 = PMSM_MC_2025a_DW.Delay2_DSTATE * 0.35F
        + PMSM_MC_2025a_ConstB.Add_c * PMSM_MC_2025a_DW.Delay_DSTATE_o0;

      /* Switch: '<S266>/Switch1' incorporates:
       *  Constant: '<S266>/Constant2'
       *  Constant: '<S266>/Constant3'
       *  Constant: '<S269>/Constant'
       *  Inport: '<Root>/MotorSpdRef'
       *  RelationalOperator: '<S269>/Compare'
       */
      if (MotorSpdRef >= 0) {
        rtb_Minus_p = -1;
      } else {
        rtb_Minus_p = 1;
      }

      /* End of Switch: '<S266>/Switch1' */

      /* Sum: '<S267>/Add6' incorporates:
       *  Constant: '<S267>/Constant'
       *  Constant: '<S267>/Constant2'
       *  Constant: '<S267>/Ts1'
       *  Delay: '<S267>/Delay1'
       *  Delay: '<S267>/Delay3'
       *  Delay: '<S6>/Delay1'
       *  Product: '<S267>/Product3'
       *  Product: '<S267>/Product4'
       *  Product: '<S267>/Product5'
       *  Sum: '<S267>/Add4'
       *  Sum: '<S267>/Add5'
       */
      PMSM_MC_2025a_DW.Delay1_DSTATE_kw += ((PMSM_MC_2025a_DW.Delay1_DSTATE_k -
        PMSM_MC_2025a_DW.Delay3_DSTATE) * 23809.5F + -1904.8F *
        PMSM_MC_2025a_DW.Delay1_DSTATE_kw) * 5.0E-5F;

      /* Sum: '<S267>/Add7' incorporates:
       *  Delay: '<S267>/Delay1'
       */
      rtb_err_g = PMSM_MC_2025a_DW.Delay1_DSTATE_kw - rtb_Product_cc;

      /* Switch: '<S327>/Switch' incorporates:
       *  Constant: '<S267>/Constant9'
       *  Constant: '<S327>/Constant'
       *  Product: '<S327>/Divide'
       *  RelationalOperator: '<S327>/Relational Operator'
       *  RelationalOperator: '<S327>/Relational Operator1'
       *  Switch: '<S327>/Switch1'
       */
      if (rtb_err_g > 0.7F) {
        rtb_Sum_la = 1.0F;
      } else if (rtb_err_g < PMSM_MC_2025a_ConstB.Gain_n) {
        /* Switch: '<S327>/Switch1' incorporates:
         *  Constant: '<S327>/Constant1'
         */
        rtb_Sum_la = -1.0F;
      } else {
        rtb_Sum_la = rtb_err_g / 0.7F;
      }

      /* Product: '<S327>/Product' incorporates:
       *  Constant: '<S267>/Constant8'
       *  Delay: '<S267>/Delay3'
       *  Switch: '<S327>/Switch'
       */
      PMSM_MC_2025a_DW.Delay3_DSTATE = rtb_Sum_la * 5.5F;

      /* Delay: '<S325>/Delay' */
      if (PMSM_MC_2025a_DW.icLoad_i) {
        /* Sum: '<S325>/Add1' incorporates:
         *  Delay: '<S267>/Delay3'
         */
        PMSM_MC_2025a_DW.Delay_DSTATE_n = PMSM_MC_2025a_DW.Delay3_DSTATE;
      }

      /* Sum: '<S325>/Add1' incorporates:
       *  Constant: '<S267>/Constant10'
       *  Delay: '<S267>/Delay3'
       *  Delay: '<S325>/Delay'
       *  Product: '<S325>/Product'
       *  Product: '<S325>/Product1'
       */
      PMSM_MC_2025a_DW.Delay_DSTATE_n = PMSM_MC_2025a_DW.Delay3_DSTATE * 0.35F +
        PMSM_MC_2025a_ConstB.Add_m * PMSM_MC_2025a_DW.Delay_DSTATE_n;

      /* Sum: '<S266>/err' incorporates:
       *  Delay: '<S266>/Delay'
       *  Product: '<S266>/Product'
       *  Product: '<S266>/Product1'
       *  Product: '<S266>/Product2'
       *  Product: '<S266>/Product3'
       *  Trigonometry: '<S266>/Cos'
       *  Trigonometry: '<S266>/Sin'
       */
      rtb_err_g = cosf(PMSM_MC_2025a_DW.Delay_DSTATE_b) *
        PMSM_MC_2025a_DW.Delay_DSTATE_o0 * (real32_T)rtb_Minus_p + sinf
        (PMSM_MC_2025a_DW.Delay_DSTATE_b) * PMSM_MC_2025a_DW.Delay_DSTATE_n *
        (real32_T)rtb_Minus_p;

      /* DiscreteIntegrator: '<S306>/Integrator' incorporates:
       *  Constant: '<S266>/Constant6'
       *  RelationalOperator: '<S268>/Compare'
       */
      if (SensorLessEn_CFG && (PMSM_MC_2025a_DW.Integrator_PrevResetState_j <= 0))
      {
        PMSM_MC_2025a_DW.Integrator_DSTATE_i = 0.0F;
      }

      /* Sum: '<S315>/Sum' incorporates:
       *  Constant: '<S266>/Constant'
       *  DiscreteIntegrator: '<S306>/Integrator'
       *  Product: '<S311>/PProd Out'
       */
      rtb_Add6 = rtb_err_g * 200.0F + PMSM_MC_2025a_DW.Integrator_DSTATE_i;

      /* Math: '<S266>/Mod' incorporates:
       *  Constant: '<S266>/Constant5'
       *  Delay: '<S266>/Delay'
       *  Gain: '<S266>/Gain'
       *  Sum: '<S266>/Add'
       */
      PMSM_MC_2025a_DW.Delay_DSTATE_b = rt_modf_snf(5.0E-5F * rtb_Add6 +
        PMSM_MC_2025a_DW.Delay_DSTATE_b, 6.28318548F);

      /* Merge: '<S20>/Merge' incorporates:
       *  Delay: '<S266>/Delay'
       *  SignalConversion generated from: '<S148>/Thetae_Est'
       */
      PMSM_MC_2025a_B.Merge = PMSM_MC_2025a_DW.Delay_DSTATE_b;

      /* Delay: '<S270>/Delay' */
      if (PMSM_MC_2025a_DW.icLoad_o) {
        PMSM_MC_2025a_DW.Delay_DSTATE_ok = rtb_Add6;
      }

      /* Sum: '<S152>/Add1' incorporates:
       *  Constant: '<S266>/Constant1'
       *  Delay: '<S270>/Delay'
       *  Product: '<S270>/Product'
       *  Product: '<S270>/Product1'
       *  Sum: '<S270>/Add1'
       */
      PMSM_MC_2025a_B.Merge1 = rtb_Add6 * 0.0085F + PMSM_MC_2025a_ConstB.Add *
        PMSM_MC_2025a_DW.Delay_DSTATE_ok;

      /* Update for Delay: '<S324>/Delay' */
      PMSM_MC_2025a_DW.icLoad = false;

      /* Update for Delay: '<S325>/Delay' */
      PMSM_MC_2025a_DW.icLoad_i = false;

      /* Update for DiscreteIntegrator: '<S306>/Integrator' incorporates:
       *  Constant: '<S266>/Constant4'
       *  Constant: '<S266>/Constant6'
       *  Product: '<S303>/IProd Out'
       *  RelationalOperator: '<S268>/Compare'
       */
      PMSM_MC_2025a_DW.Integrator_DSTATE_i += rtb_err_g * 10.0F;
      PMSM_MC_2025a_DW.Integrator_PrevResetState_j = (int8_T)SensorLessEn_CFG;

      /* Update for Delay: '<S270>/Delay' */
      PMSM_MC_2025a_DW.icLoad_o = false;
      PMSM_MC_2025a_DW.Delay_DSTATE_ok = PMSM_MC_2025a_B.Merge1;
    }

    /* End of Outputs for SubSystem: '<S20>/SMO+PLL' */
    if (SensorLessEn_CFG) {
      rtb_Sum_j = PMSM_MC_2025a_B.Thetae_SensLess;
    } else if (rtb_LogicalOperator) {
      /* Switch: '<S15>/Switch1' */
      rtb_Sum_j = PMSM_MC_2025a_B.MotCalThetae;
    } else {
      if (Switch < 0.0F) {
        /* Signum: '<S15>/Sign' incorporates:
         *  Switch: '<S15>/Switch1'
         */
        rtb_Minus_p = -1;
      } else {
        /* Signum: '<S15>/Sign' incorporates:
         *  Switch: '<S15>/Switch1'
         */
        rtb_Minus_p = (Switch > 0.0F);
      }

      /* Switch: '<S15>/Switch' incorporates:
       *  Abs: '<S15>/Abs'
       *  Constant: '<S136>/Constant'
       *  Constant: '<S15>/Constant'
       *  Constant: '<S15>/Constant1'
       *  Math: '<S15>/Mod'
       *  RelationalOperator: '<S136>/Compare'
       *  Signum: '<S15>/Sign'
       *  Sum: '<S15>/Add'
       *  Switch: '<S15>/Switch1'
       */
      if (rtb_Minus_p > 0) {
        rtb_Sum_j = rt_modf_snf(fabsf(Switch), 6.28F);
      } else {
        rtb_Sum_j = 6.28F - rt_modf_snf(fabsf(Switch), 6.28F);
      }

      /* End of Switch: '<S15>/Switch' */
    }

    /* Trigonometry: '<S15>/SinCos' incorporates:
     *  Constant: '<S143>/Constant'
     *  Constant: '<S144>/Constant'
     *  Constant: '<S145>/Constant'
     *  Constant: '<S15>/Constant3'
     *  RelationalOperator: '<S143>/Compare'
     *  RelationalOperator: '<S144>/Compare'
     *  RelationalOperator: '<S145>/Compare'
     *  Signum: '<S15>/Sign'
     *  Switch: '<S15>/Switch1'
     */
    rtb_Integrator_g = cosf(rtb_Sum_j);
    rtb_Sum_j = sinf(rtb_Sum_j);

    /* Sum: '<S18>/Add' incorporates:
     *  Inport: '<Root>/ACurrent_Sample'
     *  Product: '<S18>/Product'
     *  Product: '<S18>/Product1'
     *  Trigonometry: '<S15>/SinCos'
     */
    DAixCurrent = ACurrent_Sample * rtb_Integrator_g + rtb_Product_cc *
      rtb_Sum_j;

    /* Sum: '<S14>/Minus' */
    Switch = DAixCurrent_Ref - DAixCurrent;

    /* Logic: '<S14>/Logical Operator' incorporates:
     *  Constant: '<S21>/Constant'
     *  Constant: '<S24>/Constant'
     *  RelationalOperator: '<S21>/Compare'
     *  RelationalOperator: '<S24>/Compare'
     */
    rtb_LogicalOperator = ((PMSM_MC_2025a_B.Switch_m == 7) ||
      (PMSM_MC_2025a_B.Switch_m == 5));

    /* DiscreteIntegrator: '<S64>/Integrator' */
    if (rtb_LogicalOperator && (PMSM_MC_2025a_DW.Integrator_PrevResetState <= 0))
    {
      PMSM_MC_2025a_DW.Integrator_DSTATE = PMSM_MC_2025a_ConstB.Constant5;
      if (PMSM_MC_2025a_DW.Integrator_DSTATE > 13.0F) {
        PMSM_MC_2025a_DW.Integrator_DSTATE = 13.0F;
      } else if (PMSM_MC_2025a_DW.Integrator_DSTATE < -13.0F) {
        PMSM_MC_2025a_DW.Integrator_DSTATE = -13.0F;
      }
    }

    /* Sum: '<S73>/Sum' incorporates:
     *  Constant: '<S14>/Constant'
     *  DiscreteIntegrator: '<S64>/Integrator'
     *  Product: '<S69>/PProd Out'
     */
    rtb_err_g = Switch * MC_DCurrLopKp_CFG + PMSM_MC_2025a_DW.Integrator_DSTATE;

    /* Product: '<S14>/Divide' incorporates:
     *  Constant: '<S14>/Constant6'
     *  Inport: '<Root>/VBus_Sample'
     */
    rtb_Add6 = VBus_Sample / 1.732F;

    /* MultiPortSwitch: '<S17>/Multiport Switch' incorporates:
     *  Constant: '<S17>/Constant1'
     *  Constant: '<S17>/Constant3'
     */
    switch (PMSM_MC_2025a_B.Switch_m) {
     case 1:
      rtb_err_g = 0.6F;
      break;

     case 2:
      rtb_err_g = 0.6F;
      break;

     case 3:
      rtb_err_g = 0.0F;
      break;

     case 4:
      rtb_err_g = 0.0F;
      break;

     case 5:
      /* Switch: '<S28>/Switch2' incorporates:
       *  Gain: '<S14>/Gain'
       *  RelationalOperator: '<S28>/LowerRelop1'
       *  RelationalOperator: '<S28>/UpperRelop'
       *  Switch: '<S28>/Switch'
       */
      if (rtb_err_g > rtb_Add6) {
        rtb_err_g = rtb_Add6;
      } else if (rtb_err_g < -rtb_Add6) {
        /* Switch: '<S28>/Switch' incorporates:
         *  Gain: '<S14>/Gain'
         */
        rtb_err_g = -rtb_Add6;
      }
      break;

     case 6:
      rtb_err_g = 0.0F;
      break;

     case 7:
      /* Switch: '<S28>/Switch2' incorporates:
       *  Gain: '<S14>/Gain'
       *  RelationalOperator: '<S28>/LowerRelop1'
       *  RelationalOperator: '<S28>/UpperRelop'
       *  Switch: '<S28>/Switch'
       */
      if (rtb_err_g > rtb_Add6) {
        rtb_err_g = rtb_Add6;
      } else if (rtb_err_g < -rtb_Add6) {
        /* Switch: '<S28>/Switch' incorporates:
         *  Gain: '<S14>/Gain'
         */
        rtb_err_g = -rtb_Add6;
      }
      break;

     default:
      rtb_err_g = 0.0F;
      break;
    }

    /* End of MultiPortSwitch: '<S17>/Multiport Switch' */

    /* DiscreteIntegrator: '<S116>/Integrator' */
    if (rtb_LogicalOperator && (PMSM_MC_2025a_DW.Integrator_PrevResetState_c <=
         0)) {
      PMSM_MC_2025a_DW.Integrator_DSTATE_j = PMSM_MC_2025a_ConstB.Constant4;
      if (PMSM_MC_2025a_DW.Integrator_DSTATE_j > 13.0F) {
        PMSM_MC_2025a_DW.Integrator_DSTATE_j = 13.0F;
      } else if (PMSM_MC_2025a_DW.Integrator_DSTATE_j < -13.0F) {
        PMSM_MC_2025a_DW.Integrator_DSTATE_j = -13.0F;
      }
    }

    /* Sum: '<S18>/Add1' incorporates:
     *  Inport: '<Root>/ACurrent_Sample'
     *  Product: '<S18>/Product2'
     *  Product: '<S18>/Product3'
     *  Trigonometry: '<S15>/SinCos'
     */
    QAixCurrent = rtb_Integrator_g * rtb_Product_cc - ACurrent_Sample *
      rtb_Sum_j;

    /* Switch: '<S14>/Switch1' incorporates:
     *  Constant: '<S23>/Constant'
     *  Logic: '<S14>/Logical Operator1'
     *  RelationalOperator: '<S23>/Compare'
     *  RelationalOperator: '<S25>/Compare'
     *  Switch: '<S14>/Switch'
     */
    if (PMSM_MC_2025a_B.Switch_m == 5) {
      /* Temporary diagnostic handover: keep the pre-switch q-current command
       * for 200 ms so a bad estimated speed cannot immediately drive the
       * speed PI into saturation. */
      if (!PMSM_MC_2025a_Mode5Seen) {
        PMSM_MC_2025a_Mode5Seen = true;
        PMSM_MC_2025a_Mode5HoldActive = true;
        PMSM_MC_2025a_Mode5HoldTicks = 4000U;
        PMSM_MC_2025a_Mode5IqHold = QAixCurrent_Ref;
      }

      if (PMSM_MC_2025a_Mode5HoldActive) {
        rtb_Sum_la = PMSM_MC_2025a_Mode5IqHold;
        if (PMSM_MC_2025a_Mode5HoldTicks > 0U) {
          PMSM_MC_2025a_Mode5HoldTicks--;
        } else {
          PMSM_MC_2025a_Mode5HoldActive = false;
        }
      } else {
        rtb_Sum_la = QAixCurrent_Ref;
      }
    } else if ((PMSM_MC_2025a_B.Switch_m == 7) && (!PMSM_MC_2025a_B.TransmActiveFlag))
    {
      /* Switch: '<S14>/Switch' incorporates:
       *  Constant: '<S14>/Constant7'
       *  Constant: '<S22>/Constant'
       *  Inport: '<Root>/MotorSpdRef'
       *  RelationalOperator: '<S22>/Compare'
       */
      if (MotorSpdRef > 0) {
        rtb_Sum_la = 0.6F;
      } else {
        rtb_Sum_la = PMSM_MC_2025a_ConstB.Gain1_j;
      }
    } else {
      PMSM_MC_2025a_Mode5Seen = false;
      PMSM_MC_2025a_Mode5HoldActive = false;
      PMSM_MC_2025a_Mode5HoldTicks = 0U;
      rtb_Sum_la = QAixCurrent_Ref;
    }

    /* Sum: '<S14>/Minus1' incorporates:
     *  Switch: '<S14>/Switch1'
     */
    rtb_Product_cc = rtb_Sum_la - QAixCurrent;

    /* Sum: '<S125>/Sum' incorporates:
     *  Constant: '<S14>/Constant2'
     *  DiscreteIntegrator: '<S116>/Integrator'
     *  Product: '<S121>/PProd Out'
     */
    rtb_Sum_la = rtb_Product_cc * MC_QCurrLopKp_CFG +
      PMSM_MC_2025a_DW.Integrator_DSTATE_j;

    /* MultiPortSwitch: '<S17>/Multiport Switch1' incorporates:
     *  Constant: '<S17>/Constant'
     *  Constant: '<S17>/Constant2'
     */
    switch (PMSM_MC_2025a_B.Switch_m) {
     case 1:
      rtb_Add6 = 0.0F;
      break;

     case 2:
      rtb_Add6 = 0.0F;
      break;

     case 3:
      rtb_Add6 = 0.0F;
      break;

     case 4:
      rtb_Add6 = 0.0F;
      break;

     case 5:
      /* Switch: '<S29>/Switch2' incorporates:
       *  RelationalOperator: '<S29>/LowerRelop1'
       */
      if (!(rtb_Sum_la > rtb_Add6)) {
        /* Switch: '<S29>/Switch' incorporates:
         *  Gain: '<S14>/Gain'
         *  RelationalOperator: '<S29>/UpperRelop'
         */
        if (rtb_Sum_la < -rtb_Add6) {
          rtb_Add6 = -rtb_Add6;
        } else {
          rtb_Add6 = rtb_Sum_la;
        }
      }
      break;

     case 6:
      rtb_Add6 = 0.0F;
      break;

     case 7:
      /* Switch: '<S29>/Switch2' incorporates:
       *  RelationalOperator: '<S29>/LowerRelop1'
       */
      if (!(rtb_Sum_la > rtb_Add6)) {
        /* Switch: '<S29>/Switch' incorporates:
         *  Gain: '<S14>/Gain'
         *  RelationalOperator: '<S29>/UpperRelop'
         */
        if (rtb_Sum_la < -rtb_Add6) {
          rtb_Add6 = -rtb_Add6;
        } else {
          rtb_Add6 = rtb_Sum_la;
        }
      }
      break;

     default:
      rtb_Add6 = 0.6F;
      break;
    }

    /* End of MultiPortSwitch: '<S17>/Multiport Switch1' */

    /* Sum: '<S17>/Add' incorporates:
     *  Delay: '<S6>/Delay1'
     *  Product: '<S17>/Product1'
     *  Product: '<S17>/Product3'
     *  Trigonometry: '<S15>/SinCos'
     */
    PMSM_MC_2025a_DW.Delay1_DSTATE_k = rtb_Integrator_g * rtb_Add6 + rtb_err_g *
      rtb_Sum_j;

    /* Sum: '<S17>/Minus' incorporates:
     *  Delay: '<S6>/Delay'
     *  Product: '<S17>/Product2'
     *  Product: '<S17>/Product4'
     *  Trigonometry: '<S15>/SinCos'
     */
    PMSM_MC_2025a_DW.Delay_DSTATE_j = rtb_err_g * rtb_Integrator_g - rtb_Add6 *
      rtb_Sum_j;

    /* Fcn: '<S138>/B' incorporates:
     *  Delay: '<S6>/Delay1'
     *  Fcn: '<S138>/C'
     */
    rtb_err_g = 0.5F * PMSM_MC_2025a_DW.Delay1_DSTATE_k;

    /* DataTypeConversion: '<S138>/Data Type Conversion' incorporates:
     *  Delay: '<S6>/Delay'
     *  Delay: '<S6>/Delay1'
     *  Fcn: '<S138>/A'
     *  Fcn: '<S138>/B'
     *  Fcn: '<S138>/C'
     *  Gain: '<S138>/Gain'
     *  Gain: '<S138>/Gain1'
     *  Sum: '<S138>/Add'
     *  Switch: '<S138>/Switch'
     *  Switch: '<S138>/Switch1'
     *  Switch: '<S138>/Switch2'
     */
    rtb_Switch_hz = (uint8_T)((int32_T)((((uint32_T)
      ((PMSM_MC_2025a_DW.Delay_DSTATE_j * 0.866025388F - rtb_err_g > 0.0F) << 7)
      + ((uint32_T)(PMSM_MC_2025a_DW.Delay1_DSTATE_k > 0.0F) << 6)) + ((uint32_T)
      ((-PMSM_MC_2025a_DW.Delay_DSTATE_j * 0.866025388F - rtb_err_g > 0.0F) << 7)
      << 1)) >> 1) >> 5);

    /* Gain: '<S141>/Gain2' incorporates:
     *  Delay: '<S6>/Delay1'
     */
    rtb_err_g = 0.866025388F * PMSM_MC_2025a_DW.Delay1_DSTATE_k;

    /* Gain: '<S141>/Gain' incorporates:
     *  Delay: '<S6>/Delay'
     */
    rtb_Add6 = 1.5F * PMSM_MC_2025a_DW.Delay_DSTATE_j;

    /* Product: '<S141>/Product3' incorporates:
     *  Fcn: '<S141>/Fcn'
     *  Inport: '<Root>/VBus_Sample'
     */
    rtb_Integrator_g = 1.0F / VBus_Sample;

    /* MultiPortSwitch: '<S139>/Multiport Switch' incorporates:
     *  Delay: '<S6>/Delay1'
     *  Gain: '<S139>/Gain'
     *  Gain: '<S139>/Gain1'
     *  Gain: '<S139>/Gain2'
     *  Gain: '<S141>/Gain1'
     *  Product: '<S141>/Product'
     *  Product: '<S141>/Product1'
     *  Product: '<S141>/Product2'
     *  Sum: '<S141>/Add'
     *  Sum: '<S141>/Add1'
     */
    switch (rtb_Switch_hz) {
     case 1:
      rtb_Sum_j = (rtb_err_g - rtb_Add6) * rtb_Integrator_g;

      /* MultiPortSwitch: '<S139>/Multiport Switch1' incorporates:
       *  Product: '<S141>/Product1'
       *  Product: '<S141>/Product2'
       *  Sum: '<S141>/Add'
       *  Sum: '<S141>/Add1'
       */
      rtb_Integrator_g *= rtb_err_g + rtb_Add6;
      break;

     case 2:
      rtb_Sum_j = (rtb_err_g + rtb_Add6) * rtb_Integrator_g;

      /* MultiPortSwitch: '<S139>/Multiport Switch1' incorporates:
       *  Delay: '<S6>/Delay1'
       *  Gain: '<S139>/Gain'
       *  Gain: '<S141>/Gain1'
       *  Product: '<S141>/Product'
       *  Product: '<S141>/Product1'
       *  Sum: '<S141>/Add'
       */
      rtb_Integrator_g = -(1.73205078F * PMSM_MC_2025a_DW.Delay1_DSTATE_k *
                           rtb_Integrator_g);
      break;

     case 3:
      rtb_Sum_j = -((rtb_err_g - rtb_Add6) * rtb_Integrator_g);

      /* MultiPortSwitch: '<S139>/Multiport Switch1' incorporates:
       *  Delay: '<S6>/Delay1'
       *  Gain: '<S139>/Gain2'
       *  Gain: '<S141>/Gain1'
       *  Product: '<S141>/Product'
       *  Product: '<S141>/Product2'
       *  Sum: '<S141>/Add1'
       */
      rtb_Integrator_g *= 1.73205078F * PMSM_MC_2025a_DW.Delay1_DSTATE_k;
      break;

     case 4:
      rtb_Sum_j = -(1.73205078F * PMSM_MC_2025a_DW.Delay1_DSTATE_k *
                    rtb_Integrator_g);

      /* MultiPortSwitch: '<S139>/Multiport Switch1' incorporates:
       *  Delay: '<S6>/Delay1'
       *  Gain: '<S139>/Gain'
       *  Gain: '<S141>/Gain1'
       *  Product: '<S141>/Product'
       *  Product: '<S141>/Product2'
       *  Sum: '<S141>/Add1'
       */
      rtb_Integrator_g *= rtb_err_g - rtb_Add6;
      break;

     case 5:
      rtb_Sum_j = 1.73205078F * PMSM_MC_2025a_DW.Delay1_DSTATE_k *
        rtb_Integrator_g;

      /* MultiPortSwitch: '<S139>/Multiport Switch1' incorporates:
       *  Delay: '<S6>/Delay1'
       *  Gain: '<S139>/Gain1'
       *  Gain: '<S141>/Gain1'
       *  Product: '<S141>/Product'
       *  Product: '<S141>/Product1'
       *  Sum: '<S141>/Add'
       */
      rtb_Integrator_g = -((rtb_err_g + rtb_Add6) * rtb_Integrator_g);
      break;

     default:
      rtb_Sum_j = -((rtb_err_g + rtb_Add6) * rtb_Integrator_g);

      /* MultiPortSwitch: '<S139>/Multiport Switch1' incorporates:
       *  Gain: '<S139>/Gain1'
       *  Gain: '<S139>/Gain2'
       *  Product: '<S141>/Product1'
       *  Product: '<S141>/Product2'
       *  Sum: '<S141>/Add'
       *  Sum: '<S141>/Add1'
       */
      rtb_Integrator_g = -((rtb_err_g - rtb_Add6) * rtb_Integrator_g);
      break;
    }

    /* End of MultiPortSwitch: '<S139>/Multiport Switch' */

    /* Switch: '<S139>/Switch' incorporates:
     *  Constant: '<S137>/Tpwm'
     *  Fcn: '<S139>/Fcn'
     *  Fcn: '<S139>/Fcn1'
     *  Fcn: '<S139>/Fcn2'
     *  Switch: '<S139>/Switch1'
     */
    if ((1.0F - rtb_Integrator_g) - rtb_Sum_j >= 0.0F) {
      rtb_Add6 = rtb_Sum_j;
      rtb_err_g = rtb_Integrator_g;
    } else {
      /* Fcn: '<S139>/Fcn' incorporates:
       *  Fcn: '<S139>/Fcn1'
       */
      rtb_err_g = rtb_Sum_j + rtb_Integrator_g;
      rtb_Add6 = rtb_Sum_j / rtb_err_g;
      rtb_err_g = rtb_Integrator_g / rtb_err_g;
    }

    /* End of Switch: '<S139>/Switch' */

    /* Abs: '<S139>/Abs' */
    rtb_Add6 = fabsf(rtb_Add6);

    /* Abs: '<S139>/Abs1' */
    rtb_err_g = fabsf(rtb_err_g);

    /* MultiPortSwitch: '<S140>/Multiport Switch' */
    switch (rtb_Switch_hz) {
     case 1:
      /* Merge: '<S3>/Merge1' incorporates:
       *  Constant: '<S137>/Tpwm'
       *  Fcn: '<S140>/Fcn1'
       */
      UVoltage_PWM = ((1.0F - rtb_Add6) + rtb_err_g) / 2.0F;

      /* Merge: '<S3>/Merge2' incorporates:
       *  Constant: '<S137>/Tpwm'
       *  Fcn: '<S140>/Fcn'
       *  MultiPortSwitch: '<S140>/Multiport Switch1'
       */
      VVoltage_PWM = ((rtb_Add6 + 1.0F) + rtb_err_g) / 2.0F;

      /* Merge: '<S3>/Merge3' incorporates:
       *  Constant: '<S137>/Tpwm'
       *  Fcn: '<S140>/Fcn2'
       *  MultiPortSwitch: '<S140>/Multiport Switch2'
       */
      WVoltage_PWM = ((1.0F - rtb_Add6) - rtb_err_g) / 2.0F;
      break;

     case 2:
      /* Merge: '<S3>/Merge1' incorporates:
       *  Constant: '<S137>/Tpwm'
       *  Fcn: '<S140>/Fcn'
       */
      UVoltage_PWM = ((rtb_Add6 + 1.0F) + rtb_err_g) / 2.0F;

      /* Merge: '<S3>/Merge2' incorporates:
       *  Constant: '<S137>/Tpwm'
       *  Fcn: '<S140>/Fcn2'
       *  MultiPortSwitch: '<S140>/Multiport Switch1'
       */
      VVoltage_PWM = ((1.0F - rtb_Add6) - rtb_err_g) / 2.0F;

      /* Merge: '<S3>/Merge3' incorporates:
       *  Constant: '<S137>/Tpwm'
       *  Fcn: '<S140>/Fcn1'
       *  MultiPortSwitch: '<S140>/Multiport Switch2'
       */
      WVoltage_PWM = ((1.0F - rtb_Add6) + rtb_err_g) / 2.0F;
      break;

     case 3:
      /* Merge: '<S3>/Merge1' incorporates:
       *  Constant: '<S137>/Tpwm'
       *  Fcn: '<S140>/Fcn'
       */
      UVoltage_PWM = ((rtb_Add6 + 1.0F) + rtb_err_g) / 2.0F;

      /* Merge: '<S3>/Merge2' incorporates:
       *  Constant: '<S137>/Tpwm'
       *  Fcn: '<S140>/Fcn1'
       *  MultiPortSwitch: '<S140>/Multiport Switch1'
       */
      VVoltage_PWM = ((1.0F - rtb_Add6) + rtb_err_g) / 2.0F;

      /* Merge: '<S3>/Merge3' incorporates:
       *  Constant: '<S137>/Tpwm'
       *  Fcn: '<S140>/Fcn2'
       *  MultiPortSwitch: '<S140>/Multiport Switch2'
       */
      WVoltage_PWM = ((1.0F - rtb_Add6) - rtb_err_g) / 2.0F;
      break;

     case 4:
      /* Merge: '<S3>/Merge1' incorporates:
       *  Constant: '<S137>/Tpwm'
       *  Fcn: '<S140>/Fcn2'
       */
      UVoltage_PWM = ((1.0F - rtb_Add6) - rtb_err_g) / 2.0F;

      /* Merge: '<S3>/Merge2' incorporates:
       *  Constant: '<S137>/Tpwm'
       *  Fcn: '<S140>/Fcn1'
       *  MultiPortSwitch: '<S140>/Multiport Switch1'
       */
      VVoltage_PWM = ((1.0F - rtb_Add6) + rtb_err_g) / 2.0F;

      /* Merge: '<S3>/Merge3' incorporates:
       *  Constant: '<S137>/Tpwm'
       *  Fcn: '<S140>/Fcn'
       *  MultiPortSwitch: '<S140>/Multiport Switch2'
       */
      WVoltage_PWM = ((rtb_Add6 + 1.0F) + rtb_err_g) / 2.0F;
      break;

     case 5:
      /* Merge: '<S3>/Merge1' incorporates:
       *  Constant: '<S137>/Tpwm'
       *  Fcn: '<S140>/Fcn2'
       */
      UVoltage_PWM = ((1.0F - rtb_Add6) - rtb_err_g) / 2.0F;

      /* Merge: '<S3>/Merge2' incorporates:
       *  Constant: '<S137>/Tpwm'
       *  Fcn: '<S140>/Fcn'
       *  MultiPortSwitch: '<S140>/Multiport Switch1'
       */
      VVoltage_PWM = ((rtb_Add6 + 1.0F) + rtb_err_g) / 2.0F;

      /* Merge: '<S3>/Merge3' incorporates:
       *  Constant: '<S137>/Tpwm'
       *  Fcn: '<S140>/Fcn1'
       *  MultiPortSwitch: '<S140>/Multiport Switch2'
       */
      WVoltage_PWM = ((1.0F - rtb_Add6) + rtb_err_g) / 2.0F;
      break;

     default:
      /* Merge: '<S3>/Merge1' incorporates:
       *  Constant: '<S137>/Tpwm'
       *  Fcn: '<S140>/Fcn1'
       */
      UVoltage_PWM = ((1.0F - rtb_Add6) + rtb_err_g) / 2.0F;

      /* Merge: '<S3>/Merge2' incorporates:
       *  Constant: '<S137>/Tpwm'
       *  Fcn: '<S140>/Fcn2'
       *  MultiPortSwitch: '<S140>/Multiport Switch1'
       */
      VVoltage_PWM = ((1.0F - rtb_Add6) - rtb_err_g) / 2.0F;

      /* Merge: '<S3>/Merge3' incorporates:
       *  Constant: '<S137>/Tpwm'
       *  Fcn: '<S140>/Fcn'
       *  MultiPortSwitch: '<S140>/Multiport Switch2'
       */
      WVoltage_PWM = ((rtb_Add6 + 1.0F) + rtb_err_g) / 2.0F;
      break;
    }

    /* End of MultiPortSwitch: '<S140>/Multiport Switch' */

    /* Switch: '<S20>/Switch1' incorporates:
     *  Constant: '<S20>/Constant3'
     *  RelationalOperator: '<S142>/Compare'
     *  Switch: '<S20>/Switch2'
     */
    if (SensorLessEn_CFG) {
      /* Switch: '<S20>/Switch1' */
      Thetae_Est = PMSM_MC_2025a_B.Merge;

      /* Switch: '<S20>/Switch2' */
      PMSM_MC_2025a_B.Switch2 = PMSM_MC_2025a_B.Merge1;
    } else {
      /* Switch: '<S20>/Switch1' incorporates:
       *  Constant: '<S20>/Constant4'
       */
      Thetae_Est = 0.0F;

      /* Switch: '<S20>/Switch2' incorporates:
       *  Constant: '<S20>/Constant4'
       */
      PMSM_MC_2025a_B.Switch2 = 0.0F;
    }

    /* End of Switch: '<S20>/Switch1' */

    /* Update for DiscreteIntegrator: '<S64>/Integrator' incorporates:
     *  Constant: '<S14>/Constant1'
     *  Product: '<S61>/IProd Out'
     */
    PMSM_MC_2025a_DW.Integrator_DSTATE += Switch * MC_DCurrLopKi_CFG;
    if (PMSM_MC_2025a_DW.Integrator_DSTATE > 13.0F) {
      PMSM_MC_2025a_DW.Integrator_DSTATE = 13.0F;
    } else if (PMSM_MC_2025a_DW.Integrator_DSTATE < -13.0F) {
      PMSM_MC_2025a_DW.Integrator_DSTATE = -13.0F;
    }

    PMSM_MC_2025a_DW.Integrator_PrevResetState = (int8_T)rtb_LogicalOperator;

    /* End of Update for DiscreteIntegrator: '<S64>/Integrator' */

    /* Update for DiscreteIntegrator: '<S116>/Integrator' incorporates:
     *  Constant: '<S14>/Constant3'
     *  Product: '<S113>/IProd Out'
     */
    PMSM_MC_2025a_DW.Integrator_DSTATE_j += rtb_Product_cc * MC_QCurrLopKi_CFG;
    if (PMSM_MC_2025a_DW.Integrator_DSTATE_j > 13.0F) {
      PMSM_MC_2025a_DW.Integrator_DSTATE_j = 13.0F;
    } else if (PMSM_MC_2025a_DW.Integrator_DSTATE_j < -13.0F) {
      PMSM_MC_2025a_DW.Integrator_DSTATE_j = -13.0F;
    }

    PMSM_MC_2025a_DW.Integrator_PrevResetState_c = (int8_T)rtb_LogicalOperator;

    /* End of Update for DiscreteIntegrator: '<S116>/Integrator' */
    /* End of Outputs for SubSystem: '<S3>/FOC' */
  } else {
    /* Outputs for IfAction SubSystem: '<S3>/Stop' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Merge: '<S3>/Merge' incorporates:
     *  Constant: '<S8>/Constant1'
     *  SignalConversion generated from: '<S8>/SD_MosCtr'
     */
    SD_MosCtr = false;

    /* Merge: '<S3>/Merge1' incorporates:
     *  Constant: '<S8>/Constant'
     *  SignalConversion generated from: '<S8>/UVoltage_PWM'
     */
    UVoltage_PWM = 0.0F;

    /* Merge: '<S3>/Merge2' incorporates:
     *  Constant: '<S8>/Constant'
     *  SignalConversion generated from: '<S8>/VVoltage_PWM'
     */
    VVoltage_PWM = 0.0F;

    /* Merge: '<S3>/Merge3' incorporates:
     *  Constant: '<S8>/Constant'
     *  SignalConversion generated from: '<S8>/WVoltage_PWM'
     */
    WVoltage_PWM = 0.0F;

    /* End of Outputs for SubSystem: '<S3>/Stop' */
  }

  /* End of If: '<S3>/If' */

  /* Saturate: '<S3>/Saturation' */
  if (UVoltage_PWM > 0.95F) {
    /* Merge: '<S3>/Merge1' incorporates:
     *  Saturate: '<S3>/Saturation'
     */
    UVoltage_PWM = 0.95F;
  } else if (UVoltage_PWM < 0.0F) {
    /* Merge: '<S3>/Merge1' incorporates:
     *  Saturate: '<S3>/Saturation'
     */
    UVoltage_PWM = 0.0F;
  }

  /* End of Saturate: '<S3>/Saturation' */

  /* Saturate: '<S3>/Saturation1' */
  if (VVoltage_PWM > 0.95F) {
    /* Merge: '<S3>/Merge2' incorporates:
     *  Saturate: '<S3>/Saturation1'
     */
    VVoltage_PWM = 0.95F;
  } else if (VVoltage_PWM < 0.0F) {
    /* Merge: '<S3>/Merge2' incorporates:
     *  Saturate: '<S3>/Saturation1'
     */
    VVoltage_PWM = 0.0F;
  }

  /* End of Saturate: '<S3>/Saturation1' */

  /* Saturate: '<S3>/Saturation2' */
  if (WVoltage_PWM > 0.95F) {
    /* Merge: '<S3>/Merge3' incorporates:
     *  Saturate: '<S3>/Saturation2'
     */
    WVoltage_PWM = 0.95F;
  } else if (WVoltage_PWM < 0.0F) {
    /* Merge: '<S3>/Merge3' incorporates:
     *  Saturate: '<S3>/Saturation2'
     */
    WVoltage_PWM = 0.0F;
  }

  /* End of Saturate: '<S3>/Saturation2' */
  if (PMSM_MC_2025a_DW.counter >= 100000000U) {
    PMSM_MC_2025a_DW.counter = 0U;
  } else {
    PMSM_MC_2025a_DW.counter++;
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 5.0E-5, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  PMSM_MC_2025a_M->Timing.clockTick0++;
}

/* Model initialize function */
void PMSM_MC_2025a_initialize(void)
{
  /* SystemInitialize for Chart: '<Root>/Scheduler' incorporates:
   *  SubSystem: '<S1>/MC_LowFrqTask'
   */
  /* InitializeConditions for Delay: '<S332>/Delay' */
  PMSM_MC_2025a_DW.icLoad_c = true;

  /* InitializeConditions for Delay: '<S338>/Delay' */
  PMSM_MC_2025a_DW.icLoad_a1 = true;

  /* InitializeConditions for Delay: '<S339>/Delay' */
  PMSM_MC_2025a_DW.icLoad_e = true;

  /* InitializeConditions for DiscreteIntegrator: '<S377>/Integrator' */
  PMSM_MC_2025a_DW.Integrator_DSTATE_e = PMSM_MC_2025a_ConstB.Constant;
  if (PMSM_MC_2025a_DW.Integrator_DSTATE_e > 3.0F) {
    PMSM_MC_2025a_DW.Integrator_DSTATE_e = 3.0F;
  } else if (PMSM_MC_2025a_DW.Integrator_DSTATE_e < -3.0F) {
    PMSM_MC_2025a_DW.Integrator_DSTATE_e = -3.0F;
  }

  /* End of InitializeConditions for DiscreteIntegrator: '<S377>/Integrator' */

  /* SystemInitialize for Chart: '<Root>/Scheduler' incorporates:
   *  SubSystem: '<S1>/MC_HighFrqTask'
   */
  /* SystemInitialize for IfAction SubSystem: '<S3>/FOC' */
  /* InitializeConditions for DiscreteIntegrator: '<S64>/Integrator' */
  PMSM_MC_2025a_DW.Integrator_DSTATE = PMSM_MC_2025a_ConstB.Constant5;
  if (PMSM_MC_2025a_DW.Integrator_DSTATE > 13.0F) {
    PMSM_MC_2025a_DW.Integrator_DSTATE = 13.0F;
  } else if (PMSM_MC_2025a_DW.Integrator_DSTATE < -13.0F) {
    PMSM_MC_2025a_DW.Integrator_DSTATE = -13.0F;
  }

  PMSM_MC_2025a_DW.Integrator_PrevResetState = 2;

  /* End of InitializeConditions for DiscreteIntegrator: '<S64>/Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S116>/Integrator' */
  PMSM_MC_2025a_DW.Integrator_DSTATE_j = PMSM_MC_2025a_ConstB.Constant4;
  if (PMSM_MC_2025a_DW.Integrator_DSTATE_j > 13.0F) {
    PMSM_MC_2025a_DW.Integrator_DSTATE_j = 13.0F;
  } else if (PMSM_MC_2025a_DW.Integrator_DSTATE_j < -13.0F) {
    PMSM_MC_2025a_DW.Integrator_DSTATE_j = -13.0F;
  }

  PMSM_MC_2025a_DW.Integrator_PrevResetState_c = 2;

  /* End of InitializeConditions for DiscreteIntegrator: '<S116>/Integrator' */

  /* SystemInitialize for Enabled SubSystem: '<S20>/FluxObs+PLL' */
  /* InitializeConditions for DiscreteIntegrator: '<S188>/Integrator' */
  PMSM_MC_2025a_DW.Integrator_PrevResetState_cx = 2;

  /* InitializeConditions for Delay: '<S152>/Delay' */
  PMSM_MC_2025a_DW.icLoad_m = true;

  /* End of SystemInitialize for SubSystem: '<S20>/FluxObs+PLL' */

  /* SystemInitialize for Enabled SubSystem: '<S20>/Luenberger+PLL' */
  /* InitializeConditions for Delay: '<S208>/Delay' */
  PMSM_MC_2025a_DW.icLoad_h = true;

  /* InitializeConditions for Delay: '<S209>/Delay' */
  PMSM_MC_2025a_DW.icLoad_hx = true;

  /* InitializeConditions for DiscreteIntegrator: '<S248>/Integrator' */
  PMSM_MC_2025a_DW.Integrator_PrevResetState_m = 2;

  /* InitializeConditions for Delay: '<S212>/Delay' */
  PMSM_MC_2025a_DW.icLoad_a = true;

  /* End of SystemInitialize for SubSystem: '<S20>/Luenberger+PLL' */

  /* SystemInitialize for Enabled SubSystem: '<S20>/SMO+PLL' */
  /* InitializeConditions for Delay: '<S324>/Delay' */
  PMSM_MC_2025a_DW.icLoad = true;

  /* InitializeConditions for Delay: '<S325>/Delay' */
  PMSM_MC_2025a_DW.icLoad_i = true;

  /* InitializeConditions for DiscreteIntegrator: '<S306>/Integrator' */
  PMSM_MC_2025a_DW.Integrator_PrevResetState_j = 2;

  /* InitializeConditions for Delay: '<S270>/Delay' */
  PMSM_MC_2025a_DW.icLoad_o = true;

  /* End of SystemInitialize for SubSystem: '<S20>/SMO+PLL' */
  /* End of SystemInitialize for SubSystem: '<S3>/FOC' */

  /* Enable for Chart: '<Root>/Scheduler' incorporates:
   *  SubSystem: '<S1>/MC_LowFrqTask'
   */
  /* Enable for Chart: '<S331>/ModeMgr' */
  PMSM_MC_2025a_DW.previousTicks_h = PMSM_MC_2025a_M->Timing.clockTick0;

  /* Enable for Chart: '<Root>/Scheduler' incorporates:
   *  SubSystem: '<S1>/MC_HighFrqTask'
   */
  /* Enable for Chart: '<S7>/OpenLopThetaeCal' */
  PMSM_MC_2025a_DW.previousTicks = PMSM_MC_2025a_M->Timing.clockTick0;
}

/* Model terminate function */
void PMSM_MC_2025a_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
