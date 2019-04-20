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
	arvtime[s] = pt;    //��������ʱ�� <- �ÿͼƻ�����ʱ��
	
	for(j = 0; j < 11; j++) {
		for(k = 1; (k < 5) && (j != s); k++) {
			if(L.G[0].trans[s][j].elem[k].stime < arvtime[s]) {    //arvtime[i]:��һ��ε��� i �ص�ʱ��
				L.G[0].trans[s][j].elem[k].stime+=24;
				L.G[0].trans[s][j].elem[k].etime+=24;
			}	//��γ���ʱ�����ڵ���õص�ʱ��:�ڶ������
			
			if((L.G[0].trans[s][j].elem[k].etime + (L.G[0].trans[s][j].elem[k].overday * 24)) < \
				(L.G[0].trans[s][j].elem[0].etime + (L.G[0].trans[s][j].elem[0].overday * 24))) {
					L.G[0].trans[s][j].elem[0] = L.G[0].trans[s][j].elem[k];
			}	//��˳���ĵ�һ��Ԫ�ط���Ϊ����ʱ������İ��
		}
		L.G[0].trans[s][j].elem[0].etime += arvtime[s] - (arvtime[s] % 24); //ʵ�ʵ���ʱ��
		
		arvtime[j] = L.G[0].trans[s][j].elem[0].etime;  //���� j �ص�����ʱ��
		D[s][j] = arvtime[j] - arvtime[s];	//�����ص���ʱ�����Ϊ��ʱ�����Դ�Ϊ����ֵ
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
			else {  //���ؼ���ֱ���λ� i=j
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
	
	if(c == 0) {	//���û�й涨;������
		temp = e;
		count = 0;
		do {
			v[count] = temp;
			temp = path[s][v[count]];
			count++;
		} while(temp != s);
		count = count-1;
		printf("\nΪ���滮��·��Ϊ��");
		printf("%s ", L.G[0].vex[s]);
		for(i = count; i >=0 ; i--) {
			printf("%s ", L.G[0].vex[v[i]]);
		}
		printf("\n");
		printf("��С��ʱΪ:%dСʱ", D[s][e]);
	}
	else {	//����涨��;������
		printf("\nΪ���滮��·��Ϊ��");
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
		printf("��С��ʱΪ:%dСʱ", time);
	}
}
