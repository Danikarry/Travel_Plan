#include<stdio.h>
#include"struct.h"

void minprice(int c, int* m, int s, int e, SqList L) {
	int i, j, k, count;
	int price;
	int temp, temp1, temp2, temp3 = 0;
	int v[11], D[11][11], path[11][11];

	for(i = 0; i < 11; i++) {	//把顺序表的第一个元素放置为价格最少的
		for(j = 0; j < 11; j++) {
			for(k = 1; (k < 5) && (i != j); k++) {
				if(L.G[0].trans[i][j].elem[k].price < L.G[0].trans[i][j].elem[0].price)
					L.G[0].trans[i][j].elem[0] = L.G[0].trans[i][j].elem[k];
			}
		}
	}
	for(i = 0; i < 11; i++) {
		for(j = 0; j < 11; j++) {
			D[i][j] = L.G[0].trans[i][j].elem[0].price;
			if((D[i][j] < 32767) && (i != j)) {
				path[i][j] = i;
			}
			else {
				path[i][j] = -1;
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
	if(c == 0) { //如果没有规定途径城市
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
		printf("最小费用为:%d元", D[s][e]);
	}
	else {//如果规定了途经城市
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
			price = temp3 + D[m[k]][m[k+1]];
			temp3 = price;
		}
		printf("最小费用为:%d元", price);
	}
}
