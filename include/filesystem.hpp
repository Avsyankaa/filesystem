// Copyright 2018 Avsyankaa <Avsyankaa@gmail.com>

#ifndef INCLUDE_FILESYSTEM_HPP_
#define INCLUDE_FILESYSTEM_HPP_

#include <boost/filesystem.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <utility>

class Finansial_files {
 public:
  Finansial_files() {};
  void print_list_of_files();
  void print_resulting_data();
  void search_data(boost::filesystem::path);
  void make_resulting_data();

  friend std::vector<std::string> get_vector(Finansial_files f) { 
	  return f.resulting_data;
	  }

  friend std::pair<std::string, std::string> get_vector_element(Finansial_files f, unsigned index) { 
	  return f.finansial_files[index];
  }


 private:
  std::vector<std::pair<std::string, std::string>> finansial_files;
  std::vector<std::string> resulting_data;
  void search_finansial_files(boost::filesystem::path, std::string);
  unsigned make_unsigned_int(std::string);
  std::string give_account(std::string);
};

#endif  // INCLUDE_FILESYSTEM_HPP_
