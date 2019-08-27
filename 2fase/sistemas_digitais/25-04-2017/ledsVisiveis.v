module counter (
  input CLOCK_50,
  output [0:0] LEDG
  );

  reg light = 0;
  reg [25:0] count;
  assign LEDG = light;

  always @(posedge CLOCK_50) begin
    // PISCA UMA VEZ EM TANTAS MIL PARA FICAR VISÍVEL
    if(count == 500000000) begin
      light <= ~light;
      count <= 0;
    end else begin
      count <= count+1;
    end
  end
endmodule

module test;
  reg CLOCK_50;
  reg KEY;
  wire light;

  always #1 CLOCK_50 <= ~CLOCK_50;

  counter c(CLOCK_50, light);

  initial begin
    $dumpvars;
    #0
    KEY <= 0;
    #5000
    $finish;
  end
endmodule


// SEGUNDO TRABALHO: LEDS PISCANDO (VISÍVEL)
