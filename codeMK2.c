//
// Created by sids on 6/12/18.
//
#include <stdio.h>
#include <stdlib.h> // For exit()
int code(char letter);
int main(int argc, char *argv[])
{
    FILE *messageFile = fopen(argv[1], "r");
    FILE *passPhraseFile = fopen(argv[2],"r");
    char messageChar, passPhraseChar;
    int passPhraseASCII, passPhrase, flag=1;
    int passPhraseDiff = 0, tempASCII, countPPDigit = 0;
    if (messageFile == NULL)
    {
        printf("Please give input File destination \n");
        exit(0);
    }
    if (passPhraseFile == NULL) {
        printf("Please Give PassPhrase destination \n");
        exit(0);
    }
    passPhraseChar = fgetc(passPhraseFile);
    while(passPhraseChar != EOF){
        if ((int)passPhraseChar != 10) {
            passPhraseASCII = (int) passPhraseChar;
            tempASCII = passPhraseASCII;
            while (tempASCII != 0){
                tempASCII = tempASCII/10;
                countPPDigit++;
            }
            if (flag == 1) {
                passPhraseDiff = passPhraseASCII;
                flag = 0;
            } else {
                passPhraseDiff = passPhraseDiff - passPhraseASCII;
            }
            passPhraseChar = fgetc(passPhraseFile);

        } else {
            break;
        }
    }
    passPhraseDiff = abs(passPhraseDiff);
    passPhrase = (passPhraseDiff / countPPDigit);

    printf("%d\n",passPhraseDiff);
    printf("%d\n",passPhrase);
    messageChar = fgetc(messageFile);
//    printf("Initial: %c",c);
    while (messageChar != EOF)
    {
        //fputc(c, fp);
        //printf ("%c", c);
        code(messageChar);
        messageChar = fgetc(messageFile);
    }
    printf("\n");
    fclose(messageFile);
    return 0;
}
int code(char letter){

    int ascii = (int) letter;
    printf("%d",ascii);
}
int sunCodePassPhrase(int number){
    int digit,code;
    while (number != 0){
        digit = number % 10;
        number = number/10;
    }
    switch (digit) {
        case '0':
            code = 0;
            break;
        case '1':
            code = 1;
            break;
        case '2':
            code = 10;
            break;
        case '3':
            code = 11;
            break;
        case '4':
            code = 100;
            break;
        case '5':
            code = 101;
            break;
        case '6':
            code = 110;
            break;
        case '7':
            code = 111;
            break;
        case '8':
            code = 1000;
            break;
        case '9':
            code = 1001;
            break;
    }
}
int code(int digit){
    
}