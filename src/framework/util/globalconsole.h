/*
    OpenGalaxies PreCU Server - A Star Wars Galaxies Pre-Combat Upgrade Server.
    Copyright (C) 2009  OpenGalaxies (www.opengalaxies.org)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef GLOBALCONSOLE_H
#define GLOBALCONSOLE_H

// PROJECT INCLUDES
//
#include <framework/util/bytebuffer.h>
#include <framework/util/logger.h>
#include <framework/util/ogdef.h>
#include <framework/util/ogtypes.h>
#include <framework/util/singleton.h>

namespace OGFramework
{
	namespace Util
	{
		class OG_API GlobalConsole : /*public OGFramework::Util::Log,*/ public OGFramework::Util::Singleton< GlobalConsole >
		{
		public:
			GlobalConsole();
			virtual ~GlobalConsole();
		};

#define sConsole GlobalConsole::Instance()

	}
}

#endif
