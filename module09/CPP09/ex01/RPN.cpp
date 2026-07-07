#include "RPN.hpp"

RPN::RPN() {

}

RPN::RPN(const RPN &copy) {
	(void)copy;
}

RPN::~RPN() {

}

RPN	&RPN::operator=(const RPN &copy) {
	(void)copy;
	return (*this);
}

bool	RPN::_rpn_error() {
	while (!this->_stack.empty())
		this->_stack.pop();
	std::cerr << "Error" << std::endl;
	return (false);
}

bool	RPN::rpn(std::string expression) {
	size_t	i = 0;
	int	result = 0, a, b;
	while (i < expression.length()) {
		if (expression[i] <= '9' && expression[i] >= '0') {
			this->_stack.push(static_cast<int>(expression[i] - '0'));
		} else {
			if (this->_stack.size() < 2)
				return (this->_rpn_error());
			b = this->_stack.top();
			this->_stack.pop();
			a = this->_stack.top();
			this->_stack.pop();
			switch (expression[i]) {
				case '+':
					result = a + b;
					break;
				case '-':
					result = a - b;
					break;
				case '*':
					result = a * b;
					break;
				case '/':
					if (b == 0)
						return (this->_rpn_error());
					result = a / b;
					break;
				default:
					return (this->_rpn_error());
			}
			this->_stack.push(result);
		}
		++i;
		if (i == expression.length()) {
			if (this->_stack.size() != 1)
				return (this->_rpn_error());
			result = this->_stack.top();
			this->_stack.pop();
			std::cout << result << std::endl;
			return (true);
		} else if (expression[i] != ' ')
			return (this->_rpn_error());
		++i;
	}
	return (this->_rpn_error());
}
