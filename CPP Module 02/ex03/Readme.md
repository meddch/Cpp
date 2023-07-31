<!--
	 Point in Polygon for Convex Polygons
A convex polygon is a polygon with all its interior angles less than 180°, which means all the vertices point away from the interior of the polygon.

We discuss this separately as the most common types of polygons encountered in computer vision are convex polygons. Theses includes all triangles, squares, parallelograms, trapezoids, etc.

Algorithm: For a convex polygon, if the sides of the polygon can be considered as a path from any one of the vertex. Then, a query point is said to be inside the polygon if it lies on the same side of all the line segments making up the path. This can be seen in the diagram below.


Point P1 lies inside both the polygons shown above as the P1 is on the same side of all the edges for both the polygons. (source : Author)
To find on which side of the line segment does the point lie, we can simply substitute the point in the equation of the line segment. For example for the line formed by (x1, y1) and (x2, y2), the query point (xp,yp) can be substituted like:

result = (yp - y1) * (x2 -x1) - (xp - x1) * (y2 - y1)
When looking at segment in anticlockwise direction if the result is :

result > 0: Query point lies on left of the line.
result = 0: Query point lies on the line.
result < 0: Query point lies on right of the line.

Reference:
https://towardsdatascience.com/is-the-point-inside-the-polygon-574b86472119
-->