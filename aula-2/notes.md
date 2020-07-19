# Promises fooled you

One thing to notice about promises in JS is that writing a nested `Promise.resolve` will end up flattening everything into a single promise.

```js
Promise.resolve(Promise.resolve(2));
// Promise { <state>: "fulfilled", <value>: 2 }
```

This shouldn't be the expected behavior. We should have nested promises instead!

## A Promise isn't a Monad

Even though they look similar, promises and monads aren't the same. The gist of the misconception is probably because they try to solve a similar problem.

## Two different approaches

The code for this class uses two different approached when dealing with promises.

The first approach was using [bs-let](https://github.com/reasonml-labs/bs-let), which is a PPX (language extension) designed to make _monadic operations_ (think async functions with "await" statements in Javascript if you don't know what a monadic operation is) easy to write and read in ReasonML. Here, an "emulation" of the JavaScript's async was done using `bs-let`:

```reason
module Await = {
  let let_ = (promise, map) => Js.Promise.then_(map, promise);
};

...

let _ = {
  let%Await res = data;

  setMessage(_ => res);

  Js.Promise.resolve();
};
```

The second approach was using [aantron/promise](https://github.com/aantron/promise), which is a lightweight and type-safe binding to JavaScript promises. The usage was really straightforward and considerably close to what would be done using JS.

```reason
...

Promise.resolved("Hello from Promise")
->Promise.get(s => setMessage(_ => s));
```
