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
	std::cout << "\n" << std::endl;

	//print to console & file.
	logger.setLogger(true,true);
	logger.Info( "Testing logger without loggerName." );

	//print to console only.
	logger.setLogger(true,false);
	logger.Info( "Testing Info Level." );
	logger.Debug( "Testing Debug Level." );
	logger.Warning( "Testing Warning Level." );
	logger.Error( "Testing Error Level." );
	logger.Fatal( "Testing Fatal Level." );

	//print to file only
	logger.setLogger(false,true);
	logger.setLoggerTag( "TestLogger" );

	logger.Info( "Testing Info Level." );
	logger.Debug( "Testing Debug Level." );
	logger.Warning( "Testing Warning Level." );
	logger.Error( "Testing Error Level." );
	logger.Fatal( "Testing Fatal Level." );

	//print to console & file.
	logger.setLogger(true,true);

	logger.Info( "Testing logger with loggerName. logs to file too." );
}