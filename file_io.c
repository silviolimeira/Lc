/* KTOD: Do teclado para o disco. */
#include <stdio.h>
#include <stdlib.h>

/* fopen()

    Modo    Significado

    r       Abre um arquivo-texto para leitura
    w       Cria um arquivo-texto para escrita
    a       Anexa um arquivo binario para leitura
    rb      Abre um arquivo binario para leitura
    wb      Abra um arquivo binario para escrita
    ab      Anexa um arquivo binario
    r+      Abre um arquivo-texto para leitura e escrita
    w+      Abre um arquivo-texto para leitura e escrita
    a+      Anexa ou cria um arquivo-texto para leitura e escrita
    r+b     Abre um arquivo binario para leitura e escrita
    w+b     Cria um arquivo binario para leitura e escrita
    a+b     Anexa a um arqivo binario para leitura e escrita
*/

int main(int argc, char *argv[])
{
    FILE *fp;
    char ch;

    if (argc != 2) {
        printf("Você esqueceu de digitar o nome do arquivo.\n");
        exit(1);
    }

    if ((fp=fopen(argv[1], "a")) == NULL) {
        printf("O arquivo não pode ser aberto.\n");
        exit(1);
    }

    do {
        ch = getchar();
        putc(ch, fp);
    } while (ch != '.');

    putc('\r', fp);
    putc('\n', fp);

    fclose(fp);

    printf("Pressione ENTER 1 para sair do programa.");
    getchar();
    return 0;
}
