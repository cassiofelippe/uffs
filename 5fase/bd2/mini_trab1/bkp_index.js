var pg = require('pg');
var conString = "postgres://postgres:postgres@localhost:5432/mini_trab1";

var client = new pg.Client(conString);
client.connect();

client.query("INSERT INTO test (name, created_on) values ('Cassio', current_timestamp)");
client.query("INSERT INTO test (name, created_on) values ('Lucas', current_timestamp)");
client.query("INSERT INTO test (name, created_on) values ('Vinicius', current_timestamp)");

var query = client.query("SELECT * FROM test");

query.on('row', function(row) {
  console.log(row);
});

query.on('end', function() {
  client.end();
});
