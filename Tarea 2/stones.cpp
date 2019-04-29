#include <iostream>
#include <vector>

using namespace std;

long long maximo(long long a,long long b, long long c){
    long long max=0;
    if (a<b){
        max=b;
    }
    else{
        max=a;
    }
    if (max<c){
        max=c;
    }
    return max;
}


int main(){
    long long h,w,t;
    cin>>t;
    vector<long long> test(t);
    while(t){
        cin>>h>>w;
        vector<vector<long long> > stones(h,vector<long long>(w));
        vector<vector<long long> > maxstones(h,vector<long long>(w));
        for (long long i=0; i<h; i++){
            for(long long j=0; j<w; j++){
                cin>>stones[i][j];
            }
        }
        for (long long i=0;i<w;i++){
            maxstones[0][i]=stones[0][i];
        }
        for (long long i=1;i<h;i++){
            for(long long j=0; j<w;j++){
                if (j==0){
                    maxstones[i][j]=max(maxstones[i-1][j],maxstones[i-1][j+1])+stones[i][j];
                }
                else if (j==(w-1)){
                    maxstones[i][j]=max(maxstones[i-1][j],maxstones[i-1][j-1])+stones[i][j];
                }
                else{
                    maxstones[i][j]=maximo(maxstones[i-1][j],maxstones[i-1][j-1],maxstones[i-1][j+1])+stones[i][j];
                }
                }
        }
        long long numax=0;
        for (long long i=0;i<w;i++){
            if(numax<maxstones[h-1][i]){
                numax=maxstones[h-1][i];
            }

        }
        test[test.size()-t]=numax;


    t--;
    }
    for(long long i=0; i<test.size();i++){
        cout<<test[i]<<endl;
    }

    return 0;
}