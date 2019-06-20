#include "mybuild.h"
#include <stdlib.h>




int myBuild_hand(void)
{int count;
extern STUlist*head=NULL;
	STUlist*p1,*p2;
head=p1=p2=(STUlist*)malloc(LEN);
printf("请输入数据");
scanf("%lu\n%d\n%s",&head->number,&head->Class,&head->name);
for(count=0;(head->name)[count]!='\0';count++)
{if((head->name)[count]=='#')//结束标志
break;
}
if((head->name)[count]=='#')
head->next=NULL;//防止只输入一个数据

else
{printf("请输入数据");
p1=(STUlist*)malloc(LEN);
head->next=p1;
scanf("%lu\n%d\n%s",&p1->number,&p1->Class,&p1->name);
for(count=0;(p1->name)[count]!='\0';count++)
{if((p1->name)[count]=='#')//结束标志
break;
}
if((p1->name)[count]=='#')
(p1->next)=NULL;//防止只输入两个数据
else
{
while((p1->name[count])!='#')
{printf("请输入数据");
p2=(STUlist*)malloc(LEN);
p1->next=p2;
scanf("%lu\n%d\n%s",&p2->number,&p2->Class,&p2->name);
for(count=0;(p1->name)[count]!='\0';count++)
{if((p1->name)[count]=='#')//结束标志
{(p1->name)[count]='\0';//去除结束标志
	break;}
}

p1=p2;


p2->next=NULL;
}//while的下括号


}//对于第二次输入数据的else的下括号





}//对于第一次输入数据的else的下括号

printf("创建完成\n");


return 1;
}




/*
出于复杂度考虑，文件将自行提供，不需要使用者输入文件名
*/

int myBuild_file()
{
FILE*fstu;
STUlist*p1,*p2;
head=p1=p2=(STUlist*)malloc(LEN);
fstu=fopen("F:\\Stuide\\Student_console\\Studentconsole\\USER\\Allclass.txt","r");

fscanf(fstu,"%lu%d%s",&head->number,&head->Class,head->name);
p1=(STUlist*)malloc(LEN);
fscanf(fstu,"%lu%d%s",&p1->number,&p1->Class,p1->name);
head->next=p1;
while(!feof(fstu))
{
p2=(STUlist*)malloc(LEN);
fscanf(fstu,"%lu%d%s",&p2->number,&p2->Class,p2->name);
p1->next=p2;
p1=p2;
}
p1->next=NULL;
fclose(fstu);
return 1;
}
