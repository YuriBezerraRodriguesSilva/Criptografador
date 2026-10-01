#include<stdio.h>

char alfabetoCompleto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
//Alfabeto em maiúsculo, minúsculo e numérico definidos em uma char.

int aplicandoShift(int posicao, int shift) {
        int novaPosicao;
        novaPosicao = (posicao + shift) % 62;
        return novaPosicao;
}
int main() {
    char palavra[16];
    //Palavra não pode passar de 15 letras.
    char palavraOriginal[16];
    int shift;
    //Valor armazenado para a mudança das letras, INT para número.
    int posicao;
    //Verificar a posição dentro da char do alfabeto.
    int termo;
    //Termo principal da PG.
    int razao;
    //Razão da multiplicação da PG.
    int valorPG;
    //Armazena o valor da PG.
    int quantidadeLetras = 0;
    //Armazena a quantidade de letras da palavra.
    FILE *arquivo;
    
    printf("Digite a palavra que sera criptografada:");
    scanf("%s", palavra);

    int i = 0;

    while (palavra[i] != '\0') {
        palavraOriginal[i] = palavra[i];
        quantidadeLetras++;
        i++;
    }

    palavraOriginal[i] = '\0';

    printf("Digite o valor do shift:");
    scanf("%d", &shift); //Pede a palavra e o valor do shift.
    
    for (int i = 0; palavra[i] != '\0'; i++) {
        for (int j = 0; j < 62; j++) { //Compara palavra[i] com alfabetoCompleto[j].
            if (palavra[i] == alfabetoCompleto[j]) { //Percorreu os caracteres da palavra
            posicao = j; //Guarda o valor dessa procura.
            posicao = aplicandoShift(posicao, shift); //Aplica o valor do shift pra posicao.
            palavra[i] = alfabetoCompleto[posicao]; //Substitui a palavra por sua versão criptografada.
            break;
        }
    }
}
    printf("Digite o termo da PG:");
    scanf("%d", &termo);
    printf("Digite a razao da PG:");
    scanf("%d", &razao);
    valorPG = termo;
    //Pede os valores da razão e do termo da PG para a camada 2.
    
    for (int i = 0; palavra[i] != '\0'; i++) {
        for (int j = 0; j < 62; j++) {
            if (palavra[i] == alfabetoCompleto[j]) {

                posicao = j;
                posicao = (posicao + valorPG) % 62;
                palavra[i] = alfabetoCompleto[posicao];

                valorPG = valorPG * razao;

                break;
            }
        }
    }
    
    arquivo = fopen("log_criptografia.txt", "w"); // Cria o arquivo TXT para armazenar os dados da execução.

    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo de log.\n");
        return 1;
    } // Verifica se houve algum erro ao criar o arquivo.
    

    fprintf(arquivo, "(Log de execucao)\n\n"); // Escreve o título do log.
    fprintf(arquivo, "Palavra original: %s\n", palavraOriginal); // Registra a palavra antes da criptografia.
    fprintf(arquivo, "Palavra codificada: %s\n", palavra); // Registra a palavra após as duas camadas.
    fprintf(arquivo, "Quantidade de letras: %d\n", quantidadeLetras); // Registra a quantidade de caracteres da palavra.
    fprintf(arquivo, "Valor do SHIFT: %d\n", shift); // Registra o valor utilizado na primeira camada.
    fprintf(arquivo, "Primeiro termo da PG: %d\n", termo); // Registra o primeiro termo utilizado na segunda camada.
    fprintf(arquivo, "Razão da PG: %d\n", razao); // Registra a razão utilizada para gerar a PG.
    fclose(arquivo); // Fecha o arquivo após terminar a gravação.

    fclose(arquivo);

    printf("\nPalavra criptografada: %s\n", palavra);
    return 0;
}

