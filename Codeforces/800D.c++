#include <stdio.h>

#define N	1000000
#define A	1000000
#define L	6
#define MD	1000000007
#define V2	500000004

int pp10[L], pp2[N + 1];

void init() {
	int i, l;

	pp10[0] = 1;
	for (l = 1; l < L; l++)
		pp10[l] = pp10[l - 1] * 10;
	pp2[0] = 1;
	for (i = 1; i <= N; i++)
		pp2[i] = (long long) pp2[i - 1] * 2 % MD;
}

int main() {
	static int kk[A], dp1[A], dp2[A], dp[A];
	int n, h, a;
	long long x;

	init();
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &a);
		kk[a]++;
	}
	for (a = 0; a < A; a++) {
		dp1[a] = (long long) kk[a] * a % MD;
		dp2[a] = (long long) dp1[a] * a % MD;
	}
	for (h = 0; h < L; h++)
        for (a = A - 1; a >= 0; a--)
			if (a / pp10[h] % 10 < 9) {
				kk[a] += kk[a + pp10[h]];
				dp1[a] = (dp1[a] + dp1[a + pp10[h]]) % MD;
				dp2[a] = (dp2[a] + dp2[a + pp10[h]]) % MD;
			}
	for (a = 0; a < A; a++)
		dp[a] = ((long long) dp1[a] * dp1[a] + dp2[a]) % MD * pp2[kk[a]] % MD * V2 % MD * V2 % MD;
	for (h = 0; h < L; h++)
		for (a = 0; a < A; a++)
			if (a / pp10[h] % 10 < 9)
				dp[a] = (dp[a] - dp[a + pp10[h]] + MD) % MD;
	x = 0;
	for (a = 0; a < A; a++)
		x ^= (long long) dp[a] * a;
	printf("%lld\n", x);
	return 0;
}
