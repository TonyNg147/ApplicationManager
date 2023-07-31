#include "ViewEnums.h"
#include "ViewStructs.h"
#include "Defines.h"
static const State StateA = {ViewEnums::SCREEN_A,Layer::SCREEN,SCREEN_A_PATH};
static const State StateB = {ViewEnums::SCREEN_B,Layer::SCREEN,SCREEN_B_PATH};

static State_Event Screen_A_Event[] = 
{
    {ViewEnums::TO_B,StateB}
};
static State_Event Screen_B_Event[] = 
{
    {ViewEnums::TO_A,StateA}
};
static SystemState SYSTEM_ALL_STATE[] =
{
    {ViewEnums::SCREEN_A,Screen_A_Event,size(Screen_A_Event),StateA},
    {ViewEnums::SCREEN_B,Screen_B_Event,size(Screen_B_Event),StateB},
};