#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int db[100] = {0};
int dbMoney[100] = {0};

int main(){
    srand(time(NULL));
    int age=0;
    int optionMain=0;
    int optionLogin = 0;
    int optionReg = 0;
    int playerId=0;
    int playerId2=0;
    int flag=0;
    int global_flag=0;
    int dbIndex=0;
    int moneyInAccIndex = 0;
    int bet = 0;
    int winningNum = 0;
    int guessNum = 0;

    while (1){
        printf("\n|-----NCC lottery game-----|\n");
        printf("\nEnter your age:");
        scanf("%d",&age);

        if(age>17){
            printf("\nWelcome to our game.\n");

            while (1){
                flag = 0;
                global_flag = 0;
                printf("\n\tPress 1 to Login.\n\tPress 2 to Register.\n\tPress 3 to Complete Quit.\n\tPress 4 to Read about the game.\n\tYour choice:");
                scanf("%d",&optionMain);
                printf("\n\n");

                while (1){
                    if (optionLogin==3){
                        printf("\n\tPress 1 to Login.\n\tPress 2 to Register.\n\tPress 3 to Complete Quit.\n\tPress 4 to Read about the game.\n\tYour choice:");
                        scanf("%d",&optionMain);
                        printf("\n\n");
                    }
                    if(optionMain==1){
                        printf("|----Login----|\n");
                        printf("Enter your id:");
                        scanf("%d",&playerId);

                        for(int i=0; i<100 ; i++){
                            if(db[i] == playerId){
                                flag=1;
                                moneyInAccIndex=i;
                                break;
                            }
                        }

                        if(flag==1){
                            printf("You Can play game.\n");
                            printf("The money in your account is %d\n\n", dbMoney[moneyInAccIndex]);

                            while (1){
                                printf("Press 1 to Top up money.\nPress 2 to Play the game.\nPress 3 to Log out.\nPress 4 to Exit the game.\nYour choice:");
                                scanf("%d",&optionLogin);
                                printf("\n");

                                if (optionLogin==1){
                                    int topUp = 0;
                                    printf("How much do you want to top up:");
                                    scanf("%d",&topUp);
                                    dbMoney[moneyInAccIndex] +=topUp;
                                    printf("The money in your account is %d\n\n", dbMoney[moneyInAccIndex]);
                                    continue;
                                } else if (optionLogin==2){
                                    while (1){
                                        if (dbMoney[moneyInAccIndex]>=10000){
                                            winningNum = rand()%100;
                                            printf("%d",winningNum);    // This line is to know the random winning number.
                                            printf("\nEnter your guess number:");
                                            scanf("%d",&guessNum);
                                            printf("Enter your bet:");
                                            scanf("%d",&bet);
                                            dbMoney[moneyInAccIndex]-=bet;

                                            if (winningNum==guessNum){
                                                printf("\nCongratulations!!\nYou won the lottery.\n");
                                                dbMoney[moneyInAccIndex] += (bet*10);
                                                printf("The money in your account is %d\n\n", dbMoney[moneyInAccIndex]);
                                            } else{
                                                printf("\nYou were not lucky enough to win the game.Good Luck!\n");
                                                printf("The money in your account is %d\n\n", dbMoney[moneyInAccIndex]);
                                            }

                                            printf("Press 1 to Play the game again.\nPress 2 to Choose the options again.\nPress 3 to exit the game.\nYour choice:");
                                            scanf("%d",&optionLogin);
                                            printf("\n");

                                            if (optionLogin==1){
                                                continue;
                                            }else if(optionLogin==2){
                                                break;
                                            } else if(optionLogin==3){
                                                exit(1);
                                            } else{
                                                printf("Invalid Option\n");
                                                break;
                                            }

                                        } else{
                                            printf("You don't have enough money to play the game!\nPlease top up.\n\n");
                                            break;
                                        }
                                    }
                                }else if (optionLogin==3){
                                    break;
                                }else if (optionLogin==4){
                                    exit(1);
                                } else {
                                    printf("Invalid option!!\nPlease choose a correct option.\n");
                                    continue;
                                }
                            }
                        } else{
                            printf("Your id is not valid!\n\n");
                            printf("Press 1 to retry Login.\nPress 2 to exit Login.\nYour choice:");
                            scanf("%d",&optionReg);
                            printf("\n");
                            if (optionReg==1){
                                continue;
                            } else if(optionReg==2){
                                break;
                            } else{
                                printf("Invalid Option\n");
                                break;
                            }
                        }
                    }

                    else if(optionMain==2){
                        if(global_flag==1){
                            break;
                        }

                        printf("|----Register----|:\n");
                        printf("Please Enter your id:");
                        scanf("%d",&playerId);

                        for(int i=0; i<100; i++){
                            if(db[i]==playerId){
                                flag=1;
                            }
                        }
                        while (1){
                            if(flag==1){
                                printf("User Id Already Taken!\nTry again..\n\n");
                                flag = 0;
                                break;
                            } else{
                                printf("Confirm your ID:");
                                scanf("%d",&playerId2);

                                if(playerId==playerId2){
                                    db[dbIndex]=playerId;
                                    dbIndex++;
                                    printf("\nRegistration success.\n");
                                    printf("Please Login to play the game.\n");
                                    global_flag=1;
                                    break;
                                } else{
                                    printf("\nId not same!\nTry again.\n\n");
                                    break;
                                }
                            }
                        }

                    }
                    else if(optionMain==3){
                        exit(1);
                    }
                    else if(optionMain==4){
                        printf("The type of this game is a lottery game that the player have to buy a ticket with guessed number and the winning number is between 1 and 99, and will be random. The minimum price for a ticket is 3000 and the player can bet as much money as he wants. The winner will get 10x of his bet.\n\n");
                        break;
                    }
                    else{
                        printf("Invalid Option!\n");
                        break;
                    }
                }
            }
        }
        else{
            printf("You are not old enough to play the game!\n");
            break;
        }
    }
    return 0;
}