#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <thread>

void sort()
{

    using namespace std::chrono_literals;

    std::ifstream file("Arrayfile.txt");
    if (file.is_open())
    {
        int sortingArray[5000];
        int tempArray[2];
        int h = 1;
        bool loopagain = false;

        for (int p = 0; p < 5000; ++p)
        {
            file >> sortingArray[p];
        }

        for (int i = 0; i < h; i++)
        {

            for (int ii = 0; ii < 4999; ii++)
            {
                if (sortingArray[ii] > sortingArray[ii + 1])
                {
                    tempArray[0] = sortingArray[ii];
                    sortingArray[ii] = sortingArray[ii + 1];
                    sortingArray[ii + 1] = tempArray[0];
                    loopagain = true;
                }
            }
            if (loopagain != false)
            {
                h++;
            }
            loopagain = false;

        }
        //for (int k = 0; k < 5000; k++)
        //{
        //    std::cout << sortingArray[k] << "\n";
        //}

        std::cout << "\n";
        std::cout << "Array was sorted in " << h << " passes\n";
    }
    else
    {
        std::cout << "file not found \n";
    }
}

int main()
{
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    auto t1 = high_resolution_clock::now();
    sort();
    auto t2 = high_resolution_clock::now();

    /* Getting number of milliseconds as an integer. */
    auto ms_int = duration_cast<milliseconds>(t2 - t1);

    /* Getting number of milliseconds as a double. */
    duration<double, std::milli> ms_double = t2 - t1;

    std::cout << ms_int.count() << "ms\n";
    std::cout << ms_double.count() << "ms";
    return 0;
}
