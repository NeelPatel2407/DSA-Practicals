#include<stdio.h>
#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top=-1;

void push(int vertex){
    stack[++top]=vertex;
}

int pop(){
    return stack[top--];
}

void DFS(int start,int n){

    int current;

    push(start);

    while(top!=-1){

        current=pop();

        if(visited[current]==0){

            printf("%c ",current+'A');
            visited[current]=1;

            for(int i=n-1;i>=0;i--){
                if(graph[current][i]==1 && visited[i]==0){
                    push(i);
                }
            }
        }
    }
}

int main(){

    int n,edges;
    char u,v,start;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

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

    printf("DFS Traversal: ");
    DFS(start-'A',n);

    return 0;
}