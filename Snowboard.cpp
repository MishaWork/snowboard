
 #include "TXLib.h"

 void AlphaBlend (HDC Dest, int xDest, int yDest, int wDest, int hDest, HDC Src,  int xSrc,  int ySrc,  int wSrc,  int hSrc, double alpha);

 int main()
     {
     txCreateWindow (800, 600);

     HDC Jopa = txLoadImage ("Панелька.bmp");
     if (Jopa == NULL) txMessageBox ("Ты плоская баба");

     txBegin ();

     AlphaBlend (txDC(), 0, 0, 60, 45, Jopa, 0, 0, 600, 450, 1);

     txEnd ();

     return 0;
     }

void AlphaBlend (HDC Dest, int xDest, int yDest, int wDest, int hDest,
                 HDC Src,  int xSrc,  int ySrc,  int wSrc,  int hSrc, double alpha)
    {

    BLENDFUNCTION blend = { AC_SRC_OVER, 0, (alpha * 255), AC_SRC_ALPHA };

    Win32::AlphaBlend (Dest, xDest, yDest, wSrc,  hSrc,
                       Src,  xSrc,  ySrc,  wDest, hDest, blend);
    }

