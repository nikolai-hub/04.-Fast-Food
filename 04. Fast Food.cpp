#include<iostream>
#include<queue>
#include<limits>
#include<string>
#include<sstream>
#include<vector>

std::queue<int> readInput() {
	std::queue<int> allOrders;
	std::string line;
	getline(std::cin, line);
	std::istringstream istr(line);
	int currOrder = 0;
	while (istr >> currOrder)
	{
		allOrders.push(currOrder);
	}

	return allOrders;
}

void printBiggestOrder(const std::queue<int>& orders) {
	std::queue<int> ordersCopy = orders;
	int biggestOrder = std::numeric_limits<int>::min();
	while (!ordersCopy.empty())
	{
		const int currNumber = ordersCopy.front();

		if (biggestOrder < currNumber)
		{
			biggestOrder = currNumber;
		}

		ordersCopy.pop();
	}
	std::cout << biggestOrder << std::endl;
}

void servicing(std::queue<int>& orders, int& quantityFood) {
	while (!orders.empty())
	{
		int currOrder = orders.front();
		if (quantityFood - currOrder >= 0)
		{
			quantityFood -= currOrder;
			orders.pop();
		}
		else
		{
			break;
		}
	}
}

void printSolution(std::queue<int>& orders) {
	if (orders.empty())
	{
		std::cout << "Orders complete" << std::endl;
	}
	else
	{
		std::cout << "Orders left: ";
		while (!orders.empty())
		{
			std::cout << orders.front() << ' ';
			orders.pop();
		}
	}
}

int main() {

	int quantityFood = 0;
	std::cin >> quantityFood;
	std::cin.ignore();
	std::queue<int> orders = readInput();
	printBiggestOrder(orders);
	servicing(orders, quantityFood);
	printSolution(orders);

	return 0;
}