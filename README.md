# Flyier
A 2d endless runner game where the goal is to get the higheest score possible. 
This is build using entity component system where process such as movement and collision are seperated in to their own classes and assign to classes that need them

audio is from freesound.org


### Problem during development
 - couldn't implement sf::drawable
 I made my custom class inhert sf::drawable so that i could just call window.draw on the class instance. Visual Studio won't regonise that my customs classes had constructors and were looking for the function in sf::drawable.
 Due to this, i spent a lot of developent working with my logic class and my gui as seperate entities which made development way more difficult.
 I evently found a soluation to this, which was to include the deconstruction and put the virtual draw function in private. This seems to fix it but im not sure why.
