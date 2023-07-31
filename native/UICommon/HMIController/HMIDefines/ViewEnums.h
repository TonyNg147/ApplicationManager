#ifndef VIEW_ENUMS
#define VIEW_ENUMS
#include <QObject>
class ViewEnums: public QObject{
    Q_OBJECT
    Q_ENUMS(STATE_ROOT)
    Q_ENUMS(STATE_SCREEN)
    Q_ENUMS(EVENT_ID)
    public:
        enum STATE_ROOT: uint8_t{
            STATE_ROOT_MIN=0,
            ROOT,
            STATE_ROOT_MAX
        };
        enum STATE_SCREEN{
            STATE_SCREEN_MIN = STATE_ROOT_MAX + 1,
            SCREEN_A,
            SCREEN_B,
            STATE_SCREEN_MAX
        };
        enum EVENT_ID: uint16_t{
            EVENT_ID_MIN = STATE_SCREEN_MAX + 1,
            TO_A,
            TO_B,
            EVENT_ID_MAX
        };
};
#endif //VIEW_ENUMS