#include <bits/stdc++.h>


using namespace std;

int ucnl(int a, int b)
{
    if (b == 0)   return a;
    return ucnl(b, a%b);
}
int bcnn(int a, int b)
{
    return (a*b)/ucnl(a,b);
}
class Phanso
{
    private:
        int tu;
        int mau;
    public:
        Phanso(int,int);
        void rutgon();
        void tong();
        friend istream& operator >> (istream& in, Phanso& a);
        friend ostream& operator << (ostream& out, Phanso a);
        friend Phanso operator + (Phanso, Phanso);
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
Phanso operator + (Phanso a, Phanso b)
{
    Phanso tong(1,1);
    int tmp = bcnn(a.mau,b.mau);
    cout << tmp << endl;
    tong.mau = tmp;
    tong.tu = (tmp/a.mau)*a.tu + (tmp/b.mau)*b.tu;
    return tong;
}
int main()
{
    Phanso p(1,1), q(1,1);
    cin >> p >> q;
    Phanso tong = p+q;
    // tong.rutgon();
    cout << tong;
    return 0;
}