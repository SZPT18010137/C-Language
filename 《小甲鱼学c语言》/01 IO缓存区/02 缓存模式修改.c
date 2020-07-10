/*
 * 程序：缓存模式修改
 * 作者：吴楚鹏
 * 时间：2020年7月10日
 * 描述：缓冲区的模式有三种：按块模式、按列模式、不缓存，在setvbuf函数里面的表现形式为
 *       _IOFBF/_IOLBF/_IONBF，当模式为按块和按列模式时，先把数据先缓存，然后通过
 *       ffulsh强制刷新缓存区，输出第一行文字，然后等待按下后再执行下一条文字，而当模
 *       式为不缓存的时候，则直接输出两行文字。
 */

/***** 库 *****/
#include <stdio.h>
#include <string.h>

/***** 主函数 *****/
int main(void){
	
	char buff[1024]; // 缓冲区
	
	memset(buff, '\0', sizeof(buff)); // 填入0
	
	#define MODE_IONBF
	
	#ifdef MODE_IOFBF // 设置块缓冲
		setvbuf(stdout, buff, _IOFBF, 1024); 
	#endif
	
	#ifdef MODE_IOLBF // 设置列缓冲
		setvbuf(stdout, buff, _IOLBF, 1024); 
	#endif
	
	#ifdef MODE_IONBF // 设置无缓冲
		setvbuf(stdout, buff, _IONBF, 1024);
	#endif
	
	fprintf(stdout, "Welcome to China\n"); // 第一行输出
	
	fflush(stdout); // 刷新缓存区
	
	fprintf(stdout, "I want to have a dinner\n"); // 第二行输出
	
	getchar();
	
	return 0;
}
