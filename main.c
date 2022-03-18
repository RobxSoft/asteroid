#include "Headers/glob.h"

void startGame(){
    for(int x; x < SIZE_X+1; x++){
        for(int y; y < SIZE_Y; y++){
            if(x==0 && y==0){
                GAME[x][y] = ">";
            }else{
                GAME[x][y] = " ";
            }
        }
    }
}

void draw(){
    for(int x; x < SIZE_X+1; x++){
        for(int y; y < SIZE_Y; y++){
            if(x==1){
                printf("%d", y);
            }else{
                printf("%c", GAME[x][y]);
            }
        }
    }
}

int main(void){
    startGame();
    draw();
    return 1;
}