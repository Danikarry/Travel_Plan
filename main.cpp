// 01.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
#include <stdio.h>
#include <stdlib.h>
#include"struct.h"

void input(SqList L);
void minprice(int c, int* m, int s, int e, SqList L);
void mintime(int pt, int c, int* m, int s, int e, SqList L);
void timeprice(int pt, int c, int* m, int s, int e, SqList L);

int main() {
	int startpart, endpart;
	int i, j, k;
	int midcount = 0, plan = 0;
	SqList list;
	
	list.G = (Gragh*)malloc(100*sizeof(Gragh));//��̬����Ԥ�����С����ռ�
	
	printf("��ӭ��ʹ������·�߲�ѯϵͳ��\n\n");
	printf("�����������趨��11�����ж�Ӧ������:\n");
	printf("0.����  1.�Ϻ�  2.���  3.����  4.����  5.�Ͼ�  6.����  7.�ɶ�  8.�人  9.������  10.����\n\n");

	printf("�밴�������趨����������㣨���֣���");
	scanf("%d", &startpart);
	printf("�밴�������趨���������յ㣨���֣���");
	scanf("%d", &endpart);
	
	printf("���Ƿ�Ҫ�涨;�����У�����ǣ������1���������2��");
	scanf("%d", &i);
	if(i == 1) {
		printf("����������;�����и�����");
		scanf("%d", &midcount);
	} 
	
	int midpart[midcount+2];
	midpart[0] = startpart; //���������㣬���һ�����յ�
	midpart[midcount+1] = endpart;
	
	if(midcount > 0) {
		printf("�밴˳����������;�����б�ţ�");
		for(k = 1; k <= midcount; k++) {
			scanf("%d", &midpart[k]);
		}
	} //midpart����洢;��������ţ�������βΪ����յ�
	
	printf("��ѡ���������в���(���ٷ��ò��������1������ʱ����������2���ڹ涨ʱ��������������������3)��");
    scanf("%d", &plan);
    input(list);
	if(plan == 1) {
		minprice(midcount, &midpart[0], startpart, endpart, list);
	}
	else {
		int plantime;
		printf("���������ƻ��ĳ���ʱ�䣨24Сʱ�ƣ�����Сʱ��������");
		scanf("%d", &plantime);
		
		if(plan == 2) {
			mintime(plantime, midcount, &midpart[0], startpart, endpart, list);
		}
		else if(plan == 3) {
			timeprice(plantime, midcount, &midpart[0], startpart, endpart, list);
		}
	}
	
	return 0;
}
