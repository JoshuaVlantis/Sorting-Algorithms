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
        int h = 1;
        bool loopagain = false;

        for (int p = 0; p < 10; ++p)
        {
            file >> sortingArray[p];
        }

        for (int i = 0; i < h; i++)
        {

            for (int ii = 0; ii < 9; ii++)
            {
                if (sortingArray[ii] > sortingArray[ii + 1])
                {
                    tempArray[0] = sortingArray[ii];
                    tempArray[1] = sortingArray[ii + 1];
                    sortingArray[ii] = tempArray[1];
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
        for (int k = 0; k < 10; k++)
        {
            std::cout << sortingArray[k] << "\n";
        }
        std::cout << "\n";
        std::cout << "Array was sorted in " << h << " passes\n";
    }
    else
    {
        std::cout << "file not found \n";
    }

}
