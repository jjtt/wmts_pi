/******************************************************************************
 *
 * Project:  OpenCPN
 * Purpose:  WMTS Plugin
 * Author:   Juho Törmä
 *
 ***************************************************************************
 *   Copyright (C) 2018 by Juho Törmä                                      *
 *   $EMAIL$                                                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 */

#include "wx/wxprec.h"

#ifndef  WX_PRECOMP
  #include "wx/wx.h"
#endif //precompiled headers

#include "wmts_pi.h"


class wmts_pi;

// the class factories, used to create and destroy instances of the PlugIn

extern "C" DECL_EXP opencpn_plugin* create_pi(void *ppimgr)
{
    return new wmts_pi(ppimgr);
}

extern "C" DECL_EXP void destroy_pi(opencpn_plugin* p)
{
    delete p;
}

//---------------------------------------------------------------------------------------------------------
//
//    WMTS PlugIn Implementation
//
//---------------------------------------------------------------------------------------------------------

#include "icons.h"

//---------------------------------------------------------------------------------------------------------
//
//          PlugIn initialization and de-init
//
//---------------------------------------------------------------------------------------------------------

wmts_pi::wmts_pi(void *ppimgr)
      :opencpn_plugin_17 (ppimgr)
{
      // Create the PlugIn icons
      initialize_images();
}

wmts_pi::~wmts_pi(void)
{
     delete _img_wmts_pi;
     delete _img_wmts;
}

int wmts_pi::Init(void)
{
  m_tool_id = InsertPlugInTool(_T(""), _img_wmts, _img_wmts, wxITEM_CHECK, _("WMTS"), _T(""), NULL, WMTS_TOOL_POSITION, 0, this);

  return PLUGIN_OPTIONS;
}

bool wmts_pi::DeInit(void)
{
    return true;
}

int wmts_pi::GetAPIVersionMajor()
{
      return MY_API_VERSION_MAJOR;
}

int wmts_pi::GetAPIVersionMinor()
{
      return MY_API_VERSION_MINOR;
}

int wmts_pi::GetPlugInVersionMajor()
{
      return PLUGIN_VERSION_MAJOR;
}

int wmts_pi::GetPlugInVersionMinor()
{
      return PLUGIN_VERSION_MINOR;
}

wxBitmap *wmts_pi::GetPlugInBitmap()
{
      return _img_wmts_pi;
}

wxString wmts_pi::GetCommonName()
{
      return _("WMTS");
}

wxString wmts_pi::GetShortDescription()
{
      return _("WMTS - short description");
}

wxString wmts_pi::GetLongDescription()
{
      return _("WMTS - long description");
}

int wmts_pi::GetToolbarToolCount(void)
{
      return 1;
}

void wmts_pi::OnToolbarToolCallback(int id)
{
  wxLogMessage(wxT("WMTS_pi: OnToolbarToolCallback - start"));
}

void wmts_pi::ShowPreferencesDialog( wxWindow* parent )
{
}

bool wmts_pi::RenderOverlay( wxDC &dc, PlugIn_ViewPort *vp )
{
  wxLogMessage(wxT("WMTS_pi: RenderOverlay - start"));
  dc.DrawCircle(100,100,50);
  wxLogMessage(wxT("WMTS_pi: RenderOverlay - end"));
  return true;
}

