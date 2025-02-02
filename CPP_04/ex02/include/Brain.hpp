#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	private:
			std::string ideas[100];

	public:
		//Constructors & destructors
			Brain(void);
			Brain(Brain const &copy);
			virtual ~Brain(void);
		
		//Operators
			Brain &operator=(Brain const &copy);
		
		//getters & setters
			std::string			getIdea(int i) const;
			void				setIdeas(int i, std::string const &idea);
};

#endif