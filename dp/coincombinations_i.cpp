#include <bits/stdc++.h>

using namespace std;

const int mod = (int)1e9 + 7;

long long int coincombs(int sum, vector<int> c, vector<long long int> &dp){

    if(sum == 0) return 1;

    if(dp[sum] != -1) return dp[sum];
    int n = c.size();
    long long int ans = 0;
    for(int i = 0; i < n; i++){

        if(c[i] <= sum) {
            ans += coincombs(sum-c[i],c,dp)%mod;
        }
        else{
            break;
        }
    }

    return dp[sum] = ans%mod;
}
int main(){

    int n; cin >> n;
    int x; cin >> x;

    vector<int> c(n);

    for(int i  = 0; i < n; i++) cin >> c[i];

    sort(c.begin(),c.end());

    // vector<long long int> dp(x+1,-1);

    vector<long long int> dp(x+1,0);

    dp[0] = 1;
    for(int sum = 1; sum <= x; sum++){
        for(int i = 0; i < n; i++){

            if(c[i] <= sum) {
                dp[sum] += dp[sum-c[i]];
                dp[sum] %= mod;
            }
            // else{
            //     break;
            // }
    }
    }

    cout << dp[x] << endl;

}