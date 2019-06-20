#include "mydelete.h"
#include "myinsert.h"
#include "mysearch.h"
#include "mybuild.h"
#include <stdlib.h>
#include <string.h>


extern STUlist*head;

int main()
{
int choice1,choice2;
char China[10];//输入汉字用
unsigned long int number;
enum symbol1{del=1,inse,seek,change,out};
enum symbol2{hand=1,file};

	printf("******************\n欢迎来到学生证管理系统\n******************\n");
printf("删除文件，请键入1\n添加文件，请键入2\n查找信息，请键入3\n修改信息，请键入4\n将信息导入文件，请键入5\n");
part1 :printf("请输入您的选择:");
scanf("%d",&choice1);
printf("\n");
getchar();//吸收回车


if(head==NULL)//检索数据库中是否有数据
{printf("检索到数据库为空，是否添加数据？(输入 是or否)");
scanf("%s",&China);
if(strcmp(China,"否")==0)
exit(0);//退出文件
else if(strcmp(China,"是")==0)
{printf("请选择输入文件的方式\n若手动添加，则键入1\n若从文件导入，则键入2\n");
scanf("%d",&choice2);


	
	switch(choice2)
{case hand://手动输入
{    printf("输入格式为：\n学生证号：\n班级：\n姓名：\n若输入结束，则在本次输入的姓名处加#\n");
     printf("范例：\n20185527\n1\n郭雨龙#\n");
     myBuild_hand();//进行手动输入数据

}break;//选择hand的下括号
	case file://文件输入
		{
		myBuild_file();
		printf("**********\n导入完成\n**********\n");}break;


}//switch的下括号

goto part1;
}//选择是的elseif的下括号

else
{printf("ERROR!!\n请重新输入");
	goto part1;}//选择不是‘是’或‘否’的else的下括号





}//检索数据库中是否有数据的下括号

switch(choice1)
{
case del:
	{printf("删除：请输入学生证编号");
	scanf("%d",&number);
	if(number>99999999||number<10000000)//输入的学生证号码位数有误
		printf("**********\nERROR:输入的学生证号码位数有误\n**********\n");
	else
	{if(myDelete(number)!=0)
	printf("**********\n删除完成\n**********\n");
	else
		printf("**********\nERROR:未找到此信息!\n**********\n");}
	goto part1;}break;
case inse:{
		  myInsert();
		  printf("**********\n插入完成\n**********\n");
		  goto part1;}break;
case seek:
	{int seek_choice;
	enum{seek_person=1,seek_class};
		printf("**********\n查询个人信息，请键入1\n查询班级，请键入2\n**********\n");
        scanf("%d",&seek_choice);
		switch(seek_choice)
		{case seek_person:
		{printf("请输入学生证号");
		scanf("%lu",&number);
        if(number>99999999||number<10000000)//输入的学生证号码位数有误
		printf("**********\nERROR:输入的学生证号码位数有误\n**********\n");
        else
		{	if(mySearch(number)!=0)
				printf("**********\n查找完成\n**********\n");
			else
                printf("**********\nERROR:未找到此条信息!\n**********\n");}
			goto part1;//结束则返回最初
		}break;
		case seek_class:
			{int the_class;
				printf("请输入班级号(1~5)\n");
			scanf("%d",&the_class);
			if(the_class<1||the_class>5)//输入的班级码有误
		    printf("**********\nERROR:输入的班级码有误\n**********\n");
			else
			{if(mySearch_class(the_class)!=0)
				printf("**********\n查找完成\n**********\n");
			else
				printf("**********\nERROR:未找到此条信息!\n**********\n");}
			goto part1;//结束则返回最初
			
			
			}//seekclass的下括号
		}//seekswitch的下括号
	
	
	}//caseseek的下括号
case change:
	{printf("请输入学生证号");
	scanf("%lu",&number);
	mychange(number);
	printf("**********\n重置成功\n**********\n");
	goto part1;
	}break;
case out:
	{myInsert_to_file();
	printf("**********\n已将现有信息导入文件\n**********\n");
	goto part1;
	}break;
default:{printf("**********\nERROR:您输入的信息有误!\n**********\n\n");
	     goto part1;
		
		}break;

}


return 0;

}//主函数的下括号
