/*
 * ������getchar�������
 * ���ߣ������
 * ʱ�䣺2020��7��10��
 * ���������ļ�д��һ���ַ�������һ��ִ�е�getchar��������������fclose֮ǰ��
 *       ����һֱ�ȴ�getchar������������������û���������ļ��С������ַ���
 *       û�����ļ���
 */

/***** �� *****/
#include <stdio.h>
#include <stdlib.h>

/***** ������ *****/
int main(void){
	
	FILE *fp; // �ļ�ָ��
	
	fp = fopen("output.txt", "w"); // ��д�ķ�ʽ���ļ�
	
	if(fp == NULL){
		/* ��ʧ�� */
		perror("���ļ�ʧ�ܣ�");
		exit(EXIT_FAILURE);
	}
	
	fputs("�����ţ��\n", fp); // ���ļ�д������
	
	getchar(); // �ȴ�����
	
	fclose(fp); // �ر��ļ�
	
	return 0;
}
