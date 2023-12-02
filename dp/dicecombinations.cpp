// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;
long long int mod = 1e9+7;
long long int NoOfWays(int n, vector<long long int> &dp){
    if(n == 1 || n == 0) return 1;
    
    if(dp[n] != -1) return dp[n];
    long long int ans = 0;
    for(int i = 1; i <= 6; i++){
        if(i <= n){
            ans += NoOfWays(n-i,dp)%mod;
        }
    }
    return dp[n] = ans%mod;
}

int main() {
    // Write C++ code here
    int n; cin >> n;
    vector<long long int> dp(n+1,-1);
    
    cout << NoOfWays(n,dp)%mod << endl;
    return 0;
}