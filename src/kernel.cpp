#include "kernel.hpp"
#include "String.hpp"

uint16_t *Kernel::videoMem;
uint16_t Kernel::terminalRow;
uint16_t Kernel::terminalCollumn;
Kernel::Kernel() {
  videoMem = nullptr;
  terminalRow = 0;
  terminalCollumn = 0;
  terminalInitialize();
}

void Kernel::print(const char *message) {
  size_t len = strlen(message);
  for (size_t i{}; i < len; i++) {
    terminalWriteChar(message[i], 15);
  }
}
void Kernel::terminalWriteChar(char c, char colour) {
  terminalPutChar(terminalCollumn, terminalRow, c, colour);
  terminalCollumn += 1;
  if (terminalCollumn >= VGA_WIDTH) {
    terminalCollumn = 0;
    terminalRow += 1;
  }
}

void Kernel::terminalPutChar(int x, int y, char c, char colour) {
  videoMem[(y * VGA_WIDTH) + x] = terminalMakeChar(c, colour);
}

void Kernel::terminalInitialize() {

  videoMem = (uint16_t *)(0xB8000);

  for (int y{}; y < VGA_HEIGHT; y++) {
    for (int x{}; x < VGA_WIDTH; x++) {
      terminalPutChar(x, y, ' ', 15);
    }
  }
}

uint16_t Kernel::terminalMakeChar(char c, char colour) {
  return (colour << 8) | c;
}

extern "C" void kernelMain() {

  Kernel kernel;
  Kernel::print("pidarats");
}
