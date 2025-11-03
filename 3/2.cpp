#include "templ.hpp"

const vector<pair<int, int>> moves = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};

bool isIn(const vector<string> &field, int i, int j)
{
	return (i >= 0 && i < field.size()) && (j >= 0 && j < field[i].size());
}

bool checkSurr(const vector<string> &field, int i, int j)
{
	bool res = false;

	for (auto &[di, dj] : moves)
		res |= isIn(field, i + di, j + dj) ? !(isdigit(field[i + di][j + dj]) || field[i + di][j + dj] == '.') : false;

	return res;
}

void solve()
{
	vector<string> field(0);
	string s = "";

	while (getline(cin, s))
		field.push_back(s);

	map<pair<int, int>, pair<ll, int>> gears;
	for (int i = 0; i < field.size(); i++)
		for (int j = 0; j < field[i].size(); j++)
			if (field[i][j] == '*')
				gears[{i, j}] = {1, 0};

	for (int i = 0; i < field.size(); i++)
	{
		ll num = 0;
		int len = 0;
		bool isOk = false;

		for (int j = 0; j < field[i].size(); j++)
		{
			if (isdigit(field[i][j]))
			{
				num = num * 10ll + (field[i][j] - '0');
				len++;
				isOk |= checkSurr(field, i, j);
			}
			else
			{
				if (isOk)
				{
					set<pair<int, int>> used;
					for (int s = 0; s < len; s++)
					{
						for (auto &[di, dj] : moves)
						{
							if (isIn(field, i + di, j - s + dj - 1) && field[i + di][j - s + dj - 1] == '*' &&
							    used.find({i + di, j - s + dj - 1}) == used.end())
							{
								gears[{i + di, j - s + dj - 1}].fi *= num;
								gears[{i + di, j - s + dj - 1}].se++;
								used.insert({i + di, j - s + dj - 1});
							}
						}
					}
				}

				isOk = false;
				len = 0;
				num = 0;
			}
		}

		if (isOk)
		{
			set<pair<int, int>> used;
			int m = field[i].size();
			for (int s = 0; s < len; s++)
			{
				for (auto &[di, dj] : moves)
				{
					if (isIn(field, i + di, m - 1 - s + dj) && field[i + di][m - 1 - s + dj] == '*' &&
					    used.find({i + di, m - 1 - s + dj}) == used.end())
					{
						gears[{i + di, m - 1 - s + dj}].fi *= num;
						gears[{i + di, m - 1 - s + dj}].se++;
						used.insert({i + di, m - 1 - s + dj});
					}
				}
			}
		}
	}

	ll sum = 0;
	for (auto &[coord, val] : gears)
		if (val.se == 2)
			sum += val.fi;

	cout << sum;
}