// CSC382
// Project 4 & 5 - comparing insertion Sort, merge Sort, & Heap Sort

#include <iostream>
#include<cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

void insertionSort (int A[], int n);
void mergesort (int A[],int low, int high, int B[]);
void merge (int A[], int low, int mid, int high, int B[]);
void heapsort (int A[], int n);
void fixheap (int A[], int root, int key, int bound);

int main()
{
    cout<<"Input size"<<"\t"<<"Insertion Sort";
    cout<<"\t\t"<<"Merge Sort";
    cout<<"\t\t"<<"Heap Sort"<<endl;
    
    srand((unsigned)time(0));
    int bound = 100000000;
    int n=10;
    //Creating temp arrays for each sprt
    int *test = new int [n];
    int *test_1 = new int [n];
    int *test_2 = new int [n];
    clock_t time1, end;
    double insertionS, merg, heap;
    
    for (int i=0; i<=5; i++)
    {
        switch (i)
        {
            case 0:
                n=100;
                break;
            case 1:
                n=1000;
                break;
            case 2:
                n=10000;
                break;
            case 3:
                n=50000;
                break;
            case 4:
                n=100000;
                break;
            case 5:
                n=200000;
                break;
            default:
                break;
        }
        int *test = new int [n];
        int *test_1 = new int [n];
        int *test_2 = new int [n];
        for (int k=0; k<n; k++)
        {
            test [k] = ( rand() % (bound + 1) ) ;		//generates random number
            test_1 [k] = test [k];
            test_2 [k] = test [k];
        }
        
        time1=clock();
        insertionSort (test,n);
        insertionS = (clock()-time1)/ (double) CLOCKS_PER_SEC;
        end=clock();
        
        time1=clock();
        int *B=new int [n];
        mergesort (test_1, 0, n-1, B);
        delete [] B;
        B= NULL;
        merg = (clock()-time1)/ (double) CLOCKS_PER_SEC;
        end=clock();
        
        time1 = clock();
        heapsort (test_2,n);
        heap = (clock()-time1)/ (double) CLOCKS_PER_SEC;
        end = clock();
        
        cout << n << "      " << insertionS << "            ";
        cout << merg << "           " << heap <<endl;
    }
    delete [] test;
    test = NULL;
    delete [] test_1;
    test_1 = NULL;
    delete [] test_2;
    test_2 = NULL;
    return 0;
}

void insertionSort (int A[], int n)
{
    int i,j, temp;
    for (i=1; i<n; i++)
    {
        j=i;
        while ( A[j] < A[j-1])
        {
            temp=A[j];
            A[j]=A[j-1];
            A[j-1]=temp;
            j--;
        }
    }
}

void merge (int A[], int low, int mid, int high, int B[])
{
    int l=low, i=low, h=mid+1, k;
    
    while ((l <=mid) && (h <=high))
    {
        if (A[l] <=A[h])
        {
            B[i]=A[l];
            l++;
        }
        
        else
        {
            B[i]=A[h];
            h++;
        }
        i++;
    }
    
    if (l > mid)
        for (k=h; k <=high; k++)
        {
            B[i]=A[k];
            i++;
        }
    
    else
        for (k=l; k <= mid; k++)
        {
            B[i]=A[k];
            i++;
        }
    
    
    for (k=low; k <=high; k++)
    {
        A[k]=B[k];
    }
}

void mergesort (int A[ ], int low, int high, int B[])
{
    if (low < high)
    {
        int mid=(low + high)/2;
        mergesort (A,low, mid, B);
        mergesort (A, mid+1, high, B);
        merge (A,low, mid, high, B);
    }
}

void fixheap (int A[ ], int root, int key, int bound) 

{ 
    int vacant, bigChild;
    bool inserted = false;  
    vacant = root; 
    while ( (2*vacant <= bound) && (!inserted) )
    { 
        bigChild = 2 * vacant;
        if ( (bigChild < bound) && A[bigChild +1] > A[bigChild])
            bigChild++;
        if ( key < A[bigChild] )
        { A[vacant] = A[bigChild];
            vacant = bigChild;
        }
        else 
            inserted=true;
    } 
    A[vacant] = key;
}

void heapsort (int A[ ], int n)
{
    int i, heapsize, max;
    
    for (i=n/2; i>=1; i--) 
        fixheap(A, i, A[i], n);
    for (heapsize = n; heapsize >= 2; heapsize --)
    {  
        max = A[1];						
        fixheap (A, 1, A[heapsize], heapsize-1);
        A[heapsize]=max;
    }
}


