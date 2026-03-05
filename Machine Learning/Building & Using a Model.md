### Model

In supervised learning, a model is the complex collection of numbers that define the mathematical relationship from specific input feature patterns to specific output label values. The model discovers these patterns through training.

## Dropping missing values for table

```python
melbourne_data = melbourne_data.dropna(axis=0)  # na = not available 
```

## Selecting The Prediction Target

```python
y = melbourne_data.Price #This single column is stored in a Pandas Series
						# y is the prediction target now
```

## Selecting Features

The columns that are inputted into our model (and later used to make predictions) are called "features".

```python
melbourne_features = ['Rooms', 'Bathroom', 'Landsize', 'Lattitude', 'Longtitude']

# Defining a list of column names to isolate specific features from the larger dataset

X = melbourne_data[melbourne_features]

# Using bracket notation with a list of column names inside (`DataFrame[list_of_columns]`) returns a new DataFrame with only those columns.

# X is a new DataFrame that now has the selected features (columns) that we are going to predict the prices from

X.head()           # Viewing the first 5 rows of the selected features to check if                      everything is allright

```

In pandas, the `head()` method returns the first n rows of a DataFrame or Series. By default, if no argument is passed, it returns the first 5 rows. This method is commonly used to quickly preview the beginning of a dataset to understand its structure and content without printing the entire dataset.

---

# Building Your Model

You will use the **scikit-learn** library to create your models.

The steps to building and using a model are:

- **Define:** What type of model will it be? A decision tree? Some other type of model? Some other parameters of the model type are specified too.
- **Fit:** Capture patterns from provided data. This is the heart of modeling.
- **Predict:** Just what it sounds like
- **Evaluate**: Determine how accurate the model's predictions are.

Here is an example of defining a decision tree model with scikit-learn and fitting it with the features and target variable:

```python
from sklearn.tree import DecisionTreeRegressor

# Define model. Specify a number for random_state to ensure same results each run
melbourne_model = DecisionTreeRegressor(random_state=1)

# Many machine learning models allow some randomness in model training. Specifying a number for `random_state` ensures you get the same results in each run. This is considered a good practice. You use any number, and model quality won't depend meaningfully on exactly what value you choose.

# Fit model
melbourne_model.fit(X, y)  # X being is the selected features, y is the target
```

## Making Predictions
```python
print("Making predictions for the following 5 houses:")
print(X.head())
print("The predictions are")          #making prediction for house prices
print(melbourne_model.predict(X.head()))
```

| Index | Rooms | Bathroom | Landsize | Latitude | Longitude | Prediction |
| ----- | ----- | -------- | -------- | -------- | --------- | ---------- |
| 1     | 2     | 1.0      | 156.0    | -37.8079 | 144.9934  | 1,035,000  |
| 2     | 3     | 2.0      | 134.0    | -37.8093 | 144.9944  | 1,465,000  |
| 4     | 4     | 1.0      | 120.0    | -37.8072 | 144.9941  | 1,600,000  |
| 6     | 3     | 2.0      | 245.0    | -37.8024 | 144.9993  | 1,876,000  |
| 7     | 2     | 1.0      | 256.0    | -37.8060 | 144.9954  | 1,636,000  |

# Evaluating the model

Mean Absolute Error check

```python
predictions = melbourne_model.predict(X.head())
mean_absolute_error(y, predictions)
```

This is an =="In-Sample" Score==, meaning we made our model on the  _training data_ and compared those predictions to the target values in the _training data_ itself, which is huge mistake when evaluating the model

To fix this:

Since models' practical value come from making predictions on new data, we measure performance on data that wasn't used to build the model. The most straightforward way to do this is to exclude some data from the model-building process, and then use those to test the model's accuracy on data it hasn't seen before. This data is called ==validation data==

The scikit-learn library has a function `train_test_split` to break up the data into two pieces. 
We'll use some of that data as training data to fit the model, and we'll use the other data as validation data to calculate `mean_absolute_error`.

This will be called "Out-of-sample" Score, which is the right way to do it.

```python
from sklearn.model_selection import train_test_split
train_X, val_X, train_y, val_y = train_test_split(X, y, random_state = 0)

# Using built-in function of sklearn to split the features (train_X = training values, val_X = evaluation values) & target (train_y = training targets/lables, val_y = validation/test targets)

# The split is based on a random number generator [random_state = 0] 

# That Supplys a numeric value to the random_state argument, which guarantees we get the same split every time we run this script.
```


```python
# Define model
melbourne_model = DecisionTreeRegressor(random_state=1)
# Fit model
melbourne_model.fit(train_X, train_y)

# get predicted prices on validation data
val_predictions = melbourne_model.predict(val_X)

from sklearn.metrics import mean_absolute_error

print(mean_absolute_error(val_y, val_predictions))
```