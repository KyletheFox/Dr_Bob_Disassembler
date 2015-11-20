#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disassembler.h"

void getInstruction(int);
char *getStrSpace(int);

int main(int argc, char *argv[]) {
	unsigned int ip;
	unsigned int acc;
	FILE *fp;

	// Open File
	if ((fp=fopen(argv[1], "r"))==NULL) {
      		printf("ERROR: File Doesn't Exist\n");
      		exit(1);
    	}

	do {
		fscanf(fp, "%d %d", &ip, &acc);
		printf("%3d %d ", ip, acc);
		getInstruction(acc);
	} while (!feof(fp));

	fclose(fp);

	return 0;
}

char *getStrSpace(int a) {
		char *temp;
		
		// Malloc temp
		if ((temp = (char*)malloc((a+1)*sizeof(char))) == NULL)	{
			printf("ERROR\n");
			exit(2);
		}

		return temp;	
}

void getInstruction(int acc) {
	char temp;
	char temp2;
	char *tempStr;

	temp = acc/1000;

	switch(temp) {
		case HALT:
			temp = acc%1000;
			tempStr = getStrSpace(4);
			tempStr = "HALT";
		case LD:
			temp = acc%1000;
			tempStr = getStrSpace(4);
			sprintf(tempStr, "LD %d", temp);
			break;
		case ST:
			temp = acc%1000;
			tempStr = getStrSpace(4);
			sprintf(tempStr, "ST %d", temp);
			break;
		case ADD:
			temp = acc%1000;
			tempStr = getStrSpace(5);
			sprintf(tempStr, "ADD %d", temp);
			break;
		case SUB:
			temp = acc%1000;
			tempStr = getStrSpace(5);
			sprintf(tempStr, "SUB %d", temp);
			break;
		case LDA:
			temp = acc%1000;
			tempStr = getStrSpace(5);
			sprintf(tempStr, "LDA %d", temp);
			break;
		case JMP:
			temp = acc%1000;
			tempStr = getStrSpace(5);
			sprintf(tempStr, "JMP %d", temp);
			break;
		case SKIPSET:

			temp2 = acc%1000;
			temp2 /= 100;
			
			switch(temp2) {
				case SKIP:
					temp%=10;
					tempStr = getStrSpace(8);
					sprintf(tempStr, "SKIP %%r%d", temp);
					break;
				case SKEQ:
					temp%=10;
					tempStr = getStrSpace(8);
					sprintf(tempStr, "SKEQ %%r%d", temp);
					break;
				case SKNE:
					temp%=10;
					tempStr = getStrSpace(8);
					sprintf(tempStr, "SKNE %%r%d", temp);
					break;
				case SKGT:
					temp%=10;
					tempStr = getStrSpace(8);
					sprintf(tempStr, "SKGT %%r%d", temp);
					break;
				case SKGE:
					temp%=10;
					tempStr = getStrSpace(8);
					sprintf(tempStr, "SKGE %%r%d", temp);
					break;
				case SKLT:
					temp%=10;
					tempStr = getStrSpace(8);
					sprintf(tempStr, "SKLT %%r%d", temp);
					break;
				case SKLE:
					temp%=10;
					tempStr = getStrSpace(8);
					sprintf(tempStr, "SKLE %%r%d", temp);
					break;		
			}
			break;
		case ONEREG:

			temp2 = acc%1000;
			temp2 /= 100;

			switch(temp2) {
					case IN:
						temp%=10;
						tempStr = getStrSpace(5);
						sprintf(tempStr, "IN %%r%d", temp);
						break;
					case OUT:
						temp%=10;
						tempStr = getStrSpace(6);
						sprintf(tempStr, "OUT %%r%d", temp);
						break;
					case CLR:
						temp%=10;
						tempStr = getStrSpace(6);
						sprintf(tempStr, "CLR %%r%d", temp);
						break;
					case INC:
						temp%=10;
						tempStr = getStrSpace(6);
						sprintf(tempStr, "INC %%r%d", temp);
						break;
					case DEC:
						temp%=10;
						tempStr = getStrSpace(6);
						sprintf(tempStr, "DEC %%r%d", temp);
						break;
					case NEG:
						temp%=10;
						tempStr = getStrSpace(6);
						sprintf(tempStr, "NEG %%r%d", temp);
						break;
					case SHFTL:
						temp%=10;
						tempStr = getStrSpace(9);
						sprintf(tempStr, "SHFTL %%r%d", temp);
						break;	
					case SHFTR:
						temp%=10;
						tempStr = getStrSpace(9);
						sprintf(tempStr, "SHFTR %%r%d", temp);
						break;			
				}		
			break;

		// Not correct. Need to get two regesitries. For Debug purposes only
		case TWOREG:
			temp2 = acc%1000;
			temp2 /= 100;

			switch(temp2) {
					case MVRR:
						temp%=10;
						tempStr = getStrSpace(12);
						sprintf(tempStr, "MVRR %%r%d", temp);
						break;
					case MVMR:
						temp%=10;
						tempStr = getStrSpace(12);
						sprintf(tempStr, "MVMR %%r%d", temp);
						break;
					case MVRM:
						temp%=10;
						tempStr = getStrSpace(12);
						sprintf(tempStr, "MVRM %%r%d", temp);
						break;
					case EXCH:
						temp%=10;
						tempStr = getStrSpace(12);
						sprintf(tempStr, "EXCH %%r%d", temp);
						break;
					case ADDR:
						temp%=10;
						tempStr = getStrSpace(12);
						sprintf(tempStr, "ADDR %%r%d", temp);
						break;
					case SUBR:
						temp%=10;
						tempStr = getStrSpace(12);
						sprintf(tempStr, "SUBR %%r%d", temp);
						break;
			}
			break;		
		}
			printf("%s\n", tempStr);		

}