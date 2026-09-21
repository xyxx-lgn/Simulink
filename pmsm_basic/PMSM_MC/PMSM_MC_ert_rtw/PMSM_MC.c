/*
 * File: PMSM_MC.c
 *
 * Code generated for Simulink model 'PMSM_MC'.
 *
 * Model version                  : 1.66
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Mon Sep 21 18:07:12 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PMSM_MC.h"
#include "rtwtypes.h"
#include <math.h>
#include "PMSM_MC_private.h"
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include <float.h>

/* Named constants for Chart: '<S135>/Chart' */
#define PMSM_MC_IN_CalFailed           ((uint8_T)1U)
#define PMSM_MC_IN_Calibrate           ((uint8_T)2U)
#define PMSM_MC_IN_Calibrate1          ((uint8_T)1U)
#define PMSM_MC_IN_Calibrate2          ((uint8_T)2U)
#define PMSM_MC_IN_Init                ((uint8_T)3U)
#define PMSM_MC_IN_NO_ACTIVE_CHILD     ((uint8_T)0U)
#define PMSM_MC_IN_Normal              ((uint8_T)3U)
#define PMSM_MC_IN_RngChk              ((uint8_T)4U)
#define PMSM_MC_IN_Run                 ((uint8_T)1U)
#define PMSM_MC_IN_Stop                ((uint8_T)2U)

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
boolean_T SD_MosCtr;                   /* '<S3>/Merge' */

/* Exported block parameters */
real32_T MC_DCurrLopKi_CFG = 0.0F;     /* Variable: MC_DCurrLopKi_CFG
                                        * Referenced by: '<S13>/Constant1'
                                        */
real32_T MC_DCurrLopKp_CFG = 0.0F;     /* Variable: MC_DCurrLopKp_CFG
                                        * Referenced by: '<S13>/Constant'
                                        */
real32_T MC_QCurrLopKi_CFG = 0.0F;     /* Variable: MC_QCurrLopKi_CFG
                                        * Referenced by: '<S13>/Constant3'
                                        */
real32_T MC_QCurrLopKp_CFG = 0.0F;     /* Variable: MC_QCurrLopKp_CFG
                                        * Referenced by: '<S13>/Constant2'
                                        */
real32_T MC_SpdLopKi_CFG = 0.0F;       /* Variable: MC_SpdLopKi_CFG
                                        * Referenced by: '<S137>/Constant3'
                                        */
real32_T MC_SpdLopKp_CFG = 0.0F;       /* Variable: MC_SpdLopKp_CFG
                                        * Referenced by: '<S137>/Constant2'
                                        */
uint8_T MC_MotModeDebug_CFG = 255U;    /* Variable: MC_MotModeDebug_CFG
                                        * Referenced by: '<S135>/Constant'
                                        */
uint8_T MC_POLE_NUM_CFG = 4U;          /* Variable: MC_POLE_NUM_CFG
                                        * Referenced by:
                                        *   '<S9>/Constant'
                                        *   '<S10>/Constant'
                                        */

/* Block signals (default storage) */
B_PMSM_MC_T PMSM_MC_B;

/* Block states (default storage) */
DW_PMSM_MC_T PMSM_MC_DW;

/* Real-time model */
static RT_MODEL_PMSM_MC_T PMSM_MC_M_;
RT_MODEL_PMSM_MC_T *const PMSM_MC_M = &PMSM_MC_M_;

/* Forward declaration for local functions */
static void PMSM_MC_RangeCheck(void);
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

/* Function for Chart: '<S135>/Chart' */
static void PMSM_MC_RangeCheck(void)
{
  int32_T qY;
  if ((PMSM_MC_DW.MotOffsetBuff[0] >= 0) && (PMSM_MC_DW.MotOffsetBuff[1] <
       PMSM_MC_DW.MotOffsetBuff[0] - MAX_int32_T)) {
    qY = MAX_int32_T;
  } else if ((PMSM_MC_DW.MotOffsetBuff[0] < 0) && (PMSM_MC_DW.MotOffsetBuff[1] >
              PMSM_MC_DW.MotOffsetBuff[0] - MIN_int32_T)) {
    qY = MIN_int32_T;
  } else {
    qY = PMSM_MC_DW.MotOffsetBuff[0] - PMSM_MC_DW.MotOffsetBuff[1];
  }

  if (qY < 0) {
    if (qY <= MIN_int32_T) {
      qY = MAX_int32_T;
    } else {
      qY = -qY;
    }
  }

  if (qY > 100) {
    PMSM_MC_DW.MotCalNormal = false;
  } else {
    PMSM_MC_DW.MotCalNormal = true;
    if ((PMSM_MC_DW.MotOffsetBuff[0] < 0) && (PMSM_MC_DW.MotOffsetBuff[1] <
         MIN_int32_T - PMSM_MC_DW.MotOffsetBuff[0])) {
      qY = MIN_int32_T;
    } else if ((PMSM_MC_DW.MotOffsetBuff[0] > 0) && (PMSM_MC_DW.MotOffsetBuff[1]
                > MAX_int32_T - PMSM_MC_DW.MotOffsetBuff[0])) {
      qY = MAX_int32_T;
    } else {
      qY = PMSM_MC_DW.MotOffsetBuff[0] + PMSM_MC_DW.MotOffsetBuff[1];
    }

    PMSM_MC_B.MotOffset = qY / 2;
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

/* Model step function */
void PMSM_MC_step(void)
{
  int64m_T tmp;
  int64m_T tmp_0;
  int32_T rtb_Add_c2;
  int32_T rtb_Sign_e;
  real32_T rtb_Divide;
  real32_T rtb_Gain2_e;
  real32_T rtb_Minus1;
  real32_T rtb_Product3_l;
  real32_T rtb_Product_ik;
  real32_T rtb_Sum;
  real32_T rtb_Sum_b;
  uint32_T elapsedTicks;
  uint32_T tmp_1;
  int16_T tmp_2;
  uint8_T rtb_DataTypeConversion;
  boolean_T rtb_Compare_j;
  if (PMSM_MC_DW.counter % 16U == 15U) {
    /* Outputs for Function Call SubSystem: '<S1>/MC_LowFrqTask' */
    /* Chart: '<S135>/Chart' incorporates:
     *  Inport: '<Root>/Ecode_cnt'
     *  Inport: '<Root>/MotorSpdRef'
     */
    elapsedTicks = PMSM_MC_M->Timing.clockTick0 - PMSM_MC_DW.previousTicks;
    PMSM_MC_DW.previousTicks = PMSM_MC_M->Timing.clockTick0;
    elapsedTicks += PMSM_MC_DW.temporalCounter_i1;
    if (elapsedTicks <= 32767U) {
      PMSM_MC_DW.temporalCounter_i1 = (uint16_T)elapsedTicks;
    } else {
      PMSM_MC_DW.temporalCounter_i1 = 32767U;
    }

    if (PMSM_MC_DW.is_active_c1_PMSM_MC == 0) {
      PMSM_MC_DW.is_active_c1_PMSM_MC = 1U;
      PMSM_MC_DW.is_c1_PMSM_MC = PMSM_MC_IN_Calibrate;
      PMSM_MC_DW.is_Calibrate = PMSM_MC_IN_Init;
      PMSM_MC_B.Switch = 0U;
    } else {
      switch (PMSM_MC_DW.is_c1_PMSM_MC) {
       case PMSM_MC_IN_CalFailed:
        PMSM_MC_B.Switch = 3U;
        if (MotorSpdRef == 0) {
          PMSM_MC_DW.is_c1_PMSM_MC = PMSM_MC_IN_Calibrate;
          PMSM_MC_DW.is_Calibrate = PMSM_MC_IN_Init;
          PMSM_MC_B.Switch = 0U;
        }
        break;

       case PMSM_MC_IN_Calibrate:
        switch (PMSM_MC_DW.is_Calibrate) {
         case PMSM_MC_IN_Calibrate1:
          PMSM_MC_B.Switch = 1U;
          PMSM_MC_B.MotCalThetae = 1.046F;
          if (PMSM_MC_DW.temporalCounter_i1 >= 24000) {
            PMSM_MC_DW.temporalCounter_i1 = 0U;
            PMSM_MC_DW.is_Calibrate = PMSM_MC_IN_Calibrate2;
            if (Ecode_cnt < -2147483482) {
              PMSM_MC_DW.MotOffsetBuff[0] = MIN_int32_T;
            } else {
              PMSM_MC_DW.MotOffsetBuff[0] = Ecode_cnt - 166;
            }

            PMSM_MC_B.Switch = 2U;
            PMSM_MC_B.MotCalThetae = 2.093F;

            /* 120бу */
          }
          break;

         case PMSM_MC_IN_Calibrate2:
          PMSM_MC_B.Switch = 2U;
          PMSM_MC_B.MotCalThetae = 2.093F;
          if (PMSM_MC_DW.temporalCounter_i1 >= 24000) {
            PMSM_MC_DW.is_Calibrate = PMSM_MC_IN_RngChk;
            if (Ecode_cnt < -2147483315) {
              PMSM_MC_DW.MotOffsetBuff[1] = MIN_int32_T;
            } else {
              PMSM_MC_DW.MotOffsetBuff[1] = Ecode_cnt - 333;
            }

            PMSM_MC_RangeCheck();
          }
          break;

         case PMSM_MC_IN_Init:
          PMSM_MC_B.Switch = 0U;
          if (MotorSpdRef != 0) {
            PMSM_MC_DW.temporalCounter_i1 = 0U;
            PMSM_MC_DW.is_Calibrate = PMSM_MC_IN_Calibrate1;
            PMSM_MC_B.Switch = 1U;
            PMSM_MC_B.MotCalThetae = 1.046F;

            /* 60бу */
          }
          break;

         default:
          /* case IN_RngChk: */
          if (!PMSM_MC_DW.MotCalNormal) {
            PMSM_MC_DW.is_Calibrate = PMSM_MC_IN_NO_ACTIVE_CHILD;
            PMSM_MC_DW.is_c1_PMSM_MC = PMSM_MC_IN_CalFailed;
            PMSM_MC_B.Switch = 3U;
          } else {
            PMSM_MC_DW.is_Calibrate = PMSM_MC_IN_NO_ACTIVE_CHILD;
            PMSM_MC_DW.is_c1_PMSM_MC = PMSM_MC_IN_Normal;
            PMSM_MC_DW.is_Normal = PMSM_MC_IN_Stop;
            PMSM_MC_B.Switch = 4U;
          }
          break;
        }
        break;

       default:
        /* case IN_Normal: */
        if (PMSM_MC_DW.is_Normal == PMSM_MC_IN_Run) {
          PMSM_MC_B.Switch = 5U;
          if (MotorSpdRef == 0) {
            PMSM_MC_DW.is_Normal = PMSM_MC_IN_Stop;
            PMSM_MC_B.Switch = 4U;
          }
        } else {
          /* case IN_Stop: */
          PMSM_MC_B.Switch = 4U;
          if (MotorSpdRef != 0) {
            PMSM_MC_DW.is_Normal = PMSM_MC_IN_Run;
            PMSM_MC_B.Switch = 5U;
          }
        }
        break;
      }
    }

    /* End of Chart: '<S135>/Chart' */

    /* Switch: '<S135>/Switch' incorporates:
     *  Constant: '<S135>/Constant'
     *  Constant: '<S139>/Constant'
     *  RelationalOperator: '<S139>/Compare'
     */
    if (MC_MotModeDebug_CFG != 255) {
      /* Switch: '<S135>/Switch' */
      PMSM_MC_B.Switch = MC_MotModeDebug_CFG;
    }

    /* End of Switch: '<S135>/Switch' */

    /* RelationalOperator: '<S141>/Compare' incorporates:
     *  Constant: '<S141>/Constant'
     */
    rtb_Compare_j = (PMSM_MC_B.Switch == 5);

    /* DiscreteIntegrator: '<S179>/Integrator' */
    if (rtb_Compare_j && (PMSM_MC_DW.Integrator_PrevResetState_n <= 0)) {
      PMSM_MC_DW.Integrator_DSTATE_dr = PMSM_MC_ConstB.Constant;
      if (PMSM_MC_DW.Integrator_DSTATE_dr > 6.0F) {
        PMSM_MC_DW.Integrator_DSTATE_dr = 6.0F;
      } else if (PMSM_MC_DW.Integrator_DSTATE_dr < -6.0F) {
        PMSM_MC_DW.Integrator_DSTATE_dr = -6.0F;
      }
    }

    /* Delay: '<S136>/Delay' incorporates:
     *  Inport: '<Root>/Ecode_cnt'
     */
    if (PMSM_MC_DW.icLoad) {
      PMSM_MC_DW.Delay_DSTATE_a = Ecode_cnt;
    }

    /* Product: '<S136>/Product' incorporates:
     *  Constant: '<S136>/Constant'
     *  Constant: '<S136>/Constant1'
     *  DataTypeConversion: '<S136>/Data Type Conversion'
     *  Delay: '<S136>/Delay'
     *  Inport: '<Root>/Ecode_cnt'
     *  Product: '<S136>/Divide'
     *  Sum: '<S136>/Minus'
     */
    rtb_Product_ik = (real32_T)(Ecode_cnt - PMSM_MC_DW.Delay_DSTATE_a) / 4000.0F
      * 60000.0F;

    /* Delay: '<S140>/Delay' */
    if (PMSM_MC_DW.icLoad_d) {
      /* Sum: '<S140>/Add1' */
      PMSM_MC_DW.Delay_DSTATE = rtb_Product_ik;
    }

    /* Sum: '<S140>/Add1' incorporates:
     *  Delay: '<S140>/Delay'
     *  Product: '<S140>/Product'
     *  Product: '<S140>/Product1'
     */
    PMSM_MC_DW.Delay_DSTATE = PMSM_MC_ConstB.Add * PMSM_MC_DW.Delay_DSTATE +
      rtb_Product_ik;

    /* Switch: '<S144>/Switch2' incorporates:
     *  Constant: '<S137>/Constant4'
     *  Gain: '<S137>/Gain1'
     *  Inport: '<Root>/MotorSpdRef'
     *  RelationalOperator: '<S144>/LowerRelop1'
     *  RelationalOperator: '<S144>/UpperRelop'
     *  Switch: '<S144>/Switch'
     */
    if (MotorSpdRef > 5000) {
      tmp_2 = 5000;
    } else if ((MotorSpdRef << 15) < PMSM_MC_ConstB.Gain1) {
      /* Switch: '<S144>/Switch' incorporates:
       *  Gain: '<S137>/Gain1'
       */
      tmp_2 = (int16_T)(PMSM_MC_ConstB.Gain1 >> 15);
    } else {
      tmp_2 = MotorSpdRef;
    }

    /* Sum: '<S137>/Minus' incorporates:
     *  DataTypeConversion: '<S137>/Data Type Conversion'
     *  Switch: '<S144>/Switch2'
     */
    rtb_Product_ik = (real32_T)tmp_2 - PMSM_MC_DW.Delay_DSTATE;

    /* Sum: '<S188>/Sum' incorporates:
     *  Constant: '<S137>/Constant2'
     *  DiscreteIntegrator: '<S179>/Integrator'
     *  Product: '<S184>/PProd Out'
     */
    PMSM_MC_B.Switch2 = rtb_Product_ik * MC_SpdLopKp_CFG +
      PMSM_MC_DW.Integrator_DSTATE_dr;

    /* Switch: '<S143>/Switch2' incorporates:
     *  Constant: '<S137>/Constant1'
     *  RelationalOperator: '<S143>/LowerRelop1'
     *  RelationalOperator: '<S143>/UpperRelop'
     *  Switch: '<S143>/Switch'
     */
    if (PMSM_MC_B.Switch2 > 6.0F) {
      /* Sum: '<S188>/Sum' incorporates:
       *  Switch: '<S143>/Switch2'
       */
      PMSM_MC_B.Switch2 = 6.0F;
    } else if (PMSM_MC_B.Switch2 < PMSM_MC_ConstB.Gain) {
      /* Sum: '<S188>/Sum' incorporates:
       *  Switch: '<S143>/Switch'
       *  Switch: '<S143>/Switch2'
       */
      PMSM_MC_B.Switch2 = PMSM_MC_ConstB.Gain;
    }

    /* End of Switch: '<S143>/Switch2' */

    /* Update for DiscreteIntegrator: '<S179>/Integrator' incorporates:
     *  Constant: '<S137>/Constant3'
     *  Product: '<S176>/IProd Out'
     */
    PMSM_MC_DW.Integrator_DSTATE_dr += rtb_Product_ik * MC_SpdLopKi_CFG;
    if (PMSM_MC_DW.Integrator_DSTATE_dr > 6.0F) {
      PMSM_MC_DW.Integrator_DSTATE_dr = 6.0F;
    } else if (PMSM_MC_DW.Integrator_DSTATE_dr < -6.0F) {
      PMSM_MC_DW.Integrator_DSTATE_dr = -6.0F;
    }

    PMSM_MC_DW.Integrator_PrevResetState_n = (int8_T)rtb_Compare_j;

    /* End of Update for DiscreteIntegrator: '<S179>/Integrator' */

    /* Update for Delay: '<S136>/Delay' incorporates:
     *  Inport: '<Root>/Ecode_cnt'
     */
    PMSM_MC_DW.icLoad = false;
    PMSM_MC_DW.Delay_DSTATE_a = Ecode_cnt;

    /* Update for Delay: '<S140>/Delay' */
    PMSM_MC_DW.icLoad_d = false;

    /* End of Outputs for SubSystem: '<S1>/MC_LowFrqTask' */
  }

  /* Chart: '<Root>/Scheduler' incorporates:
   *  SubSystem: '<S1>/MC_HighFrqTask'
   */
  /* Sum: '<S5>/Add' incorporates:
   *  Inport: '<Root>/Ecode_cnt'
   */
  rtb_Add_c2 = Ecode_cnt - PMSM_MC_B.MotOffset;

  /* Signum: '<S8>/Sign' */
  if (rtb_Add_c2 < 0) {
    rtb_Sign_e = -1;
  } else {
    rtb_Sign_e = (rtb_Add_c2 > 0);
  }

  /* End of Signum: '<S8>/Sign' */

  /* If: '<S8>/If' */
  if (rtb_Sign_e == 1) {
    /* Outputs for IfAction SubSystem: '<S8>/If Action Subsystem' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* SignalConversion generated from: '<S9>/Out1' incorporates:
     *  Constant: '<S9>/Constant'
     *  Constant: '<S9>/Constant2'
     *  Constant: '<S9>/Constant3'
     *  DataTypeConversion: '<S9>/Data Type Conversion'
     *  DataTypeConversion: '<S9>/Data Type Conversion1'
     *  Math: '<S9>/Mod'
     *  Product: '<S9>/Divide'
     *  Product: '<S9>/Product'
     *  Product: '<S9>/Product1'
     */
    rtb_Product_ik = (real32_T)(rtb_Add_c2 - div_s32_floor(rtb_Add_c2, 4000) *
      4000) / 4000.0F * 6.28F * (real32_T)MC_POLE_NUM_CFG;

    /* End of Outputs for SubSystem: '<S8>/If Action Subsystem' */
  } else if (rtb_Sign_e == -1) {
    /* Outputs for IfAction SubSystem: '<S8>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* Gain: '<S10>/Gain' */
    elapsedTicks = 2147483648U;
    tmp_1 = (uint32_T)rtb_Add_c2;
    sMultiWordMul(&elapsedTicks, 1, &tmp_1, 1, &tmp_0.chunks[0U], 2);

    /* DataTypeConversion: '<S10>/Data Type Conversion3' */
    sMultiWordShr(&tmp_0.chunks[0U], 2, 31U, &tmp.chunks[0U], 2);
    rtb_Add_c2 = MultiWord2sLong(&tmp.chunks[0U]);

    /* Gain: '<S10>/Gain1' incorporates:
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
    rtb_Product_ik = -((real32_T)(rtb_Add_c2 - div_s32_floor(rtb_Add_c2, 4000) *
      4000) / 4000.0F * 6.28F * (real32_T)MC_POLE_NUM_CFG);

    /* End of Outputs for SubSystem: '<S8>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S8>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    /* SignalConversion generated from: '<S11>/Out1' incorporates:
     *  Constant: '<S11>/Constant1'
     */
    rtb_Product_ik = 0.0F;

    /* End of Outputs for SubSystem: '<S8>/If Action Subsystem2' */
  }

  /* End of If: '<S8>/If' */

  /* Outputs for IfAction SubSystem: '<S3>/FOC' incorporates:
   *  ActionPort: '<S6>/Action Port'
   */
  /* If: '<S3>/If' incorporates:
   *  Logic: '<S14>/Logical Operator'
   */
  rtb_Compare_j = ((PMSM_MC_B.Switch == 1) || (PMSM_MC_B.Switch == 2));

  /* End of Outputs for SubSystem: '<S3>/FOC' */
  if (rtb_Compare_j || (PMSM_MC_B.Switch == 5)) {
    /* Outputs for IfAction SubSystem: '<S3>/FOC' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* Merge: '<S3>/Merge' incorporates:
     *  Constant: '<S6>/Constant1'
     *  SignalConversion generated from: '<S6>/SD_MosCtr'
     */
    SD_MosCtr = true;

    /* Sum: '<S12>/Minus' incorporates:
     *  Gain: '<S12>/Gain'
     *  Gain: '<S12>/Gain1'
     *  Inport: '<Root>/BCurrent_Sample'
     *  Inport: '<Root>/CCurrent_Sample'
     */
    rtb_Sum_b = 0.57735F * BCurrent_Sample - 0.57735F * CCurrent_Sample;

    /* Switch: '<S14>/Switch1' incorporates:
     *  Signum: '<S14>/Sign'
     */
    if (rtb_Compare_j) {
      rtb_Product3_l = PMSM_MC_B.MotCalThetae;
    } else {
      if (rtb_Product_ik < 0.0F) {
        /* Signum: '<S14>/Sign' */
        rtb_Add_c2 = -1;
      } else {
        /* Signum: '<S14>/Sign' */
        rtb_Add_c2 = (rtb_Product_ik > 0.0F);
      }

      /* Switch: '<S14>/Switch' incorporates:
       *  Abs: '<S14>/Abs'
       *  Constant: '<S129>/Constant'
       *  Constant: '<S14>/Constant'
       *  Constant: '<S14>/Constant1'
       *  Math: '<S14>/Mod'
       *  RelationalOperator: '<S129>/Compare'
       *  Signum: '<S14>/Sign'
       *  Sum: '<S14>/Add'
       */
      if (rtb_Add_c2 > 0) {
        rtb_Product3_l = rt_modf_snf(fabsf(rtb_Product_ik), 6.28F);
      } else {
        rtb_Product3_l = 6.28F - rt_modf_snf(fabsf(rtb_Product_ik), 6.28F);
      }

      /* End of Switch: '<S14>/Switch' */
    }

    /* End of Switch: '<S14>/Switch1' */

    /* Trigonometry: '<S14>/SinCos' */
    rtb_Gain2_e = cosf(rtb_Product3_l);
    rtb_Product3_l = sinf(rtb_Product3_l);

    /* Sum: '<S13>/Minus' incorporates:
     *  Constant: '<S6>/Constant'
     *  Inport: '<Root>/ACurrent_Sample'
     *  Product: '<S16>/Product'
     *  Product: '<S16>/Product1'
     *  Sum: '<S16>/Add'
     *  Trigonometry: '<S14>/SinCos'
     */
    rtb_Product_ik = 0.0F - (ACurrent_Sample * rtb_Gain2_e + rtb_Sum_b *
      rtb_Product3_l);

    /* RelationalOperator: '<S18>/Compare' incorporates:
     *  Constant: '<S18>/Constant'
     */
    rtb_Compare_j = (PMSM_MC_B.Switch == 5);

    /* DiscreteIntegrator: '<S57>/Integrator' */
    if (rtb_Compare_j && (PMSM_MC_DW.Integrator_PrevResetState <= 0)) {
      PMSM_MC_DW.Integrator_DSTATE = PMSM_MC_ConstB.Constant4;
      if (PMSM_MC_DW.Integrator_DSTATE > 13.0F) {
        PMSM_MC_DW.Integrator_DSTATE = 13.0F;
      } else if (PMSM_MC_DW.Integrator_DSTATE < -13.0F) {
        PMSM_MC_DW.Integrator_DSTATE = -13.0F;
      }
    }

    /* Product: '<S13>/Divide' incorporates:
     *  Constant: '<S13>/Constant6'
     *  Inport: '<Root>/VBus_Sample'
     */
    rtb_Divide = VBus_Sample / 1.732F;

    /* MultiPortSwitch: '<S15>/Multiport Switch' incorporates:
     *  Constant: '<S15>/Constant1'
     *  Constant: '<S15>/Constant3'
     */
    switch (PMSM_MC_B.Switch) {
     case 1:
      rtb_Sum = 6.0F;
      break;

     case 2:
      rtb_Sum = 6.0F;
      break;

     case 3:
      rtb_Sum = 0.0F;
      break;

     case 4:
      rtb_Sum = 0.0F;
      break;

     default:
      /* Sum: '<S66>/Sum' incorporates:
       *  Constant: '<S13>/Constant'
       *  DiscreteIntegrator: '<S57>/Integrator'
       *  Product: '<S62>/PProd Out'
       */
      rtb_Sum = rtb_Product_ik * MC_DCurrLopKp_CFG +
        PMSM_MC_DW.Integrator_DSTATE;

      /* Switch: '<S21>/Switch2' incorporates:
       *  Gain: '<S13>/Gain'
       *  RelationalOperator: '<S21>/LowerRelop1'
       *  RelationalOperator: '<S21>/UpperRelop'
       *  Switch: '<S21>/Switch'
       */
      if (rtb_Sum > rtb_Divide) {
        rtb_Sum = rtb_Divide;
      } else if (rtb_Sum < -rtb_Divide) {
        /* Switch: '<S21>/Switch' incorporates:
         *  Gain: '<S13>/Gain'
         */
        rtb_Sum = -rtb_Divide;
      }

      /* End of Switch: '<S21>/Switch2' */
      break;
    }

    /* End of MultiPortSwitch: '<S15>/Multiport Switch' */

    /* DiscreteIntegrator: '<S109>/Integrator' */
    if (rtb_Compare_j && (PMSM_MC_DW.Integrator_PrevResetState_o <= 0)) {
      PMSM_MC_DW.Integrator_DSTATE_d = PMSM_MC_ConstB.Constant5;
      if (PMSM_MC_DW.Integrator_DSTATE_d > 13.0F) {
        PMSM_MC_DW.Integrator_DSTATE_d = 13.0F;
      } else if (PMSM_MC_DW.Integrator_DSTATE_d < -13.0F) {
        PMSM_MC_DW.Integrator_DSTATE_d = -13.0F;
      }
    }

    /* Sum: '<S13>/Minus1' incorporates:
     *  Inport: '<Root>/ACurrent_Sample'
     *  Product: '<S16>/Product2'
     *  Product: '<S16>/Product3'
     *  Sum: '<S16>/Add1'
     *  Trigonometry: '<S14>/SinCos'
     */
    rtb_Minus1 = PMSM_MC_B.Switch2 - (rtb_Gain2_e * rtb_Sum_b - ACurrent_Sample *
      rtb_Product3_l);

    /* MultiPortSwitch: '<S15>/Multiport Switch1' incorporates:
     *  Constant: '<S15>/Constant'
     */
    switch (PMSM_MC_B.Switch) {
     case 1:
      rtb_Sum_b = 0.0F;
      break;

     case 2:
      rtb_Sum_b = 0.0F;
      break;

     case 3:
      rtb_Sum_b = 0.0F;
      break;

     case 4:
      rtb_Sum_b = 0.0F;
      break;

     default:
      /* Sum: '<S118>/Sum' incorporates:
       *  Constant: '<S13>/Constant2'
       *  DiscreteIntegrator: '<S109>/Integrator'
       *  Product: '<S114>/PProd Out'
       */
      rtb_Sum_b = rtb_Minus1 * MC_QCurrLopKp_CFG +
        PMSM_MC_DW.Integrator_DSTATE_d;

      /* Switch: '<S22>/Switch2' incorporates:
       *  Gain: '<S13>/Gain'
       *  RelationalOperator: '<S22>/LowerRelop1'
       *  RelationalOperator: '<S22>/UpperRelop'
       *  Switch: '<S22>/Switch'
       */
      if (rtb_Sum_b > rtb_Divide) {
        rtb_Sum_b = rtb_Divide;
      } else if (rtb_Sum_b < -rtb_Divide) {
        /* Switch: '<S22>/Switch' incorporates:
         *  Gain: '<S13>/Gain'
         */
        rtb_Sum_b = -rtb_Divide;
      }

      /* End of Switch: '<S22>/Switch2' */
      break;
    }

    /* End of MultiPortSwitch: '<S15>/Multiport Switch1' */

    /* Sum: '<S15>/Add' incorporates:
     *  Product: '<S15>/Product1'
     *  Product: '<S15>/Product3'
     *  Trigonometry: '<S14>/SinCos'
     */
    rtb_Divide = rtb_Gain2_e * rtb_Sum_b + rtb_Sum * rtb_Product3_l;

    /* Sum: '<S15>/Minus' incorporates:
     *  Product: '<S15>/Product2'
     *  Product: '<S15>/Product4'
     *  Trigonometry: '<S14>/SinCos'
     */
    rtb_Sum = rtb_Sum * rtb_Gain2_e - rtb_Sum_b * rtb_Product3_l;

    /* Fcn: '<S131>/B' incorporates:
     *  Fcn: '<S131>/C'
     */
    rtb_Product3_l = 0.5F * rtb_Divide;

    /* DataTypeConversion: '<S131>/Data Type Conversion' incorporates:
     *  Fcn: '<S131>/A'
     *  Fcn: '<S131>/B'
     *  Fcn: '<S131>/C'
     *  Gain: '<S131>/Gain'
     *  Gain: '<S131>/Gain1'
     *  Sum: '<S131>/Add'
     *  Switch: '<S131>/Switch'
     *  Switch: '<S131>/Switch1'
     *  Switch: '<S131>/Switch2'
     */
    rtb_DataTypeConversion = (uint8_T)((int32_T)((((uint32_T)((rtb_Sum *
      0.866025388F - rtb_Product3_l > 0.0F) << 7) + ((uint32_T)(rtb_Divide >
      0.0F) << 6)) + ((uint32_T)((-rtb_Sum * 0.866025388F - rtb_Product3_l >
      0.0F) << 7) << 1)) >> 1) >> 5);

    /* Gain: '<S134>/Gain2' */
    rtb_Gain2_e = 0.866025388F * rtb_Divide;

    /* Gain: '<S134>/Gain' */
    rtb_Sum *= 1.5F;

    /* Product: '<S134>/Product3' incorporates:
     *  Fcn: '<S134>/Fcn'
     *  Inport: '<Root>/VBus_Sample'
     */
    rtb_Product3_l = 1.0F / VBus_Sample;

    /* MultiPortSwitch: '<S132>/Multiport Switch' incorporates:
     *  Gain: '<S132>/Gain'
     *  Gain: '<S132>/Gain1'
     *  Gain: '<S132>/Gain2'
     *  Gain: '<S134>/Gain1'
     *  Product: '<S134>/Product'
     *  Product: '<S134>/Product1'
     *  Product: '<S134>/Product2'
     *  Sum: '<S134>/Add'
     *  Sum: '<S134>/Add1'
     */
    switch (rtb_DataTypeConversion) {
     case 1:
      rtb_Sum_b = (rtb_Gain2_e - rtb_Sum) * rtb_Product3_l;

      /* MultiPortSwitch: '<S132>/Multiport Switch1' incorporates:
       *  Product: '<S134>/Product1'
       *  Product: '<S134>/Product2'
       *  Sum: '<S134>/Add'
       *  Sum: '<S134>/Add1'
       */
      rtb_Product3_l *= rtb_Gain2_e + rtb_Sum;
      break;

     case 2:
      rtb_Sum_b = (rtb_Gain2_e + rtb_Sum) * rtb_Product3_l;

      /* MultiPortSwitch: '<S132>/Multiport Switch1' incorporates:
       *  Gain: '<S132>/Gain'
       *  Gain: '<S134>/Gain1'
       *  Product: '<S134>/Product'
       *  Product: '<S134>/Product1'
       *  Sum: '<S134>/Add'
       */
      rtb_Product3_l = -(1.73205078F * rtb_Divide * rtb_Product3_l);
      break;

     case 3:
      rtb_Sum_b = -((rtb_Gain2_e - rtb_Sum) * rtb_Product3_l);

      /* MultiPortSwitch: '<S132>/Multiport Switch1' incorporates:
       *  Gain: '<S132>/Gain2'
       *  Gain: '<S134>/Gain1'
       *  Product: '<S134>/Product'
       *  Product: '<S134>/Product2'
       *  Sum: '<S134>/Add1'
       */
      rtb_Product3_l *= 1.73205078F * rtb_Divide;
      break;

     case 4:
      rtb_Sum_b = -(1.73205078F * rtb_Divide * rtb_Product3_l);

      /* MultiPortSwitch: '<S132>/Multiport Switch1' incorporates:
       *  Gain: '<S132>/Gain'
       *  Gain: '<S134>/Gain1'
       *  Product: '<S134>/Product'
       *  Product: '<S134>/Product2'
       *  Sum: '<S134>/Add1'
       */
      rtb_Product3_l *= rtb_Gain2_e - rtb_Sum;
      break;

     case 5:
      rtb_Sum_b = 1.73205078F * rtb_Divide * rtb_Product3_l;

      /* MultiPortSwitch: '<S132>/Multiport Switch1' incorporates:
       *  Gain: '<S132>/Gain1'
       *  Gain: '<S134>/Gain1'
       *  Product: '<S134>/Product'
       *  Product: '<S134>/Product1'
       *  Sum: '<S134>/Add'
       */
      rtb_Product3_l = -((rtb_Gain2_e + rtb_Sum) * rtb_Product3_l);
      break;

     default:
      rtb_Sum_b = -((rtb_Gain2_e + rtb_Sum) * rtb_Product3_l);

      /* MultiPortSwitch: '<S132>/Multiport Switch1' incorporates:
       *  Gain: '<S132>/Gain1'
       *  Gain: '<S132>/Gain2'
       *  Product: '<S134>/Product1'
       *  Product: '<S134>/Product2'
       *  Sum: '<S134>/Add'
       *  Sum: '<S134>/Add1'
       */
      rtb_Product3_l = -((rtb_Gain2_e - rtb_Sum) * rtb_Product3_l);
      break;
    }

    /* End of MultiPortSwitch: '<S132>/Multiport Switch' */

    /* Switch: '<S132>/Switch' incorporates:
     *  Constant: '<S130>/Tpwm'
     *  Fcn: '<S132>/Fcn'
     *  Fcn: '<S132>/Fcn1'
     *  Fcn: '<S132>/Fcn2'
     *  Switch: '<S132>/Switch1'
     */
    if ((1.0F - rtb_Product3_l) - rtb_Sum_b >= 0.0F) {
      rtb_Sum = rtb_Sum_b;
      rtb_Divide = rtb_Product3_l;
    } else {
      /* Fcn: '<S132>/Fcn' incorporates:
       *  Fcn: '<S132>/Fcn1'
       */
      rtb_Divide = rtb_Sum_b + rtb_Product3_l;
      rtb_Sum = rtb_Sum_b / rtb_Divide;
      rtb_Divide = rtb_Product3_l / rtb_Divide;
    }

    /* End of Switch: '<S132>/Switch' */

    /* Abs: '<S132>/Abs' */
    rtb_Sum = fabsf(rtb_Sum);

    /* Abs: '<S132>/Abs1' */
    rtb_Divide = fabsf(rtb_Divide);

    /* MultiPortSwitch: '<S133>/Multiport Switch' */
    switch (rtb_DataTypeConversion) {
     case 1:
      /* Merge: '<S3>/Merge1' incorporates:
       *  Constant: '<S130>/Tpwm'
       *  Fcn: '<S133>/Fcn1'
       */
      UVoltage_PWM = ((1.0F - rtb_Sum) + rtb_Divide) / 2.0F;

      /* Merge: '<S3>/Merge2' incorporates:
       *  Constant: '<S130>/Tpwm'
       *  Fcn: '<S133>/Fcn'
       *  MultiPortSwitch: '<S133>/Multiport Switch1'
       */
      VVoltage_PWM = ((rtb_Sum + 1.0F) + rtb_Divide) / 2.0F;

      /* Merge: '<S3>/Merge3' incorporates:
       *  Constant: '<S130>/Tpwm'
       *  Fcn: '<S133>/Fcn2'
       *  MultiPortSwitch: '<S133>/Multiport Switch2'
       */
      WVoltage_PWM = ((1.0F - rtb_Sum) - rtb_Divide) / 2.0F;
      break;

     case 2:
      /* Merge: '<S3>/Merge1' incorporates:
       *  Constant: '<S130>/Tpwm'
       *  Fcn: '<S133>/Fcn'
       */
      UVoltage_PWM = ((rtb_Sum + 1.0F) + rtb_Divide) / 2.0F;

      /* Merge: '<S3>/Merge2' incorporates:
       *  Constant: '<S130>/Tpwm'
       *  Fcn: '<S133>/Fcn2'
       *  MultiPortSwitch: '<S133>/Multiport Switch1'
       */
      VVoltage_PWM = ((1.0F - rtb_Sum) - rtb_Divide) / 2.0F;

      /* Merge: '<S3>/Merge3' incorporates:
       *  Constant: '<S130>/Tpwm'
       *  Fcn: '<S133>/Fcn1'
       *  MultiPortSwitch: '<S133>/Multiport Switch2'
       */
      WVoltage_PWM = ((1.0F - rtb_Sum) + rtb_Divide) / 2.0F;
      break;

     case 3:
      /* Merge: '<S3>/Merge1' incorporates:
       *  Constant: '<S130>/Tpwm'
       *  Fcn: '<S133>/Fcn'
       */
      UVoltage_PWM = ((rtb_Sum + 1.0F) + rtb_Divide) / 2.0F;

      /* Merge: '<S3>/Merge2' incorporates:
       *  Constant: '<S130>/Tpwm'
       *  Fcn: '<S133>/Fcn1'
       *  MultiPortSwitch: '<S133>/Multiport Switch1'
       */
      VVoltage_PWM = ((1.0F - rtb_Sum) + rtb_Divide) / 2.0F;

      /* Merge: '<S3>/Merge3' incorporates:
       *  Constant: '<S130>/Tpwm'
       *  Fcn: '<S133>/Fcn2'
       *  MultiPortSwitch: '<S133>/Multiport Switch2'
       */
      WVoltage_PWM = ((1.0F - rtb_Sum) - rtb_Divide) / 2.0F;
      break;

     case 4:
      /* Merge: '<S3>/Merge1' incorporates:
       *  Constant: '<S130>/Tpwm'
       *  Fcn: '<S133>/Fcn2'
       */
      UVoltage_PWM = ((1.0F - rtb_Sum) - rtb_Divide) / 2.0F;

      /* Merge: '<S3>/Merge2' incorporates:
       *  Constant: '<S130>/Tpwm'
       *  Fcn: '<S133>/Fcn1'
       *  MultiPortSwitch: '<S133>/Multiport Switch1'
       */
      VVoltage_PWM = ((1.0F - rtb_Sum) + rtb_Divide) / 2.0F;

      /* Merge: '<S3>/Merge3' incorporates:
       *  Constant: '<S130>/Tpwm'
       *  Fcn: '<S133>/Fcn'
       *  MultiPortSwitch: '<S133>/Multiport Switch2'
       */
      WVoltage_PWM = ((rtb_Sum + 1.0F) + rtb_Divide) / 2.0F;
      break;

     case 5:
      /* Merge: '<S3>/Merge1' incorporates:
       *  Constant: '<S130>/Tpwm'
       *  Fcn: '<S133>/Fcn2'
       */
      UVoltage_PWM = ((1.0F - rtb_Sum) - rtb_Divide) / 2.0F;

      /* Merge: '<S3>/Merge2' incorporates:
       *  Constant: '<S130>/Tpwm'
       *  Fcn: '<S133>/Fcn'
       *  MultiPortSwitch: '<S133>/Multiport Switch1'
       */
      VVoltage_PWM = ((rtb_Sum + 1.0F) + rtb_Divide) / 2.0F;

      /* Merge: '<S3>/Merge3' incorporates:
       *  Constant: '<S130>/Tpwm'
       *  Fcn: '<S133>/Fcn1'
       *  MultiPortSwitch: '<S133>/Multiport Switch2'
       */
      WVoltage_PWM = ((1.0F - rtb_Sum) + rtb_Divide) / 2.0F;
      break;

     default:
      /* Merge: '<S3>/Merge1' incorporates:
       *  Constant: '<S130>/Tpwm'
       *  Fcn: '<S133>/Fcn1'
       */
      UVoltage_PWM = ((1.0F - rtb_Sum) + rtb_Divide) / 2.0F;

      /* Merge: '<S3>/Merge2' incorporates:
       *  Constant: '<S130>/Tpwm'
       *  Fcn: '<S133>/Fcn2'
       *  MultiPortSwitch: '<S133>/Multiport Switch1'
       */
      VVoltage_PWM = ((1.0F - rtb_Sum) - rtb_Divide) / 2.0F;

      /* Merge: '<S3>/Merge3' incorporates:
       *  Constant: '<S130>/Tpwm'
       *  Fcn: '<S133>/Fcn'
       *  MultiPortSwitch: '<S133>/Multiport Switch2'
       */
      WVoltage_PWM = ((rtb_Sum + 1.0F) + rtb_Divide) / 2.0F;
      break;
    }

    /* End of MultiPortSwitch: '<S133>/Multiport Switch' */

    /* Update for DiscreteIntegrator: '<S57>/Integrator' incorporates:
     *  Constant: '<S13>/Constant1'
     *  Product: '<S54>/IProd Out'
     */
    PMSM_MC_DW.Integrator_DSTATE += rtb_Product_ik * MC_DCurrLopKi_CFG;
    if (PMSM_MC_DW.Integrator_DSTATE > 13.0F) {
      PMSM_MC_DW.Integrator_DSTATE = 13.0F;
    } else if (PMSM_MC_DW.Integrator_DSTATE < -13.0F) {
      PMSM_MC_DW.Integrator_DSTATE = -13.0F;
    }

    PMSM_MC_DW.Integrator_PrevResetState = (int8_T)rtb_Compare_j;

    /* End of Update for DiscreteIntegrator: '<S57>/Integrator' */

    /* Update for DiscreteIntegrator: '<S109>/Integrator' incorporates:
     *  Constant: '<S13>/Constant3'
     *  Product: '<S106>/IProd Out'
     */
    PMSM_MC_DW.Integrator_DSTATE_d += rtb_Minus1 * MC_QCurrLopKi_CFG;
    if (PMSM_MC_DW.Integrator_DSTATE_d > 13.0F) {
      PMSM_MC_DW.Integrator_DSTATE_d = 13.0F;
    } else if (PMSM_MC_DW.Integrator_DSTATE_d < -13.0F) {
      PMSM_MC_DW.Integrator_DSTATE_d = -13.0F;
    }

    PMSM_MC_DW.Integrator_PrevResetState_o = (int8_T)rtb_Compare_j;

    /* End of Update for DiscreteIntegrator: '<S109>/Integrator' */
    /* End of Outputs for SubSystem: '<S3>/FOC' */
  } else {
    /* Outputs for IfAction SubSystem: '<S3>/Stop' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* Merge: '<S3>/Merge' incorporates:
     *  Constant: '<S7>/Constant1'
     *  SignalConversion generated from: '<S7>/SD_MosCtr'
     */
    SD_MosCtr = false;

    /* Merge: '<S3>/Merge1' incorporates:
     *  Constant: '<S7>/Constant'
     *  SignalConversion generated from: '<S7>/UVoltage_PWM'
     */
    UVoltage_PWM = 0.0F;

    /* Merge: '<S3>/Merge2' incorporates:
     *  Constant: '<S7>/Constant'
     *  SignalConversion generated from: '<S7>/VVoltage_PWM'
     */
    VVoltage_PWM = 0.0F;

    /* Merge: '<S3>/Merge3' incorporates:
     *  Constant: '<S7>/Constant'
     *  SignalConversion generated from: '<S7>/WVoltage_PWM'
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
  if (PMSM_MC_DW.counter >= 100000000U) {
    PMSM_MC_DW.counter = 0U;
  } else {
    PMSM_MC_DW.counter++;
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 6.25E-5, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  PMSM_MC_M->Timing.clockTick0++;
}

/* Model initialize function */
void PMSM_MC_initialize(void)
{
  /* SystemInitialize for Chart: '<Root>/Scheduler' incorporates:
   *  SubSystem: '<S1>/MC_LowFrqTask'
   */
  /* InitializeConditions for DiscreteIntegrator: '<S179>/Integrator' */
  PMSM_MC_DW.Integrator_DSTATE_dr = PMSM_MC_ConstB.Constant;
  if (PMSM_MC_DW.Integrator_DSTATE_dr > 6.0F) {
    PMSM_MC_DW.Integrator_DSTATE_dr = 6.0F;
  } else if (PMSM_MC_DW.Integrator_DSTATE_dr < -6.0F) {
    PMSM_MC_DW.Integrator_DSTATE_dr = -6.0F;
  }

  PMSM_MC_DW.Integrator_PrevResetState_n = 2;

  /* End of InitializeConditions for DiscreteIntegrator: '<S179>/Integrator' */

  /* InitializeConditions for Delay: '<S136>/Delay' */
  PMSM_MC_DW.icLoad = true;

  /* InitializeConditions for Delay: '<S140>/Delay' */
  PMSM_MC_DW.icLoad_d = true;

  /* SystemInitialize for Chart: '<Root>/Scheduler' incorporates:
   *  SubSystem: '<S1>/MC_HighFrqTask'
   */
  /* SystemInitialize for IfAction SubSystem: '<S3>/FOC' */
  /* InitializeConditions for DiscreteIntegrator: '<S57>/Integrator' */
  PMSM_MC_DW.Integrator_DSTATE = PMSM_MC_ConstB.Constant4;
  if (PMSM_MC_DW.Integrator_DSTATE > 13.0F) {
    PMSM_MC_DW.Integrator_DSTATE = 13.0F;
  } else if (PMSM_MC_DW.Integrator_DSTATE < -13.0F) {
    PMSM_MC_DW.Integrator_DSTATE = -13.0F;
  }

  PMSM_MC_DW.Integrator_PrevResetState = 2;

  /* End of InitializeConditions for DiscreteIntegrator: '<S57>/Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S109>/Integrator' */
  PMSM_MC_DW.Integrator_DSTATE_d = PMSM_MC_ConstB.Constant5;
  if (PMSM_MC_DW.Integrator_DSTATE_d > 13.0F) {
    PMSM_MC_DW.Integrator_DSTATE_d = 13.0F;
  } else if (PMSM_MC_DW.Integrator_DSTATE_d < -13.0F) {
    PMSM_MC_DW.Integrator_DSTATE_d = -13.0F;
  }

  PMSM_MC_DW.Integrator_PrevResetState_o = 2;

  /* End of InitializeConditions for DiscreteIntegrator: '<S109>/Integrator' */
  /* End of SystemInitialize for SubSystem: '<S3>/FOC' */

  /* Enable for Chart: '<Root>/Scheduler' incorporates:
   *  SubSystem: '<S1>/MC_LowFrqTask'
   */
  /* Enable for Chart: '<S135>/Chart' */
  PMSM_MC_DW.previousTicks = PMSM_MC_M->Timing.clockTick0;
}

/* Model terminate function */
void PMSM_MC_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
