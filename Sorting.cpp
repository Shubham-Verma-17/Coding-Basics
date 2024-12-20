#include <bits/stdc++.h>
using namespace std;

// ALL sorting algorithms in one code

// T:O(N^2) S:O(1)
void bubbleSort(vector<int>&arr){
    int n=arr.size();


    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }
}


// T:O(N^2) S:O(1)
void selectionSort(vector<int>&arr){
    int n=arr.size();


    for(int i=0;i<n-1;i++){
        int mn=arr[i];
        int position=i;


        for(int j=i+1;j<n;j++){
            if(arr[j]<mn){
                mn=arr[j];
                position=j;
            }
        }
        swap(arr[i],arr[position]);
    }
}


// T:O(N^2) S:O(1)
void insertionSort(vector<int>&arr){
    int n=arr.size();


    for(int i=1;i<n;i++){
        int num=arr[i];
        int j;
        for(j=i-1;j>=0 && num<arr[j];j--){
            arr[j+1]=arr[j];
        }
        arr[j+1]=num;
    }
}




void merge(vector<int>&arr,int s,int e){
    int total=e-s+1;
    int temp[total];
    int mid=s+(e-s)/2;
    int i=s,j=mid+1,k=0;


    while(i<=mid && j<=e){
        if(arr[i]<=arr[j]) temp[k++]=arr[i++];
        else temp[k++]=arr[j++];
    }
    while(i<=mid) temp[k++]=arr[i++];
    while(j<=e) temp[k++]=arr[j++];


    k=0;
    for(i=s;i<=e;i++){
        arr[i]=temp[k++];
    }
}


// T:O(N*logN) S:O(N)
void mergeSort(vector<int>&arr,int s,int e){
    if(s>=e) return ;


    int mid=s+(e-s)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,e);
}


// T:O(N^2) S:O(logN) avg. T:O(N*logN)
void quickSort(vector<int>&arr,int s, int e){
    if(s>=e) return;


    int pivot=e;
    int j=e-1;
    for(int i=e-1;i>=0;i--){
        if(arr[i]>arr[pivot]){
            swap(arr[i],arr[j--]);
        }
    }
    swap(arr[j+1],arr[pivot]);


    quickSort(arr,s,j);
    quickSort(arr,j+2,e);
}


// T:O(N^2) S:O(logN) avg. T:O(N*logN) with less worst cases
void quickSortRand(vector<int>&arr,int s, int e){
    if(s>=e) return;


    int random=s+rand()%(e-s+1);
    swap(arr[random],arr[e]);
    int pivot=e;
   
    int j=e-1;
    for(int i=e-1;i>=0;i--){
        if(arr[i]>arr[pivot]){
            swap(arr[i],arr[j--]);
        }
    }
    swap(arr[j+1],arr[pivot]);


    quickSortRand(arr,s,j);
    quickSortRand(arr,j+2,e);
}


void heapify(vector<int>&arr,int i, int n){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;


    if(left<n && arr[left]>arr[largest]) largest=left;
    if(right<n && arr[right]>arr[largest]) largest=right;


    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,largest,n);
    }
}


// T:O(N*logN) S:O(logN)
void heapSort(vector<int>&arr, int n){
    //build heap max
    for(int i=(n/2)-1;i>=0;i--){
        heapify(arr,i,n);
    }


    //sort
    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,0,i);
    }
}


int main(){
    int n;
    cin>>n;


    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];


    //bubbleSort(arr);
    //selectionSort(arr);
    //insertionSort(arr);
    //mergeSort(arr,0,n-1);
    //quickSort(arr,0,n-1);
    //srand(time(NULL));
    //quickSortRand(arr,0,n-1);
    //heapSort(arr,n);


    for(int i=0;i<n;i++) cout<<arr[i]<<" ";


    return 0;
}
