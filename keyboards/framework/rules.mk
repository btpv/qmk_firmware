SRC += btpv_matrix.c sleep.c communication.c keyboard.c
ANALOG_DRIVER_REQUIRED = yes
RGB_MATRIX_CUSTOM_KB = yes
RAW_ENABLE = yes
OS_DETECTION_ENABLE = yes
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
