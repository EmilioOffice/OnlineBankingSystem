#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

struct user{
    char phone[50];
    char accNum[50];
    char password[50];
    float balance;
};

void ticketGenerator(float amount, struct user *user);
int verifAccNumber(struct user *user);
int verifPhoneNumber(struct user *user);
int verifPassword(struct user *user);

// THIS PROJECT HAS BEEN COMPLETED SUCCESSFULLY BY THE ENGINEER PRESENTING IT, THE MAIN INTEREST OF THIS PROJECT IS FOR PRACTICE //
// THIS PROJECT IS PROPERITY ALL RIGHTS RESERVED TO THE DEVELOPER OF THIS CODE Copyright © EMILIO MARQUEZ                        //

int main(){
    int verif = 0, verif2 = 0;
    struct user user, user2;
    FILE *arch;
    char fileName[50], phoneNumber[50], pword[50];
    char cont = 'y';
    int opt, opt2;
    float amount;
while(1){
    printf("\n|=======================================================|");
    printf("\n|=======|WELCOME TO YOUR ONLINE BANKING SYSTEM|=========|");
    printf("\n|=======================================================|");
    printf("\n|          What would you like to do today?             |");
    printf("\n|=======================================================|");
    printf("\n| 1 -- Register an Account                              |");
    printf("\n| 2 -- Login to your Account                            |");
    printf("\n| 3 -- Close Program                                    |");
    printf("\n|=======================================================|");
    printf("\n| Option:\t");
    scanf("%i",&opt);  
    if(opt == 1){
        while(1){
            printf("\n \n \n");
            printf("\n \n \n");
            printf("\n \n|=======================================================|");
            printf("\n| Enter your Account Number:\t");
            scanf("%s",user.accNum);
            if(verifAccNumber(&user) != 0){
            printf("|=======================================================|");
            printf("\n| Invalid Account Nummber, please try again...          |");
            printf("\n| the Account Number Must contain 16 digits and         |");
            printf("\n| Must be composed by numbers                           |");
            printf("\n|=======================================================|");
            }else{printf("\n| Enter your Phone Number:\t");
                scanf("%s",user.phone);
                if(verifPhoneNumber(&user) != 0){
                    printf("|=======================================================|");
                    printf("\n| Invalid Phone Number, please try again...            |");
                    printf("\n| the Phone Number Must contain 10 digits and           |");
                    printf("\n| Must be composed by numbers                           |");
                    printf("\n|=======================================================|");
                }else{
                    printf("\n| Create your password:\t");
                    scanf("%s",user.password);
                    if(verifPassword(&user) != 0){
                        printf("|=======================================================|");
                        printf("\n| Invalid Password, please try again...                 |");
                        printf("\n| the Password Must contain at least 8 digits and       |");
                        printf("\n| less than 12 digits, may include letters and numbers  |");
                        printf("\n|=======================================================|");
                    }else{
                        user.balance = 0;
                        strcpy(fileName,user.phone);
                        arch = fopen(strcat(fileName,".txt"),"w");
                        fwrite(&user,sizeof(struct user),1,arch);
                        if(fwrite != 0){
                            printf("\n|=======================================================|");
                            printf("\n| Account Saved Succesfully                             |");
                            printf("\n|=======================================================|");
                            break;
                        }else{
                            printf("\n|=======================================================|");
                            printf("\n| Something went Wrong, please try again                |");
                            printf("\n|=======================================================|");
                        }
                        fclose(arch);
                    }
                }
            }
        }
    }
    if(opt == 2){
        printf("\n \n \n");
        printf("\n \n \n");
        printf("\n\n|=======================================================|");
        printf("\n| Phone Number: ");
        scanf("%s",phoneNumber);
        printf("|=======================================================|");
        printf("\n| Password: ");
        scanf("%s",pword);
        printf("|=======================================================|");
        strcpy(fileName,phoneNumber);
        arch = fopen(strcat(fileName,".txt"),"r");
        if(arch == NULL){
            printf("\n| Phone Number is not registered                        |");
            printf("\n|=======================================================|");
        }else{
            fread(&user,sizeof(struct user),1,arch);
            fclose(arch);
            if(!strcmp(pword,user.password)){
                while(cont == 'y' || cont == 'Y'){
                printf("\n|=======================================================|");
                printf("\n|              WELCOME TO YOUR ACCOUNT                  |");
                printf("\n|=======================================================|");
                printf("\n| 1 -- Check My Balance                                 |");
                printf("\n| 2 -- Deposit to My Account                            |");
                printf("\n| 3 -- Cash Withdraw                                    |");
                printf("\n| 4 -- Online Transfer                                  |");
                printf("\n| 5 -- Change My Password                               |");
                printf("\n| 6 -- Close My Account                                 |");
                printf("\n|=======================================================|");
                printf("\n| Option: \t");
                scanf("%d",&opt2);
                switch(opt2){
                case 1:
                printf("\n|=======================================================|");
                printf("\n|                      YOUR ACCOUNT                     |");
                printf("\n|=======================================================|");
                printf("\n| BALANCE: %.2f                                    |",user.balance);
                printf("\n|=======================================================|");
                    break;
                case 2:
                    printf("\n|=======================================================|");
                    printf("\n|                      YOUR ACCOUNT                     |");
                    printf("\n|=======================================================|");
                    printf("\n| BALANCE: %.2f                               |",user.balance);
                    printf("\n|=======================================================|");
                    printf("\n| Enter the Deposit Amount: \t");
                    scanf("%f",&amount);
                    user.balance += amount;
                    arch = fopen(fileName,"w");
                    fwrite(&user, sizeof(struct user), 1, arch);
                    if(fwrite != NULL){
                    printf("|=======================================================|");
                    printf("\n| Amount Deposited Succesfully                          |");
                    }
                    fclose(arch);
                    printf("\n|=======================================================|");
                    ticketGenerator(amount, &user);
                    break;
                case 3:
                while(1){
                    printf("\n|=======================================================|");
                    printf("\n|                      YOUR ACCOUNT                     |");
                    printf("\n|=======================================================|");
                    printf("\n| BALANCE: %.2f                               |",user.balance);
                    printf("\n|=======================================================|");
                    printf("\n| Enter the Amount: \t");
                    scanf("%f",&amount);
                    if(amount > user.balance){
                        printf("|=======================================================|");
                        printf("\n| Amount exceds your balance, try a lower amount        |");
                        printf("\n|=======================================================|");
                    }else{
                        user.balance -= amount;
                        arch = fopen(fileName,"w");
                        fwrite(&user, sizeof(struct user), 1, arch);
                        if(fwrite != NULL){
                            printf("|=======================================================|");
                            printf("\n| Amount Withdrawn Succesfully                          |");
                            printf("\n|=======================================================|");
                        }
                        fclose(arch);
                        ticketGenerator(amount, &user);
                        break;
                    }
                }
                    break;
                case 4:
                while(1){
                    printf("\n|=======================================================|");
                    printf("\n|                      YOUR ACCOUNT                     |");
                    printf("\n|=======================================================|");
                    printf("\n| BALANCE: %.2f                               |",user.balance);
                    printf("\n|=======================================================|");
                    printf("\n| Phone Number that receives the transfer:  ");
                    scanf("%s",phoneNumber);
                    printf("|=======================================================|");
                    strcpy(fileName,phoneNumber);
                    arch = fopen(strcat(fileName,".txt"),"w");
                    if(arch == NULL){
                            printf("\n|=======================================================|");
                            printf("\n|The Account does not exist                             |");
                            printf("\n|=======================================================|");
                        }else{
                            fread(&user2, sizeof(struct user), 1, arch);
                            printf("\n| Enter the Amount: \t");
                            scanf("%f",&amount);
                            printf("|=======================================================|");
                            if(amount > user.balance){
                                printf("|=======================================================|");
                                printf("\n| Amount exceds your balance, try a lower amount        |");
                                printf("\n|=======================================================|");
                            }else{
                                user.balance -= amount;
                                user2.balance += amount;
                                fwrite(&user2, sizeof(struct user), 1, arch);
                                if(fwrite != NULL){
                                    printf("\n|=======================================================|");
                                    printf("\n| The transfer was processed succesfully                |");
                                    printf("\n|=======================================================|");
                                }
                                fclose(arch);
                                break;
                                }
                        }
                        }
                    break;
                case 5:
                    char pwordtemp [50];
                    while(1){
                        printf("\n|=======================================================|");
                        printf("\n| New password: ");
                        scanf("%s",pwordtemp);
                        if(!(strcmp(pwordtemp, user.password))){
                            if(verifPassword(pwordtemp) == 0){
                                strcpy(user.password,pwordtemp);
                                printf("\n|=======================================================|");
                                printf("\n|The password has been updated succesfully              |");
                                printf("\n|=======================================================|");
                            }else{
                                printf("\n|=======================================================|");
                                printf("\n|The password you entered does not fill the requirements|");
                                printf("\n|=======================================================|");
                            }
                        }else{
                            printf("\n|=======================================================|");
                            printf("\n|The new password cannot be equal to the one right now  |");
                            printf("\n|=======================================================|");
                        }
                    }
                    break;
                case 6:
                    if(user.balance > 0){
                        printf("\n|=======================================================|");
                        printf("\n| You need to have $0.00 balance                        |");
                        printf("\n|=======================================================|");
                        printf("\n|You may withdraw your full balance or transfer it      |");
                        printf("\n|=======================================================|");
                    }else{
                        remove(fileName);
                        if(!(remove(fileName) == 0)){
                            printf("\n|=======================================================|");
                            perror("\n| Error deleting the file                               |");
                            printf("\n|=======================================================|");
                        }else{
                            printf("\n|=======================================================|");
                            printf("\n| Your account has been succesfully closed              |");
                            printf("\n|=======================================================|");
                            printf("\n|We hope you enjoyed your experience with us            |");
                            printf("\n|=======================================================|");
                        }
                    }
                    break;
                default:
                    printf("\n|=======================================================|");
                    printf("\n| The option chosen is invalid                          |");
                    printf("\n|=======================================================|");
                    break;
                }
                printf("\n|=======================================================|");
                printf("\n| Would you like to process a New Transaction?   [Y/N]  |");
                printf("\n| Answer:\t");
                scanf("%s",&cont);
                printf("|=======================================================|");
                }
            }else{
                printf("\n|=======================================================|");
                printf("\n| Password Missmatch                                    |");
                printf("\n|=======================================================|");
            }
        }
    }
    if(opt == 3){
        printf("\n|=======================================================|");
        printf("\n|               ONLINE BANKING SYSTEM                   |");
        printf("\n|=======================================================|");
        printf("\n| Thank you for your preference on our service,         |");
        printf("\n| we try our best to provide the best for our           |");
        printf("\n| clients.                                              |");
        printf("\n|=======================================================|");
        printf("\n|=======================================================|");
        return 0;
    } 
        printf("\n\n\n\n\n");
    }
return 0;
}

int verifAccNumber(struct user *user){
    int i = 0, j;
    char nums[10] = "1234567890";
    while(user->accNum[i] != '\0'){
        j = 0;
        while(j < 10){
            if(user->accNum[i] != nums[j]){
                j++;
            }else{break;}
        }
        if(j == 10){
            return 1;
        }
        i++;
    }
    if(i != 16){
        return 1;
    }else{
        return 0;
    }
}

int verifPhoneNumber(struct user *user){
    int i = 0, j;
    char nums[10] = "1234567890";
        while(user->phone[i] != '\0'){
            j = 0;
            while(j < 10){
                if(user->phone[i] != nums[j]){
                    j++;
                }else{break;}
            }
            if(j == 10){
                return 1;
            }
            i++;
        }
        if(i != 10){
            return 1;
        }else{
            return 0;
        }
}

int verifPassword(struct user *user){
    int i = 0;
    while(user->password[i] != '\0'){
        i++;
    }
    if(i > 8 && i < 12){
        return 0;
    }else{
        return 1;
    }
}

void ticketGenerator(float amount, struct user *user){
    time_t now;
    time(&now); 
    printf("\n\n\n\n");
    printf("\n|=======================================================|");
    printf("\n|              BANKING SERVICE TICKET                   |");
    printf("\n|=======================================================|");
    printf("\n|\t%s",ctime(&now));
    printf("\n| Account number: %s                      |", user->accNum);
    printf("\n| Phone Number: %s                              |", user->phone);
    printf("\n| Amount: $%.2f                                     |", amount);
    printf("\n| Balance: $%.2f                                    |", user->balance);
    printf("\n|=======================================================|");
    printf("\n|=======================================================|");
    printf("\n|Thank you for your preference on our service           |");
    printf("\n|we always want to provide the best for our clients     |");
    printf("\n|and we really apreciate your loyalty                   |");
    printf("\n|=======================================================|");
    printf("\n|ALL RIGHTS RESERVED FOR THE DEVELOPER OF THE CODE      |");
    printf("\n\n\n\n");
}