#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string sentence, word = "", longest = "";

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    sentence += " ";

    for (int i = 0; i < sentence.length(); i++)
    {
        if (isalpha(sentence[i]))
        {
            word += sentence[i];
        }
        else if (sentence[i] == ' ')
        {
            if (word.length() > longest.length())
            {
                longest = word;
            }
            word = "";
        }
    }

    cout << "Longest word: " << longest << endl;
    cout << "Length: " << longest.length() << endl;

    return 0;
}
