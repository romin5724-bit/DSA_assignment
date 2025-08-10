
#include <stdio.h>

void swap(int *a,int *b){ int t=*a; *a=*b; *b=t; }

void heapify_max(int arr[], int n, int i){
    int largest = i; int l = 2*i+1, r = 2*i+2;
    if(l<n && arr[l]>arr[largest]) largest=l;
    if(r<n && arr[r]>arr[largest]) largest=r;
    if(largest!=i){ swap(&arr[i], &arr[largest]); heapify_max(arr,n,largest); }
}

void heapify_min(int arr[], int n, int i){
    int smallest = i; int l = 2*i+1, r = 2*i+2;
    if(l<n && arr[l]<arr[smallest]) smallest=l;
    if(r<n && arr[r]<arr[smallest]) smallest=r;
    if(smallest!=i){ swap(&arr[i], &arr[smallest]); heapify_min(arr,n,smallest); }
}

void build_max_heap(int arr[], int n){
    for(int i=n/2 -1; i>=0; i--) heapify_max(arr,n,i);
}

void build_min_heap(int arr[], int n){
    for(int i=n/2 -1; i>=0; i--) heapify_min(arr,n,i);
}

void print_arr(int arr[], int n){
    for(int i=0;i<n;i++) printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int a[] = {7,3,5,1,9,2,8};
    int n = sizeof(a)/sizeof(a[0]);
    int b[10];
    memcpy(b,a,sizeof(a));
    printf("Original array: ");
    print_arr(a,n);
    build_max_heap(a,n);
    printf("Max-heap array: ");
    print_arr(a,n);
    build_min_heap(b,n);
    printf("Min-heap array: ");
    print_arr(b,n);
    return 0;
}