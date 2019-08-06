create or replace function retornatexto(t text) returns text as $$
begin
	return t;
end;
$$ language plpgsql;