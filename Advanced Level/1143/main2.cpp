/*
1.���Ž⣺������ BST ����ǰ�򣬴��߼��Ͽ��ǣ�a �� b ����͹������Ⱦ���
			ǰ���������� a �� b ֮����� c,��Ϊ a �� b �϶��ֱ�������������������
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	vector<int> arr(n);
	unordered_map<int,bool> my;
	for (int i=0;i<n;i++) {
		scanf("%d",&arr[i]);
		my[arr[i]]=1;
	}
	for (int i=0;i<m;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		int k=0;
		for (;k<n;k++) if (u>=arr[k]&&v<=arr[k]||u<=arr[k]&&v>=arr[k]) break;
		if (my[u]==0&&my[v]==0) printf("ERROR: %d and %d are not found.\n",u,v);
		else if (my[u]==0||my[v]==0)
			printf("ERROR: %d is not found.\n",my[u]?v:u);
		else if (arr[k]==u||arr[k]==v)
			printf("%d is an ancestor of %d.\n",arr[k],arr[k]==u?v:u);
		else printf("LCA of %d and %d is %d.\n",u,v,arr[k]);
	}
	return 0;
}
