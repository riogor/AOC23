#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back

#ifndef LOCAL
#define cerr                                                                                                           \
	if (0)                                                                                                             \
	cerr
#endif

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<int> vi;
typedef vector<vi> vvi;

template <typename T, typename V> ostream &operator<<(ostream &out, const pair<T, V> &p)
{
	out << "(" << p.ff << ", " << p.ss << ")";

	return out;
}

template <typename T> ostream &operator<<(ostream &out, const vector<T> &v)
{
	out << "[";
	for (const T &e : v)
		out << e << ", ";
	out << "]";

	return out;
}

template <typename T, typename V, typename C> ostream &operator<<(ostream &out, const map<T, V, C> m)
{
	out << "<";
	for (const auto &e : m)
		out << e << ", ";
	out << ">";

	return out;
}

void solve();

void init()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

int main()
{
	init();

	solve();

	return 0;
}
