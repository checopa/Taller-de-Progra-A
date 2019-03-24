#include "iostream"

using namespace std;

int main(){
	int i,h;
	cin >> i >>h;
	int numeros[i];
	int k=0;
	for(int j=0;j<i;j++){
		cin >> numeros[j];
		if (numeros[j]>h){
			k+=2;		
		}
		else{
			k+=1;		
		}
	}
	cout << k <<endl;
}
