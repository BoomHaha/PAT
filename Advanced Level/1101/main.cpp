/*
1.��ȷ���ֲ��� upper_bound lower_bound ʹ����������Ϊ��������
2.��������⡣����֪��Ϊʲô
3.ѧ��ʹ�� max min
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n,countt=1;
	scanf("%d",&n);
	vector<long> ans,arr(n),leftt(n),rightt(n);
	for (int i=0; i<n; i++) {
		scanf("%d",&arr[i]);
		if (i>0) {
			if(arr[i]>arr[i-1]) {
				leftt[i]=leftt[i-1]+countt;
				countt=1;
			} else {
				leftt[i]=leftt[i-1];
				countt++;
			}
		}
	}
	countt=1;
	for (int i=n-1; i>=0; i--) {
		if (i<n-1) {
			if (arr[i]<arr[i+1]) {
				rightt[i]=rightt[i+1]+countt;
				countt=1;
			} else {
				rightt[i]=rightt[i+1];
				countt++;
			}
		}
		if (leftt[i]==i&&rightt[i]==n-1-i) ans.push_back(arr[i]);
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for (int i=0; i<ans.size(); i++) {
		printf("%d",ans[i]);
		if (i<ans.size()-1) printf(" ");
	}
	printf("\n");
	return 0;
}
