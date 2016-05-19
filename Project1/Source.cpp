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
		MPI_Status status;
		cin >> n >> t >> s;

		int* task_table = new int[n];
		srand(s * time(NULL));

		//petla rozsylajaca wykonuje sie n+size  jezeli i>n to wysylaj zalozmy zero lub tag 0 i przy odbiorze jezeli bedze to cos to koncz odbieranie :)
		for (int i = 0; i < n; i++){
			task_table[i] = (rand() % t) + 1;
		}


		int counter = 1;
		for (int i = 0; i < n; i++){

			if (i < size - 1){
				MPI_Send(&task_table[i], 1, MPI_INT, i + 1, 1, MPI_COMM_WORLD);
				cout << i + 1 << " " << task_table[i] << endl;

			}
			else{
				/*cout << "0" << " " << endl;*/

				/*to do odbiór*/
				/*MPI_Send(&trigger, 1, MPI_INT, counter + 1, 1, MPI_COMM_WORLD);*/
			}
		}

		/*rozes³anie statusu konca nadawanie przez mastera*/
		for (int i = 1; i < size; i++){
			cout << " proces " << i << "koniec odbierania" << endl;

		}
		
	}
	else{

		/*impelemntacja zmiennych pomocniczych*/
		int liczba = 0;


		/*	do
			{*/

		MPI_Recv(&liczba, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

		double r = 0;
		double mianownik = 1;
		double silnia = 1;

		/*if (liczba == 0){
			r = 0;
			/*MPI_Send(&r, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);*/
		/*}
		else{*/
		if (liczba == 1){

			r = 1;
			MPI_Send(&r, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
			cout << "proces " << rank << " obliczyla " << r << endl;
			/*dodaæ mierzenie czasu*/
		}
		else{
			for (int i = liczba; i > 1; i--){
				silnia = silnia* i;
				mianownik = mianownik + i;
			}

			r = silnia / mianownik;
			cout << "proces " << rank << " silnia " << silnia << endl;
			cout << "proces " << rank << " mianownik " << mianownik << endl;
			cout << "proces " << rank << " wynik " << r << endl;
			/*}
			/*MPI_Send(&r, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);*/
			/*dodaæ mierzenie czasu*/
			/*}

			} while (liczba == 0);*/
		}





		

		//}
	}
	MPI_Finalize();
	return 0;
}