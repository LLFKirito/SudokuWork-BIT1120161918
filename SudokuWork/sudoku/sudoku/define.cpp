/// <summary> 
///	���ļ�ʵ�ֻ���������� 
/// </summary> 

#include "stdafx.h"

///	<summary> ������ַ���Ϊ����  </summary>
/// <return> 
///	-1:�������� ; -2: ����̫�� ; -3:�������ֳ�����ĿҪ�󵫿���ִ�� ; else �����ַ������������ 
///	</return> 

#pragma warning(disable:4996)

int change_num(char s[])
{
	int len = strlen(s);

	for (int i = 0; i<len; i++) {
		if (isdigit(s[i])) {
			continue;
		}
		else return -1;	// ���� -1 ��ʾ�������� 
	}

	if (len>8) return -2;	// ����-2 ��ʾ����̫��

	int num = 0;
	for (int i = 0; i<len; i++) {
		num = num * 10 + s[i] - '0';
	}

	if (num>2903040) return -2;// ����-2 ��ʾ����̫�� 
	if (num>1000000 && num <= 2903040) return -3;//// ����-3 ��ʾ�������ֳ�����ĿҪ�󵫿���ִ�� 
	return num;
}

///	<summary> ���д���ļ�  </summary>
/// <param name="fp"> ָ��д����ļ� </param> 
/// <param name="board"> ��Ҫ��ӡ���������� </param> 
/// <param name="flag"> ��־(ֵΪ0����ӡ����) </param> 
void print(FILE* fp, BOARD board, int flag)
{
	if (flag != 0)
		fputc('\n', fp);
	for (int i = 0; i<9; i++) {
		for (int j = 0; j<9; j++) {
			fprintf(fp, "%d%c", board.map[i][j], j == 8 ? '\n' : ' ');
		}
	}
}
