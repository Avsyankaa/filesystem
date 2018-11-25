// Copyright 2018 Avsyankaa <Avsyankaa@gmail.com>

#include <filesystem.hpp>

int main(int argc, char *argv[]) {
  if (argc != 1) {
    boost::filesystem::path path_to_ftp(argv[1]);
    std::cout << std::endl;
    Finansial_files f;
    f.search_data(path_to_ftp);
    f.print_list_of_files();
    std::cout << std::endl;
    f.print_resulting_data();
  } else {
    boost::filesystem::path current_path(boost::filesystem::current_path());
    std::cout << current_path.filename() << std::endl;
  }
}
