#include "bankingsystem.h"

int main(){

    printf("\n What do you want to do?");
    printf("\n\n1. Register an account");
    printf("\n2. Login to an account");    

    printf("\n\nYour choice:\t");
    scanf("%d", &opt);
    
    if (opt==1){
        system("cls");
        printf("Enter your account number:\t");
        scanf("%s", usr.ac);
        printf("Enter your phone number:\t");
        scanf("%s", usr.phone);
        printf("Enter your new password:\t");
        scanf("%s", usr.password);
        usr.balance=0;
        strcpy(filename, usr.phone);
        fp = fopen(strcat(filename, ".dat"), "w");
        fwrite(&usr, sizeof(struct user),1, fp);
        if (fwrite != 0){
            printf("\n\nAccount succesfully registered");
        }else{
            printf("\n\nSomething went wrong please try again");
        }
        fclose(fp);
    }
    if (opt == 2){
        system("cls");
        printf("\nPhone number:\t");
        scanf("%s", phone);
        printf("Password:\t");
        scanf("%s", pword);
        strcpy(filename, phone);
        fp= fopen(strcat(filename,".dat"),"r");
        if (fp == NULL){
            printf("\nAccount number not registered");
        } else{
        fread(&usr, sizeof(struct user),1,fp);
        fclose(fp);
        if (!strcmp(pword, usr.password)){
            while(cont == 'y'){
                system("cls");
                printf("\n\tWelcome (%s)", usr.phone);
                printf("\nPress 1 for Balance Inquiry");
                printf("\nPress 2 for Depositing Cash");
                printf("\nPress 3 for Cash Withdrawl");
                printf("\nPress 4 for Online Transfer");
                printf("\nPress 5 for Password Change");
                printf("\n\nYour choice:\t");
                scanf("%d", &choice);

                switch (choice){
                    case 1:
                    printf("\nYour current balance is Rs.%.2f", usr.balance);
                    break;
                    
                    case 2:
                    printf("\nEnter the amount:\t");
                    scanf("%f", &amount);  
                    usr.balance += amount; 
                    fp= fopen(filename, "w");
                    fwrite(&usr, sizeof(struct user),1,fp);
                    if(fwrite != NULL) printf("\nSuccesfully deposited.");
                    fclose(fp);
                    break;
                   
                    case 3:
                    printf("\nEnter the amount:\t");
                    scanf("%f", &amount);  
                    usr.balance -= amount; 
                    fp= fopen(filename, "w");
                    fwrite(&usr, sizeof(struct user),1,fp);
                    if(fwrite != NULL) printf("\nYou have withdrawn Rs.%.2f",amount);
                    fclose(fp);
                    break;

                    case 4:
                    printf("\nPlease enter the phone number to transfer the balance:\t");
                    scanf("%s", phone);
                    printf("\nPlease enter the amount to transfer:\t");
                    scanf("%f", &amount);
                    strcpy(filename, phone);
                    fp= fopen(strcat(filename, ".dat"), "r");
                    if (fp == NULL) printf("\nAccount number not registered");
                    else {
                         fread(&usr1, sizeof(struct user),1,fp);
                    fclose(fp);
                    if (amount > usr.balance) printf("\nInsufficient balance");
                    else{  
                        fp = fopen(filename, "w");
                        usr1.balance += amount;
                        fwrite(&usr1, sizeof(struct user),1,fp);
                        fclose(fp);
                        if (fwrite!=NULL){
                            printf("\nYou have succesfully transfered Rs.%.2f to %s", amount, phone);
                            strcpy(filename, usr.phone);
                            fp= fopen(strcat(filename, ".dat"), "w");
                            usr.balance -= amount;
                            fwrite(&usr, sizeof(struct user),1,fp);
                            fclose(fp);
                        }
                    }
                    break;

                    case 5:
                    printf("\nPlease enter your new password:\t");
                    scanf("%s", pword);
                    fp = fopen(filename, "w");
                    strcpy(usr.password, pword);
                    fwrite(&usr, sizeof(struct user),1,fp);
                    if (fwrite !=NULL)
                    printf("\nPassword succesfully changed");
                }
                break;
                default:
                printf("\nInvalid option");
                    }   
                printf("\nDo you want to continue the transaction [y/n]\t");
                scanf("%s", &cont);
            }
        }
        else{
            printf("\nInvalid password");
        }
        }
        printf("\n\t**Thank you for Banking**\n\n");
    }
    return 0;
}