/*
1.��������˵��̰���к��ѵ��ˣ��ú����˼·
2.��Ŀ��û��˵�������������Ҵ�ʵ�����忼�ǿ�����С���ı�������� double ��
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000001
using namespace std;
struct station
{
	double price,dis;
};
bool cmp(station a,station b)
{
	if (a.dis!=b.dis) return a.dis<b.dis;
	else return a.price<b.price;
}
int main()
{
	double Cmax,D,Davg;
	int n;
	scanf("%lf %lf %lf %d",&Cmax,&D,&Davg,&n);
	vector<station> arr(n+1);
	for (int i=0;i<n;i++)
		scanf("%lf %lf",&arr[i].price,&arr[i].dis);
	arr[n].price=0.0;
	arr[n].dis=D;
	sort(arr.begin(),arr.end(),cmp);
	if (arr[0].dis>0) {
		printf("The maximum travel distance = 0.00\n");
		return 0;
	}
	int cur=0;
	double totalexp=0.0,maxdis=Cmax*Davg,curCap=0.0;
	while (cur<n) {
		/*
        ����һ������վ���ӵ�ǰ����վ��ʼ����Ҫ����ʻ�ķ�Χ�ڣ�
        ˼�룺����бȵ�ǰ�ͼ۸��͵ľ�ֱ��ѡ����
                ���û�о�ѡ��һ���ͼ���͵�
                ����Ҳ���˵�����ܵ���һ���ˣ�ֱ�����
		*/
		int k=0;
		double minPrice=INF;
		for (int i=cur+1;i<=n&&arr[i].dis-arr[cur].dis<=maxdis;i++) {
			if (arr[i].price<minPrice) {
				minPrice=arr[i].price;
				k=i;
			}
			if (minPrice<arr[cur].price) break;
		}
		if (k==0) {
			double overDis=arr[cur].dis+maxdis;
			printf("The maximum travel distance = %.2lf\n",overDis);
			return 0;
		}
		/*
        �ӵ�ǰ����һ������վ��˼·��
        1.����¸�����վ�ͼ�С�ڵ�ǰ����ֻ���ܹ����¸�����վ���ͣ����¸�������Ϊ0
        2.������ǣ����ڵ�ǰ���ͼ�����������һ����������ȥ��Ӧ��
        3.�������
		*/
		double need=(arr[k].dis-arr[cur].dis)/Davg;
		if (minPrice<arr[cur].price)
			if (curCap<need) {
				totalexp+=(need-curCap)*arr[cur].price;
				curCap=0;
			}
			else curCap-=need;
		else {
			totalexp+=(Cmax-curCap)*arr[cur].price;
			curCap=Cmax;
			curCap-=need;
		}
		cur=k;
	}
	printf("%.2lf\n",totalexp);
	return 0;
}
