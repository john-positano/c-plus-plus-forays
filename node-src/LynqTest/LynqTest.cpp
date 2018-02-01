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

   class Lyst {
    public:
      Lyst (const v8::FunctionCallbackInfo<v8::Value>& args) {
        Isolate* isolate = Isolate::GetCurrent();
        HandleScope scope(isolate);

        if (!args.IsConstructCall()) {
          isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "@Lyst is a Constructor. Use 'new' to construct a new Lyst.")));
          args.GetReturnValue().SetUndefined();
          return;
        }

        Handle<Object> $this = args.This();
        this->__NODES.push_back(new $$NODE);

        this->$$NODES = Array::New(isolate);
        this->$$ROOTNODE = new $$NODE();

        this->$$addNode = FunctionTemplate::New(isolate);

        $this->SetAccessor(
          String::NewFromUtf8(isolate, "_NODES"),
          [](Local<String> propertyName, const PropertyCallbackInfo<Value>& info) {
            Isolate* isolate = Isolate::GetCurrent();
            HandleScope scope(isolate);
            info.GetReturnValue().Set(Array::New(isolate));
            Local<Array> $$NODES_ARRAY = Array::New(isolate);
            $$NODES_ARRAY->Set(Number::New(isolate, 0), info.Data());
            info.GetReturnValue().Set($$NODES_ARRAY);
          },
          [](Local<String> propertyName, Local<Value> value, const PropertyCallbackInfo<void>& info) {
            Isolate* isolate = Isolate::GetCurrent();
            HandleScope scope(isolate);
            info.GetReturnValue().Set(Boolean::New(isolate, true));
          },
          this->$$ROOTNODE->$$MEMORY
        );

        $this->Set(
          String::NewFromUtf8(isolate, "addNode"),
          this->$$addNode->GetFunction()
        );

        args.GetReturnValue().Set($this);
      };

      void addNode (const v8::FunctionCallbackInfo<v8::Value>& args) {

      };
    private:
      class $$NODE {
        public:
          std::vector<$$NODE*> __NODES;
          std::vector<Handle<Object>> NODES;
          Handle<Array> $$NODES;
          Handle<Object> $$MEMORY;
          $$NODE () {
            Isolate* isolate = Isolate::GetCurrent();
            HandleScope scope(isolate);
            this->$$NODES = Array::New(isolate);

            Local<FunctionTemplate> $$NODE_TEMPLATE = FunctionTemplate::New(
              isolate,
              [](const v8::FunctionCallbackInfo<v8::Value>& args) {

              }
            );
            $$NODE_TEMPLATE->SetClassName(String::NewFromUtf8(isolate, "_NODE"));

            Constructor.Reset(isolate, $$NODE_TEMPLATE->GetFunction());
            this->$$MEMORY = $$NODE_TEMPLATE->GetFunction()->NewInstance();
          };
      };

      std::vector<$$NODE*> __NODES;
      std::vector<Handle<Object>> NODES;

      Handle<Array> $$NODES;
      $$NODE* $$ROOTNODE;
      Handle<FunctionTemplate> $$addNode;
  };

  static void $$init (Handle<Object> exports) {
    Isolate* isolate = exports->GetIsolate();

    Handle<FunctionTemplate> _Lyst_New = FunctionTemplate::New(
      isolate,
      [](const v8::FunctionCallbackInfo<v8::Value>& args) {
        Lyst* _Lyst = new Lyst(args);
      }
    );

    _Lyst_New->SetClassName(String::NewFromUtf8(isolate, "Lyst"));
    _Lyst_New->InstanceTemplate()->SetInternalFieldCount(1);
    
    Constructor.Reset(isolate, _Lyst_New->GetFunction());
    exports->Set(String::NewFromUtf8(isolate, "Lyst"), _Lyst_New->GetFunction());
  };
};

NODE_MODULE(NODE_GYP_MODULE_NAME, Lynq::$$init)