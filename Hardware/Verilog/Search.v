`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 	   Cal Poly Pomona
// Engineer: 	   Byron Phung
// 
// Create Date:    15:18:15 04/17/2016 
// Design Name: 
// Module Name:    Search 
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
module Search(
	input clock,
	input reset,
	input [511:0] data,
	input [511:0] key,
	output reg match
);

reg [511:0] data1;
reg [510:0] data2;
reg [509:0] data3;
reg [508:0] data4;
wire [63:0] key1, key2, key3, key4;
reg match1, match2, match3, match4;
reg max_counter = 113;
reg [6:0] counter;

Comparator c1
(
	.clock(clock),
	.data(data1),
	.key(key1),
	.match(match1)
);

Comparator c2
(
	.clock(clock),
	.data(data2),
	.key(key2),
	.match(match2)
);

Comparator c3
(
	.clock(clock),
	.data(data3),
	.key(key3),
	.match(match3)
);

Comparator c4
(
	.clock(clock),
	.data(data4),
	.key(key4),
	.match(match4)
);

always @(posedge clock, posedge reset)
begin
	if (reset)
	begin
		counter <= 0;
		data1 <= data;
		data2 <= data[511:1];
		data3 <= data[511:2];
		data4 <= data[511:3];
	end
		
	else
	begin
		if (counter == max_counter)
		begin
			counter <= 0;
			data1 <= data;
			data2 <= data[511:1];
			data3 <= data[511:2];
			data4 <= data[511:3];
		end
		
		else
		begin
			counter <= counter + 1;
			data1 <= data1 << 1;
			data2 <= data2 << 1;
			data3 <= data3 << 1;
			data4 <= data4 << 1;
		end
			
		if (match1 || match2 || match3 || match4)
			match <= 1;
		else
			match <= 0;
	end
end

endmodule
