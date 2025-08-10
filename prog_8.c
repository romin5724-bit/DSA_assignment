
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long comps=0, swaps=0;

void print_arr(int a[], int n){
    for(int i=0;i<n;i++) printf("%d ", a[i]);
    printf("\n");
}


void bubble_sort(int a[], int n){
    comps=swaps=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            comps++;
            if(a[j]>a[j+1]){ swaps++; int t=a[j]; a[j]=a[j+1]; a[j+1]=t; }
        }
    }
}


void selection_sort(int a[], int n){
    comps=swaps=0;
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){ comps++; if(a[j]<a[min]) min=j; }
        if(min!=i){ swaps++; int t=a[i]; a[i]=a[min]; a[min]=t; }
    }
}


void insertion_sort(int a[], int n){
    comps=swaps=0;
    for(int i=1;i<n;i++){
        int key=a[i], j=i-1;
        while(j>=0){ comps++; if(a[j]>key){ a[j+1]=a[j]; swaps++; j--; } else break; }
        a[j+1]=key;
    }
}


void merge(int a[], int l, int m, int r){
    int n1=m-l+1, n2=r-m;
    int L[n1], R[n2];
    for(int i=0;i<n1;i++) L[i]=a[l+i];
    for(int j=0;j<n2;j++) R[j]=a[m+1+j];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        comps++;
        if(L[i]<=R[j]){ a[k++]=L[i++]; }
        else { a[k++]=R[j++]; }
    }
    while(i<n1) a[k++]=L[i++];
    while(j<n2) a[k++]=R[j++];
}

void merge_sort_rec(int a[], int l, int r){
    if(l<r){
        int m = l + (r-l)/2;
        merge_sort_rec(a,l,m);
        merge_sort_rec(a,m+1,r);
        merge(a,l,m,r);
    }
}

void merge_sort(int a[], int n){
    comps=swaps=0;
    merge_sort_rec(a,0,n-1);
}

int main(){
    srand(time(NULL));
    int N;
    printf("Enter N (number of random integers): ");
    if(scanf("%d",&N)!=1||N<=0) return 0;
    int *arr = malloc(sizeof(int)*N);
    for(int i=0;i<N;i++) arr[i] = rand()%1000 + 1;
    printf("Original array:\n");
    print_arr(arr,N);

    printf("Choose sorting algorithm:\n1. Bubble\n2. Selection\n3. Insertion\n4. Merge\nEnter choice: ");
    int choice; scanf("%d",&choice);
    int *b = malloc(sizeof(int)*N);
    for(int i=0;i<N;i++) b[i]=arr[i];

    switch(choice){
        case 1: bubble_sort(b,N); break;
        case 2: selection_sort(b,N); break;
        case 3: insertion_sort(b,N); break;
        case 4: merge_sort(b,N); break;
        default: printf("Invalid choice\n"); free(arr); free(b); return 0;
    }

    printf("Sorted array:\n"); print_arr(b,N);
    printf("Comparisons: %lld\nSwaps: %lld\n", comps, swaps);
    free(arr); free(b);
    return 0;
}