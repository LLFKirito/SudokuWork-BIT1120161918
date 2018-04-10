/// <summary> 
///	本文件实现基本输入输出 
/// </summary> 

#include "stdafx.h"

///	<summary> 输入的字符变为数字  </summary>
/// <return> 
///	-1:不是数字 ; -2: 数字太大 ; -3:输入数字超过题目要求但可以执行 ; else 返回字符串代表的数字 
///	</return> 

#pragma warning(disable:4996)

int change_num(char s[])
{
	int len = strlen(s);

	for (int i = 0; i<len; i++) {
		if (isdigit(s[i])) {
			continue;
		}
		else return -1;	// 返回 -1 表示不是数字 
	}

	if (len>8) return -2;	// 返回-2 表示数字太大

	int num = 0;
	for (int i = 0; i<len; i++) {
		num = num * 10 + s[i] - '0';
	}

	if (num>2903040) return -2;// 返回-2 表示数字太大 
	if (num>1000000 && num <= 2903040) return -3;//// 返回-3 表示输入数字超过题目要求但可以执行 
	return num;
}

///	<summary> 输出写入文件  </summary>
/// <param name="fp"> 指向写入的文件 </param> 
/// <param name="board"> 需要打印的数独局面 </param> 
/// <param name="flag"> 标志(值为0不打印空行) </param> 
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
