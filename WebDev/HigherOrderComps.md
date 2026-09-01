A **Higher-Order Component (HOC)** in React is a **function that takes a component and returns a new component with additional behavior**.

Think of it as:

> **Component → HOC → Enhanced Component**

### Basic example

```jsx
function withLoading(Component) {
  return function EnhancedComponent({ isLoading, ...props }) {
    if (isLoading) {
      return <p>Loading...</p>;
    }

    return <Component {...props} />;
  };
}
```

You can use it like this:

```jsx
function UserList({ users }) {
  return (
    <ul>
      {users.map(user => (
        <li key={user.id}>{user.name}</li>
      ))}
    </ul>
  );
}

const UserListWithLoading = withLoading(UserList);
```

Then:

```jsx
<UserListWithLoading
  isLoading={false}
  users={[{ id: 1, name: "John" }]}
/>
```

Here:

* `UserList` = original component
* `withLoading` = Higher-Order Component
* `UserListWithLoading` = enhanced component

### Why use HOCs?

HOCs are useful when **multiple components need the same behavior**, such as:

* Authentication checks
* Loading states
* Permissions
* Logging
* Subscribing to data
* Adding common props

For example:

```jsx
function withAuth(Component) {
  return function ProtectedComponent(props) {
    const isLoggedIn = true;

    if (!isLoggedIn) {
      return <p>Please log in.</p>;
    }

    return <Component {...props} />;
  };
}
```

Then:

```jsx
const DashboardWithAuth = withAuth(Dashboard);
```

### Important point

A HOC **doesn't modify the original component**. It creates and returns a new component.

Also, in modern React, **custom hooks are often preferred over HOCs** for sharing logic. HOCs are still important to understand, especially when working with older React codebases and libraries.

**Interview definition:**

> A Higher-Order Component is a function that accepts a React component as an argument and returns a new enhanced component.



### How HOCs help in protected routing

HOCs can be used for **protected routing** by putting the authentication check *before* rendering the protected component.

### Example

Suppose you have a `Dashboard` that only logged-in users should access.

You create an HOC:

```jsx
function withAuth(Component) {
  return function ProtectedComponent(props) {
    const isAuthenticated = localStorage.getItem("token");

    if (!isAuthenticated) {
      return <Navigate to="/login" replace />;
    }

    return <Component {...props} />;
  };
}
```

Then wrap your component:

```jsx
const ProtectedDashboard = withAuth(Dashboard);
```

And use it in your routes:

```jsx
<Routes>
  <Route path="/login" element={<Login />} />

  <Route
    path="/dashboard"
    element={<ProtectedDashboard />}
  />
</Routes>
```

### Result

When the user visits `/dashboard`:

```text
                /dashboard
                     ↓
          ProtectedDashboard
                     ↓
            Is user authenticated?
                 ↙       ↘
               NO         YES
               ↓           ↓
        Navigate /login   Dashboard
```

So the HOC acts like a **security gate** around the component.

### Why `...props`?

This:

```jsx
return <Component {...props} />;
```

passes all the props received by the HOC to the original component.

For example:

```jsx
const Dashboard = ({ username }) => {
  return <h1>Welcome {username}</h1>;
};
```

The HOC can preserve that:

```jsx
return <Component {...props} />;
```

and:

```jsx
<ProtectedDashboard username="John" />
```

will ultimately render:

```text
Welcome John
```

### One important distinction

The HOC protects the **UI route**, but it is **not real security** by itself. A user can potentially manipulate client-side JavaScript or storage. Your backend/API must also verify authentication and authorization.

In **modern React Router**, you can also implement protected routes using a route wrapper/layout rather than an HOC, which is often cleaner.
