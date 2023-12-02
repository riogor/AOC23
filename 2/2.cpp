#include "templ.hpp"

void solve()
{
	ll sum = 0;

	string s;

	while (getline(cin, s))
	{
		string games = s.substr(s.find(':') + 2);
		size_t pos = 0;

		ll r = 0, g = 0, b = 0;

		while (pos < string::npos)
		{
			string game = games.substr(pos, games.find(';', pos + 1) - pos);

			size_t poss = 0;
			while (poss < string::npos)
			{
				string val = game.substr(poss, game.find(',', poss + 1) - poss);

				switch (val.back())
				{
				case 'e': // blue
					b = max(b, stoll(val.substr(0, val.size() - 5)));
					break;
				case 'd': // red
					r = max(r, stoll(val.substr(0, val.size() - 4)));
					break;
				case 'n': // green
					g = max(g, stoll(val.substr(0, val.size() - 6)));
					break;

				default:
					throw runtime_error("wha???");
				}

				if (game.find(',', poss + 1) == string::npos)
					break;

				poss = game.find(',', poss + 1) + 2;
			}

			if (games.find(';', pos + 2) == string::npos)
				break;

			pos = games.find(';', pos + 2) + 2;
		}

		sum += r * g * b;
	}

	cout << sum;
}