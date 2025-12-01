#include <string>

class Dish {
  private:
    std::string description;

  public:
    Dish() {              // Default constructor; you need this or the program crashes
      description = "";
    }

    Dish(std::string description) {
      this->description = description;
    }

    std::string get_description() {
      return this->description;
    }
};