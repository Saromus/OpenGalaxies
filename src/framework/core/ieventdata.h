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

#ifndef IEVENTDATA_H
#define IEVENTDATA_H

// BOOST INCLUDE
//
#include <boost/shared_ptr.hpp>

// PROJECT INCLUDE
//
#include <framework/util/hashedstring.h>
#include <framework/util/iserializable.h>
#include <framework/util/ogdef.h>
#include <framework/util/ogtypes.h>

// STL INCLUDES
//
#include <ostream>

// TYPEDEF
//
typedef OGFramework::Util::HashedString EventType;

namespace OGFramework
{
	namespace Core
	{
		/**
		 * @class IEventData
		 * @brief A interface used to construct events for the EventManager.
		 *
		 * @note This class is based off of the IEventData class form "Game Coding Complete: Third Edition" by Mike McShaffry.
		 */
		class OG_API IEventData : public OGFramework::Util::ISerializable
		{
		public:
			IEventData() { }
			IEventData( std::istream &in ) { }
			virtual ~IEventData() { }
	
			// OPERATIONS
			//
			virtual bool Validate( void ) { return true; }
			virtual void Serialize( OGFramework::Util::ByteBuffer& archv ) const { }
			virtual void Deserialize( OGFramework::Util::ByteBuffer& archv ) const { }

			// ACCESS
			//
			virtual const EventType& GetEventType( void ) const = 0;
			virtual float GetTimeStamp() const = 0;
		};
	}
}

typedef boost::shared_ptr<OGFramework::Core::IEventData> IEventDataPtr;

#endif
