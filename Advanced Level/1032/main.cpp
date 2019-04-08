/*
1.�ؼ�������������־λ����
2.Ϊ�˽�ʡ�ռ䣬�����ַ���ڵ��ӳ������� unordered_map
*/
#include <iostream>
#include <unordered_map>
using namespace std;
struct node
{
	int data,next;
	bool flag;
	node() {
		data=next=0;
		flag=0;
	}
};
int main()
{
	unordered_map<int,node> my;
	int node1,node2,n;
	scanf("%d %d %d",&node1,&node2,&n);
	for (int i=0; i<n; i++) {
		node tt;
		int addr;
		scanf("%d %c %d",&addr,&tt.data,&tt.next);
		my[addr]=tt;
	}
	bool isappear=0;
	for (int p=node1;p!=-1;p=my[p].next) my[p].flag=1;
	for (int p=node2;p!=-1;p=my[p].next) {
		if (my[p].flag) {
			printf("%05d\n",p);
			isappear=1;
			break;
		}
	}
	if (!isappear) printf("-1\n");
	return 0;
}
