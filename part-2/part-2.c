#include <stdio.h>
#include <stdbool.h>
int main(int argc, char** argv){
	bool add;
	if(argc==1)
		return 0;
	add = (argv[1] == '+');
	int size = 0;
	//char key[] = argv.slice(3);
	for(int i=3; i<argc; i++){
		size = size + sizeof(argv[i]);
	}
	char key[size];
	int index = 0;
	for(int i=3; i<argc; i++){
		for(int j=0;j<sizeof(argv[i]);j++)
			key[index++] = argv[i][j];
	}
	
	

	FILE *infile = stdin;
	FILE *outfile = stdout;
	while(!feof(infile)){
		char *c = fgetc(infile);

	}
	


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
