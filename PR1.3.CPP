#include <iostream>
using namespace std;

int main()
{
    string sentence;

    cout<<"Enter a sentence:\n";
    getline(cin,sentence);

    string word="";
    string longest="";

    for(int i=0;i<=sentence.length();i++)
    {
        if(sentence[i]==' ' || sentence[i]=='\0')
        {
            if(word.length()>longest.length())
            {
                longest=word;
            }

            word="";
        }
        else
        {
            word=word+sentence[i];
        }
    }

    cout<<"Longest Word: "<<longest<<endl;
    cout<<"Length: "<<longest.length();

    return 0;
}
