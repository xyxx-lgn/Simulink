/*
 * File: PMSM_MC_2025a.c
 *
 * Code generated for Simulink model 'PMSM_MC_2025a'.
 *
 * Model version                  : 5.13
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Wed Oct 14 22:22:18 2026
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

/* Named constants for Chart: '<S326>/ModeMgr' */
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
real32_T MotorActSpd_Encode;           /* '<S333>/Add1' */
real32_T MotorActSpd_Est;              /* '<S334>/Add1' */
real32_T MotorActSpd;                  /* '<S327>/Switch' */
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
                                        * Referenced by: '<S328>/Constant3'
                                        */
real32_T MC_SpdLopKp_CFG = 0.002F;     /* Variable: MC_SpdLopKp_CFG
                                        * Referenced by: '<S328>/Constant2'
                                        */
boolean_T OpenLoopEn_CFG = false;      /* Variable: OpenLoopEn_CFG
                                        * Referenced by: '<S326>/Constant2'
                                        */
boolean_T SensorLessEn_CFG = false;    /* Variable: SensorLessEn_CFG
                                        * Referenced by:
                                        *   '<S326>/Constant1'
                                        *   '<S327>/Constant5'
                                        *   '<S15>/Constant3'
                                        */
uint8_T MC_MotModeDebug_CFG = 255U;    /* Variable: MC_MotModeDebug_CFG
                                        * Referenced by: '<S326>/Constant'
                                        */
uint8_T MC_POLE_NUM_CFG = 7U;          /* Variable: MC_POLE_NUM_CFG
                                        * Referenced by:
                                        *   '<S10>/Constant'
                                        *   '<S11>/Constant'
                                        */
uint8_T SensorLessType_CFG = 1U;       /* Variable: SensorLessType_CFG
                                        * Referenced by: '<S20>/Constant'
                                        */

/* Block signals (default storage) */
B_PMSM_MC_2025a_T PMSM_MC_2025a_B;

/* Block states (default storage) */
DW_PMSM_MC_2025a_T PMSM_MC_2025a_DW;

/* Real-time model */
static RT_MODEL_PMSM_MC_2025a_T PMSM_MC_2025a_M_;
RT_MODEL_PMSM_MC_2025a_T *const PMSM_MC_2025a_M = &PMSM_MC_2025a_M_;

/* Forward declaration for local functions */
static void PMSM_MC_2025a_RangeCheck(void);
static void PMSM_MC_2025a_Ramping(real_T in, real_T MaxStep);
static void PMSM_MC_2025a_OLThetaeSum(void);
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

/* Function for Chart: '<S326>/ModeMgr' */
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
    PMSM_MC_2025a_DW.Thetae_OL = (real32_T)fmod(PMSM_MC_2025a_DW.Thetae_OL, 6.28);
    PMSM_MC_2025a_DW.Thetae_OL = (real32_T)(6.28 - PMSM_MC_2025a_DW.Thetae_OL);
  } else {
    /* set range to [0 2pi] */
    PMSM_MC_2025a_DW.Thetae_OL = (real32_T)fmod(PMSM_MC_2025a_DW.Thetae_OL, 6.28);
  }
}

/* Function for Chart: '<S7>/OpenLopThetaeCal' */
static void PMSM_MC_2025a_WeightedTransmite(const real32_T *Switch)
{
  /* update factor each sw cycle */
  PMSM_MC_2025a_DW.TransmFactor += PMSM_MC_2025a_DW.TransmStep;

  /* open loop angle calculate */
  PMSM_MC_2025a_Ramping((real_T)PMSM_MC_2025a_ConstB.Gain, (real_T)
                        PMSM_MC_2025a_ConstB.Gain1);
  PMSM_MC_2025a_OLThetaeSum();
  if (PMSM_MC_2025a_DW.TransmFactor > 1.0F) {
    /* limit to [0,1] */
    PMSM_MC_2025a_DW.TransmFactor = 1.0F;
  }

  if (PMSM_MC_2025a_DW.TransmFactor > 0.99) {
    /* 开环切闭环完成 */
    PMSM_MC_2025a_B.OLStartCompletedFlag = true;
  }

  /* 计算一下输出的无感模式电角度 */
  PMSM_MC_2025a_B.Thetae_SensLess = (1.0F - PMSM_MC_2025a_DW.TransmFactor) *
    PMSM_MC_2025a_DW.Thetae_OL + *Switch * PMSM_MC_2025a_DW.TransmFactor;
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
  real_T rtb_Add3;
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
  uint8_T rtb_DataTypeConversion_e;
  boolean_T rtb_Compare_gz;
  if (PMSM_MC_2025a_DW.counter % 20U == 19U) {
    /* Outputs for Function Call SubSystem: '<S1>/MC_LowFrqTask' */
    /* Chart: '<S326>/ModeMgr' incorporates:
     *  Constant: '<S326>/Constant1'
     *  Constant: '<S326>/Constant2'
     *  Inport: '<Root>/Ecode_cnt'
     *  Inport: '<Root>/MotorSpdRef'
     */
    elapsedTicks_p = PMSM_MC_2025a_M->Timing.clockTick0 -
      PMSM_MC_2025a_DW.previousTicks_h;
    PMSM_MC_2025a_DW.previousTicks_h = PMSM_MC_2025a_M->Timing.clockTick0;
    elapsedTicks_p += PMSM_MC_2025a_DW.temporalCounter_i1_j;
    if (elapsedTicks_p <= 32767U) {
      PMSM_MC_2025a_DW.temporalCounter_i1_j = (uint16_T)elapsedTicks_p;
    } else {
      PMSM_MC_2025a_DW.temporalCounter_i1_j = 32767U;
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
            } else if (PMSM_MC_2025a_DW.temporalCounter_i1_j >= 12000) {
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
        rtb_Compare_gz = ((!OpenLoopEn_CFG) && (MotorSpdRef != 0));
        if (rtb_Compare_gz && SensorLessEn_CFG) {
          PMSM_MC_2025a_DW.is_c1_PMSM_MC_2025a = PMSM_MC_2025a_IN_SensorLessCtr;
          PMSM_MC_2025a_DW.is_SensorLessCtr = PMSM_MC_2025a_IN_Stop_e;
          PMSM_MC_2025a_B.Switch_m = 4U;
        } else if (rtb_Compare_gz && (!SensorLessEn_CFG)) {
          PMSM_MC_2025a_DW.is_c1_PMSM_MC_2025a = PMSM_MC_2025a_IN_SensorCtr;
          PMSM_MC_2025a_DW.is_SensorCtr = PMSM_MC_2025a_IN_Calibrate;
          PMSM_MC_2025a_DW.is_Calibrate = PMSM_MC_2025a_IN_Init;
          PMSM_MC_2025a_B.Switch_m = 0U;
        }
        break;
      }
    }

    /* End of Chart: '<S326>/ModeMgr' */

    /* Switch: '<S326>/Switch' incorporates:
     *  Constant: '<S326>/Constant'
     *  Constant: '<S329>/Constant'
     *  RelationalOperator: '<S329>/Compare'
     */
    if (MC_MotModeDebug_CFG != 255) {
      /* Switch: '<S326>/Switch' */
      PMSM_MC_2025a_B.Switch_m = MC_MotModeDebug_CFG;
    }

    /* End of Switch: '<S326>/Switch' */

    /* RelationalOperator: '<S335>/Compare' incorporates:
     *  Constant: '<S335>/Constant'
     */
    rtb_Compare_gz = (PMSM_MC_2025a_B.Switch_m == 5);

    /* DiscreteIntegrator: '<S373>/Integrator' */
    if (rtb_Compare_gz && (PMSM_MC_2025a_DW.Integrator_PrevResetState_k <= 0)) {
      PMSM_MC_2025a_DW.Integrator_DSTATE_e = PMSM_MC_2025a_ConstB.Constant;
      if (PMSM_MC_2025a_DW.Integrator_DSTATE_e > 3.0F) {
        PMSM_MC_2025a_DW.Integrator_DSTATE_e = 3.0F;
      } else if (PMSM_MC_2025a_DW.Integrator_DSTATE_e < -3.0F) {
        PMSM_MC_2025a_DW.Integrator_DSTATE_e = -3.0F;
      }
    }

    /* Delay: '<S327>/Delay' incorporates:
     *  Inport: '<Root>/Ecode_cnt'
     */
    if (PMSM_MC_2025a_DW.icLoad_c) {
      PMSM_MC_2025a_DW.Delay_DSTATE_h5 = Ecode_cnt;
    }

    /* Sum: '<S327>/Minus' incorporates:
     *  Delay: '<S327>/Delay'
     *  Inport: '<Root>/Ecode_cnt'
     */
    rtb_Minus_p = Ecode_cnt - PMSM_MC_2025a_DW.Delay_DSTATE_h5;

    /* Switch: '<S327>/Switch1' incorporates:
     *  Constant: '<S327>/Constant6'
     *  Constant: '<S331>/Constant'
     *  Constant: '<S332>/Constant'
     *  RelationalOperator: '<S331>/Compare'
     *  RelationalOperator: '<S332>/Compare'
     *  Sum: '<S327>/Add2'
     *  Switch: '<S327>/Switch2'
     */
    if (rtb_Minus_p < -8000) {
      sLong2MultiWord(rtb_Minus_p + 16384, &tmp.chunks[0U], 2);
      sMultiWordShl(&tmp.chunks[0U], 2, 31U, &rtb_Switch1.chunks[0U], 2);
    } else if (rtb_Minus_p > 8000) {
      /* Gain: '<S327>/Gain1' incorporates:
       *  Constant: '<S327>/Constant9'
       *  Delay: '<S327>/Delay'
       *  Inport: '<Root>/Ecode_cnt'
       *  Sum: '<S327>/Add5'
       *  Switch: '<S327>/Switch2'
       */
      elapsedTicks_p = 2147483648U;
      tmp_0 = (uint32_T)((PMSM_MC_2025a_DW.Delay_DSTATE_h5 - Ecode_cnt) + 16384);
      sMultiWordMul(&elapsedTicks_p, 1, &tmp_0, 1, &rtb_Switch1.chunks[0U], 2);
    } else {
      /* Switch: '<S327>/Switch2' */
      sLong2MultiWord(rtb_Minus_p, &tmp.chunks[0U], 2);
      sMultiWordShl(&tmp.chunks[0U], 2, 31U, &rtb_Switch1.chunks[0U], 2);
    }

    /* End of Switch: '<S327>/Switch1' */

    /* Product: '<S327>/Product' incorporates:
     *  Constant: '<S327>/Constant'
     *  Constant: '<S327>/Constant1'
     *  DataTypeConversion: '<S327>/Data Type Conversion'
     *  Product: '<S327>/Divide'
     */
    rtb_Product_cc = sMultiWord2Single(&rtb_Switch1.chunks[0U], 2, 0) *
      4.65661287E-10F / 16384.0F * 60000.0F;

    /* Delay: '<S333>/Delay' */
    if (PMSM_MC_2025a_DW.icLoad_a1) {
      PMSM_MC_2025a_DW.Delay_DSTATE_pq = rtb_Product_cc;
    }

    /* Sum: '<S333>/Add1' incorporates:
     *  Delay: '<S333>/Delay'
     *  Product: '<S333>/Product'
     *  Product: '<S333>/Product1'
     */
    MotorActSpd_Encode = PMSM_MC_2025a_ConstB.Add_k *
      PMSM_MC_2025a_DW.Delay_DSTATE_pq + rtb_Product_cc;

    /* Gain: '<S327>/Gain' incorporates:
     *  Constant: '<S327>/Constant3'
     *  Product: '<S327>/Divide1'
     */
    rtb_Product_cc = PMSM_MC_2025a_B.Merge1 / 7.0F * 9.55414F;

    /* Delay: '<S334>/Delay' */
    if (PMSM_MC_2025a_DW.icLoad_e) {
      PMSM_MC_2025a_DW.Delay_DSTATE_a = rtb_Product_cc;
    }

    /* Sum: '<S334>/Add1' incorporates:
     *  Delay: '<S334>/Delay'
     *  Product: '<S334>/Product'
     *  Product: '<S334>/Product1'
     */
    MotorActSpd_Est = PMSM_MC_2025a_ConstB.Add_iy *
      PMSM_MC_2025a_DW.Delay_DSTATE_a + rtb_Product_cc;

    /* Switch: '<S327>/Switch' incorporates:
     *  Constant: '<S327>/Constant5'
     */
    if (SensorLessEn_CFG) {
      /* Switch: '<S327>/Switch' */
      MotorActSpd = MotorActSpd_Est;
    } else {
      /* Switch: '<S327>/Switch' */
      MotorActSpd = MotorActSpd_Encode;
    }

    /* End of Switch: '<S327>/Switch' */

    /* Switch: '<S338>/Switch2' incorporates:
     *  Constant: '<S328>/Constant4'
     *  Gain: '<S328>/Gain1'
     *  Inport: '<Root>/MotorSpdRef'
     *  RelationalOperator: '<S338>/LowerRelop1'
     *  RelationalOperator: '<S338>/UpperRelop'
     *  Switch: '<S338>/Switch'
     */
    if (MotorSpdRef > 2000) {
      tmp_2 = 2000;
    } else if ((MotorSpdRef << 15) < PMSM_MC_2025a_ConstB.Gain1_g) {
      /* Switch: '<S338>/Switch' incorporates:
       *  Gain: '<S328>/Gain1'
       */
      tmp_2 = (int16_T)(PMSM_MC_2025a_ConstB.Gain1_g >> 15);
    } else {
      tmp_2 = MotorSpdRef;
    }

    /* Sum: '<S328>/Minus' incorporates:
     *  DataTypeConversion: '<S328>/Data Type Conversion'
     *  Switch: '<S338>/Switch2'
     */
    rtb_Product_cc = (real32_T)tmp_2 - MotorActSpd;

    /* Sum: '<S382>/Sum' incorporates:
     *  Constant: '<S328>/Constant2'
     *  DiscreteIntegrator: '<S373>/Integrator'
     *  Product: '<S378>/PProd Out'
     */
    PMSM_MC_2025a_B.Switch2 = rtb_Product_cc * MC_SpdLopKp_CFG +
      PMSM_MC_2025a_DW.Integrator_DSTATE_e;

    /* Switch: '<S337>/Switch2' incorporates:
     *  Constant: '<S328>/Constant1'
     *  RelationalOperator: '<S337>/LowerRelop1'
     *  RelationalOperator: '<S337>/UpperRelop'
     *  Switch: '<S337>/Switch'
     */
    if (PMSM_MC_2025a_B.Switch2 > 3.0F) {
      /* Sum: '<S382>/Sum' incorporates:
       *  Switch: '<S337>/Switch2'
       */
      PMSM_MC_2025a_B.Switch2 = 3.0F;
    } else if (PMSM_MC_2025a_B.Switch2 < PMSM_MC_2025a_ConstB.Gain_k) {
      /* Sum: '<S382>/Sum' incorporates:
       *  Switch: '<S337>/Switch'
       *  Switch: '<S337>/Switch2'
       */
      PMSM_MC_2025a_B.Switch2 = PMSM_MC_2025a_ConstB.Gain_k;
    }

    /* End of Switch: '<S337>/Switch2' */

    /* Update for DiscreteIntegrator: '<S373>/Integrator' incorporates:
     *  Constant: '<S328>/Constant3'
     *  Product: '<S370>/IProd Out'
     */
    PMSM_MC_2025a_DW.Integrator_DSTATE_e += rtb_Product_cc * MC_SpdLopKi_CFG;
    if (PMSM_MC_2025a_DW.Integrator_DSTATE_e > 3.0F) {
      PMSM_MC_2025a_DW.Integrator_DSTATE_e = 3.0F;
    } else if (PMSM_MC_2025a_DW.Integrator_DSTATE_e < -3.0F) {
      PMSM_MC_2025a_DW.Integrator_DSTATE_e = -3.0F;
    }

    PMSM_MC_2025a_DW.Integrator_PrevResetState_k = (int8_T)rtb_Compare_gz;

    /* End of Update for DiscreteIntegrator: '<S373>/Integrator' */

    /* Update for Delay: '<S327>/Delay' incorporates:
     *  Inport: '<Root>/Ecode_cnt'
     */
    PMSM_MC_2025a_DW.icLoad_c = false;
    PMSM_MC_2025a_DW.Delay_DSTATE_h5 = Ecode_cnt;

    /* Update for Delay: '<S333>/Delay' */
    PMSM_MC_2025a_DW.icLoad_a1 = false;
    PMSM_MC_2025a_DW.Delay_DSTATE_pq = MotorActSpd_Encode;

    /* Update for Delay: '<S334>/Delay' */
    PMSM_MC_2025a_DW.icLoad_e = false;
    PMSM_MC_2025a_DW.Delay_DSTATE_a = MotorActSpd_Est;

    /* End of Outputs for SubSystem: '<S1>/MC_LowFrqTask' */
  }

  /* Chart: '<Root>/Scheduler' incorporates:
   *  SubSystem: '<S1>/MC_HighFrqTask'
   */
  /* Product: '<S7>/Divide' incorporates:
   *  Constant: '<S7>/Pn'
   *  Delay: '<S3>/Delay'
   */
  rtb_Product_cc = PMSM_MC_2025a_DW.Delay_DSTATE_c / 7.0F;

  /* Switch: '<S323>/Switch' incorporates:
   *  Constant: '<S325>/Constant'
   *  Delay: '<S3>/Delay1'
   *  RelationalOperator: '<S325>/Compare'
   */
  if (PMSM_MC_2025a_DW.Delay1_DSTATE_i >= 0.0F) {
    /* Switch: '<S323>/Switch' incorporates:
     *  Constant: '<S323>/Constant'
     *  Math: '<S323>/Mod'
     */
    Switch = rt_modf_snf(PMSM_MC_2025a_DW.Delay1_DSTATE_i, 6.28F);
  } else {
    /* Switch: '<S323>/Switch' incorporates:
     *  Abs: '<S323>/Abs'
     *  Constant: '<S323>/Constant1'
     *  Constant: '<S323>/Constant2'
     *  Math: '<S323>/Mod1'
     *  Sum: '<S323>/Add'
     */
    Switch = 6.28F - rt_modf_snf(fabsf(PMSM_MC_2025a_DW.Delay1_DSTATE_i), 6.28F);
  }

  /* End of Switch: '<S323>/Switch' */

  /* Chart: '<S7>/OpenLopThetaeCal' incorporates:
   *  Constant: '<S7>/OLWeightedTransmTime_ms'
   */
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

    /* init output */
    PMSM_MC_2025a_B.Thetae_SensLess = 0.0F;
    PMSM_MC_2025a_B.OLStartCompletedFlag = false;

    /* init local variable */
    PMSM_MC_2025a_DW.WeRefRamped = 0.0F;
    PMSM_MC_2025a_DW.OLStableCnt = 0U;
    PMSM_MC_2025a_DW.TransmStep = 0.0F;
    PMSM_MC_2025a_DW.TransmFactor = 0.0F;
    PMSM_MC_2025a_DW.Thetae_OL = 0.0F;
  } else {
    switch (PMSM_MC_2025a_DW.is_c2_PMSM_MC_2025a) {
     case PMSM_MC_2025a_IN_CloseLop:
      if (PMSM_MC_2025a_B.Switch_m != 5) {
        PMSM_MC_2025a_DW.is_c2_PMSM_MC_2025a = PMSM_MC_2025a_IN_Stop_m;

        /* init output */
        PMSM_MC_2025a_B.Thetae_SensLess = 0.0F;
        PMSM_MC_2025a_B.OLStartCompletedFlag = false;

        /* init local variable */
        PMSM_MC_2025a_DW.WeRefRamped = 0.0F;
        PMSM_MC_2025a_DW.OLStableCnt = 0U;
        PMSM_MC_2025a_DW.TransmStep = 0.0F;
        PMSM_MC_2025a_DW.TransmFactor = 0.0F;
        PMSM_MC_2025a_DW.Thetae_OL = 0.0F;
      } else {
        PMSM_MC_2025a_B.Thetae_SensLess = Switch;
      }
      break;

     case PMSM_MC_2025a_IN_IFStart_k:
      if (PMSM_MC_2025a_B.OLStartCompletedFlag && (PMSM_MC_2025a_B.Switch_m == 5))
      {
        PMSM_MC_2025a_DW.is_IFStart = PMSM_MC_2025_IN_NO_ACTIVE_CHILD;
        PMSM_MC_2025a_DW.is_c2_PMSM_MC_2025a = PMSM_MC_2025a_IN_CloseLop;
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

            /* cal steps according time */
            PMSM_MC_2025a_DW.TransmStep = 0.5F;

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

        /* init output */
        PMSM_MC_2025a_B.Thetae_SensLess = 0.0F;
        PMSM_MC_2025a_B.OLStartCompletedFlag = false;

        /* init local variable */
        PMSM_MC_2025a_DW.WeRefRamped = 0.0F;
        PMSM_MC_2025a_DW.OLStableCnt = 0U;
        PMSM_MC_2025a_DW.TransmStep = 0.0F;
        PMSM_MC_2025a_DW.TransmFactor = 0.0F;
        PMSM_MC_2025a_DW.Thetae_OL = 0.0F;
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
   *  Constant: '<S141>/Constant'
   *  Constant: '<S142>/Constant'
   *  Constant: '<S143>/Constant'
   *  Constant: '<S15>/Constant3'
   *  Constant: '<S20>/Constant'
   *  Logic: '<S15>/Logical Operator'
   *  RelationalOperator: '<S141>/Compare'
   *  RelationalOperator: '<S142>/Compare'
   *  RelationalOperator: '<S143>/Compare'
   *  Signum: '<S15>/Sign'
   *  Switch: '<S15>/Switch1'
   *  Switch: '<S15>/Switch2'
   */
  rtb_Compare_gz = ((PMSM_MC_2025a_B.Switch_m == 1) || (PMSM_MC_2025a_B.Switch_m
    == 2));

  /* End of Outputs for SubSystem: '<S3>/FOC' */
  if (rtb_Compare_gz || (PMSM_MC_2025a_B.Switch_m == 5) ||
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

    /* Outputs for Enabled SubSystem: '<S20>/FluxObs+PLL' incorporates:
     *  EnablePort: '<S144>/Enable'
     */
    if (SensorLessType_CFG == 2) {
      /* Sum: '<S147>/e' incorporates:
       *  Delay: '<S147>/Delay2'
       *  Delay: '<S147>/Delay3'
       *  Math: '<S147>/Math Function'
       *  Math: '<S147>/Math Function1'
       *
       * About '<S147>/Math Function':
       *  Operator: magnitude^2
       *
       * About '<S147>/Math Function1':
       *  Operator: magnitude^2
       */
      rtb_err_g = (PMSM_MC_2025a_ConstB.MathFunction2 -
                   PMSM_MC_2025a_DW.Delay2_DSTATE_f *
                   PMSM_MC_2025a_DW.Delay2_DSTATE_f) -
        PMSM_MC_2025a_DW.Delay3_DSTATE_c * PMSM_MC_2025a_DW.Delay3_DSTATE_c;

      /* Sum: '<S147>/Add5' incorporates:
       *  Constant: '<S147>/Gamma'
       *  Delay: '<S147>/Delay'
       *  Delay: '<S147>/Delay2'
       *  Delay: '<S6>/Delay'
       *  Gain: '<S147>/Rs'
       *  Gain: '<S147>/Ts'
       *  Inport: '<Root>/ACurrent_Sample'
       *  Product: '<S147>/Product'
       *  Product: '<S147>/Product2'
       *  Sum: '<S147>/Add'
       *  Sum: '<S147>/Add1'
       */
      PMSM_MC_2025a_DW.Delay_DSTATE_i += ((PMSM_MC_2025a_DW.Delay_DSTATE_j -
        0.08F * ACurrent_Sample) + PMSM_MC_2025a_DW.Delay2_DSTATE_f * rtb_err_g *
        100000.0F) * 5.0E-5F;

      /* Sum: '<S147>/Add6' incorporates:
       *  Delay: '<S147>/Delay'
       *  Gain: '<S147>/Ld'
       *  Inport: '<Root>/ACurrent_Sample'
       */
      rtb_Add6 = PMSM_MC_2025a_DW.Delay_DSTATE_i - 4.2E-5F * ACurrent_Sample;

      /* Sum: '<S147>/Add7' incorporates:
       *  Constant: '<S147>/Gamma'
       *  Delay: '<S147>/Delay1'
       *  Delay: '<S147>/Delay3'
       *  Delay: '<S6>/Delay1'
       *  Gain: '<S147>/Rs1'
       *  Gain: '<S147>/Ts1'
       *  Product: '<S147>/Product1'
       *  Product: '<S147>/Product3'
       *  Sum: '<S147>/Add3'
       *  Sum: '<S147>/Add4'
       */
      PMSM_MC_2025a_DW.Delay1_DSTATE_o += (rtb_err_g *
        PMSM_MC_2025a_DW.Delay3_DSTATE_c * 100000.0F +
        (PMSM_MC_2025a_DW.Delay1_DSTATE_k - 0.08F * rtb_Product_cc)) * 5.0E-5F;

      /* Sum: '<S147>/Add8' incorporates:
       *  Delay: '<S147>/Delay1'
       *  Delay: '<S147>/Delay3'
       *  Gain: '<S147>/Lq'
       */
      PMSM_MC_2025a_DW.Delay3_DSTATE_c = PMSM_MC_2025a_DW.Delay1_DSTATE_o -
        4.2E-5F * rtb_Product_cc;

      /* Sum: '<S148>/err' incorporates:
       *  Delay: '<S147>/Delay3'
       *  Delay: '<S148>/Delay'
       *  Product: '<S148>/Product'
       *  Product: '<S148>/Product2'
       *  Trigonometry: '<S148>/Cos'
       *  Trigonometry: '<S148>/Sin'
       */
      rtb_err_g = cosf(PMSM_MC_2025a_DW.Delay_DSTATE_p) *
        PMSM_MC_2025a_DW.Delay3_DSTATE_c - sinf(PMSM_MC_2025a_DW.Delay_DSTATE_p)
        * rtb_Add6;

      /* Sum: '<S194>/Sum' incorporates:
       *  Constant: '<S148>/Constant'
       *  DiscreteIntegrator: '<S185>/Integrator'
       *  Product: '<S190>/PProd Out'
       */
      rtb_Sum_j = rtb_err_g * 52000.0F + PMSM_MC_2025a_DW.Integrator_DSTATE_l;

      /* Sum: '<S148>/Add' incorporates:
       *  Delay: '<S147>/Delay2'
       *  Delay: '<S148>/Delay'
       *  Gain: '<S148>/Gain'
       */
      PMSM_MC_2025a_DW.Delay2_DSTATE_f = 5.0E-5F * rtb_Sum_j +
        PMSM_MC_2025a_DW.Delay_DSTATE_p;

      /* Math: '<S148>/Mod' incorporates:
       *  Constant: '<S148>/Constant5'
       *  Delay: '<S147>/Delay2'
       *  Delay: '<S148>/Delay'
       */
      PMSM_MC_2025a_DW.Delay_DSTATE_p = rt_modf_snf
        (PMSM_MC_2025a_DW.Delay2_DSTATE_f, 6.28318548F);

      /* SignalConversion generated from: '<S144>/Thetae_Est' incorporates:
       *  Delay: '<S148>/Delay'
       *  Delay: '<S3>/Delay1'
       */
      PMSM_MC_2025a_DW.Delay1_DSTATE_i = PMSM_MC_2025a_DW.Delay_DSTATE_p;

      /* Delay: '<S149>/Delay' */
      if (PMSM_MC_2025a_DW.icLoad_m) {
        PMSM_MC_2025a_DW.Delay_DSTATE_e = rtb_Sum_j;
      }

      /* Sum: '<S149>/Add1' incorporates:
       *  Constant: '<S148>/Constant1'
       *  Delay: '<S149>/Delay'
       *  Product: '<S149>/Product'
       *  Product: '<S149>/Product1'
       */
      PMSM_MC_2025a_B.Merge1 = rtb_Sum_j * 0.0085F + PMSM_MC_2025a_ConstB.Add_f5
        * PMSM_MC_2025a_DW.Delay_DSTATE_e;

      /* Update for Delay: '<S147>/Delay2' */
      PMSM_MC_2025a_DW.Delay2_DSTATE_f = rtb_Add6;

      /* Update for DiscreteIntegrator: '<S185>/Integrator' incorporates:
       *  Constant: '<S148>/Constant4'
       *  Product: '<S182>/IProd Out'
       */
      PMSM_MC_2025a_DW.Integrator_DSTATE_l += rtb_err_g * 40.0F;

      /* Update for Delay: '<S149>/Delay' */
      PMSM_MC_2025a_DW.icLoad_m = false;
      PMSM_MC_2025a_DW.Delay_DSTATE_e = PMSM_MC_2025a_B.Merge1;
    }

    /* End of Outputs for SubSystem: '<S20>/FluxObs+PLL' */

    /* Outputs for Enabled SubSystem: '<S20>/Luenberger+PLL' incorporates:
     *  EnablePort: '<S145>/Enable'
     */
    if (SensorLessType_CFG == 3) {
      /* Gain: '<S203>/Ts3' incorporates:
       *  Delay: '<S145>/Delay'
       */
      rtb_Integrator_g = 5.0E-5F * PMSM_MC_2025a_DW.Delay_DSTATE_d;

      /* Delay: '<S203>/Delay3' */
      rtb_err_g = PMSM_MC_2025a_DW.Delay3_DSTATE_e;

      /* Delay: '<S203>/Delay1' */
      rtb_Add6 = PMSM_MC_2025a_DW.Delay1_DSTATE_p;

      /* Sum: '<S203>/Add4' incorporates:
       *  Delay: '<S203>/Delay'
       *  Delay: '<S203>/Delay1'
       *  Delay: '<S203>/Delay3'
       *  Gain: '<S203>/Ts2'
       *  Inport: '<Root>/ACurrent_Sample'
       *  Product: '<S203>/Product2'
       *  Product: '<S203>/Product3'
       *  Sum: '<S203>/Add5'
       */
      PMSM_MC_2025a_DW.Delay1_DSTATE_p = ((ACurrent_Sample -
        PMSM_MC_2025a_DW.Delay_DSTATE_n4) * PMSM_MC_2025a_ConstB.k1 * 5.0E-5F +
        PMSM_MC_2025a_DW.Delay1_DSTATE_p) - rtb_Integrator_g *
        PMSM_MC_2025a_DW.Delay3_DSTATE_e;

      /* Delay: '<S205>/Delay' */
      if (PMSM_MC_2025a_DW.icLoad_h) {
        /* Sum: '<S205>/Add1' incorporates:
         *  Delay: '<S203>/Delay1'
         */
        PMSM_MC_2025a_DW.Delay_DSTATE_jn = PMSM_MC_2025a_DW.Delay1_DSTATE_p;
      }

      /* Sum: '<S205>/Add1' incorporates:
       *  Delay: '<S203>/Delay1'
       *  Delay: '<S205>/Delay'
       *  Product: '<S205>/Product'
       *  Product: '<S205>/Product1'
       */
      PMSM_MC_2025a_DW.Delay_DSTATE_jn = PMSM_MC_2025a_ConstB.Add_p *
        PMSM_MC_2025a_DW.Delay_DSTATE_jn + PMSM_MC_2025a_DW.Delay1_DSTATE_p;

      /* Switch: '<S204>/Switch1' incorporates:
       *  Constant: '<S204>/Constant2'
       *  Constant: '<S204>/Constant3'
       *  Constant: '<S207>/Constant'
       *  Inport: '<Root>/MotorSpdRef'
       *  RelationalOperator: '<S207>/Compare'
       */
      if (MotorSpdRef >= 0) {
        rtb_Sum_j = -1.0F;
      } else {
        rtb_Sum_j = 1.0F;
      }

      /* End of Switch: '<S204>/Switch1' */

      /* Sum: '<S203>/Add7' incorporates:
       *  Delay: '<S203>/Delay2'
       *  Delay: '<S203>/Delay3'
       *  Gain: '<S203>/Ts6'
       *  Product: '<S203>/Product6'
       *  Product: '<S203>/Product7'
       *  Sum: '<S203>/Add9'
       */
      PMSM_MC_2025a_DW.Delay3_DSTATE_e = ((rtb_Product_cc -
        PMSM_MC_2025a_DW.Delay2_DSTATE_d) * PMSM_MC_2025a_ConstB.k1 * 5.0E-5F +
        PMSM_MC_2025a_DW.Delay3_DSTATE_e) + rtb_Add6 * rtb_Integrator_g;

      /* Delay: '<S206>/Delay' */
      if (PMSM_MC_2025a_DW.icLoad_hx) {
        /* Sum: '<S206>/Add1' incorporates:
         *  Delay: '<S203>/Delay3'
         */
        PMSM_MC_2025a_DW.Delay_DSTATE_dq = PMSM_MC_2025a_DW.Delay3_DSTATE_e;
      }

      /* Sum: '<S206>/Add1' incorporates:
       *  Delay: '<S203>/Delay3'
       *  Delay: '<S206>/Delay'
       *  Product: '<S206>/Product'
       *  Product: '<S206>/Product1'
       */
      PMSM_MC_2025a_DW.Delay_DSTATE_dq = PMSM_MC_2025a_ConstB.Add_b *
        PMSM_MC_2025a_DW.Delay_DSTATE_dq + PMSM_MC_2025a_DW.Delay3_DSTATE_e;

      /* Sum: '<S204>/err' incorporates:
       *  Delay: '<S204>/Delay'
       *  Product: '<S204>/Product'
       *  Product: '<S204>/Product1'
       *  Product: '<S204>/Product2'
       *  Product: '<S204>/Product3'
       *  Trigonometry: '<S204>/Cos'
       *  Trigonometry: '<S204>/Sin'
       */
      rtb_Sum_j = cosf(PMSM_MC_2025a_DW.Delay_DSTATE_h) *
        PMSM_MC_2025a_DW.Delay_DSTATE_jn * rtb_Sum_j + sinf
        (PMSM_MC_2025a_DW.Delay_DSTATE_h) * PMSM_MC_2025a_DW.Delay_DSTATE_dq *
        rtb_Sum_j;

      /* Sum: '<S253>/Sum' incorporates:
       *  Constant: '<S204>/Constant'
       *  DiscreteIntegrator: '<S244>/Integrator'
       *  Product: '<S249>/PProd Out'
       */
      rtb_Integrator_g = rtb_Sum_j * 200.0F +
        PMSM_MC_2025a_DW.Integrator_DSTATE_m;

      /* Math: '<S204>/Mod' incorporates:
       *  Constant: '<S204>/Constant5'
       *  Delay: '<S204>/Delay'
       *  Gain: '<S204>/Gain'
       *  Sum: '<S204>/Add'
       */
      PMSM_MC_2025a_DW.Delay_DSTATE_h = rt_modf_snf(5.0E-5F * rtb_Integrator_g +
        PMSM_MC_2025a_DW.Delay_DSTATE_h, 6.28318548F);

      /* SignalConversion generated from: '<S145>/Thetae_Est' incorporates:
       *  Delay: '<S204>/Delay'
       *  Delay: '<S3>/Delay1'
       */
      PMSM_MC_2025a_DW.Delay1_DSTATE_i = PMSM_MC_2025a_DW.Delay_DSTATE_h;

      /* Delay: '<S208>/Delay' */
      if (PMSM_MC_2025a_DW.icLoad_a) {
        PMSM_MC_2025a_DW.Delay_DSTATE_k = rtb_Integrator_g;
      }

      /* Sum: '<S208>/Add1' incorporates:
       *  Constant: '<S204>/Constant1'
       *  Delay: '<S145>/Delay'
       *  Delay: '<S208>/Delay'
       *  Product: '<S208>/Product'
       *  Product: '<S208>/Product1'
       */
      PMSM_MC_2025a_DW.Delay_DSTATE_d = rtb_Integrator_g * 0.0085F +
        PMSM_MC_2025a_ConstB.Add_f * PMSM_MC_2025a_DW.Delay_DSTATE_k;

      /* Sum: '<S149>/Add1' incorporates:
       *  Delay: '<S145>/Delay'
       *  Merge: '<S20>/Merge1'
       *  SignalConversion generated from: '<S145>/We_Est'
       */
      PMSM_MC_2025a_B.Merge1 = PMSM_MC_2025a_DW.Delay_DSTATE_d;

      /* Sum: '<S203>/Add6' incorporates:
       *  Delay: '<S203>/Delay2'
       *  Delay: '<S6>/Delay1'
       *  Gain: '<S203>/1-Rs*Ts//Ls1'
       *  Gain: '<S203>/Ts//Ls2'
       *  Gain: '<S203>/Ts//Ls3'
       *  Gain: '<S203>/Ts5'
       *  Product: '<S203>/Product4'
       *  Product: '<S203>/Product5'
       *  Sum: '<S203>/Add8'
       */
      PMSM_MC_2025a_DW.Delay2_DSTATE_d = (((0.90476191F *
        PMSM_MC_2025a_DW.Delay2_DSTATE_d - PMSM_MC_2025a_DW.Delay2_DSTATE_d *
        PMSM_MC_2025a_ConstB.Ts4) - 1.19047618F * rtb_err_g) + 1.19047618F *
        PMSM_MC_2025a_DW.Delay1_DSTATE_k) + PMSM_MC_2025a_ConstB.Add_i *
        rtb_Product_cc * 5.0E-5F;

      /* Sum: '<S203>/Add3' incorporates:
       *  Delay: '<S203>/Delay'
       *  Delay: '<S6>/Delay'
       *  Gain: '<S203>/1-Rs*Ts//Ls'
       *  Gain: '<S203>/Ts//Ls'
       *  Gain: '<S203>/Ts//Ls1'
       *  Gain: '<S203>/Ts1'
       *  Inport: '<Root>/ACurrent_Sample'
       *  Product: '<S203>/Product'
       *  Product: '<S203>/Product1'
       *  Sum: '<S203>/Add2'
       */
      PMSM_MC_2025a_DW.Delay_DSTATE_n4 = (((0.90476191F *
        PMSM_MC_2025a_DW.Delay_DSTATE_n4 - PMSM_MC_2025a_DW.Delay_DSTATE_n4 *
        PMSM_MC_2025a_ConstB.Ts) - 1.19047618F * rtb_Add6) + 1.19047618F *
        PMSM_MC_2025a_DW.Delay_DSTATE_j) + PMSM_MC_2025a_ConstB.Add_i *
        ACurrent_Sample * 5.0E-5F;

      /* Update for Delay: '<S205>/Delay' */
      PMSM_MC_2025a_DW.icLoad_h = false;

      /* Update for Delay: '<S206>/Delay' */
      PMSM_MC_2025a_DW.icLoad_hx = false;

      /* Update for DiscreteIntegrator: '<S244>/Integrator' incorporates:
       *  Constant: '<S204>/Constant4'
       *  Product: '<S241>/IProd Out'
       */
      PMSM_MC_2025a_DW.Integrator_DSTATE_m += rtb_Sum_j * 2.0F;

      /* Update for Delay: '<S208>/Delay' incorporates:
       *  Delay: '<S145>/Delay'
       */
      PMSM_MC_2025a_DW.icLoad_a = false;
      PMSM_MC_2025a_DW.Delay_DSTATE_k = PMSM_MC_2025a_DW.Delay_DSTATE_d;
    }

    /* End of Outputs for SubSystem: '<S20>/Luenberger+PLL' */

    /* Outputs for Enabled SubSystem: '<S20>/SMO+PLL' incorporates:
     *  EnablePort: '<S146>/Enable'
     */
    if (SensorLessType_CFG == 1) {
      /* Sum: '<S263>/Add2' incorporates:
       *  Delay: '<S263>/Delay'
       *  Delay: '<S263>/Delay2'
       *  Delay: '<S6>/Delay'
       *  Product: '<S263>/Product'
       *  Product: '<S263>/Product1'
       *  Product: '<S263>/Product2'
       *  Sum: '<S263>/Add'
       *  Sum: '<S263>/Add1'
       */
      PMSM_MC_2025a_DW.Delay_DSTATE += ((PMSM_MC_2025a_DW.Delay_DSTATE_j -
        PMSM_MC_2025a_DW.Delay2_DSTATE) * 23809.5 + -1904.800048828125 *
        PMSM_MC_2025a_DW.Delay_DSTATE) * 4.9999998736893758E-5;

      /* Sum: '<S263>/Add3' incorporates:
       *  Delay: '<S263>/Delay'
       *  Inport: '<Root>/ACurrent_Sample'
       */
      rtb_Add3 = PMSM_MC_2025a_DW.Delay_DSTATE - ACurrent_Sample;

      /* Switch: '<S321>/Switch' incorporates:
       *  Constant: '<S321>/Constant'
       *  Product: '<S321>/Divide'
       *  RelationalOperator: '<S321>/Relational Operator'
       *  RelationalOperator: '<S321>/Relational Operator1'
       *  Switch: '<S321>/Switch1'
       */
      if (rtb_Add3 > 0.699999988079071) {
        rtb_Add3 = 1.0;
      } else if (rtb_Add3 < PMSM_MC_2025a_ConstB.Gain_a) {
        /* Switch: '<S321>/Switch1' incorporates:
         *  Constant: '<S321>/Constant1'
         */
        rtb_Add3 = -1.0;
      } else {
        rtb_Add3 /= 0.699999988079071;
      }

      /* Product: '<S321>/Product' incorporates:
       *  Delay: '<S263>/Delay2'
       *  Switch: '<S321>/Switch'
       */
      PMSM_MC_2025a_DW.Delay2_DSTATE = rtb_Add3 * 5.5;

      /* Delay: '<S319>/Delay' */
      if (PMSM_MC_2025a_DW.icLoad) {
        /* Sum: '<S319>/Add1' incorporates:
         *  Delay: '<S263>/Delay2'
         */
        PMSM_MC_2025a_DW.Delay_DSTATE_o = PMSM_MC_2025a_DW.Delay2_DSTATE;
      }

      /* Sum: '<S319>/Add1' incorporates:
       *  Delay: '<S263>/Delay2'
       *  Delay: '<S319>/Delay'
       *  Product: '<S319>/Product'
       *  Product: '<S319>/Product1'
       */
      PMSM_MC_2025a_DW.Delay_DSTATE_o = PMSM_MC_2025a_DW.Delay2_DSTATE *
        0.34999999403953552 + PMSM_MC_2025a_ConstB.Add_c *
        PMSM_MC_2025a_DW.Delay_DSTATE_o;

      /* Switch: '<S262>/Switch1' incorporates:
       *  Constant: '<S262>/Constant2'
       *  Constant: '<S262>/Constant3'
       *  Constant: '<S264>/Constant'
       *  Inport: '<Root>/MotorSpdRef'
       *  RelationalOperator: '<S264>/Compare'
       */
      if (MotorSpdRef >= 0) {
        rtb_Minus_p = -1;
      } else {
        rtb_Minus_p = 1;
      }

      /* End of Switch: '<S262>/Switch1' */

      /* Sum: '<S263>/Add6' incorporates:
       *  Delay: '<S263>/Delay1'
       *  Delay: '<S263>/Delay3'
       *  Delay: '<S6>/Delay1'
       *  Product: '<S263>/Product3'
       *  Product: '<S263>/Product4'
       *  Product: '<S263>/Product5'
       *  Sum: '<S263>/Add4'
       *  Sum: '<S263>/Add5'
       */
      PMSM_MC_2025a_DW.Delay1_DSTATE += ((PMSM_MC_2025a_DW.Delay1_DSTATE_k -
        PMSM_MC_2025a_DW.Delay3_DSTATE) * 23809.5 + -1904.800048828125 *
        PMSM_MC_2025a_DW.Delay1_DSTATE) * 4.9999998736893758E-5;

      /* Sum: '<S263>/Add7' incorporates:
       *  Delay: '<S263>/Delay1'
       */
      rtb_Add3 = PMSM_MC_2025a_DW.Delay1_DSTATE - rtb_Product_cc;

      /* Switch: '<S322>/Switch' incorporates:
       *  Constant: '<S322>/Constant'
       *  Product: '<S322>/Divide'
       *  RelationalOperator: '<S322>/Relational Operator'
       *  RelationalOperator: '<S322>/Relational Operator1'
       *  Switch: '<S322>/Switch1'
       */
      if (rtb_Add3 > 0.699999988079071) {
        rtb_Add3 = 1.0;
      } else if (rtb_Add3 < PMSM_MC_2025a_ConstB.Gain_n) {
        /* Switch: '<S322>/Switch1' incorporates:
         *  Constant: '<S322>/Constant1'
         */
        rtb_Add3 = -1.0;
      } else {
        rtb_Add3 /= 0.699999988079071;
      }

      /* Product: '<S322>/Product' incorporates:
       *  Delay: '<S263>/Delay3'
       *  Switch: '<S322>/Switch'
       */
      PMSM_MC_2025a_DW.Delay3_DSTATE = rtb_Add3 * 5.5;

      /* Delay: '<S320>/Delay' */
      if (PMSM_MC_2025a_DW.icLoad_i) {
        /* Sum: '<S320>/Add1' incorporates:
         *  Delay: '<S263>/Delay3'
         */
        PMSM_MC_2025a_DW.Delay_DSTATE_n = PMSM_MC_2025a_DW.Delay3_DSTATE;
      }

      /* Sum: '<S320>/Add1' incorporates:
       *  Delay: '<S263>/Delay3'
       *  Delay: '<S320>/Delay'
       *  Product: '<S320>/Product'
       *  Product: '<S320>/Product1'
       */
      PMSM_MC_2025a_DW.Delay_DSTATE_n = PMSM_MC_2025a_DW.Delay3_DSTATE *
        0.34999999403953552 + PMSM_MC_2025a_ConstB.Add_m *
        PMSM_MC_2025a_DW.Delay_DSTATE_n;

      /* Sum: '<S262>/err' incorporates:
       *  DataTypeConversion: '<S262>/Data Type Conversion'
       *  DataTypeConversion: '<S262>/Data Type Conversion1'
       *  Delay: '<S262>/Delay'
       *  Product: '<S262>/Product'
       *  Product: '<S262>/Product1'
       *  Product: '<S262>/Product2'
       *  Product: '<S262>/Product3'
       *  Trigonometry: '<S262>/Cos'
       *  Trigonometry: '<S262>/Sin'
       */
      rtb_err_g = cosf(PMSM_MC_2025a_DW.Delay_DSTATE_b) * (real32_T)
        PMSM_MC_2025a_DW.Delay_DSTATE_o * (real32_T)rtb_Minus_p + sinf
        (PMSM_MC_2025a_DW.Delay_DSTATE_b) * (real32_T)
        PMSM_MC_2025a_DW.Delay_DSTATE_n * (real32_T)rtb_Minus_p;

      /* Sum: '<S310>/Sum' incorporates:
       *  Constant: '<S262>/Constant'
       *  DiscreteIntegrator: '<S301>/Integrator'
       *  Product: '<S306>/PProd Out'
       */
      rtb_Add6 = rtb_err_g * 200.0F + PMSM_MC_2025a_DW.Integrator_DSTATE_i;

      /* Math: '<S262>/Mod' incorporates:
       *  Constant: '<S262>/Constant5'
       *  Delay: '<S262>/Delay'
       *  Gain: '<S262>/Gain'
       *  Sum: '<S262>/Add'
       */
      PMSM_MC_2025a_DW.Delay_DSTATE_b = rt_modf_snf(5.0E-5F * rtb_Add6 +
        PMSM_MC_2025a_DW.Delay_DSTATE_b, 6.28318548F);

      /* SignalConversion generated from: '<S146>/Thetae_Est' incorporates:
       *  Delay: '<S262>/Delay'
       *  Delay: '<S3>/Delay1'
       */
      PMSM_MC_2025a_DW.Delay1_DSTATE_i = PMSM_MC_2025a_DW.Delay_DSTATE_b;

      /* Delay: '<S265>/Delay' */
      if (PMSM_MC_2025a_DW.icLoad_o) {
        PMSM_MC_2025a_DW.Delay_DSTATE_ok = rtb_Add6;
      }

      /* Sum: '<S149>/Add1' incorporates:
       *  Constant: '<S262>/Constant1'
       *  Delay: '<S265>/Delay'
       *  Product: '<S265>/Product'
       *  Product: '<S265>/Product1'
       *  Sum: '<S265>/Add1'
       */
      PMSM_MC_2025a_B.Merge1 = rtb_Add6 * 0.0085F + PMSM_MC_2025a_ConstB.Add *
        PMSM_MC_2025a_DW.Delay_DSTATE_ok;

      /* Update for Delay: '<S319>/Delay' */
      PMSM_MC_2025a_DW.icLoad = false;

      /* Update for Delay: '<S320>/Delay' */
      PMSM_MC_2025a_DW.icLoad_i = false;

      /* Update for DiscreteIntegrator: '<S301>/Integrator' incorporates:
       *  Constant: '<S262>/Constant4'
       *  Product: '<S298>/IProd Out'
       */
      PMSM_MC_2025a_DW.Integrator_DSTATE_i += rtb_err_g * 10.0F;

      /* Update for Delay: '<S265>/Delay' */
      PMSM_MC_2025a_DW.icLoad_o = false;
      PMSM_MC_2025a_DW.Delay_DSTATE_ok = PMSM_MC_2025a_B.Merge1;
    }

    /* End of Outputs for SubSystem: '<S20>/SMO+PLL' */
    if (SensorLessEn_CFG) {
      rtb_Sum_j = PMSM_MC_2025a_B.Thetae_SensLess;
    } else if (rtb_Compare_gz) {
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
       *  Constant: '<S135>/Constant'
       *  Constant: '<S15>/Constant'
       *  Constant: '<S15>/Constant1'
       *  Math: '<S15>/Mod'
       *  RelationalOperator: '<S135>/Compare'
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
     *  Constant: '<S141>/Constant'
     *  Constant: '<S142>/Constant'
     *  Constant: '<S143>/Constant'
     *  Constant: '<S15>/Constant3'
     *  Constant: '<S20>/Constant'
     *  RelationalOperator: '<S141>/Compare'
     *  RelationalOperator: '<S142>/Compare'
     *  RelationalOperator: '<S143>/Compare'
     *  Signum: '<S15>/Sign'
     *  Switch: '<S15>/Switch1'
     */
    rtb_Integrator_g = cosf(rtb_Sum_j);
    rtb_Sum_j = sinf(rtb_Sum_j);

    /* Sum: '<S14>/Minus' incorporates:
     *  Constant: '<S6>/Constant'
     *  Inport: '<Root>/ACurrent_Sample'
     *  Product: '<S18>/Product'
     *  Product: '<S18>/Product1'
     *  Sum: '<S18>/Add'
     *  Trigonometry: '<S15>/SinCos'
     */
    Switch = 0.0F - (ACurrent_Sample * rtb_Integrator_g + rtb_Product_cc *
                     rtb_Sum_j);

    /* Logic: '<S14>/Logical Operator' incorporates:
     *  Constant: '<S21>/Constant'
     *  Constant: '<S24>/Constant'
     *  RelationalOperator: '<S21>/Compare'
     *  RelationalOperator: '<S24>/Compare'
     */
    rtb_Compare_gz = ((PMSM_MC_2025a_B.Switch_m == 7) ||
                      (PMSM_MC_2025a_B.Switch_m == 5));

    /* DiscreteIntegrator: '<S63>/Integrator' */
    if (rtb_Compare_gz && (PMSM_MC_2025a_DW.Integrator_PrevResetState <= 0)) {
      PMSM_MC_2025a_DW.Integrator_DSTATE = PMSM_MC_2025a_ConstB.Constant4;
      if (PMSM_MC_2025a_DW.Integrator_DSTATE > 13.0F) {
        PMSM_MC_2025a_DW.Integrator_DSTATE = 13.0F;
      } else if (PMSM_MC_2025a_DW.Integrator_DSTATE < -13.0F) {
        PMSM_MC_2025a_DW.Integrator_DSTATE = -13.0F;
      }
    }

    /* Sum: '<S72>/Sum' incorporates:
     *  Constant: '<S14>/Constant'
     *  DiscreteIntegrator: '<S63>/Integrator'
     *  Product: '<S68>/PProd Out'
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
      rtb_err_g = 1.0F;
      break;

     case 2:
      rtb_err_g = 1.0F;
      break;

     case 3:
      rtb_err_g = 0.0F;
      break;

     case 4:
      rtb_err_g = 0.0F;
      break;

     case 5:
      /* Switch: '<S27>/Switch2' incorporates:
       *  Gain: '<S14>/Gain'
       *  RelationalOperator: '<S27>/LowerRelop1'
       *  RelationalOperator: '<S27>/UpperRelop'
       *  Switch: '<S27>/Switch'
       */
      if (rtb_err_g > rtb_Add6) {
        rtb_err_g = rtb_Add6;
      } else if (rtb_err_g < -rtb_Add6) {
        /* Switch: '<S27>/Switch' incorporates:
         *  Gain: '<S14>/Gain'
         */
        rtb_err_g = -rtb_Add6;
      }
      break;

     case 6:
      rtb_err_g = 0.0F;
      break;

     case 7:
      /* Switch: '<S27>/Switch2' incorporates:
       *  Gain: '<S14>/Gain'
       *  RelationalOperator: '<S27>/LowerRelop1'
       *  RelationalOperator: '<S27>/UpperRelop'
       *  Switch: '<S27>/Switch'
       */
      if (rtb_err_g > rtb_Add6) {
        rtb_err_g = rtb_Add6;
      } else if (rtb_err_g < -rtb_Add6) {
        /* Switch: '<S27>/Switch' incorporates:
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

    /* DiscreteIntegrator: '<S115>/Integrator' */
    if (rtb_Compare_gz && (PMSM_MC_2025a_DW.Integrator_PrevResetState_c <= 0)) {
      PMSM_MC_2025a_DW.Integrator_DSTATE_j = PMSM_MC_2025a_ConstB.Constant5;
      if (PMSM_MC_2025a_DW.Integrator_DSTATE_j > 13.0F) {
        PMSM_MC_2025a_DW.Integrator_DSTATE_j = 13.0F;
      } else if (PMSM_MC_2025a_DW.Integrator_DSTATE_j < -13.0F) {
        PMSM_MC_2025a_DW.Integrator_DSTATE_j = -13.0F;
      }
    }

    /* Switch: '<S14>/Switch1' incorporates:
     *  Constant: '<S23>/Constant'
     *  RelationalOperator: '<S23>/Compare'
     *  Switch: '<S14>/Switch'
     */
    if (PMSM_MC_2025a_B.Switch_m == 7) {
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
      rtb_Sum_la = PMSM_MC_2025a_B.Switch2;
    }

    /* Sum: '<S14>/Minus1' incorporates:
     *  Inport: '<Root>/ACurrent_Sample'
     *  Product: '<S18>/Product2'
     *  Product: '<S18>/Product3'
     *  Sum: '<S18>/Add1'
     *  Switch: '<S14>/Switch1'
     *  Trigonometry: '<S15>/SinCos'
     */
    rtb_Product_cc = rtb_Sum_la - (rtb_Integrator_g * rtb_Product_cc -
      ACurrent_Sample * rtb_Sum_j);

    /* Sum: '<S124>/Sum' incorporates:
     *  Constant: '<S14>/Constant2'
     *  DiscreteIntegrator: '<S115>/Integrator'
     *  Product: '<S120>/PProd Out'
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
      /* Switch: '<S28>/Switch2' incorporates:
       *  RelationalOperator: '<S28>/LowerRelop1'
       */
      if (!(rtb_Sum_la > rtb_Add6)) {
        /* Switch: '<S28>/Switch' incorporates:
         *  Gain: '<S14>/Gain'
         *  RelationalOperator: '<S28>/UpperRelop'
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
      /* Switch: '<S28>/Switch2' incorporates:
       *  RelationalOperator: '<S28>/LowerRelop1'
       */
      if (!(rtb_Sum_la > rtb_Add6)) {
        /* Switch: '<S28>/Switch' incorporates:
         *  Gain: '<S14>/Gain'
         *  RelationalOperator: '<S28>/UpperRelop'
         */
        if (rtb_Sum_la < -rtb_Add6) {
          rtb_Add6 = -rtb_Add6;
        } else {
          rtb_Add6 = rtb_Sum_la;
        }
      }
      break;

     default:
      rtb_Add6 = 1.0F;
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

    /* Fcn: '<S137>/B' incorporates:
     *  Delay: '<S6>/Delay1'
     *  Fcn: '<S137>/C'
     */
    rtb_err_g = 0.5F * PMSM_MC_2025a_DW.Delay1_DSTATE_k;

    /* DataTypeConversion: '<S137>/Data Type Conversion' incorporates:
     *  Delay: '<S6>/Delay'
     *  Delay: '<S6>/Delay1'
     *  Fcn: '<S137>/A'
     *  Fcn: '<S137>/B'
     *  Fcn: '<S137>/C'
     *  Gain: '<S137>/Gain'
     *  Gain: '<S137>/Gain1'
     *  Sum: '<S137>/Add'
     *  Switch: '<S137>/Switch'
     *  Switch: '<S137>/Switch1'
     *  Switch: '<S137>/Switch2'
     */
    rtb_DataTypeConversion_e = (uint8_T)((int32_T)((((uint32_T)
      ((PMSM_MC_2025a_DW.Delay_DSTATE_j * 0.866025388F - rtb_err_g > 0.0F) << 7)
      + ((uint32_T)(PMSM_MC_2025a_DW.Delay1_DSTATE_k > 0.0F) << 6)) + ((uint32_T)
      ((-PMSM_MC_2025a_DW.Delay_DSTATE_j * 0.866025388F - rtb_err_g > 0.0F) << 7)
      << 1)) >> 1) >> 5);

    /* Gain: '<S140>/Gain2' incorporates:
     *  Delay: '<S6>/Delay1'
     */
    rtb_err_g = 0.866025388F * PMSM_MC_2025a_DW.Delay1_DSTATE_k;

    /* Gain: '<S140>/Gain' incorporates:
     *  Delay: '<S6>/Delay'
     */
    rtb_Add6 = 1.5F * PMSM_MC_2025a_DW.Delay_DSTATE_j;

    /* Product: '<S140>/Product3' incorporates:
     *  Fcn: '<S140>/Fcn'
     *  Inport: '<Root>/VBus_Sample'
     */
    rtb_Integrator_g = 1.0F / VBus_Sample;

    /* MultiPortSwitch: '<S138>/Multiport Switch' incorporates:
     *  Delay: '<S6>/Delay1'
     *  Gain: '<S138>/Gain'
     *  Gain: '<S138>/Gain1'
     *  Gain: '<S138>/Gain2'
     *  Gain: '<S140>/Gain1'
     *  Product: '<S140>/Product'
     *  Product: '<S140>/Product1'
     *  Product: '<S140>/Product2'
     *  Sum: '<S140>/Add'
     *  Sum: '<S140>/Add1'
     */
    switch (rtb_DataTypeConversion_e) {
     case 1:
      rtb_Sum_j = (rtb_err_g - rtb_Add6) * rtb_Integrator_g;

      /* MultiPortSwitch: '<S138>/Multiport Switch1' incorporates:
       *  Product: '<S140>/Product1'
       *  Product: '<S140>/Product2'
       *  Sum: '<S140>/Add'
       *  Sum: '<S140>/Add1'
       */
      rtb_Integrator_g *= rtb_err_g + rtb_Add6;
      break;

     case 2:
      rtb_Sum_j = (rtb_err_g + rtb_Add6) * rtb_Integrator_g;

      /* MultiPortSwitch: '<S138>/Multiport Switch1' incorporates:
       *  Delay: '<S6>/Delay1'
       *  Gain: '<S138>/Gain'
       *  Gain: '<S140>/Gain1'
       *  Product: '<S140>/Product'
       *  Product: '<S140>/Product1'
       *  Sum: '<S140>/Add'
       */
      rtb_Integrator_g = -(1.73205078F * PMSM_MC_2025a_DW.Delay1_DSTATE_k *
                           rtb_Integrator_g);
      break;

     case 3:
      rtb_Sum_j = -((rtb_err_g - rtb_Add6) * rtb_Integrator_g);

      /* MultiPortSwitch: '<S138>/Multiport Switch1' incorporates:
       *  Delay: '<S6>/Delay1'
       *  Gain: '<S138>/Gain2'
       *  Gain: '<S140>/Gain1'
       *  Product: '<S140>/Product'
       *  Product: '<S140>/Product2'
       *  Sum: '<S140>/Add1'
       */
      rtb_Integrator_g *= 1.73205078F * PMSM_MC_2025a_DW.Delay1_DSTATE_k;
      break;

     case 4:
      rtb_Sum_j = -(1.73205078F * PMSM_MC_2025a_DW.Delay1_DSTATE_k *
                    rtb_Integrator_g);

      /* MultiPortSwitch: '<S138>/Multiport Switch1' incorporates:
       *  Delay: '<S6>/Delay1'
       *  Gain: '<S138>/Gain'
       *  Gain: '<S140>/Gain1'
       *  Product: '<S140>/Product'
       *  Product: '<S140>/Product2'
       *  Sum: '<S140>/Add1'
       */
      rtb_Integrator_g *= rtb_err_g - rtb_Add6;
      break;

     case 5:
      rtb_Sum_j = 1.73205078F * PMSM_MC_2025a_DW.Delay1_DSTATE_k *
        rtb_Integrator_g;

      /* MultiPortSwitch: '<S138>/Multiport Switch1' incorporates:
       *  Delay: '<S6>/Delay1'
       *  Gain: '<S138>/Gain1'
       *  Gain: '<S140>/Gain1'
       *  Product: '<S140>/Product'
       *  Product: '<S140>/Product1'
       *  Sum: '<S140>/Add'
       */
      rtb_Integrator_g = -((rtb_err_g + rtb_Add6) * rtb_Integrator_g);
      break;

     default:
      rtb_Sum_j = -((rtb_err_g + rtb_Add6) * rtb_Integrator_g);

      /* MultiPortSwitch: '<S138>/Multiport Switch1' incorporates:
       *  Gain: '<S138>/Gain1'
       *  Gain: '<S138>/Gain2'
       *  Product: '<S140>/Product1'
       *  Product: '<S140>/Product2'
       *  Sum: '<S140>/Add'
       *  Sum: '<S140>/Add1'
       */
      rtb_Integrator_g = -((rtb_err_g - rtb_Add6) * rtb_Integrator_g);
      break;
    }

    /* End of MultiPortSwitch: '<S138>/Multiport Switch' */

    /* Switch: '<S138>/Switch' incorporates:
     *  Constant: '<S136>/Tpwm'
     *  Fcn: '<S138>/Fcn'
     *  Fcn: '<S138>/Fcn1'
     *  Fcn: '<S138>/Fcn2'
     *  Switch: '<S138>/Switch1'
     */
    if ((1.0F - rtb_Integrator_g) - rtb_Sum_j >= 0.0F) {
      rtb_Add6 = rtb_Sum_j;
      rtb_err_g = rtb_Integrator_g;
    } else {
      /* Fcn: '<S138>/Fcn' incorporates:
       *  Fcn: '<S138>/Fcn1'
       */
      rtb_err_g = rtb_Sum_j + rtb_Integrator_g;
      rtb_Add6 = rtb_Sum_j / rtb_err_g;
      rtb_err_g = rtb_Integrator_g / rtb_err_g;
    }

    /* End of Switch: '<S138>/Switch' */

    /* Abs: '<S138>/Abs' */
    rtb_Add6 = fabsf(rtb_Add6);

    /* Abs: '<S138>/Abs1' */
    rtb_err_g = fabsf(rtb_err_g);

    /* MultiPortSwitch: '<S139>/Multiport Switch' */
    switch (rtb_DataTypeConversion_e) {
     case 1:
      /* Merge: '<S3>/Merge1' incorporates:
       *  Constant: '<S136>/Tpwm'
       *  Fcn: '<S139>/Fcn1'
       */
      UVoltage_PWM = ((1.0F - rtb_Add6) + rtb_err_g) / 2.0F;

      /* Merge: '<S3>/Merge2' incorporates:
       *  Constant: '<S136>/Tpwm'
       *  Fcn: '<S139>/Fcn'
       *  MultiPortSwitch: '<S139>/Multiport Switch1'
       */
      VVoltage_PWM = ((rtb_Add6 + 1.0F) + rtb_err_g) / 2.0F;

      /* Merge: '<S3>/Merge3' incorporates:
       *  Constant: '<S136>/Tpwm'
       *  Fcn: '<S139>/Fcn2'
       *  MultiPortSwitch: '<S139>/Multiport Switch2'
       */
      WVoltage_PWM = ((1.0F - rtb_Add6) - rtb_err_g) / 2.0F;
      break;

     case 2:
      /* Merge: '<S3>/Merge1' incorporates:
       *  Constant: '<S136>/Tpwm'
       *  Fcn: '<S139>/Fcn'
       */
      UVoltage_PWM = ((rtb_Add6 + 1.0F) + rtb_err_g) / 2.0F;

      /* Merge: '<S3>/Merge2' incorporates:
       *  Constant: '<S136>/Tpwm'
       *  Fcn: '<S139>/Fcn2'
       *  MultiPortSwitch: '<S139>/Multiport Switch1'
       */
      VVoltage_PWM = ((1.0F - rtb_Add6) - rtb_err_g) / 2.0F;

      /* Merge: '<S3>/Merge3' incorporates:
       *  Constant: '<S136>/Tpwm'
       *  Fcn: '<S139>/Fcn1'
       *  MultiPortSwitch: '<S139>/Multiport Switch2'
       */
      WVoltage_PWM = ((1.0F - rtb_Add6) + rtb_err_g) / 2.0F;
      break;

     case 3:
      /* Merge: '<S3>/Merge1' incorporates:
       *  Constant: '<S136>/Tpwm'
       *  Fcn: '<S139>/Fcn'
       */
      UVoltage_PWM = ((rtb_Add6 + 1.0F) + rtb_err_g) / 2.0F;

      /* Merge: '<S3>/Merge2' incorporates:
       *  Constant: '<S136>/Tpwm'
       *  Fcn: '<S139>/Fcn1'
       *  MultiPortSwitch: '<S139>/Multiport Switch1'
       */
      VVoltage_PWM = ((1.0F - rtb_Add6) + rtb_err_g) / 2.0F;

      /* Merge: '<S3>/Merge3' incorporates:
       *  Constant: '<S136>/Tpwm'
       *  Fcn: '<S139>/Fcn2'
       *  MultiPortSwitch: '<S139>/Multiport Switch2'
       */
      WVoltage_PWM = ((1.0F - rtb_Add6) - rtb_err_g) / 2.0F;
      break;

     case 4:
      /* Merge: '<S3>/Merge1' incorporates:
       *  Constant: '<S136>/Tpwm'
       *  Fcn: '<S139>/Fcn2'
       */
      UVoltage_PWM = ((1.0F - rtb_Add6) - rtb_err_g) / 2.0F;

      /* Merge: '<S3>/Merge2' incorporates:
       *  Constant: '<S136>/Tpwm'
       *  Fcn: '<S139>/Fcn1'
       *  MultiPortSwitch: '<S139>/Multiport Switch1'
       */
      VVoltage_PWM = ((1.0F - rtb_Add6) + rtb_err_g) / 2.0F;

      /* Merge: '<S3>/Merge3' incorporates:
       *  Constant: '<S136>/Tpwm'
       *  Fcn: '<S139>/Fcn'
       *  MultiPortSwitch: '<S139>/Multiport Switch2'
       */
      WVoltage_PWM = ((rtb_Add6 + 1.0F) + rtb_err_g) / 2.0F;
      break;

     case 5:
      /* Merge: '<S3>/Merge1' incorporates:
       *  Constant: '<S136>/Tpwm'
       *  Fcn: '<S139>/Fcn2'
       */
      UVoltage_PWM = ((1.0F - rtb_Add6) - rtb_err_g) / 2.0F;

      /* Merge: '<S3>/Merge2' incorporates:
       *  Constant: '<S136>/Tpwm'
       *  Fcn: '<S139>/Fcn'
       *  MultiPortSwitch: '<S139>/Multiport Switch1'
       */
      VVoltage_PWM = ((rtb_Add6 + 1.0F) + rtb_err_g) / 2.0F;

      /* Merge: '<S3>/Merge3' incorporates:
       *  Constant: '<S136>/Tpwm'
       *  Fcn: '<S139>/Fcn1'
       *  MultiPortSwitch: '<S139>/Multiport Switch2'
       */
      WVoltage_PWM = ((1.0F - rtb_Add6) + rtb_err_g) / 2.0F;
      break;

     default:
      /* Merge: '<S3>/Merge1' incorporates:
       *  Constant: '<S136>/Tpwm'
       *  Fcn: '<S139>/Fcn1'
       */
      UVoltage_PWM = ((1.0F - rtb_Add6) + rtb_err_g) / 2.0F;

      /* Merge: '<S3>/Merge2' incorporates:
       *  Constant: '<S136>/Tpwm'
       *  Fcn: '<S139>/Fcn2'
       *  MultiPortSwitch: '<S139>/Multiport Switch1'
       */
      VVoltage_PWM = ((1.0F - rtb_Add6) - rtb_err_g) / 2.0F;

      /* Merge: '<S3>/Merge3' incorporates:
       *  Constant: '<S136>/Tpwm'
       *  Fcn: '<S139>/Fcn'
       *  MultiPortSwitch: '<S139>/Multiport Switch2'
       */
      WVoltage_PWM = ((rtb_Add6 + 1.0F) + rtb_err_g) / 2.0F;
      break;
    }

    /* End of MultiPortSwitch: '<S139>/Multiport Switch' */

    /* Update for DiscreteIntegrator: '<S63>/Integrator' incorporates:
     *  Constant: '<S14>/Constant1'
     *  Product: '<S60>/IProd Out'
     */
    PMSM_MC_2025a_DW.Integrator_DSTATE += Switch * MC_DCurrLopKi_CFG;
    if (PMSM_MC_2025a_DW.Integrator_DSTATE > 13.0F) {
      PMSM_MC_2025a_DW.Integrator_DSTATE = 13.0F;
    } else if (PMSM_MC_2025a_DW.Integrator_DSTATE < -13.0F) {
      PMSM_MC_2025a_DW.Integrator_DSTATE = -13.0F;
    }

    PMSM_MC_2025a_DW.Integrator_PrevResetState = (int8_T)rtb_Compare_gz;

    /* End of Update for DiscreteIntegrator: '<S63>/Integrator' */

    /* Update for DiscreteIntegrator: '<S115>/Integrator' incorporates:
     *  Constant: '<S14>/Constant3'
     *  Product: '<S112>/IProd Out'
     */
    PMSM_MC_2025a_DW.Integrator_DSTATE_j += rtb_Product_cc * MC_QCurrLopKi_CFG;
    if (PMSM_MC_2025a_DW.Integrator_DSTATE_j > 13.0F) {
      PMSM_MC_2025a_DW.Integrator_DSTATE_j = 13.0F;
    } else if (PMSM_MC_2025a_DW.Integrator_DSTATE_j < -13.0F) {
      PMSM_MC_2025a_DW.Integrator_DSTATE_j = -13.0F;
    }

    PMSM_MC_2025a_DW.Integrator_PrevResetState_c = (int8_T)rtb_Compare_gz;

    /* End of Update for DiscreteIntegrator: '<S115>/Integrator' */
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

  /* Update for Delay: '<S3>/Delay' */
  PMSM_MC_2025a_DW.Delay_DSTATE_c = PMSM_MC_2025a_B.Merge1;
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
  /* InitializeConditions for DiscreteIntegrator: '<S373>/Integrator' */
  PMSM_MC_2025a_DW.Integrator_DSTATE_e = PMSM_MC_2025a_ConstB.Constant;
  if (PMSM_MC_2025a_DW.Integrator_DSTATE_e > 3.0F) {
    PMSM_MC_2025a_DW.Integrator_DSTATE_e = 3.0F;
  } else if (PMSM_MC_2025a_DW.Integrator_DSTATE_e < -3.0F) {
    PMSM_MC_2025a_DW.Integrator_DSTATE_e = -3.0F;
  }

  PMSM_MC_2025a_DW.Integrator_PrevResetState_k = 2;

  /* End of InitializeConditions for DiscreteIntegrator: '<S373>/Integrator' */

  /* InitializeConditions for Delay: '<S327>/Delay' */
  PMSM_MC_2025a_DW.icLoad_c = true;

  /* InitializeConditions for Delay: '<S333>/Delay' */
  PMSM_MC_2025a_DW.icLoad_a1 = true;

  /* InitializeConditions for Delay: '<S334>/Delay' */
  PMSM_MC_2025a_DW.icLoad_e = true;

  /* SystemInitialize for Chart: '<Root>/Scheduler' incorporates:
   *  SubSystem: '<S1>/MC_HighFrqTask'
   */
  /* SystemInitialize for IfAction SubSystem: '<S3>/FOC' */
  /* InitializeConditions for DiscreteIntegrator: '<S63>/Integrator' */
  PMSM_MC_2025a_DW.Integrator_DSTATE = PMSM_MC_2025a_ConstB.Constant4;
  if (PMSM_MC_2025a_DW.Integrator_DSTATE > 13.0F) {
    PMSM_MC_2025a_DW.Integrator_DSTATE = 13.0F;
  } else if (PMSM_MC_2025a_DW.Integrator_DSTATE < -13.0F) {
    PMSM_MC_2025a_DW.Integrator_DSTATE = -13.0F;
  }

  PMSM_MC_2025a_DW.Integrator_PrevResetState = 2;

  /* End of InitializeConditions for DiscreteIntegrator: '<S63>/Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S115>/Integrator' */
  PMSM_MC_2025a_DW.Integrator_DSTATE_j = PMSM_MC_2025a_ConstB.Constant5;
  if (PMSM_MC_2025a_DW.Integrator_DSTATE_j > 13.0F) {
    PMSM_MC_2025a_DW.Integrator_DSTATE_j = 13.0F;
  } else if (PMSM_MC_2025a_DW.Integrator_DSTATE_j < -13.0F) {
    PMSM_MC_2025a_DW.Integrator_DSTATE_j = -13.0F;
  }

  PMSM_MC_2025a_DW.Integrator_PrevResetState_c = 2;

  /* End of InitializeConditions for DiscreteIntegrator: '<S115>/Integrator' */

  /* SystemInitialize for Enabled SubSystem: '<S20>/FluxObs+PLL' */
  /* InitializeConditions for Delay: '<S149>/Delay' */
  PMSM_MC_2025a_DW.icLoad_m = true;

  /* End of SystemInitialize for SubSystem: '<S20>/FluxObs+PLL' */

  /* SystemInitialize for Enabled SubSystem: '<S20>/Luenberger+PLL' */
  /* InitializeConditions for Delay: '<S205>/Delay' */
  PMSM_MC_2025a_DW.icLoad_h = true;

  /* InitializeConditions for Delay: '<S206>/Delay' */
  PMSM_MC_2025a_DW.icLoad_hx = true;

  /* InitializeConditions for Delay: '<S208>/Delay' */
  PMSM_MC_2025a_DW.icLoad_a = true;

  /* End of SystemInitialize for SubSystem: '<S20>/Luenberger+PLL' */

  /* SystemInitialize for Enabled SubSystem: '<S20>/SMO+PLL' */
  /* InitializeConditions for Delay: '<S319>/Delay' */
  PMSM_MC_2025a_DW.icLoad = true;

  /* InitializeConditions for Delay: '<S320>/Delay' */
  PMSM_MC_2025a_DW.icLoad_i = true;

  /* InitializeConditions for Delay: '<S265>/Delay' */
  PMSM_MC_2025a_DW.icLoad_o = true;

  /* End of SystemInitialize for SubSystem: '<S20>/SMO+PLL' */
  /* End of SystemInitialize for SubSystem: '<S3>/FOC' */

  /* Enable for Chart: '<Root>/Scheduler' incorporates:
   *  SubSystem: '<S1>/MC_LowFrqTask'
   */
  /* Enable for Chart: '<S326>/ModeMgr' */
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
