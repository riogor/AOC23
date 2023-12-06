#include "templ.hpp"

void solve()
{
	ll time = 0, dist = 0;

	{
		string s;

		getline(cin, s);
		s = s.substr(s.find(':') + 1);

		for (char c : s)
			if (isdigit(c))
				time = time * 10ll + (c - '0');

		getline(cin, s);
		s = s.substr(s.find(':') + 1);

		for (char c : s)
			if (isdigit(c))
				dist = dist * 10ll + (c - '0');
	}

	ll res = 0;

	for (ll t = 0; t <= time; t++)
		res += (t * (time - t) > dist);

	cout << res;
}