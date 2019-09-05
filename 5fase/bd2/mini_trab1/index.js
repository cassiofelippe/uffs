var pg = require('pg');

var client = new pg.Client("postgres://postgres:postgres@localhost:5432/mini_trab1");
client.connect();

(async () => {
  // ESSA TRANSAÇÃO FUNCIONA
  await client.query('BEGIN')
  await client.query(`INSERT INTO test (name, created_on) VALUES('OK', current_timestamp) RETURNING id`);
  await client.query('COMMIT')

  /*
    ESSA TRANSAÇÃO CAUSARÁ FALHA, POIS ESTÁ TENTANDO INSERIR UMA STRING NO LUGAR DE TIMESTAMP
    LOGO SERÁ FEITO ROLLBACK AUTOMATICAMENTE
  */
  await client.query('BEGIN')
  await client.query(`INSERT INTO test (name, created_on) VALUES('MUST NOT BE INSERTED', current_timestamp) RETURNING id`);
  await client.query(`INSERT INTO test (name, created_on) VALUES('ERROR', '1762getsyt') RETURNING id`);
  await client.query('COMMIT')
})().catch(e => console.log('Houve falha na transação'))




/*
DATABASE

CREATE DATABASE mini_trab1;

CREATE TABLE public.test (
    id integer NOT NULL,
    name character varying(50),
    created_on timestamp without time zone
);

*/









/*
var query = client.query("SELECT * FROM test");

query.on('row', function(row) {
  console.log(row);
});

query.on('end', function() {
  client.end();
});
*/