#include <bits/stdc++.h>

using namespace std;

void intro()
{
    cout << "----------------------------------------------" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "----------- WELCOME TO CARO GAME -------------" << endl;
    cout << "-----------    AUTHOR: HARI      -------------" << endl;
    cout << endl;
    cout << " GUIDE: Enter your step follow table below: " << endl;
    cout << "       |       |        " << endl;
    cout << "   1   |   2   |   3    " << endl;
    cout << "       |       |        " << endl;
    cout << "----------------------- " << endl;
    cout << "       |       |        " << endl;
    cout << "   4   |   5   |   6    " << endl;
    cout << "       |       |        " << endl;
    cout << "----------------------- " << endl;
    cout << "       |       |        " << endl;
    cout << "   7   |   8   |   9    " << endl;
    cout << "       |       |        " << endl;
    cout << "If you make a straight or horizontal or diagonal line with the same symbol ==> you will win" << endl;
    cout << endl << endl;
}
int choices()
{
    cout << "Choose mode play: " << endl;
    cout << "1. Two player."<< endl;
    cout << "2. One player (you will play with computer)" << endl;
    int c ; cin >> c;
    return c;
}
// print array:
void printarray(string (&arr)[20][20])
{
    for(int i = 0;i < 12;i++)
    {
        for (int j = 0;j < 12;j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }
}
///

bool win(string (&arr)[20][20], string charac);
vector<int> remove(vector<int> arr, int a);
int getRandomElement(vector<int>& array);


int main()
{
    intro();
    string arr[20][20]= {
        {"       ","|","       ","|","       "},                 
        {"       ","|","       ","|","       "},                    
        {"       ","|","       ","|","       "},                
        {"-----------------------"},   
        {"       ","|","       ","|","       "},                              
        {"       ","|","       ","|","       "},                 
        {"       ","|","       ","|","       "},              
        {"-----------------------"},              
        {"       ","|","       ","|","       "},               
        {"       ","|","       ","|","       "},               
        {"       ","|","       ","|","       "},                
    };
    // Pointer for modify array
    multimap<int,int> square;
    square.insert({1,0});
    square.insert({1,2});
    square.insert({1,4});
    square.insert({5,0});
    square.insert({5,2});
    square.insert({5,4});
    square.insert({9,0});
    square.insert({9,2});
    square.insert({9,4});
    vector<pair<int,int>> truyxuat;
    for (auto& pair : square) {
        truyxuat.push_back(pair);
    }
    string* modify[20][20];
    for (int i = 0; i < 20; ++i) 
    {
        for (int j = 0; j < 20; ++j) {
            modify[i][j] = &arr[i][j];
        }
    }

    int choice = choices();

    if(choice == 1)
    {
        int j = 0;
        int i = 2;
        // Game for two player
        while(true)
        {
            if(i%2 == 0)    
            {
                cout << "Player 1: Please enter your input: ";
                int tmp; cin >> tmp;
                tmp = tmp -1;
                *modify[truyxuat[tmp].first][truyxuat[tmp].second] = "   X   ";
                printarray(arr);
                if(win(arr,"   X   ")) 
                {
                    cout <<"----------- PLAYER 1 WIN ----------"<< endl;
                    break;
                }
                i += 1;
                j += 1;
            }
            if (j == 9)
            {
                cout << "----------- DRAWN -------" << endl;
                break;
            }
            if(i%2 != 0)    
            {
                cout << "Player 2: Please enter your input: ";       
                int tmp; cin >> tmp;
                tmp = tmp - 1;
                *modify[truyxuat[tmp].first][truyxuat[tmp].second] = "   O   "; 
                printarray(arr);
                if(win(arr,"   O   ")) 
                {
                    cout <<"----------- PLAYER 2 WIN ----------"<< endl;
                    break;
                }
                i +=1;
                j+=1;
            }
        }
    }
    else if(choice == 2)
    {
        vector<int> ar = {1,2,3,4,5,6,7,8,9};
        // Game for one player;
        int j =0;
        int i = 2;
        while(true)
        {
            if(i%2 == 0)    
            {
                cout << "YOUR TURN: Please enter your input: ";
                int tmp; cin >> tmp;
                ar = remove(ar,tmp);
                tmp = tmp -1;
                *modify[truyxuat[tmp].first][truyxuat[tmp].second] = "   X   ";
                printarray(arr);
                if(win(arr,"   X   ")) 
                {
                    cout << "----------- YOU WIN ----------" << endl;
                    break;
                }
                i+=1;
            }
            if (j == 9)
            {
                cout << "---------- DRAWN -----------" << endl;
                break;
            }
            if(i%2 != 0)    
            {
                cout << "Computer: " << endl;       
                int tmp = getRandomElement(ar);
                tmp = tmp -1;
                *modify[truyxuat[tmp].first][truyxuat[tmp].second] = "   O   "; 
                printarray(arr);
                if(win(arr,"   O   ")) 
                {
                    cout << "----------- COMPUTER WIN ----------" << endl;
                    break;
                }
                i+=1;
            }
        }
    }
    return 0;
}

//Handle win 
bool win(string (&arr)[20][20],string charac)
{
    // for straight
    if((arr[1][0] == charac) && ( arr[1][2] == charac) && (arr[1][4] == charac)) return true;
    if((arr[5][0] == charac) && ( arr[5][2] == charac) && (arr[5][4] == charac)) return true;
    if((arr[9][0] == charac) && ( arr[9][2] == charac) && (arr[9][4] == charac)) return true;

    // for horizontal
    if((arr[1][0] == charac) && ( arr[5][0] == charac) && (arr[9][0] == charac)) return true;
    if((arr[1][4] == charac) && ( arr[5][4] == charac) && (arr[9][4] == charac)) return true;
    if((arr[1][2] == charac) && ( arr[5][2] == charac) && (arr[9][2] == charac)) return true;

    // for dialog
    if((arr[1][0] == charac) && ( arr[5][2] == charac) && (arr[9][4] == charac)) return true;
    if((arr[1][4] == charac) && ( arr[5][2] == charac) && (arr[9][0] == charac)) return true;

    return false;
}
vector<int> remove(vector<int> arr, int a)
{
    auto it = find(arr.begin(), arr.end(),a);
    arr.erase(it);
    return arr;
}


//Random verison
int getRandomElement(vector<int>& array) 
{    
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> dist(0, array.size() - 1);
    int randomIndex = dist(rng);
    return array[randomIndex];
}