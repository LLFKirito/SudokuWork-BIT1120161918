/// <summary> 
///	本文件对外提供 initial_origin()函数，为 origin 数组初始化 
///	本文件对外提供 origin数组，供生成 290 3040 个不重复的数独终局 
/// </summary> 

#include "initial.h"

int origin[40320][9] = { 0 };	// 存放2~8全排列，第1位根据学号要求存放1 
int init[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};

int count = 0;

/// <summary> 实现交换两个数 </summary> 
inline void swap(int& a,int& b)
{
	int temp=a;	 a=b;	b=temp;
}

/// <summary> 递归求取全排列 </summary>
void permutation(int offset)
{
    if(offset == 8) {
		for(int i=0;i<9;i++) {
			origin[count][i]=init[i];
		}
		count++;
		return;
    }
	for(int i=offset;i<9;i++) {
		swap(init[i], init[offset]);
		permutation(offset + 1);
		swap(init[i], init[offset]);
    }
}

/// <summary> 初始化全排列数组 </summary>
void initial_origin()
{
	count = 0;
	permutation(1);
}
