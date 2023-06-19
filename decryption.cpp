/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: 

:

Gradescope is my life
I will document every single line of my code
I will not shed tears while I write my code
I am currently working on trying to fix the problems I created when I tried to fix the problems
I created when I tried to fix the problems I created when ...
@returns :
*/

#include<iostream>
#include <string>
using namespace std;

char shiftChar(char c, int rshift){
  int x,o;
  o = (int)c;
  x=o + rshift;
  if((x>122 && o>96 &&o<123)||(x>90&&o>64&&o<91)){
    x-=26;
  }
  else if(!isalpha(x)){
    x = o;
  }
  return x;
}

char shiftCharl(char c, int lshift){
  int x,o;
  o = (int)c;
  x = o - lshift;
  if((x<97 && o>96 &&o<123)||(x<65&&o>64&&o<91)){
    x+=26;
  }
  else if(!isalpha(x)){
    x = o;
  }
  return x;
}

string encryptCaesar(string plaintext, int rshift){
  for(int i = 0;i < plaintext.length();i++){
    if((int)plaintext[i]>64&&(int)plaintext[i]<123){
      plaintext[i] = shiftChar(plaintext[i],rshift);
    }
  }
  return plaintext;
}

string encryptVigenere(string plaintext,string keyword){
  int c = 0;
  string x;
  for(int i = 0;i < plaintext.length();i++){
    int num = plaintext[i];
    if(isalpha(plaintext[i])){
      x += shiftChar(num,((int)keyword[(c%keyword.length())]-97));
      c++;
    }
    else{
      x+=plaintext[i];
    }
  }
  return x;
}

string decryptCaesar(string ciphertext, int rshift){
  for(int i = 0;i < ciphertext.length();i++){
    if( (int)ciphertext[i]>64&&(int)ciphertext[i]<123){
      ciphertext[i] = shiftCharl(ciphertext[i],rshift);
    }
  }
  return ciphertext;
}

string decryptVigenere(string ciphertext,string keyword){
  int c = 0;
  string x;
  for(int i = 0;i < ciphertext.length();i++){
    int num = ciphertext[i];
    if(isalpha(ciphertext[i])){
      x += shiftCharl(num,((int)keyword[(c%keyword.length())]-97));
      c++;
    }
    else{
      x+=ciphertext[i];
    }
  }
  return x;
}

int main(){
  string x,n,k;
  int s;
  cout << "Enter plaintext: ";
  getline(cin,x);
  cout <<"\n= Caesar= \nEnter shift: ";
  cin >> s;
  n = encryptCaesar(x,s);
  cout << "Ciphertext: " << n << endl;
  n = decryptCaesar(n,s);
  cout << "Decrypted: " << n;
  cout <<"\n= Vigenere= \nEnter keyword: ";
  cin >> k;
  n = encryptVigenere(x,k);
  cout << "Ciphertext: " << n << endl;
  n = decryptVigenere(n,k);
  cout << "Decrypted: " << n << endl;

  return 0;
}
