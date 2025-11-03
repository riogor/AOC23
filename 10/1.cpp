#include "templ.hpp"

const set<char> up = {'|', 'L', 'J', 'S'};
const set<char> lt = {'-', 'J', '7', 'S'};
const set<char> rt = {'-', 'F', 'L', 'S'};
const set<char> down = {'|', '7', 'F', 'S'};
const vector<array<int, 2>> mv = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
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

inline void dfs(int x, int y, int px, int py, int dd)
{
	d[x][y] = dd;

	for (auto &[dx, dy] : mv)
	{
		int nx = x + dx, ny = y + dy;

		if (!check(x, y, dx, dy))
			continue;

		if (nx == px && ny == py)
			continue;

		if (nx == sx && ny == sy)
			throw dd;

		if (d[nx][ny] != inf)
			continue;

		dfs(nx, ny, x, y, dd + 1);
	}

	d[x][y] = -1;
}

inline void solve()
{
	string s;

	while (getline(cin, s))
		gr.push_back(s);

	n = gr.size();
	m = gr[0].size();

	d.resize(n, vector<int>(m, inf));

	try
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (gr[i][j] == 'S')
				{
					sx = i, sy = j;
					dfs(i, j, -1, -1, 0);
				}
	}
	catch (int &dd)
	{
		cout << dd;
	}
}