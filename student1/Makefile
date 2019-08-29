#指定编译器
CC=gcc
#指定编译标准
STD=-std=gnu99
#指定编译参数
FLAG=-Wall -Werror
#设置目标文件
OBJ=main.o student.o file.o list.o tools.o teacher.o principal.o
#设置可执行文件名
BIN=管理系统

all:$(OBJ)
	$(CC) $(OBJ) -o $(BIN)
%.o:%.c
	$(CC) $(STD) $(FLAG) -c $< -o $@    
clean:
	rm -rf $(OBJ) $(BIN)
