#pragma once
/*
 *      Copyright (C) 2005-2013 Team XBMC
 *      http://xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#include "IDirectory.h"
#include <string>

class CURL;
class TiXmlElement;

namespace XFILE
{
  class CTuxBoxDirectory : public IDirectory
  {
    public:
      CTuxBoxDirectory(void);
      virtual ~CTuxBoxDirectory(void);
      virtual bool GetDirectory(const CURL& url, CFileItemList &items);
      virtual bool AllowAll() const { return true; }
      virtual DIR_CACHE_TYPE GetCacheType(const CURL& url) const { return DIR_CACHE_ALWAYS; };
    private:
      bool GetRootAndChildString(const std::string strPath, std::string& strBQRequest, std::string& strXMLRootString, std::string& strXMLChildString );
      void GetRootAndChildStringEnigma2(std::string& strBQRequest, std::string& strXMLRootString, std::string& strXMLChildString );
  };
}

