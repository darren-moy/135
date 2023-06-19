#include<iostream>
#include <cstdlib>
#include <fstream>
#include <climits>
#include <string>

using namespace std;

int main(){
  int difficulty = 7;
  int tries = 5;

  int remaining = difficulty - tries;
    for (int i = 0; i < remaining; i++)
    {
        cout << "O";
    }
    for (int j = 0; j < difficulty - remaining; j++)
    {
        cout << "X";
    }

    return 0;
}
