#ifndef TOOLS_H
#define TOOLS_H


//清理缓存区
void clean_stdin(void);

//获取指令
char get_cmd(char start,char end);

//按任意键继续
void anykey_continue(void);

//菜单1
void menu1(void);

//菜单2
void menu2(void);

//菜单3
void menu3(void);

//菜单4
void menu4(void);
void open_and_creat();
void save();

#endif//TOOLS_H
