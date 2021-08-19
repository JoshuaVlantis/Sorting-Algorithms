#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::ifstream file("Arrayfile.txt");
    if (file.is_open())
    {
        int sortingArray[10000];
        int tempArray[2];
        for (int p = 0; p < 10000; ++p)
        {
            file >> sortingArray[p];
        }
        for (int i = 0; i < 10000; i++)
        {
            for (int ii = 0; ii < 10000; ii++)
            {
                if (sortingArray[i] < sortingArray[ii])
                {
                    tempArray[0] = sortingArray[i];
                    sortingArray[i] = sortingArray[ii];
                    sortingArray[ii] = tempArray[0];
                }
            }
        }
        for (int k = 0; k < 10000; k++)
        {
            std::cout << sortingArray[k] << "\n";
        }

    }
    else
    {
        std::cout << "file not found \n";
    }
}