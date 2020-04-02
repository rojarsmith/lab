#include <QCoreApplication>
#include <string>

void static strTest(char * str)
{

}

void static strTest(const char * str)
{

}

void static strTest(std::string str)
{

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const char * const ELEKCOIN_CONF_FILENAME = "elekcoin.conf";
    std::string str1 = "aaa";
    strTest(ELEKCOIN_CONF_FILENAME);
    strTest(str1);

    return a.exec();
}
