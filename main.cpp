#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Alunos: Lucas Lopes Rodrigues da Silva SP3210499 e Luiz Otávio de Lima Rodrigues SP3211959
//Instruções: 1- No terminal use g++ montador1.cpp -o montador1.exe 2- Use o comando ./montador1.exe (O Montador irá traduzir o arquivo prog1.asm para o novo aqrquivo prog1.mem, ressaltando o arquvio prog1.asm deverá estar na mesma pasta que o executavel)


int main() 
{
	unsigned char NOP = 0x00;
	unsigned char STA = 0x10;
	unsigned char LDA = 0x20;
	unsigned char ADD = 0x30;
	unsigned char OR = 0x40;
	unsigned char AND = 0x50;
	unsigned char NOT = 0x60;
	unsigned char JMP = 0x80;
	unsigned char JN = 0x90;
	unsigned char JZ = 0xA0;
	unsigned char HLT = 0xF0;

    FILE *arqent = fopen("prog1.asm", "r");
    if (arqent == NULL) 
	{
		printf("Falha ao acessar o arquivo de entrada...");
        return 1;
    }   
    FILE *arqout = fopen("prog1.mem", "wb");
    if (arqout == NULL)
	{
    	printf("Falha ao criar o arquivo de Saida...");
        fclose(arqent);
        return 1;
    }
    unsigned char cabecalho[] = {0x03, 0x4E, 0x44, 0x52};
    fwrite(cabecalho, 1, 4, arqout);
    char linha[256];
    int linha_num = 0;
    while (fgets(linha, sizeof(linha), arqent)) 
	{
        linha_num++;
        linha[strcspn(linha, "\r\n")] = 0;
        char *linha_lim = linha;
        while (isspace(*linha_lim)) linha_lim++;
        if (*linha_lim == '\0' || *linha_lim == ';') {
            continue;
        }
        char inst[10];
        char comp[50];
        unsigned char bextra = 0x00;
        if (sscanf(linha_lim, "%s %x", inst, comp) == 2){
        } else if (sscanf(linha_lim, "%s", inst) == 1){
		}
		else 
		{
            continue;
        }
		if (strcmp(inst, "NOP") == 0)
        {
        	fwrite(&NOP, 1, 1, arqout);
        	fwrite(&bextra, 1, 1, arqout);
		}
		else if(strcmp(inst, "STA") == 0)
		{
			
        	fwrite(&STA, 1, 1, arqout);
        	fwrite(&bextra, 1, 1, arqout);
        	fwrite(&comp, 1, 1, arqout);
        	fwrite(&bextra, 1, 1, arqout);
		}
		else if(strcmp(inst, "LDA") == 0)
		{
			
        	fwrite(&LDA, 1, 1, arqout);
        	fwrite(&bextra, 1, 1, arqout);
        	fwrite(&comp, 1, 1, arqout);
        	fwrite(&bextra, 1, 1, arqout);
		}
		else if(strcmp(inst, "ADD") == 0)
		{
			
        	fwrite(&ADD, 1, 1, arqout);
        	fwrite(&bextra, 1, 1, arqout);
        	fwrite(&comp, 1, 1, arqout);
        	fwrite(&bextra, 1, 1, arqout);
		}
		else if(strcmp(inst, "OR") == 0)
		{
			
        	fwrite(&OR, 1, 1, arqout);
        	fwrite(&bextra, 1, 1, arqout);
        	fwrite(&comp, 1, 1, arqout);
        	fwrite(&bextra, 1, 1, arqout);
		}
		else if(strcmp(inst, "AND") == 0)
		{
			
        	fwrite(&AND, 1, 1, arqout);
        	fwrite(&bextra, 1, 1, arqout);
        	fwrite(&comp, 1, 1, arqout);
        	fwrite(&bextra, 1, 1, arqout);
		}
		else if (strcmp(inst, "NOT") == 0)
        {
        	fwrite(&NOT, 1, 1, arqout);
        	fwrite(&bextra, 1, 1, arqout);
		}
		else if(strcmp(inst, "JMP") == 0)
		{
			
        	fwrite(&JMP, 1, 1, arqout);
        	fwrite(&bextra, 1, 1, arqout);
        	fwrite(&comp, 1, 1, arqout);
        	fwrite(&bextra, 1, 1, arqout);
		}
		else if(strcmp(inst, "JN") == 0)
		{
			
        	fwrite(&JN, 1, 1, arqout);
        	fwrite(&bextra, 1, 1, arqout);
        	fwrite(&comp, 1, 1, arqout);
        	fwrite(&bextra, 1, 1, arqout);
		}
		else if(strcmp(inst, "JZ") == 0)
		{
			
        	fwrite(&OR, 1, 1, arqout);
        	fwrite(&bextra, 1, 1, arqout);
        	fwrite(&comp, 1, 1, arqout);
        	fwrite(&bextra, 1, 1, arqout);
		}
		else if (strcmp(inst, "HLT") == 0)
        {
        	fwrite(&HLT, 1, 1, arqout);
        	fwrite(&bextra, 1, 1, arqout);
		}
    }
    fclose(arqent);
    fclose(arqout);
    printf("Arquivo final concluido com sucesso!");
    return 0;
}