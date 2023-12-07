#include "templ.hpp"

map<char, int> cards = {{'A', 14}, {'K', 13}, {'Q', 12}, {'T', 10}, {'9', 9}, {'8', 8}, {'7', 7},
                        {'6', 6},  {'5', 5},  {'4', 4},  {'3', 3},  {'2', 2}, {'J', 1}};

const int HAND_SIZE = 5;

bool isCardLess(const char lhs, const char rhs)
{
	return cards[lhs] < cards[rhs];
}

int getHandType(const string &hand)
{
	int J = 0;
	char maxc = hand[0];

	map<char, int, greater<int>> mp;
	for (char c : hand)
	{
		if (c == 'J')
		{
			J++;
			continue;
		}

		if (mp.contains(c))
			mp[c]++;
		else
			mp[c] = 1;

		if (mp[c] > mp[maxc])
			maxc = c;
	}

	if (J == 5)
		return 7;

	mp[maxc] += J;

	int cnt[6] = {};

	for (auto &[key, val] : mp)
		cnt[val]++;

	if (cnt[5])
		return 7;

	if (cnt[4])
		return 6;

	if (cnt[3] && cnt[2])
		return 5;

	if (cnt[3])
		return 4;

	if (cnt[2] == 2)
		return 3;

	if (cnt[2])
		return 2;

	return 1;
}

struct game
{
	string hand;
	ll bid;
	int type;

	game() = default;
	game(const string &hand, const ll bid) : hand(hand), bid(bid), type(getHandType(hand))
	{
	}

	bool operator<(const game &oth) const
	{
		if (type != oth.type)
			return type < oth.type;

		for (int i = 0; i < HAND_SIZE; i++)
		{
			if (hand[i] == oth.hand[i])
				continue;

			return isCardLess(hand[i], oth.hand[i]);
		}

		return false;
	}
};

void solve()
{
	vector<game> games;

	{
		string s;

		while (getline(cin, s))
			games.pb(game(s.substr(0, 5), stoll(s.substr(6))));
	}

	sort(games.begin(), games.end());

	ll sum = 0;
	for (ll i = 0; i < games.size(); i++)
		sum += (i + 1) * games[i].bid;

	cout << sum;
}