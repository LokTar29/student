#include <stdio.h>
#include "tools.h"
#include <stdlib.h>
#include <getch.h>
//清理缓存区
void clean_stdin(void)
{
   stdin->_IO_read_ptr=stdin->_IO_read_end;
}

//按任意键继续
void anykey_continue(void)
{
    clean_stdin();
    printf("请输入任意键继续....");
    getch();
}
//获取指令
char get_cmd(char start,char end)
{
   for (;;)
   {
      char cmd=getch();
      if (start<=cmd && cmd<=end) 
      {
         printf("%c\n",cmd);
         return cmd;
      }
   }
}
//菜单1
void menu1(void)
{
   system("clear");
   puts("***欢迎使用学生信息管理系统***");
   puts("请输入您的身份");
   puts("1、学生");
   puts("2、教师");
   puts("3、校长");
   puts("4、退出学生信息管理系统");
   puts("请输入指令：");
}


//菜单2
void menu2(void)
{
   system("clear");
   puts("***欢迎使用学生信息管理系统***");
   puts("1、查询成绩");
   puts("2、修改密码");
   puts("3、查看个人信息");
   puts("4、退出学生信息管理系统");
   puts("请输入指令：");
}

//菜单3
void menu3(void)
{
   system("clear");
   puts("***欢迎使用学生信息管理系统***");
   puts("1、添加学生");
   puts("2、删除学生");
   puts("3、查找学生");
   puts("4、修改学生信息");
   puts("5、录入学生成绩");
   puts("6、重置学生密码");
   puts("7、显示所有在校学生信息");
   puts("8、显示所有退出学生信息");
   puts("9、解锁学生账号");
   puts("10、退出学生信息管理系统");
   puts("请输入指令：");
}

//菜单4
void menu4(void)
{
   system("clear");
   puts("***欢迎使用学生信息管理系统***");
   puts("1、重置自己的密码");
   puts("2、重置教师的密码");
   puts("3、添加教师");
   puts("4、删除教师");
   puts("5、显示所有在职教师");
   puts("6、显示所有离职教师");
   puts("7、退出学生信息管理系统");
   puts("请输入指令：");
}

