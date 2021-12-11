#include "graphing.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>


int main() {

	
	std::string line;
	
	std::string checker;

	std::ifstream myReadFile;
	myReadFile.open("input1.txt");
	


	std::getline(myReadFile, checker);

	std::cout << checker << std::endl;

	int holder = checker.at(0);

	int number = holder - '0';

	int size = number;
	
	nwacc::unweighted_graph graph(number);
	


	unsigned int letter = 0;

	if (myReadFile.is_open()) {
		while (std::getline(myReadFile, line)) {

			


			holder = line.at(0);

			number = holder - '0';

			graph.add_vertex('A' + letter, number);

			letter++;

			for (unsigned int i = 1; i <= line.length()-1 ; i++) {

				int first = line.at(0) - '0';

				int second = line.at(i) - '0';

				//std::cout << first << " " << second << std::endl;

				graph.add_edge(first, second);
			}
			

		}
	}
	myReadFile.close();
	
	graph.print();

	std::ofstream myfile;
	myfile.open("output.txt");
	
	

	
	std::vector<char> dfs_result;
	std::vector<char> bfs_result;
	std::vector<char> path_result;

	myfile << "dfs result" << std::endl;

	graph.dfs(dfs_result);



	for (auto& value : dfs_result) {
		myfile << value << ' ';
	}
	
	myfile << std::endl;


	myfile << "bfs result" << std::endl;

	graph.bfs(bfs_result);
	
	for (auto& value : bfs_result) {
		myfile << value << ' ';
	}
	myfile <<std::endl;
	


	if (dfs_result.size() == size)
	{
		myfile << "graph is connected" << std::endl;

	}
	else
	{
		myfile << "graph is not connected" << std::endl;


	}




	

	if (graph.find_path(path_result, 1, 4) == true)
	{
		myfile << "path between B and D " << std::endl;

		for (auto& value : path_result) {
			myfile << value << ' ';
		}
	}
	else
	{
		myfile << "path not found from B to D " << std::endl;
	}


	myfile.close();










	std::string line1;
	
	std::string checker1;

	std::ifstream myReadFile1;
	myReadFile1.open("input2.txt");
	


	std::getline(myReadFile1, checker1);

	std::cout << checker1 << std::endl;

	int holder1 = checker1.at(0);

	int number1 = holder1 - '0';

	int size1 = number1;
	
	nwacc::unweighted_graph graph1(number1);
	


	unsigned int letter1 = 0;

	if (myReadFile1.is_open()) {
		while (std::getline(myReadFile1, line)) {

			


			holder = line.at(0);

			number = holder - '0';

			graph1.add_vertex('A' + letter1, number);

			letter1++;

			for (unsigned int i = 1; i <= line.length()-1 ; i++) {

				int first = line.at(0) - '0';

				int second = line.at(i) - '0';

				//std::cout << first << " " << second << std::endl;

				graph1.add_edge(first, second);
			}
			

		}
	}
	myReadFile1.close();
	
	graph1.print();

	std::ofstream myfile1;
	myfile1.open("output2.txt");
	
	

	
	std::vector<char> dfs_result1;
	std::vector<char> bfs_result1;
	std::vector<char> path_result1;

	myfile1 << "dfs result" << std::endl;

	graph1.dfs(dfs_result1);



	for (auto& value : dfs_result1) {
		myfile1 << value << ' ';
	}
	
	myfile1 << std::endl;


	myfile1 << "bfs result" << std::endl;

	graph1.bfs(bfs_result1);
	
	for (auto& value : bfs_result1) {
		myfile1 << value << ' ';
	}
	myfile1 <<std::endl;
	


	if (dfs_result1.size() == size1)
	{
		myfile1 << "graph is connected" << std::endl;

	}
	else
	{
		myfile1 << "graph is not connected" << std::endl;


	}




	

	if (graph1.find_path(path_result1, 0, 5) == true)
	{
		myfile1 << "path between A and E " << std::endl;

		for (auto& value : path_result1) {
			myfile1 << value << ' ';
		}
	}
	else
	{
		myfile1 << "path not found from A to F " << std::endl;
	}


	myfile1.close();

}