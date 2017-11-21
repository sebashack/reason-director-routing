type action =
  | Tick;

type state = {
  count: int,
  timerId: ref(option(Js.Global.intervalId))
};

let component = ReasonReact.reducerComponent("Counter");

let make = (_children) => {
  ...component,
  initialState: () => {count: 0, timerId: ref(None)},
  reducer: (action, state) =>
    switch action {
    | Tick => ReasonReact.Update({...state, count: state.count + 1})
    },
  didMount: (self) => {
    self.state.timerId := Some(Js.Global.setInterval(self.reduce((_) => Tick), 1000));
    ReasonReact.NoUpdate
  },
  willUnmount: (self) =>
    switch self.state.timerId.contents {
    | Some(timerId) => Js.Global.clearInterval(timerId)
    | None => ()
    },
  render: ({state}) => <div> (ReasonReact.stringToElement(string_of_int(state.count))) </div>
};
