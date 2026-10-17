#include<stdio.h>
#define MAX 20

int graph[MAX][MAX];
int n;
int directed;
char vertexNames[MAX];

void initializeGraph(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            graph[i][j]=0;
        }
    }
}

void assignVertexNames(int n){
    for(int i=0;i<n;i++){
        vertexNames[i]='A'+i;
    }
}

int getIndex(char name){
    for(int i=0;i<n;i++){
        if(vertexNames[i]==name)
            return i;
    }
    return -1;
}

void addEdgeByName(char srcName,char destName,int weight){
    int source=getIndex(srcName);
    int destination=getIndex(destName);

    if(source==-1 || destination==-1){
        printf("Invalid Vertex\n");
        return;
    }

    graph[source][destination]=weight;

    if(directed==0){
        graph[destination][source]=weight;
    }
}

void displayGraph(){
    int i,j;

    printf("    ");

    for(i=0;i<n;i++){
        printf("%4c",vertexNames[i]);
    }

    printf("\n");

    for(i=0;i<n;i++){
        printf("%4c",vertexNames[i]);

        for(j=0;j<n;j++){
            printf("%4d",graph[i][j]);
        }

        printf("\n");
    }
}

void checkEdgeByName(char srcName,char destName){
    int source=getIndex(srcName);
    int destination=getIndex(destName);

    if(source==-1 || destination==-1){
        printf("Invalid Vertex\n");
        return;
    }

    if(graph[source][destination]!=0){
        printf("Edge Exist. Weight=%d\n",graph[source][destination]);
    }
    else{
        printf("Edge Doesnot Exist.\n");
    }
}

int main(){

    int choice;
    int weight;
    char src,dest;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    if(n<=0 || n>MAX){
        printf("Invalid number of vertices.\n");
        return 0;
    }

    printf("0 - For Undirected Graph\n");
    printf("1 - For Directed Graph\n");
    printf("Enter Graph Type: ");
    scanf("%d",&directed);

    if(directed!=0 && directed!=1){
        printf("Invalid Graph Type.\n");
        return 0;
    }

    initializeGraph(n);
    assignVertexNames(n);

    do{
        printf("\n\n1. Add Edge");
        printf("\n2. Display Graph");
        printf("\n3. Check Edge");
        printf("\n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){

            case 1:
                printf("Enter source vertex: ");
                scanf(" %c",&src);

                printf("Enter destination vertex: ");
                scanf(" %c",&dest);

                printf("Enter weight: ");
                scanf("%d",&weight);

                addEdgeByName(src,dest,weight);
                break;

            case 2:
                displayGraph();
                break;

            case 3:
                printf("Enter source vertex: ");
                scanf(" %c",&src);

                printf("Enter destination vertex: ");
                scanf(" %c",&dest);

                checkEdgeByName(src,dest);
                break;

            case 0:
                printf("Program Ended.\n");
                break;

            default:
                printf("Invalid Choice.\n");
        }

    }while(choice!=0);

    return 0;
}