#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n; cin >> n;
    multiset<int> q;
    for(ll i = 0; i < n;i++)
    {
        ll tmp; cin >> tmp;
        q.insert(tmp);
    }
    ll numofquery; cin >> numofquery;
    while(numofquery--)
    {
        int que;
        ll value; 
        cin >> que >> value;        
        if(que == 1)
        {
            q.insert(value);
        }
        else if (que == 2)
        {
            for(multiset<ll>::iterator it = q.begin(); it != q.end(); it++)
            {
                if(q.count(value)!=0)    q.erase(value);   
            }
        }
        else if (que == 3)
        {
            if(q.find(value) != q.end())    cout << "YES" << endl;
            else    cout << "NO" << endl;
        }
    }
    return 0;
}