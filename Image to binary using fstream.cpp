
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
  fstream txt_file("image.txt", ios::out | ios::binary);

  fstream image_file("bmw.jpg", ios::in | ios::binary);

  // Read the JPEG image and store its binary data in a vector
  vector<unsigned char> image_data;
  while (true) {
    unsigned char byte;
    image_file.read((char *) &byte, sizeof(byte));
    if (image_file.eof()) {
      break;
    }
    image_data.push_back(byte);
  }

  // Write the binary data of the JPEG image to the TXT file
  for (unsigned char byte : image_data) {
    txt_file.write((char *) &byte, sizeof(byte));
  }

  image_file.close();
  txt_file.close();

  // Display a success message
  cout << "The JPEG image has been uploaded and its binary data has been stored in the TXT file." << endl;

  return 0;
}
