/*01-复杂度2 Maximum Subsequence Sum  题目链接：https://pintia.cn/problem-sets/1211841066264109056/problems/1211848231062290433
!！最小值不唯一的时候 输出最小的i和j
！！如果所有的输入的值都是负数的时候，输出总和为0  还有首 尾的值 
负数和0 都存在的时候 输出 0 
*/
#include<stdio.h>
#define max 100000
int main()
{
	int i,n,sum=0,temp=0,a[max],start=0,end=0,flag1=0,flag2=0,count=0; //flag1记录是否全是负数，flag2记录判断起始位置 
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]<0) count++;
	}
	
	for(i=0;i<n;i++)
	{
		temp+=a[i];
		if(temp>sum) //加进来的数比0 大 
		{
			flag1=1; //现在不是都为负数，对于负数特别处理 
			if(flag2==0)
			{
			    start=i; //标记初始位置 
			    flag2=1; 
			}
			sum=temp;
			end=i; 
		}
		if(temp<0) //比0小的时候自动归零 
		{
			temp=0;
			flag2=0; 
		}
	} 
	if(count==n) //都是负数的时候，输出0 首 尾值 
	{
		printf("0 ");
		printf("%d %d",a[0],a[n-1]);
	}
	else if(flag1==0)// 当0和负数同时出现 输出全0 
	{
		printf("0 0 0");
	}
	else printf("%d %d %d",sum,a[start],a[end]);
	return 0;
 } 
 
