#include "iostream"
#include "vector"

using namespace std;

int bb(vector<int> vec, int obj){
	int fin=vec.size()-1;
	int inicial=0;
	int centro;
	while(inicial<fin){
		centro=(inicial+fin)/2;
		if (vec[centro]<obj)
			inicial=centro+1;
		else
			fin=centro;
	}	
	if (vec[inicial]==obj)
		return inicial;
	else
		return -1;
}

int main(){
	int i,j,buscar;
	cin >> i >> j;
	vector<int> arreglo(i);
	vector<int> num(j);
	for (int cont=0; cont<i;cont++)
		cin>>arreglo[cont];
	for (int cont=0;cont<j;cont++){
		cin>>buscar;
		num[cont]=bb(arreglo,buscar);}
	for (int cont=0;cont<j;cont++)
		cout << num[cont]<<endl;
	return 0;
}
