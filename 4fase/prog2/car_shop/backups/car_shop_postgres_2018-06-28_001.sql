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
-- Name: client; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.client (
    document character varying(18) NOT NULL,
    type character varying(20) NOT NULL,
    name character varying(50) NOT NULL,
    bdate date
);


ALTER TABLE public.client OWNER TO postgres;

--
-- Name: portion; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.portion (
    id integer NOT NULL,
    sell_id integer NOT NULL,
    value numeric(10,2) NOT NULL,
    number integer NOT NULL
);


ALTER TABLE public.portion OWNER TO postgres;

--
-- Name: sell; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.sell (
    id integer NOT NULL,
    term integer NOT NULL,
    value numeric(10,2) NOT NULL,
    vehicle_plate character varying(8) NOT NULL,
    client_doc character varying(18) NOT NULL
);


ALTER TABLE public.sell OWNER TO postgres;

--
-- Name: vehicle; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.vehicle (
    plate character varying(8) NOT NULL,
    brand character varying(25) NOT NULL,
    model character varying(40) NOT NULL,
    year integer NOT NULL,
    state character varying(25) NOT NULL,
    city character varying(40) NOT NULL,
    color character varying(20) NOT NULL,
    status character varying(25) NOT NULL,
    condition character varying(25),
    type character varying(20) NOT NULL
);


ALTER TABLE public.vehicle OWNER TO postgres;

--
-- Data for Name: client; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.client (document, type, name, bdate) FROM stdin;
\.


--
-- Data for Name: portion; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.portion (id, sell_id, value, number) FROM stdin;
\.


--
-- Data for Name: sell; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.sell (id, term, value, vehicle_plate, client_doc) FROM stdin;
\.


--
-- Data for Name: vehicle; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.vehicle (plate, brand, model, year, state, city, color, status, condition, type) FROM stdin;
\.


--
-- Name: pk_client; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.client
    ADD CONSTRAINT pk_client PRIMARY KEY (document);


--
-- Name: pk_portion; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.portion
    ADD CONSTRAINT pk_portion PRIMARY KEY (id);


--
-- Name: pk_sell; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.sell
    ADD CONSTRAINT pk_sell PRIMARY KEY (id);


--
-- Name: pk_vehicle; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.vehicle
    ADD CONSTRAINT pk_vehicle PRIMARY KEY (plate);


--
-- Name: fk_portion_sell; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.portion
    ADD CONSTRAINT fk_portion_sell FOREIGN KEY (sell_id) REFERENCES public.sell(id);


--
-- Name: fk_sell_client; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.sell
    ADD CONSTRAINT fk_sell_client FOREIGN KEY (client_doc) REFERENCES public.client(document);


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

