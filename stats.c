#include "stats.h"
#define N 1000000

//显示菜单
void menu() {
	printf("--menu--\n");
	printf("Input -h or --help for more information!\n");
	printf("Input -g or --graph for more functions\n");
	printf("Input -sp to continue\n");
	printf("./search-cli -g ./sx-stackoverflow.txt -sp Dijkstra -u 1 -v 5\n");
}
//ya
int strcmp(char *str1, char *str2)
{
    int j;
    int i;
    for (i = 0; (*(str1 + i) != '\0') && (*(str2 + i) != '\0'); i++) {
        j = *(str1 + i) - *(str2 + i);
        if (j > 0) {
            return 1;
        }else if(j == 0){
            continue;
        }else {
            return -1;
        }
    }
    if(j == 0){
        return 0;
    }
}
//借鉴于https://blog.csdn.net/second60/article/details/80504365
char *strcpy(char *strDest, const char *strSrc)
{
    char *p=NULL;
    if(strDest == NULL || strSrc == NULL){
        return NULL;
    }
    p = strDest;
    while((*strDest++ = *strSrc++) != '\0');
    return p;
}

//https://blog.csdn.net/enjoymyselflzz/article/details/81167970?utm_source=blogxgwz1
void *memset(void *dest, int set, long long int len)
{
	if (dest == NULL || len < 0)
	{
		return NULL;
	}
    char *pdest = (char *)dest;
	while (len-->0)
	{
		*pdest++ = set;
	}
	return dest;
}

//返回文件图的边
int numberOfEdges(char name[])
{
    FILE *fp = NULL;
    fp = fopen(name, "r");
    char str[N + 1];
    if((fp == NULL)) {
        printf("Fail to open file!\n");
        exit(0);
    }
    int edges = 0;
    while (fgets(str,N,fp) != NULL){
        edges++;
    }
    return  (edges / 2);
    fclose(fp);
}
//返回文件图的顶点
int numberOfVertices(char name[])
{
    FILE *fp = NULL;
    fp = fopen(name, "r");
    if((fp == NULL)) {
        printf("Fail to open file!\n");
        exit(0);
    }
    int vertices = 0;
    int i, j, k;
    int max = 0, p;
    while (fscanf(fp,"%d%d%d", &i, &j, &k) != EOF){
	    freeman_num[i]++;
        p = i > j ? i : j;
        max = p > max ? p : max;
    }
    return (max + 1);
    fclose(fp);
}

float freemanNetworkCentrality(char name[])
{
    memset(freeman_num, 0, sizeof(freeman_num));
    long long sum = 0;
    long long max = 0;
    long long n = (long long)numberOfVertices(name);
    for (int i = 0; i < n; i++)
    {
        if (freeman_num[i] > max)
        {
            max = freeman_num[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        sum += max - freeman_num[i];
    }
	    return sum / (float)((n - 1) * (n - 2));
}
