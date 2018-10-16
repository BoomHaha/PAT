/*
1.stringstream�����ת��Ϊint  unsigned long long ��������
        Ҫ��string�����ּ��ת��
2.cin�����޷���������ֱ���䣬��scanf������Ҫ������Ƹ�ʽ��%u����%d�����
*/
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
unsigned long long stringtoint(string s)
{
	stringstream strr(s);
	unsigned long long aa;
	strr>>aa;
	return aa;
}
bool ishuiwenshu(unsigned long long n)
{
	string temp=to_string(n);
	int k=temp.length()-1;
	for (int i=0;i<=k/2;i++) {
		if (temp[i]!=temp[k-i]) return false;
	}
	return true;
}
int main()
{
	unsigned long long n;
	int countt=1;
	cin>>n;
	while (countt<=10) {
		if (ishuiwenshu(n)) {
			cout<<n<<" is a palindromic number.\n";
			return 0;
		}
		else {
			string num=to_string(n);
			reverse(num.begin(),num.end());
			unsigned long long nre=stringtoint(num);
			cout<<n<<" + "<<num<<" = ";
			n+=nre;
			cout<<n<<endl;
			countt++;
		}
	}
	cout<<"Not found in 10 iterations.\n";
	return 0;
}
