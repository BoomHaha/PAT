/*
1.map�Զ���������
2.ע�����͵�ѡ��
3.map�е�erase�����Ĳ��� (1)��iteratorָ��
						 (2)�ùؼ���key
						 (3)����ĳ�����䣺��iteratorָ�룬ָ��ʼ�ͽ���
*/
#include <cstdio>
#include <map>
using namespace std;
struct comp
{
	bool operator()(int a,int b) const {
		return a>b;
	}
};
int main()
{
	int n1,n2;
	map<int,double,comp> arr;
	scanf("%d",&n1);
	for (int i=0;i<n1;i++) {
		int exp;
		double coe;
		scanf("%d%lf",&exp,&coe);
		arr[exp]=coe;
	}
	scanf("%d",&n2);
	for (int i=0;i<n2;i++) {
  		int exp;
		double coe;
		scanf("%d%lf",&exp,&coe);
		map<int,double,comp>::iterator it=arr.find(exp);
		if (it!=arr.end()) {
			it->second+=coe;
			if (it->second==0) arr.erase(it);
		}
		else arr[exp]=coe;
	}
	int countt=arr.size();
	if (countt==0) {
		printf("%d",countt);
		return 0;
	}
	printf("%d ",countt);
	for (map<int,double,comp>::iterator p=arr.begin();p!=arr.end();p++) {
		printf("%d %.1lf",p->first,p->second);
		countt--;
		if (countt) printf(" ");
	}
	return 0;
}
