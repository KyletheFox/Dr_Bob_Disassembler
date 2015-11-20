#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disassembler.h"

void getInstruction(int, char *);

int main(int argc, char *argv[]) {
	unsigned int ip;
	unsigned int acc;
	char *temp;
	FILE *fp;

	// Open File
	if ((fp=fopen(argv[1], "r"))==NULL) {
      		printf("ERROR: File Doesn't Exist\n");
      		exit(1);
    	}
	
	// Malloc tempreset
	if ((temp = (char*)malloc(10*sizeof(char))) == NULL)	{
		printf("ERROR\n");
		exit(2);
	}

	do {
		fscanf(fp, "%d %d", &ip, &acc);
		printf("%3d %d ", ip, acc);
		getInstruction(acc, temp);
	} while (!feof(fp));

	fclose(fp);

	return 0;
}

void getInstruction(int acc, char *tempStr) {
	char temp;
	char temp2;

	temp = acc/1000;

	switch(temp) {
		case HALT:
			temp = acc%1000;
			tempStr = "HALT";
		case LD:
			temp = acc%1000;
			sprintf(tempStr, "LD %d", temp);
			break;
		case ST:
			temp = acc%1000;
			sprintf(tempStr, "ST %d", temp);
			break;
		case ADD:
			temp = acc%1000;
			sprintf(tempStr, "ADD %d", temp);
			break;
		case SUB:
			temp = acc%1000;
			sprintf(tempStr, "SUB %d", temp);
			break;
		case LDA:
			temp = acc%1000;
			sprintf(tempStr, "LDA %d", temp);
			break;
		case JMP:
			temp = acc%1000;
			sprintf(tempStr, "JMP %d", temp);
			break;
		case SKIPSET:
			
			temp = acc%1000;
			temp /= 100;
			
			switch(temp) {
				case SKIP:
					temp%=10;
					sprintf(tempStr, "SKIP %%r%d", temp);
					break;
				case SKEQ:
					temp%=10;
					sprintf(tempStr, "SKEQ %%r%d", temp);
					break;
				case SKNE:
					temp%=10;
					sprintf(tempStr, "SKNE %%r%d", temp);
					break;
				case SKGT:
					temp%=10;
					sprintf(tempStr, "SKGT %%r%d", temp);
					break;
				case SKGE:
					temp%=10;
					sprintf(tempStr, "SKGE %%r%d", temp);
					break;
				case SKLT:
					temp%=10;
					sprintf(tempStr, "SKLT %%r%d", temp);
					break;
				case SKLE:
					temp%=10;
					sprintf(tempStr, "SKLE %%r%d", temp);
					break;		
			}
			break;
		case ONEREG:

		temp = acc%1000;
		temp /= 100;

		switch(temp) {
				case IN:
					temp%=10;
					sprintf(tempStr, "IN %%r%d", temp);
					break;
				case OUT:
					temp%=10;
					sprintf(tempStr, "OUT %%r%d", temp);
					break;
				case CLR:
					temp%=10;
					sprintf(tempStr, "CLR %%r%d", temp);
					break;
				case INC:
					temp%=10;
					sprintf(tempStr, "INC %%r%d", temp);
					break;
				case DEC:
					temp%=10;
					sprintf(tempStr, "DEC %%r%d", temp);
					break;
				case NEG:
					temp%=10;
					sprintf(tempStr, "NEG %%r%d", temp);
					break;
				case SHFTL:
					temp%=10;
					sprintf(tempStr, "SHFTL %%r%d", temp);
					break;	
				case SHFTR:
					temp%=10;
					sprintf(tempStr, "SHFTR %%r%d", temp);
					break;			
			}		
			break;
		case TWOREG:
			
			break;		
		}
			printf("%s\n", tempStr);		

	

}