#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

struct pointer { 
	   int d;
	   pointer *p;
};

void formirStek(pointer **ph, int data) {
	 *ph = new pointer;
	 (*ph) -> d = data;
	 (*ph) -> p = NULL;
}

void dobavStek(pointer **ph, int data) { 
	 pointer *px = new pointer;
	 px -> d = data;
	 px -> p = (*ph);
	 (*ph) = px;
}

int i = 1, j, data;

int main() {
	pointer *ph = NULL;
	cout<<"Vvedite " << i << " element --> ";
	cin >> data ;
	formirStek(&ph, data);
 	i++;

do {
	cout<<"Vvedite " << i << " element --> ";
	cin >> data;
	dobavStek(&ph, data);
	i++;
}
while (data != 0);
    ph -> d = 10000000;
	cout<<"\nVivod steka: \n\n";
	i = 0;
	int min = 1000000;
	pointer *pc = ph;
	while (ph != NULL) {
		data = ph -> d;
		ph = ph -> p;
		if (data < min) min = data;
	}
	
	////////
	ph = pc;
	ph -> d = 0;
	cout<<"MINIMALKA ----->   " << min << "\n" << endl;
   /////////
   
   while (ph != NULL) {
		i++;
		int k = 0;
		data = ph -> d;
		ph = ph -> p;
		if (data == min) dobavStek(&ph, k);
		cout << i << " - Element steca --> " << data << endl;
	}
}
