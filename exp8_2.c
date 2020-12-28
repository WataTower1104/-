#include<stdio.h>
#include<stdlib.h>
struct Student
{
	long int snum;
	char sname[10];
	float score;
};
typedef struct Student INFO;
void sort(INFO *pstu);
int main()
{
	int i;
	INFO stu[10];
	INFO *pstu=stu;
	printf("=======请输入10个学生信息=======\n");
	printf("==姓名========学号========成绩==\n");
	for(i=0;i<10;i++)
	{
		scanf("%s %ld %f",&((pstu+i)->sname),&((pstu+i)->snum),&((pstu+i)->score));
		fflush(stdin);
	}
	sort(pstu);
	printf("========转换后的学生信息========\n");
	printf("==姓名========学号========成绩==\n");
	for(i=0;i<10;i++)
	{
		printf("  %s      %ld      %f  \n",(pstu+i)->sname,(pstu+i)->snum,(pstu+i)->score);
	}
	printf("\n");
	return 0;
}
void sort(INFO *pstu)
{
	INFO p;
	int i,j;
	for(i=0;i<10;i++)
		for(j=i+1;j<10;j++)
		{
			if((pstu+i)->score<(pstu+j)->score)
			{
				p=pstu[i];
				pstu[i]=pstu[j];
				pstu[j]=p;
			}
		}
}