
create or replace FUNCTION emp_time() RETURNS trigger AS $$
  BEGIN
    IF NEW.salary IS NULL THEN
        RAISE EXCEPTION 'salary may not be null';
		END IF;
	
    new.salary := new.salary * 1.1;
      
		RETURN new;
  END;
$$ LANGUAGE plpgsql;

create TRIGGER emp_time before INSERT OR UPDATE ON emp
    FOR EACH ROW EXECUTE PROCEDURE emp_time();

insert into emp(name, salary) values ('joao', 1000);
	
select * from emp;
