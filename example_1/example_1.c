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
    unsigned int num = 0b0000;

    LOG_WHITE("%s\n", bin_print(num));


    LOG_WHITE("s 0x000000FF %s\n", bin_print(bin_set_bit(&num, 0x12, 0x000000FF)));
    LOG_WHITE("s 0x0000FF00 %s\n", bin_print(bin_set_bit(&num, 0x45, 0x0000FF00)));
    LOG_WHITE("s 0x00FF0000 %s\n", bin_print(bin_set_bit(&num, 0x78, 0x00FF0000)));
    LOG_WHITE("s 0xFF000000 %s\n", bin_print(bin_set_bit(&num, 0xF5, 0xFF000000)));


    /* 获取 */
    LOG_WHITE("g 0x000000FF [%x]-[%d] %s\n", bin_get_bit(num, 0x000000FF), bin_get_bit(num, 0x000000FF), bin_print(bin_get_bit(num, 0x000000FF)));
    LOG_WHITE("g 0x0000FF00 [%x]-[%d] %s\n", bin_get_bit(num, 0x0000FF00), bin_get_bit(num, 0x0000FF00), bin_print(bin_get_bit(num, 0x0000FF00)));
    LOG_WHITE("g 0x00FF0000 [%x]-[%d] %s\n", bin_get_bit(num, 0x00FF0000), bin_get_bit(num, 0x00FF0000), bin_print(bin_get_bit(num, 0x00FF0000)));
    LOG_WHITE("g 0xFF000000 [%x]-[%d] %s\n", bin_get_bit(num, 0xFF000000), bin_get_bit(num, 0xFF000000), bin_print(bin_get_bit(num, 0xFF000000)));

}

int main()
{
    _number();


    return 0;
}