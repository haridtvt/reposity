#include <bits/stdc++.h>


using namespace std;

int ucnl(int a, int b)
{
    if (b == 0)   return a;
    return ucnl(b, a%b);
}
class Phanso
{
    private:
        int tu;
        int mau;
    public:
        Phanso(int,int);
        void rutgon();
        friend istream& operator >> (istream& in, Phanso& a);
        friend ostream& operator << (ostream& out, Phanso a);
};
Phanso::Phanso(int a, int b)
{
    this->tu = a;
    this->mau = b;
}
istream& operator >> (istream& in, Phanso& a)
{
    in >> a.tu >> a.mau;
    return in;
}
ostream& operator << (ostream& out, Phanso a)
{
    out << a.tu << "/" << a.mau << endl;
    return out;
}
void Phanso::rutgon()
{
    int tmp = ucnl(this->tu,this->mau);
    this->tu = tu/tmp;
    this->mau = mau/tmp;
}
int main()
{
    Phanso p(1,1);
    cin >> p;
    p.rutgon();
    cout << p;
    return 0;
}