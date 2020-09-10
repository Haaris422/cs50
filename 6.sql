SELECT AVG(rating) 
FROM ratings JOIN movies ON movies.id = ratings.movie_id  
WHERE(year==2012);
/* To join the 2 tables on the basis of movie id.