/*  Title: Rotation Cipher
    Description: This code takes in a message and produces a cipher of that message using a Rotation Cipher.
    Usage: Please enter the message you want to encrypt: lunchtime
           The ciphered text is (key shift = 2) nwpejvkog
*/



#include<stdio.h>

// Define my function
void Cipher(char* plainText, int key);

int main()
{
   int key = 2;
   char plainText[150];
   
   printf("please enter the message that you want to encrypt: ");
   scanf("%s", plainText);
   
   
}
