/*
���Ž⣺
�õļ��������ֵĴ���һ������k�ı���
ֻҪ����һ���ַ���������������ֵĴ�������k�ı������ַ�����
ע��Ӻ���Ͽ���
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> v(300);
vector<int> vis(300);
int main()
{
	int k,cnt=1;
	string s;
	cin>>k>>s;
	char per='#';
	s+="#";
	for (int i=0;i<s.length();i++) {
		if (s[i]==per) cnt++;
		else {
			if (cnt%k) v[per]=1;
			cnt=1;
		}
		per=s[i];
	}
	for (int i=0;i<s.length()-1;i++)
		if (v[s[i]]==0&&vis[s[i]]==0) {
			cout<<s[i];
			vis[s[i]]=1;
		}
	cout<<endl;
	for (int i=0;i<s.length()-1;i++) {
		cout<<s[i];
		if (v[s[i]]==0) i+=k-1;
	}
	cout<<endl;
	return 0;
}
