#include "cube.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

//C Lib
#include <cstdlib>
#include <ctime>


using namespace std;

extern Cube Chandler;

void testapp(int mod) {
    const bool DEBUG = 1; // 1:debug // 0:deploy
    //const int TESTMODULE;
    // 1 : init, print
    // 2 : string to task
    // 3 : Random shuffle function ->c_rsfl
    // 4 : CMD_isValid -> bool CMD_isValid(char c) {
    // 5 : Cube action 

    int TESTMODULE = mod;
    c_init(&Chandler);
    string buf,testbuffer;
    queue<string> tasks;

    //test1 : init, and printer
    if (DEBUG && TESTMODULE == 1) {
        cout << "TEST1 [cube init & print]\n";
        cout << "gogo? (Y/N) : ";
        cin >> testbuffer;
        if(testbuffer == "N" || testbuffer == "n" ) {
            return;
        }
        c_init(&Chandler);
        c_print(&Chandler);
        cout  << endl;
    }
    
    //test2 : c_s2task
    //string to task : UUR -> U,U,R
    else if (DEBUG && TESTMODULE == 2) {
        cout << "TEST2 [string to task converter]\n";
        cout << "insert String : ";
        cin >> testbuffer;
        vector<string> tv = c_s2task(testbuffer);
        for (auto i : tv) {
            cout << i << endl;
        }
    }

    //test 3: Random tasks
    else if (DEBUG && TESTMODULE == 3) {
        cout << "TEST3 [Random tasks Gen] \n";
        cout << "Generate Random tasks? (Y/N) : ";
        if(testbuffer == "N" || testbuffer == "n" ) {
            return;
        }
        cin >> testbuffer;
        vector<string> tv = c_rsfl();
        for (auto i : tv) {
            cout << i << endl;
        }
    }

    //test 4 : CMD_isValid
    else if (DEBUG && TESTMODULE == 4) {
        cout << "TEST4 [CMD_isValid] insert : ";
        cin >> testbuffer;
        if (CMD_isValid(testbuffer)) {
            cout << testbuffer << "is Valid Commad!!" << endl;
        }
        else {
            cout << testbuffer << "..? UNKNOWN cmd....." << endl;
        }
    }

    //test 5 : action, do cube sim core
    else if (DEBUG && TESTMODULE == 5) {
        
        cout << "TEST5 [cube spin test : F R U B L D or +\'(prime=reverse) ]\n";
        cout << "insert string CMD : ";
        cin >> testbuffer;
        if (CMD_isValid(testbuffer)) {
            c_act(&Chandler,testbuffer);
            cout << "  \n\n=====  After spin  ======\n" << endl;
            c_print(&Chandler);
        }
        else {
            cout << "..? UNKNOWN cmd....." << endl;
        }
    }
    else {
        cout << "Test is only 1~5"<<endl;
    }
    
}


void c_init(Cube * handler) {
    cSide* ptr = &(handler->top);
    const char initdata[] = "BWOGYR";
    for (int k = 0; k < 6; k++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                ptr[k][i][j] = initdata[k];
            }
        }
    }

}


void c_print(Cube* handler) {
    //cube print
    //cube_handler
    cSide* csp = &(handler->top);
    const string ADJUSTER = "            ";

    //top
    for (int j = 0; j < 3; j++) {
        cout << ADJUSTER;
        for (int k = 0; k < 3; k++) {
            cout << csp[0][j][k] << ' ';
        }
        cout << '\n';
    }
    cout << endl;
    
    //mid
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <=4 ; j++) {
            for (int k = 0; k < 3; k++) {
                cout << csp[j][i][k] << ' ';
            }
            cout << "  ";
        }
        cout << '\n';
    }
    cout << endl;

    //bot
    for (int j = 0; j < 3; j++) {
        cout << ADJUSTER;
        for (int k = 0; k < 3; k++) {
            cout << csp[5][j][k] << ' ';
        }
        cout << '\n';
    }
    cout << endl;
    
    return;
}


void c_helper(void) {
    cout << "\n\n\n===== Help RubixCube Sim =====\n"<<endl;
    cout << "1) Cube simulator"<<endl;
    cout << "   - Press any key down blow" <<endl;
    cout << "    : <F>   <R>   <U>   <B>   <L>  <D>"<<endl;
    cout << "    : <F'>  <R'>  <U'>  <B'>  <L'>  <D'>"<<endl;
    cout << "    ex) <FRR'U2R> : FRR'UUR"<<endl;
    cout << "\n" <<endl;
    cout << "2) Terminate Program"<<endl;
    cout << "   - Insert : <Q> "<<endl;
    cout << "\n" <<endl;
    cout << "3) Unit Test "<<endl;
    cout << "   - <T1>, <T2>, <T3>, <T4>, <T5>" <<endl;
    cout << "     - T1 : Cube Initialize and print test"<<endl;
    cout << "     - T2 : insert commnad string, and convert to task "<<endl;
    cout << "     - T3 : Random shuffle function "<<endl;
    cout << "     - T4 : Validation check, inserted command from user "<<endl;
    cout << "     - T5 : Cube activation only Single shot"<<endl;
    cout << "\n" <<endl;
    cout << "4) Additional functions" <<endl;
    cout << "   - Random Shuffle : <@>" <<endl;
    cout << "   - Fit all sides : <> ,no insert auto triggered" << endl;
    cout << " \n===== Help End =====  " << endl;
    return;
}


void c_finalize(time_t *startTime, int iter) {
    time_t curTime;
    curTime = time(NULL);
    cout << "\n\n ====== Bye~ Bye~ =====\n";
    cout << "Elapsed time : "<< to_string(curTime-(*startTime))<<endl; 
    cout << "Additional implemented functions : " << endl;
    cout << "\t- Random Shuffle \n\t- Time Display \n\t- Fit all sides"<<endl;
    cout << "Number of operations : " << iter << endl;
    cout << "\n \t< END > \n\n";
    return;
}

bool is_Fitallsides(Cube* handler) {
    cSide* ptr = &(handler->top);
    const char initdata[] = "BWOGYR";
    for (int k = 0; k < 6; k++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if(ptr[k][i][j] != initdata[k]) {
                    return false;
                }
            }
        }
    }
    return true;
}

vector<string> c_rsfl() {
    srand((unsigned int)time(NULL));
    
    vector<string> add_task;//cube random shuffle
    //char sub[] = "FRUBLD";
    string cmdlist[10]= {"R","U","L","B","F'","R'","U'","B'","L'","D'"};  
    int count = rand();
    count = count%7;// 최소 5회~12회의 랜덤 명령어가 입력되도록

    //랜덤값 뽑아서넣어주기
    for (int i = 0; i < 5+count; i++) {
        add_task.push_back(cmdlist[rand()%10]);
    }
    return add_task;
}

vector<string> c_s2task(string s) {
    //FRR'U2R
    int len = s.length();
    vector<string> ret;

    for (int i = 0; i < len; i++) {
        if (s[i + 1] == '\'') {
            //prime case
            if (CMD_isValid(s.substr(i,2))) {
                ret.push_back(s.substr(i, 2));
                i++;
            }
        }
        else if ('0' <= s[i + 1] && s[i + 1] <= '9') {
            //주의 : 한자리 숫자 반복만 지원함.
            string st = s.substr(i, 1);
            bool temp = CMD_isValid(st);
            if (temp) {
                int rep = 0;
                rep = (int)(s[i + 1] - '0');
                for (int i = 0; i < rep; i++) {
                    ret.push_back(st);
                }
                i = i+1;
            }
        }
        else {
            //nomal case
            if(CMD_isValid(s.substr(i, 1))) {
                ret.push_back(s.substr(i, 1));
            }
        }
    }
    return ret;
}

bool CMD_isValid(string cin) {
    const static char CMD_LIST[] = "FRUBLD";//len = 6
    vector<string> CMD_LIST_v {"F\'","R\'","U\'","B\'","L\'","D\'","C!"   };

    if (cin.length() == 1) {
        for (int i = 0; i < 6; i++) {
            if (cin[0] == CMD_LIST[i]) {
                return true;
            }
        }
    }
    else {
        for (int i = 0; i < (int)CMD_LIST_v.size(); i++) {
            if (cin == CMD_LIST_v[i]) {
                return true;
            }
        }
    }
    return false;
}


int c_act(Cube* c,string s) {
    //명령에 따라서 큐브를 실제로 동작시킴
    //"F'","R'","U'","B'","L'","D'",
    char temp[3];
    //char* temp[3];
    //char *ss;
    if (s == "F'") {
        // m4<<bot<<m2<<top
        temp[0] = c->m4[0][0];
        temp[1] = c->m4[1][0];
        temp[2] = c->m4[2][0];
        //
        c->m4[0][0] = c->bot[0][0];
        c->m4[1][0] = c->bot[0][1];
        c->m4[2][0] = c->bot[0][2];
        //
        c->bot[0][0] = c->m2[0][2];
        c->bot[0][1] = c->m2[1][2];
        c->bot[0][2] = c->m2[2][2];
        //
        c->m2[0][2] = c->top[2][0];
        c->m2[1][2] = c->top[2][1];
        c->m2[2][2] = c->top[2][2];
        //
        c->top[2][0] = temp[0];
        c->top[2][1] = temp[1];
        c->top[2][2] = temp[2];
    }
    else if (s == "F") {
        // top<<m2<<bot<<m4
        temp[0] = c->top[2][0];
        temp[1] = c->top[2][1];
        temp[2] = c->top[2][2];
        //
        c->top[2][0] = c->m2[0][2];
        c->top[2][1] = c->m2[1][2];
        c->top[2][2] = c->m2[2][2];
        //
        c->m2[0][2] = c->bot[0][0];
        c->m2[1][2] = c->bot[0][1];
        c->m2[2][2] = c->bot[0][2];
        //
        c->bot[0][0] = c->m4[0][0];
        c->bot[0][1] = c->m4[1][0];
        c->bot[0][2] = c->m4[2][0];
        //
        c->m4[0][0] = temp[0];
        c->m4[1][0] = temp[1];
        c->m4[2][0] = temp[2];
    }
    else if (s == "R'") {
        // top << m3 << bot << m1
        temp[0] = c->top[0][2];
        temp[1] = c->top[1][2];
        temp[2] = c->top[2][2];
        //
        c->top[0][2] = c->m3[0][0];
        c->top[1][2] = c->m3[1][0];
        c->top[2][2] = c->m3[2][0];
        //
        c->m3[0][0] = c->bot[0][2];
        c->m3[1][0] = c->bot[1][2];
        c->m3[2][0] = c->bot[2][2];
        //
        c->bot[0][2] = c->m1[0][2];
        c->bot[1][2] = c->m1[1][2];
        c->bot[2][2] = c->m1[2][2];
        //
        c->m1[0][2] = temp[0];
        c->m1[1][2] = temp[1];
        c->m1[2][2] = temp[2];
        //
    }
    else if (s == "R") {
        // m1 << bot << m3 << top
        temp[0] = c->m1[0][2];
        temp[1] = c->m1[1][2];
        temp[2] = c->m1[2][2];
        //
        c->m1[0][2] = c->bot[0][2];
        c->m1[1][2] = c->bot[1][2];
        c->m1[2][2] = c->bot[2][2];
        //
        c->bot[0][2] = c->m3[0][0];
        c->bot[1][2] = c->m3[1][0];
        c->bot[2][2] = c->m3[2][0];
        //
        c->m3[0][0] = c->top[0][2];
        c->m3[1][0] = c->top[1][2];
        c->m3[2][0] = c->top[2][2];
        //
        c->top[0][2] = temp[0];
        c->top[1][2] = temp[1];
        c->top[2][2] = temp[2];
    }
    else if (s == "U'") {
        // m1 << m2 << m3 << m4
        temp[0] = c->m1[0][0];
        temp[1] = c->m1[0][1];
        temp[2] = c->m1[0][2];
        //
        c->m1[0][0] = c->m2[0][0];
        c->m1[0][1] = c->m2[0][1];
        c->m1[0][2] = c->m2[0][2];
        //
        c->m2[0][0] = c->m3[0][0];
        c->m2[0][1] = c->m3[0][1];
        c->m2[0][2] = c->m3[0][2];
        //
        c->m3[0][0] = c->m4[0][0];
        c->m3[0][1] = c->m4[0][1];
        c->m3[0][2] = c->m4[0][2];
        //
        c->m4[0][0] = temp[0];
        c->m4[0][1] = temp[1];
        c->m4[0][2] = temp[2];
    }
    else if (s == "U") {
        //m4 << m3 << m2 << m1
        temp[0] = c->m4[0][0];
        temp[1] = c->m4[0][1];
        temp[2] = c->m4[0][2];
        //
        c->m4[0][0] = c->m3[0][0];
        c->m4[0][1] = c->m3[0][1];
        c->m4[0][2] = c->m3[0][2];
        //
        c->m3[0][0] = c->m2[0][0];
        c->m3[0][1] = c->m2[0][1];
        c->m3[0][2] = c->m2[0][2];
        //
        c->m2[0][0] = c->m1[0][0];
        c->m2[0][1] = c->m1[0][1];
        c->m2[0][2] = c->m1[0][2];
        //
        c->m1[0][0] = temp[0];
        c->m1[0][1] = temp[1];
        c->m1[0][2] = temp[2];
    }
    else if (s == "B'") {
        // top << m4 << bot << m2
        temp[0] = c->top[0][0];
        temp[1] = c->top[0][1];
        temp[2] = c->top[0][2];
        //
        c->top[0][0] = c->m4[0][2];
        c->top[0][1] = c->m4[1][2];
        c->top[0][2] = c->m4[2][2];
        //
        c->m4[0][2] = c->bot[2][0];
        c->m4[1][2] = c->bot[2][1];
        c->m4[2][2] = c->bot[2][2];
        //
        c->bot[2][0] = c->m2[0][0];
        c->bot[2][1] = c->m2[1][0];
        c->bot[2][2] = c->m2[2][0];
        //
        c->m2[0][0] = temp[0];
        c->m2[1][0] = temp[1];
        c->m2[2][0] = temp[2];
    }
    else if (s == "B") {
        //m2 << bot << m4 << top
        temp[0] = c->m2[0][0];
        temp[1] = c->m2[1][0];
        temp[2] = c->m2[2][0];
        //
        c->m2[0][0] = c->bot[2][0];
        c->m2[1][0] = c->bot[2][1];
        c->m2[2][0] = c->bot[2][2];
        //
        c->bot[2][0] = c->m4[0][2];
        c->bot[2][1] = c->m4[1][2];
        c->bot[2][2] = c->m4[2][2];
        //
        c->m4[0][2] = c->top[0][0];
        c->m4[1][2] = c->top[0][1];
        c->m4[2][2] = c->top[0][2];
        //
        c->top[0][0] = temp[0];
        c->top[0][1] = temp[1];
        c->top[0][2] = temp[2];
    }
    else if (s == "L'") {
        // top << m1 << bot << m3
        temp[0] = c->top[0][0];
        temp[1] = c->top[1][0];
        temp[2] = c->top[2][0];
        //
        c->top[0][0] = c->m1[0][0];
        c->top[1][0] = c->m1[1][0];
        c->top[2][0] = c->m1[2][0];
        //
        c->m1[0][0] = c->bot[0][0];
        c->m1[1][0] = c->bot[1][0];
        c->m1[2][0] = c->bot[2][0];
        //
        c->bot[0][0] = c->m3[0][2];
        c->bot[1][0] = c->m3[1][2];
        c->bot[2][0] = c->m3[2][2];
        //
        c->m3[0][2] = temp[0];
        c->m3[1][2] = temp[1];
        c->m3[2][2] = temp[2];
    }
    else if (s == "L") {
        //m3 << bot << m1 << top
        temp[0] = (c->m3[0][2]);
        temp[1] = c->m3[1][2];
        temp[2] = c->m3[2][2];
        //
        c->m3[0][2] = c->bot[0][0];
        c->m3[1][2] = c->bot[1][0];
        c->m3[2][2] = c->bot[2][0];
        //
        c->bot[0][0] = c->m1[0][0];
        c->bot[1][0] = c->m1[1][0];
        c->bot[2][0] = c->m1[2][0];
        //
        c->m1[0][0] = c->top[0][0];
        c->m1[1][0] = c->top[1][0];
        c->m1[2][0] = c->top[2][0];
        //
        c->top[0][0] = temp[0];
        c->top[1][0] = temp[1];
        c->top[2][0] = temp[2];
        //
    }
    else if (s == "D'") {
        // m1 << m4 << m3 << m2
        temp[0] = c->m1[2][0];
        temp[1] = c->m1[2][1];
        temp[2] = c->m1[2][2];
        //
        c->m1[2][0] = c->m4[2][0];
        c->m1[2][1] = c->m4[2][1];
        c->m1[2][2] = c->m4[2][2];
        //
        c->m4[2][0] = c->m3[2][0];
        c->m4[2][1] = c->m3[2][1];
        c->m4[2][2] = c->m3[2][2];
        //
        c->m3[2][0] = c->m2[2][0];
        c->m3[2][1] = c->m2[2][1];
        c->m3[2][2] = c->m2[2][2];
        //
        c->m2[2][0] = temp[0];
        c->m2[2][1] = temp[1];
        c->m2[2][2] = temp[2];
    }
    else if (s == "D") {
        //m2 << m3 << m4 <<m1
        temp[0] = c->m2[2][0];
        temp[1] = c->m2[2][1];
        temp[2] = c->m2[2][2];
        //
        c->m2[2][0] = c->m3[2][0];
        c->m2[2][1] = c->m3[2][1];
        c->m2[2][2] = c->m3[2][2];
        //
        c->m3[2][0] = c->m4[2][0];
        c->m3[2][1] = c->m4[2][1];
        c->m3[2][2] = c->m4[2][2];
        //
        c->m4[2][0] = c->m1[2][0];
        c->m4[2][1] = c->m1[2][1];
        c->m4[2][2] = c->m1[2][2];
        //
        c->m1[2][0] = temp[0];
        c->m1[2][1] = temp[1];
        c->m1[2][2] = temp[2];
    }
    else if(s == "C") {
        c_print(c);
    }
    else {//drop!
        cout << "unknown : " << s << endl;
    }
    return 0;
}

