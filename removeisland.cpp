#include <iostream>
#include <bits/stdc++.h>

using namespace std;

multimap<int, int> get_border(int a, int b) 		// row, colum
{
	multimap<int, int> boder;
	for(int i = 0; i < a; i++)
	{
		for(int j = 0; j < b; j++)
		{
			if(i == 0 || j == 0 || i == a-1 || j == b-1)	boder.insert({i,j});	
		}			
	}
	return boder;
}
multimap<int, int> check_land(int a[][5], multimap<int, int> *land,int rows,int cols)
{
    multimap<int,int> dxy;
    dxy.insert({0,1});
    dxy.insert({0,-1});
    dxy.insert({1,0});
    dxy.insert({-1,0});
    int count = 1;
    for(auto it: *land)
    {
        // cout << "-----------------------------------------------" << endl;
        // cout << "Position: " << it.first << " " << it.second << endl;
        for(auto pos:dxy)
        {
            int x = it.first + pos.first;
            int y = it.second + pos.second;
            // cout << "\tPosstion check : " << x << " " << y << endl;
            if((x > rows) or (y > cols) or (x < 0) or (y < 0))   continue;
            else
            {
                if (a[x][y] == 1)   
                {
                    auto range = (*land).equal_range(x);
                    bool found = true;
                    for (auto its = range.first; its != range.second; ++its) 
                    {
                        if (its->second == y) 
                        {
                            found = false;
                            break;
                        }
                    }       
                    if(found)   
                    {
                        // cout << "\t" << x << " " << y << endl;
                        *land->insert({x,y});
                        // cout << "\tsuccess-------------" << endl;
                    }    
                }
            }
        }
    }
    return *land;
}

int main()
{
	
	int n = 5;
	int a[5][5] = {
            {1,0,1,0,1},
            {1,1,0,0,0},
            {1,0,1,0,1},
            {1,0,0,1,0},
            {0,1,0,0,1}
    };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n;j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    int rows = sizeof(a)/sizeof(a[0]) -1;
    int cols = sizeof(a[0])/sizeof(a[0][0]) -1;
	multimap<int, int> boder = get_border(n,n);
	multimap<int, int> land;
	for(auto it:boder)
	{
	    if(a[it.first][it.second] == 1)
	    {
	    	land.insert({it.first,it.second});
	    }
	}
    multimap<int, int> lands = check_land(a, &land,rows,cols);

/*  PRINT RESULT */
    cout << endl;
    cout << "After remove island" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n;j++)
        {
            auto range = lands.equal_range(i);
            bool found = false;
            for (auto its = range.first; its != range.second; ++its) 
            {
                if (its->second == j) 
                {
                    found = true;
                    break;
                }
            }       
            if(found)   cout << "1" << " ";
            else cout << "0" << " ";           
        }
        cout << endl;
    }
	return 0;
}
  