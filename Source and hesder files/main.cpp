/// <summary> 
///	���ܣ�1.ʵ�����ļ����1 ~ 100 0000�������վ� (����Ŀ���������� 290 3040 �����ظ��������վ�) 
///       2.ʵ�ִ�ָ���ļ���ȡ�����о֣������� 
/// </summary> 
/// <author> ���ַ� </author> 
///	<student_number> 1120161918 </student_number> 

#include <stdio.h>
#include <string.h>
#include "define.h"
#include "initial.h"
#include "create.h"
#include "solve.h"

int main()
{
	initial_origin();
	
	
	/*������������*/
	//char order[100];
	int p,n;
	while( printf("����ִ�е�����:"), scanf("%d",&p) ,p ){
		if(p==1){
			scanf("%d",&n);
			int examine = create_sudoku(n);
			
			if(examine==-1)
				printf("\nProgram execution error: Wrong on creation of the end of sudoku\n\n");
		}
		
		else if(p==2) {
			solve_sudoku();
		}
		
		printf("\n-----------------------------\n");
		
	}
		
	/***************/
	
	
	
	//	�ж������Ƿ�Ϸ� ��
	//	����Ϸ��������¼n��
	//		create_sudoku(n);
	
	
	
	return 0;
}
