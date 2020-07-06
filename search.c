#include "search.h"

void printpath(int u, int v)
{
    int i;
	for(i = 0; i < 1000000; i++){
		a[i] = -1;
	}
	a[0] = v;
    for(i = 1; i < 1000000; i++){
    	a[i] = path[v];
    	v = path[v];
    	if(u == v){
    		break;
		}
	}
	for( ; i > -1; i--){
		if(i == 0){
			printf("%d\n", a[i]);
		}else{
			printf("%d->", a[i]);
		}
	}
	return;
}

void print(graph *G)
{
	Node *p;
	for(int i = 0; i < 1000000; i++){
		if(G->adj[i].next != NULL){
			printf("%d->", i);
			p = G->adj[i].next;
			while(p != NULL){
				printf("%d->", p->number);
				p = p->next;
			}
			printf("#");
			printf("\n");
		}
	}
}
void read(graph *G, char *filename)
{
	int input;
	FILE *fp;
	Node *p;          //±ßjieµã
	if(!(fp = fopen(filename , "r"))){
		printf("can not open file!");
	}
	G->n = 0;
	for (int i = 0; i < 1000000; i++){
		G->adj[i].next = NULL;
	}
	while(1 == fscanf(fp, "%d", &input)) {
		p = (Node *)malloc(sizeof(Node));
		fscanf(fp, "%d", &p->number);
		fscanf(fp, "%d", &p->longth);
		p->next = G->adj[input].next;
		G->adj[input].next=p;
		G->n++;
	}
}

void dfs(graph *G, int u, int v)
{
	for(int i = 0; i < 1000000; i++){
		visit[i] = 0;
		path[i] = -1;
	}
	int t = -1, x, w;
	Node *p;
	visit[u] = 1;
	t++;
	path[t] = u;
	while(t > -1){
		x = path[t];
		p = G->adj[x].next;
		while(p != NULL){
			w = p->number;
			if(visit[w] == 0){
				visit[w] = 1;
				t++;
				path[t] = w;
				if(w == v){
					return;
				}
				break;
			}
			p = p->next;
		}
		if(p == NULL)  t--;
	}
}

void bfs(graph *G, int u, int v)
{
    int min,k;
    Node *p;
    for(int i = 0; i < 1000000; i++){
    	dist[i] = 99999;
    	path[i] = -1;
    	flag[i] = 0;
	}
	dist[u] = 0;
	for(int i = 0; i < 1000000; i++){
		flag[u] = 1;
		p = G->adj[u].next;
		min = 99999;
		while(p != NULL){
			if(flag[p->number] == 0 && (p->longth + dist[u])< dist[p->number]){
				dist[p->number] = p->longth + dist[u];
				path[p->number] = u;
			}
			p = p->next;
		}
		for(int i = 0; i < 1000000; i++){
			if(flag[i] == 0 && dist[i] < min){
				k = i;
				min = dist[i];
			}
		}
		u = k;
		if(u == v){
			return;
		}
	}
}

void Dijkstra(graph *G, int u, int v)
{
    int min,k;
    Node *p;
    for(int i = 0; i < 1000000; i++){
    	dist[i] = 99999;
    	path[i] = -1;
    	flag[i] = 0;
	}
	dist[u] = 0;
	for(int i = 0; i < 1000000; i++){
		flag[u] = 1;
		p = G->adj[u].next;
		min = 99999;
		while(p != NULL){
			if(flag[p->number] == 0 && (p->longth + dist[u])< dist[p->number]){
				dist[p->number] = p->longth + dist[u];
				path[p->number] = u;
			}
			p = p->next;
		}
		for(int i = 0; i < 1000000; i++){
			if(flag[i] == 0 && dist[i] < min){
				k = i;
				min = dist[i];
			}
		}
		u = k;
		if(u == v){
			return;
		}
	}
}
