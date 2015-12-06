#include "WayPointLoader.h"

#include <sstream>
#include <fstream>
#include <iostream>

using std::stringstream;
using std::ifstream;
using std::getline;
using std::cout;
using std::endl;

void CWayPointLoader::LoadWayPoints(string &strFile)
{
   m_sMasterCityList.clear();
   ifstream ifs;
   ifs.open(strFile.c_str());
   while (ifs.fail() == false)
   {
      string strVal;
      std::getline(ifs, strVal);
      if (ifs.fail() == false)
      {
         stringstream strStrVal;
         strStrVal.str(strVal);
         WayPoint sVal;
         strStrVal >> sVal.ulName;
         strStrVal >> sVal.fXCoord;
         strStrVal >> sVal.fYCoord;
         m_sMasterCityList.push_back(sVal);
      }
   }
   ifs.close();
}

deque<WayPoint> CWayPointLoader::GetWayPointCopy()
{
   return m_sMasterCityList;
}
