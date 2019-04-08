/*
1.˼·�ú�ѧһѧ�������ǵݹ��ж��͵ĺ���д����judge1��judge2��
2.�������һ����������ת�����ж����������߶��Ƿ���ȵ�����
    ���߶�ָ���� black �ڵ�ĸ�����
*/
#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	bool rb;
	struct node *lchild,*rchild;
	node(int x) {
		data=abs(x);
		if (x>=0) rb=0;
		else rb=1;
		lchild=rchild=NULL;
	}
};
void insert(node *&p,int x)
{
	if (p==NULL) {
		p=new node(x);
		return;
	}
	if (p->data<abs(x)) insert(p->rchild,x);
	else if (p->data>abs(x)) insert(p->lchild,x);
}
int getheight(node *p)
{
	if (p==NULL) return 0;
	int left=getheight(p->lchild);
	int right=getheight(p->rchild);
	return (p->rb==0)?max(left,right)+1:max(left,right);
}
bool judge1(node *p)
{
	if (p==NULL) return 1;
	if (p->rb==1) {
		if (p->lchild!=NULL&&p->lchild->rb==1) return 0;
		if (p->rchild!=NULL&&p->rchild->rb==1) return 0;
	}
	return judge1(p->lchild)&&judge1(p->rchild);
}
bool judge2(node *p)
{
	if (p==NULL) return 1;
	int lh=getheight(p->lchild),rh=getheight(p->rchild);
	if (lh!=rh) return 0;
	return judge2(p->lchild)&&judge2(p->rchild);
}
int main()
{
	int k;
	scanf("%d",&k);
	for (int i=0;i<k;i++) {
		int n;
		scanf("%d",&n);
		node *root=NULL;
		for (int j=0;j<n;j++) {
			int w;
			scanf("%d",&w);
			insert(root,w);
		}
		if (root->rb==1) printf("No\n");
		else {
			if (judge1(root)&&judge2(root)) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}
