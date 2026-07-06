#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "iostream"

class Brain
{
    private:
        std::string _ideas[100];
        int         _curr_index;

    public:
        Brain(void);
        Brain(const Brain &src);
        ~Brain();
		Brain	&operator=(Brain &brain);
        void    addIdea(std::string idea);
		void    getIdeas(const Brain &src, int size_ideas);
		const std::string    *getIdeaAtIndex(int index) const;
};



#endif