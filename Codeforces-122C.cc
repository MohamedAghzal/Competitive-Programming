#include <bits/stdc++.h>

using namespace std;

vector <long long> lucky;

void gen(long long i, long long n){
	if(i > n * 10 + 48) return;
	if(i != 0){
		lucky.push_back(i);
	}
	gen(i * 10 + 4, n);
	gen(i * 10 + 7, n);
}

int main() {	
	long long l, r;
	scanf("%lld %lld", &l, &r);
	
	gen(0, r);
	
	sort(lucky.begin(), lucky.end());	
	long long ans = 0;
	int i;
	
	if(binary_search(lucky.begin(), lucky.end(), l)){
	   i = lower_bound(lucky.begin(), lucky.end(), l) - lucky.begin();
	} else {
	   i = upper_bound(lucky.begin(), lucky.end(), l) - lucky.begin();
	}
	while(lucky[i] < r){
	   ans += (long long) lucky[i] * (lucky[i] - l + 1);
		l = lucky[i++] + 1;
	}
   
	printf("%lld", ans + (long long) lucky[i] * (r - l + 1));
	return 0;
}
