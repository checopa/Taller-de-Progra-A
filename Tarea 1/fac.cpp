#include "iostream"
#include "math.h"
#include "vector"
using namespace std;


float potencia(int base, int exponente){
	return exponente*log(base);
}

int bb(int base,vector<float> logs){
	int fin=100000;
	int inicial=0;
	int centro;
	while(inicial<fin){
		centro=(inicial+fin)/2;
		if (logs[centro]>potencia(base,centro)){
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
	vector<float> sumlog(100000);
	sumlog[0]=0;
	for (int i=1;i<100000;i++){
		sumlog[i]=log(i)+sumlog[i-1];
	}
	for (int j=0;j<i;j++){
		cin >> vec[j];
	}
	for(int j=0;j<i;j++){
		cout<< bb(vec[j],sumlog) <<endl;
	}
	return 0;
}
