#ifndef __DIFINE__
#define __DIFINE__

// �����߽��С 
#define SIZE 9

// ���������̽ṹ 
typedef struct {
	int map[SIZE][SIZE];	// ������������ 
	int row[SIZE];		// �� 
	int col[SIZE];		// �� 
	int grid[SIZE];		// �Ź��� 
} BOARD;

// ������ַ���Ϊ���� 
int change_num(char s[]); 

// ���д���ļ� 
void print(FILE* fp,BOARD board,int flag);


#endif
