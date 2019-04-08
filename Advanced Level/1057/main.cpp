/*
1.��״����������lowbit getsum update
2.��������״���������� hash �����ã�ÿ���±걣���±����ֳ��ֵĸ���
3.Ѱ�ҵ� k ��Ԫ�صȼ����ҵ���С�� i ʹ hash[1]+hash[2]+...+hash[i]>=k ����
    �ڱ�����ʹ�ö��ֲ��ҵķ�ʽ�ҵ���С�� i
*/
#include <bits/stdc++.h>
#define maxn 100001
using namespace std;
stack<int> st;
int arr[maxn]={0};
int lowbit(int x)
{
	return x&(-x);
}
int getsum(int x)
{
	int sum=0;
	for (int h=x;h>0;h-=lowbit(h)) sum+=arr[h];
	return sum;
}
void update(int x,int v)
{
	for (int h=x;h<=maxn;h+=lowbit(h)) arr[h]+=v;
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		char order[20]={'\0'};
		scanf("%s",order);
		if (strcmp(order,"Push")==0) {
			int t;
			scanf("%d",&t);
			st.push(t);
			update(t,1);
		}
		else if (strcmp(order,"Pop")==0) {
			if (st.empty()) printf("Invalid\n");
			else {
				printf("%d\n",st.top());
				update(st.top(),-1);
				st.pop();
			}
		}
		else {
			if (st.empty()) printf("Invalid\n");
			else {
				int kst=(st.size()&1)?((st.size()+1)/2):(st.size()/2);
				int left=1,right=maxn,mid;
				while (left<right) {
					mid=(left+right)/2;
					if (getsum(mid)>=kst) right=mid;
					else left=mid+1;
				}
				printf("%d\n",left);
			}
		}
	}
	return 0;
}
