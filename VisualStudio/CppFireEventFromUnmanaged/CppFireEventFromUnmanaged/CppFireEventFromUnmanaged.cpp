#include "stdafx.h"
#include <windows.h>

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Threading;

class Camera
{
public:
	Camera()
	{
	}
	~Camera(){}
	void(*test)(int var1);	
	//void OnNewCameraData();
	void StartDataAcquisition();
	void StartDataAcquisition2();
	int _var1 = 0;
};

void Camera::StartDataAcquisition()
{
	int i;
	while (i<10)
	{
		this->_var1++;
		test(this->_var1);
		i++;		
		Sleep(100);
	}
}

void Camera::StartDataAcquisition2()
{
	int i;
	while (i<10)
	{
		this->_var1++;
		i++;
		Sleep(100);
	}
}

delegate void FunctionToCallDelegate(int);
delegate int FunctionToCallDelegate2();

ref class CameraAdapter
{
private:
	Camera *_camera;
	FunctionToCallDelegate ^_Function;
public:
	CameraAdapter(FunctionToCallDelegate ^handler)
	{
		_Function = handler;
	}
	void Init()
	{
		_camera = new Camera();
		//pin_ptr<FunctionToCallDelegate^> tmp = &_Function;
		_camera->test = (void(__cdecl *)(int))(Marshal::GetFunctionPointerForDelegate(_Function).ToPointer());
		_camera->StartDataAcquisition();
	}

	~CameraAdapter()
	{
		delete _camera;
		_camera = 0;
	}
	void OnNewCameraData(int var1)
	{
		Console::WriteLine("Received Frame " + var1 + "\n");

		if (var1.Equals(10)){
			Console::WriteLine("Fine");
		}
	}
};

ref class CameraAdapter2
{
private:
	Camera *_camera;	
public:
	CameraAdapter2()
	{		
	}
	void Init()
	{
		_camera = new Camera();		
		_camera->StartDataAcquisition2();
	}

	~CameraAdapter2()
	{
		delete _camera;
		_camera = 0;
	}
	int getVar1()
	{
		return this->_camera->_var1;
	}
};

void threadlogic();

ref class MyThread{
public:
	CameraAdapter2 ^cameraAdapter2;

	MyThread(CameraAdapter2 ^adapter)
	{
		cameraAdapter2 = adapter;
	}

	~MyThread()
	{
	}

	void run(){
		Thread^ thr1 = gcnew ::Thread(gcnew ::Threading::ThreadStart(this, &MyThread::threadlogic));
		thr1->Start();		
	}

	void threadlogic()
	{
		for (int i = 0; i < 10; i++){
			Threading::Thread::Sleep(100);
			Console::WriteLine(cameraAdapter2->getVar1());
			//Console::WriteLine(i);
		}
	}
};


ref class MyThread2{
private:
	Camera *_camera;
public:	
	MyThread2()
	{
		_camera = new Camera();
	}

	~MyThread2()
	{
	}

	void run(){
		Thread^ thr1 = gcnew ::Thread(gcnew ::Threading::ThreadStart(this, &MyThread2::threadlogic));
		Thread^ thr2 = gcnew ::Thread(gcnew ::Threading::ThreadStart(this, &MyThread2::threadlogic2));
		thr1->Start();
		thr2->Start();
	}

	void threadlogic()
	{
		_camera->StartDataAcquisition2();
	}

	void threadlogic2()
	{
		for (int i = 0; i < 10; i++){
			Threading::Thread::Sleep(100);
			Console::WriteLine(_camera->_var1);			
		}
	}
};


int main(array<System::String ^> ^args)
{
	FunctionToCallDelegate ^dsi;
	dsi += gcnew FunctionToCallDelegate(gcnew CameraAdapter(dsi), &CameraAdapter::OnNewCameraData);
	CameraAdapter ^camera = gcnew CameraAdapter(dsi);
	camera->Init();

	//Wrong
	//CameraAdapter2 ^camera2;
	//camera2 = gcnew CameraAdapter2();
	//camera2->Init();
	//MyThread ^ myThread = gcnew MyThread(camera2);
	//myThread->run();

	MyThread2 ^ myThread2 = gcnew MyThread2();
	myThread2->run();

	Console::ReadKey();
	return 0;
}

