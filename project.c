#include "stdio.h"
#include "stdlib.h"
#define SIZE 100

struct staff{
    int id;
    int age;
    char name[30];
    char email[50];
    char password[50];

};

struct staff info[SIZE];
int globalIndex = 0;
int eFound = -1, pFound = -1;

void printingAllData();
int strInput(char str[]);
int stringLen(const char *str);
int stringCmp(char *str1, char *str2);
void passChecking(char pass[50], int userIndex);
void registration();
void login();
void lobby();
void userActionSector();
void recordingAllDataToFile();
void loadingAllDataFromFile();
int emailValidation(char *str);

int main(){
    char str[50];
    strInput(str);
    int i = emailValidation(str);
    if (i == 1) printf("True");
    else printf("False");
    return 0;
}

void printingAllData(){
    for(int i=0; i< globalIndex ; i++ ){
        printf("id: %d-name:%s - age:%d - email:%s - password:%s\n",info[i].id,info[i].name , info[i].age , info[i].email , info[i].password);
    }
}

int strInput(char str[]){
    int ch, i = 0;
    while ((ch=getchar()) != '\n') str[i++] = (char)ch;
    str[i] = '\0';
    return i;
}

int stringLen(const char *str){
    int n=0;
    while(str[n++] != '\0');
    return n-1;
}

int stringCmp(char *str1, char *str2){
    int index=0;
    if(stringLen(str1) == stringLen(str2)){
        while(str1[index] != '\0'){
            if(str1[index] == str2[index])
                index++;
            else
                return -1;
        }
        return 1;
    }
    else
        return -1;
}

void passChecking(char pass[50], int userIndex){
    int flag = stringCmp(info[userIndex].password, pass);
    pFound = flag == 1 ? 1 : -1;
}

void registration(){
    char name[30];
    char email[50];
    char passWord[50];
    printf("This is registration!\n");
    printf("Enter your email:");
    strInput(email);
    // Email validation
    if (emailValidation(email) == -1){
        printf("Invalid email!\n");
        int retry = 0;
        printf("Enter 1 to retry:\nEnter 2 to exit:");
        scanf("%d", &retry);
        if (retry == 1) registration();
        else recordingAllDataToFile();
    }
    // Email checking
    else{
        eFound=-1;
        int flag = 0;
        for (int i = 0; i < globalIndex; ++i) {
            flag = stringCmp(info[i].email, email);
            if (flag == 1){
                printf("This email has been used to create an account.\n");
                int retry = 0;
                printf("Enter 1 to retry:\nEnter 2 to exit:");
                scanf("%d", &retry);
                if (retry == 1) registration();
                else recordingAllDataToFile();
            } else{

            }
        }
    }
}

void login(){
    char lEmail[50];
    char passWord[50];
    int found  = -1;
    int flag = 0;
    printf("This is login form:\n");

    // Email checking
    printf("Enter your email to login:");
    strInput(lEmail);
    eFound = -1;
    for (int i = 0; i < globalIndex; ++i) {
        flag = stringCmp(info[i].email, lEmail);
        eFound = flag == 1 ? i : -1;
        if (eFound != -1) break;
    }

    // Password checking
    printf("Enter your password :");
    strInput(passWord);
    pFound = -1;
    passChecking(passWord , eFound);

    if(eFound != -1 && pFound == 1){
        userActionSector();
    } else{
        printf("Invalid email: or Password \n");
        int retry = 0;
        printf("Enter 1 to retry login:\nEnter 2 to exit:");
        scanf("%d", &retry);
        if (retry == 1) login();
        else recordingAllDataToFile();
    }
}

void lobby(){
    int lob=0;
    printf("This is Lobby Sector!\n");
    printf("Press 1 to Register:\n");
    printf("Press 2 to Login:\n");
    printf("Press 3 to Exit:");
    scanf(" %d",&lob);

    if(lob == 1){
        registration();
    } else if(lob == 2){
        login();
    } else if(lob == 3){
        recordingAllDataToFile();
        exit(1);
    } else{
        printf("Invalid Option!\n");
        lobby();
    }
}

void userActionSector(){
    int userAction=0;
    wrongInput:
    printf("Welcome Sir: %s\n",info[eFound].name);
    printf("Press 1 to User Action Sector:\n");
    printf("Press 2 to Home:\n");
    printf("Press 3 to Exit:");
    scanf(" %d",&userAction);

    switch (userAction) {
        case 1:
            printf("this is user action sector:\n");
            break;
        case 2:
            lobby();
            break;
        case 3:
            recordingAllDataToFile();
            break;
        default:
            printf("Invalid Option!\n");
            goto wrongInput;
    }
}

void recordingAllDataToFile(){
    FILE *fptr = fopen("dipDB.txt","w");
    if(fptr == NULL){
        printf("Error at recordingAllDataToFile fun():\n");
    } else{
        for(int i=0; i<globalIndex; i++){
            fprintf(fptr , "%d %d %s %s %s\n",info[i].id , info[i].age , info[i].name , info[i].email  , info[i].password);
        }
        printf("Recording all data to dipDB.txt is complete!\n");
    }
    fclose(fptr);
}

void loadingAllDataFromFile(){
    FILE *fptr = fopen("dipDB.txt","r");
    if(fptr == NULL){
        printf("Error at loading!\n");
    } else{
        for(int i=0; i<SIZE ; i++){
            fscanf(fptr ,"%d%d%s%s%s",&info[i].id , &info[i].age, &info[i].name,&info[i].email,&info[i].password);
            if(info[i].name[0] == '\0'){
                break;
            }
            globalIndex++;
        }
    }
}

int emailValidation(char *str){
    int strLength = stringLen(str);
    int flag = 0;
    int i = 0;
    int j;

    // return -1 if the email starts with numbers
    if (str[0] >= '0' && str[0] <= '9') return -1;

    // Checking the '@' character
    for (; i < strLength; ++i) {
        if (str[i] == '@'){
            flag = 1;
            break;
        }
    }

    // return -1 if the recipient name is missing. Example: @gmail.com
    if (i < 5) flag = 0;
    if (flag == 0) return -1;

    // Checking the '.' character for the top level domain. If the '.' is before '@', this won't be counted.
    else{
        flag = 0;
        for (j = i; j < strLength; ++j) {
            if (str[j] == '.'){
                flag = 1;
                break;
            }
        }
        // return -1 if the domain name is missing after '@' and before the top level domain. Example: john@.com
        if ((j-i) < 4) flag = 0;
        if (flag == 0) return -1;
    }

    // return -1 if the top level domain is missing. Example: john@gmail.
    if (strLength - (j-i) < 3){
        return -1;
    }
    return 1;
}
