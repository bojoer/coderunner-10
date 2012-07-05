/* 
 * File:   Compiler.cpp
 * Author: along
 * 
 * Created on 2012年5月4日, 下午12:14
 */

#include <stdio.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <sys/user.h>
#include <sys/ptrace.h>
#include <sys/timeb.h>
#include <sys/stat.h>
#include "CodeRunner.h"
#include <iostream>


#define STD_MB 1024*1024
Judge gJudges[] = {
    {
        "C",
        "main.c",
        {"gcc", "main.c", "-o", "Main", "-O2", "-Wall", "-lm", "--static", "-std=c99", "-DONLINE_JUDGE", NULL},
        {"./Main", NULL}
    },
    {
        "CPP",
        "main.cc",
        {"g++", "main.cc", "-o", "Main", "-O2", "-Wall", "-lm", "--static", "-DONLINE_JUDGE", NULL},
        {"./Main", NULL}
    },
    {
        "PASCAL",
        "main.pas",
        {"fpc", "main.pas", "-O2", "-Co", "-Ct", "-Ci", NULL},
        {"./Main", "./Main", NULL}
    },
    {
        "JAVA",
        "main.java",
        {"javac", "-J-Xms32m", "-J-Xmx256m", "Main.java", NULL},
        {"/usr/bin/java", "-Djava.security.manager", "-Djava.security.policy=./java.policy", "Main", NULL}
    },
    {
        "RUBY",
        "main.rb",
        {"ruby", "-c", "Main.rb", NULL},
        {"/ruby", "Main.rb", NULL}
    },
    {
        "BASH",
        "main.sh",
        {"chmod", "+rx", "Main.sh", NULL},
        {"/bin/bash", "Main.sh", NULL}
    },
    {
        "PYTHON",
        "main.py",
        {"python", "-c", "import py_compile; py_compile.compile(r'Main.py')", NULL},
        {"/python", "Main.py", NULL}
    },
    {
        "PHP",
        "main.php",
        {"php", "-l", "Main.php", NULL},
        {"/php", "Main.php", NULL}
    },
    {
        "PERL",
        "main.pl",
        {"perl", "-c", "Main.pl", NULL},
        {"/perl", "Main.pl", NULL}
    },
    {
        "CSHARP",
        "main.cs",
        {"gmcs", "-warn:0", "Main.cs", NULL},
        {"/mono", "--debug", "Main.exe", NULL}
    },
};

CodeRunner::CodeRunner(const string& path)
: _path(path) {
}

CodeRunner::~CodeRunner() {
}

int CodeRunner::compile(const CodePizza& pizza) {

    string path = createSafePath();
    chdir(path.c_str());

    int status = doCompile(path, pizza);
    removeSafePath(path);

    return status;
}

void CodeRunner::run(RunResult& _return, const CodePizza& pizza, const int32_t userid) {

    string path = createSafePath();
    chdir(path.c_str());

    Judge * judge = getJudge(pizza.lanuage);
    if (judge == NULL)
        return;

    doCompile(path, pizza);
    int pid = fork();
    if (pid == 0) {
        chroot("/home/along/working/wikcode/env"); 

//        ptrace(PTRACE_TRACEME, 0, NULL, NULL);
//        setRunLimit();

        freopen("stdin", "r", stdin);
        freopen("stderr", "w", stderr);
        freopen("stdout", "w", stdout);
        const char **run = judge->run;
        if (run == NULL) {
            exit(1);
        }

        execvp(run[0], (char * const*) run);
        exit(0);
    } else {
//        int status = waitRun(pid, judge);
		int status = 0;
		waitpid(pid, &status, 0);

        _return.ret = status;
        _return.stdout = getFileContent("stdout");
        _return.stderr = getFileContent("stderr");
//        removeSafePath(path);
        return;
    }
}

int CodeRunner::doCompile(const string& path, const CodePizza& pizza) {
    Judge * judge = getJudge(pizza.lanuage);
    if (judge == NULL)
        return 0;

    attachCode(pizza);
    int pid = fork();
    if (pid == 0) {
        chroot("/home/along/working/wikcode/env"); 
        setCompileLimit();

        const char **cp = judge->compile;
        if (cp == NULL) {
            exit(1);
        }

        execvp(cp[0], (char * const*) cp);
        exit(0);
    } else {
		int status = 0; 
		waitpid(pid, &status, 0);

        return status;
    }
}

int CodeRunner::waitRun(int pid, Judge * judge) {

    int status = 0;
    struct rusage ruse;
    struct user_regs_struct reg;
    while (1) {
        wait4(pid, &status, 0, &ruse);

        ptrace(PTRACE_GETREGS, pid, NULL, &reg);
        if (1) {

        }
    }
}

string CodeRunner::createSafePath() {

    struct timeb tp;
    struct tm * tm;

    ftime(&tp);
    tm = localtime(& (tp.time));
    char path[1024];
    sprintf(path, "%s/%04d%02d%02d%02d%02d%02d%03d"
            , _path.c_str()
            , tm->tm_year + 1900
            , tm->tm_mon + 1
            , tm->tm_mday
            , tm->tm_hour
            , tm->tm_min
            , tm->tm_sec
            , tp.millitm);

    mkdir(path, S_IRWXU | S_IRWXG | S_IROTH | S_IWOTH | S_IXOTH);

    return path;
}

void CodeRunner::removeSafePath(const string& path) {

    string cmd = "rm -rf " + path;
    system(cmd.c_str());
}

void CodeRunner::attachCode(const CodePizza& pizza) {

    Judge * judge = getJudge(pizza.lanuage);
    if (judge == NULL)
        return;

    FILE * fp = fopen(judge->file, "w");
    fwrite(pizza.code.c_str(), sizeof (char), pizza.code.length(), fp);
    fclose(fp);
}

string CodeRunner::getFileContent(const string& file) {

    FILE * fp = fopen(file.c_str(), "r");
    if (fp == NULL)
        return "";

    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);

    char* buff = new char[size + 1];
    rewind(fp);
    fread(buff, sizeof (char), size, fp);
    buff[size] = '\0';
    fclose(fp);

    string content = buff;
    delete[] buff;
    return content;
}

Judge * CodeRunner::getJudge(const string& language) {

    for (int i = 0; i < sizeof (gJudges) / sizeof (Judge); ++i) {
        if (language == gJudges[i].language)
            return &gJudges[i];
    }

    return NULL;
}

void CodeRunner::setCompileLimit() {

    struct rlimit LIM;
    LIM.rlim_max = 60;
    LIM.rlim_cur = 60;
    setrlimit(RLIMIT_CPU, &LIM);

    LIM.rlim_max = 60 * STD_MB;
    LIM.rlim_cur = 60 * STD_MB;
    setrlimit(RLIMIT_FSIZE, &LIM);

    LIM.rlim_max = 128 * STD_MB;
    LIM.rlim_cur = 128 * STD_MB;
    setrlimit(RLIMIT_AS, &LIM);
}

void CodeRunner::setRunLimit() {

    struct rlimit LIM;
    LIM.rlim_max = 60;
    LIM.rlim_cur = 60;
    setrlimit(RLIMIT_CPU, &LIM);

    LIM.rlim_max = 60 * STD_MB;
    LIM.rlim_cur = 60 * STD_MB;
    setrlimit(RLIMIT_FSIZE, &LIM);

    LIM.rlim_max = 128 * STD_MB;
    LIM.rlim_cur = 128 * STD_MB;
    setrlimit(RLIMIT_AS, &LIM);

    LIM.rlim_max = 0;
    LIM.rlim_cur = 0;
    setrlimit(RLIMIT_CORE, &LIM);
}
