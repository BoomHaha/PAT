/*
1.ȡģ���㣬��Ҫд�� ans+=nump*numt%mod ��Ϊ mod ���㲻���н����
            Ҫд�� ans=(ans+nump*numt)%mod
2.�����ǱȽ��ѵ��߼��⣬ע���ҵ�����
*/
#include <iostream>
#include <string>
using namespace std;
const int mod=1000000007;
const int maxn=100010;
int numP[maxn]={0};
int main()
{
	string s;
	getline(cin,s,'\n');
	long ans=0;
	int lens=s.length(),numT=0;
	if (s[0]=='P') numP[0]=1;
	else numP[0]=0;
	for (int i=1;i<lens;i++) {
		if (s[i]=='P') numP[i]=numP[i-1]+1;
		else numP[i]=numP[i-1];
	}
	for (int i=lens-1;i>=0;i--) {
		if (s[i]=='T') numT++;
		else if (s[i]=='A') ans=(numP[i]*numT+ans)%mod;
	}
	printf("%ld",ans);
	return 0;
}
