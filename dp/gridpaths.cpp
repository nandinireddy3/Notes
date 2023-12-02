#include <bits/stdc++.h>

using namespace std;

const int mod = (int)1e9+7;
int Paths(int i,int j,vector<vector<char>> matrix, vector<vector<int>> &dp){

    int n = matrix.size();
    if((0 > i) || (i >= n) || (0 > j) || (j >= n)) return 0;
    if(matrix[i][j] == '*') return 0;
    if((i == n-1) && (j == n-1)) return 1;

    if(dp[i][j] != -1) return dp[i][j];
    int ans = 0;

    ans += (Paths(i+1,j,matrix,dp)%mod)+(Paths(i,j+1,matrix,dp)%mod)%mod;

    return dp[i][j] = ans;
}
int main(){

    int n; cin >> n;
    vector<vector<char>> matrix(n,vector<char>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }

    vector<vector<int>> dp(n,vector<int>(n,0));
    dp[0][0] = (matrix[0][0] != '*')?1:0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] != '*'){
            if((i > 0)) dp[i][j] =(dp[i][j] + dp[i-1][j]);
            if((j > 0)) dp[i][j] =(dp[i][j] + dp[i][j-1]);
            
            dp[i][j] %= mod;
            }
            
        }
    }

    cout << dp[n-1][n-1] << endl;
    return 0;
}