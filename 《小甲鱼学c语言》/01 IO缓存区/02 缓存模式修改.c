/*
 * ���򣺻���ģʽ�޸�
 * ���ߣ������
 * ʱ�䣺2020��7��10��
 * ��������������ģʽ�����֣�����ģʽ������ģʽ�������棬��setvbuf��������ı�����ʽΪ
 *       _IOFBF/_IOLBF/_IONBF����ģʽΪ����Ͱ���ģʽʱ���Ȱ������Ȼ��棬Ȼ��ͨ��
 *       ffulshǿ��ˢ�»������������һ�����֣�Ȼ��ȴ����º���ִ����һ�����֣�����ģ
 *       ʽΪ�������ʱ����ֱ������������֡�
 */

/***** �� *****/
#include <stdio.h>
#include <string.h>

/***** ������ *****/
int main(void){
	
	char buff[1024]; // ������
	
	memset(buff, '\0', sizeof(buff)); // ����0
	
	#define MODE_IONBF
	
	#ifdef MODE_IOFBF // ���ÿ黺��
		setvbuf(stdout, buff, _IOFBF, 1024); 
	#endif
	
	#ifdef MODE_IOLBF // �����л���
		setvbuf(stdout, buff, _IOLBF, 1024); 
	#endif
	
	#ifdef MODE_IONBF // �����޻���
		setvbuf(stdout, buff, _IONBF, 1024);
	#endif
	
	fprintf(stdout, "Welcome to China\n"); // ��һ�����
	
	fflush(stdout); // ˢ�»�����
	
	fprintf(stdout, "I want to have a dinner\n"); // �ڶ������
	
	getchar();
	
	return 0;
}
