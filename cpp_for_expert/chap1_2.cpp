// #include <cmath>
// #include <limits>
#include <iostream>
#include <optional>
// #include <compare>
#include <vector>
using namespace std;

void vector_test(){
  // C++ 표준 라이브러리는 크기가 고정되지 않은 컨테이너를 다양하게 제공한다.
  // 런타임에 원소를 추가하거나 삭제할 수 있다.
  vector<int> myVector = {11, 22};
  
  myVector.push_back(33);
  myVector.push_back(44);

  cout << myVector[0]  << endl;
}

void pair_test(){
  pair<double, int> myPair = {1.23, 5};
  cout << myPair.first << myPair.second << endl;
}

optional<int> getData(bool giveIt){
  if(giveIt){
    return 42;
  }
  return nullopt; // 또는 그냥 {};
}


void optional_test(){
  // <optional>에 정의된 std::optional은 특정한 타입의 값을 가질 수도 있고 아무 값도 가지 않을 수 있다.
  // optional은 기본적으로 함수 매개변수에 전달된 값이 없을 수도 있는 상황에서 사용된다.
  // 기존에 return 값이 없는 경우를 표현하기 위해 특수한 값들 (nullptr, end(), -1, EOF)을 사용하지 않아도 된다.
  // 함수의 리턴값은 수행 결과의 성공 여부를 나타내는 부울 값으로 표현하고, 실제 결과는 출력용 매개변수를 이용하여 함수의 인수에 전달하는 식으로 작성하지 않아도 된다.

  // optional 타입은 클래스 탬플릿이므로 optional<int>와 같이 실제 타입을 꺾쇠괄호 안에 반드시 지정해야 한다.
  
  // 이렇게 작성한 함수는 다음과 같이 사용한다.
  optional<int> data1 = getData(true);
  optional<int> data2 = getData(false);

  // optional에 값이 있는지 확인하려면 has_value() 메서드를 사용하거나 간단히 다음과 같이 if문을 사용한다.
  cout << "data1.has_value = " << data1.has_value() << endl;
  if(data2){
    cout << "data2 has a value." << endl;
  }

  // optional에 값이 있을 때는 value()나 역참조 연산자로 그 값을 가져올 수 있다.
  cout << "data1.value = " << data1.value() << endl;
  cout << "data1.value = " << *data1 << endl;
  
  // value_or()을 사용하면 optional에 값이 있을 때는 그 값을 리턴하고, 값이 없을 때는 다른 값을 리턴한다.
  cout << "data2.value = " << data2.value_or(0) << endl;
}