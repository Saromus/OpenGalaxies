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
#include "testlogger.h"
#include <framework/util/logger.h>
#include <framework/util/globalconsole.h>

// STL INCLUDES
//
#include <iostream>

using namespace OGFramework::Util;

CPPUNIT_TEST_SUITE_REGISTRATION( TestLogger );

void 
TestLogger::setUp( void )
{
}

void
TestLogger::tearDown( void )
{
}

void 
TestLogger::LoggerTest( void )
{
	//std::cout < "\n" << std::endl; // new line so first DebugString() isn't on the same line as beginning ellipsis.
	//sConsole.DebugString( "Opening Log File." );
	Logger logger = /*new*/ Logger( "TestLogger.log" );
	//sConsole.DebugString( "'TestLogger.log' successfully opened." );

	//sConsole.DebugString( "Writing tests to Log" );

	logger.Log( INFO, "Testing Info Level." );
	logger.Log( DEBUG, "Testing Debug Level." );
	logger.Log( WARNING, "Testing Warning Level." );
	logger.Log( ERROR, "Testing Error Level." );
	logger.Log( FATAL, "Testing Fatal Level." );

	//sConsole.DebugString( "Finished logging. (delete logger)" );

	//delete logger;
}
