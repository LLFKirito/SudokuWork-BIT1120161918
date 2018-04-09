/// <summary> 
///	功能：1.实现向文件输出1 ~ 100 0000个数独终局 (本项目设计最多生成 290 3040 个不重复的数独终局) 
///       2.实现从指定文件读取数独残局，解数独 
/// </summary> 
/// <author> 李林峰 </author> 
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
	
	
	/*程序框输入测试*/
	//char order[100];
	int p,n;
	while( printf("输入执行的命令:"), scanf("%d",&p) ,p ){
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
	
	
	
	//	判断输入是否合法 ；
	//	如果合法，输入记录n：
	//		create_sudoku(n);
	
	
	
	return 0;
}
