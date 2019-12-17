ALTER TABLE names ADD PRIMARY KEY (nconst);
ALTER TABLE basics ADD PRIMARY KEY (tconst);

EXPLAIN ANALYSE SELECT primary_name FROM principals p
NATURAL JOIN names n
WHERE p.characters LIKE '%Blacksmith%'
GROUP BY primary_name
ORDER BY primary_name ASC;

EXPLAIN ANALYSE SELECT * FROM basics b
JOIN ratings r ON r.tconst = b.tconst
WHERE b.genres @> '{Comedy}'
AND r.average_rating > 6.0
ORDER BY b.original_title;


