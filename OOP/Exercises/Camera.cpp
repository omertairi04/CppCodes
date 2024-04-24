#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

class VideoCamera;
class FilmCamera;

class Camera {
protected:
  char manufacturer[20];
  char model[20];
  int yearOfProduction;
  float megaPx;

public:
  Camera() {}

  Camera(Camera &c) {
    strcpy(manufacturer, c.manufacturer);
    strcpy(model, c.model);
    yearOfProduction = c.yearOfProduction;
    megaPx = c.megaPx;
  }

  Camera(char *manufacturer, char *model, int year, float pixels) {
    strcpy(this->manufacturer, manufacturer);
    strcpy(this->model, model);
    yearOfProduction = year;
    megaPx = pixels;
  }

  virtual int price() = 0;
  virtual int rentalPrice(int days) = 0;

  virtual ~Camera() {}
};

class PhotoCamera : public Camera {
  bool supportsRaw;

public:
  PhotoCamera(char *manufacturer, char *model, int year, float pixels,
              bool raw) {
    strcpy(this->manufacturer, manufacturer);
    strcpy(this->model, model);
    yearOfProduction = year;
    megaPx = pixels;
    supportsRaw = raw;
  }

  int price() override {
    int cost = 100 + (megaPx * 20);
    if (supportsRaw) {
      cost += 50;
    }

    return cost;
  }

  int rentalPrice(int days) override {
    int price = 100 + (megaPx * 20);
    int dayCount = 0;
    for (int i = 0; i < days; i++) {
      int price = price * 0.01;
      dayCount++;
    }

    if (dayCount >= 7) {
      price = 100 + (price * 20);
    }

    return price;
  }
};

class VideoCamera : public Camera {
  int maxLength; // seconds

public:
  VideoCamera(char *manufacturer, char *model, int year, float pixels,
              int length) {
    strcpy(this->manufacturer, manufacturer);
    strcpy(this->model, model);
    yearOfProduction = year;
    megaPx = pixels;
    maxLength = length;
  }

  int price() override {
    int cost = megaPx * 80;
    int max = 60 * 60;

    if (maxLength >= max) {
      cost = cost * (40 / 100);
    }

    return cost;
  }

  int rentalPrice(int days) override {
    int price = 100 + (megaPx * 20);
    int dayCount = 0;
    for (int i = 0; i < days; i++) {
      int price = price * 0.01;
      dayCount++;
    }

    if (dayCount >= 7) {
      price = 100 + (price * 20);
    }

    return price;
  }
};

class FilmCamera : public Camera {
  int maxFPS;

public:
  FilmCamera(char *manufacturer, char *model, int year, float pixels, int fps) {
    strcpy(this->manufacturer, manufacturer);
    strcpy(this->model, model);
    yearOfProduction = year;
    megaPx = pixels;
    maxFPS = fps;
  }

  int price() override {
    int cost = 50000;
    if (maxFPS >= 30) {
      for (int i = maxFPS; i != 30; i--) {
        cost += 5000;
      }
    }
    return cost;
  }

  int rentalPrice(int days) override {
    int price = 500;
    if (maxFPS > 60) {
      price += 500;
      for (int i = 0; i < days; i++) {
        price += 1000;
      }
    } else {
      for (int i = 0; i < days; i++) {
        price += 500;
      }
    }
    return price;
  }
};

bool operator<(PhotoCamera &pc, VideoCamera &vc) {
  return pc.price() < vc.price();
}

bool operator<(FilmCamera &fc, PhotoCamera &pc) {
  return fc.price() < pc.price();
}

bool operator<(FilmCamera &fc, VideoCamera &vc) {
  return fc.price() < vc.price();
}

int production(Camera **c, int num, int days) {
  int finalPrice = 0;
  for (int i = 0; i < num; ++i) {
    finalPrice += c[i]->rentalPrice(days);
  }
  return finalPrice;
}

int mostExpensiveCamera(Camera **c, int num) {
  int mostExpensiveIndex = 0; // Initialize with the index of the first camera
  for (int i = 1; i < num; ++i) { // Start from the second camera
    if (c[i]->price() > c[mostExpensiveIndex]->price()) {
      mostExpensiveIndex = i;
    }
  }

  return c[mostExpensiveIndex]->price();
}

int main(int argc, char *argv[]) {
  // Variables for reading input
  char model[20], producer[20];
  int year, length, fps, n;
  float resolution;
  bool raw;

  int t;

  // Array of cameras
  Camera *c[10];

  // Read number of cameras
  cin >> n;

  for (int i = 0; i < n; ++i) {

    // Camera type: 1 - Photo, 2 - Video, 3 - Film
    cin >> t;

    if (t == 1) {
      cin >> producer >> model >> year >> resolution;
      cin >> raw;
      c[i] = new PhotoCamera(producer, model, year, resolution, raw);
    } else if (t == 2) {
      cin >> producer >> model >> year >> resolution;
      cin >> length;
      c[i] = new VideoCamera(producer, model, year, resolution, length);
    } else if (t == 3) {
      cin >> producer >> model >> year >> resolution;
      cin >> fps;
      c[i] = new FilmCamera(producer, model, year, resolution, fps);
    }
  }

  // Production days
  int days;
  cin >> days;

  cout << "\n"
       << "Price of production is: " << production(c, n, days);
  cout << "\n"
       << "Most expensive camera used in production is: "
       << mostExpensiveCamera(c, n);

  return 0;
}
