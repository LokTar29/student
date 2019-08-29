#include <stdio.h>
#include "teacher_list.h"

extern teacher tea1[20];
extern teacher tea2[20];

void first_teacher(int i)
{
	if (false==tea1[i].flag)
	{
		printf("请输入您的新密码\n");
		scanf("%d",&tea1[i].password);
		tea1[i].flag=true;
	}
}

void add_student_teacher(void)
{
	int n=0;
	int num=sizeof(tea1)/sizeof(tea1[1]);
	printf("1、单个输入\n");
	printf("2、批量输入\n");
	scanf("%d",&n);
	if (1==n)
	{
		printf("请输入学生姓名");
		stu1[num+1].id=num+1;
		gets(stu1[num+1].name);
		printf("请输入性别");
		scanf("%c",&stu1[num+1].sex);
		stu1[num+1].chinese=0;
		stu1[num+1].math=0;
		stu1[num+1].english=0;
		stu1[num+1].lock=false;
		stu1[num+1].flag=false;
		stu1[num+1].password=123456;
	}
	if (2==n)
	{
	
	
	}
}

void del_student_teacher(void)
{
	//int num1=sizeof(tea1)/sizeof(tea1[1]);
	//int num2=sizeof(tea2)/sizeof(tea2[1]);
	printf("请输入要删除的学号");
	int a1=0,a2=0;
	scanf("%d",&a1);
	printf("请再次输入要删除的学号");
	scanf("%d",&a2);
	if (a1==a2)
	{
		stu2[num2+1].name=stu1[a1].name;
		stu2[num2+1].id=num2+1;
		stu2[num2+1].sex=stu1[a1].sex;
		stu2[num2+1].chinese=stu1[a1].chinese;
		stu2[num2+1].math=stu1[a1].math;
		stu2[num2+1].english=stu1[a1].english;
		stu2[num2+1].lock=stu1[a1].lock;
		stu2[num2+1].flag=stu1[a1].flag;
		stu2[num2+1].password=stu1[a1].password;
		for (a1;a1<=num1;a1++)
		{
			stu1[a1].name=stu1[a1+1].name;
		}
	}
}

void find_student_teacher(void)
{
	put("1111");
}

void revise_student_teacher(void)
{
	put("1111");
}

void enter_student_teacher(void)
{
	put("1111");
}

void reset_student_teacher(void)
{
	put("1111");
}

void see_instudent_teacher(void)
{
	put("1111");
}

void see_outstudent_teacher(void)
{
	put("1111");
}

void unlock_student_teacher(void)
{
	put("1111");
}


