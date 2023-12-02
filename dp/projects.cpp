#include <bits/stdc++.h>
 
using namespace std;
 
long long int MaxAmount(int ind, int prev_end, vector<long long int> start, vector<long long int> end, vector<long long int> amount, vector<vector<long long int>> &dp){
 
    int n = start.size();
 
    if(ind == n) return 0;
 
    long long int ans = 0;
 
    if(dp[ind][prev_end] != -1) return dp[ind][prev_end];
 
    if(prev_end == n){
        ans = max(ans, MaxAmount(ind+1,ind,start,end,amount,dp)+amount[ind]);
    }
    else if(start[ind] > end[prev_end]){
        // take
        ans = max(ans, MaxAmount(ind+1,ind,start,end,amount,dp)+amount[ind]);
    }
    // not take
    ans = max(ans,MaxAmount(ind+1,prev_end,start,end,amount,dp));
 
    return dp[ind][prev_end] = ans;
}
 
int main(){
 
    int n; cin >> n;
 
    vector<long long int> start(n);
    vector<long long int> end(n);
    vector<long long int> amount(n);
 
    
    vector<pair<long long int, int>> pp(n);
 
    for(int i = 0; i < n; i++){
        cin >> start[i] >> end[i] >> amount[i];
        pp[i].first = start[i];
        pp[i].second = i;
    }
 
    sort(pp.begin(), pp.end());
 
    vector<long long int> temp(n);
 
    for(int i = 0; i < n; i++){
        temp[i] = start[pp[i].second];
    }
    start = temp;
 
    for(int i = 0; i < n; i++){
        temp[i] = end[pp[i].second];
    }
    end = temp;
 
    for(int i = 0; i < n; i++){
        temp[i] = amount[pp[i].second];
    }
    amount = temp;
 
    // sort based on end
 
    vector<vector<long long int>> dp(n, vector<long long int>(n+1,-1));
 
    cout << MaxAmount(0,n,start,end,amount,dp) << endl;
}