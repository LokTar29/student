#include <stdio.h>
#include "principal.h"
#include "list.h"
#include "tools.h"
#include <stdlib.h>
#include <getch.h>
#include <string.h>
#include "teacher.h"

extern List* list1,*list2,*list3,*list4;
extern int num1,num2,num3,num4;


bool signin_boss(void)
{
	if (boss.lock == 1) 
	{
		printf("已被锁定\n");
		return false;
	}
	int pass=0;
	for(int i=0;i<3;i++)
	{
		printf("请输入您的密码:");
		scanf("%d",&pass);
		if (pass == boss.password) 
		{
			printf("登录成功\n");
			return true;
		}
	}
	printf("账号已被锁\n");
	boss.lock = 1;
	return false;	
}
void unlock_boss(void)
{
	if (boss.lock == 1)
	{
		printf("账号被锁，请输入secret:");
		int n=0;
		scanf("%d",&n);
		clean_stdin();
		if (n == boss.secret)
		{
			printf("密码重置为123456\n");
			boss.lock = 0;
			boss.password = 123456;
			
		}
		else 
		{
			printf("secret错误\n");
		}
	}
}
void first_signin_boss(void)
{
	if (!boss.flag)
	{
		printf("请输入您的新密码");
		scanf("%d",&boss.password);
		boss.flag = 1;
	}
}
void add_tea(void)
{
	Teacher* tea = malloc(sizeof(Teacher));
	printf("请输入教师的姓名和性别");
	tea->id = ++num3;
	tea->lock = 0;
	tea->flag = 0;
	tea->password = 123456;
	scanf("%s %c",tea->name,&tea->sex);
	tail_add_list(list3,tea);
}
bool del_tea(void)
{
	size_t id1=0,id2=0;
	printf("请输入要删除的教师的工号:");
	scanf("%u",&id1);
	printf("请再次输入要删除的教师的工号:");
	scanf("%u",&id2);
	if (id1 == id2)
	{
		Node* node = list1->head;
		Teacher* tea = malloc(sizeof(Teacher));
		for(int i=0;i<id1-1;i++)
		{
			node = node->next;
		}
		tea =node->ptr;
		tail_add_list(list4,tea);
		int  cmp(const void* ptr1,const void* ptr2)
		{
			const Teacher* tea = ptr1;
			const size_t* id = ptr2;
			if (tea->id > *id) return 1;
			else if (tea->id < *id) return -1;
			else return 0;
		}
		if (delete_value_list(list3,&id1,cmp)) 
		{
			
			printf("删除成功\n");
			num4++;
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
void reset_boss_boss(void)
{
	printf("请输入您的新密码");
	scanf("%d",&boss.password);
}
void reset_tea_boss(void)
{
	int n=0;
	printf("请输入你要修改密码的工号");
	scanf("%d",&n);
	Node* node = list3->head;
	Teacher* tea = malloc(sizeof(Teacher));
	for(int i=0;i<n-1;i++)
	{
		node = node->next;
	}
	tea =node->ptr;
	printf("请输入该教师的新密码");
	scanf("%d",&tea->password);
	
}
void show_intea(void)
{
	void show(const void* ptr)
	{
		const Teacher* tea =ptr;
		printf("%u %s %c \n",tea->id,tea->name,tea->sex);
	}
	show_list(list3,show);
}
void show_outtea(void)
{
	void show(const void* ptr)
	{
		const Teacher* tea =ptr;
		printf("%u %s %c \n",tea->id,tea->name,tea->sex);
	}
	show_list(list4,show);
}


void modify_tea_boss(void)
{
	int n=0;
	printf("请输入你要修改信息的工号\n");
	scanf("%d",&n);
	Teacher* tea = malloc(sizeof(Teacher));
	printf("1、修改教师基础信息\n");
	printf("2、返回上一层\n");
	switch(get_cmd('1','2')-'0')
		{       
    	    case 1:
    	    {
				for(Node* node = list3->head;node != NULL;node = node->next)
				{
					tea =node->ptr;
					if (tea->id == n) break;
				}
    	    	printf("请输入新的教师的姓名：");
    	    	gets(tea->name);
    	    	printf("请输入新的教师的性别：");
    	    	scanf("%c",&tea->sex);
    	    	break;
    	    }
    	    case 2:return;
    	}	
	
}

