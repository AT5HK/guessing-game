//
//  main.c
//  Guessing game
//
//  Created by Auston Salvana on 6/30/15.
//  Copyright (c) 2015 ASolo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct player{
    int lives;
    char answer[100];
    bool turn;
    int score;
    
};

struct player player1;
struct player player2;

void question(int num1, int num2){
    
    
        
    printf("%d+%d\n",num1,num2);
   
    
    
}

int answer(int num1, int num2){
    
    int total = num1+num2;
    char response[100];
    char totalChar[100];
    
    sprintf(totalChar, "%d", total);
    
    fgets(response, 100, stdin);
    
    //get rid of newline
    size_t ln = strlen(response) - 1;
    if (response[ln] == '\n'){
        response[ln] = '\0';
    }
    
    
    //compare
    if (strcmp(response, totalChar) == 0) {
//        printf("Right\n");
        return 1;
    }
    else{
//        printf("Wrong\n");
        return 0;
    }
    
    
    
    
}





int main(int argc, const char * argv[]) {
    
    player1.lives = 3;
    player2.lives = 3;
    
    while (player1.lives > 0 || player2.lives > 0) {
        
        
        
        int num1 = rand() % 20;
        int num2 = rand() % 20;
        
        
        question(num1, num2);
        int rightOrNot = answer(num1, num2);
        
        if (player1.turn == 0) {
            if (rightOrNot == 1) {
                player1.score++;
            }
            else{
                player1.lives--;
            }
            player1.turn = 1;
        }
        else{
            if (rightOrNot == 1) {
                player2.score++;
            }
            else{
                player2.lives--;
            }
            player1.turn = 0;
        }
        
        printf("player1 score:%d\n", player1.score);
        printf("player2 score:%d\n", player2.score);
  
    }
    
    if (player1.lives > player2.lives) {
        printf("player1 Won!");
    }
    else{
        printf("player2 Won!");
    }
    
    
    return 0;
}
