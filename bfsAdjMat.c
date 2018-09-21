#include<stdio.h>
#include<stdlib.h>

#define MAX 25

struct Queue
{
	int data[MAX];
	int front,rear;
};

typedef struct Queue queue;

int visited[MAX];

int adjMat[MAX][MAX];

int n,e;

queue q;

void init()
{
	for(int i = 0; i < MAX; i++)
	{
		visited[i] = 0;

		for(int j = 0; j < MAX; j++)
		{
			adjMat[i][j] = 0;
		
			if(i == j )
				adjMat[i][j] = -1;
		}
	}

	q.front = q.rear = 0;
}

void enqueue(int n)
{
	if(q.rear == MAX - 1)	
		printf("Queue Full\n");
	else
		q.data[q.rear++] = n;
}


int isEmpty()
{
	if(q.front > q.rear)
		return 1;
	return 0;
}

int dequeue()
{
	if(isEmpty())
	{
		printf("Queue Empty\n");
		return -9999;
	}		

	return q.data[q.front++];	
			
}

void read_graph()
{
	printf("Enter number of vertices : ");
	scanf("%d",&n);

	int num;

	for(int i = 0; i < n; i++)
	{
		printf("\nEnter number of vertices adjacent to %d : ",i);
		scanf("%d",&num);
		int v;

		printf("\nEnter the Vertices Number adjacent to %d : \n",i);
		for(int j = 0; j < num; j++)
		{
			scanf("%d",&v);

			if(v > -1 && v < n)
				adjMat[i][v] = 1;
			else
			{
				printf("Invalid edge\n");
				j--;
			}
		}

	}
}


void bfs(int v)
{
	enqueue(v);

	visited[v] = 1;

	while(!isEmpty())
	{
		int ver = dequeue();

		printf("\n%d",ver);

		for(int i = 0; i < n; i++)
		{
			if(adjMat[ver][i] == 1 && (visited[i] == 0))
			{
				visited[i] = 1;
				enqueue(i);
			}
		}
	}

}

void displayAdjMat()
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			printf("%d ",adjMat[i][j]);

}

int main()
{
	init();

	read_graph();

	//printf("Adjacency matrix ...\n");
	
	//displayAdjMat();

	bfs(0);

	return 0;
}
