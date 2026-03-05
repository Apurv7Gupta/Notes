| || || |_

- [**Loss**](https://developers.google.com/machine-learning/glossary?authuser=1#loss) is a numerical metric that describes how wrong a model's [**predictions**](https://developers.google.com/machine-learning/glossary?authuser=1#prediction) are.

- Loss measures the distance between the model's predictions and the actual labels.

- Loss focuses on the _distance_ between the values, not the direction. (if a model predicts 2, but the actual value is 5, we don't care that the loss is negative)

- To remove the  sign, we use MAE (Mean Absolute Error) and  MSE (Mean Squared Error)

Formulas for finding loss:

- **MSE**. The model is closer to the outliers but further away from most of the other data points.
    
- **MAE**. The model is further away from the outliers but closer to most of the other data points.

-The functional difference between L1 loss and L2 loss (or between MAE and MSE) is squaring. When the difference between the prediction and label is large, squaring makes the loss even larger. When the difference is small (less than 1), squaring makes the loss even smaller. 


## Algorithms

### [**Gradient descent**](https://developers.google.com/machine-learning/glossary?authuser=1#gradient-descent)  (for linear regression)

is a mathematical technique that iteratively finds the weights and bias that produce the model with the lowest loss. Gradient descent finds the best weight and bias by repeating the following process for a number of user-defined iterations.