set xlabel "Time"
set ylabel "Value"

set term png
set output "continuous_plot.png"

plot "continuous_plot_data" u 1:2  with l title "position_x", \
     "continuous_plot_data" u 1:3  with l title " velocity_x", \
     "continuous_plot_data" u 1:4  with l title " position_y", \
     "continuous_plot_data" u 1:5  with l title " velocity_y", \