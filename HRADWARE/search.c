#include "mysearch.h"
#include "myinsert.h"
#include "mybuild.h"




extern STUlist*head;


int mySearch(unsigned long int number)
{STUlist*p1;
p1=head;
while(p1!=NULL)
{
if(p1->number!=number)
p1=p1->next;
else
break;
}

if(p1->number==number)
{printf("学生证号：%lu\n班级：%d\n姓名：%s\n",p1->number ,p1->Class ,p1->name );
return 1;}
else
return 0;
}


int mySearch_class(int Class)
{int count=0;
STUlist*p1;
p1=head;
while(p1!=NULL)
{
if(p1->Class==Class)
{count++;
printf("%lu %s",p1->number,p1->name );
printf("\n");}
p1=p1->next;
}
if(count!=0)
{
printf("此班级共有%d人\n",count);
return 1;}

else
return 0;

}


int mychange(unsigned long int number)

{STUlist*p1;
p1=head;
while(p1!=NULL)
{
if(p1->number ==number)
break;
p1=p1->next ;
}
if(p1->number ==number)
{
printf("请输入新的学生证信息\n");
scanf("%lu\n%d\n%s",&p1->number,&p1->Class,&p1->name);
printf("已修改\n");
return 1;}
else
return 0;
}
