import { useState } from "react";

function Coutner() {
  const [Value, setValue] = useState(0);

  const increaseCount = () => {
    setValue((prevValue) => prevValue + 1);
  };

  const decreaseCount = () => {
    setValue((c) => Math.max(0, c - 1));
  };
  return (
    <>
      <div className="flex-col justify-center items-center border-2">
        <div className="flex justify-center items-center">
          <button onClick={increaseCount}>+</button>
          <button onClick={decreaseCount}>-</button>
        </div>
        <div className="justify-self-center bg-gray-400 p-5">{Value}</div>
      </div>
    </>
  );
}

export default Coutner;
