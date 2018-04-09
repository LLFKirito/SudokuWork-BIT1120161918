/// <summary> 
///	���ļ������ṩ initial_origin()������Ϊ origin �����ʼ�� 
///	���ļ������ṩ origin���飬������ 290 3040 �����ظ��������վ� 
/// </summary> 

#include "initial.h"

int origin[40320][9] = { 0 };	// ���2~8ȫ���У���1λ����ѧ��Ҫ����1 
int init[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};

int count = 0;

/// <summary> ʵ�ֽ��������� </summary> 
inline void swap(int& a,int& b)
{
	int temp=a;	 a=b;	b=temp;
}

/// <summary> �ݹ���ȡȫ���� </summary>
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

/// <summary> ��ʼ��ȫ�������� </summary>
void initial_origin()
{
	count = 0;
	permutation(1);
}
