/*
1.һ���ǳ������Ĵ��󣺽���ʱǧ������˼�������
2.������ȷ�ⷨ�Ǹ���ǰ�����н�����������ǰ������ж��Ƿ�һ��
3.vector�����Ƚ�Ԫ���Ƿ���ͬ����ֱ���� == ��������������
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
	int data;
	struct node *lchild,*rchild;
	node(int x) {
		data=x;
		lchild=rchild=NULL;
	}
};
vector<int> pre,pretest,ans;
void postorder(node *p)
{
	if (p==NULL) return;
	postorder(p->lchild);
	postorder(p->rchild);
	ans.push_back(p->data);
}
void preorder(node *p)
{
	if (p==NULL) return;
	pretest.push_back(p->data);
	preorder(p->lchild);
	preorder(p->rchild);
}
void exchange(node *p)
{
	if (p==NULL) return;
	exchange(p->lchild);
	exchange(p->rchild);
	node *tt=p->lchild;
	p->lchild=p->rchild;
	p->rchild=tt;
}
//ע���һ������ǧ������˼ӣ���������Ҫע��
void insert(node *&root,int x)
{
	if (root==NULL) {
		root=new node(x);
		return;
	}
	if (root->data<=x) insert(root->rchild,x);
	else insert(root->lchild,x);
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		int aa;
		scanf("%d",&aa);
		pre.push_back(aa);
	}
	node *root=NULL;
	for (int i=0; i<n; i++) insert(root,pre[i]);
	preorder(root);
	if (pre==pretest) {
		postorder(root);
		printf("YES\n");
		for (int i=0; i<ans.size(); i++) {
			printf("%d",ans[i]);
			if (i<ans.size()-1) printf(" ");
		}
	} else {
		pretest.clear();
		exchange(root);
		preorder(root);
		if (pre==pretest) {
			postorder(root);
			printf("YES\n");
			for (int i=0; i<ans.size(); i++) {
				printf("%d",ans[i]);
				if (i<ans.size()-1) printf(" ");
			}
		} else printf("NO\n");
	}
	return 0;
}
