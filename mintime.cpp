#include<stdio.h>
#include"struct.h"

void mintime(int pt, int c, int* m, int s, int e, SqList L) {
	int i, j, k, count;
	int time, arvtime[11];
	int temp, temp1, temp2, temp3 = 0;
	int v[11], D[11][11], path[11][11];
	
	for(i = 0; i < 11; i++) {
		for(j = 0; j < 11; j++){
			D[i][j] = -1;
		}
	}
	arvtime[s] = pt;    //到达起点的时间 <- 旅客计划出发时间
	
	for(j = 0; j < 11; j++) {
		for(k = 1; (k < 5) && (j != s); k++) {
			if(L.G[0].trans[s][j].elem[k].stime < arvtime[s]) {    //arvtime[i]:上一班次到达 i 地的时间
				L.G[0].trans[s][j].elem[k].stime+=24;
				L.G[0].trans[s][j].elem[k].etime+=24;
			}	//班次出发时刻早于到达该地的时间:第二天出发
			
			if((L.G[0].trans[s][j].elem[k].etime + (L.G[0].trans[s][j].elem[k].overday * 24)) < \
				(L.G[0].trans[s][j].elem[0].etime + (L.G[0].trans[s][j].elem[0].overday * 24))) {
					L.G[0].trans[s][j].elem[0] = L.G[0].trans[s][j].elem[k];
			}	//把顺序表的第一个元素放置为到达时刻最早的班次
		}
		L.G[0].trans[s][j].elem[0].etime += arvtime[s] - (arvtime[s] % 24); //实际到达时间
		
		arvtime[j] = L.G[0].trans[s][j].elem[0].etime;  //到达 j 地的最早时间
		D[s][j] = arvtime[j] - arvtime[s];	//以两地到达时间差作为耗时，并以此为弧的值
	}
	
	for(i = 0; i < 11; i++) {
		if(arvtime[i] < 0) {
			continue;
		}
		for(j = 0; j < 11; j++) {
			if((L.G[0].trans[i][j].elem[1].etime == 32767) || (j == s)) {
				D[i][j] = 32767;
				continue;
			}
			for(k = 1; (k < 5) && (i != j); k++) {
				if(L.G[0].trans[i][j].elem[k].stime < (arvtime[i] % 24)) {
					L.G[0].trans[i][j].elem[k].stime += 24;
					L.G[0].trans[i][j].elem[k].etime += 24;
				}
				if((L.G[0].trans[i][j].elem[k].etime + (L.G[0].trans[i][j].elem[k].overday * 24)) < \
					(L.G[0].trans[i][j].elem[0].etime + (L.G[0].trans[i][j].elem[0].overday * 24))) {
						L.G[0].trans[i][j].elem[0] = L.G[0].trans[i][j].elem[k];
				}
			}
			L.G[0].trans[i][j].elem[0].etime += arvtime[i] - (arvtime[i] % 24);
			arvtime[j] = L.G[0].trans[i][j].elem[0].etime;
			if((D[i][j] > (arvtime[j] - arvtime[i])) || (D[i][j] < 0)) {
				D[i][j] = arvtime[j] - arvtime[i];
			}
		}
	}
	for(i = 0; i < 11; i++) {
		for(j = 0; j < 11; j++) {
			if((D[i][j] < 32767) && (D[i][j] > 0) && (i != j)) {
				path[i][j] = i;
			}
			else {  //两地间无直达班次或 i=j
				path[i][j] = -1;
				D[i][j] = 32767;
			}
		}
	}
	
	for(k = 0; k < 11; k++) {
		for(i = 0; i < 11; i++) {
			for(j = 0; j < 11; j++) {
				if((D[i][k] + D[k][j]) < D[i][j]) {
					D[i][j] = D[i][k]+D[k][j];
					path[i][j] = path[k][j];
				}
			}
		}
	}
	
	if(c == 0) {	//如果没有规定途径城市
		temp = e;
		count = 0;
		do {
			v[count] = temp;
			temp = path[s][v[count]];
			count++;
		} while(temp != s);
		count = count-1;
		printf("\n为您规划的路线为：");
		printf("%s ", L.G[0].vex[s]);
		for(i = count; i >=0 ; i--) {
			printf("%s ", L.G[0].vex[v[i]]);
		}
		printf("\n");
		printf("最小耗时为:%d小时", D[s][e]);
	}
	else {	//如果规定了途经城市
		printf("\n为您规划的路线为：");
		printf("%s ", L.G[0].vex[s]);
		for(j = 0; j <= c; j++) {
			count = 0;
			temp1 = m[j];
			temp2 = m[j+1];
			do {
				v[count] = temp2;
				temp2 = path[temp1][v[count]];
				count++;
			} while(temp2 != temp1);
			count = count-1;
			for(i = count; i >= 0; i--) {
				printf("%s ", L.G[0].vex[v[i]]);
			}
		}
		printf("\n");
		for(k = 0; k <= c; k++) {
			time = temp3 + D[m[k]][m[k+1]];
			temp3 = time;
		}
		printf("最小耗时为:%d小时", time);
	}
}
