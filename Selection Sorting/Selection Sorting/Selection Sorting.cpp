#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

int sortingArray[5000];
int output[2];

void sort()
{
    std::ifstream file("Arrayfile.txt");
    if (file.is_open())
    {
        int h = 1;
        int tempArray[1];
        for (int p = 0; p < 5000; ++p)
        {
            file >> sortingArray[p];
        }
        for (int i = 0; i < 5000; i++)
        {
            for (int ii = 0; ii < 5000; ii++)
            {
                if (sortingArray[i] < sortingArray[ii])
                {
                    tempArray[0] = sortingArray[i];
                    sortingArray[i] = sortingArray[ii];
                    sortingArray[ii] = tempArray[0];
                }
            }
            h++;
            output[0] = h;
        }
    }
    else
    {
        std::cout << "file not found \n";
    }
}

int main()
{
    int showoutput;
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    auto t1 = high_resolution_clock::now();
    sort();
    auto t2 = high_resolution_clock::now();

    //Getting number of milliseconds as an integer
    auto ms_int = duration_cast<milliseconds>(t2 - t1);
    //Getting number of milliseconds as a double
    duration<double, std::milli> ms_double = t2 - t1;

    std::cout << "\n";
    std::cout << "Array has been sorted in " << output[0] << " passes in " << ms_double.count() << "ms\n";
    //std::cout << ms_double.count() << "ms";
    std::cout << "\n";
    std::cout << "Selection Sorting";
    std::cout << "Would you like to show output\n";
    std::cout << "[1] Yes                [2] No\n";
    std::cin >> showoutput;

    if (showoutput == 1)
    {
        //Output sorted Array
        for (int k = 0; k < 5000; k++)
        {
            std::cout << sortingArray[k] << "\n";
        }
    }
    return 0;
}