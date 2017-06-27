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
#include <gui/template_screen/TemplatePresenter.hpp>
#include <gui/template_screen/TemplateView.hpp>

TemplatePresenter::TemplatePresenter(TemplateView& v)
    :
	BasePresenter(v),
	view(v)
{
}

void TemplatePresenter::activate()
{
	timeUpdated(model->getCurrentTime());
}

void TemplatePresenter::deactivate()
{

}

void TemplatePresenter::timeUpdated(Time time)
{
	view.handleTimeUpdated(time.getValueInMillis());
	//view.handleTimeUpdated(time.hours, time.minutes, time.seconds);
}