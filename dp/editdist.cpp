#include <bits/stdc++.h>

using namespace std;

int EditDistance(int ptr1, string s1, int ptr2, string s2, vector<vector<int>> &dp){

    if(ptr1 == (int)s1.size()) return s2.size()-ptr2;
    if(ptr2 == (int)s2.size()) return s1.size()-ptr1;
    
    if(dp[ptr1][ptr2] != -1) return dp[ptr1][ptr2];
    
    int ans = s1.size()+s2.size();

    if(s1[ptr1] == s2[ptr2]){
       ans = min(ans, EditDistance(ptr1+1,s1,ptr2+1,s2,dp));
       return dp[ptr1][ptr2] = ans;
    }
    // Insert
    ans = min(ans, EditDistance(ptr1,s1,ptr2+1,s2,dp)+1);

    // Remove
    ans = min(ans, EditDistance(ptr1+1,s1,ptr2,s2,dp)+1);

    // Replace
    ans = min(ans, EditDistance(ptr1+1,s1,ptr2+1,s2,dp)+1);

    return dp[ptr1][ptr2] = ans;
}
int main(){

    string s1; cin >> s1;
    string s2; cin >> s2;

    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,n+m));
    // cout << EditDistance(0,s1,0,s2,dp) << endl;

    for(int i = 0; i <= m; i++){
        dp[n][i] = m-i;
    }

    for(int i = 0; i <= n; i++){
        dp[i][m] = n-i;
    }

    for(int ptr1 = n-1; 0 <= ptr1; ptr1--){
        for(int ptr2 = m-1; 0 <= ptr2; ptr2--){

        if(s1[ptr1] == s2[ptr2]){
            dp[ptr1][ptr2] = min(dp[ptr1][ptr2], dp[ptr1+1][ptr2+1]);
         }
        else{
            // Insert
            dp[ptr1][ptr2] = min(dp[ptr1][ptr2], dp[ptr1][ptr2+1]+1);

            // Remove
            dp[ptr1][ptr2] = min(dp[ptr1][ptr2], dp[ptr1+1][ptr2]+1);

            // Replace
            dp[ptr1][ptr2] = min(dp[ptr1][ptr2], dp[ptr1+1][ptr2+1]+1);
         }
            
        }
    }

    cout << dp[0][0] << endl;

}