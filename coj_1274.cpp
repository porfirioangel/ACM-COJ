#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

typedef vector<int> vi;

vi cr;
int i, md, n, c, contador, pM, j;
long long d;
bool m[10000];
int pis[1239];

void criba(int tam) {
	m[0] = false;
	m[1] = false;
	for( i = 2; i <= tam; ++i)
		m[i] = true;
	for( i = 2; i * i <= tam; ++i)
		if(m[i])
			for(int h = 2; i * h <= tam; ++h)
				m[i * h] = false;
	for( i = 0; i <= tam; ++i)
		if(m[i] == true)
			cr.push_back(i);
}

void pri(int a) {
	if(a > 99) printf("%d",a);
	else if(a > 9) printf(" %d",a);
	else if(a > 0) printf("  %d",a);
	else printf("   ");
}

int main() {
	criba(10000);
	scanf("%d", &n);
	while(n) {
		memset(pis, 0, sizeof(pis));
		pri(n);
		printf("! =");
		c=0;
		contador = 0;
		d = n;
		pM = 0;
		for(j = n; j >= 1; j--) {
			i = j;
			c = 0;
			contador = 0;
			while(i > 1) {
				if(i % cr[c] != 0) {
					pis[c] = pis[c] + contador;
					if(pM < c) pM = c;
					contador = 0;
					c++;
				} else {
					i = i / cr[c];
					contador++;
				}
			}
			pis[c] = pis[c] + contador;
			if(pM < c) pM = c;
		}
		for(i = 0; i <= pM; i++) {
			if(i % 15 == 0 && i!=0) printf("\n      ");
			pri(pis[i]);
		}
		printf("\n");
		scanf("%d", &n);
	}
	return 0;
}