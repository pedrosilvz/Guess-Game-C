#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>


int main() {           

    setlocale(LC_ALL, "Portuguese_Brazil");                     


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
    printf("\nSelecione a dificuldade: (1) fácil, (2) médio, (3) difícil.\n\n");
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


        for (int i = 1; i <= numerodetentativas; i++) {                                
        printf("\nTentativa número %d de %d\n", tentativas, numerodetentativas);              
        printf("\nQual é o número secreto?: ");      
        scanf("%d", &chute);                                                
        printf("\n");                 

        if(chute < 0) {
            printf("\n======================================================================================\n");;
            printf("\n- Você não pode chutar números negativos! O número de tentativas não será descontado!\n");
            printf("\n======================================================================================\n");      
            continue;     
        }

        acertou = (chute == numeroSecreto);     
        int maior = (chute > numeroSecreto);   
        
        if (acertou) {
            break;        

        } else if (maior) {                                                    
            printf("\n===============================================\n");
            printf("\n- SEU CHUTE FOI: %d\n", chute);
            printf("\n- Você errou! Tente novamente!\n");
            printf("\n- Seu chute foi maior que o número secreto\n");
            printf("\n===============================================\n");  
            }
         else {
                printf("\n===============================================\n"); 
                printf("\n- SEU CHUTE FOI: %d\n", chute);
                printf("\n- Você errou! Tente novamente!\n");
                printf("\n- Seu chute foir menor que o número secreto\n");
                printf("\n===============================================\n");  
            }

            tentativas++;        // Incrementa o número de tentativas    

            double pontosperdidos = abs(chute - numeroSecreto) / (double)2;            
            pontos = pontos - pontosperdidos;          

         }  

            printf("\n\n===============================================\n");
            printf("\n                 FIM DE JOGO!\n");
        

         if(acertou){
            printf("\n   Parabéns! você acertou o número secreto %d\n", numeroSecreto);
            printf("\n===============================================\n");
            printf("\n- Você acertou em %d tentativa(s)!\n", tentativas);    
            printf("\n- SCORE: %.1f\n\n", pontos);
            printf("===============================================\n\n");
         } else {
            printf("\n- Você perdeu! Jogue novamente!\n");
            printf("\n- O número secreto era: %d\n\n", numeroSecreto);
            printf("===============================================\n\n");
         }
     
    }
