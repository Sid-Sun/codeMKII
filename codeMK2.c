//
// Created by sids on 6/12/18.
//
#include <stdio.h>
#include <stdlib.h> // For exit()
int code(char letter);
int sunCodePassPhrase(int number, int count);
unsigned concatenate(unsigned x, unsigned y);
int actCode(int digit);
int main(int argc, char *argv[])
{
    FILE *messageFile = fopen(argv[1], "r");
    FILE *passPhraseFile = fopen(argv[2],"r");
    FILE *outputFile = fopen(argv[3],"w");
    char messageChar, passPhraseChar;
    int messageArray[1000];
    char minus = *"-";
    int a=7260703;
    long long int temp1,temp2,temp3;
    long long int messageIndivisualEncoded;
    int passPhraseASCII, passPhrase, flag=1,SPP, passPhraseDiff = 0, tempASCII, countPPDigit = 0;
    int messageASCII,n=0,i=0;
    if (messageFile == NULL)
    {
        printf("Please give input File destination \n");
        exit(0);
    }
    //Start Code for PP calculation
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
    //PP Calculation ended
    //Start calculations for SPP
    tempASCII = passPhrase;
    countPPDigit = 0;
    while (tempASCII != 0){
        tempASCII = tempASCII/10;
        countPPDigit++;
    }
    SPP = sunCodePassPhrase(passPhrase,countPPDigit);
    //SPP Calculated
    //Start Message calculations
    messageChar = fgetc(messageFile);
    while (messageChar != EOF)
    {
        printf("Char: %c, ASCII: %d\n",messageChar, (int)messageChar);
        messageASCII = (int) messageChar;
        messageIndivisualEncoded =  (long long int) ((a + messageASCII*SPP)/(long long int)passPhrase);
        messageArray[n] = messageIndivisualEncoded;
//        messageArray[n+1] = *"-";
        n++;
        messageChar = fgetc(messageFile);
    }
    for (i=0;i<n;i++){
        fprintf(outputFile,"%d", messageArray[i]);
        putc(minus, outputFile);
    }
    fclose(outputFile);
    fclose(passPhraseFile);
    fclose(messageFile);
    return 0;
}
/*int code(char letter){
    int ascii = (int) letter;

    printf("%d\n",ascii);
}*/
int sunCodePassPhrase(int number, int count){
    int digit,code,spp = 1,flag = 1, digitArray[count],n=1;
    unsigned int pow = 10;
  //  printf("Count: %d",count);
  //  printf("Got: %d\n",number);
    while (number != 0){
        digit = number % 10;
        digitArray[count-n] = digit;
        n++;
        number = number/10;
    }
    for (n=0;n<count;n++){
        code = actCode(digitArray[n]);
        if(flag==1){
            spp = code;
            flag = 0;
        } else {
            spp = concatenate(spp, code);
        }
    }
    return spp;
}
unsigned concatenate(unsigned x, unsigned y) {
    unsigned pow = 10;
    while(y >= pow)
        pow *= 10;
    return x * pow + y;
}
int actCode(int digit){
    int code;
    switch (digit) {
        case 0:
            code = 0;
            break;
        case 1:
            code = 1;
            break;
        case 2:
            code = 10;
            break;
        case 3:
            code = 11;
            break;
        case 4:
            code = 100;
            break;
        case 5:
            code = 101;
            break;
        case 6:
            code = 110;
            break;
        case 7:
            code = 111;
            break;
        case 8:
            code = 1000;
            break;
        case 9:
            code = 1001;
            break;
        default:
            break;
    }
    return code;
}