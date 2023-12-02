#include "templ.hpp"

const vector<string> nums = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const vector<int> numi = {1, 2, 3, 4, 5, 6, 7, 8, 9};

void solve()
{
	ll sum = 0;
	string s;

	while (getline(cin, s))
	{
		int n = s.size();
		s += "-----";

		int cur = 0;

		for (int i = 0; i < n; i++)
		{
			if (isdigit(s[i]))
			{
				cur += (s[i] - '0') * 10;
				break;
			}

			auto it = nums.begin();
			if ((it = find(nums.begin(), nums.end(), s.substr(i, 3))) != nums.end() ||
			    (it = find(nums.begin(), nums.end(), s.substr(i, 4))) != nums.end() ||
			    (it = find(nums.begin(), nums.end(), s.substr(i, 5))) != nums.end())
			{
				cur += numi[it - nums.begin()] * 10;
				break;
			}
		}

		for (int i = n - 1; i >= 0; i--)
		{
			if (isdigit(s[i]))
			{
				cur += (s[i] - '0');
				break;
			}

			auto it = nums.begin();

			if ((it = find(nums.begin(), nums.end(), s.substr(i, 3))) != nums.end() ||
			    (it = find(nums.begin(), nums.end(), s.substr(i, 4))) != nums.end() ||
			    (it = find(nums.begin(), nums.end(), s.substr(i, 5))) != nums.end())
			{
				cur += numi[it - nums.begin()];
				break;
			}
		}

		sum += cur;
	}

	cout << sum;
}
