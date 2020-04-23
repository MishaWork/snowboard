
 #include "TXLib.h"

 void AlphaBlend (HDC Dest, int xDest, int yDest, int wDest, int hDest, HDC Src,  int xSrc,  int ySrc,  int wSrc,  int hSrc, double alpha);
 double Distance (double TreeX, double TreeY, double SnoX, double SnoY, int SisyaX);

 int main()
     {
     txCreateWindow (800, 600);

     HDC Jopa = txLoadImage ("unnamed.bmp");
     if (Jopa == NULL) txMessageBox ("Ты плоская баба");

     HDC Sisya = txLoadImage ("Snowboard1.bmp");
     if (Sisya == NULL) txMessageBox ("Ты кошачий лоток");

     HDC Kaka = txLoadImage ("Tree.bmp");
     if (Kaka == NULL) txMessageBox ("У вас запор");

     int SourceY1 = 0;

     int JopaY = txGetExtentY (Jopa) / 34;

     int JopaX = txGetExtentX (Jopa);

     int SisyaX = txGetExtentX (Sisya) / 19;

     int TreeSX = txGetExtentX (Kaka) / 1;
     int TreeSY = txGetExtentY (Kaka) / 1;

     //int Move = 0;

     int SourceX2 = 0;

     int Ang = 0;

     int angV = 0;

     double TreeMW = 204;
     double TreeMH = 300;

     double TreeX = 400;
     double TreeY = 300;

     double SnoX = 0;
     double SnoY = 360;

     double Mult = 0.5;

     txBegin ();

     //AlphaBlend (txDC(), 0, 0, 600, 450, Jopa, 0, 0, 368, , 1);
     while (1 < 2)
        {
        SourceY1 += JopaY;

        txBitBlt (txDC(), 0, 0, 0, JopaY, Jopa, 0, SourceY1);

        //AlphaBlend (txDC(), 0, 0, 800, 600, Jopa, 0, SourceY1, JopaX, JopaY, 1);

        txAlphaBlend (txDC(), SnoX+200, SnoY, SisyaX, 0, Sisya, (Ang + 9) * SisyaX);

        AlphaBlend (txDC(), TreeX - 92*Mult, TreeY - 280*Mult, Mult * TreeSX, Mult * TreeSY, Kaka, 0, 0, TreeSX, TreeSY, 1);

        txSetColor (TX_LIGHTGREEN);

        txCircle (SnoX+200+SisyaX/2, SnoY+70, 10);

        txSetColor (TX_PINK);

        txCircle (TreeX, TreeY, 10);

        TreeY += 10;
        TreeX -= 1.9;

        Mult += 0.05;

        double DistanceST = Distance (TreeX, TreeY, SnoX, SnoY, SisyaX);

        if (DistanceST < 70) TreeY = 300, TreeX = 400, Mult = 0.5, SnoX = SnoX+200+SisyaX/2, SnoY + 70;

        printf ("Я ем соленый металолом %lg\n", DistanceST);

        if (TreeY > 700) TreeY = 300, TreeX = 400, Mult = 0.5;

        txLine (100, 0, 100, 600);
        txLine (700, 0, 700, 600);

        if (SourceY1 > 8500) SourceY1 = 0;

        //if (GetAsyncKeyState ('A')) Move = Move - 10;
        //if (GetAsyncKeyState ('D')) Move = Move + 10;

        if  (GetAsyncKeyState (VK_LEFT))  angV =  1;
        if  (GetAsyncKeyState (VK_RIGHT)) angV = -1;

        if (SnoX > 200) SnoX = 0;
        if (SnoX < -300) SnoX = 0;

        Ang = Ang + angV;

        if (Ang < -9) Ang = -9;
        if (Ang > +9) Ang = +9;

        SnoX = SnoX - Ang*2;

        txSleep (100);
        }

    txEnd ();

     return 0;
     }

void AlphaBlend (HDC Dest, int xDest, int yDest, int wDest, int hDest,
                 HDC Src,  int xSrc,  int ySrc,  int wSrc,  int hSrc, double alpha)
    {

    BLENDFUNCTION blend = { AC_SRC_OVER, 0, (alpha * 255), 1};

    Win32::AlphaBlend (Dest, xDest, yDest,  wDest, hDest,
                       Src,  xSrc,  ySrc,   wSrc,  hSrc, blend);
    }

double Distance (double TreeX, double TreeY, double SnoX, double SnoY, int SisyaX)
    {
    double DistanceST = sqrt ((SnoX+200+SisyaX/2 - TreeX) * (SnoX+200+SisyaX/2 - TreeX) + (SnoY + 70 - TreeY) * (SnoY + 70 - TreeY));

    return DistanceST;
    }


