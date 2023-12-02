#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int maxLCS(string lotteryID, string winnerID, int k) {
    int m = lotteryID.length();
    int n = winnerID.length();
    
    // Create a 3D DP array dp where dp[i][j][k] represents the LCS length
    // between the first i characters of lotteryID and the first j characters of winnerID
    // after using at most k operations.
    vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(k+1, 0)));
    
    // Fill in the DP array
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int ops = 0; ops <= k; ops++) {
                if (lotteryID[i-1] == winnerID[j-1]) {
                    // Characters match, so increase LCS length
                    dp[i][j][ops] = dp[i-1][j-1][ops-1] + 1;
                } else {
                    // Characters don't match, try both directions for operations
                    dp[i][j][ops] = max(dp[i-1][j][ops], dp[i][j-1][ops]);
                    if (ops-(abs(lotteryID[i-1]-winnerID[j-1])%26) >= 0) {
                        // lID[] = pr or next
                        // if(equal)
                        dp[i][j][ops] = max(dp[i][j][ops], dp[i-1][j-1][ops-(abs(lotteryID[i-1]-winnerID[j-1])%26)] + 1);
                        // else
                    }
                }
                // cout << i << ": " << j << ": " << ops << "k: " << dp[i][j][ops] << endl;
            }
        }
    }
    
    // The answer is stored in dp[m][n][k]
    return dp[m][n][k];
}

int main() {
    string lotteryID, winnerID;
    int k;
    
    cout << "Enter lottery ID: ";
    cin >> lotteryID;
    
    cout << "Enter winner ID: ";
    cin >> winnerID;
    
    cout << "Enter maximum number of operations (k): ";
    cin >> k;
    
    int result = maxLCS(lotteryID, winnerID, k);
    cout << "Maximum LCS length after at most " << k << " operations: " << result << endl;
    
    return 0;
}
