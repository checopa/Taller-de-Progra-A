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
    return inicial;
}

int main(){
    int i,j,num,buscar;
    cin>>i;
    vector<int> worms(i+1);
    for(int k=1;k<=i;k++){
        cin>>num;
        worms[k]=worms[k-1]+num;
    }
    cin>>j;
    vector<int> juicy(j);
    for(int k=0;k<j;k++){
        cin>>buscar;
        juicy[k]=bb(worms,buscar);
    }
    for (int k=0;k<j;k++)
		cout << juicy[k]<<endl;
	return 0;
    
    
}
