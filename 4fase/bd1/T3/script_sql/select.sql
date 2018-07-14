select * from ala a
join hospital h on h.cnpj = a.cnpjhosp
join enfermeira e on e.cpf = a.cpfenf;

select * from atendimento a
join medico m on m.cpf = a.cpfmedico
join paciente p on p.cpf = a.cpfpaciente;

select * from convenio c
join hospital h on h.cnpj = c.cnpjhospital
join plano p on p.cnpj = c.cnpjplano;

select * from endereco;

select * from enfermeira enf
join endereco e on e.codigo = enf.codendereco;

select * from especialidade;

select * from hospital h
join endereco e on e.codigo = h.codendereco;

select * from internacao i
join ala a on a.codigo = i.codala
join paciente p on p.cpf = i.cpfpaciente;

select * from internacao_medico im
join internacao i on i.codigo = codinternacao
join medico m on m.cpf = im.cpfmedico;

select * from medico m
join endereco e on e.codigo = m.codendereco
join especialidade es on es.sigla = m.sigespecialidade;

select * from paciente pa
join plano pl on pl.cnpj = pa.cnpjplano
join endereco e on e.codigo = pa.codendereco;

select * from plano p
join endereco e on e.codigo = p.codendereco;

select * from planos_medicos pm
join plano p on p.cnpj = pm.cnpjplano
join medico m on m.cpf = pm.cpfmedico;