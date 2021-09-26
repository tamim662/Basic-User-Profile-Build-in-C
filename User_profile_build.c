#include<stdio.h>
#include<string.h>


#define FAIL_VAL -99999
#define SUCCESS_VAL 99999
#define MAX_USER 20
#define MAX_LEN 200

char emailArr[MAX_USER][MAX_LEN];
char passArr[MAX_USER][MAX_LEN];

char nameArr[MAX_USER][MAX_LEN];
char addressArr[MAX_USER][MAX_LEN];

int user_count=0;

int search_email(char email[]){
    int cnt=user_count;
    while(cnt>=0){
        if(strcmp(emailArr[cnt],email)==0)
            return cnt ; // True
        cnt--;
    }
    return 0; //False

}

int signupUser(char email[], char pass[]){
    int flag=1, temp;
    int cnt=user_count;

    //Duplicate Email Handle
    if(search_email(email)!=0){
        printf("This email already Used, Try with Another Email.");
        return 0; //False
    }
    // email validity check
    int check_a=0;
    for(int i=0;i<strlen(email); i++){
        if(email[i]=='@'){
            temp=i;
            for(int j=i; j<strlen(email); j++){
                if (email[j]=='.'){
                    check_a++;

                }

            }
        }

    }
    if(check_a==0){
        printf("Invalid Email!");
        flag=1; // False
    }
    else
        flag=0; //True


    //password lenght check
    if(strlen(pass)>=8){
        flag=0;
    }
    else{
        printf("Password length must ne at least 8!");
        flag=1;
    }
    //Uppercase check
    int check_up=0;
    for (int i=0; i<strlen(pass); i++){
        if(pass[i] >= 'A' && pass[i] <= 'Z'){
            check_up++;
        }
    }
    if(check_up==0){
        printf("Password must contain uppercase char!");
        flag=1;
    }
    else
        flag=0;

    //Lowercase check
    int check_low=0;
    for (int i=0; i<strlen(pass); i++){
        if(pass[i] >= 'a' && pass[i] <= 'z'){
            check_low++;
        }
    }
    if(check_low==0){
        printf("Password must contain lowercase char!");
        flag=1;
    }
    else
        flag=0;

    //Digit check
    int check_dig=0;
    for (int i=0; i<strlen(pass); i++){
        if(pass[i] >= 48 && pass[i] <= 57){ // 0-9 Ascii value
            check_dig++;
        }
    }
    if(check_dig==0){
        printf("Password must contain a Digit!");
        flag=1;
    }
    else
        flag=0;

    //Uppercase check
    int check_spec=0;
    for (int i=0; i<strlen(pass); i++){
        if(pass[i]=='$' || pass[i]=='#' ||pass[i]=='*' ||pass[i]=='@'){
            check_spec++;
        }
    }
    if(check_spec==0){
        printf("Password must contain Special Char like ($ # * @)!");
        flag=1;
    }
    else
        flag=0;

    // Store the Email and Pass of User
    if(flag==0){
        strcpy(emailArr[user_count], email);
        strcpy(passArr[user_count], pass);
        user_count++;
        printf("Account created");
    }

}

int loginUser(char email[], char pass[]){
    int found=search_email(email);
    if(found==0){
        printf("No Email Found!, First Sign Up.");
        return 1; //False
    }
    else{
        if(strcmp(pass,passArr[found])==0){
            printf("Login Successful:)");
            return 0;
        }
        else{
            printf("Wrong Password!");
            return 1;

        }
    }
}

int buildUserProfile(char email[], char firstName[], char lastName[], char address[]){
    int found=search_email(email);
    if(found==0){
        printf("Email Doesn't Exists!");
        return 1; //False
    }
    else{
        strcat(strcat(firstName," "),lastName);
        strcpy(nameArr[found],firstName);
        strcpy(addressArr[found],address);
        return 0; //True

    }

}

void searchByName(char name[]){
    int ind=user_count;
    while(ind>=0){
        if(strcmpi(name,nameArr[ind])==0){
            printf("%s\n", emailArr[ind]);
            printf("%s\n", nameArr[ind]);
            printf("%s\n", addressArr[ind]);
        ind--;
        }
    }
    printf("Not Found!");

}

void searchByAddress(char address[]){
    int ind=user_count;
    while(ind>=0){
        if(strcmpi(addressArr[ind],address)==0){
            printf("%s\n", emailArr[ind]);
            printf("%s\n", nameArr[ind]);
            printf("%s\n", addressArr[ind]);
        ind--;
        }
    }
    printf("Not Found!");
}

int main()
{
        while(1)
        {
            printf("*******************************************************************\n");
            printf("1. signup User. 2. login User. 3. build User Profile. 4.Search By Name. 5. Search By Address. 6.exit \n");

            int choice;
            scanf("%d",&choice);

            if(choice==1){

                char mail[MAX_LEN], pass[MAX_LEN];
                printf("give User Email :");
                scanf("\n%[^\n]s",mail);
                printf("give User Password :");
                scanf("\n%[^\n]s",pass);
                signupUser(mail,pass);
            }

            if(choice==2){

                char mail[MAX_LEN], pass[MAX_LEN];
                printf("give User Email :");
                scanf("\n%[^\n]s",mail);

                printf("give User Password :");
                scanf("\n%[^\n]s",pass);

                loginUser(mail,pass);
            }

            if(choice==3){

                char mail[MAX_LEN], fname[MAX_LEN], lname[MAX_LEN], address[MAX_LEN];
                printf("give User Email :");
                scanf("\n%[^\n]s",mail);
                printf("%s\n",mail);
                printf("give First Name :");
                scanf("\n%[^\n]s",fname);
                printf("%s\n",fname);
                printf("give Last Name :");
                scanf("\n%[^\n]s",lname);
                printf("%s\n",lname);
                printf("give Address :");
                scanf("\n%[^\n]s",address);
                printf("%s\n",address);

                buildUserProfile(mail,fname,lname,address);
            }

            if(choice==4){

                char name[MAX_LEN];
                printf("give User Name :");
                scanf("\n%[^\n]s",name);

                searchByName(name);
            }

             if(choice==5){

                char address[MAX_LEN];
                printf("give User Address :");
                scanf("\n%[^\n]s",address);

                searchByAddress(address);
            }
            if (choice==6){
                break;
            }




        }

}
