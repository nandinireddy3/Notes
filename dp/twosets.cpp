#include <bits/stdc++.h>

using namespace std;

const int mod = (int)1e9+7;
int inv(int b){
    int ans = 1;
    int i = mod-2;
    while(i--){
        ans *= b;
        ans %= mod; 
    }
    return ans;
}

long long int twosets(int ind, int sum,int n, vector<vector<long long int>> &dp){

    if(sum == 0) return 1;
    if(ind == -1) return 0;

    if(dp[ind][sum] != -1) return dp[ind][sum];
    long long int ans = 0;

    ans = twosets(ind-1,sum,n,dp);

    if(0 <= sum-(ind+1)){
       ans += twosets(ind-1,sum-(ind+1),n,dp);
    }
    ans = ans%mod;

    return dp[ind][sum] = ans;
}

int main(){

    int n; cin >> n;
    
    int sum = (n*(n+1))/2;

    if(sum%2 != 0) {
        cout << 0 << endl;
        return 0;
    }
    else sum = sum/2;
    
    int in = (int)500000004;
    vector<vector<long long int>> dp(n,vector<long long int>(sum+1,-1));
    cout << twosets(n-1,sum,n,dp)%mod*in%mod << endl;
}