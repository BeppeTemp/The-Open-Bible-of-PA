//
// Created by Lorenzo Paolo Cocchinone on 07/10/2020.
//

#include <iostream>
#include <ctime>

#define N 5

using namespace std;

void QuickSort(int *a, int sx, int dx);
int Distribuzione(int *a, int sx, int px, int dx);
void Scambia(int *a, int i, int j);

void QuickSort(int *a, int sx, int dx){
    if(sx < dx){
        int px = sx + rand()%(dx-sx+1) ;
        int indiceFinalePivot = Distribuzione(a, sx, px, dx);
        QuickSort(a, sx, indiceFinalePivot-1);
        QuickSort(a, indiceFinalePivot+1, dx);

    }
}

int Distribuzione(int *a, int sx, int px, int dx){

    if(a[px] != a[dx]) Scambia(a, px, dx);


    int i = sx;
    int j = dx - 1;

    while(i <= j){

        while((i <= j) && (a[i] <= a[dx])) i = i + 1;
        while((i <= j) && (a[j] >= a[dx])) j = j - 1;

        if(i < j){
            Scambia(a, i, j);

            i = i + 1;
            j = j - 1;

        }
    }
    if (i != dx) Scambia(a, i, dx);
    return i;
}

void Scambia(int *a, int i, int j){
    int temp = a[j];
    a[j] =a[i];
    a[i] = temp;
}

int main(){
    cout << "Quick Sort" << endl;
    srand(time(NULL));

    int *number;
    number = (int*) calloc(N, sizeof(int));

    cout << "Array random non ordinato: " << endl;
    for(int i = 0; i < N; i = i + 1){
        number[i] = rand()%(N*10)+1;
    }

    for(int i = 0; i < N; i = i + 1){
        cout << number[i] << endl;
    }
    QuickSort(number, 0, N-1);

    cout << "\n\nArray Random ordinato: " << endl;
    for(int i = 0; i < N; i = i + 1){
        cout << number[i] << endl;
    }

}

