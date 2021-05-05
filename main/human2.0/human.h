#include <string>
  enum humansex {male,female};
  class human
  {
    std::string name;
    humansex sex;
    unsigned old;
    double money;
    bool alive;
    unsigned level;
  public:
    human();
    human(std::string name_i, humansex sex_i, unsigned old_i, double money_i, bool alive_i, unsigned level_i);
    ~human();
    double power();
    friend bool compare(const human &a, const human &b);
    void info(human man);
    human fight();
    human fight(human &man);
  };
