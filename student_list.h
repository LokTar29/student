#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H
#include <stdbool.h>

typedef struct student
{
	char name[20];
	char sex;
	int  id;
	double chinese;
	double math;
	double english;
	bool flag;
	int password;
	bool lock;
}student;
//定义学生数组
extern student stu1[20];
extern student stu2[20];

//判断是否是第一次登录
void first_student(int i);

//查询成绩
void find_student(int i);

//修改密码
void change_student(int i);

//查看个人信息
void see_student(int i);

#endif//STUDENT_LIST_H
