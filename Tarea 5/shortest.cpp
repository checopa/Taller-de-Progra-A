#include <bits/stdc++.h>

using namespace std;


int main(){
    char fl,fn,sl,sn;
    int fln,sln,dh,dv;
    string v,h;
    cin>>fl>>fn>>sl>>sn;
    fln=(int)fl;
    sln=(int)sl;
    if(fln<sln){
        h="R";
    }
    else{
        h="L";
    }
    if(fn<sn){
        v="U";
    }
    else{
        v="D";
    }
    dh=abs(fln-sln);
    dv=abs(fn-sn);
    if(dh>dv){
        cout<<dh<<endl;
        for(int i=0;i<dh;i++){
            cout<<h;
            if(dv>0){
                cout<<v;
                dv--;
            }
            cout<<endl;
        }
    }
    else{
        cout<<dv<<endl;
        for(int i=0;i<dv;i++){
            if(dh>0){
                cout<<h;
                dh--;
            }
            cout<<v<<endl;
        }
    }



    return 0;
}