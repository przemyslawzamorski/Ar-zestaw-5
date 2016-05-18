#include <stdio.h>          // printf
#include <mpi.h>
#include <stdlib.h>         
#include <time.h>  
#include <iostream>

using namespace std;

int main(int argc, char **argv) {

	MPI_Init(&argc, &argv);
	int rank, size;

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if (rank == 0){
		int n, t, s;
		cin >> n >> t >> s;
		
		int* task_table = new int[n];
		srand(s * time(NULL));

		//petla rozsylajaca wykonuje sie n+size  jezeli i>n to wysylaj zalozmy zero lub tag 0 i przy odbiorze jezeli bedze to cos to koncz odbieranie :)
		for (int i = 0; i < n ; i++){
				task_table[i] = (rand() % t) + 1;
		}

		int trigger = 0;
		int counter = 1;
		for (int i = 0; i < 2 * n; i++){

			if (i<n){
				trigger = task_table[i];
			}
			else{
				cout << endl;
				trigger = 0;
			}

			counter = counter%size;
			if (counter == size || counter ==0){
				counter = 1;
			}
			cout << counter;
			/*MPI_Send(&trigger, 1, MPI_INT, counter + 1, 1, MPI_COMM_WORLD);*/
			counter++;
			
			
			

		}

			/*if (i < size){
				MPI_Send(&task_table[i], 1, MPI_INT,i+1, 1, MPI_COMM_WORLD);
			}
			else{
				int licznik;
				int* cos=new int [size];
				/*zbieranie*/
				/*MPI_Recv(&licznik, 1, MPI_INT, MPI_ANY_TAG, MPI_ANY_SOURCE, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				cos[i - n] = licznik;



				MPI_Send(0, 1, MPI_INT, i + 1, 1, MPI_COMM_WORLD);
			}
		}*/
	}
	else{

		/*impelemntacja zmiennych pomocniczych*/
	/*	int liczba = 0;
	

		do
		{
		MPI_Recv(&liczba, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		int r = 0;
		int mianownik = 0;
		int silnia = 1;

		if (liczba == 0){
			r = 0;
			MPI_Send(&r, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);


		}
		else{
			if (liczba == 1){
				
				r = 1;
				MPI_Send(&r, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
				/*dodaæ mierzenie czasu*/
			/*}
			else{
				for (int i = liczba; i > 1; i--){
					silnia *= i;
					mianownik += i;
				}

				r = silnia / mianownik;
			}
			MPI_Send(&r, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
			/*dodaæ mierzenie czasu*/
		/*}

		} while (liczba == 0);*/
	}




	
	MPI_Finalize();
	return 0;

}
