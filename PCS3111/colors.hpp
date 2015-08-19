#ifndef _COLORS_HPP_
#define _COLORS_HPP_

#ifdef _WIN32

#include <windows.h>
#include <winnt.h>
#include <stdio.h>

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//CONSOLE_SCREEN_BUFFER_INFO original;

#define CRESET SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN/*original.wAttributes*/);
#define CPINK  SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
#define CBLUE  SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
#define CRED   SetConsoleTextAttribute(hOut, FOREGROUND_RED);
#define CGREEN SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
#define CLEAR  system("cls");


#else

#define CRESET std::cout << "\033[0m";
#define CBLUE  std::cout << "\033[38;5;33m";
#define CRED   std::cout << "\033[38;5;196m";
#define CGREEN std::cout << "\033[38;5;120m";
#define CPINK  std::cout << "\033[38;5;201m";
#define CLEAR  system("reset");

#endif // Win32 or linux

#endif /* end of include guard: _COLORS_HPP_ */
