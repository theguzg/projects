'''
Created on Dec 15, 2016

@author: Gutza
'''
from Repository.inmemory import InMemoryRepository
from Controller.controller import ParticipantController
from UI.console import Console
from Domain.validators import ParticipantValidator

rep = InMemoryRepository()
val = ParticipantValidator()
ctr = ParticipantController(rep,val)
ui = Console(ctr)

ui.ShowUI()