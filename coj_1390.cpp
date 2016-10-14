#include <cstdio>
#include <vector>
#include <set>

using namespace std;

#define LIM 200001

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vb criba;
vll primos;
int N, max, m;

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

vi prime_factors(int n) {
	vi facts;
	int pf_idx = 0;
	int pf = primos[pf_idx];
	while(n != 1 && (pf * pf) <= n) {
		while(!(n % pf)) {
			n /= pf;
			facts.push_back(pf);
		}
		pf = primos[++pf_idx];
	}
	if(n != 1) facts.push_back(n);
	return facts;
}

int main() {
	seive(LIM);
	scanf("%d", &N);
	vi facts;
	int aux, cow, maxPf = -1;
	while(N--) {
		scanf("%d", &m);
		if(m == 1)
			aux = 0;
		else {
            facts = prime_factors(m);
            int l = facts.size();
            aux = facts[l - 1];
        }
        if(maxPf < aux){
            cow = m;
            maxPf = aux;
        }
        facts.clear();
	}
	printf("%d\n", cow);
}
