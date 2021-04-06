#include "GDF.h"


#include <iostream>

// main created only for my file reader (gdf to csv, Task 1) 
// used only for individual submission

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        string s(argv[1]);

        // object of GDF
        GDF obj(s);

        obj.readInputFile();
        obj.process();
        obj.writeOutput();
    }
    return 0;
}