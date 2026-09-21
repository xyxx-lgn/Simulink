/*
 * File: PMSM_MC.h
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

#ifndef PMSM_MC_h_
#define PMSM_MC_h_
#ifndef PMSM_MC_COMMON_INCLUDES_
#define PMSM_MC_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* PMSM_MC_COMMON_INCLUDES_ */

#include "PMSM_MC_types.h"
#include "rtGetNaN.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real32_T Switch2;                    /* '<S143>/Switch2' */
  real32_T MotCalThetae;               /* '<S135>/Chart' */
  int32_T MotOffset;                   /* '<S135>/Chart' */
  uint8_T Switch;                      /* '<S135>/Switch' */
} B_PMSM_MC_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T Integrator_DSTATE;          /* '<S57>/Integrator' */
  real32_T Integrator_DSTATE_d;        /* '<S109>/Integrator' */
  real32_T Integrator_DSTATE_dr;       /* '<S179>/Integrator' */
  real32_T Delay_DSTATE;               /* '<S140>/Delay' */
  int32_T Delay_DSTATE_a;              /* '<S136>/Delay' */
  int32_T MotOffsetBuff[2];            /* '<S135>/Chart' */
  uint32_T counter;                    /* '<Root>/Scheduler' */
  uint32_T previousTicks;              /* '<S135>/Chart' */
  uint16_T temporalCounter_i1;         /* '<S135>/Chart' */
  int8_T Integrator_PrevResetState;    /* '<S57>/Integrator' */
  int8_T Integrator_PrevResetState_o;  /* '<S109>/Integrator' */
  int8_T Integrator_PrevResetState_n;  /* '<S179>/Integrator' */
  uint8_T is_active_c1_PMSM_MC;        /* '<S135>/Chart' */
  uint8_T is_c1_PMSM_MC;               /* '<S135>/Chart' */
  uint8_T is_Calibrate;                /* '<S135>/Chart' */
  uint8_T is_Normal;                   /* '<S135>/Chart' */
  boolean_T icLoad;                    /* '<S136>/Delay' */
  boolean_T icLoad_d;                  /* '<S140>/Delay' */
  boolean_T MotCalNormal;              /* '<S135>/Chart' */
} DW_PMSM_MC_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T Constant4;            /* '<S13>/Constant4' */
  const real32_T Constant5;            /* '<S13>/Constant5' */
  const real32_T Add;                  /* '<S140>/Add' */
  const real32_T Constant;             /* '<S137>/Constant' */
  const real32_T Gain;                 /* '<S137>/Gain' */
  const int32_T Gain1;                 /* '<S137>/Gain1' */
} ConstB_PMSM_MC_T;

/* Real-time Model Data Structure */
struct tag_RTM_PMSM_MC_T {
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
extern B_PMSM_MC_T PMSM_MC_B;

/* Block states (default storage) */
extern DW_PMSM_MC_T PMSM_MC_DW;
extern const ConstB_PMSM_MC_T PMSM_MC_ConstB;/* constant block i/o */

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
                                        * Referenced by: '<S13>/Constant1'
                                        */
extern real32_T MC_DCurrLopKp_CFG;     /* Variable: MC_DCurrLopKp_CFG
                                        * Referenced by: '<S13>/Constant'
                                        */
extern real32_T MC_QCurrLopKi_CFG;     /* Variable: MC_QCurrLopKi_CFG
                                        * Referenced by: '<S13>/Constant3'
                                        */
extern real32_T MC_QCurrLopKp_CFG;     /* Variable: MC_QCurrLopKp_CFG
                                        * Referenced by: '<S13>/Constant2'
                                        */
extern real32_T MC_SpdLopKi_CFG;       /* Variable: MC_SpdLopKi_CFG
                                        * Referenced by: '<S137>/Constant3'
                                        */
extern real32_T MC_SpdLopKp_CFG;       /* Variable: MC_SpdLopKp_CFG
                                        * Referenced by: '<S137>/Constant2'
                                        */
extern uint8_T MC_MotModeDebug_CFG;    /* Variable: MC_MotModeDebug_CFG
                                        * Referenced by: '<S135>/Constant'
                                        */
extern uint8_T MC_POLE_NUM_CFG;        /* Variable: MC_POLE_NUM_CFG
                                        * Referenced by:
                                        *   '<S9>/Constant'
                                        *   '<S10>/Constant'
                                        */

/* Model entry point functions */
extern void PMSM_MC_initialize(void);
extern void PMSM_MC_step(void);
extern void PMSM_MC_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PMSM_MC_T *const PMSM_MC_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S21>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Data Type Propagation' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Data Type Propagation' : Unused code path elimination
 * Block '<S143>/Data Type Duplicate' : Unused code path elimination
 * Block '<S143>/Data Type Propagation' : Unused code path elimination
 * Block '<S144>/Data Type Duplicate' : Unused code path elimination
 * Block '<S144>/Data Type Propagation' : Unused code path elimination
 * Block '<S9>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * '<Root>' : 'PMSM_MC'
 * '<S1>'   : 'PMSM_MC/PMSM_MC'
 * '<S2>'   : 'PMSM_MC/Scheduler'
 * '<S3>'   : 'PMSM_MC/PMSM_MC/MC_HighFrqTask'
 * '<S4>'   : 'PMSM_MC/PMSM_MC/MC_LowFrqTask'
 * '<S5>'   : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/ElecAngleCal'
 * '<S6>'   : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC'
 * '<S7>'   : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/Stop'
 * '<S8>'   : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/ElecAngleCal/AngleCal'
 * '<S9>'   : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/ElecAngleCal/AngleCal/If Action Subsystem'
 * '<S10>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/ElecAngleCal/AngleCal/If Action Subsystem1'
 * '<S11>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/ElecAngleCal/AngleCal/If Action Subsystem2'
 * '<S12>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/Clark'
 * '<S13>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop'
 * '<S14>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/ElecAgCorrect'
 * '<S15>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/IPark'
 * '<S16>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/Park'
 * '<S17>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/SVPWM'
 * '<S18>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Compare To Constant'
 * '<S19>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller'
 * '<S20>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1'
 * '<S21>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Saturation Dynamic'
 * '<S22>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Saturation Dynamic1'
 * '<S23>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Anti-windup'
 * '<S24>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/D Gain'
 * '<S25>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/External Derivative'
 * '<S26>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Filter'
 * '<S27>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Filter ICs'
 * '<S28>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/I Gain'
 * '<S29>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Ideal P Gain'
 * '<S30>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S31>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Integrator'
 * '<S32>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Integrator ICs'
 * '<S33>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/N Copy'
 * '<S34>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/N Gain'
 * '<S35>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/P Copy'
 * '<S36>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Parallel P Gain'
 * '<S37>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Reset Signal'
 * '<S38>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Saturation'
 * '<S39>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Saturation Fdbk'
 * '<S40>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Sum'
 * '<S41>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Sum Fdbk'
 * '<S42>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Tracking Mode'
 * '<S43>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Tracking Mode Sum'
 * '<S44>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Tsamp - Integral'
 * '<S45>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Tsamp - Ngain'
 * '<S46>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/postSat Signal'
 * '<S47>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/preInt Signal'
 * '<S48>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/preSat Signal'
 * '<S49>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S50>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/D Gain/Disabled'
 * '<S51>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/External Derivative/Disabled'
 * '<S52>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Filter/Disabled'
 * '<S53>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Filter ICs/Disabled'
 * '<S54>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/I Gain/External Parameters'
 * '<S55>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S56>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S57>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Integrator/Discrete'
 * '<S58>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Integrator ICs/External IC'
 * '<S59>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S60>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/N Gain/Disabled'
 * '<S61>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/P Copy/Disabled'
 * '<S62>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Parallel P Gain/External Parameters'
 * '<S63>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Reset Signal/External Reset'
 * '<S64>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Saturation/Passthrough'
 * '<S65>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S66>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Sum/Sum_PI'
 * '<S67>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S68>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S69>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S70>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S71>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S72>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S73>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/preInt Signal/Internal PreInt'
 * '<S74>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S75>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Anti-windup'
 * '<S76>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/D Gain'
 * '<S77>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/External Derivative'
 * '<S78>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Filter'
 * '<S79>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Filter ICs'
 * '<S80>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/I Gain'
 * '<S81>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Ideal P Gain'
 * '<S82>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S83>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Integrator'
 * '<S84>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Integrator ICs'
 * '<S85>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/N Copy'
 * '<S86>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/N Gain'
 * '<S87>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/P Copy'
 * '<S88>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Parallel P Gain'
 * '<S89>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Reset Signal'
 * '<S90>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Saturation'
 * '<S91>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Saturation Fdbk'
 * '<S92>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Sum'
 * '<S93>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Sum Fdbk'
 * '<S94>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Tracking Mode'
 * '<S95>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Tracking Mode Sum'
 * '<S96>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Tsamp - Integral'
 * '<S97>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Tsamp - Ngain'
 * '<S98>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/postSat Signal'
 * '<S99>'  : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/preInt Signal'
 * '<S100>' : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/preSat Signal'
 * '<S101>' : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Anti-windup/Passthrough'
 * '<S102>' : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/D Gain/Disabled'
 * '<S103>' : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/External Derivative/Disabled'
 * '<S104>' : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Filter/Disabled'
 * '<S105>' : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Filter ICs/Disabled'
 * '<S106>' : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/I Gain/External Parameters'
 * '<S107>' : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S108>' : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S109>' : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Integrator/Discrete'
 * '<S110>' : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Integrator ICs/External IC'
 * '<S111>' : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S112>' : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/N Gain/Disabled'
 * '<S113>' : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/P Copy/Disabled'
 * '<S114>' : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Parallel P Gain/External Parameters'
 * '<S115>' : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Reset Signal/External Reset'
 * '<S116>' : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Saturation/Passthrough'
 * '<S117>' : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S118>' : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Sum/Sum_PI'
 * '<S119>' : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S120>' : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S121>' : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S122>' : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S123>' : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S124>' : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S125>' : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/preInt Signal/Internal PreInt'
 * '<S126>' : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S127>' : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/ElecAgCorrect/Compare To Constant'
 * '<S128>' : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/ElecAgCorrect/Compare To Constant1'
 * '<S129>' : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/ElecAgCorrect/Compare To Constant2'
 * '<S130>' : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/SVPWM/SevenSegSVPWM'
 * '<S131>' : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/SVPWM/SevenSegSVPWM/SectorCaculate'
 * '<S132>' : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/SVPWM/SevenSegSVPWM/T1T2Caculate'
 * '<S133>' : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/SVPWM/SevenSegSVPWM/TcmCaculate'
 * '<S134>' : 'PMSM_MC/PMSM_MC/MC_HighFrqTask/FOC/SVPWM/SevenSegSVPWM/XYZCaculate'
 * '<S135>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/MotModeCtr'
 * '<S136>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/MotSpdCal'
 * '<S137>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop'
 * '<S138>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/MotModeCtr/Chart'
 * '<S139>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/MotModeCtr/Compare To Constant'
 * '<S140>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/MotSpdCal/LPF'
 * '<S141>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Compare To Constant'
 * '<S142>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller'
 * '<S143>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Saturation Dynamic'
 * '<S144>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Saturation Dynamic1'
 * '<S145>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Anti-windup'
 * '<S146>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/D Gain'
 * '<S147>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/External Derivative'
 * '<S148>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Filter'
 * '<S149>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Filter ICs'
 * '<S150>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/I Gain'
 * '<S151>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Ideal P Gain'
 * '<S152>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S153>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Integrator'
 * '<S154>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Integrator ICs'
 * '<S155>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/N Copy'
 * '<S156>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/N Gain'
 * '<S157>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/P Copy'
 * '<S158>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Parallel P Gain'
 * '<S159>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Reset Signal'
 * '<S160>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Saturation'
 * '<S161>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Saturation Fdbk'
 * '<S162>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Sum'
 * '<S163>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Sum Fdbk'
 * '<S164>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Tracking Mode'
 * '<S165>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Tracking Mode Sum'
 * '<S166>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Tsamp - Integral'
 * '<S167>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Tsamp - Ngain'
 * '<S168>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/postSat Signal'
 * '<S169>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/preInt Signal'
 * '<S170>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/preSat Signal'
 * '<S171>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S172>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/D Gain/Disabled'
 * '<S173>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/External Derivative/Disabled'
 * '<S174>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Filter/Disabled'
 * '<S175>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Filter ICs/Disabled'
 * '<S176>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/I Gain/External Parameters'
 * '<S177>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S178>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S179>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Integrator/Discrete'
 * '<S180>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Integrator ICs/External IC'
 * '<S181>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S182>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/N Gain/Disabled'
 * '<S183>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/P Copy/Disabled'
 * '<S184>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Parallel P Gain/External Parameters'
 * '<S185>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Reset Signal/External Reset'
 * '<S186>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Saturation/Passthrough'
 * '<S187>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S188>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Sum/Sum_PI'
 * '<S189>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S190>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S191>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S192>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S193>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S194>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S195>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/preInt Signal/Internal PreInt'
 * '<S196>' : 'PMSM_MC/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* PMSM_MC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
