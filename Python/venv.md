```cmd
cd directory
```

Create venv

```cmd
py -3.11 -m venv myvenv
```

activate

```cmd
myvenv\Scripts\activate
```

install from reqs.txt

```cmd
pip install -r requirements.txt
```

### Creating a virtual environment doesn't automatically make VS Code use it.

Method 1 (recommended)

Press `Ctrl + Shift + P`

Type `Python: Select Interpreter`

Choose the interpreter that points to your venv:

`.\myvenv\Scripts\python.exe`
