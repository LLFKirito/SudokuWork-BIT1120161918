/// <summary> 
///	本文件对外提供 create_sudoku(int n)函数，实现构造 n 个不重复数独终局,并输出。 
/// </summary> 
///	<comment> 
///	学号：1120161918 
///	(1+8)%9+1 = 1 
///	</comment> 

#include <stdio.h>
#include "define.h"
#include "initial.h"
#include "create.h"

int shift[9] = { 0, 6, 3, 8, 5, 2, 7, 4, 1 };

int generate_1[2][3] = { {0,1,2}, {0,2,1} };
int generate_2[6][3] = { {3,4,5}, {3,5,4}, {4,3,5}, {4,5,3}, {5,3,4}, {5,4,3} };
int generate_3[6][3] = { {6,7,8}, {6,8,7}, {7,6,8}, {7,8,6}, {8,6,7}, {8,7,6} };

inline void fill(int m,int n,int l,BOARD &backup,BOARD &board)
{
	for(int i=0;i<3;i++) {
		for(int j=0;j<9;j++) {
			board.map[i][j] = backup.map[ generate_1[m][i] ][j] ;
		}
	}
	
	for(int i=3;i<6;i++) {
		for(int j=0;j<9;j++) {
			board.map[i][j] = backup.map[ generate_2[n][i-3] ][j] ;
		}
	}
	
	for(int i=6;i<9;i++) {
		for(int j=0;j<9;j++) {
			board.map[i][j] = backup.map[ generate_3[l][i-6] ][j] ;
		}
	}
}

///	<summary> 生成n个数独终局 </summary>
/// <param name="n"> 需求生成数独终局的数量 </param> 
///	<return> 1:正常生成数独终局; -1:程序执行出错 </return>
int create_sudoku(int n)
{
	//	清空TXT文件；
	
	int count=0;	// 计数，第一次输出不输出空行 
	BOARD board;
	
	for(int i=0;i<40320;i++) {
		BOARD backup;
		
		for(int k=0;k<9;k++) {
			backup.map[0][k] = origin[i][k];
			backup.row[k] = 1022;
			backup.col[k] = 1022;
			backup.grid[k] = 1022;
		}
		
		for(int j=1;j<9;j++) {
			for(int k=0;k<9;k++) {
				backup.map[j][k] = backup.map[0][ (k+shift[j])%9 ] ;
			}
		}
		
		board = backup;	// 输出初始构造 
		for(int j=0;j<6;j++) {
			for(int k=0;k<6;k++) {
				// 1~3行填充方案1 
				if(count<n) {
					fill(0,j,k,backup,board);
					print(board,count);
					count++;
				}
				else if(count==n) return 1;		// 正常完成命令 
				else if(count>=n) return -1;	// 报错:程序执行错误 
				// 1~3行填充方案2 
				if(count<n) {
					fill(1,j,k,backup,board);
					print(board,count);
					count++;
				}
				else if(count==n) return 1;		// 正常完成命令 
				else if(count>=n) return -1;	// 报错:程序执行错误 
			}
		}
	}
	return -1;	// 报错:输入n已经超过能生成的最大个数,并且已经生成 290 3040组 
}
