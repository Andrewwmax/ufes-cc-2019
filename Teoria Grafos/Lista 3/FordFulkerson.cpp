#include <iostream> 
#include <limits.h> 
#include <string.h> 
#include <queue> 
using namespace std; 

#define V 10

bool bfs(int rGraph[V][V], int s, int t, int parent[]){ 
	bool visited[V]; 
	memset(visited, 0, sizeof(visited)); 

	queue <int> q; 
	q.push(s); 
	visited[s] = true; 
	parent[s] = -1; 

	while (!q.empty()){ 
		int u = q.front(); 
		q.pop(); 

		for (int v=0; v<V; v++){
			if (visited[v]==false && rGraph[u][v] > 0){ 
				q.push(v); 
				parent[v] = u; 
				visited[v] = true;
			} 
		} 
	} 
	return (visited[t] == true); 
} 

int fordFulkerson(int graph[V][V], int s, int t){
	int u, v; 
	int rGraph[V][V];
	
	for (u = 0; u < V; u++) 
		for (v = 0; v < V; v++) 
			rGraph[u][v] = graph[u][v]; 
	
	int parent[V];
	int max_flow = 0;
	
	while (bfs(rGraph, s, t, parent)){
		int path_flow = INT_MAX; 
		for (v=t; v!=s; v=parent[v]){
			u = parent[v]; 
			path_flow = min(path_flow, rGraph[u][v]); 
			printf("%d, ", path_flow);
		} 

		for (v=t; v != s; v=parent[v]){
			u = parent[v]; 
			rGraph[u][v] -= path_flow; 
			rGraph[v][u] += path_flow; 
		}
		max_flow += path_flow; 
	}
	return max_flow; 
} 

int main(){
	// int graph[V][V] = { {0, 16, 13, 0, 0, 0}, 
	// 					{0, 0, 10, 12, 0, 0}, 
	// 					{0, 4, 0, 0, 14, 0}, 
	// 					{0, 0, 9, 0, 0, 20}, 
	// 					{0, 0, 0, 7, 0, 4}, 
	// 					{0, 0, 0, 0, 0, 0} 
	// 				}; 
	int graph[V][V];
	graph[0][1] = 10;
	graph[0][2] = 10;
	graph[0][3] = 10;

	graph[1][2] = 5;
	graph[1][5] = 8;
	
	graph[2][3] = 9;
	graph[2][4] = 10;
	graph[2][5] = 9;
	
	graph[3][4] = 9;
	
	graph[4][6] = 9;
	graph[4][7] = 7;
	graph[4][8] = 9;
	
	graph[5][4] = 6;
	graph[5][6] = 9;
	graph[5][8] = 8;
	
	graph[6][7] = 10;
	graph[6][9] = 10;
	
	graph[7][5] = 9;
	graph[7][9] = 10;
	
	graph[8][7] = 9;
	graph[8][9] = 10;

	cout << "The maximum possible flow is " << fordFulkerson(graph, 0, 9); 

	return 0; 
} 
