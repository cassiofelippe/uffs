--
-- PostgreSQL database dump
--

-- Dumped from database version 9.5.12
-- Dumped by pg_dump version 9.5.12

SET statement_timeout = 0;
SET lock_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: plpgsql; Type: EXTENSION; Schema: -; Owner: 
--

CREATE EXTENSION IF NOT EXISTS plpgsql WITH SCHEMA pg_catalog;


--
-- Name: EXTENSION plpgsql; Type: COMMENT; Schema: -; Owner: 
--

COMMENT ON EXTENSION plpgsql IS 'PL/pgSQL procedural language';


SET default_tablespace = '';

SET default_with_oids = false;

--
-- Name: ala; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.ala (
    codigo integer NOT NULL,
    cnpjhosp character varying(20) NOT NULL,
    cpfenf character varying(20) NOT NULL
);


ALTER TABLE public.ala OWNER TO postgres;

--
-- Name: atendimento; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.atendimento (
    cpfmedico character varying(20) NOT NULL,
    cpfpaciente character varying(20) NOT NULL
);


ALTER TABLE public.atendimento OWNER TO postgres;

--
-- Name: convenios; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.convenios (
    cnpjhospital character varying(20) NOT NULL,
    cnpjplano character varying(20) NOT NULL
);


ALTER TABLE public.convenios OWNER TO postgres;

--
-- Name: endereco; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.endereco (
    codigo integer NOT NULL,
    numero integer NOT NULL,
    rua character varying(30) NOT NULL,
    bairro character varying(20) NOT NULL,
    cidade character varying(20) NOT NULL
);


ALTER TABLE public.endereco OWNER TO postgres;

--
-- Name: enfermeira; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.enfermeira (
    cpf character varying(20) NOT NULL,
    cre character varying(20) NOT NULL,
    nome character varying(30) NOT NULL,
    fone character varying(15) NOT NULL,
    chefe boolean NOT NULL,
    codendereco integer NOT NULL
);


ALTER TABLE public.enfermeira OWNER TO postgres;

--
-- Name: especialidade; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.especialidade (
    sigla character varying(3) NOT NULL,
    nome character varying(20) NOT NULL
);


ALTER TABLE public.especialidade OWNER TO postgres;

--
-- Name: hospital; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.hospital (
    cnpj character varying(20) NOT NULL,
    nome character varying(30) NOT NULL,
    fone character varying(20) NOT NULL,
    codendereco integer NOT NULL
);


ALTER TABLE public.hospital OWNER TO postgres;

--
-- Name: internacao; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.internacao (
    dhentrada timestamp without time zone NOT NULL,
    dhsaida timestamp without time zone NOT NULL,
    codigo integer NOT NULL,
    codala integer NOT NULL,
    cpfpaciente character varying(20) NOT NULL
);


ALTER TABLE public.internacao OWNER TO postgres;

--
-- Name: internacao_medico; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.internacao_medico (
    cpfmedico character varying(20) NOT NULL,
    codinternacao integer NOT NULL
);


ALTER TABLE public.internacao_medico OWNER TO postgres;

--
-- Name: medico; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.medico (
    cpf character varying(20) NOT NULL,
    nome character varying(30) NOT NULL,
    fone character varying(20) NOT NULL,
    crm character varying(20) NOT NULL,
    codendereco integer NOT NULL,
    sigespecialidade character varying(3)
);


ALTER TABLE public.medico OWNER TO postgres;

--
-- Name: paciente; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.paciente (
    cpf character varying(20) NOT NULL,
    nome character varying(30) NOT NULL,
    fone character varying(20) NOT NULL,
    cnpjplano character varying(20) NOT NULL,
    codendereco integer NOT NULL
);


ALTER TABLE public.paciente OWNER TO postgres;

--
-- Name: plano_saude; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.plano_saude (
    cnpj character varying(20) NOT NULL,
    nome character varying(30) NOT NULL,
    fone character varying(20) NOT NULL,
    codendereco integer NOT NULL
);


ALTER TABLE public.plano_saude OWNER TO postgres;

--
-- Name: planos_medicos; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.planos_medicos (
    cnpjplano character varying(20) NOT NULL,
    cpfmedico character varying(20) NOT NULL
);


ALTER TABLE public.planos_medicos OWNER TO postgres;

--
-- Data for Name: ala; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.ala (codigo, cnpjhosp, cpfenf) FROM stdin;
\.


--
-- Data for Name: atendimento; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.atendimento (cpfmedico, cpfpaciente) FROM stdin;
\.


--
-- Data for Name: convenios; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.convenios (cnpjhospital, cnpjplano) FROM stdin;
\.


--
-- Data for Name: endereco; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.endereco (codigo, numero, rua, bairro, cidade) FROM stdin;
\.


--
-- Data for Name: enfermeira; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.enfermeira (cpf, cre, nome, fone, chefe, codendereco) FROM stdin;
\.


--
-- Data for Name: especialidade; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.especialidade (sigla, nome) FROM stdin;
\.


--
-- Data for Name: hospital; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.hospital (cnpj, nome, fone, codendereco) FROM stdin;
\.


--
-- Data for Name: internacao; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.internacao (dhentrada, dhsaida, codigo, codala, cpfpaciente) FROM stdin;
\.


--
-- Data for Name: internacao_medico; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.internacao_medico (cpfmedico, codinternacao) FROM stdin;
\.


--
-- Data for Name: medico; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.medico (cpf, nome, fone, crm, codendereco, sigespecialidade) FROM stdin;
\.


--
-- Data for Name: paciente; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.paciente (cpf, nome, fone, cnpjplano, codendereco) FROM stdin;
\.


--
-- Data for Name: plano_saude; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.plano_saude (cnpj, nome, fone, codendereco) FROM stdin;
\.


--
-- Data for Name: planos_medicos; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.planos_medicos (cnpjplano, cpfmedico) FROM stdin;
\.


--
-- Name: pf_atendimento; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.atendimento
    ADD CONSTRAINT pf_atendimento PRIMARY KEY (cpfmedico, cpfpaciente);


--
-- Name: ph_hospital; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.hospital
    ADD CONSTRAINT ph_hospital PRIMARY KEY (cnpj);


--
-- Name: pk_ala; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ala
    ADD CONSTRAINT pk_ala PRIMARY KEY (codigo);


--
-- Name: pk_convenios; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.convenios
    ADD CONSTRAINT pk_convenios PRIMARY KEY (cnpjhospital, cnpjplano);


--
-- Name: pk_endereco; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.endereco
    ADD CONSTRAINT pk_endereco PRIMARY KEY (codigo);


--
-- Name: pk_enfermeira; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.enfermeira
    ADD CONSTRAINT pk_enfermeira PRIMARY KEY (cpf);


--
-- Name: pk_especialidade; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.especialidade
    ADD CONSTRAINT pk_especialidade PRIMARY KEY (sigla);


--
-- Name: pk_internacao; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.internacao
    ADD CONSTRAINT pk_internacao PRIMARY KEY (codigo);


--
-- Name: pk_internacao_medico; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.internacao_medico
    ADD CONSTRAINT pk_internacao_medico PRIMARY KEY (cpfmedico, codinternacao);


--
-- Name: pk_medico; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.medico
    ADD CONSTRAINT pk_medico PRIMARY KEY (cpf);


--
-- Name: pk_paciente; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.paciente
    ADD CONSTRAINT pk_paciente PRIMARY KEY (cpf);


--
-- Name: pk_plano_saude; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.plano_saude
    ADD CONSTRAINT pk_plano_saude PRIMARY KEY (cnpj);


--
-- Name: pk_planos_medicos; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.planos_medicos
    ADD CONSTRAINT pk_planos_medicos PRIMARY KEY (cnpjplano, cpfmedico);


--
-- Name: fk_ala_enfermeira; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ala
    ADD CONSTRAINT fk_ala_enfermeira FOREIGN KEY (cpfenf) REFERENCES public.enfermeira(cpf);


--
-- Name: fk_ala_hospital; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ala
    ADD CONSTRAINT fk_ala_hospital FOREIGN KEY (cnpjhosp) REFERENCES public.hospital(cnpj);


--
-- Name: fk_atendimento_medico; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.atendimento
    ADD CONSTRAINT fk_atendimento_medico FOREIGN KEY (cpfmedico) REFERENCES public.medico(cpf);


--
-- Name: fk_atendimento_paciente; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.atendimento
    ADD CONSTRAINT fk_atendimento_paciente FOREIGN KEY (cpfpaciente) REFERENCES public.paciente(cpf);


--
-- Name: fk_convenios_hospital; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.convenios
    ADD CONSTRAINT fk_convenios_hospital FOREIGN KEY (cnpjhospital) REFERENCES public.hospital(cnpj);


--
-- Name: fk_convenios_plano_saude; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.convenios
    ADD CONSTRAINT fk_convenios_plano_saude FOREIGN KEY (cnpjplano) REFERENCES public.plano_saude(cnpj);


--
-- Name: fk_enfermeira_endereco; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.enfermeira
    ADD CONSTRAINT fk_enfermeira_endereco FOREIGN KEY (codendereco) REFERENCES public.endereco(codigo);


--
-- Name: fk_hospital_endereco; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.hospital
    ADD CONSTRAINT fk_hospital_endereco FOREIGN KEY (codendereco) REFERENCES public.endereco(codigo);


--
-- Name: fk_internacao_ala; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.internacao
    ADD CONSTRAINT fk_internacao_ala FOREIGN KEY (codala) REFERENCES public.ala(codigo);


--
-- Name: fk_internacao_medico_internacao; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.internacao_medico
    ADD CONSTRAINT fk_internacao_medico_internacao FOREIGN KEY (codinternacao) REFERENCES public.internacao(codigo);


--
-- Name: fk_internacao_medico_medico; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.internacao_medico
    ADD CONSTRAINT fk_internacao_medico_medico FOREIGN KEY (cpfmedico) REFERENCES public.medico(cpf);


--
-- Name: fk_internacao_paciente; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.internacao
    ADD CONSTRAINT fk_internacao_paciente FOREIGN KEY (cpfpaciente) REFERENCES public.paciente(cpf);


--
-- Name: fk_medico_endereco; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.medico
    ADD CONSTRAINT fk_medico_endereco FOREIGN KEY (codendereco) REFERENCES public.endereco(codigo);


--
-- Name: fk_medico_especialidade; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.medico
    ADD CONSTRAINT fk_medico_especialidade FOREIGN KEY (sigespecialidade) REFERENCES public.especialidade(sigla);


--
-- Name: fk_paciente_endereco; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.paciente
    ADD CONSTRAINT fk_paciente_endereco FOREIGN KEY (codendereco) REFERENCES public.endereco(codigo);


--
-- Name: fk_paciente_plano_saude; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.paciente
    ADD CONSTRAINT fk_paciente_plano_saude FOREIGN KEY (cnpjplano) REFERENCES public.plano_saude(cnpj);


--
-- Name: fk_plano_saude_endereco; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.plano_saude
    ADD CONSTRAINT fk_plano_saude_endereco FOREIGN KEY (codendereco) REFERENCES public.endereco(codigo);


--
-- Name: fk_planos_medicos_medico; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.planos_medicos
    ADD CONSTRAINT fk_planos_medicos_medico FOREIGN KEY (cpfmedico) REFERENCES public.medico(cpf);


--
-- Name: fk_planos_medicos_plano_saude; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.planos_medicos
    ADD CONSTRAINT fk_planos_medicos_plano_saude FOREIGN KEY (cnpjplano) REFERENCES public.plano_saude(cnpj);


--
-- Name: SCHEMA public; Type: ACL; Schema: -; Owner: postgres
--

REVOKE ALL ON SCHEMA public FROM PUBLIC;
REVOKE ALL ON SCHEMA public FROM postgres;
GRANT ALL ON SCHEMA public TO postgres;
GRANT ALL ON SCHEMA public TO PUBLIC;


--
-- PostgreSQL database dump complete
--

