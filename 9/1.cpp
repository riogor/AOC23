#define III

#include "templ.hpp"

vector<lll> fact(25);

inline lll C(ll n, ll k)
{
	return fact[n] / fact[k] / fact[n - k];
}

inline void solve()
{
	fact[0] = 1;
	for (lll i = 1; i < 25; i++)
		fact[i] = fact[i - 1] * i;

	lll sum = 0;

	string s;

	while (getline(cin, s))
	{
		stringstream ss(s);

		vector<ll> a;
		ll num;
		while (ss >> num)
			a.push_back(num);

		int n = a.size();
		lll cur = 0;

		for (int i = 0; i < n; i++)
			cur = cur + (lll)(i % 2 == n % 2 ? -1 : +1) * C(n + 1, i + 1) * a[i];

		sum += cur;
	}

	cout << sum;
}