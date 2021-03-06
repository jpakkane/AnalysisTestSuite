#include <functional>
#include <iostream>

std::function<void ()> capture_local_by_reference()
{
  int some_value = 1;

  // some_value won't exist when this function is returned
  return [&some_value](){ std::cout << some_value << '\n'; };
}

int main()
{
  const auto f = capture_local_by_reference();
  f();
}
