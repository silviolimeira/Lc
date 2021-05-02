#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(void)
{

    char str[80];
    FILE *fp;

    if ((fp = fopen("TEST", "w+")) == NULL) {
        printf("O arquivo n�o pode ser aberto.\n");
        exit(1);
    }

    do {
        printf("Digite uma string (CR para sair):\n");
        gets(str);
        strcat(str, "\n"); /* acrescenta uma nova linha */
        fputs(str, fp);
    } while (*str != '\n');


    printf("\n\nAgora le e mostra o arquivo\n");
    /* agora, le e mostra o arquivo */
    rewind(fp); /* reinicializa o indicador de posicao de arquivo
                   para o comeco do arquivo. */

    while (!feof(fp)) {
        fgets(str, 79, fp);
        printf(str);
    }

    fclose(fp);
}

