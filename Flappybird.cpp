
#include "TXLib.h"

struct Plane
    {
    int x, y;

    int v;
    };


void Plane ();

int main()
    {
    txCreateWindow (1024, 576);

    Plane ();

    return 0;
    }

void Plane ()
    {
    HDC Plane = txLoadImage ("����.bmp");
    if (Plane == NULL) txMessageBox ("������ ������");

    HDC BackG = txLoadImage ("������.bmp");
    if (BackG == NULL) txMessageBox ("� ���� �����������");

    int BackGX = txGetExtentX (BackG) / 10;

    struct Plane Pl {400, 100, 0};

    int VOLX = 0;

    while (1 < 2)
        {

        txBitBlt (txDC(), 0, 0, BackGX, 0, BackG, VOLX);

        txAlphaBlend (txDC (), Pl.x, Pl.y - Pl.v, 0, 0, Plane);

        VOLX += 10;

        Pl.y += 10;

       // PlaneX += 5;

        txSleep (50);

        if (GetAsyncKeyState (VK_SPACE)) Pl.v = Pl.v + 20;

        }
    }
