module invert(
		input [15:0] x,
		output reg o
	);

	always @(x) begin
		if(x < 0) begin
			o = -x;
		end else begin
			o = x;
		end
	end

endmodule

module calcArea(
		input [7:0] x1,
		input [7:0] x2,
		input [7:0] x3,
		input [7:0] y1,
		input [7:0] y2,
		input [7:0] y3,
		output wire [15:0] area
	);

	assign area = (((x1*y2)+(x2*y3)+(x3*y1))-((x3*y2)+(x2*y1)+(y3*x1)));

	invert inverting (area, invertedArea);

	assign area = invertedArea;

endmodule

module test;
	reg [7:0] x1;
	reg [7:0] y1;
	reg [7:0] x2;
	reg [7:0] y2;
	reg [7:0] x3;
	reg [7:0] y3;
	wire [15:0] areaSaida;

	calcArea area(x1, x2, x3, y1, y2, y3, areaSaida);

	initial begin
		$dumpvars;
		x1 = 1;
		x2 = 5;
		x3 = 1;
		y1 = 1;
		y2 = 1;
		y3 = 5;

		#1
		
		x1 = 4;
		x2 = 7;
		x3 = 2;
		y1 = 8;
		y2 = 9;
		y3 = 23;
		
		#1
		
		x1 = 12;
		x2 = 4;
		x3 = 3;
		y1 = 16;
		y2 = 21;
		y3 = 7;

    $finish;
	end

endmodule

// module triangle(
// 	// input triangle and dod coordinates
// 	input [7:0] x1,
// 	input [7:0] y1,
// 	input [7:0] x2,
// 	input [7:0] y2,
// 	input [7:0] x3,
// 	input [7:0] y3,
// 	input [7:0] xdod,
// 	input [7:0] ydod,
// 	output reg dodInTriangle
// );

// wire [7:0] x1p;

// wire signed [15:0] a;
// wire signed [15:0] b;
// wire signed [15:0] c;

// calcArea area (x1, y1, x2, y2, x3, y3);

// // assign a = (((x1*y2)+(x2*ydod)+(xdod*y1))-((xdod*y2)+(x2*y1)+(ydod*x1)));
// // assign b = (((xdod*y2)+(x2*y3)+(x3*ydod))-((x3*y2)+(x2*ydod)+(y3*xdod)));
// // assign c = (((x1*ydod)+(xdod*y3)+(x3*y1))-((x3*ydod)+(xdod*y1)+(y3*x1)));

// // assign a = calcArea(x1, y1, x2, y2, xdod, ydod);
// // assign b = calcArea(x2, y2, x3, y3, xdod, ydod);
// // assign c = calcArea(x3, y3, x1, y1, xdod, ydod);

// reg [15:0] totalArea = a + b + c;

// endmodule