using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.Algorithm.Sort
{
    public class QuickSortCls
    {
        public static void testSort()
        {
            SortNum num = new SortNum();
            QuickSort(num, 0, 8);

            foreach (int elem in num.arrData)
            {
                Console.Write("{0} ", elem);
            }
            Console.Write("\n");
        }

        static void QuickSort(SortNum arr, int low, int high)
        {
            if (low < high)
            {
                int pos = 0;
                pos = FindPos(arr, low, high);
                QuickSort(arr, low, pos - 1);
                QuickSort(arr, pos + 1, high);
            }
        }

        static int FindPos(SortNum arr, int low, int high)
        {
            int val = arr.arrData[low];
            while (low < high)
            {
                while (low < high && arr.arrData[high] > val)
                    --high;
                arr.arrData[low] = arr.arrData[high];
                while (low < high && arr.arrData[low] < val)
                    ++low;
                arr.arrData[high] = arr.arrData[low];
            }
            arr.arrData[low] = val;
            return low;
        }
    }

    public class SortNum
    {
        public int[] arrData = new int[] { 6, 1, 5, 3, 7, 9, 2, 4, 8 };
    }
}
