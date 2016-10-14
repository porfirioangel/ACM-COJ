#include <cstdio>

using namespace std;

#define MOD 1000000000

int T;
long long a, b, res;

long long mod_pow(long long a, long long b) {
	long long n;
	if(a == MOD && b == 1) return 0;
	if(b == 0) return 1;
	if(b == 1) return a;
	n = mod_pow(a, b / 2);
	n = (n * n) % MOD;
	if(b % 2 == 0)
		return n;
	return (n * a) % MOD;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%lld %lld", &a, &b);
		printf("%lld\n", mod_pow(a, b));
	}
	return 0;
}
