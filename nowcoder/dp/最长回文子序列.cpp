#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s;
    cin>>s;

    int n = s.size();

    vector<vector<int> >  dp(n+1,vector<int> (n+1));

// dp[i][j] = dp[i+1][j-1]+2
// dp[i][j] = dp[i+1][j],dp[i][j-1]
    for(int i=n-1;i>=0;i--) {
        dp[i][i] =1;
        for(int j=i+1;j<n;j++) {
            if(s[i] == s[j]) {
                dp[i][j] = dp[i+1][j-1]+2;
            }else {
                dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
    }
    cout << dp[0][n-1]<<endl;
    
    return 0;
}

