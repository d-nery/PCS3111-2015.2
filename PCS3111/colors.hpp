/**
Escola Politecnica da Universidade de Sao Paulo
14 de outubro de 2015

PCS3111 - Laboratorio de Programacao Orientada a Objetos
Exercicio Programa 2 - 2015

Turma 23
	Daniel Nery Silva de Oliveira - 9349051
	Mateus Almeida Barbosa        - 9349072

Professor Jaime S. Sichman
**/

// Macros para colorir o terminal/console e limpa-lo

#ifndef _COLORS_HPP_
#define _COLORS_HPP_

#include <cstdlib>

#ifdef _WIN32

#include <windows.h>
#include <winnt.h>
#include <stdio.h>

#define CRESET  SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | \
										FOREGROUND_INTENSITY | FOREGROUND_GREEN/*original.wAttributes*/)    // Branco

#define CPINK   SetConsoleTextAttribute(hOut, FOREGROUND_RED  | FOREGROUND_BLUE  | FOREGROUND_INTENSITY)    // Rosa
#define CBLUE   SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY)                       // Azul
#define CYELLOW SetConsoleTextAttribute(hOut, FOREGROUND_RED  | FOREGROUND_GREEN | FOREGROUND_INTENSITY)    // Amarelo
#define CRED    SetConsoleTextAttribute(hOut, FOREGROUND_RED  | FOREGROUND_INTENSITY)                       // Vermelho
#define CGOLD   SetConsoleTextAttribute(hOut, FOREGROUND_RED  | FOREGROUND_GREEN)                           // Dourado
#define CPURPLE SetConsoleTextAttribute(hOut, FOREGROUND_RED  | FOREGROUND_BLUE)                            // Roxo
#define CGREEN  SetConsoleTextAttribute(hOut, FOREGROUND_GREEN)                                             // Verde

#define CLEAR   system("cls")   // Limpa a tela (Usado na transicao entre as diferentes telas do programa)

#else

#define CRESET  std::cout << "\033[0m"

#define CPINK   std::cout << "\033[38;5;201m"
#define CBLUE   std::cout << "\033[38;5;33m"
#define CYELLOW std::cout << "\033[38;5;227m"
#define CRED    std::cout << "\033[38;5;196m"
#define CGOLD   std::cout << "\033[38;5;220m"
#define CPURPLE std::cout << "\033[38;5;99m"
#define CGREEN  std::cout << "\033[38;5;114m"

#define CLEAR   system("clear")

#endif // _win32

#endif /* end of include guard: _COLORS_HPP_ */
