#include <stdio.h>
#include "student.h"
#include "list.h"
#include "tools.h"
#include <stdlib.h>
#include <getch.h>
#include <string.h>

extern List* list1,*list2,*list3,*list4;
extern int num1,num2,num3,num4;

/*
void add_stu(void)
{
	Student* stu = malloc(sizeof(Student));
	printf("请输入学生的姓名和性别");
	stu->id = ++num1;
	stu->chinese = 0;
	stu->math = 0;
	stu->english = 0;
	stu->lock = false;
	stu->flag = false;
	stu->password = 123456;
	scanf("%s %c",stu->name,&stu->sex);
	stu->score = stu->chinese+stu->math+stu->english;
	tail_add_list(list1,stu);
}
void del_stu(void)
{
	printf("请选择要姓名n删除还是学号i删除:");
	clean_stdin();
	if ('n' == getch())
	{
		char name[20]={};
		printf("请输入要删除的姓名:");
		gets(name);
		int  cmp(const void* ptr1,const void* ptr2)
		{
			const Student* stu = ptr1;
			const char* name = ptr2;
			return strcmp(stu->name,name);
		}
		if (delete_value_list(list1,&name,cmp)) 
		{
			printf("删除成功\n");
			num2++;
		}
		else printf("删除失败\n");
	}
	else
	{
		size_t id=0;
		printf("请输入要删除的学号:");
		scanf("%u",&id);
		int  cmp(const void* ptr1,const void* ptr2)
		{
			const Student* stu = ptr1;
			const size_t* id = ptr2;
			if (stu->id > *id) return 1;
			else if (stu->id < *id) return -1;
			else return 0;
		}
		if (delete_value_list(list1,&id,cmp)) 
		{
			printf("删除成功\n");
			num2++;
		}
		else printf("删除失败\n");
	}
	
}


void show_stu(void)
{
	void show(const void* ptr)
	{
		const Student *stu =ptr;
		printf("%u %s %c\n",stu->id,stu->name,stu->sex);
	}
	show_list(list1,show);
}
*/
void first_signin_stu(int n)
{
	Student* stu = malloc(sizeof(Student));
	for(Node* node = list1->head;node != NULL;node = node->next)
	{
		stu =node->ptr;
		if (stu->id == n) break;
	}
	if (stu->flag == false)
	{
		printf("请输入您的新密码:");
		scanf("%d",&stu->password);
		stu->flag =true;
	}
}

void modify_stu(int n)
{
	Student* stu = malloc(sizeof(Student));
	for(Node* node = list1->head;node != NULL;node = node->next)
	{
		stu =node->ptr;
		if (stu->id == n) break;
	}
	printf("请输入您的新密码:");
	scanf("%d",&stu->password);
}

void see_stu(int n)
{
	Student* stu = malloc(sizeof(Student));
	for(Node* node = list1->head;node != NULL;node = node->next)
	{
		stu =node->ptr;
		if (stu->id == n) break;
	}
	printf("id:%d\n",stu->id);
	printf("姓名：%s\n",stu->name);
	printf("性别：%c\n",stu->sex);
	printf("语文：%lf\n",stu->chinese);
	printf("数学：%lf\n",stu->math);
	printf("英语：%lf\n",stu->english);
}

bool signin_stu(int n)
{
	int pass=0;
	Student* stu = malloc(sizeof(Student));
	for(Node* node = list1->head;node != NULL;node = node->next)
	{
		stu =node->ptr;
		if (stu->id == n) break;
	}
	if (stu->lock == true) 
	{
		printf("账号已被锁，请联系老师\n");
		return false;
	}
	for(int i=0;i<3;i++)
	{
		printf("请输入您的密码:");
		scanf("%d",&pass);
		if (stu->password == pass)
		{
			printf("登录成功\n");
			return true;
		}
	}
	printf("账号已被锁，请联系老师\n");
	stu->lock = true;
	return false;
}

void query_stu(int n)
{
	double max=0,min=400,average=0,self=0;
	int p=1;
	Student* stu = malloc(sizeof(Student));
	for(Node* node = list1->head;node != NULL;node = node->next)
	{
		stu =node->ptr;
		if (stu->id == n) break;
	}
	self = stu->score;
	for(Node* node=list1->head; node!=NULL; node=node->next)
	{
		stu = node->ptr;
		if (max < stu->score) 
		{
			max = stu->score;
		}
		if (min > stu->score) 
		{
			min = stu->score;
		}
		average+= stu->score;
		if (self < stu->score) 
		{
			p++;
		}
	}
	printf("最高分：%lf\n",max);
	printf("最低分：%lf\n",min);
	printf("平均分：%lf\n",average/(num1-num2));
	printf("你的排名：%d\n",p);
}
