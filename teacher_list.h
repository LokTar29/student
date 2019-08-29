#ifndef TEACHER_LIST_H
#define TEACHER_LIST_H
#include <stdbool.h>

typedef struct teacher
{
	char name[20];
	char sex;
	int id;
	int password;
	bool lock;
	bool flag;
}teacher;

extern teacher tea1[20];
extern teacher tea2[20];

void first_teacher(int i);

void add_student_teacher(void);

void del_student_teacher(void);

void find_student_teacher(void);

void revise_student_teacher(void);

void enter_student_teacher(void);

void reset_student_teacher(void);

void see_instudent_teacher(void);

void see_outstudent_teacher(void);

void unlock_student_teacher(void);


#endif//TEACHER_LIST_H
