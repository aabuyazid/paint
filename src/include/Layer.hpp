#ifndef LAYER_H
#define LAYER_H

#include <opencv2/opencv.hpp>
#include <string>

class Layer {
  // Assumes path is valid
public:
  Layer(const char *imagePath) { image = imread(imagePath, cv::IMREAD_COLOR); }
  ~Layer() {}
  Layer(int width, int height, cv::Scalar color = cv::Scalar(0x0, 0x0, 0x0)) {
    image = cv::Mat(height, width, CV_8UC3, color);
  }
  void fill(const int x, const int y, cv::Scalar scalar);
  void draw(const int x, const int y);
  cv::Mat getImage() { return image; }

private:
  // X and Y coordinates refers to the where the position of the top-left pixel
  // is on the slate
  int x; // corresponds to the width axis
  int y; // corresponds to the height axis
  int width;
  int height;
  cv::Mat image;
};

#endif // LAYER_H
