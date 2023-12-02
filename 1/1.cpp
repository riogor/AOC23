#include "templ.hpp"

void solve()
{
	ll sum = 0;
	string s;

	while (getline(cin, s))
	{
		int n = s.size();

		int cur = 0;

		for (int i = 0; i < n; i++)
			if (isdigit(s[i]))
			{
				cur += (s[i] - '0') * 10;
				break;
			}

		for (int i = n - 1; i >= 0; i--)
			if (isdigit(s[i]))
			{
				cur += (s[i] - '0');
				break;
			}

		sum += cur;
	}

	cout << sum;
}
