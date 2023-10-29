#include <cstdio>
using namespace std;

#define MAXN 10011

int N, sp;
char s[MAXN];

void read()
{
	scanf("%d", &N);
	scanf("%s", s);
}

void makeSimpleMove(int pos)
{
	printf("%d\n", pos + 1);
	s[sp] = s[pos], s[sp + 1] = s[pos + 1];
	s[pos] = s[pos + 1] = 'S';
	sp = pos;
}

void makeMove(int pos)
{
	if (s[pos + 1] != 'S')
		makeSimpleMove(pos);
	else
	{
		makeSimpleMove(2 * N);
		makeSimpleMove(pos);
	}

	int i;
	for (i = pos + 1; i < 2 * N + 2; i++)
		if (s[i] == 'F')
			break;
	if (i != 2 * N + 1)
		makeSimpleMove(i);
	else
	{
		makeSimpleMove(2 * N);
		makeSimpleMove(pos + 2);
		makeSimpleMove(pos - 1);
		makeSimpleMove(pos + 1);
	}
}

void solve()
{
	for (int i = 0; i < 2 * N + 2; i++)
		if (s[i] == 'S')
		{
			sp = i;
			break;
		}
	for (int i = 0; i < N; i++)
		if (s[i] != 'F')
			makeMove(i);
	if (s[N] != 'S')
		makeSimpleMove(N);
}

int main()
{
	// freopen("aranjare.in", "r", stdin);
	// freopen("aranjare.out", "w", stdout);

	read();
	solve();

	return 0;
}
