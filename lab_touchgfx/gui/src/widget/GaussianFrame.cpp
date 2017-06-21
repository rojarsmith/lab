#include <typeinfo>
#include <gui/widget/GaussianFrame.hpp>
#include <touchgfx/Color.hpp>
#include <touchgfx/EasingEquations.hpp>
#include <cmath>
//#include <iomanip>

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
	int points = getWidth() * getHeight();
	fbCopy = reinterpret_cast<uint16_t*>(HAL::lcd().copyFrameBufferRegionToMemory(rect));
	fbCopyRef = new uint16_t[points];
	for (int i = 0; i < (points); i++)
	{
		*(fbCopyRef + i) = *(fbCopy + i);
	}
	fbCopyPtr = fbCopy;
	fbCopyRefPtr = fbCopyRef;

	float gKernel[5][5];
	createFilter(gKernel);	

	for (int i = 0; i < (points); i++, fbCopyPtr++, fbCopyRefPtr++)
	{
		int nx = i % 480;
		int ny = i / 480;

		float gr = 0;
		float gg = 0;
		float gb = 0;

		for (int fy = -2; fy <= 2; fy++)
		{
			for (int fx = -2; fx <= 2; fx++)
			{
				int px = nx + fx;
				int py = ny + fy;

				if (nx == 480){
					int zzz = 0;
				}

				if (ny == 272){
					int zzz = 0;
				}


				if (px < 0)
				{
					px = 0;
				}
				if (py < 0)
				{
					py = 0;
				}
				if (px >= 480 || py >= 272)
				{
					px = 479;
				}
				if (py >= 272)
				{
					py = 271;
				}

				int pp = py * 480 + px;
				int rr = (*(fbCopyRef + pp) >> 11) & 0x001F;
				int rg = (*(fbCopyRef + pp) >> 5) & 0x003F;
				int rb = *(fbCopyRef + pp) & 0x001F;

				float pgr = (float)1.0 * rr * (gKernel[fx + 2][fy + 2]);
				float pgg = (float)1.0 * rg * (gKernel[fx + 2][fy + 2]);
				float pgb = (float)1.0 * rb * (gKernel[fx + 2][fy + 2]);

				gr += pgr;
				gg += pgg;
				gb += pgb;
			}
		}

		int gr2 = (int)gr;
		int gg2 = (int)gg;
		int gb2 = (int)gb;

		uint16_t wp = 0;
		wp = (gr2 << 11) | (gg2 << 5) | gb2;
		*fbCopyPtr = wp;

		//*fbCopyS = (int)(1.0 * (*fbCopyS) * 0.7);
		//*fbCopyS = 0xF800; //Red
		//*fbCopyPtr = 0x07E0; //Green
		//*fbCopyS = 0x001F; //Blue		
	}

	delete fbCopyRef;
}

void GaussianFrame::openTest()
{
}

void GaussianFrame::createFilter(float gKernel[][5])
{
	float M_PI = (float)3.14159265358979323846;

	// set standard deviation to 1.0
	float sigma = 1.0;
	float r, s = (float)2.0 * sigma * sigma;

	// sum is for normalization
	float sum = 0.0;

	// generate 5x5 kernel
	for (int x = -2; x <= 2; x++)
	{
		for (int y = -2; y <= 2; y++)
		{
			r = (float)sqrt((float)x*x + (float)y*y);
			gKernel[x + 2][y + 2] = (exp(-(r*r) / s)) / (M_PI * s);
			sum += gKernel[x + 2][y + 2];
		}
	}

	// normalize the Kernel
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			gKernel[i][j] /= sum;
}