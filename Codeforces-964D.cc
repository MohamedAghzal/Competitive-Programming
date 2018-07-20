#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <unordered_map>
#include <set>

using namespace std;
unordered_map <int, int> depth;

struct cmp{
    bool operator()(const int &l,const int &r) const{
        return depth[l] < depth[r];
    }
};

void dfs(vector <vector<int>> &g, int v, int d, int cur){
	depth[v] = d;
	for(auto e: g[v]){
		if(e != cur){
			dfs(g, e, d + 1, v);
		}
	} 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

  int n; cin >> n;
	if(!(n & 1)){
		cout << "NO";
		return 0;
	}
	vector <vector<int>> g(n + 1);
	vector <int> deg(n + 1, 0);
	int root;
	for(int u = 1; u <= n; u++){
		int v; cin >> v;
		if(v){
			g[v].push_back(u);
			g[u].push_back(v);
			deg[u]++;
			deg[v]++;
		} else {
			root = u;
		}
	}

	dfs(g, root, 0, 1);

	priority_queue <int, vector <int>, cmp> Q;
	for(int i = 1; i <= n; i++){
		if(!(deg[i] & 1)){
			Q.push(i);
		}
	}

	vector <int> constructed;
	unordered_map <int, bool> destroyed;
	unordered_map <int, bool> bad;
	while(!Q.empty()){
		int u = Q.top();
		Q.pop();
		if(bad[u] || destroyed[u]) continue;
		constructed.push_back(u);
		destroyed[u] = true;

		for(int v: g[u]){
			if(destroyed[v]) continue;
			deg[v]--;
			if(!(deg[v] & 1)){
				 Q.push(v);
				 bad[v] = false;
			}
			else bad[v] = true;
		}
	}

	cout << "YES" << endl;
	for(int e: constructed){
		cout << e << endl;
	}

	return 0;
}
