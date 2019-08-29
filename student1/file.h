#ifndef FILE_H
#define FILE_H
#include <stdbool.h>

#define TEMP_PATH	"./temp.dat"
#define PASSWORD	"--zzxx--"

void open_file_stu1(void);

void save_file_stu1(void);

void open_num1(void);

void save_num1(void);

void open_file_stu2(void);

void save_file_stu2(void);

void open_num2(void);

void save_num2(void);


void open_file_tea1(void);

void save_file_tea1(void);

void open_num3(void);

void save_num3(void);

void open_file_tea2(void);

void save_file_tea2(void);

void open_num4(void);

void save_num4(void);

void open_boss(void);

void save_boss(void);
 bool de_code(const char* path);
#endif//FILE_H
