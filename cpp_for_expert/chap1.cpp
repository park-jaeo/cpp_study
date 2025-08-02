#include <cmath>
#include <limits>
#include <iostream>
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
  enum class PieceType {
    King, Queen, Rook, Pawn
  }; // enum class 정의
  PieceType piece = PieceType::King;

  // 열거 타입의 값이 내부적으로 정수로 표현한다고 해서, 자동으로 정수로 변환되지는 않는다.
  // ERROR! (no operator "==" matches these operandsC/C++(349))
  // if(PieceType::Queen == 2) { ... }

  // 기본적으로 열거 타입은 int로 지정되지만, 다음과 같이 내부 표현 타입을 다음 타입으로 바꿀 수 있다.
  enum class PieceType : unsigned long{
    King = 1,
    Queen, // 2
    Rook = 10,
    Pawn // 11
  };

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
  Mode mode;
  switch (mode) {
    using enum Mode;
    case Custom:
      value = 84;
      /*
      fall through를 의도적으로 발생한 후에 컴파일러가 경고 메시지를 
      발생시키지 않기를 원한다면 [[fallthrough]] 어트리뷰트를 지정해서
      컴파일러에게 알려줄 수 있다.
      */
      [[fallthrough]]
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

int main(){
  // cast_test();
  short_circuit_logic();
}