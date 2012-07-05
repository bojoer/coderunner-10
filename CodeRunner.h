/* 
 * File:   Compiler.h
 * Author: along
 *
 * Created on 2012年5月4日, 下午12:14
 */

#ifndef COMPILER_H
#define	COMPILER_H

#include <map>
#include <string>
#include "gen-cpp/CodeRunner.h"
using namespace std;

struct Judge {
    const char * language;
    const char * file;
    const char * compile[20];
    const char * run[20];
}; 

class CodeRunner : virtual public CodeRunnerIf {
    
public:
    CodeRunner(const string& path);
    ~CodeRunner();

public:
    
    int compile(const CodePizza& piece);    
    void run(RunResult& _return, const CodePizza& pizza, const int32_t userid);
    
private:
    
    string createSafePath();
    void removeSafePath(const string& path);    
    void attachCode(const CodePizza& piece);
    
    int doCompile(const string& path, const CodePizza& piece);    

    void setCompileLimit();
    void setRunLimit();
    
    int waitRun(int pid, Judge * judge);
    
    string getFileContent(const string& file);
    Judge * getJudge(const string& language);


    string _path;
};

#endif	/* COMPILER_H */

