/*
1.�����⣬��������
2.ע���һ�������� string ת��ΪΨһ�ı��
3.ע������ͳ�� gang ���ܱ�Ȩʱ��Ϊ�˷�ֹ�н��δ��ͳ�ƣ�����ɾ��ͳ�ƹ��ı�
4.ע�������dfs ö��ÿ���������ʱ�����жϸýڵ��Ƿ��ѷ��ʹ���δ�����ʲ� dfs ����������ܻ��ͳ�ƽ�����
5.dfs bfs ͳ����һ�����Ŀ����ðѱ��������ȫ�ֵ�
������ѽ����Ĳ����ס���������
*/
#include <bits/stdc++.h>
#define maxn 2010
using namespace std;
int threshold=0,person=0,totaltime=0,totalren=0,totalgang=0,headren=-1,temptime=-1;
struct node
{
	int id;
	int weight;
	node(int a,int b) {
		id=a;
		weight=b;
	}
};
struct gang
{
	int headid,people;
	gang(int a,int b) {
		headid=a;
		people=b;
	}
};
vector<node> nodes[maxn];
vector<gang> ans;
bool isvisit[maxn]={0};
unordered_map<string,int> nametonum,calltime;
unordered_map<int,string> numtoname;
bool cmp(gang a,gang b)
{
	return numtoname[a.headid]<numtoname[b.headid];
}
void convert(string s)
{
	if (nametonum.find(s)==nametonum.end()) {
		nametonum[s]=person;
		numtoname[person]=s;
		person++;
	}
}
void search(int k)
{
	isvisit[k]=1;
	totalren++;
	if (calltime[numtoname[k]]>temptime) {
		temptime=calltime[numtoname[k]];
		headren=k;
	}
	while (nodes[k].size()>0) {
		int tt=nodes[k][0].id;
		totaltime+=nodes[k][0].weight;
		nodes[k].erase(nodes[k].begin());
		for (int i=0;i<nodes[tt].size();i++)
			if (nodes[tt][i].id==k) {
				nodes[tt].erase(nodes[tt].begin()+i);
				break;
			}
		if (!isvisit[tt]) search(tt);
	}
}
int main()
{
	int n;
	scanf("%d%d",&n,&threshold);
	for (int i=0;i<n;i++) {
		string A,B;
		int timet;
		cin>>A>>B>>timet;
		convert(A);
		convert(B);
		calltime[A]+=timet;
		calltime[B]+=timet;
		auto it=nodes[nametonum[A]].begin();
		for (;it!=nodes[nametonum[A]].end();it++)
			if (it->id==nametonum[B]) {
				it->weight+=timet;
				for (int j=0;j<nodes[nametonum[B]].size();j++)
					if (nodes[nametonum[B]][j].id==nametonum[A]) {
						nodes[nametonum[B]][j].weight+=timet;
						break;
					}
				break;
			}
		if (it==nodes[nametonum[A]].end()) {
			nodes[nametonum[A]].push_back(node(nametonum[B],timet));
			nodes[nametonum[B]].push_back(node(nametonum[A],timet));
		}
	}
	for (int i=0;i<person;i++) {
		if (!isvisit[i]) {
			totalren=totaltime=0;
			temptime=headren=-1;
			search(i);
			if (totaltime>threshold&&totalren>2) {
				totalgang++;
				ans.push_back(gang(headren,totalren));
			}
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	printf("%d\n",totalgang);
	for (auto &p:ans) printf("%s %d\n",numtoname[p.headid].c_str(),p.people);
	return 0;
}
