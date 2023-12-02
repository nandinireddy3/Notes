

// 9
// -2 , -3, -5
// -2, (-2,-3), (-2,-3,-5)

#include <bits/stdc++.h>

using namespace std;

const int mod = (int)1e9+7;

int CoinCombinations(int prev, int sum, vector<int> c, vector<vector<int>> &dp){

    if(sum == 0) return 1;

    if(dp[prev][sum] != -1) return dp[prev][sum];
    int ans = 0;
    int n = c.size();    
    for(int i = 0; i < n; i++){
        if((c[i] <= c[prev]) && (c[i] <= sum)){
            ans += CoinCombinations(i,sum-c[i],c,dp);
            ans %= mod;
        }
    }
    return dp[prev][sum] = ans%mod;
}
int main(){

    int n; cin >> n;
    int x; cin >> x;

    vector<int> c(n);

    for(int i  = 0; i < n; i++) cin >> c[i];

    sort(c.begin(),c.end());

    vector<vector<int>> dp(2,vector<int>(x+1,0));
    
    for(int i = 0; i < 2; i++){
        dp[i][0] = 1;
    }

    for(int k = 0; k < n; k++){
        for(int j = 1; j <= x; j++){
            if(k == 0 && c[k] <= j){
                dp[0][j] += dp[0][j-c[k]];
                dp[0][j] %= mod;
            }
            else{
                dp[1][j] += dp[0][j];
                dp[1][j] %= mod;
                if(c[k] <= j){
                    dp[1][j] += dp[1][j-c[k]];
                    dp[1][j] %= mod;
                }
                dp[0] = dp[1];
            }

         }
        
                
    }


    cout << dp[1][x] << endl;

    return 0;
}