#include "../Interfaces/Randome.h"

Randome::Randome() : gen(std::random_device{}()) {}

void Randome::randomeX(std::vector<int>& x, const std::vector<int>& exclude)
{
	std::bernoulli_distribution bit(0.5);
	do {
		for (int& value : x)
			value = bit(gen) ? 1 : 0;
	} while (x == exclude); // эталон с ответом «нет» испортил бы обучение
}
