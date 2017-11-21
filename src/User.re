let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("User");

let goToHome = (router, event) => {
  ReactEventRe.Mouse.preventDefault(event);
  DirectorRe.setRoute(router, "/")
};

let make = (~router, ~userID, _children) => {
  ...component,
  render: (_self) =>
    <div>
      <h1> (str("User " ++ userID)) </h1>
      <a href="#" onClick=(goToHome(router))> (str("Home")) </a>
    </div>
};
