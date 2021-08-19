#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::ifstream file("Arrayfile.txt");
    if (file.is_open())
    {
        int sortingArray[100];
        int tempArray[2];
        for (int p = 0; p < 100; ++p)
        {
            file >> sortingArray[p];
        }
        for (int i = 0; i < 100; i++)
        {
            for (int ii = 0; ii < 100; ii++)
            {
                if (sortingArray[i] < sortingArray[ii])
                {
                    tempArray[0] = sortingArray[i];
                    sortingArray[i] = sortingArray[ii];
                    sortingArray[ii] = tempArray[0];
                }
            }
        }
        for (int k = 0; k < 100; k++)
        {
            std::cout << sortingArray[k] << "\n";
        }

    }
    else
    {
        std::cout << "file not found \n";
    }
}