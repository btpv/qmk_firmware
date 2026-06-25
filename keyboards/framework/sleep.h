#pragma once
#include <stdbool.h>
#define SLEEP_GPIO GP0
#define MUX_ENABLE_GPIO GP4
#define BOOT_DONE_GPIO GP5

bool handle_idle(void);
