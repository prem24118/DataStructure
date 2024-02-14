// MPC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Define the state vector struct
struct State {
    double x;
    double y;
    double vx;
    double vy;
};

// Define the control input struct
struct Control {
    double ax;
    double ay;
};

// Define the output vector struct
struct Output {
    double x;
    double y;
};

// Define the MPC controller class
class MPCController
{
public:
    // Constructor
    MPCController(double dt, double N, double Q, double R) {
        dt_ = dt;
        N_ = N;
        Q_ = Q;
        R_ = R;
    }

    // Update function
    Control update(State x, Output y_ref) {
        // Initialize the control input
        Control u = { 0, 0 };

        // Define the state transition matrix
        vector<vector<double>> A = { {1, 0, dt_, 0},
                                    {0, 1, 0, dt_},
                                    {0, 0, 1, 0},
                                    {0, 0, 0, 1} };

        // Define the control input matrix
        vector<vector<double>> B = { {0, 0},
                                    {0, 0},
                                    {dt_, 0},
                                    {0, dt_} };

        // Define the output matrix
        vector<vector<double>> C = { {1, 0, 0, 0},
                                    {0, 1, 0, 0} };

        // Define the reference output
        vector<double> y_ref_vec = { y_ref.x, y_ref.y };

        // Define the output weighting matrix
        vector<vector<double>> Q = { {Q_, 0, 0, 0},
                                    {0, Q_, 0, 0},
                                    {0, 0, 0, 0},
                                    {0, 0, 0, 0} };

        // Define the control input weighting matrix
        vector<vector<double>> R = { {R_, 0},
                                    {0, R_} };

        // Define the state vector
        vector<double> x_vec = { x.x, x.y, x.vx, x.vy };

        // Initialize the cost function
        double J = 0;

        // Calculate the control input using MPC
        for (int i = 0; i < N_; i++) {
            // Calculate the output error
            vector<double> y_err = { y_ref_vec[0] - x_vec[0], y_ref_vec[1] - x_vec[1] };

            // Calculate the cost
            J += dot(y_err, matmul(Q, y_err)) + dot(u, matmul(R, u));

            // Calculate the optimal control input
            vector<double> u_opt = matmul(matmul(inv(matmul(transpose(B), matmul(inv(matmul(B, matmul(P, transpose(B))) + R)), B)), transpose(B)), matmul(inv(matmul(transpose(C), matmul(inv(matmul(C, matmul(P, transpose(C))) + Q)), C)), y_err));

            // Update the control input
            u.ax = u_opt[0];
            u.ay = u_opt[1];

            // Update the state vector
            x_vec = matmul(A, x_vec) + matmul(B, u_opt);
        }

        return u;
    }

private:
    double dt_;
    double N_;
    double Q_;
    double R_;

    // Helper functions
    double dot
}
int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
