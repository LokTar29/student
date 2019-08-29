#ifndef STUDENT_H
#define STUDENT_H
#include <stdbool.h>

typedef struct Student
{
	char name[20];
	char sex;
	int  id;
	double chinese;
	double math;
	double english;
	double score;
	bool flag;
	int password;
	bool lock;
}Student;
/*
void add_stu(void);
void del_stu(void);
*/
void see_stu(int n);
void modify_stu(int n);
void show_stu(void);
void first_signin_stu(int n);
bool signin_stu(int n);
void query_stu(int n);
#endif//STUDENT_LIST_H
