/**
 * Autogenerated by Thrift Compiler (0.7.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 */
#ifndef CodeRunner_H
#define CodeRunner_H

#include <TProcessor.h>
#include "CodeRunner_types.h"



class CodeRunnerIf {
 public:
  virtual ~CodeRunnerIf() {}
  virtual void run(RunResult& _return, const CodePizza& pizza, const int32_t userid) = 0;
};

class CodeRunnerNull : virtual public CodeRunnerIf {
 public:
  virtual ~CodeRunnerNull() {}
  void run(RunResult& /* _return */, const CodePizza& /* pizza */, const int32_t /* userid */) {
    return;
  }
};

typedef struct _CodeRunner_run_args__isset {
  _CodeRunner_run_args__isset() : pizza(false), userid(false) {}
  bool pizza;
  bool userid;
} _CodeRunner_run_args__isset;

class CodeRunner_run_args {
 public:

  CodeRunner_run_args() : userid(0) {
  }

  virtual ~CodeRunner_run_args() throw() {}

  CodePizza pizza;
  int32_t userid;

  _CodeRunner_run_args__isset __isset;

  void __set_pizza(const CodePizza& val) {
    pizza = val;
  }

  void __set_userid(const int32_t val) {
    userid = val;
  }

  bool operator == (const CodeRunner_run_args & rhs) const
  {
    if (!(pizza == rhs.pizza))
      return false;
    if (!(userid == rhs.userid))
      return false;
    return true;
  }
  bool operator != (const CodeRunner_run_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const CodeRunner_run_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class CodeRunner_run_pargs {
 public:


  virtual ~CodeRunner_run_pargs() throw() {}

  const CodePizza* pizza;
  const int32_t* userid;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _CodeRunner_run_result__isset {
  _CodeRunner_run_result__isset() : success(false) {}
  bool success;
} _CodeRunner_run_result__isset;

class CodeRunner_run_result {
 public:

  CodeRunner_run_result() {
  }

  virtual ~CodeRunner_run_result() throw() {}

  RunResult success;

  _CodeRunner_run_result__isset __isset;

  void __set_success(const RunResult& val) {
    success = val;
  }

  bool operator == (const CodeRunner_run_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const CodeRunner_run_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const CodeRunner_run_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _CodeRunner_run_presult__isset {
  _CodeRunner_run_presult__isset() : success(false) {}
  bool success;
} _CodeRunner_run_presult__isset;

class CodeRunner_run_presult {
 public:


  virtual ~CodeRunner_run_presult() throw() {}

  RunResult* success;

  _CodeRunner_run_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class CodeRunnerClient : virtual public CodeRunnerIf {
 public:
  CodeRunnerClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  CodeRunnerClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void run(RunResult& _return, const CodePizza& pizza, const int32_t userid);
  void send_run(const CodePizza& pizza, const int32_t userid);
  void recv_run(RunResult& _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class CodeRunnerProcessor : virtual public ::apache::thrift::TProcessor {
 protected:
  boost::shared_ptr<CodeRunnerIf> iface_;
  virtual bool process_fn(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, std::string& fname, int32_t seqid, void* callContext);
 private:
  std::map<std::string, void (CodeRunnerProcessor::*)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*)> processMap_;
  void process_run(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  CodeRunnerProcessor(boost::shared_ptr<CodeRunnerIf> iface) :
    iface_(iface) {
    processMap_["run"] = &CodeRunnerProcessor::process_run;
  }

  virtual bool process(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot, void* callContext);
  virtual ~CodeRunnerProcessor() {}
};

class CodeRunnerMultiface : virtual public CodeRunnerIf {
 public:
  CodeRunnerMultiface(std::vector<boost::shared_ptr<CodeRunnerIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~CodeRunnerMultiface() {}
 protected:
  std::vector<boost::shared_ptr<CodeRunnerIf> > ifaces_;
  CodeRunnerMultiface() {}
  void add(boost::shared_ptr<CodeRunnerIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void run(RunResult& _return, const CodePizza& pizza, const int32_t userid) {
    size_t sz = ifaces_.size();
    for (size_t i = 0; i < sz; ++i) {
      if (i == sz - 1) {
        ifaces_[i]->run(_return, pizza, userid);
        return;
      } else {
        ifaces_[i]->run(_return, pizza, userid);
      }
    }
  }

};



#endif
