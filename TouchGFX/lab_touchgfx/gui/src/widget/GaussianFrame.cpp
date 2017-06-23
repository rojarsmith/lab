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
	int r = 10;
	float sigma = (float)(1.0 * r / 2.57);	//2.57 *sigam半徑之後基本沒有貢獻, 所以取sigma為 r / 2.57
	int boxSize = 3;
	int * boxes = boxesForGauss(sigma, boxSize);





	int points = getWidth() * getHeight();
	fbCopy = reinterpret_cast<uint16_t*>(HAL::lcd().copyFrameBufferRegionToMemory(rect));
	//fbCopyRef = new uint16_t[points];
	for (int i = 0; i < (points); i++)
	{
		*(fbCopyRef + i) = *(fbCopy + i);
	}
	fbCopyPtr = fbCopy;
	fbCopyRefPtr = fbCopyRef;




	boxBlur(fbCopy, fbCopyRef, getWidth(), getHeight(), (boxes[0] - 1) / 2);
	boxBlur(fbCopy, fbCopyRef, getWidth(), getHeight(), (boxes[1] - 1) / 2);
	boxBlur(fbCopy, fbCopyRef, getWidth(), getHeight(), (boxes[2] - 1) / 2);

	int aaa = 0;


	//int points = getWidth() * getHeight();
	//fbCopy = reinterpret_cast<uint16_t*>(HAL::lcd().copyFrameBufferRegionToMemory(rect));
	////fbCopyRef = new uint16_t[points];
	//for (int i = 0; i < (points); i++)
	//{
	//	*(fbCopyRef + i) = *(fbCopy + i);
	//}
	//fbCopyPtr = fbCopy;
	//fbCopyRefPtr = fbCopyRef;

	//float gKernel[5][5];
	//createFilter(gKernel);	

	//for (int i = 0; i < (points); i++, fbCopyPtr++, fbCopyRefPtr++)
	//{
	//	int nx = i % 480;
	//	int ny = i / 480;

	//	float gr = 0;
	//	float gg = 0;
	//	float gb = 0;

	//	for (int fy = -2; fy <= 2; fy++)
	//	{
	//		for (int fx = -2; fx <= 2; fx++)
	//		{
	//			int px = nx + fx;
	//			int py = ny + fy;

	//			if (nx == 480){
	//				int zzz = 0;
	//			}

	//			if (ny == 272){
	//				int zzz = 0;
	//			}


	//			if (px < 0)
	//			{
	//				px = 0;
	//			}
	//			if (py < 0)
	//			{
	//				py = 0;
	//			}
	//			if (px >= 480 || py >= 272)
	//			{
	//				px = 479;
	//			}
	//			if (py >= 272)
	//			{
	//				py = 271;
	//			}

	//			int pp = py * 480 + px;
	//			int rr = (*(fbCopyRef + pp) >> 11) & 0x001F;
	//			int rg = (*(fbCopyRef + pp) >> 5) & 0x003F;
	//			int rb = *(fbCopyRef + pp) & 0x001F;

	//			float pgr = (float)1.0 * rr * (gKernel[fx + 2][fy + 2]);
	//			float pgg = (float)1.0 * rg * (gKernel[fx + 2][fy + 2]);
	//			float pgb = (float)1.0 * rb * (gKernel[fx + 2][fy + 2]);

	//			gr += pgr;
	//			gg += pgg;
	//			gb += pgb;
	//		}
	//	}

	//	int gr2 = (int)gr;
	//	int gg2 = (int)gg;
	//	int gb2 = (int)gb;

	//	uint16_t wp = 0;
	//	wp = (gr2 << 11) | (gg2 << 5) | gb2;
	//	*fbCopyPtr = wp;

	//	//*fbCopyS = (int)(1.0 * (*fbCopyS) * 0.7);
	//	//*fbCopyS = 0xF800; //Red
	//	//*fbCopyPtr = 0x07E0; //Green
	//	//*fbCopyS = 0x001F; //Blue		
	//}

	////delete fbCopyRef;
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



////////////////////////////////////////////////////////////
//利用3個均值模糊 擬合 高斯模糊
//參考：http://blog.ivank.net/fastest-gaussian-blur.html
//橫向的均值模糊 srcPix：原始的圖元值 destPix將處理過的圖元值放入到 destPix中 

// standard deviation, number of boxes
int* GaussianFrame::boxesForGauss(float sigma, int n) {

	float wIdeal = sqrt((float)(12 * sigma * sigma / n) + 1);// Ideal averaging filter width 
	int wl = (int)floor(wIdeal);
	if (wl % 2 == 0) wl--;
	int wu = wl + 2;
	float mIdeal = (12 * sigma * sigma - n * wl * wl - 4 * n * wl - 3 * n) / (-4 * wl - 4);
	int m = (int)round(mIdeal);
	int * sizes = new int[n];
	for (int i = 0; i < n; i++)
	{
		sizes[i] = (i < m ? wl : wu);
	}
	return sizes;
}

void GaussianFrame::boxBlur(uint16_t* srcPix, uint16_t* destPix, int w, int h, int r)
{
	if (r < 0)
	{
		//LOGD("boxBlur r < 0: %d", r);
		return;
	}

	boxBlurH(srcPix, destPix, w, h, r);
	boxBlurV(destPix, srcPix, w, h, r);
}


void GaussianFrame::boxBlurH(uint16_t* srcPix, uint16_t* destPix, int w, int h, int radius)
{
	//用於索引
	int index = 0;


	//r g b在遍歷是 累加的色彩通道的總和
	int a = 0, r = 0, g = 0, b = 0;
	int ta = 0, tr = 0, tg = 0, tb = 0; //臨時變數
	uint16_t color = 0;
	int preColor = 0;


	//用於計算權值 1 / num
	int num = 0;
	float iarr = 0;


	for (int i = 0; i < h; ++i)
	{
		r = 0;
		g = 0;
		b = 0;


		index = i * w;
		num = radius;


		for (int j = 0; j < radius; j++)
		{
			//累加0,radius-1的色彩的總和
			color = srcPix[index + j];
			//a += (color & 0xff000000) >> 24;
			/*		r += (color & 0x00ff0000) >> 16;
			g += (color & 0x0000ff00) >> 8;
			b += (color & 0x000000ff);*/
			r += (color >> 11) & 0x001F;
			g += (color >> 5) & 0x003F;
			b += (color & 0x001F);

			//			int rr = (*(fbCopyRef + pp) >> 11) & 0x001F;
			//			int rg = (*(fbCopyRef + pp) >> 5) & 0x003F;
			//			int rb = *(fbCopyRef + pp) & 0x001F;
		}


		//真正開始計算
		for (int j = 0; j <= radius; ++j)
		{
			num++;
			iarr = (float)(1.0 / (1.0 * num));

			color = srcPix[index + j + radius];
			//a += (color & 0xff000000) >> 24;
			//r += (color & 0x00ff0000) >> 16;
			//g += (color & 0x0000ff00) >> 8;
			//b += (color & 0x000000ff);
			r += (color >> 11) & 0x001F;
			g += (color >> 5) & 0x003F;
			b += (color & 0x001F);

			//ta = (int)(1.0 * a / num);
			tr = (int)(r * iarr);
			tg = (int)(g * iarr);
			tb = (int)(b * iarr);


			//			destPix[index + j] = tr << 16 | tg << 8 | tb | 0xff000000;
			destPix[index + j] = tr << 11 | tg << 5 | tb;
		}


		iarr = (float)(1.0 / (1.0 * num));
		for (int j = radius + 1; j < w - radius; ++j)
		{
			preColor = srcPix[index + j - 1 - radius];
			color = srcPix[index + j + radius];


			//a += (color & 0xff000000) >> 24 - (preColor & 0xff000000) >> 24;
			//r = r + ((color & 0x00ff0000) >> 16) - ((preColor & 0x00ff0000) >> 16);
			//g = g + ((color & 0x0000ff00) >> 8) - ((preColor & 0x0000ff00) >> 8);
			//b = b + (color & 0x000000ff) - (preColor & 0x000000ff);
			r = r + ((color >> 11) & 0x001F) - ((preColor >> 11) & 0x001F);
			g = g + ((color >> 5) & 0x003F) - ((preColor >> 5) & 0x003F);
			b = b + (color & 0x001F) - (preColor & 0x001F);

			//ta = (int)(1.0 * a / num);
			tr = (int)(r * iarr);
			tg = (int)(g * iarr);
			tb = (int)(b * iarr);


			//			destPix[index + j] = tr << 16 | tg << 8 | tb | 0xff000000;
			destPix[index + j] = tr << 11 | tg << 5 | tb;
		}


		for (int j = w - radius; j < w; ++j)
		{
			num--;
			iarr = (float)(1.0 / (1.0 * num));


			preColor = srcPix[index + j - 1 - radius];


			//a -= (preColor & 0xff000000) >> 24;
			/*r -= (preColor & 0x00ff0000) >> 16;
			g -= (preColor & 0x0000ff00) >> 8;
			b -= (preColor & 0x000000ff);*/
			r -= (preColor >> 11) & 0x001F;
			g -= (preColor >> 5) & 0x003F;
			b -= (preColor & 0x001F);

			//ta = (int)(1.0 * a / num);
			tr = (int)(r * iarr);
			tg = (int)(g * iarr);
			tb = (int)(b * iarr);


			//
			//destPix[index + j] = (ta << 24 | tr << 16 | tg << 8 | tb);
			//			destPix[index + j] = tr << 16 | tg << 8 | tb | 0xff000000;
			destPix[index + j] = tr << 11 | tg << 5 | tb;
		}
	}
}




//列的均值模糊 srcPix：原始的圖元值 destPix將處理過的圖元值放入到 destPix中 
void GaussianFrame::boxBlurV(uint16_t* srcPix, uint16_t* destPix, int w, int h, int radius)
{
	//r g b在遍歷是 累加的色彩通道的總和
	int a = 0, r = 0, g = 0, b = 0;
	int ta = 0, tr = 0, tg = 0, tb = 0;	//臨時變數

	int color = 0;
	int preColor = 0;


	//用於計算權值 1 / num
	int num = 0;
	float iarr = 0;


	for (int i = 0; i < w; ++i)
	{
		r = 0;
		g = 0;
		b = 0;


		num = radius;


		for (int j = 0; j < radius; ++j)
		{
			color = srcPix[j*w + i];
			//r += (color & 0x00ff0000) >> 16;
			//g += (color & 0x0000ff00) >> 8;
			//b += (color & 0x000000ff);
			r += (color >> 11) & 0x001F;
			g += (color >> 5) & 0x003F;
			b += (color & 0x001F);
		}


		for (int j = 0; j <= radius; ++j)
		{
			num++;
			iarr = (float)(1.0 / (1.0 * num));


			color = srcPix[(j + radius) * w + i];
			//r += (color & 0x00ff0000) >> 16;
			//g += (color & 0x0000ff00) >> 8;
			//b += (color & 0x000000ff);
			r += (color >> 11) & 0x001F;
			g += (color >> 5) & 0x003F;
			b += (color & 0x001F);


			tr = (int)(r * iarr);
			tg = (int)(g * iarr);
			tb = (int)(b * iarr);


			//destPix[j*w + i] = tr << 16 | tg << 8 | tb | 0xff000000;
			destPix[j*w + i] = tr << 11 | tg << 5 | tb | 0xff000000;
		}


		iarr = (float)(1.0 / (1.0 * num));
		for (int j = radius + 1; j < h - radius; ++j)
		{
			preColor = srcPix[(j - radius - 1) * w + i];
			color = srcPix[(j + radius) * w + i];


			//r = r + ((color & 0x00ff0000) >> 16) - ((preColor & 0x00ff0000) >> 16);
			//g = g + ((color & 0x0000ff00) >> 8) - ((preColor & 0x0000ff00) >> 8);
			//b = b + (color & 0x000000ff) - (preColor & 0x000000ff);
			r = r + ((color >> 11) & 0x001F) - ((preColor >> 11) & 0x001F);
			g = g + ((color >> 5) & 0x003F) - ((preColor >> 5) & 0x003F);
			b = b + (color & 0x001F) - (preColor & 0x001F);

			tr = (int)(r * iarr);
			tg = (int)(g * iarr);
			tb = (int)(b * iarr);


			//destPix[j*w + i] = tr << 16 | tg << 8 | tb | 0xff000000;
			destPix[j*w + i] = tr << 11 | tg << 5 | tb;
		}


		for (int j = h - radius; j < h; ++j)
		{
			num--;
			iarr = (float)(1.0 / (1.0 * num));
			preColor = srcPix[(j - radius - 1) * w + i];


			//r -= (preColor & 0x00ff0000) >> 16;
			//g -= (preColor & 0x0000ff00) >> 8;
			//b -= (preColor & 0x000000ff);
			r -= (preColor >> 11) & 0x001F;
			g -= (preColor >> 5) & 0x003F;
			b -= (preColor & 0x001F);

			tr = (int)(r * iarr);
			tg = (int)(g * iarr);
			tb = (int)(b * iarr);


			//destPix[j*w + i] = tr << 16 | tg << 8 | tb | 0xff000000;
			destPix[j*w + i] = tr << 11 | tg << 5 | tb;
		}
	}
}