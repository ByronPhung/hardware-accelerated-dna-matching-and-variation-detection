`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 	  Cal Poly Pomona
// Engineer:	  Byron Phung
//
// Create Date:   13:34:32 04/27/2016
// Design Name:   Search_4Comparators
// Module Name:   D:/Documents/College/CalPolyPomona/SeniorProject/hardware-accelerated-dna-matching-and-variation-detection/Hardware/Verilog/Search_4Comparators_tf.v
// Project Name:  Verilog
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Search_4Comparators
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Search_4Comparators_tf;

	// Inputs
	reg clock;
	reg reset;
	reg [1023:0] data;
	reg [63:0] key;

	// Outputs
	wire match;

	// Instantiate the Unit Under Test (UUT)
	Search_4Comparators uut (
		.clock(clock), 
		.reset(reset), 
		.data(data), 
		.key(key), 
		.match(match)
	);
	
	// Alternate the clock every unit of time.
	initial begin
		clock = 0;
		repeat (1_000_000)
			#1 clock =~ clock;
	end

	initial begin
		// Initialization
		reset = 1;
		data = 1024'b0100111010111010001100110010000010010111001110111010001010111000010111111100010011101110000010000010010100001010001111011010010010001101000100100001111100010111001110011110010001000111110010000001101100000000100100011000011100011110000110111011011000111011010000011010011011010000011111101100101100000101011101010011000010001110001110100111011000000100101000000100001010011010000011000100100000100011001101110000100011001111110001010011001100101011100100000000110000110000001010011010001000101101111000111100111100110000111100010000001000010000100110000000000011110011101000101100110011000011111000000001001001100100000000000000000001000010000010011001111000110001000010111111110101100000111110011001111000100000001100000011111111010110000010111100110111111110101110111110010001100001110010111001000110101011011110111000000100001101110000110000110010101000111001110001011100110101111100000001001100011000111011101000100000101011100000000110111010111101101001000100011110011010101110101111110111100100011100001111111110001011;
		key  = 64'b0100111010111010001100110010000010010111001110111010001010111000;
		@(negedge clock);
		
		// Turn off the reset and let the module be tested as is.
		reset = 0;
	end
      
endmodule
