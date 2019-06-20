#include "myinsert.h"
#include "mybuild.h"
#include <stdlib.h>
int myInsert(void)

{STUlist*p1;
p1=head;
while(p1->next!=NULL)
{
p1=p1->next;}
printf("请输入学生证信息");
p1->next=(STUlist*)malloc(LEN);
p1=p1->next;
scanf("%lu\n%d\n%s",&p1->number,&p1->Class,p1->name);
p1->next=NULL;
return 1;




}

int myInsert_to_file()
{STUlist*p1;
	FILE*fp1;
/*fp1=fopen("F:\\Stuide\\Student_console\\Studentconsole\\USER\\Allclass.txt","r+");
p1=head;
while(p1!=NULL)
while(!feof(fp1))
{   p2=(STUlist*)malloc(LEN);
	fscanf(fp1,"%lu%d%s",&p2->number,&p2->Class,p2->name);
    if(p1->number==p2->number);//文件中已有此数据
	break;
}
if(p1->number!=p2->number)
{fprintf(fp1,"\n%lu %d %s\n",p2->number,p2->Class,p2->name);
fclose(fp1);//重置文件指针
}
p1=p1->next;*/
	p1=head;
fp1=fopen("F:\\Stuide\\Student_console\\Studentconsole\\USER\\Allclass.txt","w+");
while(p1!=NULL)
{fprintf(fp1,"%lu %d %s\n",p1->number,p1->Class,p1->name );
p1=p1->next ;
}
fclose(fp1);
return 1;
}
