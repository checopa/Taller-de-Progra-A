#include "iostream"

using namespace std;

int main(){
	int i,j,res;
	cin >> i >>j;
	for (int h=1;h<11;h++){
		res=i*h;
		if(res%10==0 || res%10==j){
			cout<< h << endl;
			break;
	}
	}
}
