#include<iostream>
#include<climits>
#define I INT_MAX

using namespace std;

int edges[3][9] = {{1, 1, 2, 2, 3, 4, 4, 5, 5},
	{2, 6, 3, 7, 4, 5, 7, 6, 7},
	{25, 5, 12, 10, 8, 16, 14, 20, 18}
};
int set[8] = { -1, -1, -1, -1, -1, -1, -1, -1};
int included[9] = {0};
int t[2][6];

void Union(int u, int v) {
	if (set[u] < set[v]) {
		set[u] = set[u] + set[v];
		set[v] = u;
	}
	else {
		set[v] = set[u] + set[v];
		set[u] = v;
	}
}

int find(int u) {
	int x = u;
	while (set[x] > 0) {
		x = set[x];
	}
	return x;
}

int main() {
	int i, j, k, u, v, min = I, n = 7 , e = 9;

	i = 0;
	//while loop is running 6 tie coz we have to select 6 edges
	while (i < n - 1) {
		min = I;
		//finding min edge from edges array
		for (j = 0; j < e; j++) {
			if (included[j] == 0 && edges[2][j] < min) {
				min = edges[2][j];
				u = edges[0][j];
				v = edges[1][j];
				k = j;
			}
		}

		//checking for cycle
		if (find(u) != find(v)) {
			t[0][i] = u;
			t[1][i] = v;
			Union(find(u), find(v)); //
			i++;
		}

		included[k] = 1;
	}

	for (i = 0; i < n - 1; i++) {
		cout << "(" << t[0][i] << "," << t[1][i] << ")" << endl;
	}

	return 0;
}