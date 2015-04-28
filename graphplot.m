# Import the CSV file into oracle
x = csvread("output.csv");

# Plot the contents, this will plot the temperature against the ID of the sample
plot(x);

# Add a title and label the axis
title("Mixer Temperature");
xlabel("Data ID");
ylabel("Temperature");

# Pause the m file so the graph is displayed on the screen for the user to read
pause();
