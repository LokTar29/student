#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "list.h"
#include "student.h"
#include "teacher.h"
#include "principal.h"
extern List* list1,*list2,*list3,*list4;
extern int num1,num2,num3,num4;
extern Principal boss;

/*********************在校学生****************************/
void open_file_stu1(void)
{
	FILE* fp= fopen("student1.txt","r");
	for (int i=0;i<num1-num2;i++)
	{
		Student* stu = malloc(sizeof(Student));
		fscanf(fp,"%s %c %d %lf %lf %lf %lf ",stu->name,&stu->sex,&stu->id,&stu->chinese,&stu->math,&stu->english,&stu->score);
		int p=0;
		fscanf(fp,"%d",&p);
		if (0 ==p) 
		{
			stu->flag = false;
		}
		else
		{
			stu->flag = true;
		}
		fscanf(fp,"%d",&stu->password);
		fscanf(fp,"%d",&p);
		if (0 ==p) 
		{
			stu->lock = false;
		}
		else
		{
			stu->lock = true;
		}
		tail_add_list(list1,stu);
	}
}

void save_file_stu1(void)
{
	Node* node = list1->head;
	FILE* fp= fopen("student1.txt","w");
	for (int i=0;i<num1-num2;i++)
	{
		Student* stu = malloc(sizeof(Student));
		stu =node->ptr;
		fprintf(fp,"%s %c %d %lf %lf %lf %lf ",stu->name,stu->sex,stu->id,stu->chinese,stu->math,stu->english,stu->score);
		int p=0,m=1;
		if (stu->flag) 
		{
			fprintf(fp,"%d ",m);
		}
		else
		{
			fprintf(fp,"%d ",p);
		}
		fprintf(fp,"%d ",stu->password);
		if (stu->lock) 
		{
			fprintf(fp,"%d ",m);
		}
		else
		{
			fprintf(fp,"%d ",p);
		}
		node = node->next;
		//stu = stu->next;
	}
}

void open_num1(void)
{
	FILE* fp=fopen("num1.txt","r");
	fscanf(fp,"%d",&num1);
}

void save_num1(void)
{
	FILE* fp=fopen("num1.txt","w");
	fprintf(fp,"%d",num1);
}



/*********************离校学生****************************/
void open_file_stu2(void)
{
	FILE* fp= fopen("student2.txt","r");
	for (int i=0;i<num2;i++)
	{
		Student* stu = malloc(sizeof(Student));
		fscanf(fp,"%s %c %d %lf %lf %lf %lf ",stu->name,&stu->sex,&stu->id,&stu->chinese,&stu->math,&stu->english,&stu->score);
		int p=0;
		fscanf(fp,"%d",&p);
		if (0 ==p) 
		{
			stu->flag = false;
		}
		else
		{
			stu->flag = true;
		}
		fscanf(fp,"%d",&stu->password);
		fscanf(fp,"%d",&p);
		if (0 ==p) 
		{
			stu->lock = false;
		}
		else
		{
			stu->lock = true;
		}
		tail_add_list(list2,stu);
	}
}

void save_file_stu2(void)
{
	Node* node = list2->head;
	FILE* fp= fopen("student2.txt","w");
	for (int i=0;i<num2;i++)
	{
		Student* stu = malloc(sizeof(Student));
		stu =node->ptr;
		fprintf(fp,"%s %c %d %lf %lf %lf %lf ",stu->name,stu->sex,stu->id,stu->chinese,stu->math,stu->english,stu->score);
		int p=0,m=1;
		if (stu->flag) 
		{
			fprintf(fp,"%d ",m);
		}
		else
		{
			fprintf(fp,"%d ",p);
		}
		fprintf(fp,"%d ",stu->password);
		if (stu->lock) 
		{
			fprintf(fp,"%d ",m);
		}
		else
		{
			fprintf(fp,"%d ",p);
		}
		node = node->next;
	}
}

void open_num2(void)
{
	FILE* fp=fopen("num2.txt","r");
	fscanf(fp,"%d",&num2);
}

void save_num2(void)
{
	FILE* fp=fopen("num2.txt","w");
	fprintf(fp,"%d",num2);
}


/*********************在校教师****************************/
void open_file_tea1(void)
{
	FILE* fp= fopen("teacher1.txt","r");
	for (int i=0;i<num3-num4;i++)
	{
		Teacher* tea = malloc(sizeof(Teacher));
		fscanf(fp,"%s %c %d ",tea->name,&tea->sex,&tea->id);
		int p=0;
		fscanf(fp,"%d",&p);
		if (0 ==p) 
		{
			tea->flag = false;
		}
		else
		{
			tea->flag = true;
		}
		fscanf(fp,"%d",&tea->password);
		fscanf(fp,"%d",&p);
		if (0 ==p) 
		{
			tea->lock = false;
		}
		else
		{
			tea->lock = true;
		}
		tail_add_list(list3,tea);
	}
}

void save_file_tea1(void)
{
	Node* node = list3->head;
	FILE* fp= fopen("teacher1.txt","w");
	for (int i=0;i<num3-num4;i++)
	{
		Teacher* tea = malloc(sizeof(Teacher));
		tea =node->ptr;
		fprintf(fp,"%s %c %d ",tea->name,tea->sex,tea->id);
		int p=0,m=1;
		if (tea->flag) 
		{
			fprintf(fp,"%d ",m);
		}
		else
		{
			fprintf(fp,"%d ",p);
		}
		fprintf(fp,"%d ",tea->password);
		if (tea->lock) 
		{
			fprintf(fp,"%d ",m);
		}
		else
		{
			fprintf(fp,"%d ",p);
		}
		node = node->next;
	}
}

void open_num3(void)
{
	FILE* fp=fopen("num3.txt","r");
	fscanf(fp,"%d",&num3);
}

void save_num3(void)
{
	FILE* fp=fopen("num3.txt","w");
	fprintf(fp,"%d",num3);
}


/*********************离校教师****************************/
void open_file_tea2(void)
{
	FILE* fp= fopen("teacher2.txt","r");
	for (int i=0;i<num4;i++)
	{
		Teacher* tea = malloc(sizeof(Teacher));
		fscanf(fp,"%s %c %d ",tea->name,&tea->sex,&tea->id);
		int p=0;
		fscanf(fp,"%d",&p);
		if (0 ==p) 
		{
			tea->flag = false;
		}
		else
		{
			tea->flag = true;
		}
		fscanf(fp,"%d",&tea->password);
		fscanf(fp,"%d",&p);
		if (0 ==p) 
		{
			tea->lock = false;
		}
		else
		{
			tea->lock = true;
		}
		tail_add_list(list4,tea);
	}
}

void save_file_tea2(void)
{
	Node* node = list4->head;
	FILE* fp= fopen("teacher1.txt","w");
	for (int i=0;i<num4;i++)
	{
		Teacher* tea = malloc(sizeof(Teacher));
		tea =node->ptr;
		fprintf(fp,"%s %c %d ",tea->name,tea->sex,tea->id);
		int p=0,m=1;
		if (tea->flag) 
		{
			fprintf(fp,"%d ",m);
		}
		else
		{
			fprintf(fp,"%d ",p);
		}
		fprintf(fp,"%d ",tea->password);
		if (tea->lock) 
		{
			fprintf(fp,"%d ",m);
		}
		else
		{
			fprintf(fp,"%d ",p);
		}
		node = node->next;
	}
}

void open_num4(void)
{
	FILE* fp=fopen("num4.txt","r");
	fscanf(fp,"%d",&num4);
}

void save_num4(void)
{
	FILE* fp=fopen("num4.txt","w");
	fprintf(fp,"%d",num4);
}


/*********************校长****************************/


void open_boss(void)
{
	FILE* fp= fopen("principal.txt","r");
	fscanf(fp,"%d %d %d ",&boss.id,&boss.password,&boss.secret);
	int p=0;
	fscanf(fp,"%d",&p);
	if (0 ==p) 
		{
			boss.flag = false;
		}
		else
		{
			boss.flag = true;
		}
	fscanf(fp,"%d",&p);
	if (0 ==p) 
		{
			boss.lock = false;
		}
		else
		{
			boss.lock = true;
		}
}

void save_boss(void)
{
	FILE* fp= fopen("principal.txt","w");
	fprintf(fp,"%d %d %d ",boss.id,boss.password,boss.secret);
	int p=0,m=1;
	if (boss.flag) 
	{
		fprintf(fp,"%d ",m);
	}
	else
	{
		fprintf(fp,"%d ",p);
	}
	if (boss.lock) 
	{
		fprintf(fp,"%d ",m);
	}
	else
	{
		fprintf(fp,"%d ",p);
	}
}
