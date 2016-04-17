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
	input clock,
	input [63:0] data,
	input [63:0] key,
	output reg match
);

reg temp_match;

always @(posedge clock)
	match <= temp_match;

always @*
begin
	temp_match = 0;
	
	if (data == template)
		temp_match = 1;
end

endmodule
