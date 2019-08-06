create or replace function tabela() returns table (id int, nome text) as $$
declare	media int;
begin
	select avg(tabelas.id) into media from tabelas;
	return query select * from tabelas where tabelas.id > media;
end;
$$ language plpgsql;
