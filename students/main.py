'''
Created on Jun 22, 2018

@author: Gutza
'''

from Repository.filerepository import FileRepository
from Controller.controller import StudentController
from UI.console import Console

filename = "students.txt"

repo = FileRepository(filename)
ctrl = StudentController(repo)
ui = Console(ctrl)

ui.showUI()