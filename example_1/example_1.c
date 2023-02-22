#include <stdio.h>
#include <string.h>
#include <fcntl.h>

#include "include/wasApp.h"

void _user_data_api_func()
{
    #define USER_DATA_PATH "/home/xiaole/share/work/_wasApp/user_data.ini"

    LOG_WHITE("name=%s\n", user_data_read("name", USER_DATA_PATH));
    user_data_save("name2", "waszup2", USER_DATA_PATH);
    user_data_save("name4", "waszup4", USER_DATA_PATH);

}

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



int main()
{
    _user_data_api_func();



    return 0;
}