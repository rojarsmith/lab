/* 
 * File:   main.cpp
 * Author: Rojar Smith
 *
 * Created on 2014/12/28, 00:38
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

#include <boost/random/mersenne_twister.hpp> // for mt19937
#include <boost/random/uniform_int.hpp>
#include <boost/random/variate_generator.hpp>

using namespace std;

int main(int argc, char** argv) {

    unsigned frequencies[6] = {0};

    boost::mt19937 rng(std::time(0));
    boost::uniform_int<> uniform_dist(0, 5);
    boost::variate_generator<boost::mt19937&, boost::uniform_int<> > dice_roller(rng, uniform_dist);

    for (int i = 0; i < 1000000; ++i) ++frequencies[dice_roller()];

    std::cout << "テスト" << std::endl;
    
    for (int i = 0; i < 6; ++i) {
        std::cout << "骰子 " << i + 1 << " 點擲到了 " << frequencies[i] << " 次" << std::endl;
    }

    return (EXIT_SUCCESS);
}

