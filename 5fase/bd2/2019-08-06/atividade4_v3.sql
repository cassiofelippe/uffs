create or replace function aumentasalario() returns text as $$

begin

	update dados set salario = salario + salario * .1;
	raise notice 'Salário atualizado para todos os professores';

	return null;
end;

$$ language plpgsql;