#ifndef __USER_DATA_API_H__
#define __USER_DATA_API_H__


/*************************************************************************
 * @brief  读取数据
 * @date   2023-02-22 11:04
 * @author xiaole
 * @return 读取成功时， 返回对应的内容， 失败时返回NULL
 * @param  name 数据名
 * @param  path 文件路径 
 **************************************************************************/
const char *user_data_read(const char *name, const char *path);


/*************************************************************************
 * @brief  保存数据
 * @date   2023-02-22 11:03
 * @author xiaole
 * @return [1] 成功
 * @param  name 数据名
 * @param  data 数据
 * @param  path 文件路径
 **************************************************************************/
int user_data_save(const char *name, const char *data, const char *path);





#endif /* __USER_DATA_API_H__ */