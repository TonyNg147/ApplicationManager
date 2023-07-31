#ifndef VIEW_STRUCT_H
#define VIEW_STRUCT_H
#include <QString>
typedef uint8_t   EventSize;
typedef uint16_t Event_id;
typedef uint8_t  State_id;
enum class Layer{
    ROOT=0,
    SCREEN,
    POPUP,
};
struct State{
    State_id state;
    Layer    layer; 
    QString  filePath;
};
struct State_Event{
    Event_id    eventId;
    State       destState;
};
struct SystemState{
    State_id        stateId;
    State_Event     *stateEvent;
    EventSize       eventSize;
    State           state;
};
#endif //VIEW_STRUCT_H