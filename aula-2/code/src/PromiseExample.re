let usePromise = () => {
  let (message, setMessage) = React.useState(() => "Aguarde..");

  React.useEffect0(() => {
    Promise.resolved("Hello from Promise")
    ->Promise.get(s => setMessage(_ => s));

    None;
  });

  message;
};

[@react.component]
let make = () => {
  let message = usePromise();

  <p> message->React.string </p>;
};
