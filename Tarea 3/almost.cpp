#include "iostream"
#include "vector"

using namespace std;

bool check(int n){
    vector<int> p;
    int i=2,cont=0;
    while(n>1){
        if(n%i==0){
            cont++;
            while(n%i==0){
                n/=i;
                p.push_back(i);
        }
        }
        i++;
        if(cont>2){
            break;
        }
    }
    return cont==2;
}
int main(){
    int n,cant=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        if (check(i)){
            cant++;
        }
    }
    cout<<cant<<endl;
    return 0;
}