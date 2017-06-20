#include <typeinfo>
#include <gui/widget/GaussianFrame.hpp>
#include <touchgfx/Color.hpp>
#include <touchgfx/EasingEquations.hpp>

GaussianFrame::GaussianFrame()
{
	setPosition(0, 0, HAL::DISPLAY_WIDTH, HAL::DISPLAY_HEIGHT);
}

GaussianFrame::~GaussianFrame()
{
}

void GaussianFrame::draw(const touchgfx::Rect& invalidatedArea) const
{
	if (!fbCopy)
	{
		return;
	}

	Rect absRect;
	translateRectToAbsolute(absRect);
	absRect.width = rect.width;
	absRect.height = rect.height;
	HAL::lcd().blitCopy(fbCopy, absRect, invalidatedArea, 255, false);
}

touchgfx::Rect GaussianFrame::getSolidRect() const
{
	return Rect(0, 0, getWidth(), getHeight());
}

void GaussianFrame::snap()
{
	fbCopy = reinterpret_cast<uint16_t*>(HAL::lcd().copyFrameBufferRegionToMemory(rect));
	fbCopyS = fbCopy;

	for (int i = 0; i < (480*272); i++){

		//*fbCopyS = (int)(1.0 * (*fbCopyS) * 0.7);
		//*fbCopyS = 0xF800; //Red
		*fbCopyS = 0x07E0; //Green
		//*fbCopyS = 0x001F; //Blue
		fbCopyS++;
	}
}

void GaussianFrame::openTest()
{
}