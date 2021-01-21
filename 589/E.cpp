#define LOCAL

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")

#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define LLINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define uniq(x) sort(all(x)); x.resize(unique(all(x))-x.begin());
#define sz(x) (int)x.size()
#define pw(x) (1LL<<x)

using pii = pair<int, int>;
using ll = long long;
const ll MOD = 1e9 + 7;
const long double PI = acos(-1.0);

// Copied from Gennady-Korotkevich's template

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
	return '"' + s + '"';
}

string to_string(const char* s) {
	return to_string((string)s);
}

string to_string(bool b) {
	return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
	bool first = true;
	string res = "{";
	for (int i = 0; i < static_cast<int>(v.size()); i++) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(v[i]);
	}
	res += "}\n";
	return res;
}

template <size_t N>
string to_string(bitset<N> v) {
	string res = "";
	for (size_t i = 0; i < N; i++) {
		res += static_cast<char>('0' + v[i]);
	}
	return res;
}

template <typename A>
string to_string(A v) {
	bool first = true;
	string res = "{";
	for (const auto& x : v) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(x);
	}
	res += "}\n";
	return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

template <typename A, typename B, typename C, typename D, typename E>
string to_string(tuple<A, B, C, D, E> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + "," + to_string(get<4>(p)) + ")";
}

void debug_out() {
	cerr << endl;
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "\n[" << #__VA_ARGS__ << "]:\n", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

// End of Gennady-Korotkevich's template 

ll add(ll x, ll y) {
	x+=y; x%=MOD;
	return x;
}
ll sub(ll x, ll y) {
	x-=y; x%=MOD; if(x<0) x+=MOD;
	return x;
}
ll mult(ll x, ll y) {
	return (x*y)%MOD;
}
ll bin_pow(ll x, ll p) {
	if(p==0) return 1;
	if(p&1) return mult(x,bin_pow(x,p-1));
	return bin_pow(mult(x,x),p/2);
}
ll rev(ll x) {
	return bin_pow(x,MOD-2);
}

ll F[260], rF[260];
ll C[260][260];
ll powK[100000],powKM[100000];
ll getC(int n, int k) {
	return mult(F[n],mult(rF[n-k],rF[k]));
}

void solve() {
	ll n, k; cin >> n >> k;
	F[0]=1;
	for(int i=1 ; i<260 ; i++) {
		F[i]=mult(F[i-1],i);
	}
	rF[259] = rev(F[259]);
	for(int i=259 ; i>0 ; i--) {
		rF[i-1] = mult(rF[i],i); 
	}
	for(int i=0 ; i<255 ; i++) {
		for(int j=0 ; j<=i ; j++) {
			C[i][j] = getC(i,j);
		}
	}
	powK[0]=1;powKM[0]=1;
	for(int i=1 ; i<88888 ; i++) {
		powK[i] = mult(powK[i-1],k);
		powKM[i] = mult(powKM[i-1],k-1); 
	}
	ll ans = 0;
	ans += powK[n*n];
	for(int i=1 ; i<=n*2 ; i++) { // 
		int mi = (i&1) == 1 ? -1 : 1;
		for(int j=0 ; j<=n ; j++) { // j = ban 한 가로의 갯수 
			int bannedGaro = j;
			int bannedSero = i-j;
			if(bannedSero<0||bannedSero>n) continue;

			int z = bannedSero * n + bannedGaro * n - bannedSero * bannedGaro;
		
			ans += (ll)mi *mult( mult( C[n][bannedGaro] , C[n][bannedSero] ) , mult(powKM[z] , powK[n*n-z]));
			
			ans %= MOD;
			if(ans<0)ans+=MOD;
		}
	}
	cout << ans << "\n";
}

int main() {
	IOS;
	int t; t = 1;
	while(t--)
		solve();
}