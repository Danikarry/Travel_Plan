/*交通工具信息结构体*/
typedef struct{
	int price;      //该交通工具往返两地费用
	int stime;		//该交通工具出发时刻
	int etime;		//该交通工具到达时刻
	int overday;    //旅途跨越自然天的天数
	char no[10];	//交通工具班次编号
}elem;

/*交通工具表结构体*/
typedef struct{
	elem elem[5];   //往返两地可用交通工具种类个数
}datatype;

/*图的结构体*/
typedef struct{
	datatype trans[11][11];	//往返两地的交通工具信息
	char vex[11][5];
}Gragh;


/*顺式表*/
typedef struct{
	Gragh *G;		//指向数据元素的指针
	int length;		//顺序表当前长度，即图的个数
}SqList;
