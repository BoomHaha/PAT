/*
1.��û�и�����������������ѭ����������⣺
	while (cin>>a>>n)
*/
#include <iostream>
using namespace std;
int main()
{
	short a,n;
	cin>>a>>n;
	if (n!=0) cout<<a*n<<' '<<n-1;
	else cout<<"0 0";
	while (cin>>a>>n) {
		if (n!=0)
			cout<<' '<<a*n<<' '<<n-1;
	}
	return 0;
}
