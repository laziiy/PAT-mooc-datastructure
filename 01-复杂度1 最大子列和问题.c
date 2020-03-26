/*01-复杂度1 最大子列和问题*/题目：https://pintia.cn/problem-sets/1211841066264109056/problems/1211848231062290432
//方法一：
#include<stdio.h>
#define max 100000
int main()
{
	int i,n,sum=0,temp=0,a[max];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		temp+=a[i]; 
		if(temp>sum)
		{
			sum=temp;
		}
		if(temp<0) //当前值比0小，抛弃 
		{
			temp=0;
		}
	}
printf("%d",sum); 
return 0;
}

//方法二：
#include<stdio.h>
#define max 100000
int main()
{
	int i,j,n,sum=0,temp=0,a[max];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++) //左边的起始位置 
	{
		temp=0;
		for(j=i;j<n;j++) //右边终止位置 
		{
			temp+=a[j];
			if(temp>sum)  sum=temp;
		}
	}
printf("%d",sum); 
return 0;
}
