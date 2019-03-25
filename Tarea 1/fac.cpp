#include "iostream"
#include "math.h"
#include "vector"
using namespace std;

long long fact(int n){
	if (n==0)
		return 1;
	else
		return n*fact(n-1);
}

int bb(int base){
	int fin=19;
	int inicial=0;
	int centro;
	while(inicial<fin){
		centro=(inicial+fin)/2;
		cout<<centro<<endl;
		if (fact(centro)>pow(base,centro))
			fin=centro;
		else
			inicial=centro+1;
	}	
	return inicial;
}

int main(){
	int i,num;
	cin >> i;
	vector<int> vec(i);
	for (int j=0;j<i;j++){
		cin >> num;
		cout<< bb(num)<<endl;
	}
return 0;}
