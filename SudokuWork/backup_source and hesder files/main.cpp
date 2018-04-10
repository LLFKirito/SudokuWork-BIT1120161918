/// <summary> 
///	���ܣ�1.ʵ�����ļ����1 ~ 100 0000�������վ� (����Ŀ���������� 290 3040 �����ظ��������վ�) 
///       2.ʵ�ִ�ָ���ļ���ȡ�����о֣������� 
/// </summary> 
/// <author> ���ַ� </author> 
///	<student_number> 1120161918 </student_number> 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "define.h"
#include "initial.h"
#include "create.h"
#include "solve.h"

int main(int argc,char* argv[])
{
	if( strcmp(argv[1],"-c") == 0 ) {
		int num = change_num(argv[2]);
		
		if(num==-1)
			printf("\nWrong: Please input correctly!\n");
		else if(num==-2)
			printf("\nWrong: The number you entered exceeds the maximun range!\n");
		else if(num==-3)
			printf("\nWrong: The number you entered exceeds the maximun range!\n");
		else if(num==0)
			printf("\nWrong: Please input correctly!\n");
		else {
			if(origin[0][0]==0) {
				initial_origin();
			}
				
			int examine = create_sudoku(num);
			
			if(examine==-1)
				printf("\nProgram Execution Error: Wrong on creation of the end of sudoku.\n");
		}
	}
	else if( strcmp(argv[1],"-s") == 0 ) {
		FILE *fp;
		fp = fopen(argv[2],"r");
		if( fp == NULL ) {
			printf("\nWrong: File open failed.\n");
		}
		solve_sudoku(fp);
	}
	
	return 0;
}
