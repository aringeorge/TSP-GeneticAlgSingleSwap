/* 
 * File:   CityLoader.h
 * Author: temujin
 *
 * Created on May 23, 2014, 9:36 AM
 */

#pragma once

#include "Common.h"

#include <deque>
#include <string>

using std::deque;
using std::string;

class CWayPointLoader
{
protected:
   deque<WayPoint> m_sMasterCityList;
   
public:
   void LoadWayPoints(string &strFile);
   deque<WayPoint> GetWayPointCopy();
};