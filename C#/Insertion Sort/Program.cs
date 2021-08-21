using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Diagnostics;

namespace InsertionSort
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] sortArray = new int[5000];

            populateArray(sortArray);
            insertionSort(sortArray);

            Console.ReadLine();
        }

        static void insertionSort(int[] sortArray)
        {
            int temp;

            Stopwatch stopWatch = new Stopwatch();
            stopWatch.Start();

            for (int i = 1; i < 5000; i++)
            {
                while (sortArray[i] < sortArray[i - 1])
                {
                    temp = sortArray[i];
                    sortArray[i] = sortArray[i - 1];
                    sortArray[i - 1] = temp;
                    if (i != 1)
                    {
                        i -= 1;
                    }
                    else
                        continue;
                }
            }

            stopWatch.Stop();
            TimeSpan ts = stopWatch.Elapsed;
            Console.WriteLine("Time taken to sort: " + ts.Milliseconds / 10 + "ms");

        }

        static void populateArray(int[] sortArray)
        {
            StreamReader sr = new StreamReader("Arrayfile.txt");
            for (int i = 0; i < 5000; i++)
            {
                sortArray[i] = int.Parse(sr.ReadLine());
            }
            sr.Close();
        }
    }
}
