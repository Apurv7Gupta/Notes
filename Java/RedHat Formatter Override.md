Create a `.vscode/settings.prefs` file in your project root.

Add the following lines:

```txt
org.eclipse.jdt.core.formatter.comment.line_length=900
org.eclipse.jdt.core.formatter.lineSplit=900   
```

Update `settings.json`:
```json
{
  "java.settings.url": ".vscode/settings.prefs"
}
```
