/*
1.Ҫ�õ� long long ʱ���� typedef long long ll ��
2.long long ���������Ҫ�����������ǽ�ȥ������ת��ʱҪ�жϣ�����
    ���ж�������СʱҲҪ����
3.�ø����������������λ+1��Ϊ���ֿ�ʼ���½磬�� ans �� �½� �����ֵ+1���Ͻ�
4.������  1.��ϸ���Ǳ������ͺ����
			2.���ֲ���
			3.��ֹ˼ά��ʽ
*/
#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <sstream>
using namespace std;
//ע���һ
typedef long long ll;
ll strtoll(string s)
{
	stringstream ss(s);
	ll a;
	ss>>a;
	return a;
}
ll convertTo10(string n,int radix)
{
	if (radix==10) return strtoll(n);
	else {
		ll s=0;
		int a=0;
		while (n.length()>0) {
			char cc=n[n.length()-1];
			if (isdigit(cc))
				s+=(ll)((cc-'0')*pow(radix,a));
			else if (isalpha(cc))
				s+=(ll)((10+cc-'a')*pow(radix,a));
			n.erase(n.length()-1,1);
			if (s<0) return -1;
			a++;
		}
		return s;
	}
}
//n>t-->1 n==t-->0 n<t-->-1
//ע������long long ���������
int cmp(string n,int radix,ll t)
{
	ll num=convertTo10(n,radix);
	if (num<0) return 1;
	else if (t>num) return -1;
	else if (t==num) return 0;
	else return 1;
}
//ע�����
//ans ��ʼֵ�趨���⣨���˺þã�
//û��ע�⵽���Ҫ�� 1��ϸ��ϸ����ϸ��
int findlowest(string n)
{
	int ans=1;
	for (int i=0; i<n.length(); i++)
		if (isdigit(n[i])) ans=max(ans,n[i]-'0');
		else if (isalpha(n[i])) ans=max(ans,n[i]-'a'+10);
	return ans+1;
}
ll binarysearch(string n,ll low,ll high,ll t)
{
	ll mid;
	while (low<=high) {
		mid=(low+high)/2;
		int flag=cmp(n,mid,t);
		if (flag==0) return mid;
		else if (flag==-1) low=mid+1;
		else if (flag==1) high=mid-1;
	}
	return -1;
}
int main()
{
	string n1,n2;
	int tag,radix;
	cin>>n1>>n2>>tag>>radix;
	if (tag==2) swap(n1,n2);
	ll ans=convertTo10(n1,radix);
	ll low=findlowest(n2);
	ll high=max(low,ans)+1;
	ll oo=binarysearch(n2,low,high,ans);
	if (oo==-1) printf("Impossible");
	else printf("%lld",oo);
	return 0;
}
