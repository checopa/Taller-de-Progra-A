#include "iostream"
#include "vector"

using namespace std;

int main(){
    vector<long long> cant(100005);
    vector<long long> dp(100005);
    long long num,n;
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>num;
        cant[num]++;
    }
    dp[0]=0;
    dp[1]=cant[1];
    for(long long i=2;i<100001;i++){
        dp[i]=max(dp[i-1],dp[i-2]+i*cant[i]);
    }
    cout<<dp[100000]<<endl;
    return 0;
}
