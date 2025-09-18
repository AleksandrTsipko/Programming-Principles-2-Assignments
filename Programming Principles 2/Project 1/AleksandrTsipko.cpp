
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
    srand(time(0));
    const char secnum1[] = "84632";
    const char secnum2[] = "47385";
    const char secnum3[] = "16420";
    const char secnum4[] = "92601";
    const char secnum5[] = "36147";
    const char secnum6[] = "73901";
    char secnum[6];
    char guess[6];
    int c1 = 0;
    bool quit = false;
    char resp[6];
    int attempt = 0;
    int MAXGUESS = 10;
    int r;
    r = rand() % 6;
    switch(r) 
    {
    case 0:
        strcpy(secnum, secnum1);
        break;
    case 1:
        strcpy(secnum, secnum2);
        break;
    case 2:
        strcpy(secnum, secnum3);
        break;
    case 3:
        strcpy(secnum, secnum4);
        break;
    case 4:
        strcpy(secnum, secnum5);
        break;
    case 5:
        strcpy(secnum, secnum6);
        break;
    }

    cout << "Welcome to the Mastermind game!"
        << "\nResponse characters:"
        << "\nB: correct digit in correct position"
        << "\nW: correct digit in incorrect position"
        << "\n_: incorrect digit\n"
        << "\nOrder of response characters does not necessarily match digits!"
        << "\nGood Luck!"
        << "\n!You got 10 attempts!";

    while (quit == false) {

        while (quit == false)
        {
            if (attempt == MAXGUESS)
            {
                cout << "\nYou have wasted all your attempts!"
                    << "\nYou have lost";
                quit = true;
                
            }
            else {
                cout << "\nEnter a 5-digit guess (q to quit): ";
                cin >> guess;
                if (strcmp(guess, "q") == 0)
                {
                    cout << "You lost after " << attempt << " guesses. "
                        << "Thanks for playing! Better luck next time!";
                    quit = true;
                }
                else if ((strlen(guess) == 5))
                {
                    for (int i = 0; guess[i] != '\0'; i++)
                    {
                        if (!(guess[i] >= '0' and guess[i] <= '9'))
                        {
                            c1++;
                        }

                    }
                    if (c1 == 0)
                    {
                        int resppos = 0;
                        for (int i = 0; secnum[i] != '\0'; i++)
                        {
                            for (int j = 0; guess[j] != '\0'; j++)
                            {
                                if (secnum[i] == guess[j])
                                {

                                    if (i == j)
                                    {
                                        resp[resppos] = 'B';

                                    }
                                    else
                                    {
                                        resp[resppos] = 'W';

                                    }
                                    resppos++;


                                }
                            }
                        }
                        if (resppos < 5)
                        {
                            do
                            {
                                resp[resppos] = '_';
                                resppos++;
                            } while (resppos != 5);
                        }
                        resp[resppos] = '\0';
                        attempt++;
                        if (strcmp(resp, "BBBBB") == 0)
                        {
                            cout << "\nYou won on try " << attempt << "! Congratulations!";
                            cout << "\nWant to play one more time?"
                                << "\nType y for yes\nType n for no"
                                << "\nAnswer: ";
                            char answer[2];
                            cin >> answer;
                            if (strcmp(answer, "y") == 0)
                            {
                                //
                                r = rand() % 6;
                                switch (r)
                                {
                                case 0:
                                    strcpy(secnum, secnum1);
                                    break;
                                case 1:
                                    strcpy(secnum, secnum2);
                                    break;
                                case 2:
                                    strcpy(secnum, secnum3);
                                    break;
                                case 3:
                                    strcpy(secnum, secnum4);
                                    break;
                                case 4:
                                    strcpy(secnum, secnum5);
                                    break;
                                case 5:
                                    strcpy(secnum, secnum6);
                                    break;
                                }
                                //
                                attempt = 0;                               
                                quit = false;

                            }
                            else
                            {
                                cout << "Bye bye!";
                                quit = true;
                            }

                        }
                        else
                        {
                            cout << "\nOn try number: " << attempt << ", response: " << resp;
                            quit = false;
                        }

                    }
                    else
                    {
                        cout << "Your guess must contain only digits. Guess again.";
                        quit = false;

                    }

                    c1 = 0;
                }
                else
                {
                    quit = false;
                    cout << "\nYour guess must be 5-digits long. Guess again" << endl;
                }
            }
        }
    }
    return 0;
}



