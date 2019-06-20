#include "mydelete.h"
#include "mybuild.h"
#include <stdlib.h>

int myDelete(unsigned long int number)
{
STUlist*p1;
p1=head;
while(p1!=NULL)
{
if(p1->number==number)
break;
p1=p1->next;
}
if(p1->number==number)
{
free(p1->next);
p1->next =(p1->next)->next;
return 1;
}
else
return 0;

}
