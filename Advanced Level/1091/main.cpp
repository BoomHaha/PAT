/*
1.ע���ά����Ķ��壺int arr[x][y]  x �� y �е�����
2.�ɴ�ע����ά����Ķ��壺int arr[x][y][z] x �� y �� z �ߵ�����
3.������ʱ�࿪ 5 �� 10 ����Ӧ�Լ�������
4.�������ʾ����任
*/
#include <iostream>
#include <queue>
using namespace std;
//ע�����
short arr[1300][130][65]= {0};
bool inq[1300][130][65]= {0};
int m,n,l,t;
struct node {
	int x,y,z;
	node(int x1,int y1,int z1) {
		x=x1;
		y=y1;
		z=z1;
	}
};
//ע�����
short nextX[]= {1,-1,0,0,0,0};
short nextY[]= {0,0,1,-1,0,0};
short nextZ[]= {0,0,0,0,1,-1};
bool judge(node a)
{
	if (a.x>m-1||a.x<0||a.y>n-1||a.y<0||a.z>l-1||a.z<0) return 0;
	if (inq[a.x][a.y][a.z]) return 0;
	if (arr[a.x][a.y][a.z]==0) return 0;
	return 1;
}
int search(int x,int y,int z)
{
	int countt=0;
	queue<node> q;
	node xx(x,y,z);
	inq[x][y][z]=1;
	q.push(xx);
	while (!q.empty()) {
		node curt=q.front();
		q.pop();
		countt++;
		for (int h=0; h<6; h++) {
			node newt(curt.x+nextX[h],curt.y+nextY[h],curt.z+nextZ[h]);
			if (judge(newt)) {
				inq[newt.x][newt.y][newt.z]=1;
				q.push(newt);
			}
		}
	}
	if (countt>=t) return countt;
	else return 0;
}
int main()
{
	int volume=0;
	scanf("%d%d%d%d",&m,&n,&l,&t);
	//ע���һ����
	for (int i=0; i<l; i++)
		for (int j=0; j<m; j++)
			for (int k=0; k<n; k++) scanf("%d",&arr[j][k][i]);
	for (int i=0; i<l; i++)
		for (int j=0; j<m; j++)
			for (int k=0; k<n; k++)
				if (arr[j][k][i]==1&&inq[j][k][i]==0) volume+=search(j,k,i);
	printf("%d\n",volume);
	return 0;
}
