/* 
 * File:   WayPointGenerator.h
 * Author: temujin
 *
 * Created on May 23, 2014, 2:22 PM
 */

#pragma once

#include <string>

using std::string;

class CWayPointGenerator
{
protected:
public:
   void CreateWayPoints(string strFileName, int nPoints, int nGridMax);
};
