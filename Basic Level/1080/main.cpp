/*
1.cmathͷ�ļ��е��������뺯����round
2.map �����ṩ string���Զ���ṹ���ӳ��  map<string,stu> arr;
    �ṹ���ʼ����ֵΪ���캯����Ԥ���ֵ
*/
#include <iostream>
#include <map>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
struct stu
{
	string num;
	int gprogram;
	int gmidterm;
	int gfinal;
	int g;
	public:
		stu()
		{
			gprogram=-1;
			gmidterm=-1;
			gfinal=-1;
			g=-1;
		}
};
bool cmp(struct stu a,struct stu b)
{
	if (a.g==b.g) return a.num<b.num;
	else return a.g>b.g;
}
int main()
{
	int p,m,n;
	map<string,stu> arr;
	vector<stu> arr2;
	cin>>p>>m>>n;
	for (int i=0;i<p;i++) {
		string num;
		int gprog;
		cin>>num>>gprog;
		arr[num].gprogram=gprog;
	}
	for (int i=0;i<m;i++) {
		string num;
		int gmid;
		cin>>num>>gmid;
		arr[num].gmidterm=gmid;
	}
	for (int i=0;i<n;i++) {
		string num;
		int gfina;
		cin>>num>>gfina;
		arr[num].gfinal=gfina;
	}
	for (map<string,stu>::iterator it=arr.begin();it!=arr.end();it++) {
		stu temp;
		temp.num=it->first;
		temp.gprogram=(it->second).gprogram;
		temp.gmidterm=(it->second).gmidterm;
		temp.gfinal=(it->second).gfinal;
		if (temp.gmidterm>temp.gfinal) temp.g=round(temp.gmidterm*0.4+temp.gfinal*0.6);
		else temp.g=temp.gfinal;
		if (temp.gprogram>=200&&temp.g>=60) arr2.push_back(temp);
	}
	sort(arr2.begin(),arr2.end(),cmp);
	for (int i=0;i<arr2.size();i++) {
		cout<<arr2[i].num<<' '<<arr2[i].gprogram<<' '<<arr2[i].gmidterm<<' '
			<<arr2[i].gfinal<<' '<<arr2[i].g<<endl;
	}
	return 0;
}
