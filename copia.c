/* Copia um arquivo */
#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[]) {
    FILE *in, *out;
    char ch;

    if (argc != 3) {
        printf("Voce esqueceu de informar os nome do arquivo.\n");
        exit(1);
    }

    if ((in = fopen(argv[1], "rb")) == NULL) {
        printf("O arquivo-fonte nao pode ser aberto.\n");
        exit(1);
    }

    if ((out = fopen(argv[2], "wb")) == NULL) {
        printf("O arquvo-destino nao pode ser aberto.\n");
        exit(1);
    }

    /* Esse codigo copia de fato o arquivo */
    while (!feof(in)) {
        ch = getc(in);
        if (!feof(in)) putc(ch, out);
    }

    fclose(in);
    fclose(out);

    return 0;
}
