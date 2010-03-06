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

#ifndef TESTLOGGER_H_
#define TESTLOGGER_H_

// CPPUNIT INCLUDES
//
#include <cppunit/extensions/HelperMacros.h>

// PROJECT INCLUDES
#include <framework/util/logger.h>

// STL INCLUDES
#include <iostream>
#include <fstream>
#include <string>

class TestLogger : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE( TestLogger );
	CPPUNIT_TEST( LoggerTest );
	CPPUNIT_TEST_SUITE_END();

public:
	TestLogger( void ) { }
	~TestLogger( void ) { }

	void setUp( void );
	void tearDown( void );

	void LoggerTest( void );
	
protected:
private:

};

#endif
