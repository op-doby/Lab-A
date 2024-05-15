#include <stdio.h>
#include <stdbool.h>
#include <string.h>
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
	bool add;
	int size =0;
	char key[size];
	FILE *infile = stdin;
	FILE *outfile = stdout;
	if(argc > 1){
		for(int i=1; i<argc; i++){
			if(mystrlen(argv[i]>2)){
				if(argv[i][0]=="-"){
					if(argv[i][1]=='e'){
						add = false;
						size = mystrlen(argv[1])-2;	
						if(size > 0)
		 					mystrcpy(key, &argv[i][2]);// copying the rest of the string to the key  
					}
					if(argv[i][1]=='I') 
						infile=fopen(argv[i][2],"w");
					if(argv[i][1]=='O') 
						outfile=fopen(argv[i][2],"r");
				}
				else 
					if(argv[i][0]=="+"){
						add = true;
						size = mystrlen(argv[1])-2;	
						if(size > 0)
		 					mystrcpy(key, &argv[i][2]);// copying the rest of the string to the key 
					}
			}

		}		
	}
	int i=0;
	int c;
	int out;
	while(!feof(infile)){ 
		c = fgetc(infile);
		if((argc>1)&& (((c <= 'z') & (c >= 'a'))||((c >= '0') & (c <= '9')))){ // the first condition is due to the assumption
			if(((c <= 'z') & (c >= 'a'))){
				if(add)
					fputc(97+(c+key[i]-48-97)%26,outfile);
				else 
				{
					out = c-97-key[i]+48;
					(out<0) ? fputc(97+26+out,outfile) :  fputc(97+out,outfile);
				}
			}
			else {
				if(((c >= '0') & (c <= '9'))){
					if(add)
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
			fputc(c,outfile);
	}
	return 0;
}




