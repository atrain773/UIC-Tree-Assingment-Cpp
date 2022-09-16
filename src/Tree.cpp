

#include <stdexcept>
#include <string>
#include <iostream>

#include "../include/Tree.h"

Tree::Tree(){
  OFFSET_CHAR_TYPE_ = ' ';
  LEAF_CHAR_TYPE_ = '*';
  WOOD_STRING_TYPE_ = "|||";
  INPUT_MESSAGE_ = "Please insert a number: ";
  TRIANGLE_HEIGHT_ = 3;
  N_ = get_input(INPUT_MESSAGE_);
  WIDTH_ = 2 *N_ + 3;
}

 char Tree::getOffsetCharType(){
  return OFFSET_CHAR_TYPE_;
}

 char Tree::getLeafCharType(){
  return LEAF_CHAR_TYPE_;
}

 string Tree::getWoodStringType() {
  return WOOD_STRING_TYPE_;
}

int Tree::getN() {
  return N_;
}

int Tree::getWidth(){
  return WIDTH_;
}

int Tree::getTriangleHeight() {
  return TRIANGLE_HEIGHT_;
}

int Tree::get_input(string input_message) {
  int input;
  std::cout << input_message;
  std::cin >> input; 
  return input;
}

int Tree::calculate_offset(int width, int num_tree_parts) {
  return ((width - num_tree_parts) / 2) + 1;
}

int Tree::calculate_num_stars(int triangle_num, int row_num) {
  return 2 * (triangle_num + row_num) + 1;
}

string Tree::create_char_string(char c, int num_char) {
  string char_string;
  for (int i = 0; i  < num_char; ++i) 
    char_string = char_string + c;
  return char_string;
}

void Tree::print_leaves(int n, int width, int triangle_height,
                        char offset_char_type, char leaf_char_type) {
  for (int triangle_num = 0; triangle_num < n; ++triangle_num)
    print_triangle(triangle_num, width, triangle_height,
                   offset_char_type,leaf_char_type);
}

void Tree::print_triangle(int triangle_num, int width, int triangle_height, char offset_char_type, char leaf_char_type) {
  for (int row_in_triangle = 0; row_in_triangle < triangle_height; ++row_in_triangle) {
    int num_stars = calculate_num_stars(triangle_num, row_in_triangle);
    int offset = calculate_offset(width, num_stars);
    print_leaf_row(offset, num_stars, offset_char_type, leaf_char_type);
  }
}

void Tree::print_leaf_row(int offset, int num_stars, char offset_char_type, char leaf_char_type) {
  string offset_string = create_char_string(offset_char_type, offset - 1);
  string star_string = create_char_string(leaf_char_type, num_stars);
  string leaf_row_string = offset_string + star_string;
  std::cout << leaf_row_string << std::endl;
  
}

void Tree::print_trunk(int n, int width, char offset_char_type, string wood_string_type) {
  for (int i = 0; i < 2 * n; ++i)
    print_trunk_row(n, width,offset_char_type, wood_string_type);
}

void Tree::print_trunk_row(int n, int width, char offset_char_type, string wood_string_type) {
  string offset_string = create_char_string(offset_char_type, n);
  string trunk_row_string = offset_string + wood_string_type;
  std::cout << trunk_row_string << std::endl;
}

void Tree::print_tree(int n, int width, int triangle_height, char offset_char_type,
                      char leaf_char_type, string wood_char_type) {
  print_leaves(n, width, triangle_height, offset_char_type, leaf_char_type);
  print_trunk(n, width,offset_char_type, wood_char_type);
}

