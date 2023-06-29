#include "include/Slate.hpp"
#include <iostream>
#include <stdexcept>
#include <sys/stat.h>

void Slate::exportSlate(std::string exportDir, std::string name,
                        std::string fileExtension) {
  struct stat sb;
  if (stat(exportDir.c_str(), &sb) != 0) { // Does the export directory exist?
    throw new std::invalid_argument("Folder to export image does not exist.");
  }

  std::string fullPath = exportDir + name + fileExtension;
  std::string response;
  if (stat(fullPath.c_str(), &sb) == 0) { // Does the file already exist?

    std::cout << "Do you want to override file " << (name + fileExtension)
              << "? (y/n)  ";
    std::cin >> response;
    while (response != "y" || response != "n") {
      std::cout << std::endl << "Please answer with \"y\" or \"n\".";
      std::cin >> response;
    }
    std::cout << std::endl;
    if (response == "n") {
      std::cout << "Aborting file override." << std::endl;
      return;
    }
  }
  try {
    Layer flattenImage = flattenLayers(layers);
    cv::imwrite(fullPath, image);
  } catch (std::runtime_error &ex) {
    std::cerr << "Exception writing file " << name + fileExtension << " to "
              << exportDir << " " << ex.what() << std::endl;
  }
  std::cout << "File " << name + fileExtension << " saved to directory "
            << exportDir << std::endl;
}
