#include <cstdio>
#include <vector>

using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vi> vvi;

vb criba;
vll primos;
int t;
long long m, n;
bool divisible;

void seive(long long limite){
	criba.assign(limite, true);
	criba[0] = criba[1] = false;
	for(long long i = 2; i < limite; i++)
		if(criba[i]) {
			for(long long j = i * i; j < limite; j += i)
				criba[j] = false;
			primos.push_back(i);
		}
}

int main() {
	seive(100000);
	scanf("%d", &t);
	while(t--) {
		scanf("%lld %lld", &m, &n);
		for(long long i = m; i <= n; i++) {
			divisible = 0;
			for(int j = 0; j < (int) primos.size(); j++) 
				if(i != 1 && i != primos[j] && !(i % primos[j])) {
					divisible = 1;
					break;
				}
			if(!divisible)
				printf("%lld\n", i);
		}
		printf("\n");
	}
	return 0;
}
