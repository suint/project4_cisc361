// from https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/

/* C++ program for estimation of Pi using Monte 
   Carlo Simulation */
#include <bits/stdc++.h>
#include <math.h>
#include <omp.h>
#include <cmath>
#include <openacc.h>
#include "openacc_curand.h"

// Defines precision for x and y values. More the 
// interval, more the number of significant digits 

using namespace std;

int main(int argc, char** argv)
{
    const long INTERVAL = atol(argv[1]);

    int i;
    double rand_x, rand_y, pi;
    long circle_points = 0;
    // unsigned int tmp;

    // Initializing rand()
    long long seed;
    long long id;
    long long offset;
    curandState_t state;
    

    // Total Random numbers generated = possible x
    // values * possible y values

    double st = omp_get_wtime();

    #pragma acc parallel private(state)
    {
        id = __pgi_gangidx();
        seed = 12345ULL+id*477;
        offset = 0;
        curand_init(seed, id, offset, &state);

        #pragma acc loop reduction(+: circle_points) private(rand_x, rand_y)
        for (i = 0; i < INTERVAL; i++) {

            // Randomly generated x and y values
            rand_x = curand_uniform_double(&state);
            rand_y = curand_uniform_double(&state);

            // Checking if (x, y) lies inside the define
            // circle with R=1
            if (rand_x * rand_x + rand_y * rand_y <= 1)
                circle_points++;
        }
    }
    // Final Estimated Value
    pi = 4*(double(circle_points) / double(INTERVAL));

    double runtime = omp_get_wtime() - st;
    cout << " Final Estimation of Pi = " << pi << endl;
    cout << " Error = " << abs(M_PI - pi) << endl;
    printf(" total: %f s\n", runtime);

    return 0;
}
