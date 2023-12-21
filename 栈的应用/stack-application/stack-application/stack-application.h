// stack-application.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

#pragma once

#include <iostream>

// TODO: 在此处引用程序需要的其他标头。
#include<iostream>
#include<stack>
using namespace std;
int cope_(string a); // 计算运算
int compare(char a, char b);//比较运算符号优先级
int judge(char a);//判断符号类型
int Calculate(char oper, int a, int b);//计算
#define  high 1  // 判断运算优先级
#define  low 2
#define  equal 0


#define operator 3 // 判断符号类型
#define number 4
#define error 5