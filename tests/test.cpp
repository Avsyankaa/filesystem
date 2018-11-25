// Copyright 2018 Avsyankaa <Avsyankaa@gmail.com>

#include <gtest/gtest.h>

#include <filesystem.hpp>

TEST(FileSystem, Test1) {
  boost::filesystem::path path_to_ftp(
      "misc\\ftp\\bcs");
  Finansial_files f;
  f.search_data(path_to_ftp);
  std::pair<std::string, std::string> result = get_vector_element(f, 0);
  std::pair<std::string, std::string> expect = {
      "bcs", "balance_00122223_20180901.txt"};
  EXPECT_EQ(result, expect);
}

TEST(FileSystem, Test2) {
  boost::filesystem::path path_to_ftp(
      "lab-05-filesystem-Avsyankaa\\misc\\ftp");
  Finansial_files f;
  f.search_data(path_to_ftp);
  std::pair<std::string, std::string> result = get_vector_element(f, 0);
  std::pair<std::string, std::string> expect = {
      "bcs", "balance_00122223_20180901.txt"};
  EXPECT_EQ(result, expect);
}

TEST(FileSystem, Test3) {
  boost::filesystem::path path_to_ftp(
      "misc\\ftp\\bcs");
  Finansial_files f;
  f.search_data(path_to_ftp);
  f.make_resulting_data();
  std::vector<std::string> result = get_vector(f);
  std::vector<std::string> expect;
  expect.push_back("broker:bcs account:00122223 files:46 lastdate:20181016");
  expect.push_back("broker:bcs account:00123456 files:44 lastdate:20181014");
  expect.push_back("broker:bcs account:00123458 files:48 lastdate:20181018");
  expect.push_back("broker:bcs account:00143456 files:46 lastdate:20181016");
  EXPECT_EQ(result, expect);
}

TEST(FileSystem, Test4) {
  boost::filesystem::path path_to_ftp(
      "misc\\ftp\\ib");
  Finansial_files f;
  f.search_data(path_to_ftp);
  f.make_resulting_data();
  std::vector<std::string> result = get_vector(f);
  std::vector<std::string> expect;
  expect.push_back("broker:ib account:00100001 files:48 lastdate:20181018");
  expect.push_back("broker:ib account:00100002 files:48 lastdate:20181018");
  expect.push_back("broker:ib account:00100003 files:47 lastdate:20181017");
  EXPECT_EQ(result, expect);
}

TEST(FileSystem, Test5) {
  boost::filesystem::path path_to_ftp(
      "misc\\ftp\\otkritie");
  Finansial_files f;
  f.search_data(path_to_ftp);
  f.make_resulting_data();
  std::vector<std::string> result = get_vector(f);
  std::vector<std::string> expect;
  expect.push_back(
      "broker:otkritie account:03934520 files:48 lastdate:20181018");
  expect.push_back(
      "broker:otkritie account:03934523 files:47 lastdate:20181017");
  EXPECT_EQ(result, expect);
}

TEST(FileSystem, Test6) {
  boost::filesystem::path path_to_ftp(
      "misc\\ftp");
  Finansial_files f;
  f.search_data(path_to_ftp);
  f.make_resulting_data();
  std::vector<std::string> result = get_vector(f);
  std::vector<std::string> expect;
  expect.push_back("broker:bcs account:00122223 files:46 lastdate:20181016");
  expect.push_back("broker:bcs account:00123456 files:44 lastdate:20181014");
  expect.push_back("broker:bcs account:00123458 files:48 lastdate:20181018");
  expect.push_back("broker:bcs account:00143456 files:46 lastdate:20181016");
  expect.push_back("broker:ib account:00100001 files:48 lastdate:20181018");
  expect.push_back("broker:ib account:00100002 files:48 lastdate:20181018");
  expect.push_back("broker:ib account:00100003 files:47 lastdate:20181017");
  expect.push_back(
      "broker:otkritie account:03934520 files:48 lastdate:20181018");
  expect.push_back(
      "broker:otkritie account:03934523 files:47 lastdate:20181017");
  EXPECT_EQ(result, expect);
}

TEST(FileSystem, Test7) {
  boost::filesystem::path path_to_ftp(
      "misc\\ftp\\ib");
  Finansial_files f;
  f.search_data(path_to_ftp);
  std::pair<std::string, std::string> result = get_vector_element(f, 0);
  std::pair<std::string, std::string> expect = {
      "ib", "balance_00100001_20180901.txt"};
  EXPECT_EQ(result, expect);
}

TEST(FileSystem, Test9) {
  boost::filesystem::path path_to_ftp(
      "misc\\ftp\\otkritie");
  Finansial_files f;
  f.search_data(path_to_ftp);
  std::pair<std::string, std::string> result = get_vector_element(f, 0);
  std::pair<std::string, std::string> expect = {
      "otkritie", "balance_03934520_20180901.txt"};
  EXPECT_EQ(result, expect);
}
