// predictHousePrice_main.cpp
#include <cstring>
#include <iomanip>
#include <iostream>
#include "predictHousePrice.hpp"

using namespace std;

int main(int argc, char **argv)
{
    if (argc >= 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0))
    {
        cout << argv[0] << ": usage <house-area> <room-number>" << endl;
        return 0;
    }
    if (argc != 3)
    {
        cerr << argv[0] << ": missing parameters (see --help)" << endl;
        return 1;
    }

    unsigned int area;
    uint8_t rooms;

    try
    {
        if (sscanf(argv[1], "%u", &area) <= 0)
        {
            throw invalid_argument("not a valid number");
        };
        if (sscanf(argv[2], "%hhu", &rooms) <= 0)
        {
            throw invalid_argument("not a valid number");
        };
    }
    catch (const exception &e)
    {
        cerr << argv[0] << ": parameter not parseable (see --help)" << endl
             << e.what() << endl;
        return 1;
    }

    cout << "House area: " << area << endl
         << "Number of Rooms: " << static_cast<unsigned int>(rooms) << endl
         << string(40, '-') << endl
         << "Price: " << fixed << setprecision(2) << predictHousePrice(area, rooms) << endl;

    return 0;
}
