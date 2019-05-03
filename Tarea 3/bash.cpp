#include "iostream"
#include "vector"
#include "map"

using namespace std;

int main(){
	int n,j,k,aux;
	map<int,int> rep;
	vector<int> cant(100001);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>j;
		cant[j]++;
	}
	for (int i=1;i<100001;i++){
		j=cant[i];
		if(j==0){
			continue;		
		}
		aux=i;
		k=2;
		if(i==1){
			rep[1]++;;
		}
		while(aux>1){
		    if(aux%k==0){
			rep[k]+=cant[i];
			while(aux%k==0){
			    aux/=k;
		    }
		    }
		    k++;
		}
	}
	int max=0;
	for(auto kv:rep){
		if(kv.second>max){
			max=kv.second;
		}	
	}
	cout<<max<<endl;
	return 0;
}
