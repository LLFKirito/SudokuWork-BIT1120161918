#include <stdio.h>
#include "define.h"

// �����ȡ�ļ� 


// ���д���ļ� 
void print(BOARD board,int flag)
{
	if(flag!=0) putchar('\n');
	for(int i=0;i<9;i++) {
		for(int j=0;j<9;j++) {
			printf("%d%c",board.map[i][j],j==8?'\n':' ');
		}
	}
}
