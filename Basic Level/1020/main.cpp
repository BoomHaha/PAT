/*
1.̰�ĵ�˼�룺�Ȱ��±������۴Ӵ�С�ţ��ٴ���λ��ʼ����ֱ����������
2.printf�ı�־����λ��%04d %.2f %.2lf %-d % d
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct mooncake
{
	float mount;
	float price;
	float unitprice;
};
bool cmp(struct mooncake a,struct mooncake b)
{
	return a.unitprice>b.unitprice;
}
int main()
{
	int n,need;
	cin>>n>>need;
	vector<mooncake> arr(n);
	for (int i=0;i<n;i++) cin>>arr[i].mount;
	for (int i=0;i<n;i++) {
		cin>>arr[i].price;
		arr[i].unitprice=arr[i].price/arr[i].mount;
	}
	sort(arr.begin(),arr.end(),cmp);
	float sum=0.0f;
	for (int i=0;i<n;i++) {
		if (arr[i].mount<=need) {
			sum+=arr[i].price;
			need-=arr[i].mount;
		}
		else {
			sum+=need*arr[i].unitprice;
			break;
		}
	}
	printf("%.2f",sum);
	return 0;
}
