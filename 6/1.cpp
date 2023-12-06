#include "templ.hpp"

void solve()
{
	vector<ll> time, dist;

	{
		string s;

		getline(cin, s);
		s = s.substr(s.find(':') + 1);

		size_t pos = 4;
		while (pos < s.size())
		{
			time.pb(stoll(s.substr(pos, 6)));
			pos += 7;
		}

		getline(cin, s);
		s = s.substr(s.find(':') + 1);

		pos = 0;
		while (pos < s.size())
		{
			dist.pb(stoll(s.substr(pos, 6)));
			pos += 7;
		}
	}

	ll res = 1;
	for (int i = 0; i < time.size(); i++)
	{
		ll cur = 0;
		for (ll t = 0; t <= time[i]; t++)
			cur += (t * (time[i] - t) > dist[i]);
		res *= cur;
	}

	cout << res;
}