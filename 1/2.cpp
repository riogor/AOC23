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

template <typename T, typename V> ostream &operator<<(ostream &out, pair<T, V> &p)
{
	out << "(" << p.ff << ", " << p.ss << ")";

	return out;
}

template <typename T> ostream &operator<<(ostream &out, vector<T> &v)
{
	out << "[";
	for (T &e : v)
		out << e << ", ";
	out << "]";

	return out;
}

void solve();

void files()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	files();

	int t = 1;
	// cin >> t;

	while (t--)
	{
		solve();
		cout << "\n";
	}

	return 0;
}

const vector<string> nums = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const vector<int> numi = {1, 2, 3, 4, 5, 6, 7, 8, 9};

void solve()
{
	ll sum = 0;
	string s;

	while (getline(cin, s))
	{
		int n = s.size();
		s += "-----";

		int cur = 0;

		for (int i = 0; i < n; i++)
		{
			if (isdigit(s[i]))
			{
				cur += (s[i] - '0') * 10;
				break;
			}

			auto it = nums.begin();
			if ((it = find(nums.begin(), nums.end(), s.substr(i, 3))) != nums.end() ||
			    (it = find(nums.begin(), nums.end(), s.substr(i, 4))) != nums.end() ||
			    (it = find(nums.begin(), nums.end(), s.substr(i, 5))) != nums.end())
			{
				cur += numi[it - nums.begin()] * 10;
				break;
			}
		}

		for (int i = n - 1; i >= 0; i--)
		{
			if (isdigit(s[i]))
			{
				cur += (s[i] - '0');
				break;
			}

			auto it = nums.begin();

			if ((it = find(nums.begin(), nums.end(), s.substr(i, 3))) != nums.end() ||
			    (it = find(nums.begin(), nums.end(), s.substr(i, 4))) != nums.end() ||
			    (it = find(nums.begin(), nums.end(), s.substr(i, 5))) != nums.end())
			{
				cur += numi[it - nums.begin()];
				break;
			}
		}

		sum += cur;
	}

	cout << sum;
}
