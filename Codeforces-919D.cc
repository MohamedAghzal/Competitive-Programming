#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int N = 300005;
int f[N][26];

int main() {
  int n, m; 
	scanf("%d %d", &n, &m);

	string s; cin >> s;
  s = '*' + s;

	for(int i = 1; i <= n; i++){
		f[i][s[i] - 'a']++;
	}

	vector <vector<int>> g(n + 1);
	vector <int> in_deg(n + 1, 0);
	for(int i = 0; i < m; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		g[x].push_back(y);
		in_deg[y]++;
	}

	queue <int> Q;
	for(int i = 1; i <= n; i++){
		if(!in_deg[i]){
			Q.push(i);
		}
	}
  
	int cnt = 0;
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		for(auto e: g[u]){
			--in_deg[e];
			if(!in_deg[e]){
				Q.push(e);
			}
			for(int i = 'a'; i <= 'z'; i++){
				int a = i - 'a';
				f[e][a] = max(f[e][a], f[u][a] + (s[e] == i));
			}
		}
		cnt++;
	}
	if(cnt != n){
		printf("-1");
		return 0;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 'a'; j <= 'z'; j++){
			ans = max(ans, f[i][j - 'a']);
		}
	}
	printf("%d", ans);
  return 0;
}
