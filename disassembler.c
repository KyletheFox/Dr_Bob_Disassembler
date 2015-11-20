#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disassembler.h"

void getInstruction(int acc, char *);

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
	if ((temp = (char*)malloc(1000)) == NULL)	{
		printf("ERROR\n");
		exit(2);
	}

	printf("fp: %x\n", fp);

	do {
		fscanf(fp, "%d %d", ip, acc);
		printf("ip: %d\n", ip);
		printf("acc: %d\n", acc);
		getInstruction(acc, temp);
	} while (feof(fp));

	fclose(fp);

	return 0;
}

void getInstruction(int acc, char *opCode) {
	char *tempStr;
	char temp;

	temp = acc/1000;

	switch(temp) {
		case HALT:
			temp = acc%1000;
			if(temp == 0 && *(tempStr-1) != "HALT" && *(tempStr-1) != ".word")
				*tempStr = "HALT";
			else
				*tempStr = ".word";
		case LD:
			temp = acc%1000;
			*tempStr = strcat("LD ", temp);
			break;
		case ST:
			temp = acc%1000;
			*tempStr = strcat("ST ", temp);
			break;
		case ADD:
			temp = acc%1000;
			*tempStr = strcat("ADD ", temp);
			break;
		case SUB:
			temp = acc%1000;
			*tempStr = strcat("SUB ", temp);
			break;
		case LDA:
			temp = acc%1000;
			*tempStr = strcat("LDA ", temp);
			break;
		case JMP:
			temp = acc%1000;
			*tempStr = strcat("JMP ", temp);
			break;
		case SKIPSET:
			
			temp = acc%1000;
			temp /= 100;
			
			switch(temp) {
				case SKIP:
					temp%10;
					*tempStr = strcat("SKIP %r", temp);
					break;

				case SKEQ:
					temp%10;
					*tempStr = strcat("SKEQ %r", temp);
					break;
				case SKNE:
					temp%10;
					*tempStr = strcat("SKNE %r", temp);
					break;
				case SKGT:
					temp%10;
					*tempStr = strcat("SKGT %r", temp);
					break;
				case SKGE:
					temp%10;
					*tempStr = strcat("SKGE %r", temp);
					break;
				case SKLT:
					temp%10;
					*tempStr = strcat("SKLT %r", temp);
					break;
				case SKLE:
					temp%10;
					*tempStr = strcat("SKLE %r", temp);
					break;		
			}

			break;
		case ONEREG:
			
			break;
		case TWOREG:
			
			break;		
		}
			printf("opCode: %s\n", tempStr);		

	

}