using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.Algorithm.Sort
{
    public abstract class SortBase<T> where T : IComparable
    {
        public abstract void Sort(T[] a);

        public bool Less(T v, T w)
        {
            return v.CompareTo(w) < 0;
        }

        public void Exch(T[] a, int i, int j)
        {
            T t = a[i];
            a[i] = a[j];
            a[j] = t;
        }

        public bool IsSort(T[] a)
        {
            for (int i = 1; i < a.Length; i++)
            {
                if(Less(a[i], a[i-1])) 
                    return false;
            }
            return true;
        }
    }
}
