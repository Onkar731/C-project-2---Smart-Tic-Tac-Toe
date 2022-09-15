/* Project 2 - Smart Tic Tac Toe */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

// to display pattern
void displayPattern(int[], char[], char[]);

// to play with smart computer
void playWithSmartComputer();

// to play with evil computer
void playWithEvilComputer();

// to play with friend
void playWithFriend();

// to accept player's details
void acceptPlayersName(char*, char*);

// for player 1 action
void player1Play(int[], char[], char[]);

// for player 2 action
void player2Play(int[], char[], char[]);

// to check result
int checkResult(int[], int);

// to check result smartly
int checkSmartly(int[], int);

// to check result evilly
int checkEvilly(int[], int);

// for smart computer action
int playComputer(int[], int);

// to generate random value
int generateRandomValue();

// for winning situation
void win(int[], char[], char[], int);

// To display text in color - user define functions as per the color name
void red();
void green();
void yellow();
void white();


int main()
{
    int choice;


    while(1)
    {
        system("cls");

        green();
        printf("\n\n1. Want to play with Smart Computer");
        red();
        printf("\n2. Want to play with Evil Computer");
        yellow();
        printf("\n3. Want to play with Friend");
        red();
        printf("\n4. Exit");
        white();

        printf("\n\nEnter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                    // playing with smart computer
                    playWithSmartComputer();
                    break;
            case 2:
                    // playing with evil computer
                    playWithEvilComputer();
                    break;
            case 3:
                    // playing with friend
                    playWithFriend();
                    break;
            case 4:
                    exit(0);
        }
    }
    return 0;
}

void playWithSmartComputer()
{
    int array[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    char player1[20], player2[15] = "Smart Computer";

    // accepting player's name
    system("cls");
    
    printf("\n\n\n\t\t\tPLAYER NAME");
    // Accepting player 1 details
    printf("\n\n\nEnter Player 1 Name : ");
    yellow();
    scanf("%s", player1);
    white();
    system("cls");


    int count = 1, marking_place;

    while(count < 10)
    {
        if(count % 2 == 1){
            player1Play(array, player1, player2); // player 1 playing

            if(count >= 5){
                if(checkResult(array, 88)){
                    win(array, player1, player2, 1);
                    break;
                }
            }
        }
        else{
            if(count == 2){
                // generating random value to mark place
                marking_place = generateRandomValue(array);
                array[marking_place] = 79; // assigning randomly
            }
            else{
                if(marking_place = checkSmartly(array, 79)){
                    array[marking_place - 1] = 79;
                    win(array, player1, player2, 3);
                    break;
                }
                else if(marking_place = checkSmartly(array, 88)){
                    array[marking_place - 1] = 79;
                    if(count >= 6){
                        if(checkResult(array, 79)){
                            win(array, player1, player2, 3);
                            break;
                        }
                    }
                }
                else{
                    marking_place = playComputer(array, marking_place);
                    if(count >= 6){
                        if(checkResult(array, 79)){
                            win(array, player1, player2, 3);
                            break;
                        }
                    }
                }
            }
        }
        count++;
    }

    // game draw situation
    if(count == 10){
        system("cls");
        displayPattern(array, player1, player2);
        red();
        printf("Game Draw !!!");
        white();
        printf("\n\n##########################################################");
        printf("\n\nPress any key to continue....");
        getch();
    }
    
}

void playWithEvilComputer()
{
    int array[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    char player1[15], player2[14] = "Evil Computer";

    // accepting player's name
    system("cls");
    
    printf("\n\n\n\t\t\tPLAYER NAME");
    // Accepting player 1 details
    printf("\n\n\nEnter Player 1 Name : ");
    yellow();
    scanf("%s", player1);
    white();
    system("cls");


    int count = 1, marking_place, flag;

    while(count <= 10)
    {
        if(count % 2 == 1){
            player1Play(array, player1, player2); // player 1 playing

            if(count >= 5){
                if(checkResult(array, 88)){
                    win(array, player1, player2, 1);
                    break;
                }
            }
        }
        else{
            if(count == 2){
                // generating random value to mark place
                marking_place = generateRandomValue(array);
                array[marking_place] = 79; // assigning randomly
            }
            else{
                if(marking_place = checkSmartly(array, 79)){
                    array[marking_place - 1] = 79;
                    win(array, player1, player2, 4);
                    break;

                }
                else if(flag = checkEvilly(array, 88)){

                    if(flag == 2)
                        count += 2;

                    if(checkResult(array, 79)){
                        win(array, player1, player2, 4);
                        break;
                    }
                }
                else{
                    marking_place = playComputer(array, marking_place);
                    if(count >= 6){
                        if(checkResult(array, 79)){
                            win(array, player1, player2, 4);
                            break;
                        }
                    }
                }
            }
        }
        count++;
    }

    // game draw situation
    if(count > 10){
        system("cls");
        displayPattern(array, player1, player2);
        red();
        printf("Game Draw !!!");
        white();
        printf("\n\n##########################################################");
        printf("\n\nPress any key to continue....");
        getch();
    } 

}

void playWithFriend()
{
    int array[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    char player1[20], player2[20];

    // accepting player's name
    acceptPlayersName(player1, player2);

    int count = 1;

    while(count < 10)
    {
        if(count % 2 == 1){
            player1Play(array, player1, player2); // player 1 playing

            if(count >= 5){
                if(checkResult(array, 88)){
                    win(array, player1, player2, 1);
                    break;
                }
            }
        }
        else{
            player2Play(array, player1, player2); // player 2 playing

            if(count >= 6){
                if(checkResult(array, 79)){
                    win(array, player1, player2, 2);
                    break;
                }
            }
        }

        count++;
    }

    if(count == 10){
        system("cls");
        displayPattern(array, player1, player2);
        red();
        printf("Game Draw !!!");
        white();
        printf("\n\n##########################################################");
        printf("\n\nPress any key to continue....");
        getch();
    }

}

void displayPattern(int array[], char player1[], char player2[])
{
    printf("\n\n####################### Tic Tac Toe #######################\n\n\n");

    yellow();
    printf("%s : X", player1);
    green();
    printf("\n\n%s : O\n\n\n", player2);
    white();

    printf("\t");
    
    int p = 0;

    for(int i = 0; i < 4; i++)
    {    
        for(int k = 0; k < 3; k++) {
            if(k > 0){
                printf("|     ");
            }
            else{
                printf("     ");
            }
        }

        if(i == 3)
            break; 

        printf("\n\t");

        for(int j = 0; j < 3; j++)
        {
            if(array[p] < 10){
                if(j > 0)
                    printf("|  %d  ", array[p]);
                else
                    printf("  %d  ", array[p]);
            }
            else{
                if(j > 0){
                    if(array[p] == 88){
                        printf("|");
                        yellow();
                        printf("  %c  ", array[p]);
                        white();
                    }
                    else{
                        printf("|");
                        green();
                        printf("  %c  ", array[p]);
                        white();
                    }
                }
                else{
                    if(array[p] == 88){
                        yellow();
                        printf("  %c  ", array[p]);
                        white();
                    }
                    else{
                        green();
                        printf("  %c  ", array[p]);
                        white();
                    }
                }
                    
            }
            p++;
        }

        printf("\n\t");

        if(i < 2){
            for(int k = 0; k < 3; k++) {
                if(k > 0)
                    printf("|_____");
                else
                    printf("_____");
            }

            printf("\n\t");
        }

    }

    printf("\n\n\n##########################################################\n\n");
}

void acceptPlayersName(char *player1, char *player2)
{
    system("cls");
    
    printf("\n\n\n\t\t\tPLAYER'S NAME");
    // Accepting player 1 details
    printf("\n\n\nEnter Player 1 Name : ");
    yellow();
    scanf("%s", player1);

    // Accepting player 2 details
    white();
    printf("\n\nEnter Player 2 Name : ");
    green();
    scanf("%s", player2);

    system("cls");
    white();
}

void player1Play(int array[], char player1[], char player2[])
{
    int marking_place; // variable to store user marking place value

    while(1){
        displayPattern(array, player1, player2); // to display pattern
        printf("\n%s, Enter Marking Place : ", player1);
        fflush(stdin);
        scanf("%d", &marking_place);

        if(marking_place > 0 && marking_place < 10 && array[marking_place - 1] < 10){
            array[marking_place - 1] = 88;
            break;
        }

        system("cls");
    }
    system("cls");
}

void player2Play(int array[], char player1[], char player2[])
{
    int marking_place; // variable to store user marking place value

    while(1){

        displayPattern(array, player1, player2); // to display pattern
        printf("\n%s, Enter Marking Place : ", player2);
        fflush(stdin);
        scanf("%d", &marking_place);

        if(marking_place > 0 && marking_place < 10 && array[marking_place - 1] < 10){
            array[marking_place - 1] = 79;
            break;
        }

        system("cls");
    }

    system("cls");
}

int playComputer(int array[], int marking_place)
{
    int i = marking_place + 1;

    while(i < 9){
        if(array[i] < 10){
            array[i] = 79;
            return i;
        }
        i++;
    }

    if(i == 9){
        i = marking_place - 1;
        while(i > 0){
            if(array[i] < 10){
                array[i] = 79;
                return i;
            }
            i--;
        }
    }
}

int checkResult(int array[], int symbol)
{
    int winArray[8][3] = {{1,2,3}, {4,5,6}, {7,8,9}, {1,4,7}, {2,5,8}, {3,6,9}, {1,5,9}, {3,5,7}};
    int count;

    for(int i = 0; i < 8; i++) {
        count = 0;
        for(int j = 0; j < 3; j++) {
            if(array[winArray[i][j] - 1] == symbol){
                count++;
                if(count == 3)
                    return 1;
            }
        }
    }

    return 0;
}

int checkSmartly(int array[], int symbol)
{
    int winArray[8][3] = {{1,2,3}, {4,5,6}, {7,8,9}, {1,4,7}, {2,5,8}, {3,6,9}, {1,5,9}, {3,5,7}};
    int marking_place, temp;

    for(int i = 0; i < 8; i++)
    {
        int count = 0;

        for(int j = 0; j < 3; j++)
        {
            marking_place = array[winArray[i][j] - 1];

            if(marking_place == symbol)
                count++;
            else
                if(marking_place < 10)
                    temp = marking_place;
                else
                    count--;
        }

        if(count == 2)
            return temp;
    }

    return 0;
}

int checkEvilly(int array[], int symbol)
{
    int winArray[8][3] = {{1,2,3}, {4,5,6}, {7,8,9}, {1,4,7}, {2,5,8}, {3,6,9}, {1,5,9}, {3,5,7}};
    int marking_place, temp, flag = 0;

    for(int i = 0; i < 8; i++)
    {
        int count = 0;

        for(int j = 0; j < 3; j++)
        {
            marking_place = array[winArray[i][j] - 1];

            if(marking_place == symbol)
                count++;
            else
                if(marking_place < 10)
                    temp = marking_place - 1;
                else
                    count--;
        }

        if(count == 2){
            array[temp] = 79;
            flag++;
        }
    }

    return flag;
}

int generateRandomValue(int array[])
{
    // to get random value between 1 to 9
        int value = ((rand() % (9 - 1 + 1)) + 1);

    while(value != array[value - 1]){
        value = ((rand() % (9 - 1 + 1)) + 1);
    }
    return value - 1;
}

void win(int array[],char player1[], char player2[], int x)
{
    system("cls");

    displayPattern(array, player1, player2);

    if(x == 1){
        yellow();
        printf("%s, Won the game", player1);
        white();
    }
    else if(x == 2){
        green();
        printf("%s, Won the game", player2);
        white();
    }
    else if(x == 3){
        green();
        printf("Smart Computer Won The Game");
        white();
    }
    else{
        red();
        printf("Evil Computer Won The Game");
        white();
    }

    printf("\n\n##########################################################\n\n");
    printf("Press any key to continue....");
    getch();

}

void red()
{
   printf("\033[0;31m");
}

void yellow()
{
   printf("\033[0;33m");
}

void green()
{
   printf("\033[0;32m");
}

void white()
{
    printf("\033[0;37m");
}