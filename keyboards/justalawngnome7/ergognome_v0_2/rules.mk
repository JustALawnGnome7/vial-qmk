# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE

I2C_DRIVER_REQUIRED = yes

# custom matrix setup
CUSTOM_MATRIX = lite # <yes/lite>
VPATH += drivers/gpio
SRC += mcp23018.c matrix.c
