#ifndef __USER_DATA_API_H__
#define __USER_DATA_API_H__

/*************************************************************************
 * @brief  数据是否存在
 * @date   2023-02-22 15:57
 * @author xiaole
 * @return true(存在) / false(不存在)
 * @param  name 数据名
 * @param  path 文件路径 
 **************************************************************************/
bool IsUserDataExists(const char *name, const char *path);

/*************************************************************************
 * @brief  读取数据
 * @date   2023-02-22 11:04
 * @author xiaole
 * @return 读取成功时， 返回对应的内容， 失败时返回NULL
 * @param  name 数据名
 * @param  path 文件路径 
 **************************************************************************/
const char *UserDataRead(const char *name, const char *path);


/*************************************************************************
 * @brief  保存数据
 * @date   2023-02-22 11:03
 * @author xiaole
 * @return [1] 成功
 * @param  name 数据名
 * @param  data 数据
 * @param  path 文件路径
 **************************************************************************/
int UserDataSave(const char *name, const char *data, const char *path);





#endif /* __USER_DATA_API_H__ */