#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int maxN = 1e5;
int n;
int inps[maxN+1][3];
ll dp[maxN+1][3];

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < 3; ++j) cin >> inps[i][j];
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < 3; ++j) {
            if(j==0) dp[i][j] = inps[i][0] + max(dp[i-1][1], dp[i-1][2]);
            if(j==1) dp[i][j] = inps[i][1] + max(dp[i-1][0], dp[i-1][2]);
            if(j==2) dp[i][j] = inps[i][2] + max(dp[i-1][0], dp[i-1][1]);
        }
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2]});
}