#include "templ.hpp"

ll getLen(const ll time, const ll dist)
{
	ld d = sqrtl(time * time - 4ll * dist);

	ll x1 = (time - d) / 2.0l;
	while (x1 * (time - x1) < dist)
		x1++;

	ll x2 = (time + d) / 2.0l;
	while (x2 * (time - x2) < dist)
		x2--;

	return x2 - x1 + 1;
}

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
		res *= getLen(time[i], dist[i]);

	cout << res;
}