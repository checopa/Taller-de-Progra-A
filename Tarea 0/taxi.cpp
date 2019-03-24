#include "iostream"

using namespace std;

int main(){
	int i;
	cin >> i;
	int numeros[i];
	int k=0;
	for(int j=0;j<i;j++){
		cin >> numeros[j];
		k+=numeros[j];
		
	}
	if (k%4!=0){
		cout<< ((k/4)+1) << endl;	
	}
	else{
		cout<<(k/4)<<endl;
	}
}
