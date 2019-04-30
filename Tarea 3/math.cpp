#include "iostream"
#include "math.h"
#include "map"

using namespace std;

int main(){
	int n,k=2,max=0,num=1,cant;
	cin>>n;
	map<int,int> rep;
	while(n>1){
                while(n%k==0){
 			rep[k]++;
          		n/=k;
    		}
            k++;
	}	
	int valor,primo=0,unico=0;	
	for(auto kv:rep){
	num*=kv.first;
	valor=kv.second;
	if(valor>max){
		max=valor;
	}
	if(valor>1){
		primo=1;	
	}
	if(max!=kv.second){
		unico=1;
	}
	}
	cant=ceil(log2(max))+1;
	cout<<num<<endl;
	if (primo==1 && unico==1){
		cout<<cant<<endl;
	}
	else{
		if(unico==1){
			cout<<0<<endl;
		}
		else{
			cout<<log2(max)<<endl;
		}	
	}
	return 0;
}
