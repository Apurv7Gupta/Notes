## Two ways to define a react component

### function declaration:

```jsx
const CompName = () => {
  return (
    <div></div>
  );
};

export default CompName;
```

#### With multiple functions:

```jsx
const CompName = () => {
  return <div>Hello</div>;
};

const Header = () => {
  return <h1>Header</h1>;
};

const Footer = () => {
  return <footer>Footer</footer>;
};

export default CompName;
export { Header, Footer };
```

import like this: `import CompName, { Header, Footer } from "./MyComponents";`


---

### function declaration with a default export:

```jsx
export default function CompName() {
  return (
    <div>Hello</div>
  );
}
```
