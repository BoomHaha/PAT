/*
1.�ɱ��ⷢ�ֵ�һ��С���⣺����ֱ�ӳ�ʼ���� 0 ���Ե���д�� int ranks[maxn]={-1};
                            �������
�ο����ͣ�https://www.cnblogs.com/haoyijing/p/5815035.html
int arr[maxn]={-1}; ����ֻ���ʼ����һ��Ԫ�أ��������� 0
*/
#include <bits/stdc++.h>
#define maxn 10010
using namespace std;
bool vis[maxn]={0};
int ranks[maxn]={0};
bool isprime(int k)
{
	if (k<2) return 0;
	int sqr=int(sqrt(k));
	for (int i=2;i<=sqr;i++) if (k%i==0) return 0;
	return 1;
}
int main()
{
	int n,k;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		int id;
		scanf("%d",&id);
		ranks[id]=i;
	}
	scanf("%d",&k);
	for (int i=0;i<k;i++) {
		int id;
		scanf("%d",&id);
		if (ranks[id]==0) printf("%04d: Are you kidding?\n",id);
		else {
			if (vis[id]) printf("%04d: Checked\n",id);
			else {
				if (ranks[id]==1) printf("%04d: Mystery Award\n",id);
				else if (isprime(ranks[id])) printf("%04d: Minion\n",id);
				else printf("%04d: Chocolate\n",id);
				vis[id]=1;
			}
		}
	}
	return 0;
}
