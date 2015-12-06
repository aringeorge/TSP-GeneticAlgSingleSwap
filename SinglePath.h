/* 
 * File:   SinglePath.h
 * Author: temujin
 *
 * Created on May 23, 2014, 11:54 AM
 */

#pragma once

#include "Common.h"

#include <deque>
#include <iterator>

using std::deque;
using std::iterator;

class CSinglePath
{
protected:
   deque<WayPoint> m_sInternalWaypoint;
   
   const double GetDistance(const double fX1, const double fX2, const double fY1, const double fY2) const;
public:
   void LoadWayPointsRandomly(deque<WayPoint> sWaypoints);
   const int GetNumPoints() const;
   const double GetPathLength() const;
   void SwapPoints(int nPt1Idx, int nPt2Idx);
   deque<WayPoint> GetPath();
   
   bool operator<(const CSinglePath &sRightSide) const;
   bool operator>(const CSinglePath &sRightSide) const;
};

