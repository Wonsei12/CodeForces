#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <list>
#include <ctime>
#include <complex>
#include <bitset>
#include <tuple>
#include <functional>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define MOD 1000000007LL
#define rep(i,a,n) for (int i=a ; i<n ; i++)
#define per(i,a,n) for (int i=n-1 ; i>=a ; i--)
#define LLINF 100000000000000005LL
#define INF (int)1e9+1
#define endl '\n'
#define pb push_back

// debug 도구

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
    res += "}";
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

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:\n", debug_out(__VA_ARGS__)

// debug 도구 end

using llong = long long;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VLL = vector<long long>;
using PII = pair<int, int>;

//struct cmp {
//	bool operator() (int a, int b)
//	{
//		return a > b;
//	}
//};

int n;
VLL a;
VLL seg;

llong build(int index, int start, int end) {
    if (start == end) return seg[index] = a[start];
    int mid = (start + end) / 2;
    llong lseg = build(index * 2, start, mid);
    llong rseg = build(index * 2 + 1, mid + 1, end);
    int lPoint = mid, rPoint = mid + 1;
    llong curH = min(a[lPoint], a[rPoint]);
    llong mmax = 2 * curH;
    while (lPoint != start || rPoint != end) {
        if (start == lPoint) {
            rPoint++;
            curH = min(curH, a[rPoint]);
        }
        else if (end == rPoint) {
            lPoint--;
            curH = min(curH, a[lPoint]);
        }
        else {
            if (a[lPoint - 1] > a[rPoint + 1]) {
                lPoint--;
                curH = min(curH, a[lPoint]);
            }
            else {
                rPoint++;
                curH = min(curH, a[rPoint]);
            }
        }
        mmax = max(mmax, (rPoint - lPoint + 1) * curH);
      
    }
    return seg[index] = max({ mmax, lseg, rseg });
}

int main() {
    IOS;
    
   
        cin >> n;

        a = VLL(n); seg = VLL(4 * n + 2);
        rep(i, 0, n) cin >> a[i];
        build(1, 0, n - 1);
        cout << seg[1] << endl;
       // debug(seg);

   
    return 0;
}