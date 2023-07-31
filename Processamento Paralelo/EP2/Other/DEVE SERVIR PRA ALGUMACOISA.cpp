
    if (rank == 0) {
        for(i = 1; i < np ; i++){
            MPI_Send(&ind, 1, MPI_LONG_DOUBLE, i, 1, MPI_COMM_WORLD);
            MPI_Recv(&ind, 1, MPI_LONG_DOUBLE, i, 1, MPI_COMM_WORLD, &status);
            
            MPI_Recv(&procSum, 1, MPI_LONG_DOUBLE, i, 0, MPI_COMM_WORLD, &status);
            localSum += procSum;
        }
    } else {

        for (i = 0; i < np; i++){
            int ini, fim;
            long long int localInd;
            MPI_Recv(&localInd, 1, MPI_LONG_DOUBLE, i, 1, MPI_COMM_WORLD, &status);
            if (i == np - 1){
                ini = localInd;
                fim = num_steps;
            } else {
                ini = localInd;
                fim = localInd + num_steps / np;
                localInd += num_steps / np;
                MPI_Send(&localInd, 1, MPI_LONG_DOUBLE, 0, 1, MPI_COMM_WORLD);
            }
            // cout << "INI = " << ini << ", FIM = " << fim << endl;
            localSum = calcSum(rank, ini, fim, np);       
            // cout << localSum << endl;            
            MPI_Send(&localSum, 1, MPI_LONG_DOUBLE, 0, 0, MPI_COMM_WORLD);
        }
    }