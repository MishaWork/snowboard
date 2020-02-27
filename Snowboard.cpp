
 #include "TXLib.h"

 void AlphaBlend (HDC Dest, int xDest, int yDest, int wDest, int hDest, HDC Src,  int xSrc,  int ySrc,  int wSrc,  int hSrc, double alpha);

 int main()
     {
     txCreateWindow (800, 600);

     HDC Jopa = txLoadImage ("RFRFRF.bmp");
     if (Jopa == NULL) txMessageBox ("Ты плоская баба");

     AlphaBlend (txDC(), 0, 0, 300, 300, Jopa, 0, 0, 266, 193, 1);

     return 0;
     }

void AlphaBlend (HDC Dest, int xDest, int yDest, int wDest, int hDest,
                 HDC Src,  int xSrc,  int ySrc,  int wSrc,  int hSrc, double alpha)
    {

    BLENDFUNCTION blend = { AC_SRC_OVER, 0, (alpha * 255), AC_SRC_ALPHA };

    Win32::AlphaBlend (Dest, xDest, yDest, wSrc,  hSrc,
                       Src,  xSrc,  ySrc,  wDest, hDest, blend);
    }

