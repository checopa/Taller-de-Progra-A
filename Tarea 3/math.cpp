#include "iostream"
#include "math.h"
#include "map"

using namespace std;

int main(){
	int n,k=2,max=0,num=1,cant;
	cin>>n;
	if (n==1){
		cout<<1<<endl;
		cout<<0<<endl;
		return 0;		
	}
	map<int,int> rep;
	while(n>1){
                while(n%k==0){
 			rep[k]++;
          		n/=k;
    		}
            k++;
	}	
	int valor,primo=0;	
	for(auto kv:rep){
		num*=kv.first;
		valor=kv.second;
		if(valor>max){
			max=valor;
		}
	}
	for(auto kv:rep){
		if(kv.second!=max){
			primo=1;
		}	
	}
	cout<<num<<endl;
	if(primo==0 && log2(max)==(int)log2(max)){
		cout<<log2(max)<<endl;
	}
	else{
		cant=ceil(log2(max))+1;
		cout<<cant<<endl;
	}
	return 0;
}
