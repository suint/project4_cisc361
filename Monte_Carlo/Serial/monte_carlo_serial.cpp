// from https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/

/* C++ program for estimation of Pi using Monte 
   Carlo Simulation */
#include <bits/stdc++.h>
#include <math.h>
#include <omp.h>
#include <cmath>

// Defines precision for x and y values. More the 
// interval, more the number of significant digits 

using namespace std;

int main(int argc, char** argv)
{
    const long INTERVAL = atol(argv[1]);

    long i;
    double rand_x, rand_y, pi;
    long circle_points = 0;
    unsigned int tmp;

    // Initializing rand()
    srand(time(NULL));

    // Total Random numbers generated = possible x
    // values * possible y values

    double st = omp_get_wtime();

    for (i = 0; i < INTERVAL; i++) {

        // Randomly generated x and y values
        rand_x = double(rand_r(&tmp)) / RAND_MAX;
        rand_y = double(rand_r(&tmp)) / RAND_MAX;

        // Checking if (x, y) lies inside the define
        // circle with R=1
        if (rand_x * rand_x + rand_y * rand_y <= 1)
            circle_points++;
    }
    
    // Final Estimated Value
    pi = 4*(double(circle_points) / double(INTERVAL));

    double runtime = omp_get_wtime() - st;
    cout << " Final Estimation of Pi = " << pi << endl;
    cout << " Error = " << abs(M_PI - pi) << endl;
    printf(" total: %f s\n", runtime);

    return 0;
}
