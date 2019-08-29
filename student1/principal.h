#ifndef PRINCIPAL_H
#define PRINCIPAL_H
#include <stdbool.h>
typedef struct Principal
{
	int id;
	int password;
	int secret;
	int  flag;
	int  lock;
}Principal;

Principal boss;

bool signin_boss(void);
void unlock_boss(void);
void first_signin_boss(void);
void add_tea(void);
bool del_tea(void);
void reset_tea_boss(void);
void reset_boss_boss(void);
void show_intea(void);
void show_outtea(void);
void modify_tea_boss(void);

#endif//PRINCIPAL_H
