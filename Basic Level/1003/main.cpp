/*
1.map���÷���map<char,int>��ʾcharΪ������intΪ��ֵ
			map<string,int>  stringΪ������intΪ��ֵ
			map���Զ������Ƿ��йؼ�������
			�����ڣ���ֱ�Ӷ����Ӧ��ֵ�����޸�
			�������ڣ�������벢��ֵ
*/
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
	unsigned short n;
	cin>>n;
	for (unsigned short i=0;i<n;i++) {
		string ss;
		unsigned short Ppos=0,Tpos=0;
		map<char,int> mm;
		cin>>ss;
		for (unsigned short j=0;j<ss.length();j++) {
			mm[ss[j]]++;
			if (ss[j]=='P') Ppos=j;
			if (ss[j]=='T') Tpos=j;
		}
		if (mm.size()==3&&mm['P']==1&&mm['T']==1&&mm['A']!=0&&Ppos*(Tpos-Ppos-1)==ss.length()-Tpos-1)
			cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
