#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

vector<string> addWords(vector<string> v){
    vector<string> v1;
    for(int i=0; i<v.size();i++){
        v1.push_back(v.at(i));
        //cout << "value: " << v.at(i) << "\n";
    }
    return v1;

}

bool checkExists(vector<string> v, string s){
    for(int i=0; i<v.size(); i++){
        if(v.at(i) == s){
            return true;
        }
    }
     return false;
}

string * chooseAndScramble(vector<string> v){

    static string a[2];
    int randIndice;

    //Escolhe uma palavra com pelo menos 3 caracteres
    do{
        if(v.size() > 0){
            randIndice = rand() % (v.size());
            a[0] = v.at(randIndice);
        } else {
            cerr << "The vector is empty!";
            return 0;
        }
    }while(v.at(randIndice).length() < 3);

    string newWord;
    vector<char> temp;
    for(int i =0; i< a[0].length();i++){
        temp.push_back(a[0].at(i));
    }

    for(int i =0; i< temp.size();i++){
        int j = rand() % temp.size();
        bool goUp = true;

        while(temp.at(j) == '-'){
            if(j < (temp.size()-1) && goUp){
                j++;
            } else {
                goUp = false;
                if(j>=0){
                    j--;
                } else {
                    cerr << "Something went wrong!";
                }

            }
        }

        if(temp.at(j) != '-'){
            newWord += temp.at(j);
            temp.at(j) = '-';
        } else {
            cerr << "something went wrong while scramble";
        }

    }

    a[1] = newWord;

    return a;
}

/*
 * Em falta: verificar se o user introduziu o número correcto de caracteres
 * Converter minúsculas para maiúsculas
 */
bool guessTheWord(string scrambled, string original, int turns){
    cout << scrambled << " - Try to guess the word in " << turns << "turns" << "\n";

    for(int i = 0; i<=turns; i++){
        string s;
        cout << i << " - Your guess is: ";
        getline(cin,s);
        if(s==original){
            return true;
        } else {
            cout << "No, Try Again!" << "\n";
        }
    }
    return false;
}


void validWordsWith(vector<string> v, string s){
    int lettersFound = 0;
    int wordsFound = 0;

    string debugV;
    char debugSj;
    char debugVk;

    cout << "With those letters the dictionary has: " << "\n";
    for(int i=0; i<v.size(); i++){
        debugV = v[i];
        for(int j=0; j<s.length(); j++){
            debugSj = s[j];
            for(int k=0; k<v[i].length();k++){
                debugVk = v[i][k];
                if(s[j] == v[i][k]){
                    lettersFound++;
                    break;
                }
            }
        }
        if(lettersFound == s.length()){
            cout << v[i] << "\n";
            wordsFound++;
        }
        lettersFound = 0;
    }

    if(wordsFound > 0){
        cout << "The number of words found was: " << wordsFound << "\n";
    } else {
        cout << wordsFound << " words";
    }
}


/*
 * Forth Point auxiliars
 */

    vector<char> createSetOfLetters(vector<string> v){
        vector< vector <int> > v1;
        vector< char > v2;
        int biggestWord = 0;
        float letterProportion = 0.0;
        for(int i=0;i<v.size();i++){                    //percorre as palavras do vector
            //string s = v.at(i);

            if(v.at(i).length() > biggestWord){
                biggestWord = v.at(i).length();
            }

            for(int j=0;j<v.at(i).length();j++){       //para cada letra da palavra

                //char c = v.at(i)[j];
                bool auxFound = false;
                if(v1.size() == 0){
                    vector<int> firstRow;
                    firstRow.push_back(v.at(i)[j]);
                    firstRow.push_back(1);
                    v1.push_back(firstRow);
                    break;
                }
                for(int k=0; k<v1.size(); k++){         //compara com as letras do vector de char
                    int i1 = v1.at(k).at(0);
                    int i2 = v1.at(k).at(1);
                    if(v1.at(k).at(0) == v.at(i)[j]){
                        v1.at(k).at(1)++;
                        auxFound = true;
                        break;
                    } else {
                        continue;
                    }
                }

                if(!auxFound){
                    vector<int> row;
                    row.push_back(v.at(i)[j]);
                    row.push_back(1);
                    v1.push_back(row);
                }

            }
        }

        cout << "Número de letras distintas: " << v1.size() << "\n";
        cout << "Número de letras no dicionário: " << "\n";
        for(int i =0; i<v1.size(); i++){
            char temp = v1.at(i).at(0);
            int number = v1.at(i).at(1);
            cout << temp;
            cout << " - " << number;
            cout << "\n";
        }

        cout << "A maior palavra é: " << biggestWord;
        cout << "\n";

        /*** Rearrange vector in order of number of characters ****/

        for(int i=0; i<v1.size();i++){
            for(int j=0;j<v1.size();j++){
                int a = v1.at(i).at(1);     //DEBUG
                int b = v1.at(j).at(1);     //DEBUG
                vector<int> aux;
                if(v1.at(i).at(1) > v1.at(j).at(1)){
                    aux = v1.at(i);
                    v1[i] = v1.at(j);
                    v1[j] = aux;
                }
            }
        }

        //DEBUG
        cout << "Vector ordenado: " << "\n";
        for(int i =0; i<v1.size(); i++){
            char temp = v1.at(i).at(0);
            int number = v1.at(i).at(1);
            cout << temp;
            cout << " - " << number;
            cout << "\n";
        }

        int number = v1.at(v1.size()-1).at(1); //DEBUG
        letterProportion = (float) v1.at(v1.size()-1).at(1) / 2.0;

        /*** create new vector with the number of letters multiplied by the ocorrence factor *****/

        for(int i=0; i<v1.size(); i++){
            float j=0;
            float numberOfChar = ((float) v1.at(i).at(1))/letterProportion; //DEBUG
            while(j < (((float) v1.at(i).at(1))/letterProportion)){
                v2.push_back(v1.at(i).at(0));
                j+=1.0;
            }
        }

        /*Print final set*/ //DEBUG
        cout << "Final SET: " << "\n";
        for(int i =0; i<v2.size(); i++){
            char temp = v2.at(i);
            cout << temp;
            cout << "\n";
        }

        return v2;

    }

    vector<char> chooseLettersFromSet(vector<char> set, int number){
        vector<char> v;
        cout << "{ ";
        for(int i=0; i<number; i++){
            int randIndice = rand() % (set.size());
            v.push_back(set[randIndice]);
            cout << set.at(randIndice);
            if(i<number-1){
                cout << " - ";
            }
        }
        cout << " } \n";
        return v;
    }

    void verifyWord(string word, vector<char> v, vector<string> haystack){
        int initialSize = v.size();
        for(int i=0; i<word.length();i++){ //por cada letra da palavra
            for(int j=0; j<v.size();j++){   //percorre as letras possíveis
                if(word[i] == v.at(j)){     //Se a letra existir remove do array
                    v.erase(v.begin()+j);
                    break;
                }
            }
        }

        if(v.size() != initialSize-word.length()){
            cout << "The letters used are not available on the SET" << "\n";
            return;
        }

        for(int i=0; i<haystack.size();i++){
            if(haystack.at(i) == word){
                cout << "Valid Word, well done!" << "\n";
                return;
            }
        }

        cout << "The word isn't valid" << "\n";

    }

    /*
     * Fifth Point auxiliars
     */
 /*   void selectWordsLike(string w, vector<string> v){
        int howManyAsterics = 0;
        int wordIterator = 0;

        for(int i=0; i<w.length(); i++){
            if(w[i] == '*'){
                howManyAsterics+=1;
            }
        }

       for(int i=0; i<v.size();i++){ //Para cada palavra do dicionario
            if(v.at(i).length() >= w.length()-howManyAsterics){ //Se a palavra tiver o tamanho correcto
                for(int j=0; j<v.at(j).length(); j++){  //Vamos comparar os indices das duas palavras
                    if(v.at(i)[j] == w[wordIterator]){
                        wordIterator++;
                        continue;
                    } else if(w[wordIterator] == '?' && v.at(i)[j] != ''){
                        wordIterator++;
                        continue;
                    } else if(w[wordIterator] == '*'){

                    }
                }
            }
        }
    }*/


        bool wildcardMatch(const char *str, const char *strWild)
        {
            while (*strWild)
            {
                if (*strWild== '?')
                {
                    if (!*str)
                        return false;
                    ++str;
                    ++strWild;
                }
                else if (*strWild== '*')
                {
                    if (wildcardMatch(str,strWild+1))
                        return true;
                    if (*str && wildcardMatch(str+1,strWild))
                        return true;
                    return false;
                }
                else
                {
                    if (toupper(*str++)!=toupper(*strWild++))
                        return false;
                }
            }
            return !*str && !*strWild;
        }



int main() {
    srand ((int)time(NULL)); //Inicializa a seed do random
    vector<string> dummy = {
            "A",
            "AAM",
            "AARONIC",
            "ABELIAN",
            "ABELITE",
            "ABELONIAN",
            "ABRAUM",
            "FRASDO",
            "GOME",
            "GAME",
            "ALEXANDER",
            "FAONNI",
            "REWRITE",
            "RULLER",
            "BORIS",
            "BARTENDER",
            "COSMOPOLITAN",
            "YOLANDA"
    };

    vector<string> myVector = addWords(dummy);

    string myString;
    string *scrambleWord; //Second Game
    string chooseLetters; //Third Game
    vector <char> largerSet; //Forth Game
    int numberOfLetters;    //Forth Game
    vector<char> choosedLetters; //Forth Game
    string optionWord;      //Forth Game
    string searchQuery;     //Fifth Game


    bool guess=false;

    /*
     * CLI BEGINS HERE
     * TODO: The CLI must ask the user which game to play and repeat the sequence until CTRL+Z or other ending sequence!
     */

    /**** FIRST POINT ****/
    cout << "Please enter a word: " << "\n";
    getline(cin,myString);

    if(checkExists(myVector, myString)){
        //cout << "tamanho da string: " << myString.length() << "\n";
        cout << "good one" << "\n";
    } else {
        //cout << "tamanho da string: " << myString.length() << "\n";
        cout << "Oh no..." << "\n";
    }


    /****** SECOND POINT *****/

    scrambleWord = chooseAndScramble(myVector);
    if(guessTheWord(scrambleWord[1], scrambleWord[0], 3)){
        cout << "Well done you guessed it!" << "\n";
    } else {
        cout << "You loose the word was: " << scrambleWord[0] << "\n";
    }

    /**** THIRD POINT *****/

    cout << "Please choose between 1 and 5 Letters: " << "\n";
    getline(cin,chooseLetters);
    while(chooseLetters.length() < 1 || chooseLetters.length() > 5){
        cout << "Not a valid number of letters." << "\n";
        cout << "Please try again: (1 or 5 letters): " << "\n";
        getline(cin,chooseLetters);
    }

    validWordsWith(myVector, chooseLetters);

    /*
     * Forth Point
     * Needs a loop
     */

    largerSet = createSetOfLetters(myVector);

    cout << "How many letters do you wish?" << "\n";
    cin >> numberOfLetters;
    cin.clear();
    cin.ignore(100,'\n');


    choosedLetters = chooseLettersFromSet(largerSet, numberOfLetters);
    //save the set of words choosed;
    cout << "Try to create a word: " << "\n";


    getline(cin,optionWord);

    verifyWord(optionWord, choosedLetters, myVector);

    /*
     * Fifth Game
     */

    cout << "Make your search query: " << "\n";
    getline(cin,searchQuery);

    for(int i=0; i<myVector.size(); i++){
        if(wildcardMatch(&myVector.at(i)[0],&searchQuery[0])){
            cout << myVector.at(i) << "\n";
        }
    }

    //selectWordsLike(searchQuery, myVector);

    return 0;
}