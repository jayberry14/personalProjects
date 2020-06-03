DROP TABLE rides;
DROP TABLE riders;
DROP TABLE drivers;


CREATE TABLE riders
( id                 SERIAL       NOT NULL PRIMARY KEY
, authenticate       BOOLEAN      NOT NULL
, fname              VARCHAR(80)  NOT NULL
, lname              VARCHAR(80)  NOT NULL
, username           VARCHAR(80)  NOT NULL
, password_hash      VARCHAR(80)  NOT NULL
, email              VARCHAR(80)  NOT NULL
, phone              VARCHAR(80)          
);

CREATE TABLE drivers
( id     SERIAL      NOT NULL PRIMARY KEY
, name   VARCHAR(80) NOT NULL
, email  VARCHAR(80) NOT NULL
, phone  INT         NOT NULL
);

CREATE TABLE rides
( id            SERIAL       NOT NULL PRIMARY KEY
, location      VARCHAR (80) NOT NULL
, destination   VARCHAR (80) NOT NULL
, date          VARCHAR (80) NOT NULL
, time          VARCHAR (80) NOT NULL
, price         INT          NOT NULL
, driver_id     INT          NOT NULL REFERENCES drivers(id)
, rider_id      INT                   REFERENCES riders(id)
);

SELECT * FROM drivers;
SELECT * FROM riders;
SELECT * FROM rides;

INSERT INTO drivers (name, email, phone) VALUES ('John'  , 'johnsemail@google.com' , '2084962222');
INSERT INTO drivers (name, email, phone) VALUES ('Anna'  , 'annasemail@google.com' , '2084963333');
INSERT INTO drivers (name, email, phone) VALUES ('Bruce' , 'brucesemail@google.com', '2084964444');

INSERT INTO riders (authenticate, fname, lname, username, password_hash, email, phone) 
            VALUES ('true', 'Caden', 'Montgomery', 'montyc', 'jrkls09fd', 'cadensemail@google.com', '2084965990');
INSERT INTO riders (authenticate, fname, lname, username, password_hash, email, phone) 
            VALUES ('true', 'Frank', 'Harris', 'harrisf', 'W0aHe#4$o', 'franksemail@google.com', '2084963764');
INSERT INTO riders (authenticate, fname, lname, username, password_hash, email, phone) 
            VALUES ('true', 'Jenny', 'Matrix', 'matrixj', 'tr7&fffks', 'jennysemail@google.com', '2084960003');

INSERT INTO rides (location, destination, date, time, price, driver_id, rider_id) 
            VALUES ('Provo', 'Rexburg', '02/20/2020', '18:30', '10', '1', '1');
INSERT INTO rides (location, destination, date, time, price, driver_id)
            VALUES ('Rexburg', 'Salt Lake City', '03/15/2020', '05:00', '12', '1');
INSERT INTO rides (location, destination, date, time, price, driver_id)
            VALUES ('Rexburg', 'Logan', '02/29/2020', '12:00', '9', '2');
INSERT INTO rides (location, destination, date, time, price, driver_id)
            VALUES ('Rexburg', 'Provo', '02/21/2020', '11:30', '11', '1');
INSERT INTO rides (location, destination, date, time, price, driver_id)
            VALUES ('Salt Lake City', 'Rexburg', '03/17/2020', '11:30', '11', '1');
INSERT INTO rides (location, destination, date, time, price, driver_id)
            VALUES ('Boise', 'Rexburg', '02/21/2020', '9:30', '8', '3');

SELECT * FROM drivers;
SELECT * FROM riders;
SELECT * FROM rides;

-- SELECT location
-- FROM rides 
-- WHERE location = '';

-- SELECT destination
-- FROM rides 
-- WHERE destination = '';

-- SELECT price
-- FROM rides 
-- WHERE price = NULL;

-- SELECT date
-- FROM rides 
-- WHERE date = '';

-- SELECT time
-- FROM rides 
-- WHERE time = '';

SELECT location, destination, date, time, price 
FROM rides 
WHERE (location = 'something' OR destination <> 'Rexburg' OR date = '' OR time = '' OR price = NULL) AND rider_id IS NULL;


SELECT location, destination, date, time, price 
FROM rides 
WHERE (rider_id IS NULL
AND     location IS NOT NULL
AND     destination IS NOT NULL
AND     date IS NOT NULL
AND     time IS NOT NULL
AND     price <= 11);