#include <stdio.h>
#include "student_list.h"

extern student stu1[20];
extern student stu2[20];

void first_student(int i)
{
	if (false==stu1[i].flag)
	{
		printf("请输入您的新密码\n");
		scanf("%d",&stu1[i].password);
		stu1[i].flag=true;
	}
}

void find_student(int i)
{
	int j=0,p=1;
	int num=sizeof(stu1)/sizeof(stu1[1]);
	double zf=stu1[i].chinese+stu1[i].math+stu1[i].english;
	double max=stu1[i].chinese+stu1[i].math+stu1[i].english;
	double min=stu1[i].chinese+stu1[i].math+stu1[i].english;
	double average=stu1[i].chinese+stu1[i].math+stu1[i].english;
	for (j=0;j<num;j++)
	{
		if (i==j)
		{
			continue;
		}
		average+=stu1[j].chinese+stu1[j].math+stu1[j].english;
		if (max<stu1[j].chinese+stu1[j].math+stu1[j].english)
		{
			max=stu1[j].chinese+stu1[j].math+stu1[j].english;
		}
		if (min>stu1[j].chinese+stu1[j].math+stu1[j].english)
		{
			min=stu1[j].chinese+stu1[j].math+stu1[j].english;
		}
		if (zf<stu1[j].chinese+stu1[j].math+stu1[j].english)
		{
			p+=1;
		}
	}
	printf("排名为%d\n",p);
	printf("平均分为%lf\n",average/num);
	printf("最高分为%lf\n",max);
	printf("最低分为%lf\n",min);
}

void change_student(int i)
{
	printf("请输入您的新密码\n");
	scanf("%d",&stu1[i].password);
}

void see_student(int i)
{
	printf("姓名：%s\n",stu1[i].name);
	printf("性别：%c\n",stu1[i].sex);
	printf("学号：%d\n",stu1[i].id);
	printf("语文：%lf\n",stu1[i].chinese);
	printf("数学：%lf\n",stu1[i].math);
	printf("英语：%lf\n",stu1[i].english);
}
