#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define N 10

void setBoard(int slot, char board[N]);
void setCompBoard(int slot, char board[N]);
int playGame(int slot);

int main()
{
    int slot;
    
    printf("Enter position: ");
    scanf("%d", &slot);
    
    int results = playGame(slot);
    if(results == 0){
        printf("Computer wins!");
    }
    else if(results == 1){
        printf("Human wins!");
    }
    else{printf("Tie!");}
    
}

int playGame(int slot){
    int compSlot = rand() % 10, fire = 0, compfire = 0;
    bool comp = false, player = false;
    char board[N], compBoard[N], *ship, *hit, *miss;
    
    setBoard(slot, board);
    setCompBoard(compSlot, compBoard);
    
    while(comp != true && player != true){
        srand ( time(NULL) );
        compfire = rand() % 10;
        
        printf("Computer guesses %d\n\n", compfire);
        if(compfire == slot){
            printf("--HIT!--\n\n");
            hit = &board[compfire];
            *hit = 'H';
            comp = true;
        }
        else{
            printf("--MISS!--\n\n");
            miss = &board[compfire];
            *miss = 'M';
        }
        
        printf("Enter guess: ");
        scanf("%d", &fire);
        printf("You guessed %d\n\n", fire);
        
        if(fire == compSlot){
            printf("--HIT!--\n\n");
            hit = &compBoard[fire];
            *hit = 'H';
            player = true;
        }
        else{
            printf("--MISS!--\n\n");
            miss = &compBoard[fire];
            *miss = 'M';
        }
        
        printf("Human Board:\n0 1 2 3 4 5 6 7 8 9\n");
        for(int i = 0; i < 10; i++){printf("%c ", board[i]);}
        printf("\n\n");
        
        printf("Computer Board:\n0 1 2 3 4 5 6 7 8 9\n");
        for(int i = 0; i < 10; i++){printf("%c ", compBoard[i]);}
        printf("\n\n");
    }
    if(comp && player){return 2;}
    if(comp){return 0;}
    if(player){return 1;}
}

void setBoard(int slot, char board[N]){
    char *ship = &board[slot];
    *ship = 'S';
    for(int i = 0; i < N; i++){
        if(i != slot){board[i] = '*';}
    }
}

void setCompBoard(int compSlot, char compBoard[N]){
    for(int i = 0; i < N; i++){
        compBoard[i] = '*';
    }
}