#include<bits/stdc++.h>
using namespace std;

struct Program{
    int startTime;
    int endTime;
    bool operator < (const Program &a){
        return endTime < a.endTime;
    }
};

vector<Program> programs;

int main(){
    int n;
    Program protmp;
    int startTmp,endTmp;
    while(cin>>n && n!=0){
        for(int i=0;i<n;i++){
            cin>>protmp.startTime>>protmp.endTime;
            programs.push_back(protmp);
        }
        sort(programs.begin(), programs.end());
        int curTime=0,sum=0;
        for(vector<Program>::iterator it=programs.begin();it<programs.end();it++){
            if(curTime<=it->startTime){
                curTime = it->endTime;
                sum++;
            }
        }
        cout<<sum<<endl;
        programs.clear();//全局变量必须清空
    }
    return 0;
}
