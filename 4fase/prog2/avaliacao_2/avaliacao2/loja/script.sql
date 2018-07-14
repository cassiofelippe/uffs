
-- create table ala (
-- 	codigo int not null,
-- 	cnpjhosp varchar(18) not null,
-- 	cpfenf varchar(14) not null,
-- 	constraint pk_ala primary key (codigo),
-- 	constraint fk_ala_hospital foreign key (cnpjhosp) references hospital(cnpj),
-- 	constraint fk_ala_enfermeira foreign key (cpfenf) references enfermeira(cpf)
-- );

-- create table atendimento (
-- 	cpfmedico varchar(14) not null,
-- 	cpfpaciente varchar(14) not null,
-- 	constraint pk_atendimento primary key (cpfmedico, cpfpaciente),
-- 	constraint fk_atendimento_medico foreign key (cpfmedico) references medico(cpf),
-- 	constraint fk_atendimento_paciente foreign key (cpfpaciente) references paciente(cpf)
-- );

-- create table convenio (
-- 	cnpjhospital varchar(18) not null,
-- 	cnpjplano varchar(18) not null,
-- 	constraint pk_convenio primary key (cnpjhospital, cnpjplano),
-- 	constraint fk_convenio_hospital foreign key (cnpjhospital) references hospital(cnpj),
-- 	constraint fk_atendimento_plano foreign key (cnpjplano) references plano(cnpj)
-- );

-- create table endereco (
-- 	codigo int not null,
-- 	numero int not null,
-- 	rua varchar(30) not null,
-- 	bairro varchar(30) not null,
-- 	cidade varchar(30) not null,
-- 	constraint pk_endereco primary key (codigo)
-- );

-- create table enfermeira (
-- 	cpf varchar(14) not null,
-- 	cre varchar(10) not null,
-- 	nome varchar(30) not null,
-- 	fone varchar(15) not null,
-- 	chefe varchar(14),
-- 	codendereco int not null,
-- 	constraint pk_enfermeira primary key (cpf),
-- 	constraint fk_enfermeira_enfermeira foreign key (cchefe) references enfermeira(cpf),
-- 	constraint fk_enfermeira_endereco foreign key (codendereco) references endereco(codigo)
-- );

-- create table especialidade (
-- 	sigla varchar(2) not null,
-- 	nome varchar(20) not null,
-- 	constraint pk_especialidade primary key (sigla)
-- );

-- create table hospital (
-- 	cnpj varchar(18) not null,
-- 	nome varchar(20) not null,
-- 	fone varchar(15) not null,
-- 	codendereco int not null,
-- 	constraint pk_hospital primary key (cnpj),
-- 	constraint fk_hospital_endereco foreign key (codendereco) references endereco(codigo)
-- );

-- create table internacao (
-- 	codigo int not null,
-- 	dhentrada date not null,
-- 	dhsaida date not null,
-- 	codala int not null,
-- 	cpfpaciente varchar(14) not null,
-- 	constraint pk_internacao primary key (codigo),
-- 	constraint fk_internacao_ala foreign key (codala) references ala(codigo),
-- 	constraint fk_internacao_paciente foreign key (cpfpaciente) references paciente(cpf)
-- );

-- create table internacao_medico (
-- 	cpfmedico varchar(14) not null,
-- 	codinternacao int not null,
-- 	constraint pk_internacao_medico primary key (cpfmedico, codinternacao),
-- 	constraint fk_internacao_medico_medico foreign key (cpfmedico) references medico(cpf),
-- 	constraint fk_internacao_internacao foreign key (codinternacao) references internacao(codigo)
-- );

-- create table medico (
-- 	cpf varchar(14) not null,
-- 	nome varchar(20) not null,
-- 	fone varchar(15) not null,
-- 	crm varchar(15) not null,
-- 	codendereco int not null,
-- 	sigespecialidade varchar(2) not null,
-- 	constraint pk_medico primary key (cpf),
-- 	constraint fk_medico_endereco foreign key (codendereco) references endereco(codigo),
-- 	constraint fk_medico_especialidade foreign key (sigespecialidade) references especialidade(sigla)
-- );

-- create table paciente (
-- 	cpf varchar(14) not null,
-- 	nome varchar(20) not null,
-- 	fone varchar(15) not null,
-- 	cnpjplano varchar(18) not null,
-- 	codendereco int not null,
-- 	constraint pk_paciente primary key (cpf),
-- 	constraint fk_paciente_plano foreign key (cnpjplano) references plano(cnpj),
-- 	constraint fk_paciente_endereco foreign key (codendereco) references endereco(codigo)
-- );

-- create table plano (
-- 	cnpj varchar(18) not null,
-- 	nome varchar(20) not null,
-- 	fone varchar(15) not null,
-- 	codendereco int not null,
-- 	constraint pk_plano primary key (cnpj),
-- 	constraint fk_plano_endereco foreign key (codendereco) references endereco(codigo)
-- );

-- create table planos_medicos (
-- 	cnpjplano varchar(18) not null,
-- 	cpfmedico varchar(14) not null,
-- 	constraint pk_planos_medicos primary key (cnpjplano, cpfmedico),
-- 	constraint fk_planos_medicos_plano foreign key (cnpjplano) references plano(cnpj),
-- 	constraint fk_planos_medicos_medico foreign key (cpfmedico) references medico(cpf)
-- );
