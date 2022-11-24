#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char play() {
    char choice;
    int choiceMade = 0;
    
    while(choiceMade == 0){
        printf("Type s to stand, h to hit, or q to quit\n");
        scanf(" %c", &choice);

        if(choice == 's' || choice == 'h' || choice == 'q'){
            choiceMade = 1;
        } else {
            printf("You must type s, h, or q\n");
        }
    }
    return choice;
}

int main() {

    srand(time(0));

    int cards[10] = {4}; //keeping track of cards in deck
    cards[10] = 16; //includes jacks, kings, and queens
    int inGame = 1, startDeal1 = rand() % 13, startDeal2 = rand() % 13;
    int dealerCard1 = rand() % 10, dealerCard2 = rand() % 10;
    
    cards[startDeal1] -= 1;
    cards[startDeal2] -= 1;
    cards[dealerCard1] -= 1;
    cards[dealerCard2] -= 1;

    printf("You were delt a %i, and a %i\n", startDeal1, startDeal2);

    while(inGame == 1){

        char choice = play();

        if(choice == 'q'){
            inGame = 0;

        } else if( choice == 's'){

        }

    }


    return 0;
}