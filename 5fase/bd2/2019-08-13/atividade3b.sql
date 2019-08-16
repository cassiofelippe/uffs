CREATE TABLE page_revision (
  id int,
  name varchar(50),
  created_on timestamp,
  author varchar(50),
  text text
);

CREATE TABLE page_audition (
  id_page int,
  name varchar(50),
  created_on timestamp,
  author varchar(50),
  text text,
  updated_on timestamp,
  user_login varchar(20),
  dif_length int,
  operation varchar(6)
);

CREATE OR REPLACE FUNCTION audit_page() RETURNS TRIGGER AS $$
    BEGIN
        IF OLD.id IS NULL THEN -- is new record
            INSERT INTO page_audition VALUES (
              NEW.id, NEW.name, NEW.created_on, NEW.author, NEW.TEXT, CURRENT_TIMESTAMP, (SELECT current_user),
              length(NEW.TEXT), 'INSERT'
            );
        ELSE
          INSERT INTO page_audition VALUES (
            NEW.id, NEW.name, NEW.created_on, NEW.author, NEW.TEXT, current_timestamp, (SELECT current_user),
            (length(OLD.text) - length(NEW.text)), 'UPDATE');
    END IF;
    
    RETURN NEW;
    END;
$$ LANGUAGE plpgsql;


DROP TRIGGER audit_page ON page_revision;
CREATE TRIGGER audit_page AFTER INSERT OR UPDATE ON page_revision FOR EACH ROW EXECUTE PROCEDURE audit_page();

SELECT * FROM page_revision;
SELECT * FROM page_audition;

INSERT INTO page_revision VALUES (1001, 'Genesis - Band', current_timestamp, 'SomeFanOfTheBand68', 'Genesis were an English rock band formed at Charterhouse School, Godalming, Surrey, in 1967. The most successful and longest-lasting line-up consisted of keyboardist Tony Banks, bassist/guitarist Mike Rutherford and drummer/singer Phil Collins.');
UPDATE page_revision SET TEXT = 'Genesis were an English rock band where Phil Collins started his career.' WHERE id = 1001;

DELETE FROM page_revision;
DELETE FROM page_audition;

DROP TABLE page_audition;

