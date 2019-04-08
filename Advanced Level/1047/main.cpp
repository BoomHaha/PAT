/*
1.ֱ���� unordered_map �ᳬʱ
2.�� set �治֪Ϊɶ�𰸴������ڳ�ʱ��Ե������ set ����Ч�ʱȽϵ�
3.���Ž⣺�� vector algorithm ���򣬿��� vector ����
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define maxn 40010
#define maxk 2505
using namespace std;
char names[maxn][5]= {'\0'};
vector<int> my[maxk];
bool cmp(int a,int b)
{
	return strcmp(names[a],names[b])<0;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=0; i<n; i++) {
		int c;
		scanf("%s",names[i]);
		scanf("%d",&c);
		for (int j=0; j<c; j++) {
			int id;
			scanf("%d",&id);
			my[id].push_back(i);
		}
	}
	for (int i=1; i<=k; i++) {
		int s=my[i].size();
		printf("%d %d\n",i,s);
		if (s>0) {
			sort(my[i].begin(),my[i].end(),cmp);
			for (auto it:my[i]) printf("%s\n",names[it]);
		}
	}
	return 0;
}
