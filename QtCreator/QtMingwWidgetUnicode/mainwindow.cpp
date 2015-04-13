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

    const boost::filesystem::path *filePath = new boost::filesystem::path(L"D:\\MainNB\\Build\\Git\\Lab\\QtCreator\\QtMingwWidgetUnicode\\Data - テスト 測試.txt");

    boost::iostreams::mapped_file_source *file;

    try{
        file = new  boost::iostreams::mapped_file_source(*filePath);
    }catch(std::exception const&  ex){
        return;
    }

    boost::iostreams::stream<boost::iostreams::mapped_file_source> *is;

    is = new  boost::iostreams::stream<boost::iostreams::mapped_file_source>(*file, 99);

    boost::uint16_t len = file->size();

    int co = 0;
    while(true){
        int d = is->peek();
        if(d == EOF){
            break;
        }

        if(d == 0x61){
            Good a;
            is->read((char*)&a, sizeof(a));
            co++;
        }else{
            Good a;
            is->read((char*)&a, sizeof(a));
            co++;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
