#include<stdio.h>
#include<stdlib.h>
struct Student
{
	long int snum;
	char name[10];
	float score;
	char rank;
};
typedef struct Student INFO;
double SetGrade(INFO *p,int *a,int *b,int *c,int *d,int *e);
int main()
{
	INFO *pstu;
	int i,num,a,b,c,d,e;
	double avg;
	printf("������ѧ������:");
	scanf("%d",&num);
	fflush(stdin);
	if(num<=0) return 0;
	pstu=(INFO*)malloc(num*sizeof(INFO));
	if(pstu==NULL)
	{
		printf("���㹻�ڴ�!\n");
		return 0;
	}
	printf("=========������ѧ����Ϣ=========\n");
	printf("==����========ѧ��========�ɼ�==\n");
	for(i=0;i<num;i++)
	{
		scanf("%s %ld %f",&((pstu+i)->name),&((pstu+i)->snum),&((pstu+i)->score));
		fflush(stdin);
	}
	avg=SetGrade(pstu,&a,&b,&c,&d,&e);
	printf("=================ѧ����Ϣ===============\n");
	printf("==��  ��======ѧ��======�ɼ�======�ȼ�==\n");
	for(i=0;i<num;i++)
	{
		printf("  %s      %ld      %f      %c  \n",(pstu+i)->name,(pstu+i)->snum,(pstu+i)->score,(pstu+i)->rank);
	}
	printf("\n");
	free(pstu);
	printf("���س��˳�");
	return 0;
}


double SetGrade(struct Student *p, int *a, int *b, int *c, int *d, int *e)
{
	int i;
    double average = 0;
    for(i=0;i<10;i++)
    {
        if ((p + i)->score >= 90)
        {
            (p + i)->rank = 'A';
			(*a)++;
        }
        else if ((p + i)->score >= 80)
        {
            (p + i)->rank = 'B';
			(*b)++;
        }
        else if ((p + i)->score >= 70)
        {
            (p + i)->rank = 'C';
			(*c)++;
        }
        else if ((p + i)->score >= 60)
        {
            (p + i)->rank = 'D';
			(*d)++;
        }
        else
        {
            (p + i)->rank = 'E';
			(*e)++;
        }
        average += p->score;
    }
    average /= 10;
    return average;
}