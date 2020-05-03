
 #include "TXLib.h"

 void AlphaBlend (HDC Dest, int xDest, int yDest, int wDest, int hDest, HDC Src,  int xSrc,  int ySrc,  int wSrc,  int hSrc, double alpha);
 double Distance (double TreeX, double TreeY, double SnoX, double SnoY, int SNOX);

 int main()
     {
     txCreateWindow (800, 600);

     HDC Backg = txLoadImage ("unnamed.bmp");
     if (Backg == NULL) txMessageBox ("Ты плоская баба");

     HDC SNO = txLoadImage ("Snowboard1.bmp");
     if (SNO == NULL) txMessageBox ("Ты кошачий лоток");

     HDC Tree = txLoadImage ("Tree.bmp");
     if (Tree == NULL) txMessageBox ("У вас запор");

     int SourceY1 = 0;

     int BackgY = txGetExtentY (Backg) / 34;

     int BackgX = txGetExtentX (Backg);

     int SNOX = txGetExtentX (SNO) / 19;

     int TreeSX = txGetExtentX (Tree) / 1;
     int TreeSY = txGetExtentY (Tree) / 1;

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

     double ScaleTree = 0.5;

     double MoveV = 1;

     double T = 0;

     double BackgV = 1;

     double TreeV = 0.05;

     double TreeVX = 10;

     double TreeVY = 1.9;

     int StopT = 0;

     txBegin ();

     //AlphaBlend (txDC(), 0, 0, 600, 450, Jopa, 0, 0, 368, , 1);
     while (1 < 2)
        {
        //SourceY1 = SourceY * JopaY;

        T += BackgV;

        txBitBlt (txDC(), 0, 0, 0, BackgY, Backg, 0, int (T) % 34 * BackgY);

        //AlphaBlend (txDC(), 0, 0, 800, 600, Jopa, 0, SourceY1, JopaX, JopaY, 1);

        txAlphaBlend (txDC(), SnoX+200, SnoY, SNOX, 0, SNO, (Ang + 9) * SNOX);

        AlphaBlend (txDC(), TreeX - 92*ScaleTree, TreeY - 280*ScaleTree, ScaleTree * TreeSX, ScaleTree * TreeSY, Tree, 0, 0, TreeSX, TreeSY, 1);

        txSetColor (TX_LIGHTGREEN);

        txCircle (SnoX+200+SNOX/2, SnoY+70, 10);

        txSetColor (TX_PINK);

        txCircle (TreeX, TreeY, 10);

        TreeY += TreeVX;
        TreeX -= TreeVY;

        ScaleTree += TreeV;

        double DistanceST = Distance (TreeX, TreeY, SnoX, SnoY, SNOX);

        if (DistanceST < 70)
            {
            TreeY = 300,
            TreeX = 400,
            ScaleTree = 0.5,
            SnoX = SnoX+200+SNOX/2,
            SnoY + 70,
            BackgV = 0,
            TreeV = 0,
            TreeVX = 0,
            TreeVY = 0,
            StopT = GetTickCount ();
            }

        if (GetTickCount () - StopT > 7000)
            {
            BackgV = 1,
            TreeV = 0.05,
            TreeVX = 10,
            TreeVY = 1.9;
            }

        printf ("Я ем соленый металолом %lg\n", DistanceST);

        if (TreeY > 700) TreeY = 300, TreeX = 400, ScaleTree = 0.5;
                                                                         //0 0
        txLine (100, 0, 100, 600);                                       //1 1
        txLine (700, 0, 700, 600);                                       //2 0
                                                                         //3 1
        //if (T > 34) T = 0;                                               //4 0
                                                                         //5 1
                                                                         //6 0
                                                                         //7 1
        if  (GetAsyncKeyState (VK_LEFT))  angV =  1;                     //8 0
        if  (GetAsyncKeyState (VK_RIGHT)) angV = -1;                     //9 1
                                                                         //10 0
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

double Distance (double TreeX, double TreeY, double SnoX, double SnoY, int SNOX)
    {
    double DistanceST = sqrt ((SnoX+200+SNOX/2 - TreeX) * (SnoX+200+SNOX/2 - TreeX) + (SnoY + 70 - TreeY) * (SnoY + 70 - TreeY));

    return DistanceST;
    }


