/*
1.ϸ�ģ�ע�� heap �����±�� 1 ��ʼ��
2.����ıȽ� after �� heap ��heap ��ǰ��һ��Ԫ�أ��������±�� 1 ��ʼ
                            �Ƚ�ʱ after ҲҪǰ���� heap һ����Ԫ��
3.���㷨�ص㣺���ѡ����������µ���
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> heap,initial,after;
int n=0,num;
void downAdjust(int low,int high)
{
	int i=low,j=i*2;
	while (j<=high) {
		if (j+1<=high&&heap[j]<heap[j+1]) j++;
		if (heap[i]<heap[j]) {
			swap(heap[i],heap[j]);
			i=j;
			j=i*2;
		}
		else break;
	}
}
void createheap()
{
	for (int i=n/2;i>=1;i--) downAdjust(i,n);
}
void heapsort()
{
	swap(heap[num--],heap[1]);
	downAdjust(1,num);
}
int main()
{
	scanf("%d",&n);
	initial.resize(n);
	after.resize(n);
	for (int i=0;i<n;i++) scanf("%d",&initial[i]);
	for (int i=0;i<n;i++) scanf("%d",&after[i]);
	vector<int> temp(initial.begin(),initial.end());
	int i=1;
	while (i<n) {
		int tt=temp[i];
		temp.erase(temp.begin()+i);
		auto it=upper_bound(temp.begin(),temp.begin()+i,tt);
		temp.insert(it,tt);
		i++;
		if (temp==after) {
			printf("Insertion Sort\n");
			int tt=temp[i];
			temp.erase(temp.begin()+i);
			auto it=upper_bound(temp.begin(),temp.begin()+i,tt);
			temp.insert(it,tt);
			for (int j=0;j<n;j++) {
				printf("%d",temp[j]);
				if (j<n-1) printf(" ");
			}
			return 0;
		}
	}
	if (i==n) {
		heap=initial;
		num=n;
		heap.insert(heap.begin(),-1);
		after.insert(after.begin(),-1);
		createheap();
		while (num>1) {
			heapsort();
			if (heap==after) {
				printf("Heap Sort\n");
				heapsort();
				for (int j=1;j<=n;j++) {
					printf("%d",heap[j]);
					if (j<n) printf(" ");
				}
				return 0;
			}
		}
	}
	return 0;
}
