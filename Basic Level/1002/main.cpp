/*
1.string����ֵ��(int long unsigned int short��)��ת������
	(1)stringstream��
	(2)to_string����(��һ���ܱ���ͨ���������˾��õ�һ��)
2.string��length�����������ַ�������
*/
#include <iostream>
#include <string>
using namespace std;
char numbers[10][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int main()
{
	string num;
	unsigned int sum=0;
	cin>>num;
	for (unsigned short i=0;i<num.length();i++) sum+=num[i]-'0';
	string sum1=to_string(sum);
	for (unsigned short i=0;i<sum1.length();i++) {
		if (i!=sum1.length()-1) cout<<numbers[sum1[i]-'0']<<' ';
		else cout<<numbers[sum1[i]-'0']<<endl;
	}
	return 0;
}
