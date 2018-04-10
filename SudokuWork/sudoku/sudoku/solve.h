#pragma once
#include "stdafx.h"

// 最终返回的board已经填写好数独结果 
void solution(BOARD &board, BOARD &backup);

// 将fp读取的题目解出
void solve_sudoku(FILE *fp);