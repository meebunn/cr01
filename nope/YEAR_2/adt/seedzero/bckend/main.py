from fastapi import FastAPI

app = FastAPI()

@app.get("/") # Say that the method is GET method and the path is "/" (root path)
def hello_world():
  return "Hello World"