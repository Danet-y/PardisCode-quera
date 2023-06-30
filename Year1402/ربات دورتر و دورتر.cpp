// IN THE NAME OF GOD
#include<bits/stdc++.h>
#define endl '\n'
#define file_reading freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define flush cout.flush();
using namespace std;
typedef long long ll;
typedef long double dll;
typedef unsigned long long ull;

ll a[4]; 

ll f(ll ind1, ll ind2, ll ind3, ll ind4, ll k){
	ll tmp1 = a[ind1], tmp2 = a[ind2], tmp3 = a[ind3], tmp4 = a[ind4]; 
	ll mn = min(a[ind2],k); 
	if (a[ind3] > a[ind4]) tmp3 += mn; 
	else tmp4 += mn; 
	tmp2 -= mn; 
	k -= mn; 
	if (k){
		mn = min(k,min(tmp3,tmp4)); 
		tmp1 += mn;
		if (tmp3 < tmp4) tmp3 -= mn; 
		else tmp4 -= mn; 
		k -= mn; 
		if (k){
			mn = min(k,max(tmp3,tmp4)); 
			tmp1 += mn; 
			if (tmp3) tmp3 -= mn; 
			else tmp4 -= mn; 
			k -= mn; 
		}
	}
	ll ans = 1ll * (tmp1-tmp2) * (tmp1-tmp2) + 1ll * (tmp3-tmp4) * (tmp3-tmp4); 
	return ans; 
}

int32_t main(){
     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t; cin >> t; 
	while(t--){
		ll k;
		cin >> a[0] >> a[1] >> a[2] >> a[3] >> k; 
		ll mx = 0; 
		mx = max(mx,f(0,2,1,3,k)); 
		mx = max(mx,f(2,0,1,3,k)); 
		mx = max(mx,f(1,3,0,2,k)); 
		mx = max(mx,f(3,1,0,2,k)); 
		cout << mx << endl; 
	}

	return 0;
}
//Iliya Aghazadeh
