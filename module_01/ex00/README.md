# BraiiiiiiinnnzzzZ

## Requirement

- Implement a Zombie class
  - It has a private string attribute name.
  - Add a member function `void announce (void)` to the Zombie class.
- Zombies announce themselve as follows.
  - `<name>:  BraiiiiiiinnnzzzZ...`
- Do not print the angle brackets (< >).
- Implement the following two functions:
  - `Zombie *newZombie(std::string name)` - This function creates a zombie, names it, and returns it so you can use it outside of the function scope
  - `void randomChump(std::string name)` - This function creates a zombie, names it, and make it announce itself.

- Zombie must destroyed when we don't need them. The destructor must print a message with the name of the zombie for debugging purpose.
> The point of this exercise is, You have to determine in which case it is better to allocate zombies on the stack or the heap.