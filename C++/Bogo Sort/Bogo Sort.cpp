#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

long long unsigned int pass;

bool checksorted(int sortingArray[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int ii = i; ii < n; ii++)
        {
            if (sortingArray[i] > sortingArray[ii])
            {
                return false;
            }
        }
    }
    return true;
}

void randomize(int sortingArray[], int n, int tempArray)
{
    srand((unsigned int)time(NULL));
    int r;
    pass++;
    for (int i = 0; i < n; i++)
    {
        r = rand() % n;

        tempArray = sortingArray[i];
        sortingArray[i] = sortingArray[r];
        sortingArray[r] = tempArray;
    }
        
}
void sort(int sortingArray[], int n, int tempArray)
{
    while (!checksorted(sortingArray, n))
    {
        randomize(sortingArray, n, tempArray);
    }
} 

int main()
{
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    int n{};
    int tempArray{};
    int sortingArray[10000];
    pass = 0;

    std::ifstream file("Arrayfile.txt");

    if (file.is_open())
    {

        int x = 0;
        int showoutput;
        while (true)                //Gets file size and returns to to x
        {
            file >> x;
            n++;
            if (file.eof()) break;
        }

        file.seekg(0);              //Retruns to top of file
        for (x = 0; x < n; ++x)
        {
            file >> sortingArray[x];
        }
        file.close();
        auto t1 = high_resolution_clock::now();
        sort(sortingArray, n, tempArray);
        auto t2 = high_resolution_clock::now();

        //Getting number of milliseconds as an integer
        auto ms_int = duration_cast<milliseconds>(t2 - t1);
        //Getting number of milliseconds as a double
        duration<double, std::milli> ms_double = t2 - t1;

        std::cout << "Bogo Sort \n";
        std::cout << "\n";
        std::cout << "Array has been sorted in " << ms_double.count() << "ms\n" << pass;
        //std::cout << ms_double.count() << "ms";
        std::cout << "\n";
        std::cout << "Would you like to show output\n";
        std::cout << "[1] Yes                [2] No\n";
        std::cin >> showoutput;

        if (showoutput == 1)
        {
            //Output sorted Array
            for (int k = 0; k < n; k++)
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