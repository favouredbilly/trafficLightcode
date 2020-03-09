/*------------------------------------------------------------------*-
Traffic_Lights.H (v1.00)
------------------------------------------------------------------
- See T_Lights.C for details.
-*------------------------------------------------------------------*/
#ifndef _TRAFFIC_LIGHTS_H
#define _TRAFFIC_LIGHTS_H
// ------ Public data type declarations ----------------------------
// Possible system states
typedef enum {RED, RED_AND_AMBER, GREEN, AMBER} State_st;
// ------ Public function prototypes -------------------------------
void TRAFFIC_LIGHTS_Init(const State_st);
void TRAFFIC_LIGHTS_Update(void);
#endif
/*------------------------------------------------------------------*-
---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/