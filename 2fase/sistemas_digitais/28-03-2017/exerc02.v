module soma1bit (
    input a,
    input b,
    input c_in,
    output out,
    output c_out);

    reg o, c;
    assign out = o;
    assign c_out = c;

    always @(a, b, c_in) begin
        case ({a, b, c_in})
            3'b000: begin
                o <= 0;
                c <= 0;
            end
            3'b001: begin
                o <= 1;
                c <= 0;
            end
            3'b010: begin
                o <= 1;
                c <= 0;
            end
            3'b011: begin
                o <= 0;
                c <= 1;
            end
            3'b100: begin
                o <= 1;
                c <= 0;
            end
            3'b101: begin
                o <= 0;
                c <= 1;
            end
            3'b110: begin
                o <= 0;
                c <= 1;
            end
            3'b111: begin
                o <= 1;
                c <= 1;
            end
        endcase
    end

endmodule
