#ifndef TEACHER_H
#define TEACHER_H
#include <stdbool.h>
#include "list.h"
typedef struct Teacher
{
	char name[20];
	char sex;
	int  id;
	int  flag;
	int password;
	int lock;
}Teacher;

bool signin_tea(int n);
void first_signin_tea(int n);
void add_stu(void);
bool del_stu(void);
void search_stu_tea(void);
void modify_stu_tea(void);
void input_stu_tea(void);
void reset_stu_tea(void);
void show_instu(void);
void show_outstu(void);
void unlock_stu_tea(void);
void _search_stu(Node* node,char *p);
void sort_stu(void);
#endif//TEACHER_H
