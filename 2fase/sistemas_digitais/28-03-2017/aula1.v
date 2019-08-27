module leds(
	input res,
	input c,
	output o
	);

	reg m;
	
	assign o = m;

	always @(res) begin
		m <=0;
	end

	always @(c) begin
		m <= ~m;
	end
endmodule

module teste;
	reg clk, reset;
	wire saida;
	
	leds meuLeds(reset, clk, saida);
	
	always #2 begin
		clk <= ~clk;
	end
	
	initial begin
		$dumpvars(0, clk, saida);
		#1;
		reset <=1;
		#1;
		reset <=0;
		#5;
		clk <= 1;
		#300;
		$finish;
		
		
	end
endmodule