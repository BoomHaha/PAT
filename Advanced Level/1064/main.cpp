/*
1.����˼·���þ�̬�������ȫ���������Ը�����������������߱���������
2.��д��̬������������ȡ��С����������ע��ݹ�߽��� root>n
3.���±� 1 ��ʼ��˳������ľ��Ǹ���ȫ�������Ĳ�α���
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define maxn 1010
using namespace std;
int n=0,index=0;
vector<int> arr,CBT;
void inorder(int root)
{
	if (root>n) return;
	inorder(root*2);
	CBT[root]=arr[index++];
	inorder(root*2+1);
}
int main()
{
	scanf("%d",&n);
	CBT.resize(n+1);
	arr.resize(n);
	for (int i=0; i<n; i++) scanf("%d",&arr[i]);
	sort(arr.begin(),arr.end());
	inorder(1);
	for (int i=1; i<=n; i++) {
		printf("%d",CBT[i]);
		if (i<n) printf(" ");
	}
	return 0;
}
