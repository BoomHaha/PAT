/*
1.���һ�����Ե�������� 1 �� �������Բ�����
2.ע�⣺n ֻ�ܱ�������֮���С�� sqrt(n) ����������
*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	long n,startnum=0;
	int maxlens=0;
	scanf("%ld",&n);
	long sqr=(long)sqrt(n*1.0);
	for (long i=2; i<=sqr; i++) {
		long a=i,e=1;
		int countt=0;
		while (n%a==0) {
			a*=i+(e++);
			countt++;
		}
		if (countt>maxlens) {
			maxlens=countt;
			startnum=i;
		}
	}
	if (maxlens==0) printf("1\n%ld",n);
	else {
		printf("%d\n",maxlens);
		for (int i=0; i<maxlens; i++) {
			printf("%ld",startnum+i);
			if (i<maxlens-1) printf("*");
		}
	}
	printf("\n");
	return 0;
}
