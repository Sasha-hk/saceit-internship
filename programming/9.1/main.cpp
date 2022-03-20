#include <iostream>
#include <fstream>
#include <string>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/value.h>
 
using namespace std;
using namespace Json;


const string filename = "db.json";

Json::Value readAndParseDB(string filename) {
  ifstream db(filename);
  Json::Value parsed;
  Json::Reader reader;

  reader.parse(db, parsed);  

  return parsed;
}

void showInterface() {
  cout << endl << "Select action:" << endl;
  cout 
    << "  a - add item" 
    << endl << "  d - delete" 
    << endl << "  f - find" 
    << endl << "  s - show" 
    << endl << "  x - exit"
    << endl << "  u - update"
    << endl;
}

string getInput(string view = "\n > ") {
  string input;
  cout << view;
  getline(cin, input);

  return input;
}

void showDb(Json::Value data) {
  cout << data << endl;
}

void updateJson(Json::Value data) {
  Json::StreamWriterBuilder builder;
  std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
  std::ofstream outputFileStream(filename);
  writer -> write(data, &outputFileStream);  
}

void createRecord(Json::Value parsed) {
  Json::Value newRecord;

  string strID = getInput("Enter store unique id: ");
  int id; 

  stringstream geek(strID);
  geek >> id;

  newRecord["id"] = id;

  newRecord["storeCode"] = getInput("Enter store code: ");

  newRecord["productName"] = getInput("Enter product name: ");

  newRecord["number"] = getInput("Enter number of the products: ");

  newRecord["price"] = getInput("Enter price: ");

  parsed.append(newRecord);

  updateJson(parsed);
}

void deleteByCode(Json::Value parsed) {
  string code = getInput("Enter store code to delete item: ");
  Json::Value updatedData;

  for (int i = 0; i < parsed.size(); i++) {
    if (parsed[i]["storeCode"] != code) {
      updatedData.append(parsed[i]);
    }
  }

  updateJson(updatedData);  
}

void findByCode(Json::Value data) {
  const string code = getInput("Enter store code to find: ");

  for (int i = 0; i < data.size(); i++) {
    if (data[i]["storeCode"] == code) {
      cout << data[i] << endl;
    }
  }
}

void updateByID(Json::Value data) {
  const string strID = getInput("Enter id to update: ");
  int id;
  stringstream geek(strID);
  geek >> id;

  for (int i = 0; i < data.size(); i++) {
    if (data[i]["id"] == id) {
      Json::Value updateRecord;

      updateRecord["id"] = id;

      updateRecord["storeCode"] = getInput(" > Enter store code: ");

      updateRecord["productName"] = getInput(" > Enter product name: ");

      updateRecord["number"] = getInput(" > Enter number of the products: ");

      updateRecord["price"] = getInput(" > Enter price: ");  

      data[i] = updateRecord;

      updateJson(data);

      break;
    }
  }  
}

void handleOption(string option, Json::Value data) {
  if (option.length() > 1) {
    cout << "[!] Enter valid option" << endl;
    return;
  }

  char charOption = option[0];
  switch (charOption) {
    case ('x'):
      exit(0);

    case ('a'):
      createRecord(data);
      break;

    case ('d'):
      deleteByCode(data);
      break;

    case ('f'):
      findByCode(data);
      break;

    case ('s'):
      showDb(data);
      break;

    case ('u'):
      updateByID(data);
      break;

    default:
      cout << "Enter valid option" << endl;
  }
}

void makeSomething() {
  string option = "";

  Json::Value parsed = readAndParseDB(filename);

  while (option != "x") {
    // read and parse db
    Json::Value parsed = readAndParseDB(filename);

    // show options
    showInterface();

    // get input
    option = getInput();

    // handle options
    handleOption(option, parsed);
  }
}

int main() {
  makeSomething();

  return 0;
}

// tu run add -ljsoncpp to compiler
