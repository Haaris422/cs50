SELECT title 
FROM people JOIN stars ON people.id = stars.person_id 
JOIN movies ON movies.id = stars.movie_id 
WHERE name == "Johnny Depp" 
AND movie_id IN 
    (SELECT movie_id 
    FROM people JOIN stars ON stars.person_id = people.id 
    WHERE name = "Helena Bonham Carter");
/* Here, to select movies with boths stars we movie_id we got from Helena as a condition for johnny's movies, hence only the movie in which johnny depp starred WITH helena carter will be shown.    