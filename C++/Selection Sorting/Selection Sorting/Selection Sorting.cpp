#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

int output[1];
int j;
int sortingArray[10000];

void sort()
{
    int h = 1;
    int tempArray[1];

    for (int i = 0; i < j; i++)
    {
        for (int ii = 0; ii < j; ii++)
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

        std::cout << "Selection Sorting\n";
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
            for (int k = 0; k < j; k++)
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