#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int main(int argc, char** argv){
	bool add;
	int size =0;
	if(argc > 1){
		add = (argv[1][0] == '+');
		size = strlen(argv[1])-2;		
		//char key[]; //override
		//strcpy(key, &argv[1][2]); // copying the rest of the string to the key (i need the integers) 
	}
	char key[size];
	if(size > 0)
		 strcpy(key, &argv[1][2]);// copying the rest of the string to the key (i need the integers) 
	printf("%s",key);
	FILE *infile = stdin;
	FILE *outfile = stdout;
	int i=0;
	int sign = add ? 1 : -1; 
	int c;
	while(!feof(stdin)){ 
		c = fgetc(infile);
		if((argc>1)&& (((c <= 'z') & (c >= 'a'))||((c >= '0') & (c <= '9')))){ // the first condition is due to the assumption
			if(((c <= 'z') & (c >= 'a'))){ 
				if(c=='z') 
					fputc(('a'+ (sign)*key[i]-1-97)%26,outfile);
				else
					fputc((c+(sign)*key[i]-97)%26,outfile); 
			}
			else {
				if(((c >= '0') & (c <= '9'))){
					if(c=='9')
						fputc(('0'+(sign)*key[i]-1-48)%10,outfile);
					else 
						fputc((c+((sign)*key[i]-48)%10)%10,outfile); // need to check- the last thing i did 
				}
			}				
				i = (i==strlen(key)) ? 0 : i+1;
		}
		else
			fputc(c,outfile);

	}
	return 0;
}
