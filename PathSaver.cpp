#include "PathSaver.h"

#include <fstream>
#include <iostream>

using std::ofstream;
using std::endl;
using std::cout;

CPathSaver CPathSaver::m_sStaticInstance;

void CPathSaver::SavePath(string strFilename, deque<CSinglePath> sPaths)
{
   ofstream ofs;
   ofs.open(strFilename.c_str());
   for (auto sIterPaths=sPaths.begin(); sIterPaths!=sPaths.end(); sIterPaths++)
   {
      auto sCurrPath = sIterPaths->GetPath();
      for (auto sListPoints=sCurrPath.begin(); sListPoints!=sCurrPath.end(); sListPoints++)
      {
         ofs << sListPoints->ulName << " -> ";
      }
      ofs << " : " << sIterPaths->GetPathLength() << endl;
   }
   ofs.close();
}
