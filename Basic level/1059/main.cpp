/*
1.algorithm��Ҫ���յ�4���������书�ܣ�
	find  sort   reverse   for_each
	ע�� string.find �� map.find string �� map �Դ�
2.iteratorָ��ת��Ϊ�±�ķ�����
(1)(int)(it-a.begin())
(2) iteratorͷ�ļ��е�distance  advance����
*/
#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>
#include <memory.h>
using namespace std;
bool isprime(int n)
{
	for (int j=2;j<=(int)sqrt(n);j++) {
		if (n%j==0) return false;
	}
	return true;
}
int main()
{
	int n,k,ischeck[10000];
	memset(ischeck,0,sizeof(ischeck));
	cin>>n;
	deque<int> ids;
	for (int i=0;i<n;i++) {
		int stuid;
		cin>>stuid;
		ids.push_back(stuid);
	}
	cin>>k;
	for (int i=0;i<k;i++) {
		int checknum;
		cin>>checknum;
		deque<int>::iterator it=find(ids.begin(),ids.end(),checknum);
		if (it==ids.end()) {
			printf("%04d: Are you kidding?\n",checknum);
			continue;
		}
		if (ischeck[*it]==1) {
			printf("%04d: Checked\n",checknum);
			continue;
		}
		if (it==ids.begin()) {
			printf("%04d: Mystery Award\n",checknum);
			ischeck[*it]=1;
		}
		else if (isprime((int)(it-ids.begin())+1)) {
			printf("%04d: Minion\n",checknum);
			ischeck[*it]=1;
		}
		else {
			printf("%04d: Chocolate\n",checknum);
			ischeck[*it]=1;
		}
	}
	return 0;
}
