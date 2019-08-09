CREATE FUNCTION emp_time() RETURNS trigger AS $$
    BEGIN
        IF NEW.empname IS NULL THEN
            RAISE EXCEPTION 'empname nao pode ser nulo';
        END IF;
        IF NEW.salary IS NULL THEN
            RAISE EXCEPTION '% nao pode ter salario nulo', NEW.empname;
        END IF;
        NEW.last_date := current_timestamp;
        NEW.last_user := current_user;
        NEW.salary := NEW.salary * 1.1;	
        RETURN NEW;
    END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER emp_time BEFORE INSERT OR UPDATE ON emp
    FOR EACH ROW EXECUTE PROCEDURE emp_time();