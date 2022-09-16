#pragma once

#include <string>
#include <vector>
#include <algorithm>

using std::string; 
class Tree {
private:
  char OFFSET_CHAR_TYPE_, LEAF_CHAR_TYPE_;
  string WOOD_STRING_TYPE_, INPUT_MESSAGE_;
  int N_, WIDTH_, TRIANGLE_HEIGHT_;
  
public:
  Tree();
  
  int get_input(string input_message);

  int calculate_offset(int width, int num_tree_parts);
  int calculate_num_stars(int triangle_num, int row_num);

  string create_char_string(char c, int num_char);

  void print_leaves(int n, int width, int triangle_height,
                    char offset_char_type,char leaf_char_type);
  void print_triangle(int triangle_num, int width, int triangle_height,
                      char offset_char_type, char leaf_char_type);
  void print_leaf_row(int offset, int num_stars, char offset_char_type,
                      char leaf_char_type);
  void print_trunk(int n, int width, char offset_char_type, string wood_string_type);
  void print_trunk_row(int n, int width, char offset_char_type,
                       string wood_char_type);
  void print_tree(int n, int width, int triangle_height, char offset_char_type,
                  char leaf_char_type, string wood_string_type);

  char getOffsetCharType();

  char getLeafCharType();

  string getWoodStringType();
  
  int getN();

  int getWidth();

  int getTriangleHeight();
};



