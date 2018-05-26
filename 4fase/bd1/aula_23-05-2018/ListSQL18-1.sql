
create table if not exists ranking (
   rank varchar(3) not null,
   dscr varchar(20) not null,
   constraint pk_ranking primary key (rank)
);
create table if not exists sailor (
   ids integer not null,
   name varchar(30) not null,
   birthd date not null,
   rank varchar(3) not null,
   constraint pk_sailor primary key (ids),
   constraint fk_sailor_ranking foreign key (rank) references ranking(rank)
);
create table if not exists boat (
   idb integer not null,
   name varchar(30) not null,
   color  varchar(10) not null constraint ck_color_boat check (color='Blue' or color='White' or color='Red' or color='Gray'),
   len  real not null,
   power real not null,
   constraint pk_boat primary key (idb)
);
create table if not exists reserve (
   idb integer not null,
   ids integer not null,
   dater date not null,
   nhours real,
   constraint pk_reserve primary key (idb,ids,dater),
   constraint fk_reserve_boat foreign key (idb) references boat(idb),
   constraint fk_reserve_sailor foreign key (ids) references sailor(ids)
);
   
insert into ranking(rank,dscr) values (1,'Amateur'),(2,'Beginner'),
                                        (3,'Semi-Professional'),(4,'Professional'),(5,'Master');
--
insert into sailor (ids,name,birthd, rank) values (1,'Almir Klink','10/03/1963',5),
                                                  (2,'Lars Grael','12/07/1970',5),
                                                  (3,'Robert Scheidt','25/08/1971',5),
                                                  (4,'Carinha','02/04/1983',3),
                                                  (5,'Alan Turing','23/06/1912',1),
                                                  (6,'Edgar Codd','23/08/1923',2),
						  (10,'Jack','10/02/2000',2),(15,'Chris','07/08/1982',1),
                                                  (35,'Mary','21/02/1994',4),(45,'Amanda','17/11/1985',2),
                                                  (13,'John','01/09/1974',5);
--
insert into boat (idb,name,color,len,power) values (1,'Avante','Blue',23,15), (2,'Furious','Red',20,18),
                                                    (3,'Sea','White',8,10),  (4,'Faster','Gray',12,20),
                                                    (5,'Collie','White',10,10), (6,'Silver','Red',5,45),
						    (100,'Speed','Gray',20,50),(200,'Smooth','White',10,35),
						    (300,'Nail','Red',10,30),(400,'Vintage','Blue',25,60),(500,'Tomato','Red',18,35);
--
insert into reserve (idb,ids,dater,nhours) values (1,1,'01/01/2013',13.5),(1,4,'05/01/2013',10.1),
                           (2,2,'02/02/2013',13.5),(2,5,'04/04/1936',7.6), (2,6,'06/07/1941',5.5),
                           (3,1,'10/03/2013',10.3),(3,3,'08/03/2013',14.5),(400,15,'10/10/2010',4),
                           (400,13,'12/10/2010',8),(100,10,'10/10/2010',2),(300,35,'10/10/2010',3),
                           (200,15,'13/10/2010',NULL),(500,13,'13/10/2010',NULL),(1,3,'10/03/2013',NULL),
                           (400,45,'13/10/2010',NULL),(100,35,'12/10/2010',8);
