#include <iostream>
#include <ctime>

using namespace std;

void Merge (int *a, int sx, int cx, int dx){

    int i = sx;
    int j = cx + 1;
    int k = 0;

    int b[sx + dx];

    while((i <= cx) && (j <= dx)){
        if(a[i] <= a[j]){
            b[k] = a[i];
            i = i + 1;
        }

        else{
            b[k] = a[j];
            j = j + 1;
        }

        k = k + 1;
    }

    for(; i <= cx; i = i + 1 , k = k + 1){
        b[k] = a[i];
    }

    for(; j <= dx; j = j + 1 , k = k + 1){
        b[k] = a[j];
    }

    for(i = sx; i <= dx; i = i + 1){
        a[i] = b[i-sx];
    }
}

void MergeSort(int a[], int sx, int dx){
    if(sx < dx){
        int cx = (sx + dx) / 2;
        MergeSort(a, sx, cx);
        MergeSort(a, cx + 1, dx);
        Merge(a, sx, cx, dx);
    }
}

int ricercaBinaria(int *a, int n, int sx, int dx) {
    if(sx > dx) {
        return -1;
    }

    int cx = (sx+dx) / 2;
    if(n == a[cx]) {
        return cx;
    }

    if(sx == dx) {
        return -1;
    }

    if(n < a[cx]) {
        return ricercaBinaria(a, n, sx, cx - 1);
    } 
    else {
        return ricercaBinaria(a, n, cx + 1, dx);
    }
    

}


int main(){

    int *arr = (int *) calloc(50, sizeof(int));
    int res = 0;

    srand(time(NULL));

    for (size_t i = 0; i < 50; i = i + 1) {

        arr[i] = rand() % 50 + 1;

    }
    
    MergeSort(arr, 0, 49);

    for (size_t i = 0; i < 50; i++)
    {
        cout << "[" << i + 1 << "]    " << arr[i] << endl;
    }

    res = ricercaBinaria(arr, 25, 0, 49);

    if (res <= 0) {
        cout << "Elemento non trovato..." << endl;
    }

    else {
        cout << "Elemento trovato in posizione: " << res << endl;
    }
    
    
    

}