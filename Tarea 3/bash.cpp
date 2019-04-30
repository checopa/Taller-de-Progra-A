#include "iostream"
#include "vector"
#include "map"

using namespace std;

int main(){
    int n,j,k;
    map<int,int> rep;
    vector<int> cant;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>j;
        cant.push_back(j);
    }
    for (int i=0;i<n;i++){
        j=cant[i];
        k=2;
        while(j>1){
            if(j%k==0){
                map<int,int>::iterator it=rep.find(k);
                if(it!=rep.end()){
                    it->second+=1;
                }
                else{
                    rep.insert({k,1});
                }
                while(n%i==0){
                    n/=i;
            }
            }
            k++;
        }
    }
    int max=0;
    map<int,int>::iterator p = rep.begin();
    while (p != rep.end() ){
        if(p->second>max){
            max=p->second;
        }
        p++;
    }
    cout<<max<<endl;
    return 0;
}
