/* 
 * File:   main.cpp
 * Author: temujin
 *
 * Created on May 23, 2014, 9:14 AM
 */

#include "EvolutionAlgorithm.h"
#include "PathSaver.h"
#include "WayPointGenerator.h"

#include <string>
#include <sstream>
using std::string;
using std::stringstream;

int main(int argc, char* argv[]) 
{
   CWayPointGenerator sGenerator;
   sGenerator.CreateWayPoints(string("points.text"), 100, 1000);
   CEvolutionAlgorithm::Init(string("points.text"), 100);
   CEvolutionAlgorithm::SortPaths();
   CPathSaver::SavePath(string("InitialList.text"), CEvolutionAlgorithm::GetAllPaths());
   for (int i=0; i<10000; i++)
   {
      CEvolutionAlgorithm::EvolvePaths();
      CEvolutionAlgorithm::SortPaths();
      CEvolutionAlgorithm::PrunePaths();
      if ((i % 1000) == 0)
      {
         stringstream strStr;
         strStr << "IntermediatePath-" << i << ".text";
         CPathSaver::SavePath(strStr.str(), CEvolutionAlgorithm::GetAllPaths());
      }
   }
   CPathSaver::SavePath(string("FinalList.text"), CEvolutionAlgorithm::GetAllPaths());
   return 0;
}

