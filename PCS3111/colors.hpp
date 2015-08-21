/**
Escola Politecnica da Universidade de Sao Paulo
2 de setembro de 2015

PCS3111 - Laboratorio de Programacao Orientada a Objetos
Exercicio Programa 1 - 2015

Turma 23
	Daniel Nery Silva de Oliveira - 9349051
	Mateus Almeida Barbosa        - 9349072

Professor Jaime S. Sichman
**/

#ifndef _COLORS_HPP_
#define _COLORS_HPP_

#ifdef _WIN32

#include <windows.h>
#include <winnt.h>
#include <stdio.h>

#define CRESET  SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_GREEN/*original.wAttributes*/);

#define CPINK   SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
#define CBLUE   SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
#define CYELLOW SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
#define CRED    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
#define CGOLD   SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN);
#define CPURPLE SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE);
#define CGREEN  SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);

#define CLEAR   system("cls");

#else

#define CRESET  std::cout << "\033[0m";

#define CPINK   std::cout << "\033[38;5;201m";
#define CBLUE   std::cout << "\033[38;5;33m";
#define CYELLOW
#define CRED    std::cout << "\033[38;5;196m";
#define CGOLD
#define CPURPLE
#define CGREEN  std::cout << "\033[38;5;120m";

#define CLEAR   system("clear");

#endif // Win32 or linux

#endif /* end of include guard: _COLORS_HPP_ */
