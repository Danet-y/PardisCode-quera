#pragma optimize("O3")
#include <bits/stdc++.h>
#define int long long int 
#define dint long double
#define endl "\n"
#define pii pair<int, int>
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
 
using namespace std;
typedef long long ll;
typedef long double ld;

 
const int MAXN = (int)1e6 + 7;
const int MOD = (int)1e9 + 7;
const int INF = (int)1e18 + 7;

int POW(int x, int y) {
    return (!y ? 1 : (y & 1 ? x * POW(x * x, y / 2) : POW(x * x, y / 2)));
}

 
int n, m, tmp, tmp2, tmp3, c, t, k, ans, flag, a, b, cnt2, cmp, cmp2, mid, v, w, u;
int arr[MAXN], kol[MAXN], ps[MAXN], arr2[MAXN];
string s;
map<char, int> sar, tah;

void solve() {
    cin >> n;

    sar.clear();
    tah.clear();

    ans = 0;

    for (int i=1; i<=n; i++) {
        cin >> s;
        ans += s.size();
        
        sar[s[0]]++;
        if (s.size() != 1) {
            tah[s.back()]++;
        }
    }

    for (auto ch='a'; ch<='z'; ch++) {
        ans -= min(sar[ch], tah[ch]);
    }

    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) solve();


 
    return 0;
}

//ShayanSh
