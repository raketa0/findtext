#include <fstream>
#include <iostream>
#include <locale.h>
#include <optional>
#include <string>
#include <Windows.h>
#include <filesystem>
#include <fcntl.h>
#include <io.h>

const std::string INVALID_ARGUMENT_COUNT = "Invalid argument count\n";
const std::string USAGE = "Usage: findtext.exe <file name> <text to search>\n";
const std::string FAILED_TO_OPEN_FILE = "Failed to open";
const std::string FAILED_TO_READ_FILE = "Failed to read data from input file\n";
const std::string TEXT_NOT_FOUND = "Text not found\n";
int ERROR_INPUT_FILE = 1;
int ERROR_TEXT = 2;
int SUCCESS = 0;

struct Args
{
	std::string inputFileName;
	std::string textToSearch;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 3)
	{
		return std::nullopt;
	}
	Args args;
	args.inputFileName = argv[1];
	args.textToSearch = argv[2];
	return args;
}

int SearchTextInFile(const std::string& fileName, const std::string& searchText)
{
	std::ifstream input(fileName);
	if (!input.is_open())
	{
		std::cout << FAILED_TO_OPEN_FILE << fileName << "' for reading\n";
		return ERROR_INPUT_FILE;
	}

	std::string line;
	int lineNumber = 0;
	bool found = false;

	while (std::getline(input, line))
	{
		lineNumber++;
		if (line.find(searchText) != std::string::npos)
		{
			std::cout << lineNumber << std::endl;
			found = true;
		}
	}

	if (input.bad())
	{
		std::cout << FAILED_TO_READ_FILE;
		return ERROR_INPUT_FILE;
	}
	if (found == false)
	{
		return ERROR_TEXT;
	}
	return SUCCESS;
}

int main(int argc, char* argv[])
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		std::cout << INVALID_ARGUMENT_COUNT;
		std::cout << USAGE;
		return ERROR_INPUT_FILE;
	}

	int found = SearchTextInFile(args->inputFileName, args->textToSearch);

	if (found == ERROR_TEXT)
	{
		std::cout << TEXT_NOT_FOUND;
		return ERROR_INPUT_FILE;
	}
	if (found == ERROR_INPUT_FILE)
	{
		return ERROR_INPUT_FILE;
	}

	return SUCCESS;
}