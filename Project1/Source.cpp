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


		for (int i = 0; i < n; i++){

			task_table[i] = (rand() % t) + 1;

		}

		int trigger = 0;

		for (int i = 0; i < n; i++){

			/*if (i < size)*{*/
				MPI_Send(&task_table[i], 1, MPI_INT,i/*i+1*/, 0, MPI_COMM_WORLD);
			/*}
			else{

			}*/
		}
	}
	else{

		/*impelemntacja zmiennych pomocniczych*/
		int liczba = 0;
		int r = 0;
		int mianownik = 0;


		do
		{
		MPI_Recv(&liczba, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		if (liczba == 0){


		}
		else{
			if (liczba == 1){
				/*to do*/
				mianownik = 1;
			}
			else{



			}




		}

	





		} while (liczba == 0);
	}




	
	MPI_Finalize();
	return 0;

}
