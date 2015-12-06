/* 
 * File:   PathSaver.h
 * Author: temujin
 *
 * Created on May 23, 2014, 1:21 PM
 */

#pragma once

#include "SinglePath.h"

#include <deque>
#include <string>
using std::string;
using std::deque;

class CPathSaver
{
protected:
   static CPathSaver m_sStaticInstance;
   
public:
   static void SavePath(string strFilename, deque<CSinglePath> sPaths);
};