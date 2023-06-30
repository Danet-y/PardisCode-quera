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
vector<int> A, B, C;


inline int countA(int k) {return (upper_bound(all(A), k)-lower_bound(all(A), k));}
inline int countB(int k) {return (upper_bound(all(B), k)-lower_bound(all(B), k));}
inline int countC(int k) {return (upper_bound(all(C), k)-lower_bound(all(C), k));}


int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i=1; i<=n; i++) {
        cin >> tmp >> u;

        if (tmp == 1) {
            A.pb(u);
        } else if (tmp == 2) {
            B.pb(u);
        } else {
            C.pb(u);
        }
    }

    sort(all(A));
    sort(all(B));
    sort(all(C));

    int moto=0;

    for (int i=0; i<B.size(); i++) {
        moto += C.size()-countC(B[i]);
    }

    ans = 0;

    for (int i=0; i<A.size(); i++) {
        ans += moto-(countB(A[i])*(C.size()-countC(A[i])))-(countC(A[i])*(B.size()-countB(A[i])));
    }

    cout << ans;
    return 0;
}
//ShayanSh
