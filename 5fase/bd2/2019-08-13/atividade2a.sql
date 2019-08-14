create table AvailableFlights(Num_flight int , date date, numberOfFreeSeats int , price float);
create table Bookings(Num_flight int , date date , passenger int , price float);

insert into AvailableFlights values (1001, current_timestamp, 30, 1000.00);

create or replace function decrement() returns trigger as $$
	begin
		if (select numberOfFreeSeats from AvailableFlights where Num_flight = new.Num_flight) > 0 then
			update AvailableFlights set numberOfFreeSeats = numberOfFreeSeats - 1 where Num_flight = new.Num_flight;
		end if;

		return new;
	end;
$$ language plpgsql;

create TRIGGER decrement before INSERT OR UPDATE ON Bookings
    FOR EACH ROW EXECUTE PROCEDURE decrement();