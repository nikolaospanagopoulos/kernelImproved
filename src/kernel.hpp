#pragma once
#include <stdint.h>

#define VGA_WIDTH 80
#define VGA_HEIGHT 20

class Kernel {

private:
  static uint16_t terminalMakeChar(char c, char colour);
  static uint16_t *videoMem;
  static uint16_t terminalRow;
  static uint16_t terminalCollumn;

public:
  static void terminalPutChar(int x, int y, char c, char colour);
  static void terminalWriteChar(char c, char colour);
  void terminalInitialize();
  static void print(const char *message);

  Kernel();
};
