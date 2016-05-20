using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.Algorithm.Sort
{
    public class BubbleSort
    {
        public static void TestMothed()
        {
            int[] arr = new int[6] { 5, 3, 1, 4, 6, 2 };

            Sort(arr);
        }
        static void Sort(int[] arr)
        {
            int len = arr.Length;
            int i, j, t;
            for (i = 0; i < len - 1; ++i)
            {
                for (j = 0; j < len - 1 - i; ++j)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        t = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = t;
                    }
                }
            }

            for (i = 0; i < len; i++)
            {
                Console.WriteLine(arr[i]);
            }
        }
    }
}
