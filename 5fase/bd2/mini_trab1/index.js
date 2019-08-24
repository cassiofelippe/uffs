var pg = require('pg');

var client = new pg.Client("postgres://postgres:postgres@localhost:5432/mini_trab1");
client.connect();

/*
client.query("INSERT INTO test (name, created_on) values ('Cassio', current_timestamp)");
client.query("INSERT INTO test (name, created_on) values ('Lucas', current_timestamp)");
client.query("INSERT INTO test (name, created_on) values ('Vinicius', current_timestamp)");
*/

(async () => {
  await client.query('BEGIN')
  await client.query(`INSERT INTO test (name, created_on) VALUES('OK', current_timestamp) RETURNING id`)
  await client.query('COMMIT')

  await client.query('BEGIN')
  await client.query(`INSERT INTO test (name, created_on) VALUES('ERROR', current_timestamp) RETURNING id`);
  await client.query('ROLLBACK')
})().catch(e => console.error(e.stack))







/*
var query = client.query("SELECT * FROM test");

query.on('row', function(row) {
  console.log(row);
});

query.on('end', function() {
  client.end();
});
*/