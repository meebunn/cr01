from fastapi import FastAPI ,HTTPException
from typing import Optional,List
from pydantic import BaseModel
from motor.motor_asyncio import AsyncIOMotorClient
from beanie import init_beanie ,Document

app = FastAPI()

class todo(BaseModel):
    title: str
    status: str

class todomodel(Document):
    title: str
    status: str

@app.post('/create')
async def create_list(f: todo)->todomodel :
    doc = todomodel(
        title=f.title,
        status=f.status
    )
    
    await doc.insert()
    return doc

@app.on_event('startup')
async def fastapi():
    client = AsyncIOMotorClient("mongodb://localhost:27017")
    await init_beanie(client.seedzero_todos , document_models=[todomodel])


@app.get('/listtodo')
async def get_todo():
  docs = await todomodel.find().to_list()
  return docs


@app.get('/listtodo/{id}')
async def get_todo(id: str):
  try:
    doc = await todomodel.get(id)
    if doc is None:
      raise ValueError("Value is None")
    return doc
  except:
    raise HTTPException(status_code=404, detail="Not found")


@app.delete('/listtodo/{id}', status_code=204)
async def delete_todolist(id: str):
  try:
    doc = await todomodel.get(id)
    await doc.delete()
  except:
    raise HTTPException(status_code=404, detail="Not found")
  

@app.put('/listtodo/{id}')
async def replace_todolsit(id: str, f: todo):
  try:
    doc = await todomodel.get(id)
    if doc is None:
      raise ValueError("Value is None")
    doc.title = f.title
    doc.status = f.status

    await doc.save()
    return doc
  except:
    raise HTTPException(status_code=404, detail="Not found")