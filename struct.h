/*��ͨ������Ϣ�ṹ��*/
typedef struct{
	int price;      //�ý�ͨ�����������ط���
	int stime;		//�ý�ͨ���߳���ʱ��
	int etime;		//�ý�ͨ���ߵ���ʱ��
	int overday;    //��;��Խ��Ȼ�������
	char no[10];	//��ͨ���߰�α��
}elem;

/*��ͨ���߱�ṹ��*/
typedef struct{
	elem elem[5];   //�������ؿ��ý�ͨ�����������
}datatype;

/*ͼ�Ľṹ��*/
typedef struct{
	datatype trans[11][11];	//�������صĽ�ͨ������Ϣ
	char vex[11][5];
}Gragh;


/*˳ʽ��*/
typedef struct{
	Gragh *G;		//ָ������Ԫ�ص�ָ��
	int length;		//˳���ǰ���ȣ���ͼ�ĸ���
}SqList;
