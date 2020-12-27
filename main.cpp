#include "stunode.h"
#include "conio.h"
using namespace std; 

//初始化一个单链表
bool InitStudents(StuList &Students){
	Students = (StuNode *) malloc(sizeof(StuNode));
	Students->next = NULL;
	return true;
}


//读取数据文件
bool ReadFile(StuList &Students){
	char xh[STRLEN];
	char xm[STRLEN];
	char xb[STRLEN];
	char nl[STRLEN];
	char zy[STRLEN];
	FILE *fp = fopen("students.txt","r");
	StuNode *s = (StuNode *)malloc(sizeof(StuNode));
	if(fp == NULL){
		return false;
	}
	while(fscanf(fp,"%s %s %s %s %s\n",xh,xm,xb,nl,zy) != EOF){
		strcpy(s->xh,xh);
		strcpy(s->xm,xm);
		strcpy(s->xb,xb);
		strcpy(s->nl,nl);
		strcpy(s->zy,zy);
		s->next = Students->next;
		Students->next = s;
    }
    fclose(fp);
	return true;
} 


//将数据存储到文件中
bool WriteFile(StuList Students){
	FILE *fp = fopen("students.txt","w");
	StuNode *s = Students->next;
	if(fp == NULL){
		return false;
	}
	while(s != NULL){
        fprintf(fp,"%s %s %s %s %s\n",s->xh,s->xm,s->xb,s->nl,s->zy);
        s=s->next;
    }
    fclose(fp);
	return true;
} 


//新增学生信息 
bool InsertStu(StuList &Students,char xh[],char xm[],char xb[],char nl[],char zy[]){
	StuNode *s = (StuNode *)malloc(sizeof(StuNode));
	strcpy(s->xh,xh);
	strcpy(s->xm,xm);
	strcpy(s->xb,xb);
	strcpy(s->nl,nl);
	strcpy(s->zy,zy);
	s->next = Students->next;
	Students->next = s;
	return true;
} 

//输入字符串
void getstr(char str[]){
	memset(str,'\0',STRLEN);   //把数组设置为空
	char ch;
	cin>>ch;
	int i=0;
	while(ch != '\n' && i < STRLEN){
		str[i] = ch;
		ch = getchar();
		i++;
	}
}

//判断某个学号是否存在
bool JudgeStu(StuList Students,char xh[]){
	StuNode *p = Students;
	while(p->next != NULL){
		if(strcmp(xh,p->next->xh) == 0){ 
			return true;//存在，返回true 
		}
		p=p->next;
	}
	if(p->next == NULL){
		return false;//不存在，返回false 
	}
} 

//删除指定姓名学生信息 
bool DelStu(StuList Students,char xm[]){
	StuNode *p = Students;
	while(p->next != NULL){
		if(strcmp(xm,p->next->xm) == 0){
			break;
		}
		p=p->next;
	}
	if(p->next == NULL){
		return false;//未查询到该学生
	}
	StuNode *q = p->next;
	p->next = q->next;
	free(q);
	return true;
}

//删除指定学号学生信息 
bool DelStuByXh(StuList Students,char xh[]){
	StuNode *p = Students;
	while(p->next != NULL){
		if(strcmp(xh,p->next->xh) == 0){
			break;
		}
		p=p->next;
	}
	if(p->next == NULL){
		return false;//未查询到该学生
	}
	StuNode *q = p->next;
	p->next = q->next;
	free(q);
	return true;
}



//获取指定学号学生的指针
StuNode *GetStuByXh(StuList Students,char xh[]){
	StuNode *p = Students->next;
	while(p != NULL){
		if(strcmp(xh,p->xh) == 0){
			break;
		}
		p = p->next;
	}
	return p;
} 

//获取指定姓名学生的指针
StuNode *GetStuByXm(StuList Students,char xm[]){
	StuNode *p = Students->next;
	while(p != NULL){
		if(strcmp(xm,p->xm) == 0){
			break;
		}
		p = p->next;
	}
	return p;
} 



//修改指定学生信息 
bool UpdateStu(StuList Students,StuNode *p,char xh[],char xm[],char xb[],char nl[],char zy[]){ 

	//判断学号是否重复
	StuNode *s = Students->next;
	while(s != NULL){
		if(s == p){
			s = s->next;
			continue;
		}
		if(strcmp(s->xh,xh) == 0){
			return false;
		}
		s=s->next;
	}
	
	strcpy(p->xh,xh);
	strcpy(p->xm,xm);
	strcpy(p->xb,xb);
	strcpy(p->nl,nl);
	strcpy(p->zy,zy);
	return true;
}


//查询所有学生信息 
void SelectAllStudents(StuList Students){
	StuNode *p = Students->next;
	cout<<"\t"<<"学号"<<"\t"<<"\t"<<"姓名"<<"\t"<<"性别"<<"\t"<<"年龄"<<"\t"<<"专业"<<endl;
	if(p==NULL){
		cout<<"\t\t"<<"暂时还没有学生信息"<<endl;
	}
	while(p!=NULL){
		cout<<"\t"<<p->xh<<"\t"<<p->xm<<"\t"<<p->xb<<"\t"<<p->nl<<"\t"<<p->zy<<endl;
		p=p->next;
	}
}

//查询指定专业的学生信息 
void SelectStudentsByZy(StuList Students,char zy[]){
	StuNode *p = Students->next;
	cout<<"\t"<<"学号"<<"\t"<<"\t"<<"姓名"<<"\t"<<"性别"<<"\t"<<"年龄"<<"\t"<<"专业"<<endl;
	if(p==NULL){
		cout<<"             暂时还没有学生信息"<<endl;
	}
	while(p!=NULL){
		if(strcmp(zy,p->zy) == 0){
			cout<<"\t"<<p->xh<<"\t"<<p->xm<<"\t"<<p->xb<<"\t"<<p->nl<<"\t"<<p->zy<<endl;
		}
		p=p->next;
	}
} 

//查询指定姓名的学生数量
int SelectStudentsNumByXm(StuList Students,char xm[]){
	int count = 0;
	StuNode *p = Students->next;
	 while(p != NULL){
		if(strcmp(xm,p->xm) == 0){
			count++;
		}
		p=p->next;
	}
	return count;
} 



//主函数 
int main(int argc, char** argv) {
	StuList Students;
	InitStudents(Students);
	char xh[STRLEN];
	char xm[STRLEN];
	char xb[STRLEN];
	char nl[STRLEN];
	char zy[STRLEN];
	char x;
	char flag='a';
	if(ReadFile(Students) == false){
		cout<<"数据文件不存在，读取数据失败！"<<endl;	
	}else{
		cout<<"读取数据成功！"<<endl; 
	}
	while(flag != 27){//判断是否按下esc键 
		cout<<"******************************"<<endl;
		cout<<"	  功能菜单"<<endl;
		cout<<" 1	查看所有学生信息"<<endl;
		cout<<" 2	新增一条学生信息"<<endl;
		cout<<" 3	删除指定学生信息"<<endl;
		cout<<" 4	修改指定学生信息"<<endl;
		cout<<" 5	查询指定专业学生信息"<<endl;
		cout<<" 6	保存数据"<<endl; 
		cout<<" 7	退出程序"<<endl; 
		cout<<"请输入要选择的功能编号：";
		cin>>x; 
		cout<<endl;
		if(x == '1'){
			SelectAllStudents(Students);
		}else if(x == '2'){
			cout<<"请输入学生信息"<<endl; 
			cout<<"学号："; 
			getstr(xh); 
			cout<<"姓名："; 
			getstr(xm); 
			cout<<"性别："; 
			getstr(xb); 
			cout<<"年龄："; 
			getstr(nl); 
			cout<<"专业："; 
			getstr(zy); 
			//判断该学号是否存在
			if(!JudgeStu(Students,xh)){
				//不存在，新增 
				if(InsertStu(Students,xh,xm,xb,nl,zy)){
					cout<<"新增成功！"<<endl; 
				};
			} else{
				cout<<"新增失败，该学号已存在！"<<endl;
			} 
		}else if(x == '3'){
			cout<<"请输入要删除的学生的姓名"<<endl;
			getstr(xm); 
			if(SelectStudentsNumByXm(Students,xm) == 0){  //判断该姓名的学生数量 ,为0时，该学生不存在，删除失败 
				cout<<"删除失败，该学生不存在！"<<endl;
			}else if(SelectStudentsNumByXm(Students,xm) > 1){  //判断该姓名的学生数量 ，大于1时，请用户输入学号 
				cout<<"存在多个同名学生，请输入学号：";
				getstr(xh);
				if(DelStuByXh(Students,xh)){
					cout<<"删除成功！"<<endl; 
				}else{
					cout<<"删除失败，该学生不存在！"<<endl;
				} 
				 
			}else{//只有一个学生，直接删除 
				if(DelStu(Students,xm)){  
					cout<<"删除成功！"<<endl; 
				}else{
					cout<<"删除失败，该学生不存在！"<<endl;
				} 
			}
		}else if(x == '4'){
			cout<<"请输入要修改的学生的姓名"<<endl;
			char xm1[STRLEN];
			getstr(xm1);
			if(SelectStudentsNumByXm(Students,xm1) == 0){//判断该姓名的学生数量 ,为0时，该学生不存在，修改失败 
				cout<<"修改失败，该学生不存在！"<<endl;
			}else if(SelectStudentsNumByXm(Students,xm1) > 1){  //判断该姓名的学生数量 ，大于1时，请用户输入学号 
				cout<<"存在多个同名学生，请输入学号：";
				char xh1[STRLEN];
				getstr(xh1);
				
				cout<<"请输入修改后的学生信息"<<endl; 
				cout<<"学号："; 
				getstr(xh); 
				cout<<"姓名："; 
				getstr(xm); 
				cout<<"性别："; 
				getstr(xb); 
				cout<<"年龄："; 
				getstr(nl); 
				cout<<"专业："; 
				getstr(zy); 
				
				StuNode * p =  GetStuByXh(Students,xh1);
				
				if(p == NULL){
					cout<<"修改失败，该学生不存在！"<<endl;
				}else{
					if(UpdateStu(Students,p,xh,xm,xb,nl,zy)){
						cout<<"修改成功！"<<endl; 
					}else{
						cout<<"修改失败，该学号已存在！"<<endl;
					}
				} 
				
			}else{//只有一个学生，直接修改 
				
				cout<<"请输入修改后的学生信息"<<endl; 
				cout<<"学号："; 
				getstr(xh); 
				cout<<"姓名："; 
				getstr(xm); 
				cout<<"性别："; 
				getstr(xb); 
				cout<<"年龄："; 
				getstr(nl); 
				cout<<"专业："; 
				getstr(zy); 
				
				StuNode * p =  GetStuByXm(Students,xm1);
				
				if(p == NULL){
					cout<<"修改失败，该学生不存在！"<<endl;
				}else{
					if(UpdateStu(Students,p,xh,xm,xb,nl,zy)){
						cout<<"修改成功！"<<endl; 
					}else{
						cout<<"修改失败，该学号已存在！"<<endl;
					}
				}
			}
		}else if(x == '5'){
			cout<<"请输入要查询的专业的名称：";
			getstr(zy);
			SelectStudentsByZy(Students,zy);
		}else if(x == '6'){
			if(WriteFile(Students) == true){
				cout<<"数据存储成功！"<<endl;
			}
		}else if(x == '7'){
			break;
		} 
		cout<<endl<<"按下esc键结束程序，按下其他任意键返回功能选择菜单。"<<endl;
		flag = getch();
	} 
	return 0;
}
