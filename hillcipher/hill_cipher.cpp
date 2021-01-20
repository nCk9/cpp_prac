// C++ code to implement Hill Cipher 
#include <iostream> 
#include<fstream>
#include<string>
#include<vector>
using namespace std; 
  
// Following function encrypts the message 
void encrypt(int cipher_Matrix[][1], 
             int **keyMatrix,  
             int message_Vector[][1] ,int n) 
{ 
    int x, i, j; 
    for (i = 0; i < n; i++)  
    { 
        for (j = 0; j < 1; j++) 
        { 
            cipher_Matrix[i][j] = 0; 
           
             for (x = 0; x < n; x++) 
            { 
                cipher_Matrix[i][j] +=  
                     keyMatrix[i][x] * message_Vector[x][j]; 
            } 
          
            cipher_Matrix[i][j] = cipher_Matrix[i][j] % 26; 
        } 
    } 
} 
  
// Function to implement Hill Cipher 
void HillCipher(string message, int **keyMatrix, int n) 
{ 
    string CipherText;

    int k;
    for(k=1; k<=message.size(); k+=n)
    {int message_Vector[n][1]; 
     int g=k-1;
    // Generate vector for the message 
    for (int i = 0; i < n; i++) 
        {message_Vector[i][0] = (message[g]) % 97; g++;} 
  
    int cipher_Matrix[n][1]; 
  
    // Following function generates 
    // the encrypted vector 
    encrypt(cipher_Matrix, keyMatrix, message_Vector, n); 
  
     
  
    // Generate the encrypted text from  
    // the encrypted vector 
    for (int i = 0; i < n; i++) 
        CipherText += cipher_Matrix[i][0] + 97;

    for(int i=0; i<n; i++)
        cipher_Matrix[i][0] = 0;
    }

    cout << "Key Matrix : \n";
    for(int i=0; i<n; i++)
       {
            for(int j=0; j<n; j++)
                cout << keyMatrix[i][j] << " ";
            cout << "\n";
       } 

    cout << "\nPlain text : \n"; 
    for(int i=0, count=0; i<message.size(); i++)
    {
        cout << message[i];
        count++;
        if(count == 79)
        {
            count = 0 ;
            cout << "\n";
        }
    }  
    
    cout << "\nCipher Text : \n";
    // Finally print the ciphertext 
    for(int i=0, count=0; i<CipherText.size(); i++)
    {
        cout << CipherText[i];
        count++;
        if(count == 79)
        {
            count = 0 ;
            cout << "\n";
        }
    }   cout <<"\n";
} 


string key_file(string &filename)
{
    ifstream source;
    source.open(filename);
    string key_input;
    string input;
    while(getline(source, input))
    {
        if(input.empty())
            break;
        else
        {
            for(int i=0; i<input.size(); i++)
                if(input[i] == ' ')
                    {
                        input.erase(i, 1);
                        i--;
                    }
        }    
         key_input += input;
    }
    // key_input += '\0';
    return key_input;
}
  
string msg_file(string &filename, int n)
{
    ifstream source;
    source.open(filename);
    string msg;
    string input;
    while(getline(source, input))
       {
          if(input.empty())
            break;
          else 
            {
                for (int i = 0; i < input.size(); i++) 
                {  
                    if (input[i] < 'A' || input[i] > 'Z' && 
                        input[i] < 'a' || input[i] > 'z')  
                        {    
                            input.erase(i, 1);  
                            i--; 
                        }
                    else if(input[i] >= 'A'  &&  input[i] <= 'Z')
                        input[i] += 32 ; 
                }
                msg += input;   
            }
       } 

    int g = msg.size()%n;
    if(n-g != 0)
        {
            for(int i=1; i<=n-g; i++)
                msg += 'x';
        }
    
    return msg;
}

int main(int argc, char **argv)    //getting command line inputs in form of text files... 
{ 
     string  key_filename(argv[1]);
     string  plntxt_filename(argv[2]);
     string key = key_file(key_filename);
     int n = key[0] - '0';
     string  message = msg_file(plntxt_filename, n);


     
    
     int d=1;

     int **keyMatrix = new int*[n];

     for(int i=0; i<n; i++)
     {
        keyMatrix[i] = new int[n];
     }
     for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            {
                keyMatrix[i][j] = key[d] - '0';
                d++;
            } 
        
    HillCipher(message, keyMatrix, n); 
  
    return 0; 
} 