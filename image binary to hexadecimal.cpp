#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {

  // Create a file object for the HEX file
  fstream hex_file("image.hex", ios::out | ios::binary);

  // Open the TXT file
  fstream txt_file("image.txt", ios::in | ios::binary);

  // Read the TXT file and convert its binary data to hexadecimal
  vector<unsigned char> txt_data;
  while (true) {
    unsigned char byte;
    txt_file.read((char *) &byte, sizeof(byte));
    if (txt_file.eof()) {
      break;
    }
    txt_data.push_back(byte);
  }

  // Write the hexadecimal data of the TXT file to the HEX file
  for (unsigned char byte : txt_data) {
    hex_file << std::hex << std::setw(2) << std::setfill('0') << (int)byte << " ";
  }

  // Close the files
  txt_file.close();
  hex_file.close();

  // Display a success message
  cout << "The TXT file has been converted to hexadecimal and stored in the HEX file." << endl;

  return 0;
}
