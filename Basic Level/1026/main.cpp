/*
1.scanf ������Ʒ� %s(�����ַ�����) %c %d %f
2.cmath round ceil floor
3.printf ������Ʒ�
*/
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	int c1,c2;
	scanf("%d %d",&c1,&c2);
	int secc=round((float)(c2-c1)/100.0f);
	int hours=secc/3600;
	secc%=3600;
	int minutes=secc/60;
	secc%=60;
	printf("%02d:%02d:%02d\n",hours,minutes,secc);
	return 0;
}
