//
// Created by Dao An on 2019-01-05.
//

#include "sample.h"
#include <nan.h>

NAN_METHOD() {
        // Create an instance of V8's String type
        auto message = Nan::New("Hello from C++!").ToLocalChecked();
        // 'info' is a macro's "implicit" parameter - it's a bridge object between C++ and JavaScript runtimes
        // You would use info to both extract the parameters passed to a function as well as set the return value.
        info.GetReturnValue().Set(message);
}

// Module initialization logic
NAN_MODULE_INIT(Initialize) {
        // Export the `Hello` function (equivalent to `export function Hello (...)` in JS)
        NAN_EXPORT(target, Hello);
}

// Create the module called "addon" and initialize it with `Initialize` function (created with NAN_MODULE_INIT macro)
NODE_MODULE(addon, Initialize);