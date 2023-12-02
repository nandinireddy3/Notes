#include <bits/stdc++.h>

using namespace std;

int main(){

    int n; cin >> n;

    // int k = n;
    // int ans = 0;
    
    // while(k){
    //     string no = to_string(k);
    //     int size = no.size();
    //     int M = 0;
    //     for(int i = 0; i < size; i++){
    //         M = max(M,no[i]-'0');
    //     }

    //     k -= M;
    //     ans++;
    // }
    // cout << ans << endl;
    int dp[n+1];
    memset(dp,9999,sizeof(dp));
    dp[0] = 0;
    for(int i = 1; i <= n ; i++){
        string s = to_string(i);

        for(auto c:s){
            dp[i] = min(dp[i],dp[i-(c-'0')]+1);
        }
    }

    cout << dp[n] << endl;
    return 0;
}