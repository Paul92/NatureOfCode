#About Perlin Random Walker

![Screenshot of random walker](randomWalk.png)

### Description

The random walker is a point that moves a step every few frames in a random
direction. The position of the walker is represented by a black circle
drawn on a FBO in order to be able to store its path.

In this implementation, the step size of the random walker is changed
according to a unidimensional Perlin noise value, in interval 1-100.

The direction is still generated according to a uniforrm random distribution.
