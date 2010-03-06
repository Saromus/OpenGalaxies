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

// PROJECT INCLUDES
//
#include "logger.h"
#include <framework/util/globalconsole.h>

// STL INCLUDES
//
#include <iostream>
#include <fstream>
#include <string>

using namespace OGFramework::Util;

Logger::Logger( const std::string& filename )
{
	logFile.open(filename.c_str());
}

Logger::~Logger( void )
{
	if (logFile.is_open())
	{
		logFile.flush();
		logFile.close();
	}
}

void Logger::Log( LogLevel ogLevel, const std::string& msg )
{
	if (logFile.is_open())
	{
		logFile << "(" << timer.getElapsedTime() << " s) " << toString(ogLevel) << " " << msg.c_str() << std::endl;
		logFile.flush();
	}
	else
	{
		sConsole.Error( "Log File is not open for some reason!" );
	}
}

Log::Log( std::ostream &outputStream )
: mLogStream( outputStream )
{
}

Log::~Log()
{
}

void Log::DebugString( std::string message )
{
	Lock(*this);
#ifdef _DEBUG
	mLogStream << "(" << timer.getElapsedTime() << " s) " << "[Debug]: " << message << std::endl;
#endif
}

void Log::Info( std::string message )
{
	Lock(*this);
	mLogStream << "(" << timer.getElapsedTime() << " s) " << "[Info]: " << message << std::endl;
}

void Log::Warning( std::string message )
{
	Lock(*this);
	mLogStream << "(" << timer.getElapsedTime() << " s) " << "[Warning]: " << message << std::endl;
}

void Log::Error( std::string message )
{
	Lock(*this);
	mLogStream << "(" << timer.getElapsedTime() << " s) " << "[Error]: " << message << std::endl;
}

void Log::Fatal( std::string message )
{
	Lock(*this);
	mLogStream << "(" << timer.getElapsedTime() << " s) " << "[Fatal]: " << message << std::endl;
}
