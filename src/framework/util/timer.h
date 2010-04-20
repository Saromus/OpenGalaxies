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

#ifndef TIMER_H_
#define TIMER_H_

// PROJECT INCLUDES
//
#include <framework/util/ogdef.h>
#include <framework/util/ogtypes.h>

// STL INCLUDES
//
#include <time.h>

namespace OGFramework
{
	namespace Util
	{
		/**
		 * @class Timer
		 * @brief This timer class acts like a "stopwatch", returning elapsed seconds or milliseconds.
		 *
		 * @see http://www.cplusplus.com/forum/beginner/317/
		 */
		class OG_API Timer
		{
		public:

			Timer() //: mStart(0), mEnd(0), mIsReset(true) mIsRunning(false)
			{
				mIsReset = true;
				mIsRunning = false;
				mStart = 0;
				mEnd = 0;
				//StartTimer();
			}

			~Timer()
			{
				//StopTimer();
			}

			void StartTimer()
			{
				/*if ( mIsRunning )
					return;*/

				//else { }

				if ( !mIsRunning )
				{
					if ( mIsReset )
						mStart = (unsigned long) clock();
					else
						mStart -= mEnd - (unsigned long) clock();

					mIsRunning = true;
					mIsReset = false;
				}
			}

			void StopTimer()
			{
				if ( mIsRunning )
				{
					mEnd = (unsigned long) clock();
					mIsRunning = false;
				}
			}

			/*
			 * Resets the Timer to 0 and then starts it up again.
			 */
			void ResetTimer()
			{
				bool wasRunning = mIsRunning;

				if ( wasRunning )
					StopTimer();

				mIsReset = true;
				mStart = 0;
				mEnd = 0;

				if ( wasRunning )
					StartTimer();
			}

			/*
			 * Returns a time interval in seconds.
			 */
			unsigned long getElapsedTime()
			{
				if ( mIsRunning )
					return ((unsigned long) clock() - mStart) / CLOCKS_PER_SEC;
				else
					return ( mEnd - mStart ) / CLOCKS_PER_SEC;
			}

			/*
			 * Returns a time interval in milliseconds.
			 */
			unsigned long getElapsedMili()
			{
				if ( mIsRunning )
					return ((unsigned long) clock() - mStart);
				else
					return mEnd - mStart;
			}

			bool IsRunning()
			{
				return mIsRunning;
			}

			bool IsTimeout( unsigned long seconds )	//bool IsOver( unsigned long seconds )
			{
				return seconds >= getElapsedTime();
			}

		protected:

		private:
			bool			mIsReset;
			bool			mIsRunning;
			unsigned long	mStart;
			unsigned long	mEnd;	//mEnd;

		};
	}
}

#endif /* TIMER_H_ */
