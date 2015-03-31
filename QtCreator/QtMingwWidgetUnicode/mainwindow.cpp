#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <fstream>
#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/iostreams/device/mapped_file.hpp>
#include <boost/iostreams/stream.hpp>
#include "good.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    std::string p1 = "C:\\Data\\d - テスト 測試.txt";

    const boost::filesystem::path *p5 = new boost::filesystem::path(L"D:\\Build\\テスト 測試.txt");

    const wchar_t *p6 = L"C\u003A\u005CData\u005Cd - \u30C6\u30B9\u30C8 \u6E2C\u8A66.txt";

    const boost::filesystem::path *p7 = new boost::filesystem::path(p6);

    boost::iostreams::mapped_file_source *file;

    try{

    file = new  boost::iostreams::mapped_file_source(*p5);

    }catch(std::exception const&  ex){

        int abc = 0;
        abc = 999;
        return;
    }

    std::ifstream r(p1.c_str(), std::ios::in);
    if (!r) {
        std::cout << "無法讀取檔案" << std::endl;
        //return;
    }

    std::cout << r << std::endl;



    boost::filesystem::ifstream r2(*p7, std::ios::in | std::ios::binary);
    if (!r2) {
        std::cout << "無法讀取檔案" << std::endl;
        //return;
    }

    //std::cout << file.() << std::endl;


    boost::iostreams::stream<boost::iostreams::mapped_file_source> *is;


    is = new  boost::iostreams::stream<boost::iostreams::mapped_file_source>(*file, 99);



    boost::uint16_t len = file->size();

    //is.stream.
    //is.
    int co = 0;
    while(true){
        int d = is->peek();
        if(d == EOF){
            int bbb = 0;
            break;
        }

        if(d == 0x61){
            Good a;
            is->read((char*)&a, sizeof(a));
            int aaaaa = 0;
            co++;
        }else{
            Good a;
            is->read((char*)&a, sizeof(a));
            co++;
        }


    }
    //is >> a;
    boost::uint16_t zz = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}
