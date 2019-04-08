/*
1.�����Ҹ��ڵ㣺���Բ���ǰ�����ÿ���ڵ�ķ�ʽ�����ǿ�һ�����飬������ʱ���ֵĽڵ�ȫ��
                ��¼�������ҵ�һ��δ���ֵĽڵ㡣
2.������һ����������ȫ�����������ڵ��ţ����������ȫ��������maxid �ᳬ���ڵ��� n
3.���ˣ�ע�⵽ n <= 20 �������ڵ㲻���� char ����
*/
#include <bits/stdc++.h>
#define maxn 30
using namespace std;
int n,maxid=-1,ans,nodenum=0;
struct node
{
	int id,lchild,rchild;
	node() {
		lchild=rchild=id=-1;
	}
}nodes[maxn];
void layerorder(int k)
{
	queue<int> q;
	q.push(k);
	nodes[k].id=1;
	while (!q.empty()) {
		int t=q.front();
		q.pop();
		if (maxid<nodes[t].id) {
			maxid=nodes[t].id;
			ans=t;
		}
		if (nodes[t].lchild!=-1) {
			nodes[nodes[t].lchild].id=nodes[t].id*2;
			q.push(nodes[t].lchild);
		}
		if (nodes[t].rchild!=-1) {
			nodes[nodes[t].rchild].id=nodes[t].id*2+1;
			q.push(nodes[t].rchild);
		}
	}
}
void preorder(int p)
{
	if (p==-1) return;
	nodenum++;
	preorder(nodes[p].lchild);
	preorder(nodes[p].rchild);
}
int strtoint(string s)
{
	stringstream ss(s);
	int a;
	ss>>a;
	return a;
}
int main()
{
	cin>>n;
	for (int i=0;i<n;i++) {
		string a,b;
		cin>>a>>b;
		if (a!="-") nodes[i].lchild=strtoint(a);
		if (b!="-") nodes[i].rchild=strtoint(b);
	}
	int root=0;
	for (int i=0;i<n;i++) {
		nodenum=0;
		preorder(i);
		if (nodenum==n) {
			root=i;
			break;
		}
	}
	layerorder(root);
	if (maxid>n) {
		printf("NO %d\n",root);
		return 0;
	}
	else if (maxid==n) printf("YES %d\n",ans);
	return 0;
}
