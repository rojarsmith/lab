#include <typeinfo>
#include <gui/widget/GaussianFrame.hpp>
#include <touchgfx/Color.hpp>
#include <touchgfx/EasingEquations.hpp>

GaussianFrame::GaussianFrame()
	//textMoveAnimationEndedCallback(this, &GaussianFrame::textMoveAnimationEndedHandler)
{
	setPosition(0, 0, HAL::DISPLAY_WIDTH, HAL::DISPLAY_HEIGHT);
	//add(valueViewport);
	//add(pixelDataWidget);
}

GaussianFrame::~GaussianFrame()
{
}

void GaussianFrame::draw(const touchgfx::Rect& invalidatedArea) const
{
	touchgfx::Rect absolute = getAbsoluteRect();

	uint16_t *framebuffer = touchgfx::HAL::getInstance()->lockFrameBuffer();

	int allGrid = 0;

	for (int y = invalidatedArea.y; y < invalidatedArea.bottom(); y++)
	{
		for (int x = invalidatedArea.x; x < invalidatedArea.right(); x++)
		{
			allGrid++;
			int address = absolute.x + x + (absolute.y + y) * touchgfx::HAL::DISPLAY_WIDTH;
			framebuffer[address] = framebuffer[address] / 3; // TODO this is the place to do the actual blur
		}
	}

	touchgfx::HAL::getInstance()->unlockFrameBuffer();
}

touchgfx::Rect GaussianFrame::getSolidRect() const
{
	return Rect();
}

//void GaussianFrame::textMoveAnimationEndedHandler(const MoveAnimator<TextAreaWithOneWildcard>& source)
//{
//	//if (constatus == ANIMAN_IN_OV) {
//	//	constatus = VALUE_IN;
//	//}
//	//else if(constatus == VALUE_IN) {
//	//	constatus = ANIMAN_IN_OV;
//	//}
//	//else if (constatus == ANIMAN_RUNNING_VALUE_IN)
//	//{
//	//	for (int y = 0; y < sizeH; y++)
//	//	{
//	//		for (int x = 0; x < 200; x++)
//	//		{
//	//			drawPixel(x, y, 255, 255, 255, 0);
//	//		}
//	//	}
//	//	pixelDataWidget.invalidate();
//
//	//	drwagain = 1;
//	//	nX = 199;
//	//	nY = 49;
//
//	//	constatus = ANIMAN_IN_OV;
//	//}
//}
//
//void GaussianFrame::setDirection(Direction d) {
//	//direction = d;
//
//	//switch (direction) {
//	//case TOP_LEFT:
//	//	valueViewport.setPosition(0, 10, 200, 40);
//
//	//	value1Text.setPosition(0, 6, 200, 40);
//	//	value1Text.setWildcard(value1Buffer);
//	//	value1Text.setTypedText(TypedText(T_DEMO_VALUE1));
//	//	value1Text.setColor(Color::getColorFrom24BitRGB(0, 176, 80));
//	//	valueViewport.add(value1Text);
//
//	//	updateValue(0);
//
//	//	pixelDataWidget.setPosition(0, 100 - sizeH, sizeW, sizeH);
//	//	pixelDataWidget.setPixelData((uint8_t*)HAL::getInstance()->getAnimationStorage());
//	//	pixelDataWidget.setBitmapFormat(Bitmap::ARGB8888);
//
//	//	pixelBuffer = (uint8_t*)HAL::getInstance()->getAnimationStorage();
//
//	//	inventoryIn1Each = (int)((float)1.0 * len1 / inventoryIn1Max);
//	//	for (int y = 0; y < sizeH; y++)
//	//	{
//	//		for (int x = 0; x < 200; x++)
//	//		{
//	//			drawPixel(x, y, 255, 255, 255, 0);
//	//		}
//	//	}
//
//	//	break;
//	//case TOP_RIGHT:
//	//	break;
//	//case BOTTOM_LEFT:
//	//	break;
//	//case BOTTOM_RIGHT:
//	//	break;
//	//default:
//	//	break;
//	//}
//
//}
//
//void GaussianFrame::updateValue(int value)
//{
//	/*Unicode::snprintf(value1Buffer, 5, "%d", value);
//	value1Text.invalidate();*/
//}
//
//void GaussianFrame::drawLineIn()
//{
//	//for (int x = 0; x < inventoryIn1Each; x++)
//	//{
//	//	if (nX >= 150) {
//	//		drawPixel(nX - x, nX - x - 150, 0, 0, 255, alpha1);
//	//		drawPixel(nX - x + 1, nX - x - 150 - 1, 0, 0, 255, alpha1);
//	//		drawPixel(nX - x - 1, nX - x - 150 + 1, 0, 0, 255, alpha1);
//	//		drawPixel(nX - x + 1, nX - x - 150, 0, 0, 255, alpha1);
//	//		drawPixel(nX - x, nX - x - 150 + 1, 0, 0, 255, alpha1);
//	//	}
//	//	else if (nX < 150 && nX >= 2) {
//	//		if ((nX - x) == 145) {
//	//			for (int i = 0; i < 5; i++) {
//	//				drawPixel(nX - x + i, 0, 0,0, 255, alpha1);
//	//				drawPixel(nX - x + i, 1, 0,0, 255, alpha1);
//	//				drawPixel(nX - x + i, 2, 0,0, 255, alpha1);
//	//			}
//	//			continue;
//	//		}
//
//	//		drawPixel(nX - x + 1, 0, 0, 0, 255, alpha1);
//	//		drawPixel(nX - x + 1, 1, 0, 0, 255, alpha1);
//	//		drawPixel(nX - x + 1, 2, 0, 0, 255, alpha1);
//	//	}
//	//	else {
//	//		drawPixel(0, 1, 0, 0, 255, alpha1);
//	//		drawPixel(1, 0, 0, 0, 255, alpha1);
//	//		drawPixel(1, 1, 0, 0, 255, alpha1);
//	//		drawPixel(1, 2, 0, 0, 255, alpha1);
//	//		drawPixel(2, 0, 0, 0, 255, alpha1);
//	//		drawPixel(2, 1, 0, 0, 255, alpha1);
//	//		drawPixel(2, 2, 0, 0, 255, alpha1);
//	//		drwagain--;
//	//		constatus = ANIMAN_IN_OV;
//	//	}
//	//}
//	//if (nX >= inventoryIn1Each) {
//	//	nX -= inventoryIn1Each;
//	//}
//
//	//pixelDataWidget.invalidate();
//}
//
//void GaussianFrame::drawPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
//{
//	//if (x < 0 || x >= sizeW || y < 0 || y >= sizeH) { return; }
//
//	//pixelBuffer[x * 4 + y * 800 + 0] = b;
//	//pixelBuffer[x * 4 + y * 800 + 1] = g;
//	//pixelBuffer[x * 4 + y * 800 + 2] = r;
//	//pixelBuffer[x * 4 + y * 800 + 3] = a;
//}
//
//void GaussianFrame::setValueSample(int value)
//{
//	//valueSample = value;
//}
//
//void GaussianFrame::start(const int inventory, const int frequency, const int times)
//{
//	//constatus = ANIMAN_IN;
//
//	//Application::getInstance()->registerTimerWidget(this);
//}
//
//void GaussianFrame::handleTickEvent()
//{
//	//switch (constatus)
//	//{
//	//case ANIMAN_IN:
//	//	drawLineIn();
//
//	//	break;
//	//case ANIMAN_IN_OV:
//	//	if (drwagain > 0) {
//	//		drawLineIn();
//	//	}
//
//	//	if (0 == tick % 120) {
//	//		value1Text.clearMoveAnimationEndedAction();
//	//		value1Text.setMoveAnimationEndedAction(textMoveAnimationEndedCallback);
//	//		value1Text.startMoveAnimation(0, -30, 15, EasingEquations::linearEaseIn);
//	//	}
//	//	break;
//	//case VALUE_IN:
//	//	updateValue(tick % valueSample);
//	//	value1Text.setPosition(0, 42, 200, 40);
//	//	value1Text.startMoveAnimation(0, 6, 15, EasingEquations::linearEaseIn);
//	//	constatus = ANIMAN_RUNNING_VALUE_IN;
//	//	break;
//	//default:
//	//	break;
//	//}
//
//	//tick++;
//}
