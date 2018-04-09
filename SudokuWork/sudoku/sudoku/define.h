#ifndef __DIFINE__
#define __DIFINE__

// 数独边界大小 
#define SIZE 9

// 解数独棋盘结构 
typedef struct {
	int map[SIZE][SIZE];	// 待解数独盘面 
	int row[SIZE];		// 行 
	int col[SIZE];		// 列 
	int grid[SIZE];		// 九宫格 
} BOARD;

// 输入的字符变为数字 
int change_num(char s[]); 

// 输出写入文件 
void print(FILE* fp,BOARD board,int flag);


#endif
