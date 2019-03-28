#include "iostream"
#include "math.h"
#include "vector"
using namespace std;

float fact(int n){
	if (n==1)
		return log(1);
	else
		return log(n)+fact(n-1);
}
float potencia(int base, int exponente){
	return exponente*log(base);
}

int bb(int base){
	int fin=200;
	int inicial=0;
	int centro;
	while(inicial<fin){
		centro=(inicial+fin)/2;
		if (fact(centro)>potencia(base,centro)){
			fin=centro;}
		else
			inicial=centro+1;
	}	
	return inicial;
}

int main(){
	int i;
	cin >> i;
	vector<int> vec(i);
	for (int j=0;j<i;j++){
		cin >> vec[j];
	}
	for(int j=0;j<i;j++){
		cout<< bb(vec[j]) <<endl;
	}
return 0;}
