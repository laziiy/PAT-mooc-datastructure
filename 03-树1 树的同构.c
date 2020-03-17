/*03-树1 树的同构 
题目：https://pintia.cn/problem-sets/1211841066264109056/problems/1234055373040824320
解题思路：参考mooc小白专场视频，主函数里构建创建两棵树的函数，创建树Tree BuildTree (struct TreeNode T[]对树相连的子节点进行遍历，
不为空的在check数组中进行标记，遍历完没被标记的即为根节点。
找到根节点之后，建立Isomorphic(R1,R2)分类讨论，通过递归的方式判断左右树之间的关系以判断是否为同构树
*/
#include <stdio.h>
#include <stdlib.h>
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1

struct TreeNode{
	ElementType Element;
	Tree Left;
	Tree Right;
}T1[MaxTree],T2[MaxTree];

Tree BuildTree (struct TreeNode T[])
{
	char cl,cr;
	int check[10];
	int i,N;//循环次数 
	int Root=Null;
	/*输入二叉树的总层数*/
	scanf("%d\n",&N);
	//getchar();
	if(N){
	for (i=0;i<N ;i++)
	{
		check[i]=0;
	}
	/*输入二叉树每一层的信息*/ 
	for (i=0;i<N;i++)
	{
		scanf("%c %c %c\n",&T[i].Element,&cl,&cr);
		if(cl!='-'){
			T[i].Left=cl-'0';
			check[T[i].Left]=1; 
		}else{
			T[i].Left=Null;
		}
		if(cr!='-'){
			T[i].Right=cr-'0';
			check[T[i].Right]=1; 
		}else{
			T[i].Right=Null;
		}
	}
	/*得到根节点的位置*/ 
	for (i=0;i<N;i++)
	{
		if(!check[i]) break;
	}
	Root=i;
	}
	return Root;
}

Tree Isomorphic(Tree R1,Tree R2) 
{
	//r1 r2为空 
	if(R1==Null&&R2==Null)  
		return 1;
	//r1空 r2不空或者 r2空 r1为不空
	if(((R1!=Null)&&(R2==Null))||((R1==Null)&&(R2!=Null)))
		return 0;
	//r1的元素和r2元素不一样
	if (T1[R1].Element!=T2[R2].Element)
		return 0;
	//两数的左节点均为空
	if ((T1[R1].Left==Null)&&(T2[R2].Left==Null))  
		return(Isomorphic(T1[R1].Right,T2[R2].Right));
	if (((T1[R1].Left!=Null)&&(T2[R2].Left!=Null))&&((T1[T1[R1].Left].Element)==(T2[T2[R2].Left].Element)))
	//两数的左子树均不为空并且左子树根节点一样
		return(Isomorphic(T1[R1].Left,T2[R2].Left)&&Isomorphic(T1[R1].Right,T2[R2].Right));
	else
		return(Isomorphic(T1[R1].Left,T2[R2].Right)&&Isomorphic(T1[R1].Right,T2[R2].Left));
}

int main()
{
	Tree R1,R2;	
	R1=BuildTree (T1);
	R2=BuildTree (T2);
	if(Isomorphic(R1,R2)) printf("Yes\n");
	else printf("No\n");
	return 0;
}
