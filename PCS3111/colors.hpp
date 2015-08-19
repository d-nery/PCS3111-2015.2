#ifndef _COLORS_HPP_
#define _COLORS_HPP_

#ifdef _WIN32

#include <windows.h>
#include <winnt.h>
#include <stdio.h>

HANDLE consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO original;

if (!(GetConsoleScreenBufferInfo(consolehwnd, &original))) {}

#define CRESET SetConsoleTextAttribute(consolehwnd, original);
#define CPINK  SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED | FOREGROUND_INTENSITY);
#define CBLUE  SetConsoleTextAttribute(consolehwnd, FOREGROUND_BLUE);
#define CRED   SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
#define CGREEN SetConsoleTextAttribute(consolehwnd, FOREGROUND_GREEN);
#define CLEAR  System("cls");


#else

#define CRESET std::cout << "\033[0m";
#define CBLUE  std::cout << "\033[38;5;33m";
#define CRED   std::cout << "\033[38;5;196m";
#define CGREEN std::cout << "\033[38;5;120m";
#define CPINK std::cout << "\033[38;5;201m";
#define CLEAR  system("clear");

#endif // Win32 or linux

#endif /* end of include guard: _COLORS_HPP_ */
