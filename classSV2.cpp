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
    friend istream& operator >> (istream&, sinhvien&);
    friend ostream& operator << (ostream&, sinhvien);
};
istream& operator >> (istream& in, sinhvien& a)
{
    in.ignore();
    getline(in, a.hoten);
    in >> a.gpa >> a.lop >> a.ns;
    return in;
}
ostream& operator << (ostream& out, sinhvien a)
{
    if (a.ns[2] != '/')   a.ns = "0" + a.ns;
    if (a.ns[5] != '/') a.ns.insert(3,"0");
    out << a.hoten << " " << a.ns << " " << a.lop << " " << fixed << setprecision(3) << a.gpa;
    return out;
}
#define a() a
int main()
{
    sinhvien a();
    int n; cin >> n;
    sinhvien b[n];
    for(int i = 0; i< n;i++)
    {
        cin >> b[i];
        cout << b[i];
        cout << endl;
    }
    return 0;
}