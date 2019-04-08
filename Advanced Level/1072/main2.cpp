#include<bits/stdc++.h>
using namespace std;
struct Edge{//�ߵ���
    int v,length;
};
int N,M,K,Ds,station=-1;//station��ʾ����Ҫ��ļ���վ���
double minDis=-1,avgDis=1e9;//�������סլ�����롢������סլ����ƽ������
vector<Edge>graph[1015];//ͼ
int dis[1015];//��סլ���ͼ���վ����̾���
bool visit[1015];//�Ƿ��ѷ��ʹ�
int trans(const string&s){//������վ�ġ�Gi����ʽ�ı��ת����N+i��סլ���ı�Ų���
    if(s[0]=='G')
        return stoi(s.substr(1))+N;
    else
        return stoi(s);
}
void Dijkstra(){
    for(int j=0;j<N+M;++j){//ѭ��N+M��
        int v=-1,MIN=INT_MAX;
        for(int i=1;i<=N+M;++i)//�ҳ�Ŀǰ������С�ı��
            if(!visit[i]&&dis[i]<MIN){
                MIN=dis[i];
                v=i;
            }
        if(v==-1)//���ͼ����ͨ��ֱ�ӷ���
            return;
        visit[v]=true;//��ǰ����ѷ���
        for(Edge&e:graph[v])//�����ܵ���ı�ŵ���̾���
            if(!visit[e.v]&&dis[e.v]>dis[v]+e.length)
                dis[e.v]=dis[v]+e.length;
    }
}
int main(){
    scanf("%d%d%d%d",&N,&M,&K,&Ds);
    for(int i=0;i<K;++i){
        string s1,s2;
        int k1;
        cin>>s1>>s2>>k1;
        int k2=trans(s1),k3=trans(s2);
        graph[k2].push_back({k3,k1});
        graph[k3].push_back({k2,k1});
    }
    for(int i=N+1;i<=N+M;++i){//��M������վʹ��M��Dijkstra�㷨
        fill(dis,dis+N+M+1,INT_MAX);
        dis[i]=0;
        fill(visit,visit+M+N+1,false);
        Dijkstra();
        double currentMindis=INT_MAX*1.0,currentAvgDis=0.0;//��¼��ǰ����վ�������סլ�����롢������סլ����ƽ������
        bool flag=true;//��ʾ������סլ���ľ����Ƿ��ڷ���Χ��
        for(int j=1;j<=N&&flag;++j)//������Ӧ������Ϣ
            if(j!=i&&dis[j]<=Ds){
                currentMindis=min(currentMindis,dis[j]*1.0);
                currentAvgDis+=dis[j]*1.0;
            }
            else if(dis[j]>Ds)
                flag=false;
        currentAvgDis/=N;
        if(flag&&(currentMindis>minDis||(currentMindis==minDis&&currentAvgDis<avgDis))){
            station=i;
            minDis=currentMindis;
            avgDis=currentAvgDis;
        }
    }
    if(station!=-1)//�з���Ҫ��ļ���վ�����
        printf("G%d\n%.1f %.1f",station-N,minDis,avgDis);
    else
        printf("No Solution");
    return 0;
}
