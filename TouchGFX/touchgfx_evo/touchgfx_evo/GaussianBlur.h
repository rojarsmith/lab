#ifndef GAUSSIAN_BLUR_HPP_
#define GAUSSIAN_BLUR_HPP_

class GaussianBlur
{
public:
	int
#ifdef _MSC_VER	
		__declspec(dllexport) 
#endif 
		CalF(const int iNum);

    //int CalF(const int iNum);
};

#endif // GAUSSIAN_BLUR_HPP_