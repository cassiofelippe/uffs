create or replace function aumentasalarioespecifico(idprofessor int, valor float) returns text as $$
declare linha record;
begin
	select * into linha from dados where dados.id = idprofessor;
	update dados set salario = linha.salario + valor where dados.id = idprofessor;
	raise notice 'Salário atualizado para %', linha.nome;
	return null;
end;
$$ language plpgsql;