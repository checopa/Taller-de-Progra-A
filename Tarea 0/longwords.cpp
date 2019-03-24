#include "iostream"
#include "string"

using namespace std;

int main(){
	int i;
	cin >> i;
	cin.ignore();
	string str[i];
	for(int j=0;j<i;j++){
		getline(cin,str[j]);
	}
	for(int j=0;j<i;j++){
		int size=str[j].size();
		int newsize=size-2;
		if(size<=10){
			cout<<str[j]<<endl;
		}

		else{
		cout<<str[j][0]+to_string(newsize)+str[j][size-1]<<endl;
		}
	}
}
