/*
1.��ר�ŵ�����洢���������1�����
2.�������⣬��ͬ�ĳɼ�ռ��ͬ�����Σ�
	int r=1;
	for (int i=0;i<n;i++) if (i>0&&stu[i].grade!=stu[i-1].grade) r=i+1;
	ʹ����2�����
3.ע�����ȼ�������ͨ������ı����ȼ��������һ��ʼ���ź����ȼ�
4.���⣬�ش�ڶ���
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
char leibie[4]={'C','M','E','A'};   //1��
int shunxu[]={2,1,0,3};
struct stu
{
	int id;
	int grade;
	stu(int a,int b) {
		id=a;
		grade=b;
	}
};
bool cmp(struct stu a,struct stu b)
{
	return a.grade>b.grade;
}
int main()
{
	vector<stu> arr[4];
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++) {
		int id,c,m,e,a;
		scanf("%d %d %d %d",&id,&c,&m,&e);
		a=(c+m+e)/3;
		stu aa(id,c),bb(id,m),cc(id,e),dd(id,a);
		arr[0].push_back(aa);
		arr[1].push_back(bb);
		arr[2].push_back(cc);
		arr[3].push_back(dd);
	}
	for (int i=0;i<4;i++) sort(arr[i].begin(),arr[i].end(),cmp);
	for (int i=0;i<m;i++) {
		int search;
		int rank[4];
		bool flag=1;
		scanf("%d",&search);
		for (int j=0;j<4;j++) {
			rank[j]=1;
			for (int k=0;k<n;k++) {
				if (k>0&&arr[j][k].grade!=arr[j][k-1].grade) rank[j]=k+1;   //2��
				if (arr[j][k].id==search) {
					flag=0;
					break;
				}
			}
			if (flag) {
				printf("N/A\n");
				break;
			}
		}
		if (!flag) {
			int maxlei,maxrank=2000;
			for (int g=0;g<4;g++)
				if (rank[shunxu[g]]<=maxrank) {
					maxrank=rank[shunxu[g]];
					maxlei=shunxu[g];
				}
			printf("%d ",maxrank);
			printf("%c\n",leibie[maxlei]);      //1�����
		}
	}
	return 0;
}
