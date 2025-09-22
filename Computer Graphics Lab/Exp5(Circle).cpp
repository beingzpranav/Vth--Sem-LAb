#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <math.h>

class bresen {
    float x, y, a, b, r, p;

public:
    void get();
    void cal();
};

void bresen::get() {
    cout << "Enter Centre Coordinates (x, y): ";
    cin >> a >> b;
    cout << "Enter Radius: ";
    cin >> r;
}

void bresen::cal() {
    int gdriver = DETECT, gmode, errorCode;

    initgraph(&gdriver, &gmode, "C:\\Turboc3\\BGI");
    errorCode = graphresult();
    if (errorCode != grOk) {
        cout << "Graphics Error: " << grapherrormsg(errorCode);
        return;
    }

    x = 0;
    y = r;
    p = 1.25 - r;

    while (x <= y) {
        putpixel(a + x, b + y, BLUE);
        putpixel(a - x, b + y, BLUE);
        putpixel(a + x, b - y, BLUE);
        putpixel(a - x, b - y, BLUE);
        putpixel(a + y, b + x, BLUE);
        putpixel(a - y, b + x, BLUE);
        putpixel(a + y, b - x, BLUE);
        putpixel(a - y, b - x, BLUE);

        if (p < 0) {
            p += (2 * x) + 3;
        } else {
            p += (2 * (x - y)) + 5;
            y--;
        }
        x++;
    }
}

int main() {
    bresen b;
    b.get();
    b.cal();
    getch();
    return 0;
}