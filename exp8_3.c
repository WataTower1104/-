#include<stdio.h>
#include<math.h>
struct  time
{
	int hour;
	int minu;
	int secd;
};
typedef struct time TIME;
TIME TimeDiff(TIME t1,TIME t2)
{
	TIME t3;
	int temp;
	t3.hour=abs(t1.hour-t2.hour);
	if( (temp=(t1.minu-t2.minu)) <0)
	{
		if(t1.hour>t2.hour) 
			{(t3.hour)--;t3.minu=60+temp;}
		else t3.minu=-temp;
	}
	else
	{
		if(t1.hour<t2.hour)
			{(t3.hour)--;t3.minu=60-temp;}
		else t3.minu=temp;
	}
//---------------------------------------������ķ������߼ӷ�
	if( (temp=(t1.secd-t2.secd)) <0)
	{
		if(t1.hour>t2.hour) 
			{(t3.minu)--;t3.secd=60+temp;}
		else t3.secd=-temp;
	}
	else 
	{
		if(t1.hour<t2.hour) 
			{(t3.minu)--;t3.secd=temp?60-temp:0;}
		else t3.secd=temp;
	}
	return t3;		
}
int main()
{
	TIME t1,t2,t3;
	printf("�������һ��ʱ�䣬��ʱ:��:�����ʽ��");
	scanf("%d%*c%d%*c%d",&t1.hour,&t1.minu,&t1.secd);
	printf("������ڶ���ʱ�䣬��ʱ:��:�����ʽ��");
	scanf("%d%*c%d%*c%d",&t2.hour,&t2.minu,&t2.secd);
	t3=TimeDiff(t1,t2);
	printf("ʱ���Ϊ%d:%d:%d\n",t3.hour,t3.minu,t3.secd);
}
