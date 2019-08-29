#ifndef PRINCIPAL_LIST_H
#define PRINCIPAL_LIST_H
#include <stdbool.h>

typedef struct principal
{
	int password;
	bool flag;
	bool lock;
}principal;

extern principal pal;

void first_principal(void);

void reset_principal(void);

void reset_teacher_principal(void);

void add_teacher_principal(void);

void del_teacher_principal(void);

void see_inteacher_principal(void);

void see_outteacher_principal(void);

#endif//PRINCIPAL_LIST_H
