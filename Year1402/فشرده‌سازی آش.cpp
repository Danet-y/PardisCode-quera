// In the name of Allah

#include <bits/stdc++.h>
using namespace std;

typedef long long int	ll;
typedef long double	ld;
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;

#define all(x)		(x).begin(),(x).end()
#define len(x)		((ll) (x).size())
#define F		first
#define S		second
#define pb		push_back
#define sep             ' '
#define endl            '\n'
#define Mp		make_pair
#define debug(x)	cerr << #x << ": " <<  x << endl;
#define kill(x)		cout << x << '\n', exit(0)
#define set_dec(x)	cout << fixed << setprecision(x);
#define file_io(x,y)	freopen(x, "r", stdin); freopen(y, "w", stdout);

const int maxn = 26;
vector<int> adj[maxn], adjr[maxn];
bool mark[maxn]; int Tx[maxn];
int col[maxn], c = 0;

void dfs(int v) {
	mark[v] = 1; col[v] = c;
	for (int u : adj[v]) {
		if (!mark[u]) dfs(u);
	}
	for (int u : adjr[v]) {
		if (!mark[u]) dfs(u);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		string s[n];
		
		ll output = 0;
		for (int i = 0; i < maxn; i++) {
			adj[i].clear(); adjr[i].clear();
		}
		for (int i = 0; i < n; i++) {
			cin >> s[i];
			int u = s[i][0] - 'a', v = s[i][len(s[i]) - 1] - 'a';
			adj[u].pb(v); adjr[v].pb(u);
			
			output += len(s[i]);
		}
		output -= n;
		
		fill(mark, mark + maxn, 0); c = 0;
		for (int i = 0; i < maxn; i++) {
			if (!mark[i] && len(adj[i]) != 0) {
				dfs(i); c++;
			}
		}
		
		fill(Tx, Tx + maxn, 0);
		for (int i = 0; i < maxn; i++) {
			if (len(adj[i]) > len(adjr[i])) Tx[col[i]] += (len(adj[i]) - len(adjr[i]));
		}
		
		for (int i = 0; i < c; i++) {
			if (Tx[i] == 0) output++;
			else output += Tx[i];
		}
		cout << output << endl;
	}
	
	return 0;
}
