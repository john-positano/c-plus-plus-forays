// hello.cpp
#include <v8.h>
#include <node.h>
#include <node_object_wrap.h>
#include <vector>

namespace Lynq {
  using v8::FunctionCallbackInfo;
  using v8::PropertyCallbackInfo;
  using v8::Isolate;
  using v8::Local;
  using v8::Object;
  using v8::ObjectTemplate;
  using v8::Handle;
  using v8::Boolean;
  using v8::EscapableHandleScope;
  using v8::HandleScope;
  using v8::String;
  using v8::Number;
  using v8::Value;
  using v8::Exception;
  using v8::FunctionTemplate;
  using v8::Function;
  using v8::Persistent;
  using v8::Proxy;
  using v8::Context;
  using v8::MaybeLocal;
  using v8::Array;

  v8::Persistent<v8::Function> Constructor;

  class Lyst : public node::ObjectWrap {
    public:
      class $$NODE : public node::ObjectWrap {
        public:
          Handle<Object> $$MEMORY;
          std::vector<$$NODE*> __NODES;
      };

      Lyst (const v8::FunctionCallbackInfo<v8::Value>& args) {
        Isolate* isolate = Isolate::GetCurrent();
        HandleScope scope(isolate);

        $$NODE* $n = new $$NODE();
        this->__NODES.push_back($n);

        if (args.IsConstructCall()) {
          Handle<Object> $self = args.This();
          this->Wrap($self);

          args.GetReturnValue().Set($self);
        } else {
          isolate->ThrowException(
            Exception::TypeError(
              String::NewFromUtf8(
                isolate,
                "@Lyst is a Constructor. Use 'new' to construct a new Lyst."
              )
            )
          );
          args.GetReturnValue().SetUndefined();
        }
      };

      static void $$init (Handle<Object> exports) {
        Isolate* isolate = exports->GetIsolate();

        Handle<FunctionTemplate> _OBJ = FunctionTemplate::New(
          isolate, 
          [$self](const v8::FunctionCallbackInfo<v8::Value>& args) {
            Lyst* _Lyst = new Lyst(args);
            $self;
          }
        );
        Handle<ObjectTemplate> $$NODES_TEMPLATE = ObjectTemplate::New(isolate);

        _OBJ->SetClassName(String::NewFromUtf8(isolate, "Lyst"));
        _OBJ->InstanceTemplate()->SetInternalFieldCount(1);
        
        Constructor.Reset(isolate, _OBJ->GetFunction());

        exports->Set(String::NewFromUtf8(isolate, "Lyst"), _OBJ->GetFunction());
      };

    private:
      Handle<ObjectTemplate> __NODE__TEMPLATE;
      std::vector<$$NODE*> __NODES;
  };

  NODE_MODULE(NODE_GYP_MODULE_NAME, Lyst::$$init)
}