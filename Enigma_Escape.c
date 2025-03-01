#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include<windows.h>

#define FOOD 2
//to get food and increase food 

typedef struct{
    int x;
    int y;
}Food;


int check(int i, int j, int n,int arr[][n], int* path[], int l) {
    
     if(i>=0 && i<n && j>=0 && j<n  ){
        for(int k=0;k<l;k++){
        if(&arr[i][j]==path[k]){
           // break;
            return 2;
        }
        
    }   
}
 return 1;
}

//to print solution of maze 
void displaySolution(int n, int arr[][n], int* path[], int l) {

     printf("Solution path:\n");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (&arr[j][k] == path[i]) {
                    printf("\033[0;32m");
                    printf("(%d, %d) -> ", j, k);
                    printf("\033[0m");
                    break;
                }
            }
        }
    }
    //printf("(%d, %d)\n", n - 1, n - 1);
}

// Depth First Search
//to find solution of maze 
void DFS(int i, int j, int n, int arr[][n], int* path[], int l) {
    int P, Q, L, p, q;
   //   printf("%d",arr[2][1]);
    if (i == n - 2 && j == n - 2) {
        displaySolution(n, arr, path, l);
    } 
    else {
        if (arr[i + 1][j] == 0 && check(i + 1, j, n, arr, path, l) ==1) {
            path[l] = &arr[i + 1][j];
            l++;
            DFS(i + 1, j, n, arr, path, l);
        } else if (arr[i][j + 1] == 0 && check(i, j + 1,n, arr,  path, l) ==1 ) {
            path[l] = &arr[i][j + 1];
            l++;
            DFS(i, j + 1, n, arr, path, l);
        } else if (arr[i - 1][j] == 0 && check(i - 1, j,n, arr, path, l)==1) {
            path[l] = &arr[i - 1][j];
            l++;
            DFS(i - 1, j, n, arr, path, l);
        } else if (arr[i][j - 1] == 0 && check(i, j - 1, n, arr, path, l) ==1) {
            path[l] = &arr[i][j - 1];
            l++;
            DFS(i, j - 1, n, arr, path, l);
        } else {

            // Backtracking
            for (int m = 0; m < l; m++) {
                if (&arr[i][j] == path[m]) {
                    L = m;
                    break;
                }
            }
            for (int p = 0; p < n; p++) {
                for (int q = 0; q < n; q++) {
                    if (&arr[p][q] == path[L]) {
                        P = p;
                        Q = q;
                        break;
                    }
                }
            }
            DFS(P, Q, n, arr, path, l);
        }
    }
}

//to print random generated maze 

void Print_maze(int playerX, int playerY, int width, int height, int wall,int exitX, int exitY, int maze[width][height], Food food)
{
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (i == playerY && j == playerX) {
                printf("\033[0;35m");
                printf("P ");
                printf("\033[0m");
            } else if (i == exitY && j == exitX) {
                printf("\033[0;34m");
                printf("E ");
                printf("\033[0m");
            } 
            else if(i==food.y && j==food.x)
            {
                printf("\033[0;31m");
                printf("F ");
                printf("\033[0m");
            }
             
            else if (maze[i][j] == wall) {
                if (i == 1 && j == 0) { 
                    printf("  "); 
                } else {
                    printf("\033[0;33m");
                    printf("# ");
                    printf("\033[0m");
                }
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

}

//to check within the bounds of matrix
int Valid_check(int x, int y, int width, int height) {
    return x >= 0 && x < width && y >= 0 && y < width;
}

//to generate random maze
void Generate_maze(int x, int y,int width,int height, int maze[width][height],int path,int wall) {
    static int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int dir_order[4] = {0, 1, 2, 3};
    int temp;

    for (int i = 0; i < 4; i++) {
        int rand_index = rand() % 4;
        temp = dir_order[i];
        dir_order[i] = dir_order[rand_index];
        dir_order[rand_index] = temp;
    }

    maze[x][y] = path; 

    for (int i = 0; i < 4; i++) {
        int dx = directions[dir_order[i]][0];
        int dy = directions[dir_order[i]][1];

        int nx = x + dx * 2;
        int ny = y + dy * 2;

        if (Valid_check(nx, ny, width, height) && maze[nx][ny] == wall) {
            maze[x + dx][y + dy] = path;
            //maze[x + dx / 2][y + dy / 2] = path;
            Generate_maze(nx, ny,width, height, maze, path, wall);
        }
    }
}

int main(){
    srand(time(NULL));
    
    int n;
    // Instructions
    printf("\033[0;34m");
    printf("\t\t\tWelcome to enigma escape :)\n");

    printf("Press 'w' for up, 'a' for left, 's' for down and 'd' for right\n");
    printf("Press 'e' to grab food item and increase your score\n");
    printf("Press 'q' to quit the game and show the solution\n");
    printf("Press enter after each step\n");
     printf("\033[0m");
    again:
    printf("\033[0;35m");
    printf("Which level do you want to play? \nPress 1 for easy, 2 for medium and 3 for hard.\n");
    printf("Enter 4 to exit the game.\n");
    printf("\033[0m");
    scanf("%d",&n);
    printf("\033[2J\033[H"); // Clear screen

    // Variables
    int path = 0;
    int wall = 1;
    int width, height;
    int time_limit;
    int seconds=0;
    
    char choice;

    // Easy Level
    if (n == 1) 
    {
        printf("\033[0;32m");
        printf("The given time limit is 60 seconds\n");
        printf("Try to complete before that\n");
        printf("\033[0m");
        width = 11;
        height = 11;
        time_limit=60;
        
    } 
    
    // Medium Level
    else if (n == 2) 
    {
        printf("\033[0;32m");
        printf("The given time limit is 120 seconds\n");
        printf("Try to complete before that\n");
        printf("\033[0m");
        width = 17;
        height = 17;
        time_limit=120;
    } 
    
    // Hard Level
    else if (n == 3) 
    {
        printf("\033[0;32m");
        printf("The given time limit is 180 seconds\n");
        printf("Try to complete before that\n");
        printf("\033[0m");
        width = 25;
        height = 25;
        time_limit=180;
    } 

    // To quit the game
    else if (n==4)
    {
        printf("\033[0;36m");
        printf("Thank You for playing!");
        printf("\033[0m");
        exit(0);
    }

    // Wrong choice entered by user
    else{
        printf("\033[0;31m");
        printf("Invalid input. Please enter a valid choice.\n");
        printf("\033[0m");
        goto again;
    }

    int maze[width][height];
    int exitX, exitY;

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            maze[i][j] = wall;
        }
    }

    // To generate maze according to the selected level
    Generate_maze(1, 1, width, height, maze, path, wall);

    exitX = width - 2;
    exitY = height - 2;

    maze[1][1] = path;
    maze[width - 2][height - 2] = path;

    Food food;
    do{
        food.x=rand()%(width-2)+1;
        food.y=rand()%(height-2)+1;
    } while(maze[food.y][food.x]==wall);

    int score=0;

    int playerX = 0;
    int playerY = 1;

    Print_maze(playerX, playerY, width, height, wall, exitX, exitY, maze,food);


    // To check the time limit
    time_t start_time, current_time;
    double elapsed_time;

    start_time=time(NULL);

    char move; // Move declaration moved here

    int* sol[1000];
    int l = 1;
    sol[0] = &maze[1][0];
    while (1) {
        current_time=time(NULL);
        elapsed_time=difftime(current_time,start_time);

    if(elapsed_time>=time_limit){
        printf("\033[0;34m");
        printf("Time's up! Game Over.\n");
        printf("Your score is %d\n",score);
        goto again;
    }

        scanf(" %c", &move); // Added space before %c to ignore whitespace characters
        
        switch(move) {

            // Move up
            case 'w': 
                if (playerY > 1 && maze[playerY - 1][playerX] != wall)
                    playerY--;
                break;
            
            // Move down
            case 's': 
                if (playerY < height - 2 && maze[playerY + 1][playerX] != wall)
                    playerY++;
                break;

            // Move left
            case 'a': 
                if (playerX > 1 && maze[playerY][playerX - 1] != wall)
                    playerX--;
                break;

            // Move right
            case 'd': 
                if (playerX < width - 2 && maze[playerY][playerX + 1] != wall)
                    playerX++;
                break;

            // Show solution
            case 'q': 
               // DFS(playerY, playerX, width, maze, sol, l);
               
            DFS(1,0, width, maze, sol, l);
                printf("\n");
                goto again;
                

            // To capture food
            case 'e':
                if (playerX==food.x && playerY==food.y){
                    maze[food.y][food.x]=path;
                    score+=10;
                
                    do{
                        food.x=rand() % (width-2)+1;
                        food.y=rand() % (height-2)+1;
                    }while(maze[food.y][food.x]==wall);
                }
                break;
        }

        // if player reached the exit point
        if (playerX == exitX && playerY == exitY) {
            score+=10;
            Beep(523,500); 
            // 523 hertz (C5) for 500 milliseconds
            Beep(587,500);  
            // 587 hertz (D5) for 500 milliseconds
            printf("\033[38;5;208m");
            printf("Congratulations! You've reached the exit! You win\n");
            printf("Your score is:%d\n",score);
            printf("\033[0m");
            goto again;
            
        }

        printf("\033[2J\033[H"); // Clear screen
        Print_maze(playerX, playerY, width, height, wall, exitX, exitY, maze,food);
    }

    return 0;
}