create table AvailableFlights(Num_flight int , date date, numberOfFreeSeats int , price float);
create table Bookings(Num_flight int , date date , passenger int , price float);

insert into AvailableFlights values (1001, current_timestamp, 30, 1000.00);

create or replace function decrement() returns trigger as $$
	declare numOfFreeSeats int;
	begin
		numOfFreeSeats := (select numberOfFreeSeats from AvailableFlights where Num_flight = new.Num_flight);
		if numOfFreeSeats > 0 then
			update AvailableFlights set numberOfFreeSeats = numberOfFreeSeats - 1 where Num_flight = new.Num_flight;
		end if;

		raise notice 'NUM %', numOfFreeSeats;
		if numOfFreeSeats <= 0 then
			raise notice 'There are no seats available for this flight!';
			return null;
		end if;

		update AvailableFlights set price = price + 50.00 where Num_flight = new.Num_flight;

		return new;
	end;
$$ language plpgsql;

create TRIGGER decrement before INSERT OR UPDATE ON Bookings
    FOR EACH ROW EXECUTE PROCEDURE decrement();