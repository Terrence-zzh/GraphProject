#ifndef STATS_H
#define STATS_H

#include <stdio.h>
#include <stdlib.h>

int freeman_num[1000000];

int strcmp(char *str1, char *str2);          //字符串比较函数
int numberOfEdges(char name[]);              //求边
int numberOfVertices(char name[]);           //求点
void menu();                                 //菜单函数
char *strcpy(char *strDest, const char *strSrc); //字符串粘贴
float freemanNetworkCentrality(char name[]); //Freeman's Network Centrality
void *memset(void *dest, int set, long long int len);

#endif //STATS_H

