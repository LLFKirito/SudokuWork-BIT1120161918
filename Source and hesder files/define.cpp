/// <summary> 
///	本文件实现基本输入输出 
/// </summary> 

#include <stdio.h>
#include "define.h"

///	<summary> 输入读取文件  </summary>


///	<summary> 输出写入文件  </summary>
/// <param name="board"> 需要打印的数独局面 </param> 
/// <param name="flag"> 标志(值为0不打印空行) </param> 
void print(BOARD board,int flag)
{
	if(flag!=0) putchar('\n');
	for(int i=0;i<9;i++) {
		for(int j=0;j<9;j++) {
			printf("%d%c",board.map[i][j],j==8?'\n':' ');
		}
	}
}
