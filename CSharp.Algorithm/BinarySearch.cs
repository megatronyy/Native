using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.Algorithm
{
    public class BinarySearch
    {
        public static int Rank(int key, int[] a)
        {
            //数组必须是有序的
            int low = 0;
            int high = a.Length - 1;

            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (a[mid] < key)
                    high = mid - 1;
                else if (a[mid] > key)
                    low = mid + 1;
                else
                    return mid;
            }

            return -1;
        }
    }
}
