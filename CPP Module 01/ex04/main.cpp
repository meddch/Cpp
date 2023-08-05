/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 09:22:29 by mechane           #+#    #+#             */
/*   Updated: 2023/08/05 18:06:28 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>


int	main(int ac, char **av)
{

	std::string to_replace;
	std::string	new_str;
	std::string in_file_name;
	std::string out_file_name;
	std::ifstream in_file;
	std::ofstream out_file;
	std::string	line;
	std::size_t found;


	if (ac != 4)
	 return (std::cerr << "Error : Invalid argument ! (./Sedoo <filename> <str_to_replce> <new_str>)\n", 1);
	in_file_name = av[1];
	to_replace = av[2];
	new_str = av[3];
	if (!in_file_name.length() || !new_str.length() || !to_replace.length())
		return (std::cerr << "Error : String must not be empty !\n", 1);
	in_file.open(in_file_name);
	if (!in_file)
		return (std::cerr << "Error : Unable to open input file.\n", 1);
	out_file_name = in_file_name + ".replace";
	out_file.open(out_file_name);
	if (!out_file)
		return (std::cerr << "Error : Unable to create output file.\n",in_file.close(), 1);
	while (std::getline(in_file, line))
	{
		int i = 0;
		while ((found = line.find(to_replace, i * to_replace.length())) != std::string::npos)
		{
			line.erase(found, to_replace.length());
			line.insert(found, new_str);
			i++;
		}
		out_file << line << std::endl;
	}
	in_file.close();
	out_file.close();
}

