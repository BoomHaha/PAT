/*
1.ע���һ���������⣬�ж���һ�κ�ͼ�Ѿ����޸ģ������һ��ʼӦ�ð�ͼ����һ�飬
            ÿ�ж���һ�κ���л�ԭ��ʹ�� short ���Խ�ʡ�ռ�
*/
#include <bits/stdc++.h>
#define maxn 1010
using namespace std;
short graph[maxn][maxn]={0},backup[maxn][maxn]={0};
vector<int> ans;
int n=0;
int main()
{
	int m,k;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		graph[a][b]=1;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) backup[i][j]=graph[i][j];
	scanf("%d",&k);
	for (int i=0;i<k;i++) {
		vector<int> arr(n);
		bool flag=0;
		for (int j=0;j<n;j++) scanf("%d",&arr[j]);
		for (int j=0;j<n;j++) {
			int t=arr[j];
			for (int h=1;h<=n;h++)
				if (graph[h][t]==1) {
					flag=1;
					break;
				}
			if (flag) {
				ans.push_back(i);
				break;
			}
			else for (int h=1;h<=n;h++) graph[t][h]=0;
		}
		if (i<k-1) for (int i1=1;i1<=n;i1++) for (int j1=1;j1<=n;j1++)
			graph[i1][j1]=backup[i1][j1];
	}
	for (int i=0;i<ans.size();i++) {
		printf("%d",ans[i]);
		if (i<ans.size()-1) printf(" ");
	}
	return 0;
}
