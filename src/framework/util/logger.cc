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
#include <framework/util/timer.h>

// STL INCLUDES
//
#include <iostream>
#include <fstream>
#include <string>

using namespace OGFramework::Util;

std::ofstream Logger::gLogFile;

Logger::Logger( const char* filename )
{
	//mLoggerTag = " ";
	OpenGlobalLogger( filename );
}

Logger::~Logger()
{
	CloseGlobalLogger();
}

/*static*/
void Logger::OpenGlobalLogger( const char* filename )
{
	gLogFile.open( filename );
}

/*static*/
void Logger::CloseGlobalLogger()
{
	if (gLogFile.is_open())
	{
		gLogFile.flush();
		gLogFile.close();
	}
}

void Logger::setLogger( bool consoleOutput, bool fileOutput )
{
	mConsoleOutput = consoleOutput;
	mFileOutput = fileOutput;
}


void Logger::Log( LogLevel ogLevel, const char* msg )
{
	if (gLogFile.is_open())
	{
		gLogFile << "(" << mTimer.getElapsedTime() << " s) " << toString(ogLevel) << msg << std::endl;
		gLogFile.flush();
	}
	else
		Error( "The log file is not open for some reason!" );
}

void Logger::Debug( std::string msg )
{
	//if (!gLogFile.is_open())
		//Error( "The log file is not open for some reason!" );

#ifdef _DEBUG
	Lock(*this);

	if ( mFileOutput && gLogFile.is_open() )
	{
		gLogFile << "(" << mTimer.getElapsedTime() << " s) " << toString(DEBUG) << msg << std::endl;
		gLogFile.flush();
	}

	if ( mConsoleOutput )
	{
		std::cout << "(" << mTimer.getElapsedTime() << " s) " << toString(DEBUG) << msg << std::endl;
		std::cout.flush();
	}
#endif

}

void Logger::Info( std::string msg )
{
	//if (!gLogFile.is_open())
		//Error( "The log file is not open for some reason!" );

	Lock(*this);

	if ( mFileOutput && gLogFile.is_open() )
	{
		if ( getLoggerTag().empty() == false )
		{
			gLogFile << "(" << mTimer.getElapsedTime() << " s) " << getLoggerTag() << msg << std::endl;
			gLogFile.flush();
		}
		else
		{
			gLogFile << "(" << mTimer.getElapsedTime() << " s) " << toString(INFO) << msg << std::endl;
			gLogFile.flush();
		}
	}

	if ( mConsoleOutput )
	{

		if (getLoggerTag().empty() == false )
		{
			std::cout << "(" << mTimer.getElapsedTime() << " s) " << getLoggerTag() << msg << std::endl;
			std::cout.flush();
		}
		else
		{
			std::cout << "(" << mTimer.getElapsedTime() << " s) " << toString(INFO) << msg << std::endl;
			std::cout.flush();
		}
	}
}

void Logger::Warning( std::string msg )
{
	//if (!gLogFile.is_open())
		//Error( "The log file is not open for some reason!" );

	Lock(*this);

	if ( mFileOutput && gLogFile.is_open() )
	{
		gLogFile << "(" << mTimer.getElapsedTime() << " s) " << toString(WARNING) << msg << std::endl;
		gLogFile.flush();
	}

	if ( mConsoleOutput )
	{
		std::cout << "(" << mTimer.getElapsedTime() << " s) " << toString(WARNING) << msg << std::endl;
		std::cout.flush();
	}
}

void Logger::Error( std::string msg )
{
	//if (!gLogFile.is_open())
		//Error( "The log file is not open for some reason!" );

	Lock(*this);

	if ( mFileOutput && gLogFile.is_open() )
	{
		gLogFile << "(" << mTimer.getElapsedTime() << " s) " << toString(ERROR) << msg << std::endl;
		gLogFile.flush();
	}

	if ( mConsoleOutput )
	{
		std::cout << "(" << mTimer.getElapsedTime() << " s) " << toString(ERROR) << msg << std::endl;
		std::cout.flush();
	}
}

void Logger::Fatal( std::string msg )
{
	//if (!gLogFile.is_open())
		//Error( "The log file is not open for some reason!" );

	Lock(*this);

	if ( mFileOutput && gLogFile.is_open() )
	{
		gLogFile << "(" << mTimer.getElapsedTime() << " s) " << toString(FATAL) << " " << msg << std::endl;
		gLogFile.flush();
	}

	if ( mConsoleOutput )
	{
		std::cout << "(" << mTimer.getElapsedTime() << " s) " << toString(FATAL) << " " << msg << std::endl;
		std::cout.flush();
	}
}

/*
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


void Log::Info1( std::string message )
{
	Lock(*this);
	std::string tag;
	tag = "[" + logger.getLoggerTag() + "] ";
	//mLogStream << "(" << mTimer.getElapsedTime() << " s) " << tag << message << std::endl;
	std::cout << "(" << mTimer.getElapsedTime() << " s) " << tag << message << std::endl;
	//mLogStream << "(" << mTimer.getElapsedTime() << " s) " << "[" << logger.getLoggerTag() << "] " << message << std::endl;
}

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
}*/
