#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <assert.h>

int output[2];
int j;
int sortingArray[255999996];

void sort()
{
    using namespace std::chrono_literals;
     
    int h = 1;
    int tempArray[1];
    bool loopagain = false;

    for (int i = 0; i < h; i++)
    {
        for (int ii = 0; ii < j-1; ii++)
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
    output[0] = h;
}

int main()
{
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    std::ifstream file("Arrayfile.txt");

    if (file.is_open())
    {
        int x = 0;
        int showoutput;
        while (true)                //Gets file size and returns to to x
        {
            file >> x;
            j++;
            if (file.eof()) break;
        }
        
        file.seekg(0);              //Retruns to top of file
        for (x = 0; x < j; ++x)
        {
            file >> sortingArray[x];
        }
        file.close();
       
        auto t1 = high_resolution_clock::now();
        sort();
        auto t2 = high_resolution_clock::now();

        //Getting number of milliseconds as an integer
        auto ms_int = duration_cast<milliseconds>(t2 - t1);
        //Getting number of milliseconds as a double
        duration<double, std::milli> ms_double = t2 - t1;

        std::cout << "Bubble Sort\n";
        std::cout << "\n";
        std::cout << "Array has been sorted in " << output[0] << " passes in " << ms_double.count() << "ms\n";
        //std::cout << ms_double.count() << "ms";
        std::cout << "\n";
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
    }
    else
    {
        std::cout << "file not found \n";
    }
    return 0;
}