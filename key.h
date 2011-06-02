#include <node.h>
#include <openssl/evp.h>

using namespace v8;
using namespace node;

class Key : public ObjectWrap {
 public:
  static void
    Initialize (v8::Handle<v8::Object> target);
  Handle<Value> KeyLoadPublic(Handle<Value> arg, Local<Object> This);
  Handle<Value> KeyGetRSA();
  void KeyFree();

 protected:

  static Handle<Value>
    New (const Arguments& args);
  static Handle<Value>
    LoadPublic(const Arguments& args);
  static Handle<Value>
    GetRSA(const Arguments& args);
  Key ();
  ~Key ();

 private:

  EVP_PKEY *pkey;

};
