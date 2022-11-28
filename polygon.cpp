#include <iostream>
using namespace std;

struct Polygon {
    int PolygonSides;
    float length[10000];
};

void setSideOfPolygon(Polygon &a) {
    cout << "Nhap so canh cua da giac: ";
    cin >> a.PolygonSides;
    while (a.PolygonSides <= 2) {
        cout << "So canh khong hop le.\n";
        cin>>a.PolygonSides;
    }
    for (int i = 0; i < a.PolygonSides; i++) {
        cout << "Nhap chieu dai canh thu "<<i+1<<" cua da giac: ";
        cin >> a.length[i];
        while (a.length[i] <= 0) {
            cout << "Chieu dai canh khong hop le\n";
            cin>>a.length[i];
        }
    }
}

int PerimeterOfPolygon(Polygon &a) {
    int P = 0;
    for (int i = 0; i < a.PolygonSides; i++)
        P += a.length[i];
    return P;
}

int main() {
    Polygon Figure;
    setSideOfPolygon(Figure);
    cout << "Chu vi cua da giac la: " << PerimeterOfPolygon(Figure) << endl;
    return 0;
}
