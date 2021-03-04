#include<iostream>
using namespace std;

class Heap
{
    public:
        int *arr;
        int max;
        int size;
    Heap()
    {
        max=20;
        arr=new int[max];
        size=0;
    }
    int leftchild(int index)
    {
        return (2*index+1);
    }
    int rightchild(int index)
    {
        return (2*index+2);
    }
    int parent(int index)
    {
        return (index-1)/2;
    }

    void insert(int val)
    {
        if (size==max)
        return;
        else
        {
            arr[size]=val;
            size++;
            int s = size-1;
            while (s!=0 && arr[parent(s)]>arr[s])
            {
                swap(parent(s),s);
                s=parent(s);
            }
        }
    }
    void swap(int i1,int i2)
    {
        int temp=arr[i1];
        arr[i1]=arr[i2];
        arr[i2]=temp;
    }
    void Heapify(int *ar,int s,int s1)
    {
        int l = leftchild(s),largest;
        int r = rightchild(s);
        if (l<s1 && ar[l]<ar[s])
        largest=l;
        else largest=s;
        if (r<s1 && ar[r]<ar[largest])
        largest=r;
        if (largest!=s)
        {
            swap(largest,s);
            Heapify(ar,largest,s1);
        }
    }
    // void extract_max(int *arr, int size) {
	// if (size != 0) {
	// 	int ans = arr[0];
    //     int y=size-1;
	// 	arr[0] = arr[y];
	// 	size--;
	// 	Heapify(arr, 0);
	// }
	// else {
	// 	cout << "Underflow\n";
	// }
    // }

    void heapsort(int *ar,int s)
    {
        if (s!=0)
        {
            swap(0,s-1);
            s--;
            Heapify(ar, 0,s);
            heapsort(ar,s);
        }
    }
    void print()
    {
        for (int i=0;i<size;i++)
        cout<<arr[i]<<'\t';
    }
};


int main()
{
    int arr[]={12,23,43,45,6,51,4};
    Heap h;
    for(int i=0;i<7;i++)
    {
        h.insert(arr[i]);
    }
    h.print();
    //h.extract_max(h.arr,h.size);
    cout<<endl;
    h.heapsort(h.arr,h.size);
    h.print();
}