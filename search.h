#ifndef SEARCH_H
#define SEARCH_H

#include <stdio.h>
#include <stdlib.h>

int visit[1000000];
int path[1000000];
int a[1000000];
int dist[1000000];
int flag[1000000];

typedef struct anode{      //边结点
	int number;            //终点编号
	struct anode *next;
	int longth;            //权重
}Node;

typedef struct vnode{      //头节点
	Node *next;   //指向第一条边
}Vnode;

typedef struct{
	Vnode adj[1000000];
	int n;         //边数
}graph;


void print(graph *G);      //打印邻接表
void dfs(graph *G, int u, int v);
void read(graph *G, char *filename);
void bfs(graph *G, int u, int v);
void Dijkstra(graph *G, int u, int v);
void printpath(int u, int v);

#endif // SEARCH_H
