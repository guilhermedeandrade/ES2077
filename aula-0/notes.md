# Philosophy

## What is ReasonML

- One More Awesome Tool Created By Facebook ™️
- From the React's creator, Jordan Walke
- An OCaml's dialect
- OCaml is a functional languague, super fast, with a highly hackable type inference
- ML Family, Hindley-Milner type system

## Let's talk about the philosophy

"A problem is composable by multiple possibilities/branches. When we don't handle all the possibilities, we usually get what are called bugs."

"A type system doesn't magically eliminate the bugs, but it points to the not handled possibilities and ask you to handle them."

```reason
type schoolPerson = Teacher | Director | Student(string);

let greeting = person =>
  switch (person) {
  | Teacher => "Hey Professor!"
  | Director => "Hello Director."
  | Student("Richard") => "Still here Ricky?"
  | Student(anyOtherName) => "Hey, " ++ anyOtherName ++ "."
  };
```

## How to study Reason

- Before coming in, leave your suppositions at the door
- Records look like JavaScript's objects, but they are way more restrict
- Everything is an expresssion
  - Statements are imperative instructions
  - An expression is everything evaluable or that generates value
- Optional named arguments may confuse you a bit
- There is a difference between int and float
- Strings aren't UTF-16 as in JavaScript
  - "Normal strings"
  - {j|Strings with special characters like áéíóú 😬|j}

In JavaScript, expressions like the following aren't idiomatic and the easiest way of doing them is using an immediately invoked function expression (IIFE)

```js
const Welcome = ({ age }) => {
  <div>
    {(() => {
      const isMinor = age < 18;

      if (isMinor) return "Vaza";
      else return "Oi!";
    })()}
  </div>;
};
```

Since everything is an expression in Reason, we just need a code block to achieve the same result

```reason
  [@react.component]
  let make = (~age) => {
  <div>
    {
      let isMinor = age < 18

      if (isMinor)
        React.string("Vaza!")
      else
        React.string("Oi!")
    }
  </div>
  }
```
