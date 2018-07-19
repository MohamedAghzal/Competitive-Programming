#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <unordered_map>
#include <algorithm>

using namespace std;
vector <long long> is_square;

void generate_squares(void){
	is_square.push_back(0);
	is_square.push_back(1);
	for(long long i = 2; i * i <= int(1e10); i++){
		is_square.push_back(i * i);
	}
}

int main() {
	int n; cin >> n;
	vector <int> v(n);

	for(auto &e: v){
		cin >> e;
	}

	generate_squares();
	vector <long long> squares;
	vector <long long> not_squares;
	unordered_map <long long, long long> cost;

	for(int i = 0; i < n; i++){
		int idx = lower_bound(is_square.begin(), is_square.end(), v[i]) - is_square.begin();
		if(is_square[idx] == v[i]){
			squares.push_back(v[i]);
		} else {
			not_squares.push_back(v[i]);
			cost[v[i]] = min(v[i] - is_square[idx - 1], is_square[idx] - v[i]);
		}
	}

	sort(squares.begin(), squares.end());
	sort(not_squares.begin(), not_squares.end(), [&](int a, int b){
		return cost[a] < cost[b];
	});

	int cnt_squares = (int) squares.size();
	int cnt_notsquares = (int) not_squares.size();

	long long ans = 0;
	if(cnt_squares == cnt_notsquares){
	   cout << 0;
	   return 0;
	}
	if(cnt_squares > cnt_notsquares){
		for(int i = cnt_squares - 1; i >= 0; i--){
			if(squares[i] > 0){
				ans++;
			} else {
				ans += 2;
			}
			cnt_notsquares++;
			if(cnt_notsquares == n / 2) break;
		}
	} else {
		for(int i = 0; i < cnt_notsquares; i++){
			ans += cost[not_squares[i]];
			cnt_squares++;
			if(cnt_squares == n / 2) break;
		}
	}
	cout << ans;

	return 0;
}
