/*
 * 程序：用getchar阻隔缓冲
 * 作者：吴楚鹏
 * 时间：2020年7月10日
 * 描述：向文件写入一段字符串，下一步执行到getchar函数，由于它在fclose之前，
 *       所以一直等待getchar结束，缓冲区的数据没有立即到文件中。所以字符串
 *       没有在文件。
 */

/***** 库 *****/
#include <stdio.h>
#include <stdlib.h>

/***** 主函数 *****/
int main(void){
	
	FILE *fp; // 文件指针
	
	fp = fopen("output.txt", "w"); // 以写的方式打开文件
	
	if(fp == NULL){
		/* 打开失败 */
		perror("打开文件失败：");
		exit(EXIT_FAILURE);
	}
	
	fputs("吴楚鹏牛逼\n", fp); // 向文件写入数据
	
	getchar(); // 等待输入
	
	fclose(fp); // 关闭文件
	
	return 0;
}
