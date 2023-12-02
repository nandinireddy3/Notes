#include <bits/stdc++.h>

using namespace std;

int minimalCoins(int sum, vector<int> c, vector<int> &dp){

    if(sum < 0) return 1000001;
    if(sum == 0) return 0;

    if(dp[sum] != -1) return dp[sum];

    int n = c.size();
    int ans = 1000001;
    for(int i = 0; i < n; i++){
        if(c[i] <= sum)
        ans = min(ans,minimalCoins(sum-c[i],c,dp)+1);
        else break;
    }

    return dp[sum] = ans;
}

int main(){

    int n; cin >> n;
    int x; cin >> x;

    vector<int> c(n);

    for(int i  = 0; i < n; i++) cin >> c[i];

    sort(c.begin(),c.end());
    vector<int> dp(x+1,1000001);

    dp[0] = 0;
    for(int sum = 1; sum <= x; sum++){
        for(int i = 0; i < n; i++){
            if(c[i] <= sum){
                dp[sum] = min(dp[sum],dp[sum-c[i]]+1);
            }
            else break;
        }
    }
    // int ans = minimalCoins(x,c,dp);
    dp[x] = (dp[x] != 1000001)?dp[x]:-1;
    cout << dp[x] << endl;

    return 0;
}