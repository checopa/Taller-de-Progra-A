#include "iostream"


using namespace std;

int main(){
	int i,k,cp=0,cs=0,cm=0,min;
	cin >> i;
	int p[i],m[i],s[i];
	for (int j=0;j<i;j++){
		cin>>k;
		if(k==1){
			p[cp]=j+1;
			cp++;		
		}
		else{
			if(k==2){
				m[cm]=j+1;
				cm++;
			}
			else{
				s[cs]=j+1;
				cs++;
			}
		}
	}
	if (cs<cm){
		min=cs;
	}
	else{
		min=cm;
	}
	if (cp<min){
		min=cp;
	}
	if (min==0){
		cout<<min<<endl;
	}
	else{
		cout << min << endl;
		for (int j=0;j<min;j++){
			cout<<p[j]<<" "<<m[j]<<" "<<s[j]<<endl;
		}
	}
}

