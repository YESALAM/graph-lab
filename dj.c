#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

#define size 9
#define start 0
#define max 65536

int mindist(int distance[],int visited[]);
int printSolution(int dist[]);
void readFileandReturnGraph(int* graph);





int main(){

    int g[size][size] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
    int dist[size];
    int visited[size];



	clock_t c_time ;
	c_time = clock();


	readFileandMakeGraph(g);
	dijkstra(g,dist,visited);
	printSolution(dist);
	c_time = clock()-c_time;
	double time_taken = ((double)c_time)/CLOCKS_PER_SEC;
	printf("Time taken is %f\n",time_taken);
	return 0;
}

void dijkstra(int g[size][size],int dist[size],int visited[size]){

	for(int i=0;i<size;i++){
		dist[i] = INT_MAX ;
		visited[i] = 0;
	}

	dist[start] = 0 ;
	for(int i = start;i<size-1;i++){
		int u = mindist(dist,visited);
		visited[u] = 1;
		for(int j=start;j<size;j++){
			if(!visited[j] && dist[u]!=max && g[u][j]){
				if(dist[j]>dist[u]+g[u][j]) dist[j] = dist[u] + g[u][j];
			}
		}

	}
}

int mindist(int distance[],int visited[]){
	int min_index ;
	int current_min = max ;
	for(int i=start;i<size;i++){
		if(visited[i]==0 && distance[i]<=current_min){
			min_index = i ;
			current_min = distance[i];
		}
	}
	return min_index;

}

void readFileandMakeGraph(int graph[size][size]){

	FILE* file_pt = fopen("soc-sign-bitcoinotc.csv","r");
	char line[1024];
	while(fgets(line,1024,file_pt)){
		char* source_c ;
		char* dest_c ;
		char* weight_c ;

		char* temp = strdup(line);
		const char* tok;
 		tok = strtok(line,",");
		source_c = tok ;
		dest_c = strtok(NULL,",");
		weight_c = strtok(NULL,",");


		int source = atoi(source_c);
		int dest = atoi(dest_c);
		int weight = atoi(weight_c);
		graph[source][dest] = weight ;
		free(tmp);
	}
}





int printSolution(int dist[])
{
   printf("NodeId   MinmumRating\n");
   for (int i = start; i < size; i++)
      printf("%d \t\t %d\n", i, dist[i]);
}
