#pragma once
#include <string>
#include <vector>

/* Класс реализует работу с файлами данных (пример и веса). */
class File
{
public:
	/* dataDir — папка, в которой лежат example.txt и weight.txt. */
	explicit File(std::string dataDir);

	/* Читает файл с примером: size сигналов (0/1) и ожидаемый ответ. Бросает исключение при ошибке. */
	void readExample(std::vector<int>& x, bool& ans) const;

	/* Читает веса и порог. Возвращает false, если файла весов ещё нет. Бросает исключение, если файл повреждён. */
	bool readWeight(std::vector<int>& weight, int& lim) const;

	/* Записывает веса и порог в файл. */
	void writeWeight(const std::vector<int>& weight, int lim) const;

private:
	std::string path(const char* name) const;

	std::string dataDir;
};
