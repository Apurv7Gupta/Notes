import React from "react";

function PropPractice({ thing, work, perform, color, children }) {
  return (
    <div className="border-2 w-fit">
      <div className={`justify-self-center bg-${color} text-white`}>
        Hey, I am {thing} and I do {work}.
      </div>

      <div className="justify-self-center p-5 m-5">
        <button onClick={perform}>click me to perform a function</button>
      </div>

      <div className="justify-self-center m-5 bg-blue-300">{children}</div>
    </div>
  );
}

export default PropPractice;

/*

import "./App.css";
import PropPractice from "./components/PropPractice";

function App() {
  const performFunction = () => {
    alert("functionPerformed!");
  };

  return (
      <PropPractice
        work="propInjection"
        thing="an element"
        color={"purple-500"}
        perform={performFunction}
        children={<div>this div is injected from app.jsx</div>}
      />
  );
}

export default App;


*/
