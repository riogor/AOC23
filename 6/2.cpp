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

	cout << getLen(time, dist);
}