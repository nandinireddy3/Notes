#include <bits/stdc++.h>

using namespace std;

int LIS(int ind, vector<int> arr, int &val, vector<int> &dp){

    if(ind == 0) return 1;

    if(dp[ind] != -1){ 
        val = max(val,dp[ind]);
        return dp[ind];
    }
    int ans = 1;
    for(int i = 0; i < ind; i++){
        if(arr[i] < arr[ind]){
            ans = max(ans,LIS(i,arr,val,dp)+1);
        }
    }

    val = max(val,ans);
    return ans;
}

int main(){

    int n; cin >> n;
    vector<long long int> arr(n);

    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<int> dp(n+1,1);
    // LIS(n-1,arr,val,dp);

    // cout << val << endl;
    int ans = 1;
    for(int i = 0; i < n; i++){
        // for(int j = 0; j < i; j++){
        //     if((arr[j] < arr[i]) && (dp[j]+1 > dp[i])){
        //         dp[i] = dp[j]+1;
        //     }
        // }
        
        ans = max(ans,dp[i]);
    }
    cout << ans << endl;
}