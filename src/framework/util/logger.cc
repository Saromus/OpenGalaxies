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

std::ofstream Logger::gLogFile;

Logger::Logger( const char* filename )
{
	OpenLogger( filename );
}

Logger::~Logger()
{
	CloseLogger();
}

void Logger::Log( LogLevel ogLevel, const char* msg )
{
	if (gLogFile.is_open())
	{
		gLogFile << "(" << mTimer.getElapsedTime() << " s) " << toString(ogLevel) << " " << msg << std::endl;
		gLogFile.flush();
	}
	else
		sConsole.Error( "The log file is not open for some reason!" );
}

void Logger::Info( std::string msg )
{
	if (getLoggerName().empty() == false)
		std::cout << "(" << mTimer.getElapsedTime() << " s) " << "[" << getLoggerName() << "] " << msg << std::endl;

	else
		std::cout << "(" << mTimer.getElapsedTime() << " s) " << toString(INFO) << " " << msg << std::endl;
}

/*static*/
void Logger::OpenLogger( const char* filename )
{
	gLogFile.open( filename );
}

/*static*/
void Logger::CloseLogger()
{
	if (gLogFile.is_open())
	{
		gLogFile.flush();
		gLogFile.close();
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
	mLogStream << "(" << mTimer.getElapsedTime() << " s) " << "[Debug] " << message << std::endl;
#endif
}

/*
void Log::Info( std::string message )
{
	Lock(*this);
	mLogStream << "(" << mTimer.getElapsedTime() << " s) " << "[Info] " << message << std::endl;
}*/

void Log::Warning( std::string message )
{
	Lock(*this);
	mLogStream << "(" << mTimer.getElapsedTime() << " s) " << "[Warning] " << message << std::endl;
}

void Log::Error( std::string message )
{
	Lock(*this);
	mLogStream << "(" << mTimer.getElapsedTime() << " s) " << "[Error] " << message << std::endl;
}

void Log::Fatal( std::string message )
{
	Lock(*this);
	mLogStream << "(" << mTimer.getElapsedTime() << " s) " << "[Fatal] " << message << std::endl;
}