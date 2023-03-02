/*************************************************************************
 * @brief  用户数据读取和保存
 * @date   2023-02-22 16:34
 * @author xiaole
 * @note   根据数据名称来存储数据， 所存储的数据可直接打开， 
 * 通过"sed cat grep aws" 等命令和popen()函数来读取文件
 * 如pwd=123456， 修改时会通过[sed -i "s/pwd=/pwd=123123/g file_path" ] 命令来修改
 **************************************************************************/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "wasApp.h"

bool IsUserDataExists(const char *name, const char *path)
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

int UserDataAdd(const char *name, const char *data, const char *path)
{
    char cmd[256] = {0};

    memset(cmd, 0, sizeof(cmd));
    sprintf(cmd, "echo %s=%s >> %s", name, data, path);
    system(cmd);

    return 1;
}

const char *UserDataRead(const char *name, const char *path)
{
    if(!IsUserDataExists(name, path)) return NULL;

    static char buf[16]  = {0};
    char cmd[256] = {0};
    
    sprintf(cmd, "cat %s | grep \"%s=\" | awk -F \"=\" '{print $2}'", path, name);
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
        
        buf[i++] = ch;
        // i++;
    }

    fclose(fp);

    

    if(buf[0] == 0) return NULL;
    
    return buf;

}

int UserDataSave(const char *name, const char *data, const char *path)
{
    if(!IsUserDataExists(name, path))
    {
        UserDataAdd(name, data, path);
    }


    char cmd[256] = {0};

    memset(cmd, 0, sizeof(cmd));
    sprintf(cmd, "sed -i \"s/$(cat %s | grep \"%s=\")/%s=%s/g\" %s", path, name, name, data, path);
    system(cmd);


    return 1;

}

