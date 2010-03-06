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

#ifndef LOGGER_H_
#define LOGGER_H_

// PROJECT INCLUDES
//
#include <framework/util/timer.h>
#include <framework/util/ogdef.h>
#include <framework/util/ogtypes.h>
#include <framework/policies/threading.h>

// STL INCLUDES
//
#include <iostream>
#include <fstream>
#include <ostream>

namespace OGFramework
{
	namespace Util
	{
		//Saromus - TODO: Dead1ock wants this moved to Logger class under the public section. Too lazy to fix all the errors this causes atm.
		enum LogLevel
		{
			INFO,
#ifdef _DEBUG
			DEBUG,
#endif
			WARNING,
			ERROR,
			FATAL
		};

		class OG_API Logger : public OGFramework::Policies::ObjectLevelLockable< Logger >
		{
		public:

			Logger( const std::string& filename );
			virtual ~Logger( void );

			// OPERATIONS
			//
			virtual void Log( LogLevel ogLevel, const std::string& msg );

			/**
			 * Converts a LogLevel to a string representation.
			 */
			std::string toString( LogLevel ll ) const
			{
				std::string prefix;
				switch ( ll )
				{
				case INFO:
					prefix = "[Info]";
					break;

#ifdef _DEBUG
				case DEBUG:
					prefix = "[Debug]";
					break;
#endif

				case WARNING:
					prefix = "[Warning]";
					break;

				case ERROR:
					prefix = "[Error]";
					break;

				case FATAL:
					prefix = "[Fatal]";
					break;
				}
				return prefix;
			}

		protected:

		private:
			std::ofstream				logFile;
			OGFramework::Util::Timer	timer;

		}; // logger


		/**
		 * @class Log
		 * @brief A simple string logging class.
		 */
		class Log : public OGFramework::Policies::ObjectLevelLockable< Log >
		{
		public:
			/**
			 * @arg std::ostream& - A reference to the stream the information
			 * should be logged to.
			 */
			Log( std::ostream &outputStream );
			virtual ~Log();

			// OPERATIONS
			//
			virtual void Info( std::string message );
			virtual void DebugString( std::string message );
			virtual void Warning( std::string message );
			virtual void Error( std::string message );
			virtual void Fatal( std::string message );

		protected:
			std::ostream& mLogStream;

		private:
			OGFramework::Util::Timer	timer;

		}; // log
	} // util
} // ogframework

#endif /* LOGGER_H_ */
