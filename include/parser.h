#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include <fstream>        // ofstream
#include <exception>      // std::invalid_argument
#include <iterator>       // std::advance
#include <cassert>
#include <set>

namespace orca
{
  /// @brief Reads a graph from a simple format
  class UndirectedGraphParser
  {
  public:

    auto nb_nodes_declared(){return this->_nb_nodes_declared;}

    auto nb_edges_declared(){return this->_nb_edges_declared;}

    // Transfer the data, invalidates the parser
    auto take_edges() {return std::move(this->_edges);}

    // Parse from stream
    void parse(std::istream& stream)
    {
      read_graph_properties_from(stream);
      this->_edges.resize(this->_nb_edges_declared, std::pair<int,int>(0,0));
      populate_data_from(stream);
    }

    // Parse graph from input file
    void parse(const std::string &input_file)
    {
      std::ifstream stream (input_file);
      if(not stream)
        throw std::invalid_argument("Invalid input file name.");
      parse(stream);
    }

    /// @brief Declare a stream operator
    /// @note Defined in io.h
    friend std::ostream& operator <<(std::ostream& stream, orca::UndirectedGraphParser const& p);

  private:
    // Number of nodes
    int _nb_nodes_declared;
    // Number of edges
    int _nb_edges_declared;
    // Store edges
    std::vector<std::pair<int,int>> _edges;

    ///
    /// @brief Check that node id is valid
    /// @param a first node
    /// @param b second node
    /// @param n number of nodes in the graph
    static void throw_if_node_id_is_invalid(int a, int n)
    {
      // Nodes are unsigned integers
      if ( a < 0 or a > n-1)
        throw std::invalid_argument("Invalid node id:" + std::to_string(a) + " . Node ids should be between 0 and n-1.");
    }

    ///
    /// @brief Nodes are not allowed to be connected to themselves
    /// @param a first node
    /// @param b second node
    static void throw_if_self_loop(int a, int b)
    {
      if (a == b)
        throw std::invalid_argument("Self loop detected on node: " + std::to_string(a));
    }

    ///
    /// @brief Checks that enumerating edges remains consistent with declared number of edges
    static void throw_if_invalid_nb_edges(int current, int declared)
    {
    if(current >= declared)
      throw std::invalid_argument(
        "More nodes being parsed (>" + std::to_string(current) +
        ") than initially declared (" + std::to_string(declared));
    }

    ///
    /// @brief Read the number of nodes and edges from file
    ///
    std::istream& read_graph_properties_from(std::istream& stream)
    {
      stream >> this->_nb_nodes_declared >> this->_nb_edges_declared;
      return stream;
    }

    ///
    /// @brief Fills the data structures reading from file
    ///
    std::istream& populate_data_from(std::istream &stream)
    {
      int a;
      int b;
      int edge_counter = 0;
      while(stream >> a >> b)
      {
        // Preconditions
        throw_if_node_id_is_invalid(a, this->_nb_nodes_declared);
        throw_if_node_id_is_invalid(b, this->_nb_nodes_declared);
        throw_if_self_loop(a,b);
        throw_if_invalid_nb_edges(edge_counter, this->_nb_edges_declared);

        this->_edges[edge_counter] = std::make_pair(a, b);
        edge_counter += 1;
      }
      return stream;
    }
  }; // end OrcaParser

}

#endif
