// #include <bits/allocator.h>

// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())

#ifndef LOCAL
#define cerr                                                                                                           \
	if (0)                                                                                                             \
	cerr
#endif

using namespace std;

// #define int ll

typedef unsigned short us;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vl> vvl;
typedef vector<pii> vpii;

// #define III

#ifdef III
typedef __int128 lll;
#endif

#pragma region prints

#ifdef III
istream &operator>>(istream &in, lll &i)
{
	ll val;
	in >> val;
	i = val;

	return in;
}

ostream &operator<<(ostream &out, lll i)
{
	out << (ll)i;

	return out;
}
#endif

template <typename T, typename V> ostream &operator<<(ostream &out, pair<T, V> p);
template <typename T> ostream &operator<<(ostream &out, vector<T> v);
template <typename T, typename C> ostream &operator<<(ostream &out, set<T, C> s);
template <typename T, typename V, typename C> ostream &operator<<(ostream &out, map<T, V, C> m);

template <typename T, typename V> ostream &operator<<(ostream &out, pair<T, V> p)
{
	out << "(" << p.fi << ", " << p.se << ")";

	return out;
}

template <typename T> ostream &operator<<(ostream &out, vector<T> v)
{
	out << "[";
	for (T e : v)
		out << e << ", ";
	out << "]";

	return out;
}

template <typename T, typename C> ostream &operator<<(ostream &out, set<T, C> s)
{
	out << "{";
	for (T e : s)
		out << e << ", ";
	out << "}";

	return out;
}

template <typename T, typename V, typename C> ostream &operator<<(ostream &out, map<T, V, C> m)
{
	out << "{";
	for (auto e : m)
		out << e << ", ";
	out << "}";

	return out;
}

#define dbg(x) cout << #x << " : " << x << endl;

#pragma endregion

inline void solve();

signed main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t = 1;
	// cin >> t;

	while (t--)
	{
		solve();
		cout << "\n";
	}

	return 0;
}
