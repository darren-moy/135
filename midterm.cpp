#include <iostream>
#include <string>
using namespace std;

/*
string remove_a(string word)
{
    string new_word;
    for (int i = 0; i < word.length(); i++)
    {
        
    if (word.substr(i, 1) != "a")
    {
      new_word = new_word + word.substr(i, 1);
    }
    }
    return new_word;
    return 0;
}
*/

int main(){

    //string first_name;
    //int birth_year;
    //bool female;

    //birth_year > 1997 && birth_year < 2001;
    //!female && birth_year >= 2001 && (first_name[0] == 'S' || first_name[0] == 'P');
    //female && birth_year == 2022 && first_name[first_name.length() - 1] == 'y';

    //cout << remove_a("Madison") << endl;
    //return 0;

    int length;
    cout << "Input side length: ";
    cin >> length;

    cout << "Shape: " << endl;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j <= length; j++)
        {
            if (j < length - i)
            {
                cout << " ";
            }
            else cout << "*";
        }
        cout << endl;
    }

    return 0;
}




