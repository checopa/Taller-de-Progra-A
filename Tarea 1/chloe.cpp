#include "iostream"
#include "vector"
#include "string"
using namespace std;

string secuencia(int n){
	vector<string> vec;
	vec.push_back("1");
	for(int i=0;i<(n-1);i++){
		string valor=to_string(i+2);
		vec.push_back(vec[i]+valor+vec[i]);
	}
	return vec[vec.size()-1];
}

int main(){
	int i,j;
	cin >> i >> j;
	string hola=secuencia(i);
	cout << hola[j-1] <<endl;
	return 0;
}
