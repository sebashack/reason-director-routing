type route =
  | HomeRoute
  | UserRoute(string)
  | CounterRoute;

let router = DirectorRe.makeRouter({"/": "home", "/user/:userID": "user", "/counter": "counter"});

let renderForRoute = (route) => {
  let element =
    switch route {
    | HomeRoute => <Home router />
    | UserRoute(userID) => <User router userID />
    | CounterRoute => <Counter router />
    };
  ReactDOMRe.renderToElementWithId(element, "root")
};

let handlers = {
  "home": () => renderForRoute(HomeRoute),
  "user": (userID: string) => renderForRoute(UserRoute(userID)),
  "counter": () => renderForRoute(CounterRoute)
};

DirectorRe.configure(router, {"html5history": true, "resource": handlers});

DirectorRe.init(router, "/");
