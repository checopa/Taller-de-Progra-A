#include<iostream>


using namespace std;
int potencia(int base,int exponente){
	if (exponente==0){
		return 1;}
	else
		return base*potencia(base,exponente-1);
}

int main(){
	int n,k;
	int p;
	cin>>n>>k;
	while(n){
	p=potencia(2,n-1);
	if(k>p){
		k=k%p;}
	if(k==p){
		cout<<n<<endl;
		break;}
	n--;
	}
	return 0;	

}



