#include <stdio.h>
#include <stdbool.h>
int main(int argc, char** argv){
	bool debugMode = true;
	for( int i=1; i< argc; i++){
		if(debugMode)
			fprintf(stderr, "debug mode: %s\n", argv[i]);
		else
			printf("%s",argv[i]);
		if((argv[i][0]=='+') && (argv[i][1]=='D') && (argv[i][2]==(char)0))
			debugMode = true;
		if((argv[i][0]=='-') && (argv[i][1]=='D') && (argv[i][2]==(char)0))
			debugMode = false;
	}
	printf("\n");
	return 0;
}
