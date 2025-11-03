#include "templ.hpp"

const int maxv = 26 * 26 * 26 + 5;
const ll inf = 1e12;

bool check(const vector<int> &starts, const vector<bool> &finishes)
{
	for (int start : starts)
		if (!finishes[start])
			return false;

	return true;
}

void solve()
{
	string seq;

	cin >> seq;
	ll n = seq.size();

	vector<array<int, 2>> gr = {};
	gr.resize(maxv);

	map<string, int> id = {};
	int T = 0;

	vector<int> starts;
	vector<bool> finishes(maxv);

	{
		string s;

		getline(cin, s);
		getline(cin, s);
		while (getline(cin, s))
		{
			string cur = s.substr(0, 3);

			size_t comma = s.find(',');
			string left = s.substr(comma - 3, 3);
			string right = s.substr(comma + 2, 3);

			if (!id.contains(cur))
				id[cur] = T++;
			if (!id.contains(left))
				id[left] = T++;
			if (!id.contains(right))
				id[right] = T++;

			gr[id[cur]] = {id[left], id[right]};

			if (cur.back() == 'A')
				starts.pb(id[cur]);

			if (cur.back() == 'Z')
				finishes[id[cur]] = true;
		}
	}

	vector<vector<ll>> d(T, vector<ll>());
	for (int start : starts)
	{
		ll cnt = 0;
		int cur = start;
		while (cnt < 3e4)
		{
			d[cur].push_back(cnt);

			cur = gr[cur][seq[cnt % n] == 'R'];

			cnt++;
		}
	}

	vector<ll> p;

	for (int i = 0; i < id.size(); i++)
		if (finishes[i])
			p.push_back(d[i][0]);

	ll g = p[0];
	for (int i = 1; i < p.size(); i++)
		g = gcd(g, p[i]);

	ll ans = p[0];
	for (int i = 1; i < p.size(); i++)
		ans = ans * (p[i] / g);

	cout << g << " " << ans;
}