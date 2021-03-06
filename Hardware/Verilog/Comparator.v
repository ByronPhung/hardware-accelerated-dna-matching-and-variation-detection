`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 	   Cal Poly Pomona
// Engineer:       Byron Phung
// 
// Create Date:    14:15:48 04/17/2016 
// Design Name: 
// Module Name:    Comparator 
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
module Comparator(
	input [63:0] data,
	input [63:0] key,
	output reg match
);

// Combinational Logic
always @*
begin
	// Default
	match = 0;
	
	// If the key matches the data, then set the match to 1.
	if (data == key)
		match = 1;
end

endmodule
