#include "templ.hpp"

const int maxr = 12, maxg = 13, maxb = 14;

void solve()
{
	int sum = 0;

	string s;

	while (getline(cin, s))
	{
		int id = stoi(s.substr(5, s.find(':')));

		string games = s.substr(s.find(':') + 2);
		size_t pos = 0;

		int r = 0, g = 0, b = 0;

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
					b = max(b, stoi(val.substr(0, val.size() - 5)));
					break;
				case 'd': // red
					r = max(r, stoi(val.substr(0, val.size() - 4)));
					break;
				case 'n': // green
					g = max(g, stoi(val.substr(0, val.size() - 6)));
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

		if (r <= maxr && g <= maxg && b <= maxb)
			sum += id;
	}

	cout << sum;
}