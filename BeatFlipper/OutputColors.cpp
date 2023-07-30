#include <iostream>
#include "OutputColors.h"

#ifdef _WIN32
#include <Windows.h>
void OutputColors::setTextColor(int colorCode) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colorCode);
}
#endif


