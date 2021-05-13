#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

int n, k;
vector<int> inp;
vector<int> dp;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    cin >> n >> k;
    inp.resize(n);
    dp.resize(n);
    for(int i = 0; i < n; ++i) cin >> inp[i];
    dp[n-2] = abs(inp[n-1]-inp[n-2]);

    for(int i = n-3; i >= 0; --i) {
        dp[i] = 2e9;
        for(int j = i+1; j < n && j-i <= k; ++j) {
            dp[i] = min(dp[i], dp[j]+abs(inp[i]-inp[j]));
        }
    }
    cout << dp[0];
}