#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::ifstream file("Arrayfile.txt");
    if (file.is_open())
    {
        int sortingArray[10];
        int tempArray[2];
        for (int p = 0; p < 10; ++p)
        {
            file >> sortingArray[p];
        }
        for (int i = 0; i < 10; i++)
        {
            for (int ii = 0; ii < 10; ii++)
            {
                if (sortingArray[i] < sortingArray[ii])
                {
                    tempArray[0] = sortingArray[i];
                    tempArray[1] = sortingArray[ii];
                    sortingArray[i] = tempArray[1];
                    sortingArray[ii] = tempArray[0];
                }
            }
        }
        for (int k = 0; k < 10; k++)
        {
            std::cout << sortingArray[k] << "\n";
        }

    }
    else
    {
        std::cout << "file not found \n";
    }
}
