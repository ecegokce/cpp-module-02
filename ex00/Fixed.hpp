#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					rawBits;
		static const int	fractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed	&operator=(const Fixed &op);
		~Fixed();

		void	setRawBits(int const raw);
		int		getRawBits(void) const;
};

#endif