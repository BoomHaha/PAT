/*
1.ע������ṹ���е�����ʱ��Ҫ���Ǽ� &��scanf ��ϸ��飡��
2.time�����ǹؼ��ʣ�����ɽṹ��Ҫ��ǰ��� struct ������ֱ�Ӹ�timet
    �����ǹؼ��ʵ�Ҫ����ʶ�ں���Ӹ�t
3.ʱ��ת����������00:00:00Ϊ��ʼ��ȫ��ת��Ϊ�룬
            ��Ҫע��ת�������ĺ�����ǧ�����д���ˣ�������
4.���ε����壺��ѯʱ ����ʱ��==��ѯʱ�� ��������
                ����  ��ȥʱ��==��ѯʱ��  ������������
5.̫���ˣ�������ʱ��д���˲�ѯ���浼��ÿ��plate��������k�Σ�
6.��ʱ���⣺
	(1)�Ѽ������ʱ�������Ϸ����ݺϲ�
	(2)ע���ѯʱ��Ϊ��������˿������ñ��now������һ���Ͱ�now����Ϊ����������±�
	    ǰ���ǺϷ���¼Ҫ��time����
7.����ת��ʱ�䣺ѧϰ��
	printf("%02d:%02d:%02d", maxtime / 3600, (maxtime % 3600) / 60, maxtime % 60);
8.printf ��� string �ķ�����
	string ss;
	printf("%s",ss.c_str());
scanf �����ַ����ķ�����
	char s1[10];
	scanf("%s",s1);
	string s(s1);
9.����򻯣����ض���ʱ��Ľṹ�壬����ȫ��ת��Ϊ�� 00:00:00 ��ʼ����
10.�� auto ���� map vector ��
	https://blog.csdn.net/sdnulixianrui/article/details/78627544
	ע�� map ȡ������ pair ��������ָ��
	���Ҫ�� p.first p.second
	vector ȡ����ֱ����Ԫ��
*/
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
struct record
{
	string plate;
	int time;
	bool status;
};
bool cmp(record a,record b)
{
	if (a.plate!=b.plate) return a.plate<b.plate;
	else return a.time<b.time;
}
bool cmp2(record a,record b)
{
	return a.time<b.time;
}
int main()
{
	int n,k,maxtime=-1,hh,mm,ss;
	vector<record> arr;
	vector<record> vaild;
	map<string,int> my2;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) {
		record aa;
		char s1[10],s2[4];
		scanf("%s %d:%d:%d %s",s1,&hh,&mm,&ss,s2);
		string temp(s1);
		aa.plate=s1;
		aa.time=hh*3600+mm*60+ss;
		if (strcmp(s2,"in")==0) aa.status=0;
		else if (strcmp(s2,"out")==0) aa.status=1;
		arr.push_back(aa);
	}
	sort(arr.begin(),arr.end(),cmp);
	for (int i=0;i<arr.size()-1;i++) {
		if (arr[i].plate==arr[i+1].plate&&arr[i].status==0&&arr[i+1].status==1) {
			vaild.push_back(arr[i]);
			vaild.push_back(arr[i+1]);
			int inTime=arr[i+1].time-arr[i].time;
			my2[arr[i].plate]+=inTime;
			maxtime=max(maxtime,my2[arr[i].plate]);
		}
	}
	sort(vaild.begin(),vaild.end(),cmp2);
	//ע������ͳ�Ƹ�����д�����Ǳ����ܷ�AC�Ĺؼ�
	int now=0,countt=0;
	for (int i=0;i<k;i++) {
		int hh,mm,ss,time2;
		scanf("%d:%d:%d",&hh,&mm,&ss);
		time2=hh*3600+mm*60+ss;
		while (now<vaild.size()&&vaild[now].time<=time2) {
			if (vaild[now].status==0) countt++;
			else countt--;
			now++;
		}
		printf("%d\n",countt);
	}
	
	for (auto &p:my2)
		if (p.second==maxtime) printf("%s ",p.first.c_str());
	printf("%02d:%02d:%02d\n",maxtime/3600,(maxtime%3600)/60,maxtime%60);
	return 0;
}
