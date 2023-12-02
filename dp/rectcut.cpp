#include <bits/stdc++.h>

using namespace std;

int rectangleCut(int w, int h, vector<vector<int>> &dp){

    if(w == h) return 0;

    if(dp[w][h] != -1) return dp[w][h];
    int ans = h+w;
    
    // if(w < h){
    //     ans = rectangleCut(w,h-w)+1;
    // }
    // else if(h < w){
    //     ans = rectangleCut(w-h,h)+1;
    // }

    for(int i = 1; i < w; i++){
        ans = min(ans,rectangleCut(i,h,dp)+rectangleCut(w-i,h,dp)+1);
    }
    for(int i = 1; i < h; i++){
        ans = min(ans,rectangleCut(w,i,dp)+rectangleCut(w,h-i,dp)+1);
    }
    

    return dp[w][h] = ans;
}

int main(){

    int w; cin >> w;
    int h; cin >> h;

    vector<vector<int>> dp(w+1,vector<int>(h+1,h+w));

    for(int i = 1; i <= min(w,h); i++){
        dp[i][i] = 0;
    }

    for(int k = 1; k <= w; k++){
        for(int j = 1; j <= h; j++){
            if(k != j){
                for(int i = 1; i < k; i++){
                    dp[k][j] = min(dp[k][j],dp[i][j]+dp[k-i][j]+1);
                }
                for(int i = 1; i < j; i++){
                    dp[k][j] = min(dp[k][j],dp[k][i]+dp[k][j-i]+1);
                }
            }
        }
    }


    cout << dp[w][h] <<endl;
}