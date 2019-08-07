create or replace function aumentasalario(valor float) returns text as $$
declare linha record;
begin
	for linha in select * from dados loop
		update dados set salario = linha.salario + linha.salario * valor where id = linha.id;
		raise notice 'Salário atualizado para %', linha.nome;
	end loop;

	return null;
end;
$$ language plpgsql;