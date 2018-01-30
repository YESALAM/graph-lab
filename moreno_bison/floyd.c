#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


#define size 27
#define start 1
#define max 65536


int printSolution(int dist[size][size]);
void readFileandReturnGraph(int* graph);


int g[size][size];
int dist[size][size];


int main(){

	clock_t c_time ;
	c_time = clock();
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
		    g[i][j] = 0 ;
		    dist[i][j] = max ;
		}
    	}

	readFileandMakeGraph(g);
	floyd(g,dist);

    //printSolution(dist);

	c_time = clock()-c_time;
	double time_taken = ((double)c_time)/CLOCKS_PER_SEC;
	printf("Time taken is %f\n",time_taken);
	return 0;
}

void floyd(int g[size][size],int dist[size][size]){
    for(int i=0;i<size;i++){
        dist[i][i] = 0 ;
    }

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
		if(g[i][j] == 0) continue ;
            dist[i][j] = g[i][j] ;
        }
    }



    for(int k=start;k<size;k++){
        for(int i=start;i<size;i++){
            for(int j=start;j<size;j++){
                int temp = dist[i][k]+dist[k][j];
                if(dist[i][j]>temp){
                    if(i==j && temp<0){
                        printf("Negative cycle detected at node%d \n",i);
                        return;
                    }
                    dist[i][j] = temp ;
                }
                printf("\r K loop %d I loop %d J loop %d",k,i,j);
                fflush(stdout);
            }
        }
    }
    printf("\n");
}

void readFileandMakeGraph(int graph[size][size]){

	FILE* file_pt = fopen("out.moreno_bison_bison","r");
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
		int weight = abs(atoi(weight_c));
		graph[source][dest] = weight ;
	}
}





int printSolution(int dist[size][size])
{
   printf("NodeId   Minimum_Weight_Sum\n");
   for (int i = start; i < size; i++){
      for(int j=start;j<size;j++){
	printf("%d \t",dist[i][j]);
}
printf("\n");
}
}
