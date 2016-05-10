#include <cstdlib>

#include "random.h"
#include "download_from_url.h"

using namespace std;

int main(int argc, char** argv) {

    Random();

    char* argv2[] = {argv[0], argv[1]};
    runTest(argc, argv2);

    return (EXIT_SUCCESS);
}
