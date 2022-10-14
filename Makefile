build:
	g++ -I /usr/local/include/eigen3 discrete_system.cpp -o discrete_system.o
	g++ -I /usr/local/include/eigen3 continuous_system.cpp -o continuous_system.o

run:
	./discrete_system.o
	./continuous_system.o

plot:
	gnuplot discrete_plot_script.pp
	gnuplot continuous_plot_script.pp
