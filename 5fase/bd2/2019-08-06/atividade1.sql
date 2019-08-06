create or replace function increment() returns void as $$
declare n integer := 0;
begin
	n := n + 1;
	raise notice 'n incremented: %', n;
end;
$$
language plpgsql;





