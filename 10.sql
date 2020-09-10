SELECT DISTINCT (name) 
FROM people JOIN directors ON directors.person_id = people.id 
JOIN ratings ON directors.movie_id = ratings.movie_id 
WHERE(rating >= 9.0);
/* First we join on the basis of people's name and director's name then we compare the filmagrophy of the director to movies.id.