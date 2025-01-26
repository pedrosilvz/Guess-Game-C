#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>


int main() {           

    setlocale(LC_ALL, "Portuguese_Brazil");                     // Define o idioma do programa


        printf("\n================================================================================================================================================================\n");
        printf("\n                 ***          ***\n");
        printf("              ***....**     **...***\n");
        printf("             **........** **.......**\n");
        printf("      ***    **..........*.........**    ***\n");
        printf("   **.....**  **..................**  **.....**\n");
        printf(" **.........**  **..............**  **.........**\n");
        printf("*..............*   *..........*   *..............*\n");
        printf(" **..............*   *......*   *..............**     :'######:::'##::::'##:'########::'######:::'######::::::'######::::::'###::::'##::::'##:'########:'####:\n");
        printf("   **..............** *....* **..............**       '##... ##:: ##:::: ##: ##.....::'##... ##:'##... ##::::'##... ##::::'## ##::: ###::'###: ##.....:: ####:\n");
        printf("     *......................................*         '##... ##:: ##:::: ##: ##.....::'##... ##:'##... ##::::'##... ##::::'## ##::: ###::'###: ##.....:: ####:\n");
        printf("   **..............**........**..............**        ##::'####: ##:::: ##: ######:::. ######::. ######::::: ##::'####:'##:::. ##: ## ### ##: ######:::: ##::\n");
        printf(" **..............*    *....*    *..............**      ##::: ##:: ##:::: ##: ##...:::::..... ##::..... ##:::: ##::: ##:: #########: ##. #: ##: ##...:::::..:::\n");
        printf("*..............*      *....*      *..............*     ##::: ##:: ##:::: ##: ##:::::::'##::: ##:'##::: ##:::: ##::: ##:: ##.... ##: ##:.:: ##: ##:::::::'####:\n");
        printf(" **.........**        *....*        **.........**      . ######:::. #######:: ########:. ######::. ######:::::. ######::: ##:::: ##: ##:::: ##: ########: ####:\n");
        printf("   **.....**         *....*           **.....**        :......:::::.......:::........:::......::::......:::::::......::::..:::::..::..:::::..::........::....::\n");
        printf("      ***          **....*               ***\n");
        printf("                 ** * * *\n");
        printf("\n================================================================================================================================================================\n");
        printf("\n\n");

    int segundos = time(0);
    srand(segundos);
    int numerogrande = rand();
    int numeroSecreto = numerogrande % 100;            
    int chute;                                          
    int numerodetentativas;
    int tentativas = 1;
    double pontos = 1000.00;

    int acertou = 0;

    int dificuldade;
    printf("\nSelecione a dificuldade: (1) f�cil, (2) m�dio, (3) dif�cil.\n\n");
    printf("\nEscolha: ");
    scanf("%d", &dificuldade);
    printf("\n\n");

    switch (dificuldade) {
        case 1: 
        numerodetentativas = 20;
        break;

        case 2: 
        numerodetentativas = 10;
        break;
 
        default:
        numerodetentativas = 5;
        break;
    }


        for (int i = 1; i <= numerodetentativas; i++) {                                 // Loop infinito
        printf("\nTentativa n�mero %d de %d\n", tentativas, numerodetentativas);              // Imprime a tentativa atual
        printf("\nQual � o n�mero secreto?: ");      
        scanf("%d", &chute);                                             // L� o n�mero digitado pelo usu�rio e atribui � vari�vel chute --- &chute � o endere�o de mem�ria da vari�vel chute    
        printf("\n");                 

        if(chute < 0) {
            printf("\n======================================================================================\n");;
            printf("\n- Voc� n�o pode chutar n�meros negativos! O n�mero de tentativas n�o ser� descontado!\n");
            printf("\n======================================================================================\n");      
            continue;  // continue � uma instru��o que faz com que o loop pule para a pr�xima itera��o (uma itera��o � uma �nica execu��o de um loop)   
        }

        acertou = (chute == numeroSecreto);     // Verifica se o n�mero digitado � igual ao n�mero secreto --- 1 se verdadeiro, 0 se falso
        int maior = (chute > numeroSecreto);   
        
        if (acertou) {
            break;         // Encerra o loop

        } else if (maior) {                                                     // else if � uma condi��o que � verificada se a condi��o anterior for falsa
            printf("\n===============================================\n");
            printf("\n- SEU CHUTE FOI: %d\n", chute);
            printf("\n- Voc� errou! Tente novamente!\n");
            printf("\n- Seu chute foi maior que o n�mero secreto\n");
            printf("\n===============================================\n");  
            }
         else {
                printf("\n===============================================\n"); 
                printf("\n- SEU CHUTE FOI: %d\n", chute);
                printf("\n- Voc� errou! Tente novamente!\n");
                printf("\n- Seu chute foir menor que o n�mero secreto\n");
                printf("\n===============================================\n");  
            }

            tentativas++;        // Incrementa o n�mero de tentativas    

            double pontosperdidos = abs(chute - numeroSecreto) / (double)2;            //converte a vari�vel para double   //abs serve para transformar o n�mero em positivo
            pontos = pontos - pontosperdidos;          

         }  

            printf("\n\n===============================================\n");
            printf("\n                 FIM DE JOGO!\n");
        

         if(acertou){
            printf("\n   Parab�ns! voc� acertou o n�mero secreto %d\n", numeroSecreto);
            printf("\n===============================================\n");
            printf("\n- Voc� acertou em %d tentativa(s)!\n", tentativas);    // Imprime o n�mero de tentativas
            printf("\n- SCORE: %.1f\n\n", pontos);
            printf("===============================================\n\n");
         } else {
            printf("\n- Voc� perdeu! Jogue novamente!\n");
            printf("\n- O n�mero secreto era: %d\n\n", numeroSecreto);
            printf("===============================================\n\n");
         }
     
    }