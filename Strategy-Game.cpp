#include "Core/Game.hpp"
#include <ctime>

// CRT library for memory leaks detection.
#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#endif

int main() {
  srand(time(nullptr));

  Game().Execute();

  #ifdef _DEBUG
  _CrtDumpMemoryLeaks();
  #endif

  return 0;
}
