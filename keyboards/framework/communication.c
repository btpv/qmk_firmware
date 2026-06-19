#include <communication.h>
#include <quantum.h>
void send_command(const char* cmd){
    register_code(KC_LALT);
    tap_code(KC_F2);
    unregister_code(KC_LALT);
    wait_ms(50);
    SEND_STRING(cmd);
    tap_code(KC_ENTER);
}
