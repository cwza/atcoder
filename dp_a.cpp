#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

int n;
vector<int> inp;
vector<int> dp;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    cin >> n;
    inp.resize(n);
    dp.resize(n);
    for(int i = 0; i < n; ++i) cin >> inp[i];

    dp[n-2] = abs(inp[n-1]-inp[n-2]);

    for(int i = n-3; i >= 0; --i) {
        dp[i] = min(dp[i+1]+abs(inp[i]-inp[i+1]), dp[i+2]+abs(inp[i]-inp[i+2]));
    }
    cout << dp[0];
}