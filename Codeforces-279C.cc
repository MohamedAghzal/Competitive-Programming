#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

void update(vector <int> &f, int idx, int val){
	for(int i = idx; i < f.size(); i += i & -i){
		f[i] += val;
	}
}

int get(vector <int> &f, int idx){

	int sum = 0;
	for(int i = idx; i > 0; i -= i & -i){
	   sum += f[i];
	}
	return sum;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector <int> v(n);

	for(int i = 0; i < n; i++){
		cin >> v[i];
	}

	vector <int> u(n + 1, 0);
	vector <int> d(n + 1, 0);

	for(int i = 1; i < n; i++){
		if(v[i] > v[i - 1]){
			update(d, i + 1, 1);
		}

		if(v[i] < v[i - 1]){
			update(u, i + 1, 1);
		}
	}

	while(m--){
		int l, r;
		cin >> l >> r;
		int left = l, right = r + 1;
		
		while(left < right){
			int mid = (left + right) / 2;
			if(get(u, mid) - get(u, l) == 0){
				left = mid;
			} else {
				right = mid;
			}
			if(left + 1 >= right) break;
		}

		if(get(d, r) - get(d, left) == 0){
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}

	return 0;
}
