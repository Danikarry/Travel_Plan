#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"struct.h"

void input(SqList L) {
	int Spart, Epart;
	int i, j, k;
	int count = 1;
	for(i = 0; i < 11; i++) {	//初始化邻接矩阵
		for(j = 0; j < 11; j++) {
			for(k = 0; k < 5; k++) {
				L.G[0].trans[i][j].elem[k].price = 32767;
				L.G[0].trans[i][j].elem[k].stime = 32767;
				L.G[0].trans[i][j].elem[k].etime = 32767;
				L.G[0].trans[i][j].elem[k].overday = 32767;
			}	
		}
	}
	strcpy(L.G[0].vex[0], "北京");
	strcpy(L.G[0].vex[1], "上海");
	strcpy(L.G[0].vex[2], "天津");
	strcpy(L.G[0].vex[3], "重庆");
	strcpy(L.G[0].vex[4], "广州");
	strcpy(L.G[0].vex[5], "南京");
	strcpy(L.G[0].vex[6], "西安");
	strcpy(L.G[0].vex[7], "成都");
	strcpy(L.G[0].vex[8], "武汉");
	strcpy(L.G[0].vex[9], "哈尔滨");
	strcpy(L.G[0].vex[10], "沈阳");
	FILE*fp;
	fp = fopen("input.txt", "r");
	for(i = 0; ; i++) {
		fscanf(fp, "%d %d", &Spart, &Epart);
		if((Spart < 0) || (Epart < 0)) {
			break;
		}
		while(L.G[0].trans[Spart][Epart].elem[count].price != 32767) {
			count++;
		} 
		fscanf(fp, "%d", &L.G[0].trans[Spart][Epart].elem[count].price);
		fscanf(fp, "%d", &L.G[0].trans[Spart][Epart].elem[count].stime);
		fscanf(fp, "%d", &L.G[0].trans[Spart][Epart].elem[count].etime);
		fscanf(fp, "%d", &L.G[0].trans[Spart][Epart].elem[count].overday);
		count = 1;
	}
	fclose(fp);			
}
