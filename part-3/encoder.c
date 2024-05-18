#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int mystrlen (char *str){
	if(str == (char*)NULL)
		return 0;
	int i=0;
	while (str[i]!=(char)0)
		i++;
	return i;
}

void mystrcpy (char* trg, char* src){
	if(src==(char*)NULL)
		return;
	int i=0;
	while(src[i]!=(char)0){
		trg[i]=src[i];
		i++;
	}
	trg[i]=(char)0;
}
int main(int argc, char** argv){
	int encode=0;
	int size =0;
	char *key = "";
	FILE *infile = stdin;
	FILE *outfile = stdout;
	bool debugMode = false;
	if(argc > 1){
		for(int i=1; i<argc; i++){
			if(debugMode)
				fprintf(stderr, "debug mode: %s\n", argv[i]);
			if((argv[i][0]=='+') && (argv[i][1]=='D') && (argv[i][2]==(char)0))
				debugMode = true;
			if((argv[i][0]=='-') && (argv[i][1]=='D') && (argv[i][2]==(char)0))
				debugMode = false;
			if(mystrlen(argv[i])>2){
				if(argv[i][0]=='-'){
					if(argv[i][1]=='e'){
						encode = -1;
						size = mystrlen(argv[i])-2;	
						key = (char *) malloc(size+1);
						if(debugMode)
							fprintf(stderr,"DEBUG: key argument size:%d\n", size);
						if(size > 0){
							if(debugMode)
								fprintf(stderr,"DEBUG: key argument:%s\n", (char *) &argv[i][2]);
		 					mystrcpy(key, &argv[i][2]);// copying the rest of the string to the key  
						}
						if(debugMode)
							fprintf(stderr,"DEBUG: Key:%s", key);
					}
					if(argv[i][1]=='I') {
						infile=fopen(&argv[i][2],"rb");
						if(infile==NULL){
							fprintf(stderr,"ERROR: couldn't open the in file! \n");
							return 1;
						}

					}
					if(argv[i][1]=='O') {
						outfile=fopen(&argv[i][2],"w");
						if(outfile==NULL){
							fprintf(stderr,"ERROR: couldn't open the in file! \n");
							return 1;
						}
					}
				}
				else 
					if((argv[i][0]=='+') && (argv[i][1]=='e')){
						encode = 1;
						size = mystrlen(argv[i])-2;	
						key = (char *) malloc(size+1);
						if(size > 0)
		 					mystrcpy(key, &argv[i][2]);// copying the rest of the string to the key 
						if(debugMode)
							fprintf(stderr,"DEBUG: Key:%s\n", key);
					}
			}

		}		
	}
	int i=0;
	int c;
	int out;
	while(!feof(infile)) {  // negative values indicate EOF
		c = fgetc(infile);
		if(debugMode)
			fprintf(stderr," DEBUG:%c\n", c);
		//need encoding, and it's a-z or 0-9
		if((encode!=0)&& (((c <= 'z') & (c >= 'a'))||((c >= '0') & (c <= '9')))){ // the first condition is due to the assumption
			if(((c <= 'z') & (c >= 'a'))){
				if(encode ==1)
					fputc(97+(c+key[i]-48-97)%26,outfile);
				else 
				{
					out = c-97-key[i]+48;
					(out<0) ? fputc(97+26+out,outfile) :  fputc(97+out,outfile);
				}
			}
			else {
				if(((c >= '0') & (c <= '9'))){
					if(encode ==1)
						fputc(48+(c+key[i]-2*48)%10,outfile);
					else
					{
						out = c-key[i];
						(out < 0) ? fputc(48+10+out,outfile) : fputc(48+out,outfile);
					}		
				} 
			}				
				i = (i== mystrlen(key)-1) ? 0 : i+1;
		}
		else
			if(c>=0)
				fputc(c,outfile);
	}
	return 0;
}




