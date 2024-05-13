#include <stdio.h>
#include <stdbool.h>
int main(int argc, char** argv){
	bool debugMode = true;
	for( int i=1; i< argc; i++){
		if(debugMode){
			fprintf(stderr, "%s\n", argv[i]);
		}
		else
			printf("%s ",argv[i]);
		if(argv[i]=="+D")
			debugMode = true;
		if(argv[i]=="-D")
			debugMode = false;
	}
	printf("\n");
	return 0;
}
