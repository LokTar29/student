#include "student_list.h"
#include "teacher_list.h"
#include "principal_list.h"
#include "tools.h"
#include <getch.h>

void function_student()
{
	int num1=0,num2=0;
	while(1)
	{
		printf("请输入您的学号\n");
		scanf("%d",&num1);
		int i=1,j=0;
		for(i;i<=20;i++)
		{
			if (num1==stu1[i].id)
			{
				for (j;j<3;j++)
				{
					if (stu1[i].lock==true)
					{
						printf("账号已被锁定，请联系老师\n");
						return;
					}
					printf("请输入您的密码\n");
					scanf("%d",&num2);
					if (num2==stu1[i].password)
					{
						printf("登录成功\n");
						break;
					} 
					if (2==j) 
					{
						printf("账号已被锁定，请联系老师\n");
						stu1[i].lock=true;
						return;
					}
				}
				if (num2==stu1[i].password)
				{
					break;
				}
			}
		}
	}
	first_student(i);
	meun2();
    switch(get_cmd('1','4')-'0')
	{       
        case 1:find_student(i);break;
        case 2:change_student(i);break;
        case 3:see_student(i);break;
    	case 4:return;
    }	
}

void function_teacher()
{
	int num1=0,num2=0;
	while(1)
	{
		int i=1,j=0;
		printf("请输入您的工号\n");
		scanf("%d",&num1);
		for(i;i<=20;i++)
		{
			if (num1==tea1[i].id)
			{
				for (j;j<3;j++)
				{
					if (tea1[i].lock==true)
					{
						printf("账号已被锁定，请联系校长\n");
						return;
					}
					printf("请输入您的密码\n");
					scanf("%d",&num2);
					if (num2==tea1[i].password)
					{
						printf("登录成功\n");
						break;
					} 
					if (2==j) 
					{
						printf("账号已被锁定，请联系校长\n");
						tea1[i].lock=true;
						return;
					}
				}
				if (num2==tea1[i].password)
				{
					break;
				}
			}
		}
	}
	first_teacher(i);
	meun3();
    switch(get_cmd('1','9')-'0')
	{       
        case 1:add_student_teacher();break;
        case 2:del_student_teacher();break;
        case 3:find_student_teacher();break;
    	case 4:revise_student_teacher();break;
    	case 5:enter_student_teacher();break;
    	case 6:reset_student_teacher();break;
    	case 7:see_instudent_teacher();break;
    	case 8:see_outstudent_teacher();break;
    	case 9:unlock_student_teacher();break;
    	case 0:return;
    }	
}

void function_principal()
{
	int num1=0,num2=0;
	while(1)
	{
		int num1=0,i=0;
		for (i;i<3;i++)
		{
			printf("请输入您的密码\n");
			scanf("%d",&num1);
			if (num1==pal.password)
			{
				printf("登陆成功\n");
				break;
			}
			if (2==i)
			{
				pal.flag=true;
				break;
			}
		}
	}
	if (true==pal.flag)
	{
		printf("您的账号已被锁定，输入密保问题答案就可解锁\n");
		printf("请输入3个1\n");
		int num2=0;
		scanf("%d",&num2);
		if (111==num2)
		{
			printf("登录成功\n");
			pal.flag=false;
		}
		else 
		{
			return;
		}
	}
	first_principal();
	meun4();
    switch(get_cmd('1','7')-'0')
	{       
        case 1:reset_principal();break;
        case 2:reset_teacher_principal();break;
        case 3:add_teacher_principal();break;
    	case 4:del_teacher_principal();break;
    	case 5:see_inteacher_principal();break;
    	case 6:see_outteacher_principal();break;
    	case 7:return;
    }	
}
int main()
{
	for(;;)
	{
		menu1();
        switch(get_cmd('1','3')-'0')
        {
           case 1:function_student();break;
           case 2:function_teacher();break;
           case 3:function_principal();break;
           case 4:return 0;
        }
	}
}
