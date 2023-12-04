#include "templ.hpp"

vector<int> getAllNumbers(const string &s)
{
	vector<int> v;
	for (int i = 0; i < s.size(); i += 3)
		v.pb(stoi(s.substr(i, 2)));

	return v;
}

void solve()
{
	ll sum = 0;

	vector<ll> cnt(500);
	int ptr = 0;

	string s;

	while (getline(cin, s))
	{
		cnt[ptr] += 1ll;

		string win = s.substr(s.find(':') + 2, s.find('|') - (s.find(':') + 2));
		string my = s.substr(s.find('|') + 2);

		auto win_nums = getAllNumbers(win);
		auto my_nums = getAllNumbers(my);

		vector<bool> isWin(100);
		for (int e : win_nums)
			isWin[e] = true;

		int cur = 0;
		for (int e : my_nums)
			if (isWin[e])
				cur++;

		for (int i = 1; i <= cur; i++)
			cnt[ptr + i] += cnt[ptr];

		ptr++;
	}

	for (int i = 0; i < ptr; i++)
		sum += cnt[i];

	cout << sum;
}