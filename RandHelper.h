/* 
 * File:   RandHelper.h
 * Author: temujin
 *
 * Created on May 23, 2014, 12:05 PM
 */

#pragma once

#include <random>


class CRandHelper
{
protected:
   static CRandHelper m_sStaticInstance;
   
   CRandHelper();
   
public:
   static int GetRand(int nMax);
};
