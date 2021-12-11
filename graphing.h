#ifndef UNWEIGHTED_GRAPH
#define UNWEIGHTED_GRAPH

#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <fstream>

namespace nwacc {

	class unweighted_graph {
	private:
		struct vertex
		{
			char label;

			bool was_visited;


			vertex(char new_label, bool is_visited) : label{ new_label },
				was_visited{ is_visited } {}

			vertex() : label{ 0 }, was_visited{ false } {}

		};



		vertex* vertices;
		size_t number_of_vertices;

		int** matrix;


	public:



		unweighted_graph(const size_t size)
		{
			this->number_of_vertices = size;

			this->matrix = new int* [this->number_of_vertices];
			for (auto index = 0U;
				index < this->number_of_vertices;
				index++)
			{
				this->matrix[index] = new int[this->number_of_vertices];
				for (auto inner_index = 0U;
					inner_index < this->number_of_vertices;
					inner_index++) {
					this->matrix[index][inner_index] = 0;
				}
			}

			this->vertices = new vertex[this->number_of_vertices];
		}

		~unweighted_graph()
		{
			for (auto index = 0U; index < this->number_of_vertices; index++) {
				delete[] this->matrix[index];
			}

			delete[] this->matrix;
			delete[] this->vertices;
		}

		void add_vertex(const char label, const int index)
		{
			this->vertices[index].label = label;
			this->vertices[index].was_visited = false;
		}

		void add_edge(const int start, const int end)
		{
			this->matrix[start][end] = 1;
			this->matrix[end][start] = 1;
		}

		void print(std::ostream& out = std::cout) const
		{
			for (auto row = 0U; row < this->number_of_vertices; row++) {
				for (auto column = 0U; column < this->number_of_vertices; column++) {
					out << this->matrix[row][column] << ' ';
				}

				out << std::endl;
			}
		}



		int get_adjacent_unvisited_vertex(int index)
		{
			for (auto counter = 0U; counter < this->number_of_vertices; counter++) 
			{
				if (this->matrix[index][counter] == 1 && !this->vertices[counter].was_visited)
				{
					return counter;

				} 
			}


			return -1;
		}

		void dfs(std::vector<char>& result)
		{
			result.clear();
			std::stack<int> stack;
			
			stack.push(0);
			this->vertices[0].was_visited = true;
			
			result.push_back(this->vertices[0].label);
			
			while (!stack.empty()) 
			{
				auto next = this->get_adjacent_unvisited_vertex(stack.top());
				if (next < 0)
				{
				
					stack.pop();
				}
				else
				{
					
					this->vertices[next].was_visited = true;
					result.push_back(this->vertices[next].label);
					stack.push(next);
				}
			}

			for (unsigned int i = 0; i < this->number_of_vertices; i++)
			{
				this->vertices[i].was_visited = false;
			}
		}






		bool find_path(std::vector<char>& result, int first, int find)
		{
			

			result.clear();

			std::stack<int> stack;

			stack.push(first);

			this->vertices[first].was_visited = true;

			result.push_back(this->vertices[first].label);

			while (!stack.empty())
			{



				auto next = this->get_adjacent_unvisited_vertex(stack.top());

				if (this->vertices[find].label == this->vertices[next].label)
				{
					return true;
				}

				if (next < 0)
				{

					stack.pop();
				}
				else
				{

					this->vertices[next].was_visited = true;

					result.push_back(this->vertices[next].label);

					stack.push(next);
					

					
					stack.push(next);

				}
			}

			return false;
		};






		void bfs(std::vector<char>& result)
		{
			
			std::queue<int> queue;
			
			this->vertices[0].was_visited = true;
			queue.push(0);

			result.push_back(this->vertices[0].label);

			while (!queue.empty()) {
			
				auto current = queue.front();
				queue.pop(); 
				auto next_index = this->get_adjacent_unvisited_vertex(current);
				while (next_index >= 0) 
				{

					this->vertices[next_index].was_visited = true;

					result.push_back(this->vertices[next_index].label);

					queue.push(next_index);

					next_index = this->get_adjacent_unvisited_vertex(current);
				}
			}
			for (unsigned int i = 0; i < this->number_of_vertices; i++)
			{
				this->vertices[i].was_visited = false;
			}
		}
		
	};
}

#endif

