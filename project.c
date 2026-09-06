#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char arr[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[1;31m"
#define COLOR_GREEN   "\033[1;32m"
#define COLOR_YELLOW  "\033[1;33m"
#define COLOR_BLUE    "\033[1;34m"
#define COLOR_CYAN    "\033[1;36m"
#define COLOR_MAGENTA "\033[1;35m"
void showWelcomeScreen();
void showRulesScreen();
void getPlayerNames(char player1[], char player2[]);
void showBoard(char player1[], char player2[]);
int checkForWin();
void clearBuffer();
int main()
{
    char player1[50], player2[50];
    int player = 1;
    int choice, i;
    char mark;
    showWelcomeScreen();
    showRulesScreen();
    getPlayerNames(player1, player2);
    do
    {
        showBoard(player1, player2);
        player = (player % 2 != 0) ? 1 : 2;
        if (player == 1) {
            printf(COLOR_CYAN "===========================================\n");
            printf("  %s (%c), Enter a position (1-9): ", player1, 'X');
            printf("\n===========================================\n" COLOR_RESET);
        } else {
            printf(COLOR_MAGENTA "===========================================\n");
            printf("  %s (%c), Enter a position (1-9): ", player2, 'O');
            printf("\n===========================================\n" COLOR_RESET);
        }
        if (scanf("%d", &choice) != 1)
        {
            printf(COLOR_RED "\n[!] Invalid input! Numbers only. Press ENTER to continue..." COLOR_RESET);
            clearBuffer();
            getchar();
            player--; 
            continue;
        }
        mark = (player == 1) ? 'X' : 'O';
        if (choice >= 1 && choice <= 9 && arr[choice] == choice + '0') {
            arr[choice] = mark;
        }
        else
        {
            printf(COLOR_RED "\n[!] Invalid Move! Position already taken or out of range." COLOR_RESET);
            printf("\nPress ENTER to try again...");
            clearBuffer();
            getchar();
            player--;
        }
        i = checkForWin();
        player++;
    } while (i == -1);
    showBoard(player1, player2);
    if (i == 1)
    {
        player--;
        char *winnerName = (player == 1) ? player1 : player2;
        printf(COLOR_GREEN "====================================================\n");
        printf("||                                                ||\n");
        printf("||   CONGRATULATIONS! %-27s ||\n", winnerName);
        printf("||   YOU WON THE GAME!                            ||\n");
        printf("||                                                ||\n");
        printf("====================================================\n\n" COLOR_RESET);
    }
    else
    {
        printf(COLOR_YELLOW "====================================================\n");
        printf("||                                                ||\n");
        printf("||                   GAME DRAW!                   ||\n");
        printf("||        Well played both %s & %s!        ||\n", player1, player2);
        printf("||                                                ||\n");
        printf("====================================================\n\n" COLOR_RESET);
    }
    printf("Press ENTER to exit the game...");
    clearBuffer();
    getchar();
    return 0;
}
void clearBuffer() {
    while (getchar() != '\n');
}
void showWelcomeScreen() {
    printf("\033[H\033[J");
    printf(COLOR_CYAN "====================================================\n");
    printf("||                                                ||\n");
    printf("||           WELCOME TO TIC TAC TOE GAME          ||\n");
    printf("||                                                ||\n");
    printf("====================================================\n" COLOR_RESET);
    printf("\nPress ENTER to continue...");
    getchar();
}
void showRulesScreen() {
    printf("\033[H\033[J");
    printf(COLOR_YELLOW "====================================================\n");
    printf("||                  GAME RULES                    ||\n");
    printf("====================================================\n");
    printf("|| 1. Game is played on a 3x3 grid.               ||\n");
    printf("|| 2. Player 1 gets 'X' and Player 2 gets 'O'.    ||\n");
    printf("|| 3. Take turns to choose a box from 1 to 9.     ||\n");
    printf("|| 4. First to align 3 marks in a row/column/     ||\n");
    printf("||    diagonal WINS!                              ||\n");
    printf("====================================================\n" COLOR_RESET);
    printf("\nPress ENTER to enter player names...");
    getchar();
}
void getPlayerNames(char player1[], char player2[]) {
    printf("\033[H\033[J");
    printf(COLOR_BLUE "====================================================\n");
    printf("||                ENTER PLAYER NAMES              ||\n");
    printf("====================================================\n" COLOR_RESET);   
    printf(COLOR_CYAN "\nEnter Player 1 Name (X): " COLOR_RESET);
    scanf("%49s", player1);   
    printf(COLOR_MAGENTA "Enter Player 2 Name (O): " COLOR_RESET);
    scanf("%49s", player2);
    clearBuffer();
    printf(COLOR_GREEN "\n====================================================\n");
    printf("  Players registered successfully!                  \n");
    printf("====================================================\n" COLOR_RESET);
    printf("\nPress ENTER to start the game...");
    getchar();
}
void showBoard(char player1[], char player2[])
{
    printf("\033[H\033[J");
    printf(COLOR_CYAN "====================================================\n");
    printf("                   TIC TAC TOE                      \n");
    printf("====================================================\n" COLOR_RESET);
    printf(COLOR_CYAN "  %s (X)" COLOR_RESET "  vs  " COLOR_MAGENTA "%s (O)\n" COLOR_RESET, player1, player2);
    printf("====================================================\n\n");
    printf("                     |     |     \n");
    printf("                  %c  |  %c  |  %c  \n", arr[1], arr[2], arr[3]);
    printf("                -----+-----+-----\n");
    printf("                     |     |     \n");
    printf("                  %c  |  %c  |  %c  \n", arr[4], arr[5], arr[6]);
    printf("                -----+-----+-----\n");
    printf("                     |     |     \n");
    printf("                  %c  |  %c  |  %c  \n", arr[7], arr[8], arr[9]);
    printf("                     |     |     \n\n");
}
int checkForWin()
{
    if (arr[1] == arr[2] && arr[2] == arr[3]) return 1;
    else if (arr[4] == arr[5] && arr[5] == arr[6]) return 1;
    else if (arr[7] == arr[8] && arr[8] == arr[9]) return 1;
    else if (arr[1] == arr[4] && arr[4] == arr[7]) return 1;
    else if (arr[2] == arr[5] && arr[5] == arr[8]) return 1;
    else if (arr[3] == arr[6] && arr[6] == arr[9]) return 1;
    else if (arr[1] == arr[5] && arr[5] == arr[9]) return 1;
    else if (arr[3] == arr[5] && arr[5] == arr[7]) return 1;
    else if (arr[1] != '1' && arr[2] != '2' && arr[3] != '3' && 
             arr[4] != '4' && arr[5] != '5' && arr[6] != '6' && 
             arr[7] != '7' && arr[8] != '8' && arr[9] != '9')
        return 0;
    else
        return -1;
}

