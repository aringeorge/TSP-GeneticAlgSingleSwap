/* 
 * File:   EvolutionAlgorithm.h
 * Author: temujin
 *
 * Created on May 23, 2014, 12:48 PM
 */

#pragma once

#include "SinglePath.h"

#include <string>
#include <deque>

using std::string;
using std::deque;

class CEvolutionAlgorithm
{
protected:
   static CEvolutionAlgorithm m_sStaticInstance;
   static deque<CSinglePath> m_sPaths;
   
   CEvolutionAlgorithm()   {  };
   ~CEvolutionAlgorithm()  {  };
   
public:
   static void Init(string strFile, int nParentPathsPerGen);
   static void EvolvePaths();
   static void SortPaths();
   static void PrunePaths();
   static deque<CSinglePath> GetAllPaths();
};