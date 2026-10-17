#include<iostream>
#include<string>
using namespace std;

int main()
{
    string sentence,word,longest;
    int maxLen=0;

    cout<<"Enter sentence: ";
    getline(cin,sentence);

    for(int i=0;i<=sentence.length();i++)
    {
        if(i<sentence.length()&&sentence[i]!=' '&&sentence[i]!='\n'&&sentence[i]!='\t')
        {
            word+=sentence[i];
        }
        else
        {
            if(word.length()>0)
            {
                if(word.length()>maxLen)
                {
                    maxLen=word.length();
                    longest=word;
                }

                word="";
            }
        }
    }

    if(maxLen>0)
    {
        cout<<"Longest word: "<<longest<<endl;
        cout<<"Length: "<<maxLen<<endl;
    }
    else
    {
        cout<<"No word found";
    }

    return 0;
}