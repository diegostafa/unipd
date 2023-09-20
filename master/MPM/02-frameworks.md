## phonegap/cordova

props
* wraps a web app in a mobile app (interpreted/hybrid)
* os features can be accessed with: webview or cordova plugins
* usually used as the last step to convert a web app
* used through CLI (create, platform add)
* XML configuration
* script are included with cordova.js
* need to check the deviceready event before using it
* plugins are used though events:
    * deviceready, touchstart, touchend etc...

## corona/solar2d

props
* cross compiled framework for mobile game
* made for newbies
* uses events like cordova
* can handle widgets, physics, time
* scenes are handled by the composer library
* scenes have events
* build settings --> platform settings
* config lua --> app settings

lua
* interpreted
* uses tables of objects

## xamarin

props
* cross compiled/interpreted
    * xamarin.ios --> native (ios)
    * xamaring.forms --> interpreted (android/windows)
* uses mvvm and c#
* better for gp developers

## flutter

props
* cross compiled for virtually all platforms
* basic animations
* hot reloading --> state is preserved
* channels are used to communicate with platform specifics
    * binary/string
    * method api
* accessible because widgets enforce it through parameters

dart
* show, hide, lazy libs
* jit and aot

## react native

props
* cross platform framework made by facebook (meta)
* cross compiled (not to web apps)
* branched off react.js
* better for webdevs

components
* every element is a component
* class components --> stateful
* function components --> stateless
* they tracked by the virtual dom
* the real dom updates only what diffs from the virtual dom
* setState() is an async request to update the DOM

redux
* state management library
* handle DOM updates synchronously

