### Init, add, commit

git init
git add .
git commit -m "Initial commit"

### Push to a newly cloned repo
```
git remote add origin https://github.com/USERNAME/REPO.git
```

```
git branch -M main
```

```
git push -u origin main
```

#### If you intentionally want to overwrite the remote's commits

If your local folder is the ground truth and you intentionally want to replace the remote main with exactly what you have locally, force-push it.

```
git push --force-with-lease -u origin main
```

```
If that gets rejected because your local repo has no relationship with the remote history, use:
```

```
git push --force -u origin main
```



### How to create a branch:

```
https://www.youtube.com/watch?v=Wbz8zM_5iCc
```

### Git Merge Vs Rebase Vs Squash

```
https://www.youtube.com/watch?v=0chZFIZLR_0
```
