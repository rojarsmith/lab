#ifndef GAUSSIAN_FRAME_HPP_
#define GAUSSIAN_FRAME_HPP_

#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/PixelDataWidget.hpp>
#include <touchgfx/widgets/canvas/Line.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/mixins/MoveAnimator.hpp>

using namespace touchgfx;

class GaussianFrame : public Widget
{
public:
	//enum Status
	//{
	//	PREPARE,
	//	ANIMAN_RUNNING_VALUE_IN,
	//	ANIMAN_IN,
	//	ANIMAN_IN_OV,
	//	VALUE_IN
	//} constatus;

	GaussianFrame();
	virtual ~GaussianFrame();

	virtual void draw(const touchgfx::Rect& invalidatedArea) const;
	virtual touchgfx::Rect getSolidRect() const;

	//virtual void handleTickEvent();

	//void setDirection(Direction d);
	//void setValueSample(int value);
	//void start(const int inventory, const int frequency, const int times);

protected:
	//int tick;
	//int tickMax;

	//int drwagain;

	//uint16_t sizeW;
	//uint16_t sizeH;
	//uint8_t alpha1;

	//Container valueViewport;
	//PixelDataWidget pixelDataWidget;
	//MoveAnimator<TextAreaWithOneWildcard> value1Text;
	//Unicode::UnicodeChar value1Buffer[5];

	//Callback<GaussianFrame, const MoveAnimator<TextAreaWithOneWildcard>&> textMoveAnimationEndedCallback;
	//void textMoveAnimationEndedHandler(const MoveAnimator<TextAreaWithOneWildcard>& source);
};

#endif /* GAUSSIAN_FRAME_HPP_ */
