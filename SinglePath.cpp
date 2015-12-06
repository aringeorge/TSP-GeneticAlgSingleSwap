#include "SinglePath.h"
#include "RandHelper.h"

#include <iostream>

using std::cout;
using std::endl;

void CSinglePath::LoadWayPointsRandomly(deque<WayPoint> sWaypoints)
{
   if (sWaypoints.size() > 0)
   {
      do
      {
         int lVal = CRandHelper::GetRand(sWaypoints.size() - 1);
         WayPoint sPoint = *(sWaypoints.begin() + lVal);
         m_sInternalWaypoint.push_back(sPoint);
         sWaypoints.erase(sWaypoints.begin() + lVal);
      }
      while (sWaypoints.empty() == false);
   }
}

const double CSinglePath::GetDistance(const double fX1, const double fX2, const double fY1, const double fY2) const 
{
   return sqrt(((fX2 - fX1) * (fX2 - fX1)) + ((fY2 - fY1) * (fY2 - fY1)));
}

const double CSinglePath::GetPathLength() const
{
   double fLen = 0;
   for (auto sIter1=m_sInternalWaypoint.begin(); sIter1 != (m_sInternalWaypoint.end() - 1); sIter1++)
   {
      auto sIter2 = (sIter1 + 1);
      fLen = fLen + GetDistance(sIter1->fXCoord, sIter2->fXCoord, sIter1->fYCoord, sIter2->fYCoord);
   }
   auto sIter1 = (m_sInternalWaypoint.end() - 1);
   auto sIter2 = m_sInternalWaypoint.begin();
   fLen = fLen + GetDistance(sIter1->fXCoord, sIter2->fXCoord, sIter1->fYCoord, sIter2->fYCoord);
   return fLen;
}

void CSinglePath::SwapPoints(int nPt1Idx, int nPt2Idx)
{
   if ((nPt1Idx != nPt2Idx) && (nPt1Idx >= 0) && (nPt2Idx >= 0) && (nPt1Idx < (int)m_sInternalWaypoint.size()) && (nPt2Idx < (int)m_sInternalWaypoint.size()))
   {
      WayPoint sPt1 = *(m_sInternalWaypoint.begin() + nPt1Idx);
      WayPoint sPt2 = *(m_sInternalWaypoint.begin() + nPt2Idx);
      *(m_sInternalWaypoint.begin() + nPt2Idx) = sPt1;
      *(m_sInternalWaypoint.begin() + nPt1Idx) = sPt2;
   }
}

const int CSinglePath::GetNumPoints() const
{
   return m_sInternalWaypoint.size();
}

deque<WayPoint> CSinglePath::GetPath()
{
   return m_sInternalWaypoint;
}

bool CSinglePath::operator<(const CSinglePath &sRightSide) const
{
   return (this->GetPathLength() < sRightSide.GetPathLength());
}

bool CSinglePath::operator>(const CSinglePath &sRightSide) const
{
   return (this->GetPathLength() > sRightSide.GetPathLength());
}