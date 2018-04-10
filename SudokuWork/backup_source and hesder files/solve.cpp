/// <summary> 
///	本文件实现解数独 
/// </summary> 

#include <stdio.h>
#include <string.h>
#include "define.h"
#include "solve.h"

/// <summary> 在数独矩阵中找到第一个待解元素的序号，找不到返回-1 </summary>
inline int find(BOARD &board)
{
	for(int i=0;i<SIZE;i++) {
		for(int j=0;j<SIZE;j++) {
			if( board.map[i][j]==0 ) {
				return i*SIZE+j;
			}
		}
	}
	return -1;
}

inline bool set(BOARD &board,const int loc,const int num)
{
	int r = loc/SIZE;
	int c = loc%SIZE;
	int g = (r/3)*3 + c/3 ;
	
	bool valid =	board.map[r][c] == 0
				  && ( board.row[r] & (1<<num) ) ==0
				  && ( board.col[c] & (1<<num) ) ==0
				  && ( board.grid[g] & (1<<num) ) ==0 ;
	
	if(!valid) {
		return false;
	}
	
	board.map[r][c] = num;
	board.row[r] |= (1<<num) ;
	board.col[c] |= (1<<num) ;
	board.grid[g] |= (1<<num) ;
	
	return true;
}

inline void unset(BOARD &board,const int loc)
{
	int r = loc/SIZE;
	int c = loc%SIZE;
	int g = (r/3)*3 + c/3 ;
	
	int num = board.map[r][c];
	
	board.row[r] ^= (1<<num) ;
	board.col[c] ^= (1<<num) ;
	board.grid[g] ^= (1<<num) ;
	
	board.map[r][c] = 0;
}

/// <summary> 最终返回的board已经填写好数独结果  </summary>
void solution(BOARD &board,BOARD &backup)
{
	int loc = find(backup);
	
	if(loc<0) {
		board = backup;
		return ;
	}
	
	for(int i=1;i<=9;i++) {
		if( set(backup,loc,i) ) {
			solution(board,backup);
			unset(backup,loc);
		}
	}
}

inline void cal_board(BOARD &board)
{
	memset(board.row,0,sizeof(board.row));
	memset(board.col,0,sizeof(board.col));
	memset(board.grid,0,sizeof(board.grid));
	
	int num=0;
	for(int i=0;i<9;i++) {
		for(int j=0;j<9;j++) {
			if(board.map[i][j]!=0) {
				num = board.map[i][j];
				int g = (i/3)*3 + j/3 ;
				board.row[i] |= (1<<num) ;
				board.col[j] |= (1<<num) ;
				board.grid[g] |= (1<<num) ;
			}
		}
	}
}

/// <summary> 将fp读取的题目解出 </summary> 
void solve_sudoku(FILE *fp)
{
	FILE *fp_w;
	fp_w = fopen("sudoku.txt","w");
	
	int flag=0;
	BOARD board;
	
	int tmp;
	while( ~fscanf(fp,"%d",&tmp) ) {
		board.map[0][0] = tmp;
		for(int j=1;j<9;j++) {
			fscanf(fp,"%d",&board.map[0][j]);
		}
		for(int i=1;i<9;i++) {
			for(int j=0;j<9;j++) {
				fscanf(fp,"%d",&board.map[i][j]);
			}
		}
		
		cal_board(board);
		
		BOARD backup = board;
		solution(board,backup);
		print(fp_w,board,flag);
		flag=1;
	}
	
	fclose(fp);
	fclose(fp_w);
}
