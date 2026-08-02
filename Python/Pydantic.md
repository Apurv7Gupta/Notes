```python
from pydantic import BaseModel, EmailStr, AnyUrl
from typing import Optional


class NickName(BaseModel):
    name: str


class Patient(BaseModel):
    name: str
    age: int
    allergies: list[str]
    contact: dict[str, int]
    additional_details: Optional[str] = None  # this param is optional
    Email: EmailStr
    LinkedIn_url: AnyUrl
    nickname: NickName


# this function param is type-hinted to be a "Patient" object
def insertPatientData(param: Patient):
    print("Inserted!")
    print(param.name)
    print(param.age)
    print(param.allergies)
    print(param.contact)
    print(param.Email)
    print(param.LinkedIn_url)
    print("\n")
    print(param.nickname.name)


# Raw data received from an API
data = {
    "name": "Pork",
    "age": 98,
    "allergies": ["pollen"],
    "contact": {"ph": 123456789},
    "Email": "nickPork@gmail.com",
    "LinkedIn_url": "https://www.linkedin.com/in/apurv7gupta/",
    "nickname": {"name": "nick"},
}

ValidatedData = Patient(**data)  # now this data will be validated against our model

insertPatientData(ValidatedData)
```
