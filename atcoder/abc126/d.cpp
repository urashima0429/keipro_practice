#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1e5;
struct edge{ int to, weight; };
vector<edge> Edges[MAX_N + 10];

int dir[MAX_N];

void dfs(int vertex, int parent, int distance){
	dir[vertex] = distance;
	for (auto e : Edges[vertex]){
		if (e.to == parent) continue;
		dfs(e.to, vertex, distance + e.weight);
	}
}

int main(){
	int N;
	cin >> N;
	for (int i = 0; i < N-1; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		--u; --v;
		Edges[u].push_back(edge{v, w});
		Edges[v].push_back(edge{u, w});
	}

	dfs(0, -1, 0);
	for (int i = 0; i < N; ++i){
		if (dir[i] & 1){
			cout << 1 << endl;
		}else{
			cout << 0 << endl;
		}
	}
}