#include <cmath>
#include <limits>
#include <iostream>
#include <compare>
using namespace std;


void cast_test(){
  float myFloat = 3.14f;
  // cast의 세 가지 방법
  int i1 = (int)myFloat; // 많이 사용하지만 피해야 할 방법
  int i2 = int(myFloat);  // 거의 사용하지 않는 방법
  int i3 = static_cast<int>(myFloat); // 권장하는 방식
}


void number_test(){
  double number = 0.0 / 0.0;
  if(std::isnan(number)){
    cout << "0 / 0 is : NaN" << endl;
  }
  else{
    cout << "0 / 0 is : not NaN / " << number << endl;
  }


  if(std::isinf(number)){
    cout << "0 / 0 is : inf" << endl;
  }
  else{
    cout << "0 / 0 is : not inf / " << number << endl;
  }


  // 무한대를 직접 생성
  double inf = numeric_limits<double>::infinity();
  cout << "numeric_limits<double>::infinity is : " << inf << endl;
}


void enumerate_type_test(){
  const int PieceTypeKing = 0;
  const int PieceTypeQueen = 1;
  const int PieceTypeRook = 2;
  const int PieceTypePawn = 3;
  // 기타
  int myPiece = PieceTypeKing;
  myPiece += 1; // 프로그램 망가짐
}


void strongly_typed_enumeration_type_test(){
  // 변수에 지정할 수 있는 값의 범위를 엄격하게 제한하여 이러한 문제를 방지한다
  // 기본적으로 열거 타입은 int로 지정되지만, 다음과 같이 내부 표현 타입을 다음 타입으로 바꿀 수 있다.
  enum class PieceType : unsigned long{
    King = 1,
    Queen, // 2
    Rook = 10,
    Pawn // 11
  }; // enum class 정의
  
  PieceType piece = PieceType::King;

  // 열거 타입의 값이 내부적으로 정수로 표현한다고 해서, 자동으로 정수로 변환되지는 않는다.
  // ERROR! (no operator "==" matches these operandsC/C++(349))
  // if(PieceType::Queen == 2) { ... }

  // enum class로 정의한 열거 타입 값의 스코프(scope, 유효 범위)는 자동으로 확장되지 않는다.
  // 상위 스코프에 똑같은 이름이 있어도 충돌하지 않는다.
  // 따라서 서로 다른 열거 타입에 동일한 이름의 멤버가 존재할 수 있다,
  enum class State { Unknown, Started, Finished };
  enum class Error { None, BadInput, DiskFull, Unknown };
}


// 1.1.7 구조체 (struct)
// 모듈 인터페이스 파일에 구조체를 정의할 수 있다. employee.cppm



// 1.1.8 조건문
// if/else문
// if의 초기자 : if문 안에 초기자를 넣을 수 있다.
/*
if(<초기자>; <조건문>){
  <if 본문>
}
  ...
*/



// 2. switch문 : switch문에서 break문이 없다면 다음의 case문도
// 계속해서 실행하는데 이렇게 실행되는 것을 폴 스루 fallthrough(흘려보내기)라고 한다.




void switch_fallthrough(){
  enum class Mode { Default, Custom, Standard };


  int value = 42;
  Mode mode = Mode::Default; // 초기화 추가
  switch (mode) {
    using enum Mode;
    case Custom:
      value = 84;
      /*
      fall through를 의도적으로 발생한 후에 컴파일러가 경고 메시지를 
      발생시키지 않기를 원한다면 [[fallthrough]] 어트리뷰트를 지정해서
      컴파일러에게 알려줄 수 있다.
      */
      [[fallthrough]];  // 세미콜론 추가
    case Standard:
    case Default:
      // 작업 수행
      break;
  }
}


// 1.1.10 논리 연산자
// cpp은 논리 표현식을 평가할 때 단락 논리(short-circuit logic) (축약 논리)를 사용한다.
// 표현식을 평가하는 도중에 최종 결과가 나오면 나머지 부분은 판단하지 않는다.
void short_circuit_logic(){
  bool bool1 = true;
  bool bool2 = false;
  int i = 1;
  // (bool1 || 이후는 평가하지 않는다. (i++)
  bool result = (bool1 || bool2 || (i++ > 7) < 2);
  cout << i << endl;
}


// 1.1.11 3방향 비교 연산자
// three-way comparison operator는 두 값의 순서를 결정하는데 사용된다.
// 이 연산자는 주어진 표현식의 평가 결과가 비교 대상이 되는 값과 같은지 아니면 그보다 작은지 알려준다.
// 이 연산자는 true나 false가 아닌 세 가지 결과 중 하나를 알려줘야 하기 때문에 bool 타입을 리턴할 수 없다.
/*
피연산자가 정수 타입이면 강한 순서 (strong ordering)이라고 부르고 세 가지 중 하나가 된다.
strong_ordering::less:
strong_ordering::greater:
strong_ordering::equal:

부동소수점 타입이면 부분 순서가 된다.
partial_ordering::less: - 첫 번째 피연산자가 두 전째 피연산자보다 작다
partial_ordering::greater: - 첫 번째 피연산자가 두 번째 피연산자보다 크다
partial_ordering::equivalent: - 두 피연산자가 같다.
partial_ordering::unordered: - 두 피연산자 중 하나는 숫자가 아니다.
*/

void strong_ordering_test(){
  int i = 0;
  strong_ordering result =  (i <=> 0);
  if(result == strong_ordering::less) { cout << "less" << endl; }
  if(result == strong_ordering::greater) { cout << "greater" << endl; }
  if(result == strong_ordering::equal) { cout << "equal" << endl; }
}

// 1.1.13 어트리뷰트
void attribute_test(){
  // nodiscard 어트리뷰트는 어떤 값을 리턴하는 함수에 대해 지정할 수 있다.
  // 컴파일러는 이 함수가 호출될 때 리턴값에 아무 작업을 하지 않으면 경고 메시지를 출력한다.
  [[nodiscard]] int func(){ 
    return 42;
  }
  int test_main(){
    ;
    // func();
  }

  // maybe_unused 어트리뷰트는 뭔가 사용하지 않았을 때 컴파일러 경고 메시지를 출력하지 않게 할 수 있다.
  int func2(int param1, [[maybe_unused]] int param2){
    // 컴파일러 경고 수준을 높게 설정할 경우, param2를 사용하지 않으면 경고 메시지를 출력한다.
    // 이러한 경고 메시지를 출력하지 않게 해줄 수 있다.
    return 42;
  }
}

void array_test(){
  // 1.1.13 C 스타일 배열
  // array는 같은 타입의 값을 연달아 저장하고, 각 값은 배열에서 해당 위치를 이용해 접근한다.
  // C++에서 배열을 
  int myArray[3];
  myArray[0] = 0;
  myArray[1] = 0;
  myArray[2] = 0; // 각 원소를 초기화

  // C++에서 배열을 선언할 때는 반드시 배열의 크기를 지정해야 하는데, 변수로 지정할 수는 없고
  // 반드시 상수 또는 상수 표현식 (constexpr)으로 지정해야 한다.
  
  // 영 초기화 구문으로 한 번에 초기화해도 된다.
  int myArray1[3] = {0};
  // 0은 생략해도 된다.
  int myArray2[3] = {};
  // 등호를 생략할 수도 있다.
  int myArray3[3] {};

  // 초기화 리스트를 사용하고, 배열의 크기를 컴파일러를 알아서 결정하도록 해도 된다.
  int myArray4[] = {1,2,3,4};
  // 초기화 리스트에 나온 원소의 개수가 배열의 크기로 지정한 수보다 적으면 나머지 원소는 0을 초기화된다.
  int myArray5[3] = { 2 };

  // 스택 기반의 C 스타일 배열의 크기는 std::size() 함수로 구할 수 있다. <array> 헤더를 인클루드해야 한다.
  // <cstddev>에 정의된 부호 없는 정수 타입인 size_t값을 리턴한다.
  size_t arraySize = std::size(myArray);

  // sizeof 연산자는 인수로 지정한 대상의 크기를 바이트 단위로 리턴한다.
  // 스택 기반 배열에 담긴 원소의 개수를 알아내려면 이 연산자가 리턴한 값을 첫 번째 원소의 크기로 나눠야 한다.
  size_t arraySize2 = std::sizeof(myArray) / std::sizeof(myArray[0]);

  // 1.1.15 std::array
  array<int, 3> arr {9,8,7};
  cout << "Array size = " << arr.size() << endl;
  cout << "Array size = " << arr[1] << endl;

  // C++은 CTAD (class template argument deduction, 클래스 템플릿 인수 추론)이라는 기능을 제공한다.
  // CTAD는 초기자를 사용할 때만 사용한다.
  // std::array에서 이 기능을 제공하면 앞에 나온 배열을 다음과 같이 적용할 수 있다.
  array arr = {9,8,7};
}



int main(){
  // cast_test();
  // short_circuit_logic();
  strong_ordering_test();
}
