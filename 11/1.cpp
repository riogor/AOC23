#include "templ.hpp"

inline void solve()
{
	vector<string> g;
	string s;

	while (getline(cin, s))
		g.push_back(s);

	int n = g.size();
	int m = g[0].size();
	ll cnt = [&g]() {
		int cnt = 0;
		for (auto &e : g)
			cnt += count(e.begin(), e.end(), '#');

		return cnt;
	}();

	ll ans = 0;

	{
		ll c1 = cnt;
		ll c2 = 0;
		for (int i = 0; i < n; i++)
		{
			int cur = count(g[i].begin(), g[i].end(), '#');

			c1 -= cur;
			c2 += cur;

			if (cur == 0)
				ans += c1 * c2;
			ans += c1 * c2;
		}
	}

	{
		ll c1 = cnt;
		ll c2 = 0;

		for (int j = 0; j < m; j++)
		{
			int cur = 0;
			for (int i = 0; i < n; i++)
				cur += g[i][j] == '#';

			c1 -= cur;
			c2 += cur;

			if (cur == 0)
				ans += c1 * c2;
			ans += c1 * c2;
		}
	}

	cout << ans;
}