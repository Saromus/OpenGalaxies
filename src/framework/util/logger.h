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
#include <string.h>

namespace OGFramework
{
	namespace Util
	{
		/**
		 * @class Logger
		 * @brief A logging system that will log a message
		 * to a specific file.
		 *
		 * @note The basic idea of design for this class is based
		 * on the file logger (logger.h) from SWGEmu. I used that
		 * file as a base for how this logger should work/function.
		 */
		class OG_API Logger : public OGFramework::Policies::ObjectLevelLockable< Logger >
		{
		public:

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

			Logger() { }
			Logger( const char* filename );
			~Logger();

			// OPERATIONS
			//

			/**
			 * Writes a message to the log file that is open.
			 * @param ogLevel The Level to log the message as.
			 * @param msg The message to be logged.
			 */
			void Log( LogLevel ogLevel, const char* msg );

			virtual void Info( std::string msg/*, bool doLogging = false*/ );
			virtual void Debug( std::string msg );
			virtual void Warning( std::string msg );
			virtual void Error( std::string msg );
			virtual void Fatal( std::string msg );

			/**
			 * Opens a file for logging. This file will be
			 * globally accessable to all resources that
			 * call #include <framework/util/logger.h>.
			 * @param filename The name of the file to be created.
			 */
			static void OpenGlobalLogger( const char* filename );
			static void CloseGlobalLogger();

			void setLogger( bool consoleOutput, bool fileOutput );

			// ACCESS
			//
			/**
			 * Adds an additional string prepended to each message
			 * substituting '[Info]' with the prepended tag.
			 * (useful for identifying services or child processes.
			 * It will only be used for 'logger.Info()'.
			 * A copy of tag is saved.
			 * @param loggerTag The string to be prepended to each message.
			 * @example setLoggerTag("ZoneServer");
			 */
			inline void setLoggerTag(const std::string& loggerTag)
			{
				mLoggerTag = "[" + loggerTag + "] ";
			}

			inline std::string& getLoggerTag()
			{
				return mLoggerTag;
			}

			// CONVERSION
			//
			/**
			 * Converts a LogLevel to a string representation.
			 */
			std::string toString( LogLevel ll ) const
			{
				std::string prefix;
				switch ( ll )
				{
				case INFO:
					prefix = "[Info] ";
					break;
#ifdef _DEBUG
				case DEBUG:
					prefix = "[Debug] ";
					break;
#endif
				case WARNING:
					prefix = "[Warning] ";
					break;

				case ERROR:
					prefix = "[Error] ";
					break;

				case FATAL:
					prefix = "[Fatal] ";
					break;
				}
				return prefix;
			}

		protected:

		private:
			OGFramework::Util::Timer	mTimer;
			std::string					mLoggerTag;
			bool						mFileOutput;
			bool						mConsoleOutput;
			static std::ofstream		gLogFile;

		}; // logger

		/**
		 * @class Log
		 * @brief A simple string logging class.
		 */
	/*	class Log : public OGFramework::Policies::ObjectLevelLockable< Log >
		{
		public:
			/**
			 * @arg std::ostream& A reference to the stream the information
			 * should be logged to.
			 *//*
			Log( std::ostream &outputStream );
			virtual ~Log();

			// OPERATIONS
			//
			//virtual void DebugString( std::string message );
			//virtual void Info1( std::string message );
			//virtual void Warning( std::string message );
			//virtual void Error( std::string message );
			//virtual void Fatal( std::string message );

		protected:
			std::ostream&			 	mLogStream;

		private:
			OGFramework::Util::Timer	mTimer;
			OGFramework::Util::Logger	logger;

		}; // log*/
	} // util
} // ogframework


#endif /* LOGGER_H_ */
