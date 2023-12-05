#include "templ.hpp"

struct conv
{
	ll st;
	ll shift;
	ll len;

	conv() = default;
	conv(ll st1, ll st2, ll len) : st(st1), shift(st2 - st1), len(len)
	{
	}

	auto operator<=>(const conv &oth) const
	{
		return st <=> oth.st;
	}

	auto operator<=>(const ll val) const
	{
		return st <=> val;
	}

	bool isIn(const ll val) const // [st, st+len)
	{
		return st <= val && st + len > val;
	}

	ll convert(const ll val) const
	{
		return val + shift;
	}

	friend ostream &operator<<(ostream &out, const conv &c)
	{
		out << "(" << c.st << ", " << c.shift << ", " << c.len << ")";
		return out;
	}
};

void solve()
{
	vector<pair<ll, ll>> seeds;

	string s;
	getline(cin, s);

	s = s.substr(s.find(':') + 2);

	size_t ptr = 0;
	while (ptr < s.size())
	{
		size_t nxt = s.find(' ', ptr + 1);
		ll a = stoll(s.substr(ptr, nxt - ptr));
		ptr = nxt;

		nxt = s.find(' ', ptr + 1);
		ll b = stoll(s.substr(ptr, nxt - ptr));
		ptr = nxt;

		seeds.pb({a, b});
	}

	vector<vector<conv>> maps;
	maps.resize(7);
	int map_cnt = 0;

	getline(cin, s);
	while (getline(cin, s))
	{
		if (s.find(':') != string::npos)
		{
			getline(cin, s);

			do
			{
				size_t pos = s.find(' ');
				ll end = stoll(s.substr(0, pos));
				ll st = stoll(s.substr(pos + 1, s.find(' ', pos + 1) - pos - 1));
				ll len = stoll(s.substr(s.find(' ', pos + 1)));

				maps[map_cnt].pb(conv(st, end, len));

				if (!getline(cin, s))
					break;
			} while (s != "");
		}

		sort(maps[map_cnt].begin(), maps[map_cnt].end());
		map_cnt++;
	}

	ll min_pos = LLONG_MAX;

	for (auto &[b, l] : seeds)
	{
		for (ll seed = b; seed < b + l; seed++)
		{
			ll cur = seed;
			for (int i = 0; i < 7; i++)
			{
				auto it = upper_bound(maps[i].begin(), maps[i].end(), cur) - 1;
				if (it >= maps[i].begin() && it->isIn(cur))
					cur = it->convert(cur);
			}

			min_pos = min(min_pos, cur);
		}
	}

	cout << min_pos;
}