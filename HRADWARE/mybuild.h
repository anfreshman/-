#ifndef __MYBUILD_H
#define __MYBUILD_H
#include "stdio.h"
#define  LEN sizeof(STUlist)



typedef struct student
{unsigned long int number;//学生证号
int Class;//班级
char name[20];//姓名
struct student*next;//指针域
}STUlist;


STUlist*head;







int myBuild_hand();
int myBuild_file();









#endif
