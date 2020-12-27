#include "stunode.h"
#include "conio.h"
using namespace std; 

//��ʼ��һ��������
bool InitStudents(StuList &Students){
	Students = (StuNode *) malloc(sizeof(StuNode));
	Students->next = NULL;
	return true;
}


//��ȡ�����ļ�
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


//�����ݴ洢���ļ���
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


//����ѧ����Ϣ 
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

//�����ַ���
void getstr(char str[]){
	memset(str,'\0',STRLEN);   //����������Ϊ��
	char ch;
	cin>>ch;
	int i=0;
	while(ch != '\n' && i < STRLEN){
		str[i] = ch;
		ch = getchar();
		i++;
	}
}

//�ж�ĳ��ѧ���Ƿ����
bool JudgeStu(StuList Students,char xh[]){
	StuNode *p = Students;
	while(p->next != NULL){
		if(strcmp(xh,p->next->xh) == 0){ 
			return true;//���ڣ�����true 
		}
		p=p->next;
	}
	if(p->next == NULL){
		return false;//�����ڣ�����false 
	}
} 

//ɾ��ָ������ѧ����Ϣ 
bool DelStu(StuList Students,char xm[]){
	StuNode *p = Students;
	while(p->next != NULL){
		if(strcmp(xm,p->next->xm) == 0){
			break;
		}
		p=p->next;
	}
	if(p->next == NULL){
		return false;//δ��ѯ����ѧ��
	}
	StuNode *q = p->next;
	p->next = q->next;
	free(q);
	return true;
}

//ɾ��ָ��ѧ��ѧ����Ϣ 
bool DelStuByXh(StuList Students,char xh[]){
	StuNode *p = Students;
	while(p->next != NULL){
		if(strcmp(xh,p->next->xh) == 0){
			break;
		}
		p=p->next;
	}
	if(p->next == NULL){
		return false;//δ��ѯ����ѧ��
	}
	StuNode *q = p->next;
	p->next = q->next;
	free(q);
	return true;
}



//��ȡָ��ѧ��ѧ����ָ��
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

//��ȡָ������ѧ����ָ��
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



//�޸�ָ��ѧ����Ϣ 
bool UpdateStu(StuList Students,StuNode *p,char xh[],char xm[],char xb[],char nl[],char zy[]){ 

	//�ж�ѧ���Ƿ��ظ�
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


//��ѯ����ѧ����Ϣ 
void SelectAllStudents(StuList Students){
	StuNode *p = Students->next;
	cout<<"\t"<<"ѧ��"<<"\t"<<"\t"<<"����"<<"\t"<<"�Ա�"<<"\t"<<"����"<<"\t"<<"רҵ"<<endl;
	if(p==NULL){
		cout<<"\t\t"<<"��ʱ��û��ѧ����Ϣ"<<endl;
	}
	while(p!=NULL){
		cout<<"\t"<<p->xh<<"\t"<<p->xm<<"\t"<<p->xb<<"\t"<<p->nl<<"\t"<<p->zy<<endl;
		p=p->next;
	}
}

//��ѯָ��רҵ��ѧ����Ϣ 
void SelectStudentsByZy(StuList Students,char zy[]){
	StuNode *p = Students->next;
	cout<<"\t"<<"ѧ��"<<"\t"<<"\t"<<"����"<<"\t"<<"�Ա�"<<"\t"<<"����"<<"\t"<<"רҵ"<<endl;
	if(p==NULL){
		cout<<"             ��ʱ��û��ѧ����Ϣ"<<endl;
	}
	while(p!=NULL){
		if(strcmp(zy,p->zy) == 0){
			cout<<"\t"<<p->xh<<"\t"<<p->xm<<"\t"<<p->xb<<"\t"<<p->nl<<"\t"<<p->zy<<endl;
		}
		p=p->next;
	}
} 

//��ѯָ��������ѧ������
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



//������ 
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
		cout<<"�����ļ������ڣ���ȡ����ʧ�ܣ�"<<endl;	
	}else{
		cout<<"��ȡ���ݳɹ���"<<endl; 
	}
	while(flag != 27){//�ж��Ƿ���esc�� 
		cout<<"******************************"<<endl;
		cout<<"	  ���ܲ˵�"<<endl;
		cout<<" 1	�鿴����ѧ����Ϣ"<<endl;
		cout<<" 2	����һ��ѧ����Ϣ"<<endl;
		cout<<" 3	ɾ��ָ��ѧ����Ϣ"<<endl;
		cout<<" 4	�޸�ָ��ѧ����Ϣ"<<endl;
		cout<<" 5	��ѯָ��רҵѧ����Ϣ"<<endl;
		cout<<" 6	��������"<<endl; 
		cout<<" 7	�˳�����"<<endl; 
		cout<<"������Ҫѡ��Ĺ��ܱ�ţ�";
		cin>>x; 
		cout<<endl;
		if(x == '1'){
			SelectAllStudents(Students);
		}else if(x == '2'){
			cout<<"������ѧ����Ϣ"<<endl; 
			cout<<"ѧ�ţ�"; 
			getstr(xh); 
			cout<<"������"; 
			getstr(xm); 
			cout<<"�Ա�"; 
			getstr(xb); 
			cout<<"���䣺"; 
			getstr(nl); 
			cout<<"רҵ��"; 
			getstr(zy); 
			//�жϸ�ѧ���Ƿ����
			if(!JudgeStu(Students,xh)){
				//�����ڣ����� 
				if(InsertStu(Students,xh,xm,xb,nl,zy)){
					cout<<"�����ɹ���"<<endl; 
				};
			} else{
				cout<<"����ʧ�ܣ���ѧ���Ѵ��ڣ�"<<endl;
			} 
		}else if(x == '3'){
			cout<<"������Ҫɾ����ѧ��������"<<endl;
			getstr(xm); 
			if(SelectStudentsNumByXm(Students,xm) == 0){  //�жϸ�������ѧ������ ,Ϊ0ʱ����ѧ�������ڣ�ɾ��ʧ�� 
				cout<<"ɾ��ʧ�ܣ���ѧ�������ڣ�"<<endl;
			}else if(SelectStudentsNumByXm(Students,xm) > 1){  //�жϸ�������ѧ������ ������1ʱ�����û�����ѧ�� 
				cout<<"���ڶ��ͬ��ѧ����������ѧ�ţ�";
				getstr(xh);
				if(DelStuByXh(Students,xh)){
					cout<<"ɾ���ɹ���"<<endl; 
				}else{
					cout<<"ɾ��ʧ�ܣ���ѧ�������ڣ�"<<endl;
				} 
				 
			}else{//ֻ��һ��ѧ����ֱ��ɾ�� 
				if(DelStu(Students,xm)){  
					cout<<"ɾ���ɹ���"<<endl; 
				}else{
					cout<<"ɾ��ʧ�ܣ���ѧ�������ڣ�"<<endl;
				} 
			}
		}else if(x == '4'){
			cout<<"������Ҫ�޸ĵ�ѧ��������"<<endl;
			char xm1[STRLEN];
			getstr(xm1);
			if(SelectStudentsNumByXm(Students,xm1) == 0){//�жϸ�������ѧ������ ,Ϊ0ʱ����ѧ�������ڣ��޸�ʧ�� 
				cout<<"�޸�ʧ�ܣ���ѧ�������ڣ�"<<endl;
			}else if(SelectStudentsNumByXm(Students,xm1) > 1){  //�жϸ�������ѧ������ ������1ʱ�����û�����ѧ�� 
				cout<<"���ڶ��ͬ��ѧ����������ѧ�ţ�";
				char xh1[STRLEN];
				getstr(xh1);
				
				cout<<"�������޸ĺ��ѧ����Ϣ"<<endl; 
				cout<<"ѧ�ţ�"; 
				getstr(xh); 
				cout<<"������"; 
				getstr(xm); 
				cout<<"�Ա�"; 
				getstr(xb); 
				cout<<"���䣺"; 
				getstr(nl); 
				cout<<"רҵ��"; 
				getstr(zy); 
				
				StuNode * p =  GetStuByXh(Students,xh1);
				
				if(p == NULL){
					cout<<"�޸�ʧ�ܣ���ѧ�������ڣ�"<<endl;
				}else{
					if(UpdateStu(Students,p,xh,xm,xb,nl,zy)){
						cout<<"�޸ĳɹ���"<<endl; 
					}else{
						cout<<"�޸�ʧ�ܣ���ѧ���Ѵ��ڣ�"<<endl;
					}
				} 
				
			}else{//ֻ��һ��ѧ����ֱ���޸� 
				
				cout<<"�������޸ĺ��ѧ����Ϣ"<<endl; 
				cout<<"ѧ�ţ�"; 
				getstr(xh); 
				cout<<"������"; 
				getstr(xm); 
				cout<<"�Ա�"; 
				getstr(xb); 
				cout<<"���䣺"; 
				getstr(nl); 
				cout<<"רҵ��"; 
				getstr(zy); 
				
				StuNode * p =  GetStuByXm(Students,xm1);
				
				if(p == NULL){
					cout<<"�޸�ʧ�ܣ���ѧ�������ڣ�"<<endl;
				}else{
					if(UpdateStu(Students,p,xh,xm,xb,nl,zy)){
						cout<<"�޸ĳɹ���"<<endl; 
					}else{
						cout<<"�޸�ʧ�ܣ���ѧ���Ѵ��ڣ�"<<endl;
					}
				}
			}
		}else if(x == '5'){
			cout<<"������Ҫ��ѯ��רҵ�����ƣ�";
			getstr(zy);
			SelectStudentsByZy(Students,zy);
		}else if(x == '6'){
			if(WriteFile(Students) == true){
				cout<<"���ݴ洢�ɹ���"<<endl;
			}
		}else if(x == '7'){
			break;
		} 
		cout<<endl<<"����esc���������򣬰���������������ع���ѡ��˵���"<<endl;
		flag = getch();
	} 
	return 0;
}
