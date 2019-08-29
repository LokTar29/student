#include <stdio.h>
#include <stdlib.h>
#include <getch.h>
#include <string.h>
#include "student.h"
#include "list.h"
#include "tools.h"
#include "teacher.h"

extern List* list1,*list2,*list3,*list4;
extern int num1,num2,num3,num4;


bool signin_tea(int n)
{
	int pass=0;
	Teacher* tea = malloc(sizeof(Teacher));
	for(Node* node = list3->head;node != NULL;node = node->next)
	{
		tea =node->ptr;
		if (tea->id == n) break;
	}
	if (tea->lock == 1) 
	{
		printf("账号已被锁，请联系老师\n");
		return false;
	}
	for(int i=0;i<3;i++)
	{
		printf("请输入您的密码:");
		scanf("%d",&pass);
		if (tea->password == pass)
		{
			printf("登录成功\n");
			return true;
		}
	}
	printf("账号已被锁，请联系老师\n");
	tea->lock = 1;
	return false;
}
void first_signin_tea(int n)
{
	Teacher* tea = malloc(sizeof(Teacher));
	for(Node* node = list3->head;node != NULL;node = node->next)
	{
		tea =node->ptr;
		if (tea->id == n) break;
	}
	if (tea->flag == 0)
	{
		printf("请输入您的新密码:");
		scanf("%d",&tea->password);
		tea->flag =1;
	}
}
void add_stu(void)
{
	Student* stu = malloc(sizeof(Student));
	printf("请输入学生的姓名和性别");
	stu->id = ++num1;
	stu->chinese = 0;
	stu->math = 0;
	stu->english = 0;
	stu->lock = 0;
	stu->flag = 0;
	stu->password = 123456;
	scanf("%s %c",stu->name,&stu->sex);
	stu->score = stu->chinese+stu->math+stu->english;
	tail_add_list(list1,stu);
}
bool del_stu(void)
{
	size_t id1=0,id2=0;
	printf("请输入要删除的学号:");
	scanf("%u",&id1);
	printf("请再次输入要删除的学号:");
	scanf("%u",&id2);
	if (id1 == id2)
	{
		Student* stu = malloc(sizeof(Student));
		for(Node* node = list1->head;node != NULL;node = node->next)
		{
			stu =node->ptr;
			if (stu->id == id1) break;
		}
		tail_add_list(list2,stu);
		int  cmp(const void* ptr1,const void* ptr2)
		{
			const Student* stu = ptr1;
			const size_t* id = ptr2;
			if (stu->id > *id) return 1;
			else if (stu->id < *id) return -1;
			else return 0;
		}
		if (delete_value_list(list1,&id1,cmp)) 
		{
			
			printf("删除成功\n");
			num2++;
			return true;
		}
		else 
		{
			printf("删除失败\n");
			return false;
		}
	}
	else 
	{
		printf("删除失败\n");
		return false;
	}
	
}
void search_stu_tea()
{
	printf("1、按姓名查找\n");
	printf("2、按学号查找\n");
	printf("3、返回上一级\n");
	switch(get_cmd('1','3')-'0')
	{
		case 1:
		{
			char name[20]={};
			int n=0;
			printf("请输入姓名:");
			gets(name);
			for(Node* node=list1->head; node!=NULL; node=node->next)
			{
				_search_stu(node,name);
			}
			printf("请输入查找的学号:");
			scanf("%d",&n);
			see_stu(n);
			break;
		}
		case 2:
		{
			printf("请输入要查找的学生学号:");
			int n=0;
			scanf("%d",&n);
			see_stu(n);
			break;
		}
		case 3:return ;
	}
}
void _search_stu(Node* node,char *p)
{
	int i=0;
	Student* stu = malloc(sizeof(Student));
	stu = node->ptr;
	while(*p)
	{
		if (*p != stu->name[i]) return;
		p++;
	}
	printf("%d  %s\n",stu->id,stu->name);		
}
void modify_stu_tea()
{
	int n=0;
	printf("请输入你要修改信息的学号\n");
	scanf("%d",&n);
	Student* stu = malloc(sizeof(Student));
	printf("1、修改学生基础信息\n");
	printf("2、修改学生成绩\n");
	printf("3、返回上一层\n");
	switch(get_cmd('1','3')-'0')
		{       
    	    case 1:
    	    {
				for(Node* node = list1->head;node != NULL;node = node->next)
				{
					stu =node->ptr;
					if (stu->id == n) break;
				}
    	    	printf("请输入新的学生的姓名：");
    	    	gets(stu->name);
    	    	printf("请输入新的学生的性别：");
    	    	scanf("%c",&stu->sex);
    	    	break;
    	    }
    	    case 2:
    	    {
    	    	for(Node* node = list1->head;node != NULL;node = node->next)
				{
					stu =node->ptr;
					if (stu->id == n) break;
				}
    	    	printf("请输入新的学生的语文成绩：");
    	    	scanf("%lf",&stu->chinese);
    	    	printf("请输入新的学生的数学成绩：");
    	    	scanf("%lf",&stu->math);
    	    	printf("请输入新的学生的英语成绩：");
    	    	scanf("%lf",&stu->english);
    	    	stu->score = stu->chinese+stu->math+stu->english;
    	    	break;
    	    }
    		case 3:return ;
    	}	
	
}
void input_stu_tea()
{
	printf("1、单个录入\n");
	printf("2、批量录入\n");
	printf("3、返回上一层\n");
	switch(get_cmd('1','3')-'0')
		{       
    	    case 1:
    	    {
    	    	int n=0;
    	    	printf("请输入你要修改信息的学号\n");
				scanf("%d",&n);
				Student* stu = malloc(sizeof(Student));
				for(Node* node = list1->head;node != NULL;node = node->next)
				{
					stu =node->ptr;
					if (stu->id == n) break;
				}
    	    	printf("请输入该学生的语文成绩：");
    	    	scanf("%lf",&stu->chinese);
    	    	printf("请输入该学生的数学成绩：");
    	    	scanf("%lf",&stu->math);
    	    	printf("请输入该学生的英语成绩：");
    	    	scanf("%lf",&stu->english);
    	    	stu->score = stu->chinese+stu->math+stu->english;
    	    	break;
    	    }
    	    case 2:
    	    {
    	    	char frp[20]={};
    	    	printf("请输入要打开的文件");
    	    	gets(frp);
    	    	FILE *fp = fopen(frp,"r");
    	    	Student* stu = malloc(sizeof(Student));
    	    	for (Node* node=list1->head; node!=NULL; node=node->next)
    	    	{
    	    		stu = node->ptr;
    	    		fscanf(fp,"%lf %lf %lf ",&stu->chinese,&stu->math,&stu->english);
    	    		stu->score = stu->chinese+stu->math+stu->english;
    	    	}
    	    	break;
    	    }
    		case 3:return ;
    	}	
}
void reset_stu_tea()
{
	int n=0;
	printf("请输入你要修改密码的学号");
	scanf("%d",&n);
	Student* stu = malloc(sizeof(Student));
	for(Node* node = list1->head;node != NULL;node = node->next)
	{
		stu =node->ptr;
		if (stu->id == n) break;
	}
	printf("请输入该学生的新密码");
	scanf("%d",&stu->password);
}
void show_instu(void)
{
	void show(const void* ptr)
	{
		const Student *stu =ptr;
		printf("%u %s %c %lf %lf %lf \n",stu->id,stu->name,stu->sex,stu->chinese,stu->math,stu->english);
	}
	show_list(list1,show);
}
void show_outstu(void)
{
	void show(const void* ptr)
	{
		const Student *stu =ptr;
		printf("%u %s %c %lf %lf %lf \n",stu->id,stu->name,stu->sex,stu->chinese,stu->math,stu->english);
	}
	show_list(list2,show);
}
void unlock_stu_tea()
{
	int n=0;
	printf("请输入你要解锁的学号");
	scanf("%d",&n);
	Student* stu = malloc(sizeof(Student));
	for(Node* node = list1->head;node != NULL;node = node->next)
	{
		stu =node->ptr;
		if (stu->id == n) break;
	}
	stu->lock = 0;
	
}

void sort_stu(void)
{
	puts("1、按姓名排序");
	puts("2、按学号排序");
	puts("3、按成绩排序");
	puts("4、返回上一级");
	switch(get_cmd('1','4')-'0')
    	{
           case 1:
           {
           		char* arr[num1-num2];
           		int i=0;
           		Student* stu = malloc(sizeof(Student));
           		for(Node* node1 = list1->head;node1 != NULL;node1 = node1->next)
           		{
           			stu = node1->ptr;
           			arr[i++] = stu->name;
           		}
           		quick1_sort(arr,num1-num2);
           		for(int j=0;j<i;j++)
           		{
           			for(Node* node2 = list1->head;node2 != NULL;node2 = node2->next)
         			{
         				stu = node2 ->ptr;
           				if (arr[j] == stu->name)
           				{
           					printf("第%d名：%d %s %lf\n",j+1,stu->id,stu->name,stu->score);
           					break;
           				}
           			}
           		}
           		break;
           }
           case 2:
           {
           		show_instu();
           		break;
           }
           case 3:
           {	
           		double arr[num1-num2];
           		int i=0;
           		Student* stu = malloc(sizeof(Student));
           		for(Node* node1 = list1->head;node1 != NULL;node1 = node1->next)
           		{
           			stu = node1->ptr;
           			arr[i++] = stu ->score;
           		}
           		quick_sort(arr,num1-num2);
           		i=0;
           		
           		for(Node* node1 = list1->head;node1 != NULL;node1 = node1->next)
           		{
           			for(Node* node2 = list1->head;node2 != NULL;node2 = node2->next)
         			{
         				int n=i+1;
         				stu = node2 ->ptr;
           				if (arr[i] == stu->score)
           				{
           					printf("第%d名：%d %s %lf\n",n,stu->id,stu->name,arr[i++]);
           					break;
           				}
           			}
           		}
           }
           case 4:return;
        }
}
