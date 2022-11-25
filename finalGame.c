#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char play(int player, int dealer) {
    char choice;
    int choiceMade = 0;

    while(choiceMade == 0){
        printf("You have %i, the dealer has a(n) %i\n", player, dealer);

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
    int inGame = 1, startDeal1 = (rand() % 9) + 1, startDeal2 = (rand() % 9) + 1, dAce = 0, pAce = 0;
    int dealerCard1 = (rand() % 9) + 1, dealerCard2 = (rand() % 9) + 1, dealerHand, playerHand;
    
    cards[startDeal1] -= 1;
    cards[startDeal2] -= 1;
    cards[dealerCard1] -= 1;
    cards[dealerCard2] -= 1;

    if(startDeal1 == 1) {
        startDeal1 = 11;
        pAce = 1;
    }
    if (startDeal2 == 1 && pAce != 1) {
        startDeal2 = 11;
        pAce = 1;
    }
    
    if (dealerCard1 == 1) {
        dealerCard1 == 11;
        dAce = 1;
    }
    if (dealerCard2 == 1 && dAce != 1) {
        dealerCard2 == 11;
        dAce = 1;
    }

    playerHand = startDeal1 + startDeal2;
    dealerHand = dealerCard1 + dealerCard2;

    printf("You were delt a(n) %i and a(n) %i\n", startDeal1, startDeal2);

    if (playerHand == 21 && dealerHand != 21){
        printf("You win!\n");
        return 0;
    } else if(playerHand == 21 && dealerHand == 21){
        printf("Draw.\n");
        return 0;
    } 

    while(inGame == 1){
        char choice = play(playerHand, dealerCard1);
        if(choice == 'q'){
            inGame = 0;
        } else if(choice == 's'){
            printf("You stood with %i.\n", playerHand);
            while(dealerHand < 17){
                srand(time(0));
                int dCardDraw = (rand() % 10) + 1;
                if(cards[dCardDraw] > 0){
                    cards[dCardDraw] -= 1;
                    if(dAce != 1 && dCardDraw == 1){
                        dCardDraw = 11;
                        dAce = 1;
                    }

                    dealerHand += dCardDraw;
                    printf("The dealer drew a(n) %i, they now have %i. \n", dCardDraw, dealerHand);
                }            
            }

            if (dealerHand >= 17){
                if(playerHand > dealerHand || dealerHand > 21){
                    printf("You have %i, the dealer had %i, you win!\n", playerHand, dealerHand);
                    return 0;
                } else if(playerHand < dealerHand){
                    printf("You have %i, the dealer has %i, dealer wins.\n", playerHand, dealerHand);
                    return 0;
                } else if(playerHand == dealerHand){
                    printf("You have %i, the dealer has %i, it's a draw.\n", playerHand, dealerHand);
                    return 0;
                }
            }
        } else if(choice == 'h'){
            srand(time(0));
            int pCardDrawn = 0;
            while (pCardDrawn == 0){
                int pCardDraw = (rand() % 10) + 1;
                if(cards[pCardDraw] > 0){
                    cards[pCardDraw] -= 1;
                    if(pAce != 1 && pCardDraw == 1){
                        pCardDraw == 11;
                        pAce = 1;
                    }

                    playerHand += pCardDraw;
                    printf("You drew a(n) %i, you now have %i\n", pCardDraw, playerHand);
                    pCardDrawn = 1;
                    if(playerHand > 21){
                        printf("You have %i, the dealer has %i, dealer wins.", playerHand, dealerHand);
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}