#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ",");
            tok && *tok;
            tok = strtok(NULL, ","))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}



int main()
{
    FILE* stream = fopen("soc-sign-bitcoinalpha.csv", "r");

    char line[1024];
    while (fgets(line, 1024, stream))
    {
        char* tmp = strdup(line);
	char get[4][1024] ;

	const char* tok;
 	tok = strtok(line,",");
	printf(tok);
	printf("\t");
	while(tok!=NULL){
		printf("\t");
		tok = strtok(NULL,",");
		printf(tok);
		
	}
	printf("\n");
	//getfield2(tmp,get);

	
        //printf("%s\t%s\t%s\n", ,getfield(tmp,1),getfield(tmp,2));
        // NOTE strtok clobbers tmp
        free(tmp);
    }
}
