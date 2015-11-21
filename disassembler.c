#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disassembler.h"

void getInstruction(int, char);
char *getStrSpace(int);

int main(int argc, char *argv[]) {
	unsigned int ip;
	unsigned int acc;
	char start = 1;   // ignores first 0 ip
	char noHalt = 1;  // flag to determine if HALT has been called
	FILE *fp;

	// Open File
	if ((fp=fopen(argv[1], "r"))==NULL) {
      		printf("ERROR: File Doesn't Exist\n");
      		exit(1);
    	}

	while (!feof(fp)) {
		fscanf(fp, "%3d %4d", &ip, &acc);

		if (start || ip!=0) {
			printf("%03d %04d ", ip, acc);
			getInstruction(acc, noHalt);
			start = 0;
		}
		else
			printf("%03d\n", ip);

		//Determine if HALT has already been called
		if (acc == HALT) {
			noHalt = 0;
		}
	} 

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

void getInstruction(int acc, char noHalt) {
	int first, sec, third, forth;
	char *tempStr;

	// Separate each number
	first = acc/1000;
	sec = (acc/100)%10;
	third = (acc/10)%10;
	forth = acc%10;

	switch(first) {
		case HALT:
			if (noHalt) {
				tempStr = getStrSpace(4);
				tempStr = "HALT";
			}
			else {
				tempStr = getStrSpace(5);
				tempStr = ".word";
			}
			break;
		case LD:
			tempStr = getStrSpace(5);
			sprintf(tempStr, "LD %d%d", third, forth);
			break;
		case ST:
			tempStr = getStrSpace(5);
			sprintf(tempStr, "ST %d%d", third, forth);
			break;
		case ADD:
			tempStr = getStrSpace(6);
			sprintf(tempStr, "ADD %d%d", third, forth);
			break;
		case SUB:
			tempStr = getStrSpace(6);
			sprintf(tempStr, "SUB %d%d", third, forth);
			break;
		case LDA:
			tempStr = getStrSpace(6);
			sprintf(tempStr, "LDA %d%d", third, forth);
			break;
		case JMP:
			tempStr = getStrSpace(6);
			sprintf(tempStr, "JMP %d%d", third, forth);
			break;
		case SKIPSET:

			switch(sec) {
				case SKIP:
					tempStr = getStrSpace(8);
					sprintf(tempStr, "SKIP %%r%d", forth);
					break;
				case SKEQ:
					tempStr = getStrSpace(8);
					sprintf(tempStr, "SKEQ %%r%d", forth);
					break;
				case SKNE:
					tempStr = getStrSpace(8);
					sprintf(tempStr, "SKNE %%r%d", forth);
					break;
				case SKGT:
					tempStr = getStrSpace(8);
					sprintf(tempStr, "SKGT %%r%d", forth);
					break;
				case SKGE:
					tempStr = getStrSpace(8);
					sprintf(tempStr, "SKGE %%r%d", forth);
					break;
				case SKLT:
					tempStr = getStrSpace(8);
					sprintf(tempStr, "SKLT %%r%d", forth);
					break;
				case SKLE:
					tempStr = getStrSpace(8);
					sprintf(tempStr, "SKLE %%r%d", forth);
					break;		
			}
			break;
		case ONEREG:

			switch(sec) {
					case IN:
						tempStr = getStrSpace(5);
						sprintf(tempStr, "IN %%r%d", forth);
						break;
					case OUT:
						tempStr = getStrSpace(6);
						sprintf(tempStr, "OUT %%r%d", forth);
						break;
					case CLR:
						tempStr = getStrSpace(6);
						sprintf(tempStr, "CLR %%r%d", forth);
						break;
					case INC:
						tempStr = getStrSpace(6);
						sprintf(tempStr, "INC %%r%d", forth);
						break;
					case DEC:
						tempStr = getStrSpace(6);
						sprintf(tempStr, "DEC %%r%d", forth);
						break;
					case NEG:
						tempStr = getStrSpace(6);
						sprintf(tempStr, "NEG %%r%d", forth);
						break;
					case SHFTL:
						tempStr = getStrSpace(9);
						sprintf(tempStr, "SHFTL %%r%d", forth);
						break;	
					case SHFTR:
						tempStr = getStrSpace(9);
						sprintf(tempStr, "SHFTR %%r%d", forth);
						break;			
				}		
			break;

		// Not correct. Need to get two regesitries. For Debug purposes only
		case TWOREG:

			switch(sec) {
					case MVRR:
						tempStr = getStrSpace(12);
						sprintf(tempStr, "MVRR %%r%d,%%r%d", third, forth);
						break;
					case MVMR:
						tempStr = getStrSpace(12);
						sprintf(tempStr, "MVMR %%r%d,%%r%d", third, forth);
						break;
					case MVRM:
						tempStr = getStrSpace(12);
						sprintf(tempStr, "MVRM %%r%d,%%r%d", third, forth);
						break;
					case EXCH:
						tempStr = getStrSpace(12);
						sprintf(tempStr, "EXCH %%r%d,%%r%d", third, forth);
						break;
					case ADDR:
						tempStr = getStrSpace(12);
						sprintf(tempStr, "ADDR %%r%d,%%r%d", third, forth);
						break;
					case SUBR:
						tempStr = getStrSpace(12);
						sprintf(tempStr, "SUBR %%r%d,%%r%d", third, forth);
						break;
			}
			break;		
		}
			printf("%s\n", tempStr);		

}