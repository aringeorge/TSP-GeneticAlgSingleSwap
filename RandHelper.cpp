#include "RandHelper.h"

#include <ctime>

CRandHelper CRandHelper::m_sStaticInstance;

CRandHelper::CRandHelper()
{
   srand(time(0));
}

int CRandHelper::GetRand(int nMax)
{
   int lVal = 0;
   if (nMax > 0)
   {
      lVal = rand() % nMax;
   }
   return lVal;
}