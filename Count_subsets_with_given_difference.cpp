/*

JAI SHREE RAM
user: Atul Bahuguna

*/


#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define rep(i,st,en) for(ll i=st;i<en;i++)
#define F first
#define S second
#define vi vector<ll>
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;

/*****************************GCD function***********************/

int gcd(int a, int b) {

	if (a == 0) {
		return b;
	}

	// make sure always pass abs(a) and abs(b);

	return gcd(b, a % b);
}


ll power(ll base, ll n) {
	ll res = 1;
	while (n) {
		if (n % 2 == 1) {
			res = res * base;
			n--;
		}
		base = base * base;
		n /= 2;
	}

	return res;
}

bool is_prime[10000001];

void sieve() {

	ll maxN = 10000000;

	for (ll i = 1; i <= maxN; i++) {
		is_prime[i] = true;
	}
	is_prime[0] = is_prime[1] = false;

	for (ll i = 2; i * i <= maxN; i++) {
		if (is_prime[i]) {
			for (ll j = i * i; j <= maxN; j += i) {
				is_prime[j] = false;
			}
		}
	}


}


/*******************************Main function Program*******************/


void solve() {


	ll n; cin >> n;
	vi arr(n);
	ll sum = 0;
	rep(i, 0, n) {
		cin >> arr[i];
		sum += arr[i];
	}

	ll diff; cin >> diff;

	if ((diff + sum) % 2 != 0) {
		cout << 0 << endl;
		return;
	}
	ll target = (diff + sum) / 2;
	int dp[n + 1][target + 1];
	rep(i, 0, n + 1) {
		rep(j, 0, target + 1) {
			if (i == 0)dp[i][j] = 0;
			if (j == 0)dp[i][j] = 1;
		}
	}
	rep(i, 1, n + 1) {
		rep(j, 1, target + 1) {
			if (arr[i - 1] <= j) {
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[n][target] << endl;

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE

	ios::sync_with_stdio(false); cin.tie(NULL);
	sieve();
	ll T;
	cin >> T;
	while (T--) {
		solve();

	}
	return 0;
}