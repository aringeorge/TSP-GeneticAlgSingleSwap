#include "EvolutionAlgorithm.h"
#include "WayPointLoader.h"
#include "Common.h"
#include "RandHelper.h"

#include <algorithm>
#include <iostream>

using std::sort;
using std::less;

using std::cout;
using std::endl;

CEvolutionAlgorithm CEvolutionAlgorithm::m_sStaticInstance;
deque<CSinglePath> CEvolutionAlgorithm::m_sPaths;
   
void CEvolutionAlgorithm::Init(string strFile, int nParentPathsPerGen)
{
   CWayPointLoader sLoader;
   sLoader.LoadWayPoints(strFile);
   for (int i=0; i<nParentPathsPerGen; i++)
   {
      deque<WayPoint> sPoints = sLoader.GetWayPointCopy();
      CSinglePath sPath;
      sPath.LoadWayPointsRandomly(sPoints);
      m_sPaths.push_back(sPath);
   }
}

void CEvolutionAlgorithm::EvolvePaths()
{
   int lSize = m_sPaths.size();
   for (int i=0; i<lSize; i++)
   {
      CSinglePath sNewPath = *(m_sPaths.begin() + i);
      int lPt1 = CRandHelper::GetRand(sNewPath.GetNumPoints());
      int lPt2 = CRandHelper::GetRand(sNewPath.GetNumPoints());
      sNewPath.SwapPoints(lPt1, lPt2);
      m_sPaths.push_back(sNewPath);
   }
}

void CEvolutionAlgorithm::SortPaths()
{
   sort(m_sPaths.begin(), m_sPaths.end(), less<CSinglePath>());
}

void CEvolutionAlgorithm::PrunePaths()
{
   auto sBegin = m_sPaths.begin() + (m_sPaths.size() / 2);
   m_sPaths.erase(sBegin, m_sPaths.end());
}

deque<CSinglePath> CEvolutionAlgorithm::GetAllPaths()
{
   return m_sPaths;
}
