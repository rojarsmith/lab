///
/// @file
/// This is a simple, sychronous wget implementation. It accepts a URL as its one parameter,
/// connects to it, downloads the page via synchronous HTTP, and prints it to stdout.
///
/// @note   The meat of this tutorial is in the requestPage method.
///
/// @note   I use small try-catch blocks throughout the code in order to better illustrate where
///         Boost::ASIO throws exceptions and document their causes. This is, obviously, not a
///         requirement. Also, any function which may throw an exception can optionally take a
///         boost::system::error_code& as the last parameter. In this case the error will be passed
///         back through that parameter instead of an exception being thrown.
///

#ifndef DOWNLOAD_FROM_URL_H
#define	DOWNLOAD_FROM_URL_H

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/system/system_error.hpp>
#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

enum ErrorCodes {
    SUCCESS = 0,
    BAD_ARGUMENTS,
    RESOLVER_FAILURE,
    CONNECTION_FAILURE,
    WRITE_FAILURE,
    READ_FAILURE
};

int runTest(int argc, char* argv[]);

#endif	/* DOWNLOAD_FROM_URL_H */

