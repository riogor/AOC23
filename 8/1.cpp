#include "templ.hpp"

const string start = "AAA";
const string finish = "ZZZ";

const int maxv = 26 * 26 * 26 + 5;

void solve()
{
	string seq;

	cin >> seq;
	int n = seq.size();

	vector<pair<int, int>> gr = {};
	gr.resize(maxv);

	map<string, int> id = {};
	int T = 0;
	id[start] = T++;
	id[finish] = T++;

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
		}
	}

	const int start_id = id[start];
	const int finish_id = id[finish];

	int cnt = 0;
	int cur = start_id;

	while (cur != finish_id)
	{
		if (seq[cnt % n] == 'L')
			cur = gr[cur].fi;
		else
			cur = gr[cur].se;

		cnt++;
	}

	cout << cnt;
}