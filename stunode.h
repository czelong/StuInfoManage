#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define STRLEN 15
//定义学生链表 
typedef struct StuNode{
	char xh[STRLEN];//学号 
	char xm[STRLEN];//姓名 
	char xb[STRLEN];//性别 
	char nl[STRLEN];//年龄 
	char zy[STRLEN];//专业
	struct StuNode *next;
}StuNode,*StuList;
