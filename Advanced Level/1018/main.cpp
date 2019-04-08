/*
1.20�֡�����֪���ˣ�ԭ��������ûŪ͸
            ���ⲻ���ü򵥵��ۼӳ�������Ӧ���������Ƚ���ȷ�����߻��Ǵ���
            ��Ϊ����Ҫ��ֻ����ǰ�ߵ��յ�Ȼ�󷵻أ������ǿ�����·������������
            ����������ʱ����վ����������
            ���ֻ��ͨ������·��ģ��ķ�ʽ����
2.���԰� bike ������� w-c/2 Ϊ����ʾ��Ҫ���ߣ�Ϊ����ʾ��Ҫ����
3.����С need �����ʱ��ҲҪ��ֵ minback ����������Ȼ��֪��Ϊʲô������
4.������ǳ����⣬��ʱ���ٴ�һ��
*/
#include <bits/stdc++.h>
#define maxn 510
using namespace std;
const int inf=1e9;
int c=0,n=0,endt=0,graph[maxn][maxn]={0},bike[maxn]={0},dis[maxn]={0};
int minsend=inf,minback=inf,send=0,back=0;
bool vis[maxn]={0};
vector<int> pre[maxn],tempp,ans;
void calc(int k)
{
	fill(dis,dis+maxn,inf);
	dis[k]=0;
	for (int y=0;y<=n;y++) {
		int u=-1,minp=inf;
		for (int h=0;h<=n;h++) if (dis[h]<minp&&vis[h]==0) {
			u=h;
			minp=dis[h];
		}
		if (u==-1) return;
		vis[u]=1;
		for (int h=0;h<=n;h++) if (graph[u][h]!=0&&vis[h]==0) {
			if (dis[h]>dis[u]+graph[u][h]) {
				dis[h]=dis[u]+graph[u][h];
				pre[h].clear();
				pre[h].push_back(u);
			}
			else if (dis[h]==dis[u]+graph[u][h]) pre[h].push_back(u);
		}
	}
}
void search(int k)
{
	tempp.push_back(k);
	if (k==0) {
		send=back=0;
		for (int g=tempp.size()-2;g>=0;g--) {
			if (bike[tempp[g]]>0) back+=bike[tempp[g]];
			else if (bike[tempp[g]]<0) {
				if (back>=abs(bike[tempp[g]])) back-=abs(bike[tempp[g]]);
				else {
					send+=abs(bike[tempp[g]])-back;
					back=0;
				}
			}
		}
		if (send<minsend) {
			minsend=send;
			minback=back;
			ans=tempp;
		}
		else if (send==minsend) {
			if (back<minback) {
				minback=back;
				ans=tempp;
			}
		}
		tempp.pop_back();
		return;
	}
	for (int j=0;j<pre[k].size();j++) search(pre[k][j]);
	tempp.pop_back();
}
int main()
{
	int m;
	scanf("%d%d%d%d",&c,&n,&endt,&m);
	for (int i=1;i<=n;i++) {
		int w;
		scanf("%d",&w);
		bike[i]=w-c/2;
	}
	for (int i=0;i<m;i++) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		graph[a][b]=graph[b][a]=c;
	}
	calc(0);
	search(endt);
	printf("%d ",minsend);
	for (int i=ans.size()-1;i>=0;i--) {
		printf("%d",ans[i]);
		if (i>0) printf("->");
	}
	printf(" %d\n",minback);
	return 0;
}
