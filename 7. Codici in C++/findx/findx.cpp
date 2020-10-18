#include <iostream>

using namespace std;

int Find_X(int* A, int x, int sinistra, int destra){
	
	if(sinistra < destra){
		int centro = (sinistra + destra) / 2;
		int sx = Find_X(A, x, sinistra, centro);
		int dx = Find_X(A, x, centro+1, destra);

		if(sx != -1) return sx;
		if(dx != -1) return dx;

	}

	if(sinistra == destra){
		if(A[sinistra] == x) return sinistra;
	}

	return -1;
}

int main(){

	int A[10] = {1,4,6,0,19,57,48,19,35,57};

	cout << Find_X(A, 0, 0, 9) << endl;

}
