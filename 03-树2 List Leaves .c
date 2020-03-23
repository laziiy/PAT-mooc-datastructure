//03-树2 List Leaves 
//给定几个节点，按照节点顺序0-N-1依次输入，输出所有的叶子节点（左右都是- -的节点） 
思路：先找到根节点，从根节点进行遍历，对于左右都为没有内容 的节点直接输出节点号 
*/

#include<stdio.h>
struct tree
{
	int data;
	int left;
	int right;
}tr[10];  //给定N不超过10，所以内容小 

int main()
{
	int i,n,count=0,root;
	char cl,cr;
	int check[10]={0};
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
		scanf("%c %c",&cl,&cr);
		getchar();
		tr[i].data=i;
		if(cl=='-'&&cr=='-')  count++;
		if(cl!='-')
		{
			tr[i].left=cl-'0';
			check[cl-'0']=1;  //标记下正常节点，以寻找根节点
		}
		else tr[i].left=-1;
		if(cr!='-')
		{
			tr[i].right=cr-'0';
			check[cr-'0']=1;   //标记下正常节点，以寻找根节点
		}
		else tr[i].right=-1;		
	}
	
	for(i=0;i<n;i++)
	{
		if(check[i]==0)  break;
	}
	root=i; //找到根节点 
	
	int queue[10]={0};
	int rear=-1,front=-1;  //设置队列，按层次输出
	struct tree p;
	queue[++rear]=root;
	while(front!=rear)
	{                       //队列不为空 
		p=tr[queue[++front]];    //队头取出节点 
		if(p.left!=-1)    queue[++rear]=p.left;    //队尾插入左孩子
		if(p.right!=-1)   queue[++rear]=p.right;   //队尾插入右孩子 
		if(p.left==-1&&p.right==-1)
		{          //输出叶子节点 
		    printf("%d",p.data);
		    count--;
		    if(count!=0)  printf(" ");
		}
	}
	return 0;
}
