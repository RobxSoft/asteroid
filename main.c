#include "Headers/glob.h"

void spawnAsteroid(){
    srand(time(NULL)); 
    int r = rand() % SIZE_Y;
    GAME[r][SIZE_X-1] = "*";
}

void update(){
    for(int y=0; y < SIZE_Y+1; y++){
        for(int x=0; x < SIZE_X; x++){
            if(strcmp(GAME[y][x], "*") == 0){
                GAME[y][x] = " ";
                if(x>0){
                    if(strcmp(GAME[y][x-1], ">") == 0){
                        //ICI
                    }
                    GAME[y][x-1] = "*";
                }
            }else if (strcmp(GAME[y][x], "-") == 0){
                GAME[y][x] = " ";
                if(x<SIZE_X){
                    GAME[y][x+1] = "-";
                }
            }
        }
    }
}

void startGame(){
    for(int y=0; y < SIZE_Y+1; y++){
        for(int x=0; x < SIZE_X; x++){
            if(x==0 && y==0){
                GAME[y][x] = ">";
            }else{
                GAME[y][x] = " ";
            }
        }
    }
}

void draw(){
    for(int y=0; y < SIZE_Y; y++){
        for(int x=0; x < SIZE_X+1; x++){
            if(x==0){
                printf("%d", y+1);
            }else{
                printf("%c", *GAME[y][x-1]);
            }
        }
        printf("\n");
    }
}

int main(void){
    startGame();
    spawnAsteroid();
    draw();

    printf("\n\n");

    update();
    draw();
    
    printf("\n\n");
    
    update();
    draw();

    return 1;
}