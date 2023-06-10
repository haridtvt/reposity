#include <bits/stdc++.h>

using namespace std;


class sinhvien
{
    private:
        string ns;
        string lop;
        double gpa;
        string hoten;
    public:
        sinhvien()
        {
            this->ns =  this->lop =  this->hoten = "";
            this->gpa  = 0;
        }
    friend void nhap(sinhvien&);
    friend void in(sinhvien);
};
void nhap(sinhvien &a)
{
    getline(cin,a.hoten);
    cin >> a.ns >> a.lop >> a.gpa;
}
void in(sinhvien a)
{
    if (a.ns[2] != '/')   a.ns = "0" + a.ns;
    if (a.ns[5] != '/') a.ns.insert(3,"0");
    cout << a.ns << " " <<  a.lop << " "  << a.hoten << " " << fixed << setprecision(3) << a.gpa;
}
#define a() a
int main()
{
    sinhvien a();
    nhap(a);
    in(a);
    return 0;
}