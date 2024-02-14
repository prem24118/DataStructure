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

int main() {
    // PID parameters
    double kp = 0.1;
    double ki = 0.01;
    double kd = 0.05;
    double dt = 0.05;  // time step (seconds)

    // Initial conditions
    double currentSpeed, currentAcceleration, targetSpeed, targetAcceleration;

    // User inputs
    std::cout << "Enter current speed: ";
    std::cin >> currentSpeed;
    std::cout << "Enter current acceleration: ";
    std::cin >> currentAcceleration;
    std::cout << "Enter target speed: ";
    std::cin >> targetSpeed;
    std::cout << "Enter target acceleration: ";
    std::cin >> targetAcceleration;

    // Headway time target
    double headwayTarget = 1.4;  // seconds

    // PID controller
    PIDController pidController(kp, ki, kd, dt);

    // Simulation loop
    for (int i = 0; i < 50; ++i) {  // Simulate for 10 time steps (adjust as needed)
        // Calculate error (headway time error)
        //double error = headwayTarget - ((currentSpeed - targetSpeed) / currentAcceleration);

        //// Use PID controller to calculate control output (throttle/brake)
        //double controlOutput = pidController.calculateOutput(error);
        double velocityError = targetSpeed - currentSpeed;

        // Use PID controller to calculate control output (throttle/brake)
        double controlOutput = pidController.calculateOutput(velocityError);

        // Update current speed and acceleration based on control output
        currentAcceleration = targetAcceleration + controlOutput;
        currentSpeed += currentAcceleration * dt;

        // Display current state
        std::cout << "Time Step " << i << ": ";
        std::cout << "Current Speed: " << currentSpeed << " m/s, ";
        std::cout << "Current Acceleration: " << currentAcceleration << " m/s^2" << std::endl;
    }

    return 0;
}
