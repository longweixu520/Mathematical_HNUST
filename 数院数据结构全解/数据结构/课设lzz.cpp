#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#define INF 65535
#define MAXSIZE 20
#define Status int
#define VerType char
#define  ArcType int


//----------以无向图邻接矩阵形式存储图中信息----------// 
typedef struct ArcCell{
	ArcType Arcinfo;
}ArcCell,AdjMatrix[MAXSIZE][MAXSIZE];
typedef struct Vexinfo{
	int number;
	VerType name[65];
}VexCell;
typedef struct {
	VexCell vexs[MAXSIZE];
	AdjMatrix arcs;
	int vexnum,arcnum;
}MGraph;

//-------------------函数引用 -----------------------// 
Status Create (MGraph &G);
int Menu(); 

void ShortestPathFLOYD(MGraph G,int P[][MAXSIZE],int S[][MAXSIZE]);
Status FShortdis(MGraph G);
void display(MGraph G,int i,int j);

Status ShortestPashDIJ(MGraph G,int v0,int P[MAXSIZE],int D[MAXSIZE]);
Status DShortdis(MGraph G);
void print(MGraph G,int i);

//----------------定义全局变量 ---------------------// 
MGraph Hunan;//定义图结构体 
int PathMatrix[MAXSIZE];//存储单源点最短路径 
int ShortPathTable[MAXSIZE];//存储单源点最短路径长度 
int shortest[MAXSIZE][MAXSIZE];//存储一对源点最短路径长度
int path[MAXSIZE][MAXSIZE];//存储一对源点最短路径



//------------------存储算法------------------------//
Status Create (MGraph &G){
	//初始化图 
	int i,j,k;
	G.vexnum=12;
	G.arcnum=19;
	for(i=0;i<=G.vexnum;i++)
	G.vexs[i].number=i+1;
	for(i=0;i<G.vexnum;i++)
	for(j=0;j<G.vexnum;j++)
	G.arcs[i][j].Arcinfo=INF;
	
	//存入图的信息 
	strcpy(G.vexs[0].name,"岳阳");
	strcpy(G.vexs[1].name,"张家界");
	strcpy(G.vexs[2].name,"常德");
	strcpy(G.vexs[3].name,"益阳");
	strcpy(G.vexs[4].name,"长沙");
	strcpy(G.vexs[5].name,"湘潭");
	strcpy(G.vexs[6].name,"娄底");
	strcpy(G.vexs[7].name,"衡阳");
	strcpy(G.vexs[8].name,"邵阳");
	strcpy(G.vexs[9].name,"怀化");
	strcpy(G.vexs[10].name,"永州");
	strcpy(G.vexs[11].name,"郴州");
	G.arcs[0][1].Arcinfo=257;
	G.arcs[0][2].Arcinfo=144;
	G.arcs[0][4].Arcinfo=157;
	G.arcs[1][9].Arcinfo=173;
	G.arcs[2][3].Arcinfo=83;
	G.arcs[2][9].Arcinfo=232;
	G.arcs[3][4].Arcinfo=68;
	G.arcs[3][6].Arcinfo=96;
	G.arcs[3][9].Arcinfo=258;
	G.arcs[4][5].Arcinfo=42;
	G.arcs[5][6].Arcinfo=94;
	G.arcs[5][7].Arcinfo=110;
	G.arcs[6][8].Arcinfo=70;
	G.arcs[7][8].Arcinfo=115;
	G.arcs[7][11].Arcinfo=138;
	G.arcs[8][9].Arcinfo=153;
	G.arcs[8][10].Arcinfo=89;
	G.arcs[9][10].Arcinfo=207;
	G.arcs[10][11].Arcinfo=164;
	
	for(i=0;i<G.vexnum;i++)
		for(j=0;j<G.vexnum;j++)
		G.arcs[j][i].Arcinfo=G.arcs[i][j].Arcinfo;
	return 0;
}


//-----------------Dijkstra算法----------------// 
Status ShortestPashDIJ(MGraph G,int v0,int P[MAXSIZE],int D[MAXSIZE]){
	int v,min,w,k;
	int final[MAXSIZE];
	//数组初始化
	 for(v=0;v<G.vexnum;v++)
	 {
	 	final[v]=0;//全部顶点初始状态为未找到路径
		D[v]=G.arcs[v0][v].Arcinfo;//将与v0有边的路径加上权值 
		P[v]=-1;//初始化路径数组为0 
		}
	 
	 D[v0]=0;
	 final[v0]=1;
	 
	 //算法主循环
	 for(v=1;v<G.vexnum;v++)//其余G.vexnum-1个顶点
	  {
	  	min=INF;
	  	for(w=0;w<G.vexnum;w++){
	  		if(!final[w]&&D[w]<min){
	  			k=w;
	  			min=D[w];
			  }
		  }
		final[k]=1;
		for(w=0;w<G.vexnum;w++){
			if(!final[w]&&(G.arcs[k][w].Arcinfo+min)<(D[w]))
			{
			D[w]=min+G.arcs[k][w].Arcinfo;
			P[w]=k;
			}
		  }
	  }
}

//-------------打印Dijkstra最短路径-----------------// 
void print(MGraph G,int i){
	int t,p,w;
	printf("已为您查询到%s到各地的最短路径如下：\n\n",G.vexs[i].name);
	for(t=0;t<G.vexnum;t++){
		p=t;
		if(t!=i){
			printf("%s",G.vexs[t].name);
			for(w=0;w<G.vexnum;w++){
				if(PathMatrix[p]!=-1){
					printf("<--%s",G.vexs[PathMatrix[p]].name);
					p=PathMatrix[p];
				}
			}
			printf("<--%s",G.vexs[i].name);
			printf("\n总路线长度为%d\n\n",ShortPathTable[t]);
		}
	}
}

//-----------用户输入与调用Dijkstra算法------------// 
Status DShortdis(MGraph G){
	int v0=-1,t,p,w;
	char s[65];

	printf("请输入您要查询的起始地址");
	printf("(输入1退出):");
	scanf("%s",&s);
	getchar();
	if(strcmp("1",s)==0)
	return 0;
	printf("\n");
	while(v0==-1){
		for(int i=0;i<G.vexnum;i++)
		if(strcmp(G.vexs[i].name,s)==0)
		{
			v0=i;
			break;
		}
		if(v0==-1){
		printf("您输入的地址未查询到，请重新输入：");
		scanf("%s",&s);
		getchar();
		printf("\n");
		} 
	}
	ShortestPashDIJ(G,v0,PathMatrix,ShortPathTable);//调用Dijkstra算法
	print(G,v0);//调用打印函数 
	return 1;
}

//------------------Floyd算法-------------------// 
void ShortestPathFLOYD(MGraph G,int P[][MAXSIZE],int S[][MAXSIZE]){
	int i,j,k;
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)
		{
			S[i][j]=G.arcs[i][j].Arcinfo;
			P[i][j]=j;
		}
	}

	for(k=0;k<G.vexnum;k++)
		for(i=0;i<G.vexnum;i++)
			for(j=0;j<G.vexnum;j++){
				if(S[i][j]>S[i][k]+S[k][j]){
					S[i][j]=S[i][k]+S[k][j];
					P[i][j]=P[i][k];
				}
			}
}

//--------------打印Floyd最短路径---------------// 
void display(MGraph G,int i,int j){
	int a,b;
	a=i;b=j;
	printf("您要查询的两地间最短路径为：\n\n");
	printf("%s",G.vexs[a].name);
	while(path[i][j]!=b){
		printf("-->%s",G.vexs[path[i][j]].name);
		i=path[i][j];
	}
	printf("-->%s\n\n",G.vexs[b].name);
	printf("%s到%s的最短路径长度是:%d\n\n",G.vexs[a].name,G.vexs[b].name,shortest[a][b]); 
}

//--------------用户输入与调用Floyd算法--------------//
Status FShortdis(MGraph G){
	int a=-1,b=-1;
	int i,j;
	char s1[65];
	char s2[65]; 
	printf("请输入您要查询的起点地址和终点地址");
	printf("(以空格隔开，输入1 1退出):");
	scanf("%s %s",&s1,&s2);
	getchar();
	
	if(strcmp("1",s1)==0&&strcmp("1",s2)==0)
	return 0;
	printf("\n");
	while(a==-1){
	for(int i=0;i<G.vexnum;i++)
		if(strcmp(G.vexs[i].name,s1)==0)
		{
			a=i;
			break;
		}
	if(a==-1){
		printf("您输入的起点地址未查询到，请重新输入起点地址：");
		scanf("%s",&s1);
		getchar();
		printf("\n");
		} 
	}
	while(b==-1){
	for(int j=0;j<G.vexnum;j++)
		if(strcmp(G.vexs[j].name,s2)==0)
		{
			b=j;
			break;
		}
	if(b==-1){
		printf("您输入的终点地址未查询到，请重新输入终点地址：");
		scanf("%s",&s2);
		getchar();
		printf("\n");
		} 
	}
	
	ShortestPathFLOYD(Hunan,path,shortest);//调用Floyd算法
	display(G,a,b);//调用打印函数 
}

//-------------菜单函数---------------// 
int Menu() {
	char a,b;
	while(1){
		system("cls");
	printf("\t-----路径选择菜单-----\n\n");
	printf("\t1.查询一点到多点距离\n\n");
	printf("\t2.查询一点到一点距离\n\n");
	printf("\t3.退出\n\n");
	printf("\t请选择您所需的操作:");
	
	while(1){
	scanf("%s",&a);
	getchar();
	printf("\n");
	if(a=='1')
	{
		system("cls");
		DShortdis(Hunan);

		system("pause");
		break;
	}
	else if(a=='2')
	{
		system("cls");
		FShortdis(Hunan);

		system("pause");
		break;
	}
	else if(a=='3'){
		break;
	} 
	else {
		printf("\t输入错误，请重新输入:");
	}
	}
	if(a=='3'){
		break;
	} 
}
}

int main(){
	Create(Hunan);
	Menu();
}
