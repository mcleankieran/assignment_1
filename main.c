#include <stdio.h>
#include <stdlib.h>


void encryptionRotation(char message[], int n ); // function to encrypt message using cipher rotation.
void decryptionRotation(char decryption[], int n); // function to decrypt message that was encrypted with cipher rotation.
void substitutionEncryption(char plainText[]); // function to encrypt a message with substitution cipher.
void substitutionDecryption(char text[]); // Function to decrypt a message that was encrypted with a substitution cipher.


int main() {
    
    int option; // So the user can choose what operation they will perform.
    int key; // The user will determine the rotation amount for the cipher encryption/decryption.
 
    printf("Please select what what operation you would like to perform from the options below.\n");
    printf("Option 1: Encryption of a message with a rotation cipher.\n");
    printf("Option 2: Decryption of a message with a rotation cipher.\n");
    printf("Option 3: Encryption of a message with a substitution cipher.\n"); 
    printf("Option 4: Decryption of a message with a substitution cipher.\n");
    
    scanf("%d", &option); // the integer will be scanned and stored in option
    
    char plainText[200]; // declare string plainText, it will hold 200 characters 
    char encryptedText[200]; // declare string encryptedText, it will hold 200 characters 
    char secretMessage[200]; // declare string secretMessage, it will hold 200 characters 
    char inputText[200]; // declare string inputText, it will hold 200 characters 
    
    
    switch(option) // Use a switch statement so the user can choose which operation to perform
    {   case 1: 
        printf("Enter message to be encrypted: \n");
        fgets(plainText, 200, stdin); //  The message will be stored in plainText
        
        printf("\nEnter a number for the key: \n");
        scanf("%d", &key); // The key is an integer, stored in key
        
        encryptionRotation(plainText, key); // Calling the function, sending plainText and key to the function
        
        printf("Encrypted message is: %s", plainText);
        break;
        
        
        case 2: printf("Enter message to be decrypted: \n");
        fgets(encryptedText, 200, stdin); //  The message will be stored in encryptedText
        printf("Message to be decrypted is: %s", encryptedText);
        
        printf("Enter a number for the key: \n");
        scanf("%d", &key); // The key is an integer, stored in key
        
        decryptionRotation(encryptedText, key); // Calling the function, sending encryptedText and key to the function
        
        printf("Decrypted message is: %s", encryptedText);
        break;
        
       
        case 3: printf("Enter message to be encrypted: ");
        fgets(secretMessage, 200, stdin); //  The message will be stored in secretMessage
        printf("%s", secretMessage);
        
        substitutionEncryption(secretMessage); // Calling the function, sending secretMessage to the function.
        
        printf("\nEncrypted message is %s", secretMessage);
        break;
        
        case 4: printf("Enter message to be decrypted: \n");
        fgets(inputText, 200, stdin); //  The message will be stored in inputText       
        
        substitutionDecryption(inputText); // Calling the function, sending inputText to the function.
     
        printf("\nDecrypted message is %s", inputText); 
        break;
        
    }
    
return 0;
}

void encryptionRotation(char message[], int n )
{
    int i; // i is an integer used as a counter
    
    for(i=0; message[i] != '\0'; i++)
    { // Operation to ensure input from the user is converted to capital letters
        if(message[i] >= 'a' && message[i] <= 'z') 
        {
            message[i] = message[i] - 32;
        }
        
        // Operation to apply the key
        if(message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = message[i] + n;
        }
        
        /* Operation to ensure that if any letters are less greater than Z, 
        they will rotate to the start of the alphabet again*/
        
        if(message[i]>'Z')
        {
            message[i] = message[i] - 'Z' +'A' -1;
        }
    }
}
   

void decryptionRotation(char decryption[], int n)
{
    int i; // i is an integer used as a counter

    for(i=0; decryption[i] != '\0'; i++)
    { // Operation to ensure input from the user is converted to capital letters
        if(decryption[i] >= 'a' && decryption[i]<= 'z')
        {
            decryption[i] = decryption[i] - 32; 
        }
        
        
        /* The ASCII value for space is 32. This operation ensures that spaces
        and characters are returned without change. */
       
        if(decryption[i] >= 'A' && decryption[i]<= 'Z' )
        {
            if(decryption[i] - n < 'A')
            {
                decryption[i] = (decryption[i] - n) + 'Z' -'A' +1;
            }
            
            // Operation to apply the key
            else
            {
                decryption[i] = decryption[i] - n;  
            }
        }
     }

}


void substitutionEncryption(char plainText[])
{
    int i; // i is an integer used as a counter
    char key[26];
    
    printf("Please input key: \nKey must be in capital letters and contain each letter of the alphabet just once.");
    scanf("%s", key); //Take in the key from user and store in key
    
        for (i= 0; plainText[i] != '\0'; i++)  
        
        {// Operation to ensure input from the user is converted to capital letters
           if(plainText[i] >= 'a' && plainText[i]<= 'z')
           {
              plainText[i] = plainText[i] - 32;  
           }
             
             /* Operation to apply the key and ensures that spaces and characters
             will be returned unmodified because I am only asking it to apply the
             key if characters are between 'A' and 'Z'*/
           if(plainText[i] >= 'A' && plainText[i]<= 'Z')
           {
              plainText[i] = key[plainText[i] - 65]; 
           }
           
        }
}

void substitutionDecryption(char text[])
{
    char key [26];
    char alphabet[26] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}; /* I have included the alphabet
    so that the key can be translated to the alphabet and then then I can return
    a decrypted message*/
    
    printf("Please input key: \nKey must be in capital letters and contain each letter of the alphabet just once.");
    scanf("%s", key); //Take in the key from user and store in key
    
    for(int i=0; text[i] != '\0'; i++)
    
    {// Operation to ensure input from the user is converted to capital letters
        if(text[i] >= 'a' && text[i]<= 'z')
           {
              text[i] = text[i] - 32;  
           }
           
           /*Operation to ensure that only characters between 'A' and 'Z' will be
           decrypted. All other characters will return unmodified*/
          
           if(text[i] >= 'A' && text[i]<= 'Z')
           {
            int a = 0; /* a is used as a counter. By setting a=0,
            I start the loop at the first character*/
            
            //Operation below is to apply the key.
            do
            {
                a++; 
                
                if (text[i] == key[a])
                {
                 text[i] = alphabet[a];
                 break;   
                }
                
            } while(text[i] != key[a]);
           }       
    }
}



    







