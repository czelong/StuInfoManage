#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define STRLEN 15
//����ѧ������ 
typedef struct StuNode{
	char xh[STRLEN];//ѧ�� 
	char xm[STRLEN];//���� 
	char xb[STRLEN];//�Ա� 
	char nl[STRLEN];//���� 
	char zy[STRLEN];//רҵ
	struct StuNode *next;
}StuNode,*StuList;
