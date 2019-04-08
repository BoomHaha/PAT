/*
1.hash��ͻ����ʽ��H=(temp+pow(a++,2))%TSize
                    ������ȡģ��
2.�Ҳ�������λ�õ��ж�����ӦΪ a>m �� a �Ѿ��������� TSize
3.ע�� ƽ��̽���Ӣ�� quadratic probing
*/
#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;
bool isprime(int n)
{
	if (n<2) return 0;
	int sqr=(int)sqrt(n*1.0);
	for (int i=2; i<=sqr; i++) if (n%i==0) return 0;
	return 1;
}
int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	while (!isprime(m)) m++;
	unordered_map<int,int> hasht;
	for (int i=0; i<n; i++) {
		int t,a=1;
		scanf("%d",&t);
		int H=t%m;
		int temp=H;
		while (hasht.find(H)!=hasht.end()) {
			H=(temp+(int)pow(a++,2))%m;
			if (a>m) {
				printf("-");
				break;
			}
		}
		if (a<=m) {
			hasht[H]=t;
			printf("%d",H);
		}
		if (i<n-1) printf(" ");
	}
	return 0;
}
