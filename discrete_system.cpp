#include <iostream>
#include <fstream>
#include <cmath>

#include <Eigen/Dense>

Eigen::VectorXd run(double time, const Eigen::VectorXd &state, double step_size)
{
	double gravity = 9.8;

    Eigen::MatrixXd A(4, 4);
	A << 0, 1, 0, 0,
	     0, 0, 0, 0,
		 0, 0, 0, 1,
		 0, 0, 0, 0;
	
	Eigen::MatrixXd K(4, 1);
	K << 1,
	     0,
		 0,
		 -gravity;

    return state + step_size * ((A * state) + K);
}

void solve(const Eigen::VectorXd &initial_state,double step_size)
{
    Eigen::IOFormat format(8, 0, ", ", "\t", "", "", "", "");
	std::ofstream file;
	file.open("discrete_plot_data");

	int position_y_index = 2;
	double time = 0;

	Eigen::VectorXd state = initial_state;

	while(state[position_y_index] >= 0) {
		file << time << "\t" << state.format(format) << std::endl;
		state = run(time, state, step_size);
		time = time + step_size;
	}
}

int main(void)
{
	Eigen::VectorXd initial_state(4);

	double step_size = 0.1;

	double initial_angle = 45;
	double initial_velocity = 20;

	double initial_velocity_x = initial_velocity * cos(initial_angle);
	double initial_velocity_y = initial_velocity * sin(initial_angle); 

	double initial_position_x = 0;
	double initial_position_y = 0;

	initial_state << initial_position_x, initial_velocity_x, initial_position_y, initial_velocity_y;

	solve(initial_state, step_size);
}
