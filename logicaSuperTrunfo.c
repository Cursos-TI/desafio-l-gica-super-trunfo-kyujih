#include <stdio.h>

struct Carta {
    char estado[20];
    char codigo_cidade[5];
    char nome[50];
    float populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
    float pib_capital;
};

int main() {
    struct Carta cartas[2]; // Array para armazenar duas cartas


    for (int num = 0; num < 2; num++) {
        printf("\n=== Cadastro da Carta %d ===\n", num + 1);

        printf("Digite o estado Ex: Sao_Paulo\n>>> ");
        scanf("%s", cartas[num].estado); // Não aperte espaço, ele finaliza o código.

        printf("Digite o código da cidade\n(o primeiro caracter deve ser a inicial do estado) Ex: s04\n>>> ");
        scanf("%s", cartas[num].codigo_cidade); // Novamente, não aperte espaço, ele finaliza o código.

        printf("Digite o nome da cidade Ex: Sao_Paulo\n>>> ");
        scanf("%s", cartas[num].nome);

        printf("Digite a população Ex: 12345678\n>>> ");
        scanf("%f", &cartas[num].populacao);

        printf("Digite a área da cidade Ex: 1234.56\n>>> "); // Não precisa colocar km, ele coloca no output
        scanf("%f", &cartas[num].area);

        printf("Digite o PIB da cidade (Bilhões) Ex: 123.12\n>>> ");
        scanf("%f", &cartas[num].pib);

        printf("Digite quantos pontos turísticos tem a cidade Ex: 14\n>>> ");
        scanf("%d", &cartas[num].pontos_turisticos);

        cartas[num].densidade = cartas[num].populacao / cartas[num].area; //Calcula a densidade demografica
        
        cartas[num].pib_capital = cartas[num].pib / cartas[num].populacao;
        
        printf("Carta %d cadastrada com sucesso!\n", num + 1);
    }

    // Exibe as cartas cadastradas
    for (int num = 0; num < 2; num++) {
        printf("\n=== Informações da Carta %d ===\n", num + 1);
        printf("Estado: %s\n", cartas[num].estado);
        printf("Código da cidade: %s\nCidade: %s\n", cartas[num].codigo_cidade, cartas[num].nome);
        printf("População total: %.0f\nÁrea: %.2f Km²\n", cartas[num].populacao, cartas[num].area);
        printf("PIB: %.2f bilhões de reais\nPontos turísticos: %d\n", cartas[num].pib, cartas[num].pontos_turisticos);
        printf("Densidade demográfica: %f\n", cartas[num].densidade);
        printf("PIB per capita: %f\n", cartas[num].pib_capital);

    }
    
    int carta_1 = 0;
    int carta_2 = 0;
    
    
    //Começo da contagem de pontos em cada categoria.
    if (cartas[0].populacao > cartas[1].populacao) { //Verifica população
        carta_1++;
        printf("A carta número 1 ganhou da carta número 2 em: População\n");
    } else {
        carta_2++;
        printf("A carta número 2 ganhou da carta número 1 em: População\n");
    }

    if (cartas[0].area > cartas[1].area){ //Verifica área
        carta_1++;
        printf("A carta número 1 ganhou da carta número 2 em: Área\n");
    } else {
        carta_2++;
        printf("A carta número 2 ganhou da carta número 1 em: Área\n");
    }

    if (cartas[0].pib > cartas[1].pib){ //Verifica o PIB
        carta_1++;
        printf("A carta número 1 ganhou da carta número 2 em: PIB\n");
    } else {
        carta_2++;
        printf("A carta número 2 ganhou da carta número 1 em: PIB\n");
    }

    //Verifica os Pontosturisticos
    if (cartas[0].pontos_turisticos > cartas[1].pontos_turisticos){
        carta_1++;
        printf("A carta número 1 ganhou da carta número 2 em: Pontos turisticos\n");
    } else {
        carta_2++;
        printf("A carta número 2 ganhou da carta número 1 em: Pontos turisticos\n");
    }

     if (cartas[0].densidade < cartas[1].densidade){ //Verifica a densidade demográfica
        carta_1++;
        printf("A carta número 1 ganhou da carta número 2 em: Densidade demográfica\n");
    } else {
        carta_2++;
        printf("A carta número 2 ganhou da carta número 1 em: Densidade demográfica\n");
    }
    
    if (cartas[0].pib_capital > cartas[1].pib_capital){ //E por fim, verifica o PIB per capita
        carta_1++;
        printf("A carta número 1 ganhou da carta número 2 em: PIB per capita\n");
    } else {
        carta_2++;
        printf("A carta número 2 ganhou da carta número 1 em: PIB per capita\n");
    }
    //fim da contagem



    //Verifica qual carta fez mais pontos e declara o vencedor
    printf("=== RESULTADO ===\n");
    if (carta_1 > carta_2){
        printf("A carta %s ganhou por %d/6 pontos",cartas[0].codigo_cidade, carta_1);
    } else {
        if (carta_1 < carta_2){
            printf("A carta %s ganhou por %d/6 pontos",cartas[1].codigo_cidade, carta_2);
        }
        printf("Deu empate.");
    }
    return 0;
}
