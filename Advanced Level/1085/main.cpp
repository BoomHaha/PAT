/*
1.���ֲ��ҵ�˼�룬ö��ÿ�� i�����ֲ������� j��ע��������߼�
    ���ҵ�һ�����ڵ��ڵ� upper_bound����Ҫ����������
    Ҫ�õ� rbegin() rend()
2.��ֵ��Ϊ 1����ʾ������һ����
3.������������ܺ������������Ӽ�
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	long p;
	scanf("%d%ld",&n,&p);
	vector<long> arr(n);
	for (int i=0;i<n;i++) scanf("%ld",&arr[i]);
	sort(arr.begin(),arr.end());
	int ans=1;
	for (int i=0;i<n-1;i++) {
		int j=(int)(lower_bound(arr.rbegin(),arr.rend(),(long long)arr[i]*p,greater<long long>())-arr.rbegin());
		ans=max(ans,n-j-i);
	}
	printf("%d",ans);
	return 0;
}
