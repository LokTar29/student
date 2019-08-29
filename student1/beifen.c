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
	FILE* fp = fopen("student1.dat","r");
	if(NULL == fp)
	{
		return;
	}
	size_t count = 0;
	while(true)
	{
		void* ptr = malloc(sizeof(Student));
		if(0 >= fread(ptr,sizeof(Student),1,fp))
		{
			fclose(fp);
			return;
		}
		tail_add_list(list1,ptr);
		count++;	
	}
}

void save_file_stu1(void)
{
	FILE* fp= fopen("student1.dat","w");
	size_t count = 0;
	void print(const void* ptr)
	{
		fwrite(ptr,sizeof(Student),1,fp);
		count++;
	}
	show_list(list1,print);
	fclose(fp); fp = NULL;
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
		fscanf(fp,"%s %c %d %lf %lf %lf %lf %d %d %d",stu->name,&stu->sex,&stu->id,&stu->chinese,&stu->math,&stu->english,&stu->score,&stu->flag,&stu->password,&stu->lock);
		
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
		fprintf(fp,"%s %c %d %lf %lf %lf %lf %d %d %d",stu->name,stu->sex,stu->id,stu->chinese,stu->math,stu->english,stu->score,stu->flag,stu->password,stu->lock);
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
		fscanf(fp,"%s %c %d %d %d %d",tea->name,&tea->sex,&tea->id,&tea->flag,&tea->password,&tea->lock);
		
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
		fprintf(fp,"%s %c %d %d %d %d",tea->name,tea->sex,tea->id,tea->flag,tea->password,tea->lock);
		
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
		fscanf(fp,"%s %c %d %d %d %d",tea->name,&tea->sex,&tea->id,&tea->flag,&tea->password,&tea->lock);
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
		fprintf(fp,"%s %c %d %d %d %d",tea->name,tea->sex,tea->id,tea->flag,tea->password,tea->lock);
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
	fscanf(fp,"%d %d %d %d %d %d",&boss.id,&boss.password,&boss.secret,&boss.flag,&boss.password,&boss.lock);
	
}

void save_boss(void)
{
	FILE* fp= fopen("principal.txt","w");
	fprintf(fp,"%d %d %d %d %d %d",boss.id,boss.password,boss.secret,boss.flag,boss.password,boss.lock);
	
}
