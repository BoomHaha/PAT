/*
1.����������ָ�봦���ַ�����˼��
2.��λһ�飬��Ҫ�ж����������һ�Ƿ�������ǰ�����㣬����������λȫ����
3.���ڿո�Ĵ�������������ո��������Ҫ���ݣ�ֻ����λ������ո񼴿ɣ����Ա���ĩβ�����
4.������ش�ڶ���
*/
#include <iostream>
#include <string>
using namespace std;
string arr1[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
string arr2[5]={"Shi","Bai","Qian","Wan","Yi"};
int main()
{
	string s;
	cin>>s;
	if (s=="0") {
		cout<<"ling";
		return 0;
	}
	if (s[0]=='-') {
		cout<<"Fu ";
		s.erase(0,1);
	}
	int a=0,b=s.length()-1;
	while (4<=b) b-=4;
	while (b<s.length()) {
		bool flag=0,isprint=0;
		while (a<=b) {
			if (s[a]=='0') flag=1;
			else {
				if (flag) {
					cout<<" ling";
					flag=0;
				}
				if (a>0) cout<<' ';
				cout<<arr1[s[a]-'0'];
				if (a!=b) cout<<' '<<arr2[b-a-1];
				isprint=1;
			}
			a++;
		}
		if (isprint) {
			int cha=(s.length()-1-b)/4;
			if (cha) cout<<' '<<arr2[cha+2];
		}
		b+=4;
	}
	return 0;
}
