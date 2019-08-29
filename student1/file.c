#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "list.h"
#include "student.h"
#include "teacher.h"
#include "principal.h"
#include <string.h>
#include <stdint.h>
#include <unistd.h>

extern List* list1,*list2,*list3,*list4;
extern int num1,num2,num3,num4;
extern Principal boss;

/*********************在校学生****************************/
void open_file_stu1(void)
{
	de_code("student1.dat");
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
		sleep(1);
		printf("%d\n",count++);	
		//count++;
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
	de_code("student1.dat");
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
	de_code("student2.dat");
	FILE* fp = fopen("student2.dat","r");
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
		tail_add_list(list2,ptr);
		count++;	
	}
}

void save_file_stu2(void)
{
	FILE* fp= fopen("student2.dat","w");
	size_t count = 0;
	void print(const void* ptr)
	{
		fwrite(ptr,sizeof(Student),1,fp);
		count++;
	}
	show_list(list2,print);
	fclose(fp); fp = NULL;
	de_code("student2.dat");
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
	de_code("teacher1.dat");
	FILE* fp = fopen("teacher1.dat","r");
	if(NULL == fp)
	{
		return;
	}
	size_t count = 0;
	while(true)
	{
		void* ptr = malloc(sizeof(Teacher));
		if(0 >= fread(ptr,sizeof(Teacher),1,fp))
		{
			fclose(fp);
			return;
		}
		tail_add_list(list3,ptr);
		count++;	
	}
}

void save_file_tea1(void)
{
	FILE* fp= fopen("teacher1.dat","w");
	size_t count = 0;
	void print(const void* ptr)
	{
		fwrite(ptr,sizeof(Teacher),1,fp);
		count++;
	}
	show_list(list3,print);
	fclose(fp); fp = NULL;
	de_code("teacher1.dat");
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
	de_code("teacher2.dat");
	FILE* fp = fopen("teacher2.dat","r");
	if(NULL == fp)
	{
		return;
	}
	size_t count = 0;
	while(true)
	{
		void* ptr = malloc(sizeof(Teacher));
		if(0 >= fread(ptr,sizeof(Teacher),1,fp))
		{
			fclose(fp);
			return;
		}
		tail_add_list(list4,ptr);
		count++;	
	}
}

void save_file_tea2(void)
{
	FILE* fp= fopen("teacher2.dat","w");
	size_t count = 0;
	void print(const void* ptr)
	{
		fwrite(ptr,sizeof(Teacher),1,fp);
		count++;
	}
	show_list(list4,print);
	fclose(fp); fp = NULL;
	de_code("teacher2.dat");
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
	FILE* fp= fopen("principal.dat","w");
	fprintf(fp,"%d %d %d %d %d %d",boss.id,boss.password,boss.secret,boss.flag,boss.password,boss.lock);
	
}

 bool de_code(const char* path)
{
	FILE* frp = fopen(path,"r");
	if(NULL == frp) return false;
	size_t len = strlen(PASSWORD) , i = 0;
	uint8_t data = 0;
	
	FILE* fwp = fopen(TEMP_PATH,"w");
	
	while(fread(&data,1,1,frp))
	{
		data ^= PASSWORD[i++%len];
		fwrite(&data,1,1,fwp);
	}
	
	fclose(frp); frp = NULL;
	fclose(fwp); fwp = NULL;
	
	remove(path);
	rename(TEMP_PATH,path);
	return true;
}
