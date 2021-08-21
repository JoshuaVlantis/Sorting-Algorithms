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

            Stopwatch stopWatch = new Stopwatch();
            stopWatch.Start();
            
            insertionSort(sortArray);
            
            stopWatch.Stop();
            TimeSpan ts = stopWatch.Elapsed;
            Console.WriteLine("Time taken to sort: " + ts.Milliseconds + "ms");

            Console.ReadLine();
        }

        static void insertionSort(int[] sortArray)
        {
            int tempArray;
            for (int i = 0; i < 5000; i++)
            {
                for (int ii = i + 1; ii < 5000; ii++)
                {
                    if (sortArray[ii] < sortArray[i])
                    {
                        tempArray = sortArray[i];
                        sortArray[i] = sortArray[ii];
                        sortArray[ii] = tempArray;
                    }
                }
            }
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
