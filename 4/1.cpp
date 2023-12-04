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

	string s;

	while (getline(cin, s))
	{
		string win = s.substr(s.find(':') + 2, s.find('|') - (s.find(':') + 2));
		string my = s.substr(s.find('|') + 2);

		auto win_nums = getAllNumbers(win);
		auto my_nums = getAllNumbers(my);

		vector<bool> isWin(100);
		for (int e : win_nums)
			isWin[e] = true;

		ll cnt = 0;
		for (int e : my_nums)
			if (isWin[e])
				cnt++;

		if (cnt == 0)
			continue;

		cnt--;
		sum += (1ll << cnt);
	}

	cout << sum;
}