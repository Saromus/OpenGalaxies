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
#include <ctime>

//Saromus - TODO: Document methods.
namespace OGFramework
{
	namespace Util
	{
		/**
		 * @class Timer
		 * @see http://forums.devarticles.com/c-c-help-52/basic-c-timer-172684.html
		 * @see http://wiki.forum.nokia.com/index.php/CS001102_-_One-second_timer_implementation_using_Open_C%2B%2B
		 */
		class OG_API Timer
		{
		public:
			Timer() : mStartTime(0), mStopTime(0), mIsReset(false), mIsRunning(false)
			{
				StartTimer();
			}

			virtual ~Timer()
			{
				StopTimer();
			}

			virtual void StartTimer()
			{
				if (mIsRunning)
				{
					return;
				}
				else if (mIsReset)
				{
					time(&mStartTime);
				}
				else
				{
					mStartTime = time(NULL);
					mIsRunning = true;
					mIsReset = false;
				}
			}

			virtual void StopTimer()
			{
				if (mIsRunning)
				{
					mIsRunning = false;
					mStopTime = time(NULL);
					//time(&mStopTime);
					//mStopTime = time(&mStopTime);
				}
			}

			virtual void RestartTimer(bool restart)
			{
				if (mIsRunning)
				{
					StopTimer();
					mIsReset = true;
					mStartTime = mStopTime;
					if (restart)
					{
						StartTimer();
					}
				}
			}

			int Timer::getElapsedTime()
			{
				if (mIsRunning)
				{
					time_t now = time(&now);

					int elapsed = now - mStartTime;
					return elapsed;
				}
				else
				{
					/**
					 * Subtracts the start time and end time to get the total number
					 * of seconds elapsed.
					 */
					int elapsed = mStopTime - mStartTime;
					return elapsed;
				}
			}

			bool IsRunning()
			{
				return mIsRunning;
			}

			bool IsReset()
			{
				return mIsReset;
			}

		protected:

		private:
			time_t mStartTime;
			time_t mStopTime;

			bool mIsRunning;
			bool mIsReset;

		};
	}
}

#endif /* TIMER_H_ */
