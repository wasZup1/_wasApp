#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "wasApp.h"

bool is_data_exists(const char *name, const char *path)
{
    if(access(path, F_OK) != 0)
    {
        LOG_RED("err: file %s not found\n", path);
        return false;
    }

    static char buf[16]  = {0};
    char cmd[256] = {0};
    
    sprintf(cmd, "cat %s | grep %s", path, name);
    FILE *fp = popen(cmd, "r");
    if(fp == NULL)
    {
        LOG_RED("err: popen [%s] fail\n", cmd);
        return false;
    }

    if(fgets(buf, sizeof(buf)-1, fp) == NULL)
    {
        LOG_RED("err: data [%s] not exists\n", name);
        return false;
    }

    return true;

}

int user_data_add(const char *name, const char *data, const char *path)
{
    char cmd[256] = {0};

    memset(cmd, 0, sizeof(cmd));
    sprintf(cmd, "echo %s=%s >> %s", name, data, path);
    system(cmd);
}

const char *user_data_read(const char *name, const char *path)
{
    if(!is_data_exists(name, path)) return NULL;

    static char buf[16]  = {0};
    char cmd[256] = {0};
    
    sprintf(cmd, "cat %s | grep %s | awk -F \"=\" '{print $2}'", path, name);
    FILE *fp = popen(cmd, "r");
    if(fp == NULL)
    {
        LOG_RED("err: popen [%s] fail\n", cmd);
        return NULL;
    }
    

    int i = 0;
    int ch;
    while((ch = fgetc(fp)) != EOF)
    {
        if(ch == '\n')  break;
        
        buf[i] = ch;
        i ++;
    }

    fclose(fp);
    return buf;

}

int user_data_save(const char *name, const char *data, const char *path)
{
    if(!is_data_exists(name, path))
    {
        user_data_add(name, data, path);
    }


    char cmd[256] = {0};

    memset(cmd, 0, sizeof(cmd));
    sprintf(cmd, "sed -i \"s/$(cat %s | grep \"%s\")/%s=%s/g\" %s", path, name, name, data, path);
    system(cmd);


    return 1;

}
