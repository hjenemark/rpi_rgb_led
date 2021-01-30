#!/bin/bash

BASE_GPIO_PATH=/sys/class/gpio/

RED=17
GREEN=18
BLUE=27

ON="1"
OFF="0"

exportPin()
{
  if [ ! -e $BASE_GPIO_PATH/gpio$1 ]; then
    echo "$1" > $BASE_GPIO_PATH/export
  fi
}

setOutput()
{
  echo out > $BASE_GPIO_PATH/gpio$1/direction
}

setLightState()
{
  echo $2 > $BASE_GPIO_PATH/gpio$1/value
}

allLightsOff()
{
  setLightState $RED $OFF
  setLightState $GREEN $OFF
  setLightState $BLUE $OFF
}

# Ctrl-C handler for clean shutdown 
exitScript()
{
  allLightsOff
  exit 0
}

trap exitScript SIGINT

exportPin $RED
exportPin $GREEN
exportPin $BLUE

setOutput $RED
setOutput $GREEN
setOutput $BLUE

allLightsOff

while [ 1 ]
do
  setLightState $RED $ON
  sleep 3
  
  setLightState $GREEN $ON
  sleep 3

  setLightState $BLUE $ON
  sleep 3

  setLightState $RED $OFF
  sleep 3
  
  setLightState $GREEN $OFF
  sleep 3

  setLightState $BLUE $OFF
  sleep 3
done
