/*
1.algorithm����� find �� is_sorted ������ķѴ���ʱ��
2.ʹ�� right ��ʾδ��ȷ��λ�����֣�����0֮�⣩
3.����ȫ�ֱ��� k ʹ�ҽ���λ��ʱʱ��Ϊ��������
*/
#include <iostream>
#include <algorithm>
#define maxn 100010
using namespace std;
int arr[maxn]={0};
int main()
{
	int n,sum=0,k=1,right;
	scanf("%d",&n);
	right=n-1;
	for (int i=0;i<n;i++) {
		scanf("%d",&arr[i]);
		if (arr[i]==i) right--;
	}
  	while (right>0) {
  		if (arr[0]==0) {
  			while (k<n&&arr[k]==k) k++;
  			swap(arr[k],arr[0]);
  			sum++;
		}
		while (arr[0]!=0) {
			swap(arr[0],arr[arr[0]]);
			sum++;
			right--;
		}
	}
	printf("%d\n",sum);
	return 0;
}
