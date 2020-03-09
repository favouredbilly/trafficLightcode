/*------------------------------------------------------------------*-
T_lights.C (v1.00)
------------------------------------------------------------------
Traffic light control program (Test Version 1.0)
-*------------------------------------------------------------------*/
#include "Main.H"
#include "Port.H"
#include "Traffic_Lights.H"
// ------ Private constants ----------------------------------------
// Easy to change logic here
#define ON 0
#define OFF 1
// Times in each of the (four) possible light states
// (Times are in seconds)
#define RED_DURATION 20
#define RED_AND_AMBER_DURATION 5
#define GREEN_DURATION 30
#define AMBER_DURATION 5
// ------ Private variables ----------------------------------------
// The state of the system
static State_st STATE;
// The time in that state
static tLong Time_in_state;
// Used by sEOS
static tByte Call_count_G = 0;

/*------------------------------------------------------------------*-
TRAFFIC_LIGHTS_Init()
-*------------------------------------------------------------------*/
void TRAFFIC_LIGHTS_Init(const State_st START_STATE)
{
//P1 = 0x00;
STATE = START_STATE; // Decide on initial state
}
/*------------------------------------------------------------------*-
TRAFFIC_LIGHTS_Update()
Must be called once per second.
-*------------------------------------------------------------------*/

void TRAFFIC_LIGHTS_Update(void)
{
TF2 = 0;
switch (STATE)
{
case RED:
{
Red = 1;
Amber = 0;
Green = 0;

if (++Time_in_state == RED_DURATION)
{
STATE = RED_AND_AMBER;
Time_in_state = 0;
}
break;
}

case RED_AND_AMBER:
{
Red = 1;
Amber =1;
Green = 0;

if (++Time_in_state == RED_AND_AMBER_DURATION)
{
STATE = GREEN;
Time_in_state = 0;
}
break;
}
case GREEN:
{
Red = 0;
Amber =0;
Green = 1;

if (++Time_in_state == GREEN_DURATION)
{
STATE = AMBER;
Time_in_state = 0;
}
break;
}

case AMBER:
{
Red = 0;
Amber = 1;
Green = 0;

if (++Time_in_state == AMBER_DURATION)
{
STATE = RED;
Time_in_state = 0;
}
break;
}
}
}
/*------------------------------------------------------------------*-
---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/

