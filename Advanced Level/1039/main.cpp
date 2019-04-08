/*
1.map ����һ��ģ�������
2.���� set map ģ�����ĩβ������ո������
*/
#include <iostream>
#include <unordered_map>
#include <set>
#include <string>
using namespace std;
int main()
{
	int n,k;
	unordered_map<string,set<int> > my;
	scanf("%d%d",&n,&k);
	for (int i=0;i<k;i++) {
		int coursenum,people;
		scanf("%d%d",&coursenum,&people);
		for (int j=0;j<people;j++) {
			string name;
			cin>>name;
			my[name].insert(coursenum);
		}
	}
	for (int i=0;i<n;i++) {
		string s;
		cin>>s;
		auto p=my.find(s);
		if (p==my.end()) cout<<s<<" 0";
		else {
			int countt=(p->second).size();
			cout<<s<<' '<<countt<<' ';
			for (auto t:(p->second)) {
				cout<<t;
				countt--;
				if (countt>0) cout<<' ';
			}
		}
		cout<<endl;
	}
	return 0;
}
