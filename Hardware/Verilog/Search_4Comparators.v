`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 	   Cal Poly Pomona
// Engineer: 	   Byron Phung
// 
// Create Date:    15:18:15 04/17/2016 
// Design Name: 
// Module Name:    Search_4Comparators
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module Search_4Comparators(
	input clock,
	input reset,
	input [1023:0] data,
	input [63:0] key,
	output reg match
);

// Use the counter to determine which bits of data to use.
reg [7:0] counter;

// Track the data needed for each comparator.
reg [63:0] data1, data2, data3, data4;

// Track each match output for each comparator.
wire match1, match2, match3, match4;

Comparator c1
(
	.data(data1),
	.key(key),
	.match(match1)
);

Comparator c2
(
	.data(data2),
	.key(key),
	.match(match2)
);

Comparator c3
(
	.data(data3),
	.key(key),
	.match(match3)
);

Comparator c4
(
	.data(data4),
	.key(key),
	.match(match4)
);

// Sequential Logic
always @(posedge clock, posedge reset)
begin
	// If reset, reset every variable to their defaults.
	if (reset)
	begin
		counter <= 0;
		match <= 0;
	end
	
	// Otherwise, calculate the desired values.
	else
	begin
		// If the last count is reached, then reset the counter.
		// Equation: last count = (data_size - comparator_size) / num_of_comparators
		if (counter == 240)
		begin
			counter <= 0;
		end
		
		// Otherwise, increment the counter.
		else
		begin
			counter <= counter + 1;
		end
		
		// If the comparators yield matches for any of the current searches,
		// then set the overall match to 1.
		if (match1 || match2 || match3 || match4)
			match <= 1;
			
		// Otherwise, set it to 0.
		else
			match <= 0;
	end
end

always @*
begin
	if (counter == 240)
	begin
		data1 = data[1023-4*counter-:64];
		data2 = data[1023-4*counter-:64];
		data3 = data[1023-4*counter-:64];
		data4 = data[1023-4*counter-:64];
	end
	
	else
	begin
		data1 = data[1023-4*counter-:64];
		data2 = data[1022-4*counter-:64];
		data3 = data[1021-4*counter-:64];
		data4 = data[1020-4*counter-:64];
	end
end

endmodule
