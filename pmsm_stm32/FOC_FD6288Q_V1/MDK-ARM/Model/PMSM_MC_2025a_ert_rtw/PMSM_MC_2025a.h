/*
 * File: PMSM_MC_2025a.h
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

#ifndef PMSM_MC_2025a_h_
#define PMSM_MC_2025a_h_
#ifndef PMSM_MC_2025a_COMMON_INCLUDES_
#define PMSM_MC_2025a_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* PMSM_MC_2025a_COMMON_INCLUDES_ */

#include "PMSM_MC_2025a_types.h"
#include "rtGetNaN.h"
#include <math.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real32_T Thetae_SensLess;            /* '<S7>/OpenLopThetaeCal' */
  real32_T Merge1;                     /* '<S20>/Merge1' */
  real32_T Switch2;                    /* '<S337>/Switch2' */
  real32_T MotCalThetae;               /* '<S326>/ModeMgr' */
  int32_T MotOffset;                   /* '<S326>/ModeMgr' */
  uint8_T Switch_m;                    /* '<S326>/Switch' */
  boolean_T OLStartCompletedFlag;      /* '<S7>/OpenLopThetaeCal' */
} B_PMSM_MC_2025a_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<S263>/Delay' */
  real_T Delay2_DSTATE;                /* '<S263>/Delay2' */
  real_T Delay_DSTATE_o;               /* '<S319>/Delay' */
  real_T Delay1_DSTATE;                /* '<S263>/Delay1' */
  real_T Delay3_DSTATE;                /* '<S263>/Delay3' */
  real_T Delay_DSTATE_n;               /* '<S320>/Delay' */
  real32_T Delay_DSTATE_c;             /* '<S3>/Delay' */
  real32_T Delay1_DSTATE_i;            /* '<S3>/Delay1' */
  real32_T Delay_DSTATE_j;             /* '<S6>/Delay' */
  real32_T Delay1_DSTATE_k;            /* '<S6>/Delay1' */
  real32_T Integrator_DSTATE;          /* '<S63>/Integrator' */
  real32_T Integrator_DSTATE_j;        /* '<S115>/Integrator' */
  real32_T Delay_DSTATE_b;             /* '<S262>/Delay' */
  real32_T Integrator_DSTATE_i;        /* '<S301>/Integrator' */
  real32_T Delay_DSTATE_ok;            /* '<S265>/Delay' */
  real32_T Delay_DSTATE_d;             /* '<S145>/Delay' */
  real32_T Delay3_DSTATE_e;            /* '<S203>/Delay3' */
  real32_T Delay1_DSTATE_p;            /* '<S203>/Delay1' */
  real32_T Delay_DSTATE_n4;            /* '<S203>/Delay' */
  real32_T Delay_DSTATE_jn;            /* '<S205>/Delay' */
  real32_T Delay_DSTATE_h;             /* '<S204>/Delay' */
  real32_T Delay2_DSTATE_d;            /* '<S203>/Delay2' */
  real32_T Delay_DSTATE_dq;            /* '<S206>/Delay' */
  real32_T Integrator_DSTATE_m;        /* '<S244>/Integrator' */
  real32_T Delay_DSTATE_k;             /* '<S208>/Delay' */
  real32_T Delay2_DSTATE_f;            /* '<S147>/Delay2' */
  real32_T Delay3_DSTATE_c;            /* '<S147>/Delay3' */
  real32_T Delay_DSTATE_i;             /* '<S147>/Delay' */
  real32_T Delay_DSTATE_p;             /* '<S148>/Delay' */
  real32_T Delay1_DSTATE_o;            /* '<S147>/Delay1' */
  real32_T Integrator_DSTATE_l;        /* '<S185>/Integrator' */
  real32_T Delay_DSTATE_e;             /* '<S149>/Delay' */
  real32_T Integrator_DSTATE_e;        /* '<S373>/Integrator' */
  real32_T Delay_DSTATE_pq;            /* '<S333>/Delay' */
  real32_T Delay_DSTATE_a;             /* '<S334>/Delay' */
  int32_T Delay_DSTATE_h5;             /* '<S327>/Delay' */
  real32_T WeRefRamped;                /* '<S7>/OpenLopThetaeCal' */
  real32_T Thetae_OL;                  /* '<S7>/OpenLopThetaeCal' */
  real32_T TransmStep;                 /* '<S7>/OpenLopThetaeCal' */
  real32_T TransmFactor;               /* '<S7>/OpenLopThetaeCal' */
  int32_T MotOffsetBuff[2];            /* '<S326>/ModeMgr' */
  uint32_T counter;                    /* '<Root>/Scheduler' */
  uint32_T previousTicks;              /* '<S7>/OpenLopThetaeCal' */
  uint32_T previousTicks_h;            /* '<S326>/ModeMgr' */
  uint16_T OLStableCnt;                /* '<S7>/OpenLopThetaeCal' */
  uint16_T temporalCounter_i1;         /* '<S7>/OpenLopThetaeCal' */
  uint16_T temporalCounter_i1_j;       /* '<S326>/ModeMgr' */
  int8_T Integrator_PrevResetState;    /* '<S63>/Integrator' */
  int8_T Integrator_PrevResetState_c;  /* '<S115>/Integrator' */
  int8_T Integrator_PrevResetState_k;  /* '<S373>/Integrator' */
  uint8_T is_active_c2_PMSM_MC_2025a;  /* '<S7>/OpenLopThetaeCal' */
  uint8_T is_c2_PMSM_MC_2025a;         /* '<S7>/OpenLopThetaeCal' */
  uint8_T is_IFStart;                  /* '<S7>/OpenLopThetaeCal' */
  uint8_T is_VFOpenLoop;               /* '<S7>/OpenLopThetaeCal' */
  uint8_T is_active_c1_PMSM_MC_2025a;  /* '<S326>/ModeMgr' */
  uint8_T is_c1_PMSM_MC_2025a;         /* '<S326>/ModeMgr' */
  uint8_T is_SensorCtr;                /* '<S326>/ModeMgr' */
  uint8_T is_Calibrate;                /* '<S326>/ModeMgr' */
  uint8_T is_Normal;                   /* '<S326>/ModeMgr' */
  uint8_T is_SensorLessCtr;            /* '<S326>/ModeMgr' */
  boolean_T icLoad;                    /* '<S319>/Delay' */
  boolean_T icLoad_i;                  /* '<S320>/Delay' */
  boolean_T icLoad_o;                  /* '<S265>/Delay' */
  boolean_T icLoad_h;                  /* '<S205>/Delay' */
  boolean_T icLoad_hx;                 /* '<S206>/Delay' */
  boolean_T icLoad_a;                  /* '<S208>/Delay' */
  boolean_T icLoad_m;                  /* '<S149>/Delay' */
  boolean_T icLoad_c;                  /* '<S327>/Delay' */
  boolean_T icLoad_a1;                 /* '<S333>/Delay' */
  boolean_T icLoad_e;                  /* '<S334>/Delay' */
  boolean_T MotCalNormal;              /* '<S326>/ModeMgr' */
} DW_PMSM_MC_2025a_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T Gain;                 /* '<S7>/Gain' */
  const real32_T Gain1;                /* '<S7>/Gain1' */
  const real32_T Gain2;                /* '<S7>/Gain2' */
  const real32_T Gain3;                /* '<S7>/Gain3' */
  const real32_T Constant4;            /* '<S14>/Constant4' */
  const real32_T Constant5;            /* '<S14>/Constant5' */
  const real32_T Gain1_j;              /* '<S14>/Gain1' */
  const real32_T Add;                  /* '<S265>/Add' */
  const real32_T Add_c;                /* '<S319>/Add' */
  const real32_T Add_m;                /* '<S320>/Add' */
  const real32_T Gain_a;               /* '<S321>/Gain' */
  const real32_T Gain_n;               /* '<S322>/Gain' */
  const real32_T MathFunction;         /* '<S203>/Math Function' */
  const real32_T uLs;                  /* '<S203>/4*Ls' */
  const real32_T uRs;                  /* '<S203>/4*Rs' */
  const real32_T Gain_f;               /* '<S203>/Gain' */
  const real32_T Add_i;                /* '<S203>/Add' */
  const real32_T k1;                   /* '<S203>/Add1' */
  const real32_T Add_p;                /* '<S205>/Add' */
  const real32_T Add_b;                /* '<S206>/Add' */
  const real32_T Ts;                   /* '<S203>/Ts' */
  const real32_T Ts4;                  /* '<S203>/Ts4' */
  const real32_T Add_f;                /* '<S208>/Add' */
  const real32_T MathFunction2;        /* '<S147>/Math Function2' */
  const real32_T Add_f5;               /* '<S149>/Add' */
  const real32_T Add_k;                /* '<S333>/Add' */
  const real32_T Add_iy;               /* '<S334>/Add' */
  const real32_T Constant;             /* '<S328>/Constant' */
  const real32_T Gain_k;               /* '<S328>/Gain' */
  const int32_T Gain1_g;               /* '<S328>/Gain1' */
} ConstB_PMSM_MC_2025a_T;

/* Real-time Model Data Structure */
struct tag_RTM_PMSM_MC_2025a_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
  } Timing;
};

/* Block signals (default storage) */
extern B_PMSM_MC_2025a_T PMSM_MC_2025a_B;

/* Block states (default storage) */
extern DW_PMSM_MC_2025a_T PMSM_MC_2025a_DW;
extern const ConstB_PMSM_MC_2025a_T PMSM_MC_2025a_ConstB;/* constant block i/o */

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real32_T ACurrent_Sample;       /* '<Root>/ACurrent_Sample' */
extern real32_T BCurrent_Sample;       /* '<Root>/BCurrent_Sample' */
extern real32_T CCurrent_Sample;       /* '<Root>/CCurrent_Sample' */
extern int32_T Ecode_cnt;              /* '<Root>/Ecode_cnt' */
extern int16_T MotorSpdRef;            /* '<Root>/MotorSpdRef' */
extern real32_T VBus_Sample;           /* '<Root>/VBus_Sample' */
extern real32_T UVoltage_PWM;          /* '<S3>/Saturation' */
extern real32_T VVoltage_PWM;          /* '<S3>/Saturation1' */
extern real32_T WVoltage_PWM;          /* '<S3>/Saturation2' */
extern real32_T MotorActSpd_Encode;    /* '<S333>/Add1' */
extern real32_T MotorActSpd_Est;       /* '<S334>/Add1' */
extern real32_T MotorActSpd;           /* '<S327>/Switch' */
extern boolean_T SD_MosCtr;            /* '<S3>/Merge' */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real32_T MC_DCurrLopKi_CFG;     /* Variable: MC_DCurrLopKi_CFG
                                        * Referenced by: '<S14>/Constant1'
                                        */
extern real32_T MC_DCurrLopKp_CFG;     /* Variable: MC_DCurrLopKp_CFG
                                        * Referenced by: '<S14>/Constant'
                                        */
extern real32_T MC_QCurrLopKi_CFG;     /* Variable: MC_QCurrLopKi_CFG
                                        * Referenced by: '<S14>/Constant3'
                                        */
extern real32_T MC_QCurrLopKp_CFG;     /* Variable: MC_QCurrLopKp_CFG
                                        * Referenced by: '<S14>/Constant2'
                                        */
extern real32_T MC_SpdLopKi_CFG;       /* Variable: MC_SpdLopKi_CFG
                                        * Referenced by: '<S328>/Constant3'
                                        */
extern real32_T MC_SpdLopKp_CFG;       /* Variable: MC_SpdLopKp_CFG
                                        * Referenced by: '<S328>/Constant2'
                                        */
extern boolean_T OpenLoopEn_CFG;       /* Variable: OpenLoopEn_CFG
                                        * Referenced by: '<S326>/Constant2'
                                        */
extern boolean_T SensorLessEn_CFG;     /* Variable: SensorLessEn_CFG
                                        * Referenced by:
                                        *   '<S326>/Constant1'
                                        *   '<S327>/Constant5'
                                        *   '<S15>/Constant3'
                                        */
extern uint8_T MC_MotModeDebug_CFG;    /* Variable: MC_MotModeDebug_CFG
                                        * Referenced by: '<S326>/Constant'
                                        */
extern uint8_T MC_POLE_NUM_CFG;        /* Variable: MC_POLE_NUM_CFG
                                        * Referenced by:
                                        *   '<S10>/Constant'
                                        *   '<S11>/Constant'
                                        */
extern uint8_T SensorLessType_CFG;     /* Variable: SensorLessType_CFG
                                        * Referenced by: '<S20>/Constant'
                                        */

/* Model entry point functions */
extern void PMSM_MC_2025a_initialize(void);
extern void PMSM_MC_2025a_step(void);
extern void PMSM_MC_2025a_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PMSM_MC_2025a_T *const PMSM_MC_2025a_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S6>/Constant2' : Unused code path elimination
 * Block '<S6>/Constant3' : Unused code path elimination
 * Block '<S27>/Data Type Duplicate' : Unused code path elimination
 * Block '<S27>/Data Type Propagation' : Unused code path elimination
 * Block '<S28>/Data Type Duplicate' : Unused code path elimination
 * Block '<S28>/Data Type Propagation' : Unused code path elimination
 * Block '<S14>/Scope' : Unused code path elimination
 * Block '<S14>/Scope1' : Unused code path elimination
 * Block '<S147>/Atan2' : Unused code path elimination
 * Block '<S147>/Scope' : Unused code path elimination
 * Block '<S148>/PI_Out' : Unused code path elimination
 * Block '<S148>/erro' : Unused code path elimination
 * Block '<S203>/Scope' : Unused code path elimination
 * Block '<S263>/Scope' : Unused code path elimination
 * Block '<S263>/Scope1' : Unused code path elimination
 * Block '<S263>/Scope2' : Unused code path elimination
 * Block '<S263>/Scope3' : Unused code path elimination
 * Block '<S263>/Scope4' : Unused code path elimination
 * Block '<S3>/Scope' : Unused code path elimination
 * Block '<S337>/Data Type Duplicate' : Unused code path elimination
 * Block '<S337>/Data Type Propagation' : Unused code path elimination
 * Block '<S338>/Data Type Duplicate' : Unused code path elimination
 * Block '<S338>/Data Type Propagation' : Unused code path elimination
 * Block '<S10>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S11>/Data Type Conversion2' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'PMSM_MC_2025a'
 * '<S1>'   : 'PMSM_MC_2025a/PMSM_MC'
 * '<S2>'   : 'PMSM_MC_2025a/Scheduler'
 * '<S3>'   : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask'
 * '<S4>'   : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask'
 * '<S5>'   : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/ElecAngleCal'
 * '<S6>'   : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC'
 * '<S7>'   : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/OpenLopMod'
 * '<S8>'   : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/Stop'
 * '<S9>'   : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/ElecAngleCal/AngleCal'
 * '<S10>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/ElecAngleCal/AngleCal/If Action Subsystem'
 * '<S11>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/ElecAngleCal/AngleCal/If Action Subsystem1'
 * '<S12>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/ElecAngleCal/AngleCal/If Action Subsystem2'
 * '<S13>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/Clark'
 * '<S14>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop'
 * '<S15>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/ElecAgCorrect'
 * '<S16>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/FOCInfo'
 * '<S17>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/IPark'
 * '<S18>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/Park'
 * '<S19>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SVPWM'
 * '<S20>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm'
 * '<S21>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Compare To Constant'
 * '<S22>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Compare To Constant1'
 * '<S23>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Compare To Constant2'
 * '<S24>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Compare To Constant3'
 * '<S25>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller'
 * '<S26>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1'
 * '<S27>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Saturation Dynamic'
 * '<S28>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Saturation Dynamic1'
 * '<S29>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Anti-windup'
 * '<S30>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/D Gain'
 * '<S31>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/External Derivative'
 * '<S32>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Filter'
 * '<S33>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Filter ICs'
 * '<S34>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/I Gain'
 * '<S35>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Ideal P Gain'
 * '<S36>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S37>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Integrator'
 * '<S38>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Integrator ICs'
 * '<S39>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/N Copy'
 * '<S40>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/N Gain'
 * '<S41>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/P Copy'
 * '<S42>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Parallel P Gain'
 * '<S43>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Reset Signal'
 * '<S44>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Saturation'
 * '<S45>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Saturation Fdbk'
 * '<S46>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Sum'
 * '<S47>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Sum Fdbk'
 * '<S48>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Tracking Mode'
 * '<S49>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Tracking Mode Sum'
 * '<S50>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Tsamp - Integral'
 * '<S51>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Tsamp - Ngain'
 * '<S52>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/postSat Signal'
 * '<S53>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/preInt Signal'
 * '<S54>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/preSat Signal'
 * '<S55>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S56>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/D Gain/Disabled'
 * '<S57>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/External Derivative/Disabled'
 * '<S58>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Filter/Disabled'
 * '<S59>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Filter ICs/Disabled'
 * '<S60>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/I Gain/External Parameters'
 * '<S61>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S62>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S63>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Integrator/Discrete'
 * '<S64>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Integrator ICs/External IC'
 * '<S65>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S66>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/N Gain/Disabled'
 * '<S67>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/P Copy/Disabled'
 * '<S68>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Parallel P Gain/External Parameters'
 * '<S69>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Reset Signal/External Reset'
 * '<S70>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Saturation/Passthrough'
 * '<S71>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S72>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Sum/Sum_PI'
 * '<S73>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S74>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S75>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S76>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S77>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S78>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S79>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/preInt Signal/Internal PreInt'
 * '<S80>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S81>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Anti-windup'
 * '<S82>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/D Gain'
 * '<S83>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/External Derivative'
 * '<S84>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Filter'
 * '<S85>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Filter ICs'
 * '<S86>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/I Gain'
 * '<S87>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Ideal P Gain'
 * '<S88>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S89>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Integrator'
 * '<S90>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Integrator ICs'
 * '<S91>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/N Copy'
 * '<S92>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/N Gain'
 * '<S93>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/P Copy'
 * '<S94>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Parallel P Gain'
 * '<S95>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Reset Signal'
 * '<S96>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Saturation'
 * '<S97>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Saturation Fdbk'
 * '<S98>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Sum'
 * '<S99>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Sum Fdbk'
 * '<S100>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Tracking Mode'
 * '<S101>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Tracking Mode Sum'
 * '<S102>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Tsamp - Integral'
 * '<S103>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Tsamp - Ngain'
 * '<S104>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/postSat Signal'
 * '<S105>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/preInt Signal'
 * '<S106>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/preSat Signal'
 * '<S107>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Anti-windup/Passthrough'
 * '<S108>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/D Gain/Disabled'
 * '<S109>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/External Derivative/Disabled'
 * '<S110>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Filter/Disabled'
 * '<S111>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Filter ICs/Disabled'
 * '<S112>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/I Gain/External Parameters'
 * '<S113>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S114>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S115>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Integrator/Discrete'
 * '<S116>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Integrator ICs/External IC'
 * '<S117>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S118>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/N Gain/Disabled'
 * '<S119>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/P Copy/Disabled'
 * '<S120>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Parallel P Gain/External Parameters'
 * '<S121>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Reset Signal/External Reset'
 * '<S122>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Saturation/Passthrough'
 * '<S123>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S124>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Sum/Sum_PI'
 * '<S125>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S126>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S127>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S128>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S129>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S130>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S131>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/preInt Signal/Internal PreInt'
 * '<S132>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S133>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/ElecAgCorrect/Compare To Constant'
 * '<S134>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/ElecAgCorrect/Compare To Constant1'
 * '<S135>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/ElecAgCorrect/Compare To Constant2'
 * '<S136>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SVPWM/SevenSegSVPWM'
 * '<S137>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SVPWM/SevenSegSVPWM/SectorCaculate'
 * '<S138>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SVPWM/SevenSegSVPWM/T1T2Caculate'
 * '<S139>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SVPWM/SevenSegSVPWM/TcmCaculate'
 * '<S140>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SVPWM/SevenSegSVPWM/XYZCaculate'
 * '<S141>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Compare To Constant1'
 * '<S142>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Compare To Constant2'
 * '<S143>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Compare To Constant3'
 * '<S144>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL'
 * '<S145>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL'
 * '<S146>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL'
 * '<S147>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/FluxObs'
 * '<S148>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL'
 * '<S149>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/LPF'
 * '<S150>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI'
 * '<S151>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Anti-windup'
 * '<S152>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/D Gain'
 * '<S153>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/External Derivative'
 * '<S154>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Filter'
 * '<S155>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Filter ICs'
 * '<S156>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/I Gain'
 * '<S157>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Ideal P Gain'
 * '<S158>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Ideal P Gain Fdbk'
 * '<S159>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Integrator'
 * '<S160>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Integrator ICs'
 * '<S161>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/N Copy'
 * '<S162>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/N Gain'
 * '<S163>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/P Copy'
 * '<S164>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Parallel P Gain'
 * '<S165>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Reset Signal'
 * '<S166>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Saturation'
 * '<S167>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Saturation Fdbk'
 * '<S168>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Sum'
 * '<S169>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Sum Fdbk'
 * '<S170>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Tracking Mode'
 * '<S171>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Tracking Mode Sum'
 * '<S172>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Tsamp - Integral'
 * '<S173>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Tsamp - Ngain'
 * '<S174>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/postSat Signal'
 * '<S175>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/preInt Signal'
 * '<S176>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/preSat Signal'
 * '<S177>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Anti-windup/Passthrough'
 * '<S178>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/D Gain/Disabled'
 * '<S179>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/External Derivative/Disabled'
 * '<S180>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Filter/Disabled'
 * '<S181>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Filter ICs/Disabled'
 * '<S182>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/I Gain/External Parameters'
 * '<S183>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Ideal P Gain/Passthrough'
 * '<S184>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Ideal P Gain Fdbk/Disabled'
 * '<S185>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Integrator/Discrete'
 * '<S186>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Integrator ICs/Internal IC'
 * '<S187>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/N Copy/Disabled wSignal Specification'
 * '<S188>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/N Gain/Disabled'
 * '<S189>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/P Copy/Disabled'
 * '<S190>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Parallel P Gain/External Parameters'
 * '<S191>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Reset Signal/Disabled'
 * '<S192>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Saturation/Passthrough'
 * '<S193>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Saturation Fdbk/Disabled'
 * '<S194>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Sum/Sum_PI'
 * '<S195>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Sum Fdbk/Disabled'
 * '<S196>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Tracking Mode/Disabled'
 * '<S197>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Tracking Mode Sum/Passthrough'
 * '<S198>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Tsamp - Integral/TsSignalSpecification'
 * '<S199>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Tsamp - Ngain/Passthrough'
 * '<S200>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/postSat Signal/Forward_Path'
 * '<S201>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/preInt Signal/Internal PreInt'
 * '<S202>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/preSat Signal/Forward_Path'
 * '<S203>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/Luenberger'
 * '<S204>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL'
 * '<S205>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/Luenberger/LPF'
 * '<S206>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/Luenberger/LPF1'
 * '<S207>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/Compare To Zero1'
 * '<S208>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/LPF'
 * '<S209>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI'
 * '<S210>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Anti-windup'
 * '<S211>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/D Gain'
 * '<S212>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/External Derivative'
 * '<S213>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Filter'
 * '<S214>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Filter ICs'
 * '<S215>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/I Gain'
 * '<S216>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Ideal P Gain'
 * '<S217>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Ideal P Gain Fdbk'
 * '<S218>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Integrator'
 * '<S219>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Integrator ICs'
 * '<S220>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/N Copy'
 * '<S221>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/N Gain'
 * '<S222>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/P Copy'
 * '<S223>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Parallel P Gain'
 * '<S224>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Reset Signal'
 * '<S225>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Saturation'
 * '<S226>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Saturation Fdbk'
 * '<S227>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Sum'
 * '<S228>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Sum Fdbk'
 * '<S229>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Tracking Mode'
 * '<S230>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Tracking Mode Sum'
 * '<S231>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Tsamp - Integral'
 * '<S232>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Tsamp - Ngain'
 * '<S233>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/postSat Signal'
 * '<S234>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/preInt Signal'
 * '<S235>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/preSat Signal'
 * '<S236>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Anti-windup/Passthrough'
 * '<S237>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/D Gain/Disabled'
 * '<S238>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/External Derivative/Disabled'
 * '<S239>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Filter/Disabled'
 * '<S240>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Filter ICs/Disabled'
 * '<S241>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/I Gain/External Parameters'
 * '<S242>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Ideal P Gain/Passthrough'
 * '<S243>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Ideal P Gain Fdbk/Disabled'
 * '<S244>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Integrator/Discrete'
 * '<S245>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Integrator ICs/Internal IC'
 * '<S246>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/N Copy/Disabled wSignal Specification'
 * '<S247>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/N Gain/Disabled'
 * '<S248>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/P Copy/Disabled'
 * '<S249>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Parallel P Gain/External Parameters'
 * '<S250>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Reset Signal/Disabled'
 * '<S251>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Saturation/Passthrough'
 * '<S252>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Saturation Fdbk/Disabled'
 * '<S253>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Sum/Sum_PI'
 * '<S254>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Sum Fdbk/Disabled'
 * '<S255>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Tracking Mode/Disabled'
 * '<S256>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Tracking Mode Sum/Passthrough'
 * '<S257>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Tsamp - Integral/TsSignalSpecification'
 * '<S258>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Tsamp - Ngain/Passthrough'
 * '<S259>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/postSat Signal/Forward_Path'
 * '<S260>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/preInt Signal/Internal PreInt'
 * '<S261>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/preSat Signal/Forward_Path'
 * '<S262>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL'
 * '<S263>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/SMO'
 * '<S264>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/Compare To Zero1'
 * '<S265>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/LPF'
 * '<S266>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI'
 * '<S267>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Anti-windup'
 * '<S268>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/D Gain'
 * '<S269>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/External Derivative'
 * '<S270>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Filter'
 * '<S271>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Filter ICs'
 * '<S272>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/I Gain'
 * '<S273>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Ideal P Gain'
 * '<S274>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Ideal P Gain Fdbk'
 * '<S275>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Integrator'
 * '<S276>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Integrator ICs'
 * '<S277>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/N Copy'
 * '<S278>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/N Gain'
 * '<S279>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/P Copy'
 * '<S280>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Parallel P Gain'
 * '<S281>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Reset Signal'
 * '<S282>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Saturation'
 * '<S283>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Saturation Fdbk'
 * '<S284>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Sum'
 * '<S285>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Sum Fdbk'
 * '<S286>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Tracking Mode'
 * '<S287>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Tracking Mode Sum'
 * '<S288>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Tsamp - Integral'
 * '<S289>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Tsamp - Ngain'
 * '<S290>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/postSat Signal'
 * '<S291>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/preInt Signal'
 * '<S292>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/preSat Signal'
 * '<S293>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Anti-windup/Passthrough'
 * '<S294>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/D Gain/Disabled'
 * '<S295>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/External Derivative/Disabled'
 * '<S296>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Filter/Disabled'
 * '<S297>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Filter ICs/Disabled'
 * '<S298>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/I Gain/External Parameters'
 * '<S299>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Ideal P Gain/Passthrough'
 * '<S300>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Ideal P Gain Fdbk/Disabled'
 * '<S301>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Integrator/Discrete'
 * '<S302>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Integrator ICs/Internal IC'
 * '<S303>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/N Copy/Disabled wSignal Specification'
 * '<S304>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/N Gain/Disabled'
 * '<S305>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/P Copy/Disabled'
 * '<S306>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Parallel P Gain/External Parameters'
 * '<S307>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Reset Signal/Disabled'
 * '<S308>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Saturation/Passthrough'
 * '<S309>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Saturation Fdbk/Disabled'
 * '<S310>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Sum/Sum_PI'
 * '<S311>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Sum Fdbk/Disabled'
 * '<S312>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Tracking Mode/Disabled'
 * '<S313>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Tracking Mode Sum/Passthrough'
 * '<S314>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Tsamp - Integral/TsSignalSpecification'
 * '<S315>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Tsamp - Ngain/Passthrough'
 * '<S316>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/postSat Signal/Forward_Path'
 * '<S317>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/preInt Signal/Internal PreInt'
 * '<S318>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/preSat Signal/Forward_Path'
 * '<S319>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/SMO/LPF'
 * '<S320>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/SMO/LPF1'
 * '<S321>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/SMO/Sat'
 * '<S322>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/SMO/Sat1'
 * '<S323>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/OpenLopMod/AngleNormalization'
 * '<S324>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/OpenLopMod/OpenLopThetaeCal'
 * '<S325>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/OpenLopMod/AngleNormalization/Compare To Zero'
 * '<S326>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/MotModeCtr'
 * '<S327>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/MotSpdCal'
 * '<S328>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop'
 * '<S329>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/MotModeCtr/Compare To Constant'
 * '<S330>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/MotModeCtr/ModeMgr'
 * '<S331>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/MotSpdCal/Compare To Constant'
 * '<S332>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/MotSpdCal/Compare To Constant1'
 * '<S333>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/MotSpdCal/LPF'
 * '<S334>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/MotSpdCal/LPF1'
 * '<S335>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Compare To Constant'
 * '<S336>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller'
 * '<S337>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Saturation Dynamic'
 * '<S338>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Saturation Dynamic1'
 * '<S339>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Anti-windup'
 * '<S340>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/D Gain'
 * '<S341>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/External Derivative'
 * '<S342>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Filter'
 * '<S343>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Filter ICs'
 * '<S344>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/I Gain'
 * '<S345>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Ideal P Gain'
 * '<S346>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S347>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Integrator'
 * '<S348>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Integrator ICs'
 * '<S349>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/N Copy'
 * '<S350>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/N Gain'
 * '<S351>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/P Copy'
 * '<S352>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Parallel P Gain'
 * '<S353>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Reset Signal'
 * '<S354>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Saturation'
 * '<S355>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Saturation Fdbk'
 * '<S356>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Sum'
 * '<S357>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Sum Fdbk'
 * '<S358>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Tracking Mode'
 * '<S359>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Tracking Mode Sum'
 * '<S360>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Tsamp - Integral'
 * '<S361>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Tsamp - Ngain'
 * '<S362>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/postSat Signal'
 * '<S363>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/preInt Signal'
 * '<S364>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/preSat Signal'
 * '<S365>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S366>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/D Gain/Disabled'
 * '<S367>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/External Derivative/Disabled'
 * '<S368>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Filter/Disabled'
 * '<S369>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Filter ICs/Disabled'
 * '<S370>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/I Gain/External Parameters'
 * '<S371>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S372>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S373>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Integrator/Discrete'
 * '<S374>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Integrator ICs/External IC'
 * '<S375>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S376>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/N Gain/Disabled'
 * '<S377>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/P Copy/Disabled'
 * '<S378>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Parallel P Gain/External Parameters'
 * '<S379>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Reset Signal/External Reset'
 * '<S380>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Saturation/Passthrough'
 * '<S381>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S382>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Sum/Sum_PI'
 * '<S383>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S384>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S385>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S386>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S387>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S388>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S389>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/preInt Signal/Internal PreInt'
 * '<S390>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* PMSM_MC_2025a_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
