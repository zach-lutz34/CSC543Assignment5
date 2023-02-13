#include <iostream>
#include <string.h>
using namespace std;

int LCSS(char* x, char* y, int a, int b)
{

	int LCSuf[a + 1][b + 1];
	int res = 0;
	
	for (int i = 0; i <= a; i++)
	{
		for (int j = 0; j <= b; j++)
		{
			
			if (i == 0 || j == 0)
				LCSuf[i][j] = 0;

			else if (x[i - 1] == y[j - 1]) {
				LCSuf[i][j] = LCSuf[i - 1][j - 1] + 1;
				res = max(res, LCSuf[i][j]);
			}
			else
				LCSuf[i][j] = 0;
		}
	}
	return res;
}

int main()
{
	char x[] = "ABAB";
	char y[] = "BABA";

	int a = strlen(x);
	int b = strlen(y);

	cout << "Length of Longest Common Substring is: "
		<< LCSS(x, y, a, b);
	return 0;
}
