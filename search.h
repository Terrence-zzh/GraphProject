#ifndef SEARCH_H
#define SEARCH_H

#include <stdio.h>
#include <stdlib.h>

int visit[1000000];
int path[1000000];
int a[1000000];
int dist[1000000];
int flag[1000000];

typedef struct anode{      //�߽��
	int number;            //�յ���
	struct anode *next;
	int longth;            //Ȩ��
}Node;

typedef struct vnode{      //ͷ�ڵ�
	Node *next;   //ָ���һ����
}Vnode;

typedef struct{
	Vnode adj[1000000];
	int n;         //����
}graph;


void print(graph *G);      //��ӡ�ڽӱ�
void dfs(graph *G, int u, int v);
void read(graph *G, char *filename);
void bfs(graph *G, int u, int v);
void Dijkstra(graph *G, int u, int v);
void printpath(int u, int v);

#endif // SEARCH_H
