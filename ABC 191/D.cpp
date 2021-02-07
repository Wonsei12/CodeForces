#include <bits/stdc++.h>
using namespace std;

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

#define LOCAL

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

int main() {
	IOS;
	string x,y,r; cin >> x >> y >> r;
	ll xp = 0;
	int dotidx = -1;
	bool xfuck = x[0]=='-';
	bool yfuck = y[0]=='-';
	bool rfuck = r[0]=='-';
	if(xfuck) x=x.substr(1,sz(x)-1);
	if(yfuck) y=y.substr(1,sz(y)-1);
	if(rfuck) r=r.substr(1,sz(r)-1);
	for(int i=0 ; i<sz(x) ; i++) {
		if(x[i] == '.') {
			dotidx=i;
			break;
		}
		xp *= 10LL;
		xp += (ll)(x[i] - '0');
	} 
	if(dotidx == -1) {
		xp *= 10000LL;
	} else {
		int cnt = 0;
		for(int i=dotidx + 1 ; i<sz(x) ; i++) {
			cnt ++;
			xp *= 10LL;
			xp += (ll)(x[i] - '0');
		}
		while(cnt < 4) {
			cnt++;
			xp *= 10LL;
		}
	}
	ll yp=0,rp=0;
	dotidx = -1;
	for(int i=0 ; i<sz(y) ; i++) {
		if(y[i] == '.') {
			dotidx=i;
			break;
		}
		yp *= 10LL;
		yp += (ll)(y[i] - '0');
	} 
	if(dotidx == -1) {
		yp *= 10000LL;
	} else {
		int cnt = 0;
		for(int i=dotidx + 1 ; i<sz(y) ; i++) {
			cnt ++;
			yp *= 10LL;
			yp += (ll)(y[i] - '0');
		}
		while(cnt < 4) {
			cnt++;
			yp *= 10LL;
		}
	}
	dotidx = -1;
	for(int i=0 ; i<sz(r) ; i++) {
		if(r[i] == '.') {
			dotidx=i;
			break;
		}
		rp *= 10LL;
		rp += (ll)(r[i] - '0');
	} 
	if(dotidx == -1) {
		rp *= 10000LL;
	} else {
		int cnt = 0;
		for(int i=dotidx + 1 ; i<sz(r) ; i++) {
			cnt ++;
			rp *= 10LL;
			rp += (ll)(r[i] - '0');
		}
		while(cnt < 4) {
			cnt++;
			rp *= 10LL;
		}
	}
	if(xfuck)xp=-xp;
	if(yfuck)yp=-yp;
	if(rfuck)rp=-rp;
	debug(xp,yp,rp);
	auto findub = [&](ll left) -> ll {
		ll l = yp, r =5e9;
		ll ans = LLINF;
		while(l<=r) {
			ll mid = (l + r) / 2;
			if((mid - yp) * (mid - yp) <= left) {
				ans = mid;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		return ans;
	};
	auto finddb = [&](ll left) -> ll {
		ll l = -5e9, r = yp;
		ll ans = LLINF;
		while(l<=r) {
			ll mid = (l + r) / 2;
			if((mid - yp) * (mid - yp) <= left) {
				ans = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		return ans;
	};
	ll ans = 0;
	ll st = (xp - rp - 300000) - ((xp - rp) % 10000 + 10000) % 10000;
	for(ll cX = st ; cX <= (rp + xp + 300000) - ((rp + xp) % 10000LL + 10000) % 10000 ; cX += 10000) {

		if(rp * rp - (xp - cX) * (xp - cX) < 0) continue;
		ll left = rp * rp - (xp - cX) * (xp - cX);

		ll ub = findub(left);
		ll db = finddb(left);
		//debug(cX,ub,db);
		if(ub % 10000LL) {
			ll nam = (ub % 10000LL + 10000LL) % 10000LL;
			ub -= nam;
		}
		if(db % 10000LL) {
			ll nam = (db % 10000LL + 10000LL) % 10000LL;
			nam = 10000 - nam;
			db += nam;
		}
		if(ub < db) continue;
		ans += (ub - db) / 10000LL + 1LL;
	}
	cout << ans << "\n";
	
}