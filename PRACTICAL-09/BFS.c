#include<stdio.h>
#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];

int front=-1;
int rear=-1;

void enqueue(int vertex){
    if(rear==MAX-1){
        printf("Queue Overflow\n");
        return;
    }

    if(front==-1)
        front=0;

    queue[++rear]=vertex;
}

int dequeue(){
    int vertex=queue[front];

    if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        front++;
    }

    return vertex;
}

void BFS(int start,int n){

    int current;

    enqueue(start);
    visited[start]=1;

    while(front!=-1){

        current=dequeue();

        printf("%c ",current+'A');

        for(int i=0;i<n;i++){

            if(graph[current][i]==1 && visited[i]==0){

                enqueue(i);
                visited[i]=1;
            }
        }
    }
}

int main(){

    int n,edges;
    char u,v,start;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    if(n<=0 || n>MAX){
        printf("Invalid number of vertices\n");
        return 0;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            graph[i][j]=0;
        }

        visited[i]=0;
    }

    printf("Enter number of edges: ");
    scanf("%d",&edges);

    for(int i=0;i<edges;i++){

        printf("Enter edge: ");
        scanf(" %c %c",&u,&v);

        graph[u-'A'][v-'A']=1;
        graph[v-'A'][u-'A']=1;
    }

    printf("Enter starting vertex: ");
    scanf(" %c",&start);

    printf("BFS Traversal: ");

    BFS(start-'A',n);

    printf("\n");

    return 0;
}