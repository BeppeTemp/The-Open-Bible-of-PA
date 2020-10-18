#include <iostream>
#include <ctime>
#define N 10
#define R 2

using namespace std;

int QuickSelect(int *a, int sx, int rango, int dx);
int Distribuzione(int *a, int sx, int px, int dx);
void Scambia(int *a, int i, int j);


int QuickSelect(int *a, int sx, int rango, int dx){
    if(sx == dx) return a[sx];
    else{
        int px = sx + rand()%(dx-sx+1);
        int indiceFinalePivot = Distribuzione(a, sx, px, dx);

        if(rango - 1  == indiceFinalePivot) return a[indiceFinalePivot];
        else{
            if(rango-1 < indiceFinalePivot) return QuickSelect(a, sx, rango, indiceFinalePivot - 1);
            else return QuickSelect(a, indiceFinalePivot + 1, rango, dx);

        }
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

int main() {
    cout << "Quick Select" << endl;
    srand(time(NULL));

    int *number;
    number = (int*) calloc(N, sizeof(int));

    for(int i = 0; i < N; i = i + 1){
        number[i] = rand()%(N*10)+1;
    }

    cout << "\nArray Random: " << endl;
    for(int i = 0; i < N; i = i + 1){
        cout << number[i] << " | ";
    }

    int n = QuickSelect(number, 0, R, N-1);
    cout << "\nElemento di rango " << R << ": " << n << endl;


}
