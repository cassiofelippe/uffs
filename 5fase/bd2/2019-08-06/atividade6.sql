create or replace function adicionacampos() returns void as $$
declare linha record;
begin
	for linha in select * from dados loop
		update dados set usuario = current_user, data = current_date where id = linha.id;
		raise notice 'Adicionadas informações para % %', linha.id, current_user;
	end loop;
end;
$$ language plpgsql;