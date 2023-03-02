
#include <string.h>

#include "func.h"
#include "wasApp.h"


int bin_set_bit(int *num, int src, int bit)
{
    switch (bit)
    {
    case 0x000000FF:
        *num |= (*num & bit) | src;
        break;

    case 0x0000FF00:
        *num |= (*num & bit) | src << 8;
        break;

    case 0x00FF0000:
        *num |= (*num & bit) | src << 16;
        
        break;   

    case 0xFF000000:
        *num |= (*num & bit) | src << 24;
        break;
    
    default:
        LOG_RED("bit %#08X is not avliable...\n", bit);
        break;
    }

    return *num;
}



int bin_get_bit(int num, int bit)
{
    switch (bit)
    {
    case 0x000000FF:    /* 低8 */
        num = (num & bit) >> 0;
        break;

    case 0x0000FF00:    /* 高8 */
        num = (num & bit) >> 8;
        break;

    case 0x00FF0000:
        num = (num & bit) >> 16;
        break;   

    case 0xFF000000:
        num = (num & bit) >> 24;
        break;
    
    default:
        LOG_RED("bit %#08X is not avliable...\n", bit);
        break;
    }

    return num;
}

char *bin_print(int num)
{
	int i, j, m = 0;	
	static char buf[] = "00000000 00000000 00000000 00000000\0";
	memset(buf, 0, sizeof(buf));

	unsigned char *p = (unsigned char *)&num + 3; // p先指向num后面第3个字节的地址，即num的最高位字节地址

	for (i = 0; i < 4; i++) 			// 依次处理4个字节(32位）
	{
		j = *(p - i);				 	// 取每个字节的首地址，从高位字节到低位字节，即p p-1 p-2 p-3地址处
		for (int k = 7; k >= 0; k--) 	// 处理每个字节的8个位，注意字节内部的二进制数是按照人的习惯存储！
		{
			if (j & (1 << k)) 			// 1左移k位，与单前的字节内容j进行或运算，如k=7时，00000000&10000000=0 ->该字节的最高位为0
			{
				buf[m] = '1';
				m++;
			}
			else
			{
				buf[m] = '0';
				m++;
			}
		}
		buf[m] = ' ';	// 每8位加个空格，方便查看
		m++;
		
	}
	// LOG_WHITE("[%d]\t二进制输出:%s\n", num, buf);
	return buf;


	#if (0)
	{
		// 使用unsigned char来验证int的每一个字节
		unsigned char *p1 = (unsigned char *)&num;	   // 获取a的首地址
		unsigned char *p2 = (unsigned char *)&num + 1; // 获取a的首地址的后一个字节地址
		unsigned char *p3 = (unsigned char *)&num + 2; // 获取a的首地址的后两个字节地址
		unsigned char *p4 = (unsigned char *)&num + 3; // 获取a的首地址的后三个字节地址

		printf(" p1:%p, %d\r\n", p1, *p1); // 打印p1的地址与存储的字节内容
		printf(" p2:%p, %d\r\n", p2, *p2); // 打印p2的地址与存储的字节内容
		printf(" p3:%p, %d\r\n", p3, *p3); // 打印p3的地址与存储的字节内容
		printf(" p4:%p, %d\r\n", p4, *p4); // 打印p4的地址与存储的字节内容
	}
	#endif
}


bool is_file_exists(char *file_path)
{
	if(access(file_path, F_OK) == 0)
	{
		return true;
	}

	return false;
}