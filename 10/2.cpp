#include "templ.hpp"

const set<char> up = {'|', 'L', 'J', 'S'};
const set<char> lt = {'-', 'J', '7', 'S'};
const set<char> rt = {'-', 'F', 'L', 'S'};
const set<char> down = {'|', '7', 'F', 'S'};
const vector<array<int, 2>> mv = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
const int inf = 1e9;

int n, m;
int sx, sy;
vector<string> gr;
vector<vector<int>> d;

inline bool check(int x, int y, int dx, int dy)
{
	int nx = x + dx, ny = y + dy;

	if (!(nx >= 0 && ny >= 0 && nx < n && ny < m))
		return false;

	const set<char> *a = nullptr, *b = nullptr;

	if (dx == 1)
		a = &down, b = &up;
	else if (dx == -1)
		a = &up, b = &down;
	else if (dy == 1)
		a = &rt, b = &lt;
	else if (dy == -1)
		a = &lt, b = &rt;

	if (!a || !b)
	{
		cout << "FUCK" << endl;
		throw -1;
	}

	return a->contains(gr[x][y]) && b->contains(gr[nx][ny]);
}

inline void dfs(int x, int y, int px, int py)
{
	d[x][y] = 1;

	for (auto &[dx, dy] : mv)
	{
		int nx = x + dx, ny = y + dy;

		if (!check(x, y, dx, dy))
			continue;

		if (nx == px && ny == py)
			continue;

		if (nx == sx && ny == sy)
			throw 0;

		if (d[nx][ny] != 0)
			continue;

		dfs(nx, ny, x, y);
	}

	d[x][y] = -1;
}

inline ll dfs3(int x, int y)
{
	d[x][y] = 2;

	ll cnt = 1;

	for (auto &[dx, dy] : mv)
	{
		int nx = x + dx, ny = y + dy;

		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			cnt = -inf;

		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;

		if (d[nx][ny] != 0)
			continue;

		cnt += dfs3(nx, ny);
	}

	return cnt;
}

inline void solve()
{
	string s;

	while (getline(cin, s))
		gr.push_back(s);

	n = gr.size();
	m = gr[0].size();

	d.resize(n, vector<int>(m, 0));

	try
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (gr[i][j] == 'S')
				{
					sx = i, sy = j;
					dfs(i, j, -1, -1);
				}
	}
	catch (int &dd)
	{
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (d[i][j] != 1)
				d[i][j] = 0;

	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		bool isIn = false;
		char lastCorn = '.';

		for (int j = 0; j < m; j++)
		{
			if (d[i][j] == 1)
			{
				switch (gr[i][j])
				{
				case '|':
					isIn = !isIn;
					break;
				case 'F':
					lastCorn = 'F';
					break;
				case 'L':
					lastCorn = 'L';
					break;

				case '7':
					if (lastCorn == 'L')
						isIn = !isIn;

					lastCorn = '.';
					break;

				case 'J':
					if (lastCorn == 'F')
						isIn = !isIn;

					lastCorn = '.';
					break;

				case '-':
					break;
				}
			}

			if (d[i][j] == 0 && isIn)
			{
				d[i][j] = 2;
				ans++;
			}
		}
	}

	cout << ans;
}