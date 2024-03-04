#include <bits/stdc++.h>
using namespace std;

vector <string> WORD_LIST;
int WORD_COUNT;
string chooseWord()
{
    srand(time(0));
    int randomIndex = rand() % WORD_COUNT;
    return WORD_LIST[randomIndex];
}
void display_status (vector <char> incorrect, string answer) 
{
    cout << "Incorrect guess: \n";
    for (int i = 0; i < incorrect.size(); i++) {
        cout << incorrect[i]<<" ";
    }
    cout << "\nCorrect word: \n";
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i]<<" ";
    }
}

void end_game(string answer, string secretWord)
{
    if (answer == secretWord) {
        cout << "Congratulation!You win.\n";
    }
    else {
        cout << "Oh no! \n";
        cout << "The man is hanging.\n";
        cout << "The correct word is: " << secretWord << endl;
    }
}

void display_misses(int misses) 
{
    if (misses == 0) 
    {
        cout<<"  +---+ \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<" ========= \n";
    }
    else if (misses == 1) 
    {
        cout<<"  +---+ \n";
        cout<<"  |   | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<" ========= \n";
    }
    else if (misses == 2) 
    {
        cout<<"  +---+ \n";
        cout<<"  |   | \n";
        cout<<"  O   | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<" ========= \n";
    }
    else if (misses == 3) 
    {
        cout<<"  +---+ \n";
        cout<<"  |   | \n";
        cout<<"  O   | \n";
        cout<<"  |   | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<" ========= \n";
    }
    else if (misses == 4) 
    {
        cout<<"  +---+ \n";
        cout<<"  |   | \n";
        cout<<"  O   | \n";
        cout<<" /|   | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<" ========= \n";
    }
    else if (misses == 5) 
    {
        cout<<"  +---+ \n";
        cout<<"  |   | \n";
        cout<<"  O   | \n";
        cout<<" /|\\  | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<" ========= \n";
    }
    else if (misses == 6) 
    {
        cout<<"  +---+ \n";
        cout<<"  |   | \n";
        cout<<"  O   | \n";
        cout<<" /|\\  | \n";
        cout<<" /    | \n";
        cout<<"      | \n";
        cout<<" ========= \n";
    }
    else if (misses == 7) 
     {
        cout<<"  +---+ \n";
        cout<<"  |   | \n";
        cout<<"  O   | \n";
        cout<<" /|\\  | \n";
        cout<<" / \\  | \n";
        cout<<"      | \n";
        cout<<" ========= \n";
    }
}
int main() {
    // trích xuất file
    fstream in;
    in.open("word-of-hangman.txt");
    string s;
    while (in >> s) {
        WORD_LIST.push_back(s);
    }
    in.close();
    WORD_COUNT = WORD_LIST.size();
    
    //chạy chương trình
    string secretWord = chooseWord();
    string answer = secretWord;
    for (int i  = 0; i < answer.length(); i++) {
        answer[i] = '_';
    }
    int misses = 0;
    vector <char> incorrect;
    char letter;
    bool check = false;
    while (misses < 7 && answer != secretWord) {
        display_misses(misses);
        display_status (incorrect, answer);
        cout << "\n\nChoose a letter: ";
        cin  >> letter;
        for (int i  = 0; i < secretWord.size(); i++) 
        {
            if (letter == secretWord[i]) {
                answer[i] = letter;
                check  = true;
                }
        }
        if (check) cout << "\n<<<<<Correct>>>>>\n\n\n\n\n";
        else {
            cout << "\n<<<<<Incorrect>>>>>\n\n\n\n\n";
            incorrect.push_back(letter);
            misses++;
        } 
        check = false;
    }
    if (misses == 7) display_misses(misses);
    end_game(answer, secretWord);
return 0;
}