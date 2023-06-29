#ifndef SLATE_H
#define SLATE_H

#include "Layer.hpp"
#include <map>
#include <opencv2/opencv.hpp>
#include <stack>
#include <string>

using namespace std;

enum Instruction {
  AddLayer,
  MoveLayer
  // DeleteLayer
  // FlattenLayers
};

struct Action {
  Instruction inst;
  vector<Layer *> affectedLayers;
};

class Slate {
public:
  void exportSlate(string exportDir, std::string name, string fileExtension);
  void addLayer(const char *imagePath = NULL);
  void moveLayer(const int newX, const int newY, const string key);
  void fillLayer(const string key, const int x, const int y, cv::Scalar color);
  void drawLayer(const string key, const int x, const int y, const int rad,
                 cv::Scalar color);
  Layer flattenLayers(vector<Layer *> layers);
  void deleteLayer(const string key);

private:
  int height;
  int width;
  vector<Layer *> layers;
  stack<Action> actionStack;
};

#endif // SLATE_H
