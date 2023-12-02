#include <bits/stdc++.h>

using namespace std;

const int mod = (int)1e9+7;
int NoOfArrays(int ind, int prev, vector<int> &A, int m, vector<vector<int>> &dp){

    int n = A.size();
    if(ind == n) return 1;

    if(dp[prev][ind] != -1) return dp[prev][ind];
    int ans = 0;

    if((ind == 0) && (A[ind] == 0)){
        
        for(int i = 1; i <= m; i++){
            // A[ind] = i;
            ans += NoOfArrays(ind+1,i,A,m,dp);
            ans %= mod;
            
        }
    }
    else if(A[ind] == 0){
        for(int i = -1; i <= 1; i++){
            if((1 <= prev+i) && (prev+i <= m)){
                // A[ind] = prev+i;
                ans += NoOfArrays(ind+1,prev+i,A,m,dp);
                ans %= mod;
            }
        }
    }
    else{
        if(abs(prev-A[ind]) > 1){
            ans =  0;
        }
        else ans = NoOfArrays(ind+1,A[ind],A,m,dp);
        
    }
    
    return dp[prev][ind] = ans;
}

int main(){

    int n,m;
    cin >> n >> m;
    vector<int> A(n);

    for(int i = 0; i < n; i++) cin >> A[i];

    vector<vector<int>> dp(m+2,vector<int>(n,-1));

    cout << NoOfArrays(0,A[0],A,m,dp) << endl;

    return 0;
}