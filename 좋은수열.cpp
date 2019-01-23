#include <iostream>
#include <vector>
#include <string>

using namespace std;

string g_seq;
char no_select;

// true -> overlap , false -> not overlap
bool overlap_chk(string &g_seq)
{
	int mid = g_seq.size() / 2;
	bool overlap = false;

	if (mid != 0)
	{
		for (int i = 1; i <= mid; i++)
			if (g_seq.substr(g_seq.size() - i, i) == g_seq.substr(g_seq.size() - 2 * i, i))
			{
				overlap = true;
				break;
			}
		return overlap;
	}
	else if (mid == 0)
		return false;
}

void good(string &g_seq, int m_leng, int prev)
{
	bool special = true; // there is no overlap of all three numbers -> true, if not -> false
	char present;

	// return condition
	if (g_seq.length() == m_leng)
		return;

	if (prev == 0) // normal case
	{
		for (int i = 1; i <= 3; i++)
		{
			g_seq.push_back('0' + i);

			if (!overlap_chk(g_seq))
			{
				special = false;
				break;
			}

			g_seq.pop_back();
		}

		if (special == true)
			good(g_seq, m_leng, 1);
		else
			good(g_seq, m_leng, 0);
	}
	else if (prev == 1)// special case
	{
		present = g_seq.back();
		g_seq.pop_back();

		for (int i = 1; i <= 3; i++)
		{
			if (i == present - '0')
				continue;

			g_seq.push_back('0' + i);

			if (!overlap_chk(g_seq))
			{
				special = false;
				break;
			}

			g_seq.pop_back();
		}

		if (special == true)
			good(g_seq, m_leng, 1);
		else
			good(g_seq, m_leng, 0);
	}
}

int main()
{
	int n;
	cin >> n;

	good(g_seq, n, 0);
	cout << g_seq << '\n';

	return 0;
}