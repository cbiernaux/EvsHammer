#include <nan.h>
#include "HammerApi.h"

void Add(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  if (info.Length() < 2) {
    Nan::ThrowTypeError("Wrong number of arguments");
    return;
  }

  if (!info[0]->IsNumber() || !info[1]->IsNumber()) {
    Nan::ThrowTypeError("Wrong arguments");
    return;
  }

  double arg0 = info[0]->NumberValue();
  double arg1 = info[1]->NumberValue();
  v8::Local<v8::Number> num = Nan::New(arg0 + arg1);

  info.GetReturnValue().Set(num);
}

void GetClipDatabase(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  if ((info.Length() < 1) || (info.Length() > 1)) {
    Nan::ThrowTypeError("Wrong number of arguments");
    return;
  }

  if (!info[0]->IsNumber()) {
    Nan::ThrowTypeError("Wrong arguments");
    return;
  }

  int sizeOfData = 0;
  char* clipDatabase = GetClipDatabase(sizeOfData);

  v8::Local<v8::String> v8ClipDatabase = v8::String::New(clipDatabase, sizeOfData);
  v8::Local<v8::Object> obj = Nan::New<v8::Object>();
  obj->Set(Nan::New("msg").ToLocalChecked(), v8ClipDatabase);

  info.GetReturnValue().Set(obj);
}

void Init(v8::Local<v8::Object> exports) {
  exports->Set(Nan::New("Add").ToLocalChecked(),
    Nan::New<v8::FunctionTemplate>(Add)->GetFunction());
  exports->Set(Nan::New("GetClipDatabase").ToLocalChecked(),
    Nan::New<v8::FunctionTemplate>(GetClipDatabase)->GetFunction());
}

NODE_MODULE(EvsHammer, Init)