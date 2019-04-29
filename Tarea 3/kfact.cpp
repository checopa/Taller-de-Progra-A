#include "iostream"
#include "vector"

using namespace std;

int main(){
    vector<long long> p;
    long long n,k,i=2,resto=1,largo;
    cin>>n>>k;
    while(n>1){
        while(n%i==0){
            n/=i;
            p.push_back(i);
        }
        i++;
    }
    largo=p.size();
    if(largo<k){
        cout<<-1<<endl;
    }
    else{
    for(long long j=0;j<largo;j++){
        if(j<(k-1)){
            cout<<p[j]<<endl;
        }
        else{
            resto*=p[j];
        }
    }
    cout<<resto<<endl;
    }
    return 0;
}
