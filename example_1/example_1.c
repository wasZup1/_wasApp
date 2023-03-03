#include <stdio.h>
#include <string.h>
#include <fcntl.h>

#include "include/wasApp.h"




void _log_color()
{
    LOG_WHITE("White\n");
    LOG_YELLOW("Yellow\n");
    LOG_RED("Red\n");
    LOG_GREEN("Green\n");
    LOG_BLUE("Blue\n");
    LOG_PINK("Plnk\n");
    LOG_CYAN("Cyan\n");


    LOG_B_WHITE("White\n");
    LOG_B_YELLOW("Yellow\n");
    LOG_B_RED("Red\n");
    LOG_B_GREEN("Green\n");
    LOG_B_BLUE("Blue\n");
    LOG_B_PINK("Plnk\n");
    LOG_B_CYAN("Cyan\n");
}

void _number()
{
    int num1 = 0;

    bin_set_bit(&num1, 13, 0x0F00);

    LOG_WHITE("%s, %d\n", bin_print(num1), num1);
    // LOG_WHITE("%s, %d\n", bin_print(bin_get_bit(num1, 0xFF)), bin_get_bit(num1, 0xFF));



}

int main()
{
    _number();


    return 0;
}