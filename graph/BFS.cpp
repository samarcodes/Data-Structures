#include<iostream>
#include<queue>

using namespace std;

void BFS(int G[][7], int start, int n) {
	int i = start;
	queue <int> q;
	int visited[7] = {0};

	cout << i << " ";
	visited[i] = 1;
	q.push(i);

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v = 1; v < 7; v++) {
			if (G[u][v] == 1 && visited[v] == 0) {
				cout << v << " ";
				visited[v] = 1;
				q.push(v);
			}
		}
	}
	cout << endl;
}

void DFS(int G[][7], int start, int n) {
	static int visited[7] = {0};

	if (visited[start] == 0) {
		cout << start << " ";
		visited[start] = 1;

		for (int j = 1; j < n; j++) {
			if (G[start][j] == 1 && visited[j] == 0) {
				DFS(G, j, n);
			}
		}
	}
}

int main() {
	int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 1, 1, 0, 0},
		{0, 1, 0, 1, 0, 1, 0},
		{0, 1, 1, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 1, 1},
		{0, 0, 1, 0, 1, 0, 0},
		{0, 0, 0, 0, 1, 0, 0}
	};

	DFS(G, 1, 7);

	return 0;
}