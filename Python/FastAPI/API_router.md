### `APIRouter` — FastAPI Quick Revision

`APIRouter` lets you **split a large FastAPI app into smaller modules** instead of putting every endpoint in one file.

---

## Basic Example

```python
from fastapi import APIRouter

router = APIRouter()

@router.get("/users")
def get_users():
    return {"users": []}
```

Main app:

```python
from fastapi import FastAPI
from users import router

app = FastAPI()

app.include_router(router)
```

---

## Common Parameters

### `prefix`

Adds a common path to every route.

```python
router = APIRouter(prefix="/users")

@router.get("/")
def get_users():
    return []

@router.get("/{user_id}")
def get_user(user_id: int):
    return {"id": user_id}
```

Routes become:

```
GET /users/
GET /users/{user_id}
```

---

### `tags`

Groups endpoints in Swagger UI.

```python
router = APIRouter(
    prefix="/users",
    tags=["Users"]
)
```

---

### `dependencies`

Applies dependencies to **every endpoint**.

```python
from fastapi import Depends

router = APIRouter(
    dependencies=[Depends(get_current_user)]
)
```

No need to repeat `Depends()` in each route.

---

### `responses`

Default responses for all routes.

```python
router = APIRouter(
    responses={404: {"description": "Not found"}}
)
```

---

## Including a Router

```python
app.include_router(router)
```

With prefix:

```python
app.include_router(
    router,
    prefix="/api/v1"
)
```

Final URL:

```
/api/v1/users
```

---

## Multiple Routers

```
app/
│
├── main.py
├── routers/
│   ├── users.py
│   ├── items.py
│   └── auth.py
```

```python
app.include_router(users.router)
app.include_router(items.router)
app.include_router(auth.router)
```

---

## Nested Prefixes

Router:

```python
router = APIRouter(prefix="/users")
```

App:

```python
app.include_router(router, prefix="/api")
```

Final route:

```
/api/users
```

---

## Router-Level Dependency

```python
router = APIRouter(
    prefix="/admin",
    dependencies=[Depends(is_admin)]
)
```

Every `/admin/*` endpoint requires `is_admin`.

---

## Cheat Sheet

| Syntax                                      | Purpose                              |
| ------------------------------------------- | ------------------------------------ |
| `APIRouter()`                               | Create a router                      |
| `prefix="/users"`                           | Common URL prefix                    |
| `tags=["Users"]`                            | Swagger grouping                     |
| `dependencies=[Depends(...)]`               | Apply dependency to all routes       |
| `responses={404: {...}}`                    | Default responses                    |
| `app.include_router(router)`                | Register router                      |
| `app.include_router(router, prefix="/api")` | Add app-level prefix                 |
| Multiple routers                            | Organize large projects into modules |

### Typical project structure

```
app/
├── main.py
├── routers/
│   ├── users.py
│   ├── items.py
│   └── auth.py
├── models/
├── schemas/
├── database.py
└── dependencies.py
```

**Rule of thumb:** Use one `APIRouter` per feature (users, auth, items, orders, etc.), then register them in `main.py` with `app.include_router()`.
