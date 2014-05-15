/* 
 * File:   main.cpp
 * Author: matthew
 *
 * Created on May 14, 2014, 3:31 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;
string punct_mover(string word, int spaceLoc){
    int length = word.length();
    int flag = 0;
    int punctLoc;
    word.c_str();
    
    for(int i = 0; i <= length; i++){ //looks for punctuation, raises flag if found
        if((word[i] == ':') || (word[i] == ';') || (word[i] == ',') || (word[i] == '.') || (word[i] == '?') || (word[i] == '!')){
            punctLoc = i;
            flag = 1;
        }
    }
    if(flag == 1){
        string strword(word);
        string newword = strword.substr(0,punctLoc) + strword.substr(punctLoc+1,length)+ strword.substr(punctLoc,1);
        return newword; // new word with the punctuation moved to end
    }
    else{
        string strword(word);
        return strword;
    }
}
string consonant_mover(string word, int flag, char firstLetter, int spaceLoc){ //consonant and vowel are the same besides the word endings
    if(flag == 0) // words without an uppercase first letter
        word = word.substr(1,word.length()) + firstLetter + "ay";
    else{
        word.c_str();
        char newlower = tolower(firstLetter);
        char newupper = toupper(word[1]);
        string strword(word);
        strword = newupper + strword.substr(2,strword.length()) + newlower + "ay";
        strword = punct_mover(strword,spaceLoc);
        return strword;
    }
    word = punct_mover(word,spaceLoc);
    return word;
}
string vowel_mover(string word, int flag, char firstLetter, int spaceLoc){ // takes vowel and moves it
   
    if(flag == 0) // words without an uppercase first letter
        word = word.substr(1,word.length()) + firstLetter + "hay";
    else{
        word.c_str();
        char newlower = tolower(firstLetter);
        char newupper = toupper(word[1]);
        string strword(word);
        strword = newupper + strword.substr(2,strword.length()) + newlower + "hay";
        strword = punct_mover(strword,spaceLoc);
        return strword;   
    }
    word = punct_mover(word,spaceLoc);
    return word;
}
string translate(string phrase){
    int spaceLoc = phrase.find(' '); // assigned location of first space
    int flag = 0; //isUpper flag
    string word, pigLatinPhrase; 
    char firstLetter;
    
    while(spaceLoc <= phrase.length()){
        word = phrase.substr(0,spaceLoc); // tokens out words
        word.c_str(); //use this a lot to do easy toUpperCase and toLowerCase
        firstLetter = word[0]; // and to be able to treat strings as char arrays
        
        if(isupper(firstLetter))
            flag = 1; //used to know if new first letter needs capitalization
        
        string wordstr(word); //converted back to string
        if((firstLetter == 'a') || (firstLetter == 'e') || (firstLetter == 'i') || (firstLetter == 'o') || (firstLetter == 'u')) //there is probably a more elegant way to find vowels
            pigLatinPhrase = pigLatinPhrase + " " + vowel_mover(wordstr,flag,firstLetter,spaceLoc);
        else if((firstLetter == 'A') || (firstLetter == 'E') || (firstLetter == 'I') || (firstLetter == 'O') || (firstLetter == 'U'))
            pigLatinPhrase = pigLatinPhrase + " " + vowel_mover(wordstr,flag,firstLetter,spaceLoc);
        else
            pigLatinPhrase = pigLatinPhrase + " " + consonant_mover(wordstr,flag,firstLetter,spaceLoc); //if none found, its a consonant
        
        phrase = phrase.substr(spaceLoc+1); // removes last word from phrase
        spaceLoc = phrase.find(' '); // finds next space
        flag = 0;
    }
    return pigLatinPhrase;
}
int main() {
    string input;
    cout << "Enter in phrase:" << endl;
    getline(cin,input);
    
    input = input + " "; // fixes the only bug I could find in the code.
                         // it needs a space at the end to know when it's done.
    cout << translate(input);
    return 0;
}

