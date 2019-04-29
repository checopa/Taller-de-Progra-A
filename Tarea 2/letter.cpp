#include "iostream"
#include "string"
#include "vector"
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.size();
    vector<vector<int> > matrix(n,vector<int>(2));
    if(islower(s[0])){
        matrix[0][0]=0;
        matrix[0][1]=1;
    }
    else{
        matrix[0][0]=1;
        matrix[0][1]=0;
    }
    for(int i=1;i<n;i++){
        if(islower(s[i])){
            matrix[i][0]=min(matrix[i-1][0],matrix[i-1][1]);
            matrix[i][1]=matrix[i-1][1]+1;
        }
        else{
            matrix[i][0]=min(matrix[i-1][0],matrix[i-1][1])+1;
            matrix[i][1]=matrix[i-1][1]; 
        }
    }

    cout<<min(matrix[n-1][0],matrix[n-1][1])<<endl;
    return 0;
}
