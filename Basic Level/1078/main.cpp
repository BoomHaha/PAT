/*
1.string��int�໥ת���ķ�����
	1.to_string()��������֪���ĸ�ͷ�ļ���ģ����ò��˾ͻ���
	2.stoi stringתint
	3.stringstream�ࣨ���䷽����
2.������ո���ַ�����getline����
    ע��getline֮ǰ����cin������cin�����ignore����
3.string���Դ���һЩ������insert  erase  substr  c_str
	insert�����Ĳ��룺����stringʱλ��ֻ����int�±��ʾ
	                    ���뵥���ַ�ʱλ�ÿ�����iterator��ʾ
*/
#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;
int strtoint(string s)
{
	stringstream str(s);
	int temp;
	str>>temp;
	return temp;
}
string inttostr(int a)
{
	stringstream str;
	str<<a;
	return str.str();
}
string compress(string s)
{
	string aa="";
	for (int i=0;i<s.length();) {
		int k=i+1;
		while (s[k]==s[i]&&k<s.length()) k++;
		if (k-i==1) {
			aa.insert(aa.end(),s[i]);
			i++;
		}
		else if (k-i>1) {
			aa.insert(aa.size(),inttostr(k-i));
			aa.insert(aa.end(),s[i]);
			i=k;
		}
	}
	return aa;
}
string uncompress(string s)
{
	string aa="";
	for (int i=0;i<s.length();) {
		if (isdigit(s[i])) {
			int k=i+1;
			while (isdigit(s[k])) k++;
			int num=strtoint(s.substr(i,k-i));
			aa.insert(aa.end(),num,s[k]);
			i=k+1;
		}
		else if (isalpha(s[i])||isblank(s[i])) {
			aa.insert(aa.end(),s[i]);
			i++;
		}
	}
	return aa;
}
int main()
{
	char a;
	string ss;
	cin>>a;
	cin.ignore();
	getline(cin,ss,'\n');
	if (a=='C') cout<<compress(ss)<<endl;
	else if (a=='D') cout<<uncompress(ss)<<endl;
	return 0;
}
