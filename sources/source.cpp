// Copyright 2018 Avsyankaa <Avsyankaa@gmail.com>

#include <filesystem.hpp>

void Finansial_files::search_finansial_files(boost::filesystem::path p,
                                             std::string prev) {
  for (const boost::filesystem::directory_entry& x :
       boost::filesystem::directory_iterator{p}) {
    std::string file = x.path().extension().string();
    if (file != ".txt") continue;
    file = x.path().stem().string();

    if (file.size() != 25) continue;
    std::string balance;
    bool count = true;
    for (int i = 0; i < 7; i++) {
      balance += file[i];
    }
    if (balance != "balance") continue;
    if (file[7] != '_') continue;
    for (unsigned i = 8; i < 16; i++) {
      if ((file[i] != '0') && (file[i] != '1') && (file[i] != '2') &&
          (file[i] != '3') && (file[i] != '4') && (file[i] != '5') &&
          (file[i] != '6') && (file[i] != '7') && (file[i] != '8') &&
          (file[i] != '9'))
        count = false;
    }
    if (count == false) continue;
    count = true;
    if (file[16] != '_') continue;
    for (unsigned i = 17; i < file.size(); i++) {
      if ((file[i] != '0') && (file[i] != '1') && (file[i] != '2') &&
          (file[i] != '3') && (file[i] != '4') && (file[i] != '5') &&
          (file[i] != '6') && (file[i] != '7') && (file[i] != '8') &&
          (file[i] != '9'))
        count = false;
    }
    if (count == false) continue;
    std::string result = x.path().filename().string();
    std::pair res = {prev, result};
    finansial_files.push_back(res);
  }
}

void Finansial_files::search_data(boost::filesystem::path p) {
  for (const boost::filesystem::directory_entry& x :
       boost::filesystem::directory_iterator{p}) {
    if (boost::filesystem::is_directory(x)) {
      search_data(x);
      continue;
    }
    if (boost::filesystem::is_symlink(x)) {
      search_data(read_symlink(x));
      continue;
    }
    if (boost::filesystem::is_regular_file(x)) {
      search_finansial_files(p, p.stem().string());
      return;
    }
  }
}

void Finansial_files::print_list_of_files() {
  for (unsigned i = 0; i < finansial_files.size(); i++) {
    std::cout << finansial_files[i].first << " " << finansial_files[i].second
              << std::endl;
  }
}

unsigned Finansial_files::make_unsigned_int(std::string file) {
  std::string date;
  for (unsigned i = 17; i < file.size(); i++) {
    date += file[i];
  }
  return atoi(date.c_str());
}

std::string Finansial_files::give_account(std::string file) {
  std::string account;
  for (unsigned i = 8; i < 16; i++) {
    account += file[i];
  }
  return account;
}

void Finansial_files::make_resulting_data() {
  /*std::string prev = finansial_files[0].first;
  std::string account = give_account(finansial_files[0].second);
  unsigned last = make_unsigned_int(finansial_files[0].second);
  unsigned counter_financial_files = 1;
  unsigned counter = 1;
  while (counter != finansial_files.size()) {
    if (finansial_files[counter].first == prev) {
      if (give_account(finansial_files[counter].second) == account) {
        counter_financial_files++;
        if (last < make_unsigned_int(finansial_files[counter].second))
          last = make_unsigned_int(finansial_files[counter].second);
        counter++;
        continue;
      } else {
        std::string result =
            "broker:" + prev + " " + "account:" + account + " " +
            "files:" + std::to_string(counter_financial_files) + " " +
            "lastdate:" + std::to_string(last);
        resulting_data.push_back(result);
        account = give_account(finansial_files[counter].second);
        last = make_unsigned_int(finansial_files[counter].second);
        counter_financial_files = 1;
        counter++;
        continue;
      }
      std::string result = "broker:" + prev + " " + "account:" + account + " " +
                           "files:" + std::to_string(counter_financial_files) +
                           " " + "lastdate:" + std::to_string(last);
      resulting_data.push_back(result);
    }
    if (finansial_files[counter].first != prev) {
      std::string result = "broker:" + prev + " " + "account:" + account + " " +
                           "files:" + std::to_string(counter_financial_files) +
                           " " + "lastdate:" + std::to_string(last);
      resulting_data.push_back(result);
      prev = finansial_files[counter].first;
      account = give_account(finansial_files[counter].second);
      last = make_unsigned_int(finansial_files[counter].second);
      counter_financial_files = 1;
      counter++;
    }
  }
  std::string result = "broker:" + prev + " " + "account:" + account + " " +
                       "files:" + std::to_string(counter_financial_files) +
                       " " + "lastdate:" + std::to_string(last);
  resulting_data.push_back(result);*/
  std::string broker = finansial_files[0].first;
  std::string account = give_account(finansial_files[0].second);
  unsigned last_day = make_unsigned_int(finansial_files[0].second);
  unsigned counter_financial_files = 1;
  while (true) {
    for (unsigned i = 1; i < finansial_files.size(); i++) {
      if ((finansial_files[i].first == broker) &&
          (give_account(finansial_files[i].second) == account)) {
        counter_financial_files++;
        if (last_day < make_unsigned_int(finansial_files[i].second))
          last_day = make_unsigned_int(finansial_files[i].second);
      }
    }
    bool duration = false;
    while (true) {
      for (unsigned i = 1; i < finansial_files.size(); i++) {
        if ((finansial_files[i].first == broker) &&
            (give_account(finansial_files[i].second) == account)) {
          finansial_files.erase(finansial_files.begin() + i);
          duration = true;
        }
      }
      if (duration == false) break;
      duration = false;
    }
    std::string result = "broker:" + broker + " " + "account:" + account + " " +
                         "files:" + std::to_string(counter_financial_files) +
                         " " + "lastdate:" + std::to_string(last_day);
    resulting_data.push_back(result);
    counter_financial_files = 0;
    if (finansial_files.size() > 1) {
      last_day = make_unsigned_int(finansial_files[1].second);
      account = give_account(finansial_files[1].second);
      broker = finansial_files[1].first;
    } else {break;}
  }
  finansial_files.erase(finansial_files.begin());
}

void Finansial_files::print_resulting_data() {
  make_resulting_data();
  for (unsigned i = 0; i < resulting_data.size(); i++) {
    std::cout << resulting_data[i] << std::endl;
  }
}
