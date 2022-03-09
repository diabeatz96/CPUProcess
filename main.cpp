#include <iostream>
#include "CPU.h"

int main() {
   CPU cpu;

   cpu.instructions.loadFile();
   cpu.instructions.print();

}
