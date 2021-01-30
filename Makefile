PROJECT:=btCtrl
SRC_DIR:=src
INC_DIR:=include

#CFILES:= $(SRC_DIR)/button_ctrl.c
CFILES:= $(SRC_DIR)/bluetooth_ctrl.c
CFILES+= $(SRC_DIR)/gpio.c
CFILES+= $(SRC_DIR)/led_ctrl.c

include Makefile.inc

