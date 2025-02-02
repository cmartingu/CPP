#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	std::ofstream	outf;
	std::ifstream	inf;
	std::string		line;
	std::string		full_text;
	int				x;

	if (argc != 4)
	{
		std::cout << "Remember to set 3 argmuents (file, word1, word2)" << std::endl;
		return (1);
	}
	inf.open(argv[1]);
	if (inf.fail())
	{
		std::cout << "Error occurred opening file " << argv[1] << std::endl;
		return (1);
	}
	while (std::getline(inf, line))//tengo todo el texto en full_text
		full_text += line + '\n';
	inf.close();
	outf.open((std::string(argv[1]) + ".replace").c_str());
	if (outf.fail())
	{
		std::cout << "Error opening outfile" << std::endl;
		return (1);
	}
	for (int i = 0; i < (int)full_text.size(); i++)
	{
		x = full_text.find(argv[2], i);
		if (x != -1 && x == i)
		{
			outf << argv[3];
			i += std::string(argv[2]).size() - 1;
		}
		else
			outf << full_text[i];
	}
	outf.close();
	return (0);
}