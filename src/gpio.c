#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "gpio.h"

static const int MAX_STRING_LEN = 50;

static void unexport(int pinNo)
{
  int fd = open("/sys/class/gpio/unexport", O_WRONLY);
  char intBuf[4];
  
  if (fd == -1)
  {
    perror("Unable to open /sys/class/gpio/unexport");
    exit(1);
  }

  snprintf(intBuf, 3, "%d", pinNo);
  write(fd, intBuf, 2);

  close(fd);
}

static void export(int pinNo)
{
  int fd = open("/sys/class/gpio/export", O_WRONLY);
  char intBuf[2];
  
  if (fd == -1)
  {
    perror("Unable to open /sys/class/gpio/export");
    exit(1);
  }

  snprintf(intBuf, 3, "%d", pinNo);
  if(write(fd, intBuf, 2) != 2)
  {
    perror("Unable to export pin");
    exit(1);
  }
  close(fd);
}

static void setDir(int pinNo, gpio_dir_t dir )
{
  int fd, writtenBytes, writingBytes;
  char gpioDirFile[MAX_STRING_LEN];
  snprintf(gpioDirFile,35, "/sys/class/gpio/gpio%d/direction", pinNo);
  
  fd = open(gpioDirFile, O_WRONLY);
  if (fd == -1)
  {
    perror("Unable to open GPIO/direction");
    exit(1);
  }

  if(dir == GPIO_OUTPUT)
  {
    writtenBytes = write(fd, "out", 4);
    writingBytes = 4;
  }
  else if(dir == GPIO_INPUT)
  {
    writtenBytes = write(fd, "in", 3);
    writingBytes = 3;
  }
  else
  {
    printf("Not a valid direction\n");
  }

  if(writtenBytes != writingBytes)
  {
    perror("Failed to set direction");
    exit(1);
  }
  close(fd);
}

static void setState(int pinNo, gpio_state_t state )
{
  int fd, writtenBytes;
  char gpioValueFile[MAX_STRING_LEN];
  snprintf(gpioValueFile,35, "/sys/class/gpio/gpio%d/value", pinNo);
  
  fd = open(gpioValueFile, O_WRONLY);
  if (fd == -1)
  {
    perror("Unable to open GPIO/value");
    exit(1);
  }

  if(state == GPIO_HIGH)
  {
    writtenBytes = write(fd, "1", 2);
  }
  else if(state == GPIO_LOW)
  {
    writtenBytes = write(fd, "0", 2);
  }
  else
  {
    printf("Not a valid state\n");
  }

  if(writtenBytes != 2)
  {
    perror("Failed to set state");
    exit(1);
  }
  close(fd);
}

uint8_t gpio_init(int pinNo, gpio_dir_t dir, gpio_state_t state)
{
  unexport(pinNo);
  export(pinNo);
  setDir(pinNo, dir);
  if(dir == GPIO_OUTPUT) {
    setState(pinNo, state);
  }

  return 0;
}

uint8_t gpio_deinit(int pinNo)
{
  unexport(pinNo);
  return 0;
}

void gpio_setHigh(int pinNo)
{
  setState(pinNo, GPIO_HIGH);
}

void gpio_setLow(int pinNo)
{
  setState(pinNo, GPIO_LOW);
}

