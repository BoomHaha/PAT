/*
1.ע�Ȿ������ҵ�һ������� unique number
*/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main()
{
	int n;
 	unordered_map<int,int> my;
 	vector<int> my2;
	cin>>n;
	for (int i=0;i<n;i++) {
		int m;
		cin>>m;
 	 	my[m]++;
 	 	my2.push_back(m);
	}
	//����ҵ�һ������� unique number
	for (int i=0;i<my2.size();i++)
		if (my[my2[i]]==1) {
			cout<<my2[i];
			return 0;
		}
	cout<<"None";
	return 0;
}
