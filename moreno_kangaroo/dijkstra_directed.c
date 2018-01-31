#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>


#define size 18
#define start 1

int mindist(int distance[],int visited[]);
int printSolution(int dist[],int path[]);
void readFileandReturnGraph(int* graph);


int g[size][size]  ;
int dist[size];
int visited[size];
int path[size];

int main(){
	clock_t c_time ;
	c_time = clock();

	readFileandMakeGraph(g);
	dijkstra(g,dist,path,visited);
	printSolution(dist,path);
	c_time = clock()-c_time;
	double time_taken = ((double)c_time)/CLOCKS_PER_SEC;
	printf("Time taken is %f\n",time_taken);
	return 0;
}

void dijkstra(int g[size][size],int dist[size],int path[],int visited[size]){

	for(int i=0;i<size;i++){
		dist[i] = INT_MAX ;
		visited[i] = 0;
		path[i] = -1 ;
	}

	dist[start] = 0 ;

	for(int i = start;i<size-1;i++){
		int u = mindist(dist,visited);
		visited[u] = 1;
		for(int j=start;j<size;j++){
			if(!visited[j] && dist[u]!=INT_MAX && g[u][j]){
				if(dist[j]>dist[u]+g[u][j]) {
					dist[j] = dist[u] + g[u][j];
					path[j]= u ;
				}
			}
		}

	}
}

int mindist(int distance[],int visited[]){
	int min_index ;
	int current_min = INT_MAX ;
	for(int i=start;i<size;i++){
		if(visited[i]==0 && distance[i]<=current_min){
			min_index = i ;
			current_min = distance[i];
		}
	}

	return min_index;

}

void readFileandMakeGraph(int graph[size][size]){

	FILE* file_pt = fopen("out.moreno_kangaroo_kangaroo","r");
	char line[1024];
	while(fgets(line,1024,file_pt)){
        if(line[0] == '%') continue ;
		char* source_c ;
		char* dest_c ;
		char* weight_c ;

		char* temp = strdup(line);
		const char* tok;
 		tok = strtok(line," ");
		source_c = tok ;
		dest_c = strtok(NULL," ");
		weight_c = strtok(NULL," ");


		int source = atoi(source_c);
		int dest = atoi(dest_c);
		int weight = atoi(weight_c);
		graph[source][dest] = weight ;
	}
}


void printPath(int parent[], int j)
{   
    if (parent[j]==-1)
        return;

    printPath(parent, parent[j]);

    printf("%d-", j);
}


int printSolution(int dist[],int path[])
{
   printf("NodeId   MinmumRating\n");
   for (int i = start; i < size; i++){
      printf("%d \t\t %d \t\t", i, dist[i]);
      printPath(path,i);
	printf("\n");
}
}
