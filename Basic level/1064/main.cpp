/*
1.set���Զ����غ��Զ�����Ĺ��ܣ����������в������ظ�����ʱ������
        ������Ҫ����ʱ(���ظ�����multiset)
*/
#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
	int N;
	set<short> shuzu;
	cin>>N;
	for (int i=0;i<N;i++) {
		string str;
		cin>>str;
		short sum=0;
		for (int i=0;i<str.length();i++)
			sum+=str[i]-'0';
		shuzu.insert(sum);
	}
	cout<<shuzu.size()<<endl;
	int j=0;
	for (set<short>::iterator i=shuzu.begin();i!=shuzu.end();i++,j++) {
		cout<<*i;
		if (j!=shuzu.size()-1) cout<<' ';
	}
	return 0;
}
