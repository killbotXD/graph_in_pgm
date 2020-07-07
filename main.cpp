#include <bits/stdc++.h>

using namespace std;
typedef long double ld;

static string expression;
static ld scale;

#include "stack.hpp"

int f(int x1)
{
	ld x = x1 / scale, ans;
	ans = evaluate(x);
	return (ans * scale);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Incorrect syntax, try $./stack_method \"f(x) expression\"\n");
		return 0;
	}

	int img[1024][1024];
	int grid_spacing = 100;

	for (int i = 0; i < 1024; i++)
		for (int j = 0; j < 1024; j++)
		{
			int x = j - 512, y = 512 - i;

			if (x == 0 || y == 0) // highlight axes
			{
				img[i][j] = 0;
				img[i + 1][j] = 0;
				img[i - 1][j] = 0;
				img[i][j - 1] = 0;
				img[i][j + 1] = 0;
			}
			else if (y % grid_spacing == 0 || x % grid_spacing == 0) //	highlight grids
				img[i][j] = 200;
			else //	plain otherwise
				img[i][j] = 255;
		}

	char *infix;
	int k = 0;

	infix = (char *)malloc(strlen(argv[1]));
	for (int i = 0; i < strlen(argv[1]); i++) // removes whitespaces
		if (argv[1][i] != ' ')
			infix[k++] = argv[1][i];

	fstream fout("./graph.pgm", std::fstream::out);
	fout << "P2\n# " << infix << "\n1024 1024\n255\n";

	expression = infixtopostfix(infix);
	cout << "Scale graph by : ";
	cin >> scale;
	cout << "1 unit of each axis = " << 100.00 / scale << endl;

	int prev_i;
	bool initial_val = true;

	for (int x = -512; x < 512; x++)
	{
		int y = f(x);
		int i = 512 - y, j = x + 512;

		if (i < 0 || i > 1024) // f(x) is out of bounds
			continue;

		if (initial_val)
		{
			prev_i = i;
			initial_val = false;
		}

		int start = min(prev_i, i), end = max(prev_i, i);
		for (; start <= end; start++)
			img[start][j] = 0;

		prev_i = i;
	}

	for (int i = 0; i < 1024; i++)
	{
		for (int j = 0; j < 1024; j++)
			fout << img[i][j] << " ";
		fout << "\n";
	}

	fout.close();

	cout << "Graph for : " << infix << " , saved in ./graph.pgm, open with image viewer." << endl;

	return 0;
}