#include <iostream>

class PIDController {
public:
    PIDController(double kp, double ki, double kd, double dt)
        : kp(kp), ki(ki), kd(kd), dt(dt), integral(0.0), previousError(0.0) {}

    double calculateOutput(double error) {
        integral += error * dt;
        double derivative = (error - previousError) / dt;
        double output = kp * error + ki * integral + kd * derivative;
        previousError = error;
        return output;
    }

private:
    double kp;
    double ki;
    double kd;
    double dt;
    double integral;
    double previousError;
};

/*
*/

int main() {
    // PID parameters
    double kp = 0.1;
    double ki = 0.01;
    double kd = 0.05;
    double dt = 0.05;  // time step (seconds)

    // Vehicle dynamics parameters
    double vehicleMass = 1500.0;     // kg
    double dragCoefficient = 0.25;   // example value, adjust as needed
    double frontalArea = 2.0;        // m^2
    double rollingResistance = 0.01; // example value, adjust as needed

    // Initial conditions
    double currentSpeed, targetSpeed, targetAcceleration;

    // User inputs
    std::cout << "Enter current speed: ";
    std::cin >> currentSpeed;
    std::cout << "Enter target speed: ";
    std::cin >> targetSpeed;
    std::cout << "Enter target acceleration: ";
    std::cin >> targetAcceleration;

    // PID controller
    PIDController pidController(kp, ki, kd, dt);

    // Simulation loop
    for (int i = 0; i < 100; ++i) {  // Simulate for 10 time steps (adjust as needed)
        // Calculate error (velocity error)
        double velocityError = targetSpeed - currentSpeed;

        // Use PID controller to calculate control output (throttle/brake)
        double controlOutput = pidController.calculateOutput(velocityError);

        // Calculate acceleration using a simple physics-based model
        double netForce = vehicleMass * (targetAcceleration + controlOutput) +
            0.5 * dragCoefficient * frontalArea * currentSpeed * currentSpeed +
            rollingResistance * vehicleMass;
        double currentAcceleration = netForce / vehicleMass;

        // Update current speed based on acceleration
        currentSpeed += currentAcceleration * dt;

        // Display current state
        std::cout << "Time Step " << i << ": ";
        std::cout << "Current Speed: " << currentSpeed << " m/s, ";
        std::cout << "Current Acceleration: " << currentAcceleration << " m/s^2" << std::endl;
    }

    return 0;
}
