#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Èý½ÇÐÎÊýÕó
int main1()
{
	int n, m;
	while (cin >> n)
	{
		m = 2 * n - 1;
		vector<vector<int>>dp(n, vector<int>(m, 0));
		dp[0][0] = 1;
		for (int i = 1; i < n; i++)
		{
			dp[i][0] = dp[i][2 * i] = 1;
			for (int j = 1; j < 2 * i; j++)
			{
				if (j == 1)
				{
					dp[i][j] = dp[i - 1][i - 1] + dp[i - 1][j];
				}
				else
				{
					dp[i][j] = dp[i - 1][j - 2] + dp[i - 1][j - 1] + dp[i - 1][j];
				}
			}
		}
		int k;
		for (k = 0; k < m; k++)
		{
			if (dp[n - 1][k] % 2 == 0 && dp[n - 1][k] != 0)
			{
				cout << k + 1 << endl;
				break;
			}
		}
		if (k == m)
		{
			cout << -1 << endl;
		}

	}

	system("pause");
	return 0;
}