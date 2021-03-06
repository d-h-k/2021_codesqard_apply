# 2021_codesqard_apply
- 2021 codesqard 마스터즈 코스 1차 과제
#
## 1번, 2번, 3번 문제의 코드 실행방법
- 컴파일하는 경우 : main.cpp 를 C++14 이상의 버전에서 컴파일하여 실행
  - 혹은 문제에 해당하는 디렉토리에서 "make" 명령어 입력(단 make유틸리티 설치 필요)
- 개발환경 : Visual Studio 2019
- 테스트환경 : GCC (makefile)
#
## 3번 루빅스 큐브 시뮬레이터 도움말
- ![q3 demo](./img/q3demo.png)
- [데모영상 링크](https://youtu.be/GiEvbsJhUXk) : https://youtu.be/GiEvbsJhUXk
- 프롬프트 명령어
  - Q : 종료기능
  - @ : 무작위 섞기 기능
  - H : 도움말
  - 이외 : 입력받은 문자로 큐브동작, 단 정의되지 않은 명령어는 자동으로 버림
  - T# : 테스트 케이스
    - 1 : 큐브를 초기화하고, 출력하는 함수 확인
    - 2 : string to task 함수 검증
    - 3 : 큐브 무작위 섞기 기능 ->c_rsfl
    - 4 : bool CMD_isValid(char c) 함수 검증
    - 5 : Cube action 
- 주의사항
  - FRRR'UUDD' : 연속된 명령어는 연속해 처리
  - F3R : 한자리 숫자 반복만 지원함.
    - 예를들어 UF22R은 UF2R로 인식하여 UFFR 과 동일하게 처리됩니다.
    

## 이외
- Cpp로는 모든 문제(q1,q2,q3)를 풀었습니다.
- Java로는 q2문제만을 풀었습니다.
