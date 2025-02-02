#include "../include/Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Default Brain constructor called" << std::endl;
}

Brain::Brain(Brain const &copy)
{
    std::cout << "Copy Brain constructor called" << std::endl;
    *this = copy;
}

Brain::~Brain(void)
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain   &Brain::operator=(Brain const &copy)
{
    std::cout << "Assignment constructor Brain called" << std::endl;
    if (this != &copy)
        *this = copy;
    return *this;
}

std::string   Brain::getIdea(int i) const
{
    if (i < 100)
       return this->ideas[i];
    else
        return "Remember you cannot save more than 100 ideas per brain";
}

void    Brain::setIdeas(int i, std::string const &idea)
{
    if (i < 100)
        this->ideas[i] = idea;
    else
        std::cout << "You can only save 100 ideas per Brain" << std::endl;
}