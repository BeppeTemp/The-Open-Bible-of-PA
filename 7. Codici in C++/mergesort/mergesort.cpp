#include <iostream>

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

int main() {

    std::cout << "Merge Sort" << std::endl;

    int *number;
    number = (int*) calloc(50, sizeof(int));

    for(int i = 0; i < 50; i = i + 1){
        number[i] = rand()%99+1;
    }

    MergeSort(number, 0, 50);

    for(int i = 0; i < 50; i = i + 1){
        std::cout << number[i] << std::endl;
    }

  

  

}