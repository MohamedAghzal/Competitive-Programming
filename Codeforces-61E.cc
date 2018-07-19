#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int N = int(1e6) + 5;

void update(vector <long long> &f, long long idx, long long val){
	for(long long i = idx; i < f.size(); i += i & (-i)){
		f[i] += val;
	}
}

long long get_sum(vector <long long> &f, long long idx){
	long long sum = 0;
	for(long long i = idx; i > 0; i -= i & (-i)){
		sum += f[i];
	}
	return sum;
}
int main() {
	int n;
	cin >> n;
	vector <long long> seq(n);
	for(int i = 0; i < n; i++){
		cin >> seq[i];
	}
	vector <long long> sorted = seq;
	sort(sorted.begin(), sorted.end());
	int maxx = *max_element(seq.begin(), seq.end());
	maxx = min(maxx, N);
	vector <long long> f(maxx + 1, 0);
	vector <long long> g(maxx + 1, 0);
	vector <long long> L(n + 1);
	vector <long long> R(n + 1);
	for(int i = 0; i < n; i++){
		int l = lower_bound(sorted.begin(), sorted.end(), seq[i]) - sorted.begin() + 1;
		int r = lower_bound(sorted.begin(), sorted.end(), seq[n - i - 1]) - sorted.begin() + 1;
		L[i] = get_sum(f, n) - get_sum(f, l);
		R[n - i - 1] = get_sum(g, r);
		update(f, l, 1);
		update(g, r, 1);
	}
	long long ans = 0;
	for(int i = 0; i < n; i++){
		ans += (long long) R[i] * L[i];
	}
	cout << ans;
	return 0;
}
