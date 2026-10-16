/*
 * File: PMSM_MC_2025a.h
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
  real32_T Merge;                      /* '<S20>/Merge' */
  real32_T Merge1;                     /* '<S20>/Merge1' */
  real32_T Switch2;                    /* '<S20>/Switch2' */
  real32_T MotCalThetae;               /* '<S331>/ModeMgr' */
  int32_T MotOffset;                   /* '<S331>/ModeMgr' */
  uint8_T Switch_m;                    /* '<S331>/Switch' */
  boolean_T OLStartCompletedFlag;      /* '<S7>/OpenLopThetaeCal' */
  boolean_T TransmActiveFlag;          /* '<S7>/OpenLopThetaeCal' */
} B_PMSM_MC_2025a_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T Delay_DSTATE_j;             /* '<S6>/Delay' */
  real32_T Delay1_DSTATE_k;            /* '<S6>/Delay1' */
  real32_T Integrator_DSTATE;          /* '<S64>/Integrator' */
  real32_T Integrator_DSTATE_j;        /* '<S116>/Integrator' */
  real32_T Delay_DSTATE_b;             /* '<S266>/Delay' */
  real32_T Delay_DSTATE_o;             /* '<S267>/Delay' */
  real32_T Delay2_DSTATE;              /* '<S267>/Delay2' */
  real32_T Delay_DSTATE_o0;            /* '<S324>/Delay' */
  real32_T Delay1_DSTATE_kw;           /* '<S267>/Delay1' */
  real32_T Delay3_DSTATE;              /* '<S267>/Delay3' */
  real32_T Delay_DSTATE_n;             /* '<S325>/Delay' */
  real32_T Integrator_DSTATE_i;        /* '<S306>/Integrator' */
  real32_T Delay_DSTATE_ok;            /* '<S270>/Delay' */
  real32_T Delay_DSTATE_d;             /* '<S147>/Delay' */
  real32_T Delay3_DSTATE_e;            /* '<S206>/Delay3' */
  real32_T Delay1_DSTATE_p;            /* '<S206>/Delay1' */
  real32_T Delay_DSTATE_n4;            /* '<S206>/Delay' */
  real32_T Delay_DSTATE_jn;            /* '<S208>/Delay' */
  real32_T Delay_DSTATE_h;             /* '<S207>/Delay' */
  real32_T Delay2_DSTATE_d;            /* '<S206>/Delay2' */
  real32_T Delay_DSTATE_dq;            /* '<S209>/Delay' */
  real32_T Integrator_DSTATE_m;        /* '<S248>/Integrator' */
  real32_T Delay_DSTATE_k;             /* '<S212>/Delay' */
  real32_T Delay2_DSTATE_f;            /* '<S149>/Delay2' */
  real32_T Delay3_DSTATE_c;            /* '<S149>/Delay3' */
  real32_T Delay_DSTATE_i;             /* '<S149>/Delay' */
  real32_T Delay_DSTATE_p;             /* '<S150>/Delay' */
  real32_T Delay1_DSTATE_o;            /* '<S149>/Delay1' */
  real32_T Integrator_DSTATE_l;        /* '<S188>/Integrator' */
  real32_T Delay_DSTATE_e;             /* '<S152>/Delay' */
  real32_T Delay_DSTATE_pq;            /* '<S338>/Delay' */
  real32_T Delay_DSTATE_a;             /* '<S339>/Delay' */
  real32_T Integrator_DSTATE_e;        /* '<S377>/Integrator' */
  int32_T Delay_DSTATE_h5;             /* '<S332>/Delay' */
  real32_T WeRefRamped;                /* '<S7>/OpenLopThetaeCal' */
  real32_T Thetae_OL;                  /* '<S7>/OpenLopThetaeCal' */
  real32_T TransmFactor;               /* '<S7>/OpenLopThetaeCal' */
  real32_T PhaseOffset;                /* '<S7>/OpenLopThetaeCal' */
  int32_T MotOffsetBuff[2];            /* '<S331>/ModeMgr' */
  uint32_T counter;                    /* '<Root>/Scheduler' */
  uint32_T previousTicks;              /* '<S7>/OpenLopThetaeCal' */
  uint32_T previousTicks_h;            /* '<S331>/ModeMgr' */
  uint16_T OLStableCnt;                /* '<S7>/OpenLopThetaeCal' */
  uint16_T temporalCounter_i1;         /* '<S7>/OpenLopThetaeCal' */
  uint16_T temporalCounter_i1_j;       /* '<S331>/ModeMgr' */
  int8_T Integrator_PrevResetState;    /* '<S64>/Integrator' */
  int8_T Integrator_PrevResetState_c;  /* '<S116>/Integrator' */
  int8_T Integrator_PrevResetState_j;  /* '<S306>/Integrator' */
  int8_T Integrator_PrevResetState_m;  /* '<S248>/Integrator' */
  int8_T Integrator_PrevResetState_cx; /* '<S188>/Integrator' */
  uint8_T is_active_c2_PMSM_MC_2025a;  /* '<S7>/OpenLopThetaeCal' */
  uint8_T is_c2_PMSM_MC_2025a;         /* '<S7>/OpenLopThetaeCal' */
  uint8_T is_IFStart;                  /* '<S7>/OpenLopThetaeCal' */
  uint8_T is_VFOpenLoop;               /* '<S7>/OpenLopThetaeCal' */
  uint8_T is_active_c1_PMSM_MC_2025a;  /* '<S331>/ModeMgr' */
  uint8_T is_c1_PMSM_MC_2025a;         /* '<S331>/ModeMgr' */
  uint8_T is_SensorCtr;                /* '<S331>/ModeMgr' */
  uint8_T is_Calibrate;                /* '<S331>/ModeMgr' */
  uint8_T is_Normal;                   /* '<S331>/ModeMgr' */
  uint8_T is_SensorLessCtr;            /* '<S331>/ModeMgr' */
  boolean_T icLoad;                    /* '<S324>/Delay' */
  boolean_T icLoad_i;                  /* '<S325>/Delay' */
  boolean_T icLoad_o;                  /* '<S270>/Delay' */
  boolean_T icLoad_h;                  /* '<S208>/Delay' */
  boolean_T icLoad_hx;                 /* '<S209>/Delay' */
  boolean_T icLoad_a;                  /* '<S212>/Delay' */
  boolean_T icLoad_m;                  /* '<S152>/Delay' */
  boolean_T icLoad_c;                  /* '<S332>/Delay' */
  boolean_T icLoad_a1;                 /* '<S338>/Delay' */
  boolean_T icLoad_e;                  /* '<S339>/Delay' */
  boolean_T MotCalNormal;              /* '<S331>/ModeMgr' */
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
  const real32_T Add;                  /* '<S270>/Add' */
  const real32_T Add_c;                /* '<S324>/Add' */
  const real32_T Add_m;                /* '<S325>/Add' */
  const real32_T Gain_a;               /* '<S326>/Gain' */
  const real32_T Gain_n;               /* '<S327>/Gain' */
  const real32_T MathFunction;         /* '<S206>/Math Function' */
  const real32_T uLs;                  /* '<S206>/4*Ls' */
  const real32_T uRs;                  /* '<S206>/4*Rs' */
  const real32_T Gain_f;               /* '<S206>/Gain' */
  const real32_T Add_i;                /* '<S206>/Add' */
  const real32_T k1;                   /* '<S206>/Add1' */
  const real32_T Add_p;                /* '<S208>/Add' */
  const real32_T Add_b;                /* '<S209>/Add' */
  const real32_T Ts;                   /* '<S206>/Ts' */
  const real32_T Ts4;                  /* '<S206>/Ts4' */
  const real32_T Add_f;                /* '<S212>/Add' */
  const real32_T MathFunction2;        /* '<S149>/Math Function2' */
  const real32_T Add_f5;               /* '<S152>/Add' */
  const real32_T Add_k;                /* '<S338>/Add' */
  const real32_T Add_iy;               /* '<S339>/Add' */
  const real32_T Constant;             /* '<S333>/Constant' */
  const real32_T Gain_k;               /* '<S333>/Gain' */
  const int32_T Gain1_g;               /* '<S333>/Gain1' */
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
extern real32_T DAixCurrent;           /* '<S18>/Add' */
extern real32_T QAixCurrent;           /* '<S18>/Add1' */
extern real32_T Thetae_Est;            /* '<S20>/Switch1' */
extern real32_T DAixCurrent_Ref;       /* '<S6>/Constant' */
extern real32_T MotorActSpd_Encode;    /* '<S338>/Add1' */
extern real32_T MotorActSpd_Est;       /* '<S339>/Add1' */
extern real32_T MotorActSpd;           /* '<S332>/Switch' */
extern real32_T QAixCurrent_Ref;       /* '<S341>/Switch2' */
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
                                        * Referenced by: '<S333>/Constant3'
                                        */
extern real32_T MC_SpdLopKp_CFG;       /* Variable: MC_SpdLopKp_CFG
                                        * Referenced by: '<S333>/Constant2'
                                        */
extern boolean_T OpenLoopEn_CFG;       /* Variable: OpenLoopEn_CFG
                                        * Referenced by: '<S331>/Constant2'
                                        */
extern boolean_T SensorLessEn_CFG;     /* Variable: SensorLessEn_CFG
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
extern uint8_T MC_MotModeDebug_CFG;    /* Variable: MC_MotModeDebug_CFG
                                        * Referenced by: '<S331>/Constant'
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
 * Block '<S28>/Data Type Duplicate' : Unused code path elimination
 * Block '<S28>/Data Type Propagation' : Unused code path elimination
 * Block '<S29>/Data Type Duplicate' : Unused code path elimination
 * Block '<S29>/Data Type Propagation' : Unused code path elimination
 * Block '<S14>/Scope' : Unused code path elimination
 * Block '<S14>/Scope1' : Unused code path elimination
 * Block '<S149>/Atan2' : Unused code path elimination
 * Block '<S149>/Scope' : Unused code path elimination
 * Block '<S150>/PI_Out' : Unused code path elimination
 * Block '<S150>/erro' : Unused code path elimination
 * Block '<S206>/Scope' : Unused code path elimination
 * Block '<S267>/Scope' : Unused code path elimination
 * Block '<S267>/Scope1' : Unused code path elimination
 * Block '<S267>/Scope2' : Unused code path elimination
 * Block '<S267>/Scope3' : Unused code path elimination
 * Block '<S267>/Scope4' : Unused code path elimination
 * Block '<S3>/Scope' : Unused code path elimination
 * Block '<S341>/Data Type Duplicate' : Unused code path elimination
 * Block '<S341>/Data Type Propagation' : Unused code path elimination
 * Block '<S342>/Data Type Duplicate' : Unused code path elimination
 * Block '<S342>/Data Type Propagation' : Unused code path elimination
 * Block '<S10>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S11>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S266>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S266>/Data Type Conversion1' : Eliminate redundant data type conversion
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
 * '<S25>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Compare To Constant4'
 * '<S26>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller'
 * '<S27>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1'
 * '<S28>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Saturation Dynamic'
 * '<S29>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Saturation Dynamic1'
 * '<S30>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Anti-windup'
 * '<S31>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/D Gain'
 * '<S32>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/External Derivative'
 * '<S33>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Filter'
 * '<S34>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Filter ICs'
 * '<S35>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/I Gain'
 * '<S36>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Ideal P Gain'
 * '<S37>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S38>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Integrator'
 * '<S39>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Integrator ICs'
 * '<S40>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/N Copy'
 * '<S41>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/N Gain'
 * '<S42>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/P Copy'
 * '<S43>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Parallel P Gain'
 * '<S44>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Reset Signal'
 * '<S45>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Saturation'
 * '<S46>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Saturation Fdbk'
 * '<S47>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Sum'
 * '<S48>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Sum Fdbk'
 * '<S49>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Tracking Mode'
 * '<S50>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Tracking Mode Sum'
 * '<S51>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Tsamp - Integral'
 * '<S52>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Tsamp - Ngain'
 * '<S53>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/postSat Signal'
 * '<S54>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/preInt Signal'
 * '<S55>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/preSat Signal'
 * '<S56>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S57>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/D Gain/Disabled'
 * '<S58>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/External Derivative/Disabled'
 * '<S59>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Filter/Disabled'
 * '<S60>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Filter ICs/Disabled'
 * '<S61>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/I Gain/External Parameters'
 * '<S62>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S63>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S64>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Integrator/Discrete'
 * '<S65>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Integrator ICs/External IC'
 * '<S66>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S67>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/N Gain/Disabled'
 * '<S68>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/P Copy/Disabled'
 * '<S69>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Parallel P Gain/External Parameters'
 * '<S70>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Reset Signal/External Reset'
 * '<S71>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Saturation/Passthrough'
 * '<S72>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S73>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Sum/Sum_PI'
 * '<S74>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S75>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S76>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S77>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S78>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S79>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S80>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/preInt Signal/Internal PreInt'
 * '<S81>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S82>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Anti-windup'
 * '<S83>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/D Gain'
 * '<S84>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/External Derivative'
 * '<S85>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Filter'
 * '<S86>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Filter ICs'
 * '<S87>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/I Gain'
 * '<S88>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Ideal P Gain'
 * '<S89>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S90>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Integrator'
 * '<S91>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Integrator ICs'
 * '<S92>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/N Copy'
 * '<S93>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/N Gain'
 * '<S94>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/P Copy'
 * '<S95>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Parallel P Gain'
 * '<S96>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Reset Signal'
 * '<S97>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Saturation'
 * '<S98>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Saturation Fdbk'
 * '<S99>'  : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Sum'
 * '<S100>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Sum Fdbk'
 * '<S101>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Tracking Mode'
 * '<S102>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Tracking Mode Sum'
 * '<S103>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Tsamp - Integral'
 * '<S104>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Tsamp - Ngain'
 * '<S105>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/postSat Signal'
 * '<S106>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/preInt Signal'
 * '<S107>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/preSat Signal'
 * '<S108>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Anti-windup/Passthrough'
 * '<S109>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/D Gain/Disabled'
 * '<S110>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/External Derivative/Disabled'
 * '<S111>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Filter/Disabled'
 * '<S112>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Filter ICs/Disabled'
 * '<S113>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/I Gain/External Parameters'
 * '<S114>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S115>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S116>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Integrator/Discrete'
 * '<S117>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Integrator ICs/External IC'
 * '<S118>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S119>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/N Gain/Disabled'
 * '<S120>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/P Copy/Disabled'
 * '<S121>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Parallel P Gain/External Parameters'
 * '<S122>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Reset Signal/External Reset'
 * '<S123>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Saturation/Passthrough'
 * '<S124>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S125>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Sum/Sum_PI'
 * '<S126>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S127>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S128>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S129>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S130>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S131>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S132>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/preInt Signal/Internal PreInt'
 * '<S133>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/CurrentLoop/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S134>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/ElecAgCorrect/Compare To Constant'
 * '<S135>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/ElecAgCorrect/Compare To Constant1'
 * '<S136>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/ElecAgCorrect/Compare To Constant2'
 * '<S137>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SVPWM/SevenSegSVPWM'
 * '<S138>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SVPWM/SevenSegSVPWM/SectorCaculate'
 * '<S139>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SVPWM/SevenSegSVPWM/T1T2Caculate'
 * '<S140>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SVPWM/SevenSegSVPWM/TcmCaculate'
 * '<S141>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SVPWM/SevenSegSVPWM/XYZCaculate'
 * '<S142>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Compare To Constant'
 * '<S143>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Compare To Constant1'
 * '<S144>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Compare To Constant2'
 * '<S145>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Compare To Constant3'
 * '<S146>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL'
 * '<S147>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL'
 * '<S148>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL'
 * '<S149>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/FluxObs'
 * '<S150>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL'
 * '<S151>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/Compare To Constant'
 * '<S152>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/LPF'
 * '<S153>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI'
 * '<S154>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Anti-windup'
 * '<S155>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/D Gain'
 * '<S156>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/External Derivative'
 * '<S157>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Filter'
 * '<S158>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Filter ICs'
 * '<S159>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/I Gain'
 * '<S160>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Ideal P Gain'
 * '<S161>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Ideal P Gain Fdbk'
 * '<S162>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Integrator'
 * '<S163>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Integrator ICs'
 * '<S164>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/N Copy'
 * '<S165>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/N Gain'
 * '<S166>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/P Copy'
 * '<S167>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Parallel P Gain'
 * '<S168>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Reset Signal'
 * '<S169>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Saturation'
 * '<S170>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Saturation Fdbk'
 * '<S171>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Sum'
 * '<S172>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Sum Fdbk'
 * '<S173>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Tracking Mode'
 * '<S174>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Tracking Mode Sum'
 * '<S175>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Tsamp - Integral'
 * '<S176>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Tsamp - Ngain'
 * '<S177>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/postSat Signal'
 * '<S178>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/preInt Signal'
 * '<S179>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/preSat Signal'
 * '<S180>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Anti-windup/Passthrough'
 * '<S181>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/D Gain/Disabled'
 * '<S182>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/External Derivative/Disabled'
 * '<S183>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Filter/Disabled'
 * '<S184>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Filter ICs/Disabled'
 * '<S185>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/I Gain/External Parameters'
 * '<S186>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Ideal P Gain/Passthrough'
 * '<S187>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Ideal P Gain Fdbk/Disabled'
 * '<S188>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Integrator/Discrete'
 * '<S189>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Integrator ICs/Internal IC'
 * '<S190>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/N Copy/Disabled wSignal Specification'
 * '<S191>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/N Gain/Disabled'
 * '<S192>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/P Copy/Disabled'
 * '<S193>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Parallel P Gain/External Parameters'
 * '<S194>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Reset Signal/External Reset'
 * '<S195>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Saturation/Passthrough'
 * '<S196>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Saturation Fdbk/Disabled'
 * '<S197>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Sum/Sum_PI'
 * '<S198>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Sum Fdbk/Disabled'
 * '<S199>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Tracking Mode/Disabled'
 * '<S200>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Tracking Mode Sum/Passthrough'
 * '<S201>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Tsamp - Integral/TsSignalSpecification'
 * '<S202>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/Tsamp - Ngain/Passthrough'
 * '<S203>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/postSat Signal/Forward_Path'
 * '<S204>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/preInt Signal/Internal PreInt'
 * '<S205>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/FluxObs+PLL/PLL/PLL_PI/preSat Signal/Forward_Path'
 * '<S206>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/Luenberger'
 * '<S207>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL'
 * '<S208>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/Luenberger/LPF'
 * '<S209>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/Luenberger/LPF1'
 * '<S210>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/Compare To Constant'
 * '<S211>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/Compare To Zero1'
 * '<S212>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/LPF'
 * '<S213>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI'
 * '<S214>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Anti-windup'
 * '<S215>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/D Gain'
 * '<S216>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/External Derivative'
 * '<S217>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Filter'
 * '<S218>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Filter ICs'
 * '<S219>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/I Gain'
 * '<S220>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Ideal P Gain'
 * '<S221>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Ideal P Gain Fdbk'
 * '<S222>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Integrator'
 * '<S223>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Integrator ICs'
 * '<S224>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/N Copy'
 * '<S225>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/N Gain'
 * '<S226>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/P Copy'
 * '<S227>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Parallel P Gain'
 * '<S228>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Reset Signal'
 * '<S229>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Saturation'
 * '<S230>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Saturation Fdbk'
 * '<S231>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Sum'
 * '<S232>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Sum Fdbk'
 * '<S233>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Tracking Mode'
 * '<S234>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Tracking Mode Sum'
 * '<S235>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Tsamp - Integral'
 * '<S236>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Tsamp - Ngain'
 * '<S237>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/postSat Signal'
 * '<S238>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/preInt Signal'
 * '<S239>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/preSat Signal'
 * '<S240>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Anti-windup/Passthrough'
 * '<S241>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/D Gain/Disabled'
 * '<S242>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/External Derivative/Disabled'
 * '<S243>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Filter/Disabled'
 * '<S244>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Filter ICs/Disabled'
 * '<S245>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/I Gain/External Parameters'
 * '<S246>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Ideal P Gain/Passthrough'
 * '<S247>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Ideal P Gain Fdbk/Disabled'
 * '<S248>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Integrator/Discrete'
 * '<S249>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Integrator ICs/Internal IC'
 * '<S250>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/N Copy/Disabled wSignal Specification'
 * '<S251>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/N Gain/Disabled'
 * '<S252>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/P Copy/Disabled'
 * '<S253>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Parallel P Gain/External Parameters'
 * '<S254>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Reset Signal/External Reset'
 * '<S255>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Saturation/Passthrough'
 * '<S256>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Saturation Fdbk/Disabled'
 * '<S257>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Sum/Sum_PI'
 * '<S258>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Sum Fdbk/Disabled'
 * '<S259>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Tracking Mode/Disabled'
 * '<S260>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Tracking Mode Sum/Passthrough'
 * '<S261>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Tsamp - Integral/TsSignalSpecification'
 * '<S262>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/Tsamp - Ngain/Passthrough'
 * '<S263>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/postSat Signal/Forward_Path'
 * '<S264>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/preInt Signal/Internal PreInt'
 * '<S265>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/Luenberger+PLL/PLL/PLL_PI/preSat Signal/Forward_Path'
 * '<S266>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL'
 * '<S267>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/SMO'
 * '<S268>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/Compare To Constant'
 * '<S269>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/Compare To Zero1'
 * '<S270>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/LPF'
 * '<S271>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI'
 * '<S272>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Anti-windup'
 * '<S273>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/D Gain'
 * '<S274>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/External Derivative'
 * '<S275>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Filter'
 * '<S276>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Filter ICs'
 * '<S277>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/I Gain'
 * '<S278>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Ideal P Gain'
 * '<S279>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Ideal P Gain Fdbk'
 * '<S280>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Integrator'
 * '<S281>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Integrator ICs'
 * '<S282>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/N Copy'
 * '<S283>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/N Gain'
 * '<S284>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/P Copy'
 * '<S285>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Parallel P Gain'
 * '<S286>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Reset Signal'
 * '<S287>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Saturation'
 * '<S288>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Saturation Fdbk'
 * '<S289>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Sum'
 * '<S290>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Sum Fdbk'
 * '<S291>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Tracking Mode'
 * '<S292>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Tracking Mode Sum'
 * '<S293>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Tsamp - Integral'
 * '<S294>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Tsamp - Ngain'
 * '<S295>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/postSat Signal'
 * '<S296>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/preInt Signal'
 * '<S297>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/preSat Signal'
 * '<S298>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Anti-windup/Passthrough'
 * '<S299>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/D Gain/Disabled'
 * '<S300>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/External Derivative/Disabled'
 * '<S301>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Filter/Disabled'
 * '<S302>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Filter ICs/Disabled'
 * '<S303>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/I Gain/External Parameters'
 * '<S304>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Ideal P Gain/Passthrough'
 * '<S305>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Ideal P Gain Fdbk/Disabled'
 * '<S306>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Integrator/Discrete'
 * '<S307>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Integrator ICs/Internal IC'
 * '<S308>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/N Copy/Disabled wSignal Specification'
 * '<S309>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/N Gain/Disabled'
 * '<S310>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/P Copy/Disabled'
 * '<S311>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Parallel P Gain/External Parameters'
 * '<S312>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Reset Signal/External Reset'
 * '<S313>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Saturation/Passthrough'
 * '<S314>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Saturation Fdbk/Disabled'
 * '<S315>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Sum/Sum_PI'
 * '<S316>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Sum Fdbk/Disabled'
 * '<S317>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Tracking Mode/Disabled'
 * '<S318>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Tracking Mode Sum/Passthrough'
 * '<S319>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Tsamp - Integral/TsSignalSpecification'
 * '<S320>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/Tsamp - Ngain/Passthrough'
 * '<S321>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/postSat Signal/Forward_Path'
 * '<S322>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/preInt Signal/Internal PreInt'
 * '<S323>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/PLL/PLL_PI/preSat Signal/Forward_Path'
 * '<S324>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/SMO/LPF'
 * '<S325>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/SMO/LPF1'
 * '<S326>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/SMO/Sat'
 * '<S327>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/FOC/SensorLessAlgorithm/SMO+PLL/SMO/Sat1'
 * '<S328>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/OpenLopMod/AngleNormalization'
 * '<S329>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/OpenLopMod/OpenLopThetaeCal'
 * '<S330>' : 'PMSM_MC_2025a/PMSM_MC/MC_HighFrqTask/OpenLopMod/AngleNormalization/Compare To Zero'
 * '<S331>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/MotModeCtr'
 * '<S332>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/MotSpdCal'
 * '<S333>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop'
 * '<S334>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/MotModeCtr/Compare To Constant'
 * '<S335>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/MotModeCtr/ModeMgr'
 * '<S336>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/MotSpdCal/Compare To Constant'
 * '<S337>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/MotSpdCal/Compare To Constant1'
 * '<S338>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/MotSpdCal/LPF'
 * '<S339>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/MotSpdCal/LPF1'
 * '<S340>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller'
 * '<S341>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Saturation Dynamic'
 * '<S342>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Saturation Dynamic1'
 * '<S343>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Anti-windup'
 * '<S344>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/D Gain'
 * '<S345>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/External Derivative'
 * '<S346>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Filter'
 * '<S347>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Filter ICs'
 * '<S348>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/I Gain'
 * '<S349>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Ideal P Gain'
 * '<S350>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S351>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Integrator'
 * '<S352>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Integrator ICs'
 * '<S353>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/N Copy'
 * '<S354>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/N Gain'
 * '<S355>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/P Copy'
 * '<S356>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Parallel P Gain'
 * '<S357>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Reset Signal'
 * '<S358>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Saturation'
 * '<S359>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Saturation Fdbk'
 * '<S360>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Sum'
 * '<S361>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Sum Fdbk'
 * '<S362>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Tracking Mode'
 * '<S363>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Tracking Mode Sum'
 * '<S364>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Tsamp - Integral'
 * '<S365>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Tsamp - Ngain'
 * '<S366>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/postSat Signal'
 * '<S367>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/preInt Signal'
 * '<S368>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/preSat Signal'
 * '<S369>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S370>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/D Gain/Disabled'
 * '<S371>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/External Derivative/Disabled'
 * '<S372>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Filter/Disabled'
 * '<S373>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Filter ICs/Disabled'
 * '<S374>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/I Gain/External Parameters'
 * '<S375>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S376>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S377>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Integrator/Discrete'
 * '<S378>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Integrator ICs/External IC'
 * '<S379>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S380>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/N Gain/Disabled'
 * '<S381>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/P Copy/Disabled'
 * '<S382>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Parallel P Gain/External Parameters'
 * '<S383>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Reset Signal/External Reset'
 * '<S384>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Saturation/Passthrough'
 * '<S385>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S386>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Sum/Sum_PI'
 * '<S387>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S388>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S389>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S390>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S391>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S392>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S393>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/preInt Signal/Internal PreInt'
 * '<S394>' : 'PMSM_MC_2025a/PMSM_MC/MC_LowFrqTask/SpdLoop/Discrete PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* PMSM_MC_2025a_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
