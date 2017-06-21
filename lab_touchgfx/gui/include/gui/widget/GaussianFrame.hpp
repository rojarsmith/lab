#ifndef GAUSSIAN_FRAME_HPP_
#define GAUSSIAN_FRAME_HPP_

#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/PixelDataWidget.hpp>
#include <touchgfx/widgets/canvas/Line.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>
#include <touchgfx/widgets/SnapshotWidget.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/mixins/MoveAnimator.hpp>

using namespace touchgfx;

class GaussianFrame : public Widget
{
public:
	GaussianFrame();
	virtual ~GaussianFrame();

	virtual void draw(const touchgfx::Rect& invalidatedArea) const;
	virtual touchgfx::Rect getSolidRect() const;

	void snap();
	void openTest();

protected:
	uint16_t* fbCopy;
	uint16_t* fbCopyRef;
	uint16_t* fbCopyPtr;
	uint16_t* fbCopyRefPtr;

	void createFilter(float gKernel[][5]);
};

#endif /* GAUSSIAN_FRAME_HPP_ */
