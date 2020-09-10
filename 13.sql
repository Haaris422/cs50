SELECT DISTINCT (name) 
FROM people JOIN stars ON people.id = stars.person_id 
WHERE name != "Kevin Bacon"
AND movie_id IN 
    (SELECT movie_id 
    FROM people JOIN stars ON stars.person_id = people.id 
    WHERE name = "Kevin Bacon" AND birth = 1958);
/* Here, use all of kevin bacon (born in 1958) starrers as condition for printing all of his co-stars's names but not his.     