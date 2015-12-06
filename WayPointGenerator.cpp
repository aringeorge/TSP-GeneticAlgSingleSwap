#include "WayPointGenerator.h"
#include "RandHelper.h"

#include <fstream>
#include <iostream>

using std::ofstream;
using std::endl;

void CWayPointGenerator::CreateWayPoints(string strFileName, int nPoints, int nGridMax)
{
   ofstream ofs;
   ofs.open(strFileName.c_str());
   for (int i=0; i<nPoints; i++)
   {
      ofs << i << "   " << CRandHelper::GetRand(nGridMax) << "   " << CRandHelper::GetRand(nGridMax) << endl;
   }
   ofs.close();
}
