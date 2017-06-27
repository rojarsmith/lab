/******************************************************************************
 *
 * @brief     This file is part of the TouchGFX 4.8.0 standard distribution.
 *
 * @author    Draupner Graphics A/S <http://www.touchgfx.com>
 *
 ******************************************************************************
 *
 * @section Copyright
 *
 * This file is free software and is provided for example purposes. You may
 * use, copy, and modify within the terms and conditions of the license
 * agreement.
 *
 * This is licensed software, any use must strictly comply with the signed
 * license agreement and associated Terms & Conditions.
 *
 * Standard Terms & Conditions can be seen on www.touchgfx.com
 *
 * @section Disclaimer
 *
 * DISCLAIMER OF WARRANTY/LIMITATION OF REMEDIES: Draupner Graphics A/S has
 * no obligation to support this software. Draupner Graphics A/S is providing
 * the software "AS IS", with no express or implied warranties of any kind,
 * including, but not limited to, any implied warranties of merchantability
 * or fitness for any particular purpose or warranties against infringement
 * of any proprietary rights of a third party.
 *
 * Draupner Graphics A/S can not be held liable for any consequential,
 * incidental, or special damages, or any other relief, or for any claim by
 * any third party, arising from your use of this software.
 *
 *****************************************************************************/
#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

static volatile long lastUs;
#ifdef _MSC_VER
uint32_t SystemCoreClock = 200 * 1000000;
#else
extern uint32_t SystemCoreClock;
#endif
static int freqMHz;

static uint8_t mcuLoadLast = 0;


Model::Model()
	:
	modelListener(0),
	mcuLoadActive(true)
{
	lastUs = touchgfx::HAL::getInstance()->getCPUCycles();
	freqMHz = SystemCoreClock / 1000000;
}

void Model::tick()
{
	previousTime = currentTime;

	static int milliseconds = 123456;
	uint8_t mcuLoadPct = touchgfx::HAL::getInstance()->getMCULoadPct();
	if (mcuLoadLast != /*mcu_load_pct*/ mcuLoadPct)
	{
		mcuLoadLast = mcuLoadPct;
		modelListener->mcuLoadUpdated(mcuLoadLast);
	}

	long now = touchgfx::HAL::getInstance()->getCPUCycles();
	milliseconds += (now - lastUs + freqMHz / 2) / freqMHz / 1000;
	lastUs = now;
	currentTime.hours = (milliseconds / 1000 / 60 / 60) % 24;
	currentTime.minutes = (milliseconds / 1000 / 60) % 60;
	currentTime.seconds = (milliseconds / 1000) % 60;
	currentTime.milliseconds = milliseconds % 1000;
	//=========================================================================

	if (currentTime.seconds != previousTime.seconds)
	{
		if (modelListener)
		{
			modelListener->timeUpdated(currentTime);
		}
	}
}