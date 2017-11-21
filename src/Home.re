let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Home");

let goTo = (router, url, event) => {
  ReactEventRe.Mouse.preventDefault(event);
  DirectorRe.setRoute(router, url)
};

let make = (~router, _children) => {
  ...component,
  render: (_self) =>
    <div>
      <h1> (str("Home")) </h1>
      <a href="#" onClick=(goTo(router, "/user/4"))> (ReasonReact.stringToElement("User")) </a>
      <br />
      <a href="#" onClick=(goTo(router, "/counter"))> (ReasonReact.stringToElement("Counter")) </a>
    </div>
};
