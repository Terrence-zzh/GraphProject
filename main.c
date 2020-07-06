#include "stats.h"
#include "search.h"

int main(int argc, char *argv[]) {
    char temp[20];
    char temp2[20];
    char temp3[20];
    char temp4[20];
    char temp5[20];
    char temp6[20];
	char temp7[20];
    char name[20];
    char tempg[20];
    char tempgr[20];
    strcpy(temp, "-h");
    strcpy(temp2, "--help");
    strcpy(temp3, "DFS");
    strcpy(temp4, "Dijkstra");
    strcpy(temp5, "BFS");
    strcpy(temp6, "-j");
	strcpy(temp7, "freeman");
    if(strcmp(argv[1], temp6) == 0) {
        printf("\n");
		printf("¿¿¿¿¿¿¿|\n");
		printf("¿¿/¿7¿¿¿¿/\n");
		printf("¿ /¿¿¿¿ ¿¿¿\n");
		printf("¿¿¿Z ¿,¿¿¿¿¿ /`¿\n");
		printf("¿¿¿¿¿¿¿¿¿¿ /¿¿¿\n");
		printf("¿ Y¿¿¿¿¿`¿ /¿¿/\n");
		printf("¿?¿¿?¿¿¿¿??¿¿¿/\n");
		printf("¿()¿ ¿¿¿¿¿|¿¿¿\n");
		printf("¿¿>? ?_¿ ¿¿ ¿ ¿¿\n");
		printf("¿ / ¿¿¿ /¿?¿| ¿¿\n");
		printf("¿ ¿_?¿¿(_¿¿ ¿¿¿\n");

    }
    if(strcmp(argv[1], temp) == 0 || strcmp(argv[1], temp2) == 0){
        menu();
    }
    strcpy(tempg, "-g");
    strcpy(tempgr, "--graph");
    if(strcmp(argv[1], tempg) == 0 || strcmp(argv[1], tempgr) == 0){
        graph *G;
	    G = (graph *)malloc(sizeof(graph));
        strcpy(name, argv[2]);
        read(G, name);
		if(strcmp(temp7, argv[4]) == 0) {
            printf("The freemanNetworkCentrality of file is %f\n", freemanNetworkCentrality(name));
		}
        if(strcmp(temp3, argv[4]) == 0){
            int u = atoi(argv[6]);
            int v = atoi(argv[8]);
            dfs(G, u, v);
    	    for(int i = 0; i<1000000; i++){
	    	    if(path[i] == v){
	    		    printf("%d\n", path[i]);
	    		    break;
			    }else if(path[i] > -1){
    	    	    printf("%d->", path[i]);
	    	    }
    	    }
        }
        if(strcmp(temp4, argv[4]) == 0){
            int u = atoi(argv[6]);
            int v = atoi(argv[8]);
            Dijkstra(G, u, v);
            printpath(u, v);
        }
        if(strcmp(temp5, argv[4]) == 0){
            int u = atoi(argv[6]);
            int v = atoi(argv[8]);
            bfs(G, u, v);
            printpath(u, v);
        }
    }
	return 0;
}
