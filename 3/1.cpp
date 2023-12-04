#include "templ.hpp"

bool isIn(const vector<string> &field, int i, int j)
{
	return (i >= 0 && i < field.size()) && (j >= 0 && j < field[i].size());
}

const vector<pair<int, int>> moves = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};

bool checkSurr(const vector<string> &field, int i, int j)
{
	bool res = false;

	for (auto &[di, dj] : moves)
		res |= isIn(field, i + di, j + dj) ? !(isdigit(field[i + di][j + dj]) || field[i + di][j + dj] == '.') : false;

	return res;
}

void solve()
{
	ll sum = 0;

	vector<string> field(0);
	string s = "";

	while (getline(cin, s))
		field.push_back(s);

	for (int i = 0; i < field.size(); i++)
	{
		ll num = 0;
		bool isOk = false;

		for (int j = 0; j < field[i].size(); j++)
		{
			if (isdigit(field[i][j]))
			{
				num = num * 10ll + (field[i][j] - '0');
				isOk |= checkSurr(field, i, j);
			}
			else
			{
				if (isOk)
				{
					sum += num;
					cerr << num << " ";
				}

				isOk = false;
				num = 0;
			}
		}

		if (isOk)
			sum += num;
	}

	cout << sum;
}