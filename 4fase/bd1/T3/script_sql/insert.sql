insert into endereco values (1, 123, 'Rua Carlos Favaretto', 'São Cristóvão', 'Chapecó'),
														(2, 456, 'Av. Licínio Córdova', 'São Cristóvão', 'Chapecó'),
														(3, 789, 'Av. Fernando Machado', 'Centro', 'Chapecó'),
														(4, 321, 'Av. Getúlio Vargas', 'Centro', 'Chapecó'),
														(5, 654, 'Av. Nereu Ramos', 'Centro', 'Chapecó'),
														(6, 987, 'Rua Condá', 'Santa Maria', 'Chapecó'),
														(7, 132, 'Av. São Pedro', 'São Cristóvão', 'Chapecó'),
														(8, 465, 'Av. Leopoldo Sander', 'Efapi', 'Chapecó'),
														(9, 798, 'Rua Castelo Branco', 'São Cristóvão', 'Chapecó'),
														(10, 978, 'Rua Olavo Bilac', 'São Cristóvão', 'Chapecó'),
														(11, 576, 'Rua Castelo Branco', 'São Cristóvão', 'Chapecó'),
														(12, 798, 'Rua Felipe Schimdt', 'Bela Vista', 'Chapecó'),
														(13, 576, 'Rua Cel. Ernesto Bertaso', 'São Cristóvão', 'Chapecó'),
														(14, 354, 'Rua Dom Pedro I', 'São Cristóvão', 'Chapecó'),
														(15, 121, 'Rua Primeiro de Maio', 'São Cristóvão', 'Chapecó'),
														(16, 555, 'Rua Dom Pedro II', 'São Cristóvão', 'Chapecó'),
														(17, 719, 'Rua Mato Grosso', 'São Cristóvão', 'Centro');

insert into enfermeira (cpf, cre, nome, fone, codendereco)
values ('176.922.321-56', '132546', 'Maria da Silva', '(49) 98574-0984', 1);

insert into enfermeira values ('792.172.543-04', '6453421', 'Roberta Lúcia', '(49) 99765-3454', '176.922.321-56', 2),
															('807.987.666-54', '3241532', 'Julia dos Santos', '(48) 98456-0986', '176.922.321-56', 3);

insert into especialidade values ('di', 'Diagnóstico'),
																 ('on', 'Ongologista'),
																 ('pe', 'Pediatra'),
																 ('of', 'Oftalmologista'),
																 ('an', 'Anestesia'),
																 ('pl', 'Plástica');

insert into hospital values ('36.292.035/0001-99', 'Princeton-Plainsboro', '(55) 3323-5566', 4),
														('78.573.143/0001-80', 'Unihosp', '(55) 3245-1122', 5);

insert into ala values (1, '36.292.035/0001-99', '176.922.321-56'),
											 (2, '36.292.035/0001-99', '792.172.543-04'),
											 (3, '78.573.143/0001-80', '807.987.666-54');

insert into medico values ('747.902.457-64', 'Dr. House', '(55) 98765-6789', '152731', 6, 'di'),
													('756.884.265-78', 'Dr. Enéas', '(55) 98907-5543', '654732', 7, 'an'),
													('611.849.504-15', 'Dr. Hollywood', '(55) 98778-6787', '974635', 8, 'pl');

insert into plano values ('57.554.474/0001-00', 'Plano básico', '(47) 93321-1520', 9),
												 ('80.927.497/0001-27', 'Plano completo', '(47) 93345-2456', 10);

insert into planos_medicos values ('57.554.474/0001-00', '756.884.265-78'),
																	('80.927.497/0001-27', '747.902.457-64'),
																	('80.927.497/0001-27', '611.849.504-15');

insert into paciente values ('726.258.927-06', 'Mario Junior', '(49) 99999-0543', '57.554.474/0001-00', 11),
														('222.841.160-43', 'Paulo Cesar', '(49) 99876-3456', '80.927.497/0001-27', 12),
														('957.601.782-37', 'Carla Rosa', '(49) 98765-2312', '80.927.497/0001-27', 13);

insert into convenio values ('36.292.035/0001-99', '80.927.497/0001-27'),
														('78.573.143/0001-80', '57.554.474/0001-00');

insert into atendimento values ('747.902.457-64', '726.258.927-06'),
															 ('747.902.457-64', '222.841.160-43');

insert into internacao values (1, '2018-01-12', '2018-02-04', 1, '222.841.160-43');

insert into internacao (codigo, dhentrada, codala, cpfpaciente)
values (2, '2018-07-12', 3, '726.258.927-06');

insert into internacao_medico values ('611.849.504-15', 1),
																		 ('756.884.265-78', 2);