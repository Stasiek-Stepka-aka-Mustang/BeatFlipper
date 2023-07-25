#include <iostream>
#include "OutputColors.h"

/** Metoda służaca do kolorowania outputu zdefiniowana na
 *  systemy Unixowe i Windows'a. */
#ifdef _WIN32
#include <Windows.h>
void OutputColors::setTextColor(int colorCode) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colorCode);
}
#else
void OutputColors::setTextColor(const char* colorCode) {
    std::cout << colorCode;
}

void OutputColors::setTextColor(int colorCode) {

}

#endif

