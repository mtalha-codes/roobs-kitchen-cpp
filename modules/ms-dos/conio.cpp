//
// Created by Muhammad Talha on 12/20/2024.
//

#include "conio.h"
#include <iostream>

/**
 * @brief Clears the screen.
 *
 * This function uses the platform-specific command to clear the screen.
 * If the platform is Windows, it runs the command "cls" to clear the screen.
 * Otherwise, it runs the command "clear".
 *
 * For Look & Feel of #include<conio.h> from MS-DOS's Turbo C++
 */
void clrscr() {
#if WIN32
    system("cls");
#else
    system("clear");
#endif
}

/**
 * @brief Waits for a key press.
 *
 * This function halts the program execution until a key is pressed.
 * It is commonly used to pause the program and wait for user input.
 *
 * For Look & Feel of #include<conio.h> from MS-DOS's Turbo C++
 */
void getch() {
    std::cin.get();
}

