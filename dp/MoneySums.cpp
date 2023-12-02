#include <bits/stdc++.h>

using namespace std;

int main(){

    int n; cin >> n;

    vector<int> coins(n);
    int total = 0;
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
        total += coins[i];
    }

    map<int,int> mp;
    vector<vector<int>> dp(total+1,vector<int>(n+1,0));
    
    for(int i = 0; i < n; i++) dp[0][i] = 1;
    dp[coins[0]][0] = 1;
    mp[coins[0]] = 1;
    for(int sum = 1; sum <= total; sum++){
        for(int i = 1; i < n; i++){
            dp[sum][i] = dp[sum][i-1];
            if(0 <= sum-coins[i]) dp[sum][i] |= dp[sum-coins[i]][i-1];
        
            if(dp[sum][i]) mp[sum] = 1;
        }
        
    }
    
    
    // MoneySums(0,0,coins,dp);

    cout << mp.size() << endl;

    for(auto it = mp.begin(); it != mp.end(); it++){
        cout << it->first << " ";
    }
    cout << endl;

}