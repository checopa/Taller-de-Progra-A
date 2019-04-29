#include "iostream"
#include "vector"
#include "string"

using namespace std;

int main(){
    string n,n1,n2,n3;
    int largo,valor;
    cin>>n;
    largo=n.size();
    n1=n[largo-2];
    n2=n[largo-1];
    n3=n1+n2;
    valor=stoi(n3);
    if (valor%4==0){
        cout<<4<<endl;
    }
    else{
        cout<<0<<endl;
    }
    return 0;
}
