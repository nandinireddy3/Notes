#include <bits/stdc++.h>

using namespace std;

// f(i,w) -> max(f(i+1,w),f(i+1,j-wi)+vi);

int maxPages(int ind, int wgt, vector<int> prices,vector<int> pages,vector<vector<int>> &dp){

    if(ind == pages.size()){
        return 0;
    }

    if(dp[ind][wgt] != -1) return dp[ind][wgt];
    int ans = 0;

    ans = max(ans,maxPages(ind+1,wgt,prices,pages,dp));
    if(prices[ind] <= wgt){
        ans = max(ans,maxPages(ind+1,wgt-prices[ind],prices,pages,dp)+pages[ind]);
    }

    return dp[ind][wgt]=ans;
}

int main(){
    int n,x;
    cin >> n >> x;

    vector<int> prices(n);
    vector<int> pages(n);
    for(int i = 0; i < n; i++){
        cin>> prices[i];
    }
    for(int i = 0; i < n; i++){
        cin>> pages[i];
    }

    vector<vector<int>> dp(n,vector<int>(x+1,-1)); // ind,wts

    for(int i = 0; i <= x; i++){
        if(prices[0] <= i) dp[0][i] = pages[0];
        else{
            dp[0][i] = 0;
        }
    }

    for(int i = 0; i < n; i++) dp[i][0] = 0;

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= x; j++){
            dp[i][j] = max(dp[i][j],dp[i-1][j]);
            if(prices[i] <= j) dp[i][j] = max(dp[i][j],dp[i-1][j-prices[i]]+pages[i]);
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j <= x; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[n-1][x] << endl;
}