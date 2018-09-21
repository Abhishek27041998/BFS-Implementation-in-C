#include<stdio.h>
#include<stdlib.h>

#define MAX 25

int queue[MAX], front, rear;

int n;

int visited[MAX];

struct node
{
	int v;
	
	struct node *next;
};

typedef struct node node;

node *adjList[MAX];

void init()
{
	for(int i = 0; i < MAX; i++)
	{
		adjList[i] = NULL;
		visited[i] = 0;	
	}
}


void enqueue(int n)
{
	if(rear == MAX - 1)
		printf("Queue Full\n");
	else
		queue[rear++] = n;
}

int isEmpty()
{
	if(front > rear)
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
		
	return queue[front++];
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
		
		if(num != 0)
			printf("\nEnter the Vertices Number adjacent to %d : ",i);
		for(int j = 0; j < num; j++)
		{
			scanf("%d",&v);

			if(v > -1 && v < n)
			{
				node *Node = (node*)malloc(sizeof(node));

				Node->v = v;
				Node->next = NULL;
		
				if(adjList[i] == NULL)
					adjList[i] = Node;
				else
				{
					Node->next = adjList[i];
	
					adjList[i] = Node;
				}
			}			
			else
			{
				printf("Invalid edge\n");
				j--;
			}
		}

	}
}

void bfs(int ver)
{
	enqueue(ver);

	visited[ver] = 1;

	while(!isEmpty())
	{
		int vertex = dequeue();

		printf("\n%d",vertex);

		node *temp = adjList[vertex];
		
		while(temp != NULL)
		{
			int adjV = temp->v;
			
			if(visited[adjV] == 0)
			{
				enqueue(adjV);
				//printf("Added %d in queue\n",adjV);
				visited[adjV] = 1;
			}			
			temp = temp->next;
		}
	
	}	
}

int main()
{
	init();

	read_graph();
	
	bfs(0);
	
	return 0;
}

