#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {

  // Create a file object for the image file
  fstream image_file("convertedbmw.jpg", ios::out | ios::binary);

  // Open the HEX file
  fstream hex_file("image.hex", ios::in | ios::binary);

  // Read the HEX file and convert its hexadecimal data to binary
  vector<unsigned char> hex_data;
  while (true) {
    unsigned char byte;
    hex_file >> std::hex >> byte;
    if (hex_file.eof()) {
      break;
    }
    hex_data.push_back(byte);
  }

  // Write the binary data of the HEX file to the image file
  image_file.write((char *) &hex_data[0], hex_data.size());

  // Close the files
  hex_file.close();
  image_file.close();

  // Display a success message
  cout << "The HEX file has been converted to image and stored in the JPG file." << endl;

  return 0;
}
