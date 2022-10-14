set xlabel "Time"
set ylabel "Value"

set term png
set output "discrete_plot.png"

plot "discrete_plot_data" u 1:2   with l title "position_x", \
     "discrete_plot_data" u 1:3   with l title " velocity_x", \
     "discrete_plot_data" u 1:4   with l title " position_y", \
     "discrete_plot_data" u 1:5   with l title " velocity_y", \