#include<fstream>
#include<iostream>
#include<algorithm>
using namespace std;
int s;//物品种数
int c;//背包容量
int value=0;//背包最大价值
int br[1000],brr=0;//编号结果
int wr[1000],wrr=0;//比例结果
struct thing{
    int w;//重量
    int v;//价值
    int bh;//编号
}th[1000];
bool cmp(thing x,thing y){
    return (double)(x.v)/(double)(x.w)>(double)(y.v)/(double)(y.w);
}
int main()
{
    cout<<"输入物品种数：";
    cin>>s;
    cout<<"分别输入物品的重量和价值：";
    for(int i=0;i<s;i++){
        cin>>th[i].w;
        cin>>th[i].v;
        th[i].bh=i+1;
    }
    cout<<"输入背包容量：";
    cin>>c;
    sort(th,th+s,cmp);
    int i;
    for(i=0;i<s;i++){
        if(th[i].w>c)
            break;
        br[brr++]=th[i].bh;
        wr[wrr++]=th[i].w;
        value+=th[i].v;
        c-=th[i].w;
    }
    if(i<s){
        br[brr++]=th[i].bh;
        wr[wrr++]=c;
        value+=(double)th[i].v/th[i].w*c;
        c=0;
    }
    cout<<"分配情况:";
    for(int i=0;i<brr;i++){
        cout<<"编号"<<br[i]<<"装入重量："<<wr[i]<<endl;
    }
    cout<<"背包最大价值："<<value<<endl;
    cout<<"背包剩余容量："<<c<<endl;
    return 0;
}
